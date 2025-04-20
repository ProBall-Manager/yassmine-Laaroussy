#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
#include <QPrinter>
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //lors de l'exuction
    ui->setupUi(this);


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
ui->page_equipe_meilleur->hide();
ui->page_equipe->show();
ui->tableView_equipe_meilleur->setModel(eq.afficher_meilleur());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_ajouter_clicked()
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

void MainWindow::on_bt_insert_clicked()
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
QString choix=ui->combo_choix->currentText();

ui->tableView_equipe->setModel(eq.chercher(choix,text));
}


void MainWindow::on_bt_tri_clicked()
{
    QString choix=ui->combo_choix->currentText();
    QString ordre=ui->combo_ordre->currentText();

    ui->tableView_equipe->setModel(eq.tri(choix,ordre));

}

void MainWindow::on_bt_pdf_clicked()
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

void MainWindow::on_bt_go_to_acceuil_clicked()
{
    ui->page_equipe_meilleur->hide();
    ui->page_equipe->show();
}

void MainWindow::on_bt_go_to_page_meilleur_clicked()
{
    ui->page_equipe_meilleur->show();
    ui->page_equipe->hide();
}


