#include "equipe.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
equipe::equipe()
    : id_equipe(0),
      nom_equipe(""),
      nationalite(""),
      date_creation(QDate::currentDate()),
      logo(QByteArray()),
      coach(""),
      nb_joueur(0),
      nb_championnat(0)
{

}
void equipe::setIdEquipe(int id)
{
    this->id_equipe=id;

}
int equipe::getIDEquipe()
{

    return id_equipe;
}
equipe::equipe(int id_equipe,QString nom_equipe,QString nationalite,QDate date_creation,QByteArray logo,QString coach,int nb_joueur,int nb_championnat)
{
    this->id_equipe=id_equipe;
    this->nom_equipe =nom_equipe;
    this-> nationalite=nationalite;
    this-> date_creation=date_creation;
    this-> logo=logo;
    this-> coach=coach;
    this-> nb_joueur=nb_joueur;
    this->nb_joueur =nb_joueur;
    this->nb_championnat=nb_championnat;

}
equipe::equipe(QString nom_equipe, QString nationalite, QDate date_creation, QByteArray logo, QString coach, int nb_joueur, int nb_championnat)
{
    this->nom_equipe = nom_equipe;
    this->nationalite = nationalite;
    this->date_creation = date_creation;
    this->logo = logo;
    this->coach = coach;
    this->nb_joueur = nb_joueur;
    this->nb_championnat = nb_championnat;
}

bool equipe::ajouter(QString nom_equipe, QString nationalite, QDate date_creation, QByteArray logo, QString coach, int nb_joueur, int nb_championnat)
{


    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPE (NOM_EQUIPE, NATIONALITE_EQUIPE, DATE_CREATION, COACH_EQUIPE, NOMBRE_JOUEURS, CHAMPIONNAT, LOGO_EQUIPE) "
                  "VALUES (:nom, :nationalite, :date, :coach, :nb_j, :nb_c, :logo)");

    query.bindValue(":nom", nom_equipe);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":date", date_creation);
    query.bindValue(":coach", coach);
    query.bindValue(":nb_j", nb_joueur);
    query.bindValue(":nb_c", nb_championnat);
    query.bindValue(":logo", logo);

   return query.exec();
}
bool equipe::chercherEquipe(QString nom_equipe)
{
    QSqlQuery query;
    query.prepare("SELECT NOM_EQUIPE FROM EQUIPE WHERE NOM_EQUIPE = :eq");
    query.bindValue(":eq", nom_equipe);

    // Execute the query
    if (query.exec()) {
        // Check if a result is returned
        if (query.next()) {
            // Return true if the team name exists
            return true;
        }
    }

    // Return false if no team name was found or if there was an error
    return false;
}

QSqlQueryModel* equipe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EQUIPE,NATIONALITE_EQUIPE,DATE_CREATION,COACH_EQUIPE,NOMBRE_JOUEURS,CHAMPIONNAT FROM EQUIPE");
    return model;

}

bool equipe::modifier(int id_equipe, QString nom_equipe, QString nationalite, QDate date_creation, QByteArray logo, QString coach, int nb_joueur, int nb_championnat)
{


    QSqlQuery query;
    query.prepare("UPDATE EQUIPE SET NOM_EQUIPE = :nom, NATIONALITE_EQUIPE = :nationalite, "
                  "DATE_CREATION = :date, COACH_EQUIPE = :coach, NOMBRE_JOUEURS = :nb_j, "
                  "CHAMPIONNAT = :nb_c, LOGO_EQUIPE = :logo WHERE ID_EQUIPE = :id");

    query.bindValue(":nom", nom_equipe);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":date", date_creation);
    query.bindValue(":coach", coach);
    query.bindValue(":nb_j", nb_joueur);
    query.bindValue(":nb_c", nb_championnat);
    query.bindValue(":logo", logo);
    query.bindValue(":id", id_equipe);

   return query.exec();
}

int equipe::chercherIDEquipeByNom(QString nom_equipe)
{
    QSqlQuery query;
    int id=0;
    query.prepare("SELECT ID_EQUIPE FROM EQUIPE WHERE NOM_EQUIPE = :eq");
    query.bindValue(":eq", nom_equipe);

    // Execute the query
    if (query.exec()) {
        // Check if a result is returned
        if (query.next()) {

            id =query.value(0).toInt();
        }
    }

    // Return false if no team name was found or if there was an error
    return id;
}

QByteArray equipe::chercherLogoEquipeByNom(QString nom_equipe)
{
    QSqlQuery query;
    QByteArray logo; // Initialize as empty QByteArray
    query.prepare("SELECT LOGO_EQUIPE FROM EQUIPE WHERE NOM_EQUIPE = :eq");
    query.bindValue(":eq", nom_equipe);

    if (query.exec()) {
        if (query.next()) {
            logo = query.value(0).toByteArray();
        }
    }

    return logo;
}


bool equipe::supprimer(int id_equipe)
{

QSqlQuery query;
query.prepare("DELETE  FROM EQUIPE WHERE ID_EQUIPE=:id");

query.bindValue(":id",id_equipe);

return query.exec();

}

QSqlQueryModel* equipe::chercher(QString choix, QString  text)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EQUIPE,NATIONALITE_EQUIPE,DATE_CREATION,COACH_EQUIPE,NOMBRE_JOUEURS,CHAMPIONNAT FROM EQUIPE WHERE "+choix+" LIKE '%"+text+"%'");
    return model;

}

QSqlQueryModel* equipe::tri(QString choix, QString  ordre)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EQUIPE,NATIONALITE_EQUIPE,DATE_CREATION,COACH_EQUIPE,NOMBRE_JOUEURS,CHAMPIONNAT FROM EQUIPE ORDER BY "+choix+" "+ordre);
    return model;

}

int equipe::countNationalite(const QString& nat)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(NATIONALITE_EQUIPE) FROM EQUIPE WHERE NATIONALITE_EQUIPE = :nat");
    query.bindValue(":nat", nat);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}



QSqlQueryModel* equipe::afficher_meilleur()

    {
        QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT eq.NOM_EQUIPE, eq.COACH_EQUIPE, SUM(p.score) AS Score "
                        "FROM EQUIPE eq "
                        "JOIN participe p ON eq.ID_EQUIPE = p.ID_EQUIPE "
                        "GROUP BY eq.NOM_EQUIPE, eq.COACH_EQUIPE "
                        "ORDER BY Score DESC");

        return model;
    }



