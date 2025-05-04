/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *login_page;
    QLabel *bg_login;
    QLineEdit *login_email;
    QLineEdit *login_mdp;
    QLabel *label;
    QLabel *label_2;
    QPushButton *login_button;
    QLabel *label_4;
    QPushButton *mdpoubli;
    QLabel *label_5;
    QLabel *label_12;
    QGroupBox *signup_page;
    QLabel *bg_signup;
    QLineEdit *mail_employe;
    QLineEdit *nom_employe;
    QLineEdit *prenom_employe;
    QLineEdit *mdp_employe;
    QLineEdit *mdp_2_employe;
    QDateEdit *date_employe;
    QComboBox *sexe_employe;
    QLineEdit *salaire_employe;
    QComboBox *poste_employe;
    QPushButton *inserer_image;
    QLabel *label_image;
    QPushButton *ajouter_employe;
    QPushButton *modifier_employe;
    QTableView *tableView_employe;
    QComboBox *choix_tri_employe;
    QLineEdit *chercher_employe;
    QPushButton *bt_tri_employe;
    QPushButton *PDF_EMPLOYE;
    QComboBox *choix_ordre_employe;
    QPushButton *retour_menu;
    QLineEdit *image_path_employe;
    QLabel *label_6;
    QPushButton *supprimer_employe;
    QLabel *label_stat;
    QGroupBox *mdpoublie_page;
    QLabel *label_3;
    QLineEdit *mailoublie;
    QLabel *label_7;
    QPushButton *bt_envoyer_mail;
    QPushButton *retour_login;
    QLabel *label_11;
    QPushButton *bt_confirmer_code;
    QLineEdit *code_mdp;
    QGroupBox *menu_page;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *aller_gestion_employe;
    QPushButton *pushButton_10;
    QPushButton *bt_go_to_equipe;
    QLabel *label_10;
    QGroupBox *page_equipe_meilleur;
    QLabel *bg_2;
    QLabel *label_13;
    QTableView *tableView_equipe_meilleur;
    QPushButton *bt_go_to_acceuil;
    QLabel *label_23;
    QGroupBox *page_equipe;
    QLabel *bg;
    QLabel *label_14;
    QTableView *tableView_equipe;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *nom_equipe;
    QComboBox *nationalite_equipe;
    QPushButton *bt_insert;
    QLabel *label_image_2;
    QLineEdit *logo_equipe;
    QDateEdit *date_creation_equipe;
    QLineEdit *coach_equipe;
    QSpinBox *nb_championnat_equipe;
    QLineEdit *nb_joueur_equipe;
    QPushButton *bt_ajouter;
    QPushButton *bt_modifier;
    QPushButton *bt_supprimer;
    QComboBox *combo_nom_equipe;
    QLabel *label_22;
    QLineEdit *chercher;
    QComboBox *combo_ordre;
    QComboBox *combo_choix;
    QPushButton *bt_tri;
    QPushButton *bt_pdf;
    QLabel *label_stat_2;
    QPushButton *bt_go_to_page_meilleur;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1853, 1279);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        login_page = new QGroupBox(centralwidget);
        login_page->setObjectName("login_page");
        login_page->setGeometry(QRect(0, 0, 1920, 1080));
        bg_login = new QLabel(login_page);
        bg_login->setObjectName("bg_login");
        bg_login->setGeometry(QRect(0, 0, 1920, 1080));
        bg_login->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        login_email = new QLineEdit(login_page);
        login_email->setObjectName("login_email");
        login_email->setGeometry(QRect(70, 380, 211, 31));
        login_mdp = new QLineEdit(login_page);
        login_mdp->setObjectName("login_mdp");
        login_mdp->setGeometry(QRect(70, 450, 211, 31));
        label = new QLabel(login_page);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 360, 171, 16));
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        label_2 = new QLabel(login_page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 430, 171, 16));
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        login_button = new QPushButton(login_page);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(80, 670, 80, 24));
        label_4 = new QLabel(login_page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 700, 171, 16));
        label_4->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        mdpoubli = new QPushButton(login_page);
        mdpoubli->setObjectName("mdpoubli");
        mdpoubli->setGeometry(QRect(200, 700, 16, 16));
        label_5 = new QLabel(login_page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 100, 1231, 151));
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 32pt \"Segoe UI\";\n"
""));
        label_12 = new QLabel(login_page);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(1600, 10, 191, 181));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/logo.png")));
        signup_page = new QGroupBox(centralwidget);
        signup_page->setObjectName("signup_page");
        signup_page->setGeometry(QRect(0, 0, 1920, 1080));
        bg_signup = new QLabel(signup_page);
        bg_signup->setObjectName("bg_signup");
        bg_signup->setGeometry(QRect(0, 0, 1920, 1080));
        bg_signup->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        mail_employe = new QLineEdit(signup_page);
        mail_employe->setObjectName("mail_employe");
        mail_employe->setGeometry(QRect(30, 373, 221, 24));
        nom_employe = new QLineEdit(signup_page);
        nom_employe->setObjectName("nom_employe");
        nom_employe->setGeometry(QRect(30, 303, 221, 24));
        prenom_employe = new QLineEdit(signup_page);
        prenom_employe->setObjectName("prenom_employe");
        prenom_employe->setGeometry(QRect(30, 243, 221, 24));
        mdp_employe = new QLineEdit(signup_page);
        mdp_employe->setObjectName("mdp_employe");
        mdp_employe->setGeometry(QRect(30, 443, 221, 24));
        mdp_2_employe = new QLineEdit(signup_page);
        mdp_2_employe->setObjectName("mdp_2_employe");
        mdp_2_employe->setGeometry(QRect(30, 513, 221, 24));
        date_employe = new QDateEdit(signup_page);
        date_employe->setObjectName("date_employe");
        date_employe->setEnabled(false);
        date_employe->setGeometry(QRect(300, 243, 221, 25));
        sexe_employe = new QComboBox(signup_page);
        sexe_employe->addItem(QString());
        sexe_employe->addItem(QString());
        sexe_employe->addItem(QString());
        sexe_employe->addItem(QString());
        sexe_employe->setObjectName("sexe_employe");
        sexe_employe->setGeometry(QRect(300, 303, 221, 24));
        salaire_employe = new QLineEdit(signup_page);
        salaire_employe->setObjectName("salaire_employe");
        salaire_employe->setGeometry(QRect(300, 373, 221, 24));
        poste_employe = new QComboBox(signup_page);
        poste_employe->addItem(QString());
        poste_employe->addItem(QString());
        poste_employe->addItem(QString());
        poste_employe->addItem(QString());
        poste_employe->addItem(QString());
        poste_employe->setObjectName("poste_employe");
        poste_employe->setGeometry(QRect(300, 443, 221, 24));
        inserer_image = new QPushButton(signup_page);
        inserer_image->setObjectName("inserer_image");
        inserer_image->setGeometry(QRect(300, 513, 221, 24));
        label_image = new QLabel(signup_page);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(230, 60, 111, 121));
        label_image->setStyleSheet(QString::fromUtf8(""));
        ajouter_employe = new QPushButton(signup_page);
        ajouter_employe->setObjectName("ajouter_employe");
        ajouter_employe->setGeometry(QRect(170, 680, 211, 31));
        modifier_employe = new QPushButton(signup_page);
        modifier_employe->setObjectName("modifier_employe");
        modifier_employe->setGeometry(QRect(170, 730, 211, 31));
        tableView_employe = new QTableView(signup_page);
        tableView_employe->setObjectName("tableView_employe");
        tableView_employe->setGeometry(QRect(710, 210, 1061, 361));
        choix_tri_employe = new QComboBox(signup_page);
        choix_tri_employe->addItem(QString());
        choix_tri_employe->addItem(QString());
        choix_tri_employe->addItem(QString());
        choix_tri_employe->addItem(QString());
        choix_tri_employe->setObjectName("choix_tri_employe");
        choix_tri_employe->setGeometry(QRect(1470, 170, 72, 24));
        chercher_employe = new QLineEdit(signup_page);
        chercher_employe->setObjectName("chercher_employe");
        chercher_employe->setGeometry(QRect(1560, 170, 211, 24));
        bt_tri_employe = new QPushButton(signup_page);
        bt_tri_employe->setObjectName("bt_tri_employe");
        bt_tri_employe->setGeometry(QRect(1419, 170, 41, 24));
        PDF_EMPLOYE = new QPushButton(signup_page);
        PDF_EMPLOYE->setObjectName("PDF_EMPLOYE");
        PDF_EMPLOYE->setGeometry(QRect(1579, 580, 191, 24));
        choix_ordre_employe = new QComboBox(signup_page);
        choix_ordre_employe->addItem(QString());
        choix_ordre_employe->addItem(QString());
        choix_ordre_employe->setObjectName("choix_ordre_employe");
        choix_ordre_employe->setGeometry(QRect(1331, 170, 81, 24));
        retour_menu = new QPushButton(signup_page);
        retour_menu->setObjectName("retour_menu");
        retour_menu->setGeometry(QRect(40, 940, 80, 24));
        image_path_employe = new QLineEdit(signup_page);
        image_path_employe->setObjectName("image_path_employe");
        image_path_employe->setGeometry(QRect(300, 550, 221, 24));
        label_6 = new QLabel(signup_page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1600, 10, 191, 161));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/logo.png")));
        supprimer_employe = new QPushButton(signup_page);
        supprimer_employe->setObjectName("supprimer_employe");
        supprimer_employe->setGeometry(QRect(170, 780, 211, 31));
        label_stat = new QLabel(signup_page);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(750, 590, 421, 261));
        mdpoublie_page = new QGroupBox(centralwidget);
        mdpoublie_page->setObjectName("mdpoublie_page");
        mdpoublie_page->setGeometry(QRect(0, 0, 1920, 1080));
        label_3 = new QLabel(mdpoublie_page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 1920, 1080));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        mailoublie = new QLineEdit(mdpoublie_page);
        mailoublie->setObjectName("mailoublie");
        mailoublie->setGeometry(QRect(50, 220, 351, 24));
        label_7 = new QLabel(mdpoublie_page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 110, 871, 81));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: white;\n"
"font: 600 12pt \"Segoe UI\";"));
        bt_envoyer_mail = new QPushButton(mdpoublie_page);
        bt_envoyer_mail->setObjectName("bt_envoyer_mail");
        bt_envoyer_mail->setGeometry(QRect(50, 270, 80, 24));
        retour_login = new QPushButton(mdpoublie_page);
        retour_login->setObjectName("retour_login");
        retour_login->setGeometry(QRect(40, 670, 231, 24));
        label_11 = new QLabel(mdpoublie_page);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1600, 10, 191, 181));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        bt_confirmer_code = new QPushButton(mdpoublie_page);
        bt_confirmer_code->setObjectName("bt_confirmer_code");
        bt_confirmer_code->setGeometry(QRect(50, 420, 80, 24));
        code_mdp = new QLineEdit(mdpoublie_page);
        code_mdp->setObjectName("code_mdp");
        code_mdp->setGeometry(QRect(50, 370, 351, 24));
        menu_page = new QGroupBox(centralwidget);
        menu_page->setObjectName("menu_page");
        menu_page->setGeometry(QRect(0, 0, 1920, 1080));
        label_8 = new QLabel(menu_page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 0, 1920, 1080));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        label_9 = new QLabel(menu_page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 150, 411, 131));
        label_9->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 600 16pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"font: 22pt \"Segoe UI\";\n"
"font: 700 22pt \"Segoe UI\";\n"
""));
        pushButton_7 = new QPushButton(menu_page);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(50, 460, 201, 41));
        pushButton_8 = new QPushButton(menu_page);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(50, 390, 201, 41));
        aller_gestion_employe = new QPushButton(menu_page);
        aller_gestion_employe->setObjectName("aller_gestion_employe");
        aller_gestion_employe->setGeometry(QRect(50, 330, 201, 41));
        pushButton_10 = new QPushButton(menu_page);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(50, 530, 201, 41));
        bt_go_to_equipe = new QPushButton(menu_page);
        bt_go_to_equipe->setObjectName("bt_go_to_equipe");
        bt_go_to_equipe->setGeometry(QRect(50, 590, 201, 41));
        label_10 = new QLabel(menu_page);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1600, 10, 191, 181));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/logo.png")));
        page_equipe_meilleur = new QGroupBox(centralwidget);
        page_equipe_meilleur->setObjectName("page_equipe_meilleur");
        page_equipe_meilleur->setGeometry(QRect(0, 0, 1920, 1080));
        bg_2 = new QLabel(page_equipe_meilleur);
        bg_2->setObjectName("bg_2");
        bg_2->setGeometry(QRect(0, 0, 1920, 1080));
        bg_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        label_13 = new QLabel(page_equipe_meilleur);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1610, 20, 301, 211));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        tableView_equipe_meilleur = new QTableView(page_equipe_meilleur);
        tableView_equipe_meilleur->setObjectName("tableView_equipe_meilleur");
        tableView_equipe_meilleur->setGeometry(QRect(880, 270, 841, 431));
        bt_go_to_acceuil = new QPushButton(page_equipe_meilleur);
        bt_go_to_acceuil->setObjectName("bt_go_to_acceuil");
        bt_go_to_acceuil->setGeometry(QRect(110, 170, 141, 51));
        label_23 = new QLabel(page_equipe_meilleur);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(1160, 130, 311, 121));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        page_equipe = new QGroupBox(centralwidget);
        page_equipe->setObjectName("page_equipe");
        page_equipe->setGeometry(QRect(0, 0, 1920, 1080));
        bg = new QLabel(page_equipe);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1920, 1080));
        bg->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/background_interface.jpg")));
        label_14 = new QLabel(page_equipe);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1620, 10, 281, 211));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        tableView_equipe = new QTableView(page_equipe);
        tableView_equipe->setObjectName("tableView_equipe");
        tableView_equipe->setGeometry(QRect(920, 230, 841, 431));
        label_15 = new QLabel(page_equipe);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(80, 280, 181, 61));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color:white;"));
        label_16 = new QLabel(page_equipe);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(80, 370, 181, 61));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color:white;"));
        label_17 = new QLabel(page_equipe);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(80, 460, 181, 61));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color:white;"));
        label_18 = new QLabel(page_equipe);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 530, 231, 61));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("color:white;"));
        label_19 = new QLabel(page_equipe);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(80, 610, 181, 61));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color:white;"));
        label_20 = new QLabel(page_equipe);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(80, 700, 181, 61));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("color:white;"));
        label_21 = new QLabel(page_equipe);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 780, 261, 61));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("color:white;"));
        nom_equipe = new QLineEdit(page_equipe);
        nom_equipe->setObjectName("nom_equipe");
        nom_equipe->setGeometry(QRect(290, 290, 311, 41));
        nationalite_equipe = new QComboBox(page_equipe);
        nationalite_equipe->addItem(QString());
        nationalite_equipe->addItem(QString());
        nationalite_equipe->addItem(QString());
        nationalite_equipe->addItem(QString());
        nationalite_equipe->addItem(QString());
        nationalite_equipe->addItem(QString());
        nationalite_equipe->setObjectName("nationalite_equipe");
        nationalite_equipe->setGeometry(QRect(290, 380, 311, 41));
        bt_insert = new QPushButton(page_equipe);
        bt_insert->setObjectName("bt_insert");
        bt_insert->setGeometry(QRect(280, 470, 121, 41));
        label_image_2 = new QLabel(page_equipe);
        label_image_2->setObjectName("label_image_2");
        label_image_2->setGeometry(QRect(650, 680, 201, 191));
        logo_equipe = new QLineEdit(page_equipe);
        logo_equipe->setObjectName("logo_equipe");
        logo_equipe->setGeometry(QRect(440, 470, 151, 41));
        date_creation_equipe = new QDateEdit(page_equipe);
        date_creation_equipe->setObjectName("date_creation_equipe");
        date_creation_equipe->setGeometry(QRect(290, 540, 301, 41));
        date_creation_equipe->setReadOnly(true);
        coach_equipe = new QLineEdit(page_equipe);
        coach_equipe->setObjectName("coach_equipe");
        coach_equipe->setGeometry(QRect(280, 620, 311, 41));
        nb_championnat_equipe = new QSpinBox(page_equipe);
        nb_championnat_equipe->setObjectName("nb_championnat_equipe");
        nb_championnat_equipe->setGeometry(QRect(330, 800, 61, 41));
        nb_joueur_equipe = new QLineEdit(page_equipe);
        nb_joueur_equipe->setObjectName("nb_joueur_equipe");
        nb_joueur_equipe->setGeometry(QRect(280, 710, 311, 41));
        bt_ajouter = new QPushButton(page_equipe);
        bt_ajouter->setObjectName("bt_ajouter");
        bt_ajouter->setGeometry(QRect(200, 910, 141, 51));
        bt_modifier = new QPushButton(page_equipe);
        bt_modifier->setObjectName("bt_modifier");
        bt_modifier->setGeometry(QRect(410, 910, 141, 51));
        bt_supprimer = new QPushButton(page_equipe);
        bt_supprimer->setObjectName("bt_supprimer");
        bt_supprimer->setGeometry(QRect(1640, 680, 111, 41));
        combo_nom_equipe = new QComboBox(page_equipe);
        combo_nom_equipe->setObjectName("combo_nom_equipe");
        combo_nom_equipe->setGeometry(QRect(1640, 730, 111, 41));
        label_22 = new QLabel(page_equipe);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(210, 100, 291, 101));
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("color:white;"));
        chercher = new QLineEdit(page_equipe);
        chercher->setObjectName("chercher");
        chercher->setGeometry(QRect(1400, 170, 141, 41));
        combo_ordre = new QComboBox(page_equipe);
        combo_ordre->addItem(QString());
        combo_ordre->addItem(QString());
        combo_ordre->setObjectName("combo_ordre");
        combo_ordre->setGeometry(QRect(1110, 170, 111, 41));
        combo_choix = new QComboBox(page_equipe);
        combo_choix->addItem(QString());
        combo_choix->addItem(QString());
        combo_choix->addItem(QString());
        combo_choix->addItem(QString());
        combo_choix->addItem(QString());
        combo_choix->addItem(QString());
        combo_choix->setObjectName("combo_choix");
        combo_choix->setGeometry(QRect(1260, 170, 111, 41));
        bt_tri = new QPushButton(page_equipe);
        bt_tri->setObjectName("bt_tri");
        bt_tri->setGeometry(QRect(980, 170, 101, 41));
        bt_pdf = new QPushButton(page_equipe);
        bt_pdf->setObjectName("bt_pdf");
        bt_pdf->setGeometry(QRect(900, 670, 101, 41));
        label_stat_2 = new QLabel(page_equipe);
        label_stat_2->setObjectName("label_stat_2");
        label_stat_2->setGeometry(QRect(1060, 600, 511, 281));
        bt_go_to_page_meilleur = new QPushButton(page_equipe);
        bt_go_to_page_meilleur->setObjectName("bt_go_to_page_meilleur");
        bt_go_to_page_meilleur->setGeometry(QRect(1650, 830, 141, 51));
        bg->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        label_21->raise();
        label_image_2->raise();
        label_22->raise();
        label_stat_2->raise();
        nom_equipe->raise();
        nationalite_equipe->raise();
        bt_insert->raise();
        logo_equipe->raise();
        date_creation_equipe->raise();
        coach_equipe->raise();
        nb_championnat_equipe->raise();
        nb_joueur_equipe->raise();
        bt_ajouter->raise();
        bt_modifier->raise();
        bt_supprimer->raise();
        combo_nom_equipe->raise();
        chercher->raise();
        combo_ordre->raise();
        combo_choix->raise();
        bt_tri->raise();
        bt_pdf->raise();
        tableView_equipe->raise();
        bt_go_to_page_meilleur->raise();
        MainWindow->setCentralWidget(centralwidget);
        signup_page->raise();
        menu_page->raise();
        login_page->raise();
        mdpoublie_page->raise();
        page_equipe->raise();
        page_equipe_meilleur->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1853, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login_page->setTitle(QString());
        bg_login->setText(QString());
        login_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez entrer votre identifiant", nullptr));
        login_mdp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez entrer votre mot de passe", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Adresse Mail :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de Passe :", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Mot de passe oubli\303\251?", nullptr));
        mdpoubli->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "WELCOME TO PROBALL MANGER ", nullptr));
        label_12->setText(QString());
        signup_page->setTitle(QString());
        bg_signup->setText(QString());
        mail_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez saisir l'adresse mail", nullptr));
        nom_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez saisir le nom", nullptr));
        prenom_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez saisir le pr\303\251nom", nullptr));
        mdp_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cr\303\251er le mot de passe", nullptr));
        mdp_2_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Confirmer le mot de passe", nullptr));
        sexe_employe->setItemText(0, QCoreApplication::translate("MainWindow", "Entrez le sexe", nullptr));
        sexe_employe->setItemText(1, QCoreApplication::translate("MainWindow", "Homme", nullptr));
        sexe_employe->setItemText(2, QCoreApplication::translate("MainWindow", "Femme", nullptr));
        sexe_employe->setItemText(3, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        salaire_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez saisir le salaire", nullptr));
        poste_employe->setItemText(0, QCoreApplication::translate("MainWindow", "Entrez le poste", nullptr));
        poste_employe->setItemText(1, QCoreApplication::translate("MainWindow", "Ressources Humaines", nullptr));
        poste_employe->setItemText(2, QCoreApplication::translate("MainWindow", "Chef des matches", nullptr));
        poste_employe->setItemText(3, QCoreApplication::translate("MainWindow", "Chef des stades", nullptr));
        poste_employe->setItemText(4, QCoreApplication::translate("MainWindow", "Coach ", nullptr));

        inserer_image->setText(QCoreApplication::translate("MainWindow", "Ins\303\251rez une photo", nullptr));
        label_image->setText(QString());
        ajouter_employe->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        modifier_employe->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        choix_tri_employe->setItemText(0, QCoreApplication::translate("MainWindow", "----", nullptr));
        choix_tri_employe->setItemText(1, QCoreApplication::translate("MainWindow", "NOM_EMPLOYE", nullptr));
        choix_tri_employe->setItemText(2, QCoreApplication::translate("MainWindow", "PRENOM_EMPLOYE", nullptr));
        choix_tri_employe->setItemText(3, QCoreApplication::translate("MainWindow", "POSTE_EMPLOYE", nullptr));

        chercher_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche...", nullptr));
        bt_tri_employe->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        PDF_EMPLOYE->setText(QCoreApplication::translate("MainWindow", "Exportation PDF", nullptr));
        choix_ordre_employe->setItemText(0, QCoreApplication::translate("MainWindow", "ascendant", nullptr));
        choix_ordre_employe->setItemText(1, QCoreApplication::translate("MainWindow", "descendant", nullptr));

        retour_menu->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        image_path_employe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Veuillez saisir le salaire", nullptr));
        label_6->setText(QString());
        supprimer_employe->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_stat->setText(QString());
        mdpoublie_page->setTitle(QString());
        label_3->setText(QString());
        mailoublie->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre adresse mail...", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Veuillez entrer votre adresse mail et attendez quelques secondes pour re\303\247evoir un code de v\303\251rification", nullptr));
        bt_envoyer_mail->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        retour_login->setText(QCoreApplication::translate("MainWindow", "Retour \303\240 la page d'acceuil", nullptr));
        label_11->setText(QString());
        bt_confirmer_code->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        code_mdp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le code", nullptr));
        menu_page->setTitle(QString());
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "CHOISISSEZ VOTRE ACTION", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Gestion des joueurs", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Gestion des matches", nullptr));
        aller_gestion_employe->setText(QCoreApplication::translate("MainWindow", "Gestion des employ\303\251s", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Gestion des stades", nullptr));
        bt_go_to_equipe->setText(QCoreApplication::translate("MainWindow", "Gestion des equipes", nullptr));
        label_10->setText(QString());
        page_equipe_meilleur->setTitle(QString());
        bg_2->setText(QString());
        label_13->setText(QString());
        bt_go_to_acceuil->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Meilleur Score", nullptr));
        page_equipe->setTitle(QString());
        bg->setText(QString());
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Nationalite ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "LOGO", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "DATE_CREATION", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "COACH", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "NB JOUEUR", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "NB CHAMPIONNAT", nullptr));
        nationalite_equipe->setItemText(0, QCoreApplication::translate("MainWindow", "Tunisian", nullptr));
        nationalite_equipe->setItemText(1, QCoreApplication::translate("MainWindow", "French", nullptr));
        nationalite_equipe->setItemText(2, QCoreApplication::translate("MainWindow", "Italian", nullptr));
        nationalite_equipe->setItemText(3, QCoreApplication::translate("MainWindow", "German", nullptr));
        nationalite_equipe->setItemText(4, QCoreApplication::translate("MainWindow", "English", nullptr));
        nationalite_equipe->setItemText(5, QCoreApplication::translate("MainWindow", "Spanish", nullptr));

        bt_insert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        label_image_2->setText(QString());
        bt_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        bt_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        bt_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Gestion Equipe", nullptr));
        chercher->setPlaceholderText(QCoreApplication::translate("MainWindow", "chercher", nullptr));
        combo_ordre->setItemText(0, QCoreApplication::translate("MainWindow", "ASC", nullptr));
        combo_ordre->setItemText(1, QCoreApplication::translate("MainWindow", "DESC", nullptr));

        combo_choix->setItemText(0, QCoreApplication::translate("MainWindow", "NOM_EQUIPE", nullptr));
        combo_choix->setItemText(1, QCoreApplication::translate("MainWindow", "NATIONALITE_EQUIPE", nullptr));
        combo_choix->setItemText(2, QCoreApplication::translate("MainWindow", "DATE_CREATION", nullptr));
        combo_choix->setItemText(3, QCoreApplication::translate("MainWindow", "COACH_EQUIPE", nullptr));
        combo_choix->setItemText(4, QCoreApplication::translate("MainWindow", "NOMBRE_JOUEURS", nullptr));
        combo_choix->setItemText(5, QCoreApplication::translate("MainWindow", "CHAMPIONNAT", nullptr));

        bt_tri->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        bt_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_stat_2->setText(QString());
        bt_go_to_page_meilleur->setText(QCoreApplication::translate("MainWindow", "Meilleur Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
