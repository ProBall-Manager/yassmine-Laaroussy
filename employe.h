#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>


class employe
{
public:
    employe();

    employe(int id, QString nom, QString prenom, QDate date_embauche, QString sexe, int salaire, QString poste, QString email, QString mdp, QString img) ;
    employe( QString nom, QString prenom, QDate date_embauche, QString sexe, int salaire, QString poste, QString email, QString mdp, QString img) ;


    int getId_employe();
    void setId_employe(int id);

    QString getnom_employe();
    void setnom_employe(QString nom);

    QString getprenom_employe();
    void setprenom_employe(QString prenom);

    QDate getdate_embauche_employe();
    void setdate_embauche_employe(QDate date);

    QString getsexe_employe();
    void setsexe_employe(QString sexe);

    int getsalaire_employe();
    void setsalaire_employe(int salaire);


    QString getposte_employe();
    void setposte_employe(QString poste);

    QString getemail_employe();
    void setemail_employe(QString email);

    QString getmdp_employe();
    void setmdp_employe(QString mdp);

    QString getimg_employe();
    void setimg_employe(QString image);

    //les fonctions du crud
    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier();
    int chercher_IDbyEmail(QString email);
    bool supprimer(int id);


    QSqlQueryModel * chercher(QString choix,QString text);
    QSqlQueryModel * tri(QString choix,QString ordre);

    int countPoste(const QString& poste);
    QString chercher_PathByEmail(QString email);


private:
    int id_employe;
    QString nom_employe;
    QString prenom_employe;
    QDate date_embauche_employe;
    QString sexe_employe;
    int salaire_employe;
    QString poste_employe;
    QString email_employe;
    QString mdp_employe;
    QString img_employe;





};

#endif // EMPLOYE_H
