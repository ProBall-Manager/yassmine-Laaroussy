#include "email.h"
#include <QtNetwork>
#include <QDebug>

mailer::mailer() {}

int mailer::sendEmail(QString dist, QString obj, QString bdy)
{
    qDebug() << "sslLibraryBuildVersionString:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "sslLibraryVersionNumber:" << QSslSocket::sslLibraryVersionNumber();
    qDebug() << "supportsSsl:" << QSslSocket::supportsSsl();
    qDebug() << QCoreApplication::libraryPaths();

    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;
    QString username = "aymen.dhieb@esprit.tn";
    QString password = "bxgq xfek egdv kywp";

    QString from = username;
    QString to = dist;
    QString subject = obj;
    QString body = bdy;

    QSslSocket socket;

    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected(5000)) {
        qDebug() << "Connection error:" << socket.errorString();
        return -1;
    }

    auto waitForReply = [&socket]() {
        if (!socket.waitForReadyRead(5000)) {
            qDebug() << "Server timeout:" << socket.errorString();
            return false;
        }
        qDebug() << "Server:" << socket.readAll();
        return true;
    };

    auto sendCommand = [&socket](const QString& cmd) {
        socket.write(cmd.toUtf8());
        socket.waitForBytesWritten(3000);
    };

    qDebug() << "Connected to server.";

    sendCommand("HELO localhost\r\n");
    if (!waitForReply()) return -1;

    sendCommand("AUTH LOGIN\r\n");
    if (!waitForReply()) return -1;

    sendCommand(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    if (!waitForReply()) return -1;

    sendCommand(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    if (!waitForReply()) return -1;

    sendCommand("MAIL FROM:<" + from + ">\r\n");
    if (!waitForReply()) return -1;

    sendCommand("RCPT TO:<" + to + ">\r\n");
    if (!waitForReply()) return -1;

    sendCommand("DATA\r\n");
    if (!waitForReply()) return -1;

    // Compose full email headers + body
    QString mailContent;
    mailContent += "From: " + from + "\r\n";
    mailContent += "To: " + to + "\r\n";
    mailContent += "Subject: " + subject + "\r\n";
    mailContent += "MIME-Version: 1.0\r\n";
    mailContent += "Content-Type: text/plain; charset=UTF-8\r\n";
    mailContent += "\r\n";
    mailContent += body + "\r\n.\r\n";

    sendCommand(mailContent);
    if (!waitForReply()) return -1;

    sendCommand("QUIT\r\n");
    waitForReply();

    socket.close();

    qDebug() << "Email sent successfully.";
    return 0;
}
