#ifndef EQUIPE_H
#define EQUIPE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class equipe
{
public:
    equipe();
    equipe(QString, QString , QDate, QByteArray, QString, int, int);
    equipe(int,QString,QString ,QDate,QByteArray,QString,int,int);

    void setIdEquipe(int id);
    int getIDEquipe();
    // Getters for each attribute
    QString getNomEquipe() const {
        return nom_equipe;
    }

    QString getNationalite() const {
        return nationalite;
    }

    QDate getDateCreation() const {
        return date_creation;
    }

    QByteArray  getLogo() const {
        return logo;
    }

    QString getCoach() const {
        return coach;
    }

    int getNbJoueur() const {
        return nb_joueur;
    }

    int getNbChampionnat() const {
        return nb_championnat;
    }

    // Setters for each attribute
    void setNomEquipe(const QString& nom) {
        nom_equipe = nom;
    }

    void setNationalite(const QString& nation) {
        nationalite = nation;
    }

    void setDateCreation(const QDate& date) {
        date_creation = date;
    }

    void setLogo(const QByteArray & logoPath) {
        logo = logoPath;
    }

    void setCoach(const QString& coachName) {
        coach = coachName;
    }

    void setNbJoueur(int nombre) {
        nb_joueur = nombre;
    }

    void setNbChampionnat(int nombre) {
        nb_championnat = nombre;
    }
    bool ajouter(QString nom_equipe,QString nationalite,QDate date_creation,QByteArray logo,QString coach,int nb_joueur,int nb_championnat);
    QSqlQueryModel* afficher();
    bool chercherEquipe(QString nom_equipe);
    bool modifier(int id_equipe,QString nom_equipe,QString nationalite,QDate date_creation,QByteArray logo,QString coach,int nb_joueur,int nb_championnat);
    int chercherIDEquipeByNom(QString nom_equipe);
    QByteArray chercherLogoEquipeByNom(QString nom_equipe);
    bool supprimer(int id_equipe);

    QSqlQueryModel* chercher(QString choix, QString  text);
    QSqlQueryModel* tri(QString choix, QString  ordre);
    int countNationalite(const QString& nat);
    QSqlQueryModel* afficher_meilleur();

private:
    int id_equipe;
    QString nom_equipe;
    QString nationalite;
    QDate date_creation;
    QByteArray logo;

    QString coach;
    int nb_joueur;
    int nb_championnat;
};

#endif // EQUIPE_H
