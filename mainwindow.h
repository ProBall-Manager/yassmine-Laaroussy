#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "equipe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_button_clicked();



    void on_mdpoubli_clicked();


    void on_retour_menu_clicked();

    void on_retour_login_clicked();

    void on_aller_gestion_employe_clicked();


    void on_ajouter_employe_clicked();

    void on_inserer_image_clicked();

    void on_modifier_employe_clicked();

    void on_tableView_employe_clicked(const QModelIndex &index);

    void on_supprimer_employe_clicked();


    void on_chercher_employe_textChanged(const QString &arg1);

    void on_bt_tri_employe_clicked();

    void on_PDF_EMPLOYE_clicked();

    void stat_employe();
    QString generateRandomCode(int length) ;


//gestion equipe
    void on_bt_envoyer_mail_clicked();

    void on_bt_confirmer_code_clicked();

    void on_bt_go_to_equipe_clicked();

    void on_bt_ajouter_clicked();

    void on_bt_insert_clicked();

    void on_bt_modifier_clicked();

    void on_tableView_equipe_clicked(const QModelIndex &index);

    void remplir_combo_box_nom();


    void on_bt_supprimer_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_bt_tri_clicked();

    void on_bt_pdf_clicked();

    void stat_equipe();

    void on_bt_go_to_page_meilleur_clicked();

    void on_bt_go_to_acceuil_clicked();

private:
    Ui::MainWindow *ui;
    employe e;
    int ID_EMPLOYE;
    QString Poste_EMPLOYE;
    QString code;
    equipe eq;
    int id_equipe;
    QByteArray imageBlob;
};
#endif // MAINWINDOW_H
