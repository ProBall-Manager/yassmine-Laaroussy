#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

#include <QFileDialog>
#include <QPixmap>

#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QFileInfo>

#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

#include <QSqlQuery>
#include "email.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->signup_page->hide();
    ui->login_page->show();
    ui->mdpoublie_page->hide();
    ui->menu_page->hide();
    ui->page_equipe->hide();
    ui->page_equipe_meilleur->hide();

    ui->tableView_employe->setModel(e.afficher());

    //resize tableview
    ui->tableView_employe->resizeColumnsToContents();

    int tableWidth = ui->tableView_employe->viewport()->width();


    int columnCount = ui->tableView_employe->model()->columnCount();
    //Erreur
    //columnCount=9;
    int columnWidth = tableWidth / columnCount;

    for (int i = 0; i < columnCount; ++i) {
        ui->tableView_employe->setColumnWidth(i, columnWidth);
    }
    ui->image_path_employe->hide();

    ui->date_employe->setDate(QDate::currentDate());

    ui->mdp_employe->setEchoMode(QLineEdit::Password);
    ui->mdp_2_employe->setEchoMode(QLineEdit::Password);
    ui->login_mdp->setEchoMode(QLineEdit::Password);


    QIntValidator *validatorSalaire = new QIntValidator(0, 99999, this);
    ui->salaire_employe->setValidator(validatorSalaire);

    QRegularExpression nameRegex("^[A-Za-z]+$");
    QRegularExpressionValidator *validatorName = new QRegularExpressionValidator(nameRegex, this);

    ui->nom_employe->setValidator(validatorName);
    ui->prenom_employe->setValidator(validatorName);


    stat_employe();
    ui->bt_confirmer_code->hide();
    ui->code_mdp->hide();



    // gestion equipe
    QRegularExpression regex("^[a-zA-Z0-9 ]*$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->nom_equipe->setValidator(validator);

    QIntValidator *intValidator = new QIntValidator(0, 100, this); //0 ->99
    ui->nb_joueur_equipe->setValidator(intValidator);

    ui->date_creation_equipe->setDate(QDate::currentDate());


    ui->tableView_equipe->setModel(eq.afficher());
    ui->logo_equipe->hide();
    remplir_combo_box_nom();
    stat_equipe();
    ui->tableView_equipe_meilleur->setModel(eq.afficher_meilleur());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_button_clicked()
{



        QString email = ui->login_email->text();
        QString password = ui->login_mdp->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM EMPLOYE WHERE EMAIL_EMPLOYE = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next()) {

            QString storedPassword = query.value("MDP_EMPLOYE").toString();
            if (password == storedPassword) {

                query.prepare("SELECT POSTE_EMPLOYE FROM EMPLOYE WHERE EMAIL_EMPLOYE = :email");
                query.bindValue(":email", email);

                if (query.exec() && query.next())

                    Poste_EMPLOYE= query.value("POSTE_EMPLOYE").toString();
                ui->login_email->clear();
                ui->login_mdp->clear();

                ui->mdpoublie_page->hide();
                ui->signup_page->hide();
                ui->login_page->hide();
                ui->menu_page->show();

            } else {
                // Password is incorrect
                QMessageBox::critical(this, "Error", "Incorrect password");
            }
        } else {
            // User record not found
            QMessageBox::critical(this, "Error", "Incorrect email");
        }






}








void MainWindow::on_mdpoubli_clicked()
{
    ui->mdpoublie_page->show();
    ui->signup_page->hide();
    ui->login_page->hide();
    ui->menu_page->hide();

}




void MainWindow::on_retour_menu_clicked()
{
    ui->mdpoublie_page->hide();
    ui->signup_page->hide();
    ui->login_page->hide();
    ui->menu_page->show();
}


void MainWindow::on_retour_login_clicked()
{
    ui->mdpoublie_page->hide();
    ui->signup_page->hide();
    ui->login_page->show();
    ui->menu_page->hide();
}


void MainWindow::on_aller_gestion_employe_clicked()
{


        if( Poste_EMPLOYE == "ADMIN" || Poste_EMPLOYE=="Ressources Humaines" )
        {
        ui->mdpoublie_page->hide();
        ui->signup_page->show();
        ui->login_page->hide();
        ui->menu_page->hide();
        }
        else
        {
            QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion employe");
        }


}




void MainWindow::on_ajouter_employe_clicked()
{
    QString prenom=ui->prenom_employe->text();
    QString nom=ui->nom_employe->text();
    QString mail=ui->mail_employe->text();
    int salaire =ui->salaire_employe->text().toInt();
    QString mdp1=ui->mdp_employe->text();
    QString mdp2=ui->mdp_2_employe->text();
    QString path=ui->image_path_employe->text();
    QDate date_embauche=ui->date_employe->date();
    QString sexe=ui->sexe_employe->currentText();
    QString poste=ui->poste_employe->currentText();


    if(mdp1 != mdp2)
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Les mots de passes ne sont pas identiques"), QMessageBox::Cancel);
        return;
    }
    if(prenom=="" || nom =="" || mail==""  || mdp1==""||mdp2=="" ||path=="")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }

    if(sexe=="Entrez le sexe")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir le sexe"), QMessageBox::Cancel);
        return;
    }
    if(poste=="Entrez le poste")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir le poste"), QMessageBox::Cancel);
        return;
    }


    QRegularExpression emailRegex("^[\\w-]+@[\\w-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = emailRegex.match(mail);

    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Email est invalid!"), QMessageBox::Cancel);
        return;
    }

    employe e(prenom,nom,date_embauche,sexe,salaire,poste,mail,mdp1,path);

    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Succes"),
                                 QObject::tr("Ajout avec succés"), QMessageBox::Cancel);
        ui->tableView_employe->setModel(e.afficher());
        ui->prenom_employe->setText("");
        ui->nom_employe->setText("");
        ui->mail_employe->setText("");
        ui->salaire_employe->setText("");
        ui->mdp_2_employe->setText("");
        ui->mdp_employe->setText("");
        ui->image_path_employe->setText("");
        ui->poste_employe->setCurrentIndex(0);
        ui->sexe_employe->setCurrentIndex(0);
        stat_employe();
    }
    else
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Echec d'ajout "), QMessageBox::Cancel);
    }

}




void MainWindow::on_inserer_image_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.bmp *.gif)");

    if (!imagePath.isEmpty()) {
        QPixmap image(imagePath);

        if (!image.isNull()) {
            ui->label_image->setPixmap(image.scaled(ui->label_image->size(), Qt::KeepAspectRatio));

            ui->image_path_employe->setText(imagePath);


        } else {
            QMessageBox::warning(this, "Error", "Failed to load the image.");
        }
    }
}



void MainWindow::on_modifier_employe_clicked()
{
    QString prenom=ui->prenom_employe->text();
    QString nom=ui->nom_employe->text();
    QString mail=ui->mail_employe->text();
    int salaire =ui->salaire_employe->text().toInt();
    QString mdp1=ui->mdp_employe->text();
    QString mdp2=ui->mdp_2_employe->text();
    QString path=ui->image_path_employe->text();
    QDate date_embauche=ui->date_employe->date();
    QString sexe=ui->sexe_employe->currentText();
    QString poste=ui->poste_employe->currentText();


    if(mdp1 != mdp2)
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Les mots de passes ne sont pas identiques"), QMessageBox::Cancel);
        return;
    }
    if(prenom=="" || nom =="" || mail==""  || mdp1==""||mdp2=="" ||path=="")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }

    if(sexe=="Entrez le sexe")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir le sexe"), QMessageBox::Cancel);
        return;
    }
    if(poste=="Entrez le poste")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir le poste"), QMessageBox::Cancel);
        return;
    }


    QRegularExpression emailRegex("^[\\w-]+@[\\w-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = emailRegex.match(mail);

    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Email est invalid!"), QMessageBox::Cancel);
        return;
    }

    employe e(ID_EMPLOYE,prenom,nom,date_embauche,sexe,salaire,poste,mail,mdp1,path);

    bool test=e.modifier();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Succes"),
                                 QObject::tr("Modification avec succés"), QMessageBox::Cancel);
        ui->tableView_employe->setModel(e.afficher());
        ui->prenom_employe->setText("");
        ui->nom_employe->setText("");
        ui->mail_employe->setText("");
        ui->salaire_employe->setText("");
        ui->mdp_2_employe->setText("");
        ui->mdp_employe->setText("");
        ui->image_path_employe->setText("");
        ui->poste_employe->setCurrentIndex(0);
        ui->sexe_employe->setCurrentIndex(0);
        ID_EMPLOYE=0;
        stat_employe();
    }
    else
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Echec de modification "), QMessageBox::Cancel);
    }


}


void MainWindow::on_tableView_employe_clicked(const QModelIndex &index)
{
    QAbstractItemModel* model = ui->tableView_employe->model();
    int row = index.row();
    QString nom_employe = model->data(model->index(row, 0)).toString();
    QString prenom_employe = model->data(model->index(row, 1)).toString();
    QString mail_employe = model->data(model->index(row, 6)).toString();
    QString poste_employe = model->data(model->index(row, 5)).toString();
    QDate date_employe = model->data(model->index(row, 2)).toDate();
    QString sexe_employe = model->data(model->index(row, 3)).toString();
    QString salaire_employe = model->data(model->index(row, 4)).toString();

    ui->prenom_employe->setText(prenom_employe);
    ui->nom_employe->setText(nom_employe);
    ui->mail_employe->setText(mail_employe);
    ui->salaire_employe->setText(salaire_employe);
    ui->mdp_2_employe->setText("");
    ui->mdp_employe->setText("");
    ui->image_path_employe->setText("");
    ui->poste_employe->setCurrentText(poste_employe);
    ui->sexe_employe->setCurrentText(sexe_employe);
    ui->date_employe->setDate(date_employe);

    ID_EMPLOYE=e.chercher_IDbyEmail(mail_employe);

    ui->image_path_employe->setText(e.chercher_PathByEmail(mail_employe));

    if (!ui->image_path_employe->text().isEmpty()) {
        QPixmap image(ui->image_path_employe->text());

        if (!image.isNull()) {
            ui->label_image->setPixmap(image.scaled(ui->label_image->size(), Qt::KeepAspectRatio));

            ui->image_path_employe->setText(ui->image_path_employe->text());


        } else {
            QMessageBox::warning(this, "Error", "Failed to load the image.");
        }
    }

}


void MainWindow::on_supprimer_employe_clicked()
{
    if(ID_EMPLOYE==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir un employe pour supprimer "), QMessageBox::Cancel);
    }
    else
    {
        bool test=e.supprimer(ID_EMPLOYE);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Suppression avec succes "), QMessageBox::Cancel);
            ui->tableView_employe->setModel(e.afficher());
            ui->prenom_employe->setText("");
            ui->nom_employe->setText("");
            ui->mail_employe->setText("");
            ui->salaire_employe->setText("");
            ui->mdp_2_employe->setText("");
            ui->mdp_employe->setText("");
            ui->image_path_employe->setText("");
            ui->poste_employe->setCurrentIndex(0);
            ui->sexe_employe->setCurrentIndex(0);
            ID_EMPLOYE=0;
            stat_employe();
        }
        else
        {
           // qDebug()<<ID_EMPLOYE;
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Suppression echoue "), QMessageBox::Cancel);
        }
    }


}





void MainWindow::on_chercher_employe_textChanged(const QString &text)
{
    QString choix=ui->choix_tri_employe->currentText();
    if(choix=="----")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir un parametere de recherche "), QMessageBox::Cancel);
        return;
    }
    ui->tableView_employe->setModel(e.chercher(choix,text));


}


void MainWindow::on_bt_tri_employe_clicked()
{
    QString choix=ui->choix_tri_employe->currentText();
    QString ordre=ui->choix_ordre_employe->currentText();
    if(choix=="----")
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tu dois choisir un parametere de recherche "), QMessageBox::Cancel);
        return;
    }
    ui->tableView_employe->setModel(e.chercher(choix,ordre));

}


void MainWindow::on_PDF_EMPLOYE_clicked()
{

        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_employe->model()->rowCount();
        const int columnCount = ui->tableView_employe->model()->columnCount();

        out << "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               "<title>%1</title>\n"
               "<style>\n"
               "table {\n"
               "    width: 100%;\n"
               "    border-collapse: collapse;\n"
               "}\n"
               "th, td {\n"
               "    padding: 8px;\n"
               "    text-align: left;\n"
               "    border-bottom: 1px solid #ddd;\n"
               "}\n"
               "tr:nth-child(even) {\n"
               "    background-color: #f2f2f2;\n"
               "}\n"
               "</style>\n"
               "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<center> <H1>Liste des Employes</H1></center><br/><br/>\n"
               "<img src=\"/Users/Mymsi/Documents/ProBall-Manger/logo.png\" alt=\"Description of image\" style=\"max-width: 100%; height: auto;\">\n"
               "<table>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_employe->isColumnHidden(column))
            {
                out << QString("<th>%1</th>").arg(ui->tableView_employe->model()->headerData(column, Qt::Horizontal).toString());
            }
        }
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++)
        {
            out << "<tr> <td>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView_employe->isColumnHidden(column))
                {
                    QString data = ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(row, column)).toString().simplified();
                    out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }



        QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), ".pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPageSize(QPageSize::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.print(&printer);


}

void MainWindow::stat_employe()
{
    QList<QWidget*> childWidgets = ui->label_stat->findChildren<QWidget*>();
    for (QWidget* childWidget : childWidgets) {
        childWidget->deleteLater();

    }
    //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
    ui->label_stat->clear();
    ui->label_stat->hide();

    int s0, s1,s2,s3;

    s0 = e.countPoste("Ressources Humaines");
    s1 = e.countPoste("Chef des matches");
    s2 = e.countPoste("Chef des stades");
    s3 = e.countPoste("Coach ");





    int total = s0 + s1 +s2+s3  ;
    // Calculate percentages
    float x = (total != 0) ? (s0 * 100.0f) / total : 0.0f;
    float x1 = (total != 0) ? (s1 * 100.0f) / total : 0.0f;
    float x2 = (total != 0) ? (s2 * 100.0f) / total : 0.0f;
    float x3 = (total != 0) ? (s3 * 100.0f) / total : 0.0f;


    // Adjust the percentages to ensure they sum up to 100%
    float totalPercentage = x + x1+x2+x3  ;
    if (totalPercentage != 100.0f && total != 0) {
        float correction = 100.0f - totalPercentage;
        x += correction;  // Apply correction to one of the slices (usually the largest one)
    }



    //qDebug() <<  x <<endl;
    //RH 25.00%
    QString ch1 = QString("RH %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("CM %1%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("CS %1%").arg(QString::number(x2, 'f', 2));
    QString ch4 = QString("C %1%").arg(QString::number(x3, 'f', 2));






    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);

    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::white));
    slice->setBrush(QColor(Qt::white));//changer

    QPieSlice *slice1= series->append(ch2,x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::white));
    slice1->setBrush(QColor(Qt::black));//changer

    QPieSlice *slice2= series->append(ch3,x2);
    slice2->setLabelVisible();
    slice2->setLabelColor(QColor(Qt::white));
    slice2->setBrush(QColor(Qt::yellow));//changer

    QPieSlice *slice3= series->append(ch4,x3);
    slice3->setLabelVisible();
    slice3->setLabelColor(QColor(Qt::white));
    slice3->setBrush(QColor(Qt::red));//changer

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBrush backgroundBrush(QColor(187,93,87,0));
    chart->setBackgroundBrush(backgroundBrush);
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->label_stat->size());
    chartview->setParent(ui->label_stat);
    ui->label_stat->setStyleSheet("background:transparent; color:white; ");
    ui->label_stat->show();

}

QString MainWindow::generateRandomCode(int length) {
    const QString characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString randomCode;

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        randomCode.append(characters[index]);
    }

    return randomCode;
}



void MainWindow::on_bt_envoyer_mail_clicked()
{

        QString email=ui->login_email->text();
        QString code = generateRandomCode(6); // Generate a 6-character code
        QString message = "Your verification code is: " + code;
        mailer m;
        m.sendEmail(email, "Recuperation du mot de pass", message);
        qDebug()<<code;
        ui->bt_confirmer_code->show();
        ui->code_mdp->show();

}


void MainWindow::on_bt_confirmer_code_clicked()
{
    QString email=ui->login_email->text();
    QString code_user=ui->code_mdp->text();
    if(code_user==code)
    {
        QSqlQuery query;
        query.prepare("SELECT MDP_EMPLOYE FROM EMPLOYE WHERE MAIL_EMPLOYE = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next()) {

            QString storedPassword = query.value("MDP_EMPLOYE").toString();
            QString message = QString("Votre mot de passe est : %1").arg(storedPassword);
            QMessageBox::information(nullptr, QObject::tr("Mot de passe"), message, QMessageBox::Cancel);

            ui->bt_confirmer_code->hide();
            ui->code_mdp->hide();
        }
    }
}


void MainWindow::on_bt_go_to_equipe_clicked()
{
    if( Poste_EMPLOYE == "ADMIN" || Poste_EMPLOYE=="Ressources Humaines" )
    {
        ui->mdpoublie_page->hide();
        ui->signup_page->hide();
        ui->login_page->hide();
        ui->menu_page->hide();
        ui->page_equipe->show();
    }
    else
    {
        QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion employe");
    }
}


void MainWindow::on_bt_ajouter_clicked()
{
    {
        //récuperation du donnés d'apres le ui
        QString nom=ui->nom_equipe->text();
        QString nationalite=ui->nationalite_equipe->currentText();
        QString logo=ui->logo_equipe->text();
        QDate date=ui->date_creation_equipe->date();
        QString coach=ui->coach_equipe->text();
        int nb_joueur=ui->nb_joueur_equipe->text().toInt();
        int nb_championnat=ui->nb_championnat_equipe->value();

        //controle de saisie
        if(nom==""|| logo==""|| coach==""||ui->nb_joueur_equipe->text()=="")
        {
            QMessageBox::warning(nullptr, QObject::tr("Probleme"),
                                 QObject::tr("Tu dois remplir tous les champs "), QMessageBox::Cancel);
            return;
        }
        if(eq.chercherEquipe(nom))
        {

            QMessageBox::warning(nullptr, QObject::tr("Probleme"),
                                 QObject::tr("Le nom de l'équipe déja existe "), QMessageBox::Cancel);
            return;
        }

        //action d'ajout
        bool test =eq.ajouter(nom,nationalite,date,imageBlob,coach,nb_joueur,nb_championnat);
        if(test)
        {


            QMessageBox::information(nullptr, QObject::tr(""),
                                     QObject::tr("Equipe Ajoutée avec succées "), QMessageBox::Cancel);
            ui->nom_equipe->clear();
            ui->nationalite_equipe->setCurrentIndex(0);
            ui->logo_equipe->clear();
            ui->coach_equipe->clear();
            ui->nb_joueur_equipe->clear();
            ui->nb_championnat_equipe->setValue(0);

            ui->tableView_equipe->setModel(eq.afficher());
            remplir_combo_box_nom();
            stat_equipe();
            ui->label_image->clear();

        }
        else
        {
            QMessageBox::warning(nullptr, QObject::tr("Probleme"),
                                 QObject::tr("Ajout échoué "), QMessageBox::Cancel);

        }
    }
}


void MainWindow::on_bt_insert_clicked()
{
    {
        // Open a file dialog to select an image
        QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.bmp *.gif)");

        // Check if a valid image path is selected
        if (!imagePath.isEmpty()) {
            // Load the image using QPixmap
            QPixmap image(imagePath);

            // Update the QLabel with the image
            ui->label_image->setPixmap(image.scaled(ui->label_image->size(), Qt::KeepAspectRatio));

            // Set the text of the line edit or QLabel with the image path if needed
            ui->logo_equipe->setText(imagePath);

            // Convert the image to a QByteArray (BLOB)
            QFile file(imagePath);
            if (file.open(QIODevice::ReadOnly)) {
                QByteArray imageData = file.readAll();  // Read all data from the file
                file.close();

                // Now you can use imageData to store it in your database as a BLOB
                // Example: Assuming you have a function to save the image in the database
                imageBlob=imageData; // Implement this function as needed

                // Hide the QLabel if that's required for your logic
                ui->label_image->show();
            } else {
                QMessageBox::warning(this, "File Error", "Unable to open the selected image file.");
            }
        }
    }
}


void MainWindow::on_bt_modifier_clicked()
{
    //récuperation du donnés d'apres le ui
    QString nom=ui->nom_equipe->text();
    QString nationalite=ui->nationalite_equipe->currentText();
    QString logo=ui->logo_equipe->text();
    QDate date=ui->date_creation_equipe->date();
    QString coach=ui->coach_equipe->text();
    int nb_joueur=ui->nb_joueur_equipe->text().toInt();
    int nb_championnat=ui->nb_championnat_equipe->value();

    if(nom==""|| logo==""|| coach==""||ui->nb_joueur_equipe->text()=="")
    {
        QMessageBox::warning(nullptr, QObject::tr("Problem"),
                             QObject::tr("Tu dois remplir tous les champs "), QMessageBox::Cancel);
        return;
    }

    bool test =eq.modifier(id_equipe,nom,nationalite,date,imageBlob,coach,nb_joueur,nb_championnat);
    if(test)
    {


        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Equipe Modifié avec succées "), QMessageBox::Cancel);
        ui->nom_equipe->clear();
        ui->nationalite_equipe->setCurrentIndex(0);
        ui->logo_equipe->clear();
        ui->coach_equipe->clear();
        ui->nb_joueur_equipe->clear();
        ui->nb_championnat_equipe->setValue(0);
        remplir_combo_box_nom();

        ui->tableView_equipe->setModel(eq.afficher());
        stat_equipe();
        ui->label_image->clear();
    }
    else
    {
        QMessageBox::warning(nullptr, QObject::tr("Problem"),
                             QObject::tr("Modification échoué "), QMessageBox::Cancel);

    }
}


void MainWindow::on_tableView_equipe_clicked(const QModelIndex &index)
{
    {
        QAbstractItemModel* model = ui->tableView_equipe->model();

        int row = index.row();


        QString Nom = model->data(model->index(row, 0)).toString();
        QString nationalite = model->data(model->index(row, 1)).toString();

        QDate date = model->data(model->index(row, 2)).toDate();

        QString coach = model->data(model->index(row, 3)).toString();
        QString nb_joueur = model->data(model->index(row, 4)).toString();

        int championnat = model->data(model->index(row, 5)).toInt();



        ui->nom_equipe->setText(Nom);
        ui->nationalite_equipe->setCurrentText(nationalite);
        ui->date_creation_equipe->setDate(date);
        ui->coach_equipe->setText(coach);
        ui->nb_joueur_equipe->setText(nb_joueur);
        ui->nb_championnat_equipe->setValue(championnat);


        id_equipe=eq.chercherIDEquipeByNom(Nom);


        QByteArray imageBlob = eq.chercherLogoEquipeByNom(Nom);

        if (!imageBlob.isEmpty()) {
            QImage image;
            image.loadFromData(imageBlob);

            if (!image.isNull()) {
                QPixmap pixmap = QPixmap::fromImage(image);

                ui->label_image->setPixmap(pixmap.scaled(ui->label_image->size(), Qt::KeepAspectRatio));

                ui->logo_equipe->setText(Nom);

                ui->label_image->show();
            }
        } else {
            ui->label_image->clear();
        }


    }
}
    void MainWindow::remplir_combo_box_nom()
    {
        ui->combo_nom_equipe->clear();
        QSqlQuery query;
        query.prepare("SELECT NOM_EQUIPE FROM EQUIPE");
        if(query.exec())
        {
            while(query.next())
            {
                QString nom=query.value(0).toString();
                ui->combo_nom_equipe->addItem(nom);
            }

        }

    }




void MainWindow::on_bt_supprimer_clicked()
{
    QString nom=ui->combo_nom_equipe->currentText();
    int id=eq.chercherIDEquipeByNom(nom);

    bool test = eq.supprimer(id);
    if(test)
    {

        QMessageBox::warning(nullptr, QObject::tr(""),
                             QObject::tr("Suppression avec succés "), QMessageBox::Cancel);
        remplir_combo_box_nom();
        ui->tableView_equipe->setModel(eq.afficher());
    }
    else
    {
        QMessageBox::warning(nullptr, QObject::tr("Problem"),
                             QObject::tr("Suppression échoué "), QMessageBox::Cancel);

    }
    stat_equipe();
}

void MainWindow::on_chercher_textChanged(const QString &text)
{
    {
        QString choix=ui->combo_choix->currentText();

        ui->tableView_equipe->setModel(eq.chercher(choix,text));
    }



}


void MainWindow::on_bt_tri_clicked()
{
    {
        QString choix=ui->combo_choix->currentText();
        QString ordre=ui->combo_ordre->currentText();

        ui->tableView_equipe->setModel(eq.tri(choix,ordre));

    }
}


void MainWindow::on_bt_pdf_clicked()
{
    {
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_equipe->model()->rowCount();
        const int columnCount = ui->tableView_equipe->model()->columnCount();

        out << "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               "<title>%1</title>\n"
               "<style>\n"
               "table {\n"
               "    width: 100%;\n"
               "    border-collapse: collapse;\n"
               "}\n"
               "th, td {\n"
               "    padding: 8px;\n"
               "    text-align: left;\n"
               "    border-bottom: 1px solid #ddd;\n"
               "}\n"
               "tr:nth-child(even) {\n"
               "    background-color: #f2f2f2;\n"
               "}\n"
               "</style>\n"
               "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<center> <H1>Liste des equipes</H1></center><br/><br/>\n"
               "<img src=\"/Users/Msi/OneDrive/Bureau/5edmty/YasmineLaroussi/logo_application2.png\" alt=\"Description of image\" style=\"max-width: 100%; height: auto;\">\n"
               "<table>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_equipe->isColumnHidden(column))
            {
                out << QString("<th>%1</th>").arg(ui->tableView_equipe->model()->headerData(column, Qt::Horizontal).toString());
            }
        }
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++)
        {
            out << "<tr> <td>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView_equipe->isColumnHidden(column))
                {
                    QString data = ui->tableView_equipe->model()->data(ui->tableView_equipe->model()->index(row, column)).toString().simplified();
                    out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }



        QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPageSize(QPageSize::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.print(&printer);

    }
}

void MainWindow::stat_equipe()
{
    QList<QWidget*> childWidgets = ui->label_stat->findChildren<QWidget*>();
    for (QWidget* childWidget : childWidgets) {
        childWidget->deleteLater();

    }
    //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
    ui->label_stat->clear();
    ui->label_stat->hide();

    int s0, s1,s2,s3,s4,s5;

    s0 = eq.countNationalite("Tunisian");
    s1 = eq.countNationalite("French");
    s2 = eq.countNationalite("Italian");
    s3 = eq.countNationalite("German");
    s4 = eq.countNationalite("English");
    s5 = eq.countNationalite("Spanish");





    int total = s0 + s1+  s2+s3+s4+s5 ;
    // Calculate percentages
    float x = (total != 0) ? (s0 * 100.0f) / total : 0.0f;
    float x1 = (total != 0) ? (s1 * 100.0f) / total : 0.0f;
    float x2 = (total != 0) ? (s2 * 100.0f) / total : 0.0f;
    float x3 = (total != 0) ? (s3 * 100.0f) / total : 0.0f;
    float x4 = (total != 0) ? (s4 * 100.0f) / total : 0.0f;
    float x5 = (total != 0) ? (s5 * 100.0f) / total : 0.0f;


    // Adjust the percentages to ensure they sum up to 100%
    float totalPercentage = x + x1  ;
    if (totalPercentage != 100.0f && total != 0) {
        float correction = 100.0f - totalPercentage;
        x += correction;  // Apply correction to one of the slices (usually the largest one)
    }



    //qDebug() <<  x <<endl;
    // Tunisian 25.00%
    QString ch1 = QString("Tunisian %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("French %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("Italian %2%").arg(QString::number(x2, 'f', 2));
    QString ch4 = QString("German %2%").arg(QString::number(x3, 'f', 2));
    QString ch5 = QString("English %2%").arg(QString::number(x4, 'f', 2));
    QString ch6 = QString("Spanish %2%").arg(QString::number(x5, 'f', 2));






    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);

    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::white));
    slice->setBrush(QColor(Qt::white));//changer

    QPieSlice *slice1= series->append(ch2,x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::white));
    slice1->setBrush(QColor(Qt::black));//changer


    QPieSlice *slice2= series->append(ch3,x2);
    slice2->setLabelVisible();
    slice2->setLabelColor(QColor(Qt::white));
    slice2->setBrush(QColor(Qt::red));//changer

    QPieSlice *slice3= series->append(ch4,x2);
    slice3->setLabelVisible();
    slice3->setLabelColor(QColor(Qt::white));
    slice3->setBrush(QColor(Qt::yellow));//changer

    QPieSlice *slice4= series->append(ch5,x3);
    slice4->setLabelVisible();
    slice4->setLabelColor(QColor(Qt::white));
    slice4->setBrush(QColor(Qt::blue));//changer

    QPieSlice *slice5= series->append(ch6,x4);
    slice5->setLabelVisible();
    slice5->setLabelColor(QColor(Qt::white));
    slice5->setBrush(QColor(Qt::red));//changer

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBrush backgroundBrush(QColor(187,93,87,0));
    chart->setBackgroundBrush(backgroundBrush);
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->label_stat->size());
    chartview->setParent(ui->label_stat);
    ui->label_stat->setStyleSheet("background:transparent; color:white; ");
    ui->label_stat->show();

}
void MainWindow::on_bt_go_to_page_meilleur_clicked()
{
    ui->page_equipe_meilleur->show();
    ui->page_equipe->hide();
}


void MainWindow::on_bt_go_to_acceuil_clicked()
{
    ui->page_equipe_meilleur->hide();
    ui->page_equipe->show();
}

