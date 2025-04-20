#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_ajouter_clicked();

    void on_bt_insert_clicked();

    void on_bt_modifier_clicked();

    void on_tableView_equipe_clicked(const QModelIndex &index);
    void remplir_combo_box_nom();

    void on_bt_supprimer_clicked();

    void on_chercher_textChanged(const QString &text);


    void on_bt_tri_clicked();

    void on_bt_pdf_clicked();
    void stat_equipe();

    void on_bt_go_to_acceuil_clicked();

    void on_bt_go_to_page_meilleur_clicked();



private:
    Ui::MainWindow *ui;
    equipe eq;
    int id_equipe;
     QByteArray imageBlob;
};
#endif // MAINWINDOW_H
