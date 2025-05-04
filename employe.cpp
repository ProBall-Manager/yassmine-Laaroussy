#include "employe.h"
#include "qsqlquery.h"




// Constructeur sans paramètre
employe::employe() {
    id_employe = 0;
    nom_employe = "";
    prenom_employe = "";
    date_embauche_employe = QDate();
    sexe_employe = "";
    salaire_employe = 0;
    poste_employe = "";
    email_employe = "";
    mdp_employe = "";
    img_employe = "";
}

// Constructeur avec id_employe et nom_employe (et d'autres si nécessaire)
employe::employe(int id, QString nom, QString prenom, QDate date_embauche, QString sexe, int salaire, QString poste, QString email, QString mdp, QString img) {
    id_employe = id;
    nom_employe = nom;
    prenom_employe = prenom;
    date_embauche_employe = date_embauche;
    sexe_employe = sexe;
    salaire_employe = salaire;
    poste_employe = poste;
    email_employe = email;
    mdp_employe = mdp;
    img_employe = img;
}
// Constructeur avec id_employe et nom_employe (et d'autres si nécessaire)
employe::employe(QString nom, QString prenom, QDate date_embauche, QString sexe, int salaire, QString poste, QString email, QString mdp, QString img) {
    nom_employe = nom;
    prenom_employe = prenom;
    date_embauche_employe = date_embauche;
    sexe_employe = sexe;
    salaire_employe = salaire;
    poste_employe = poste;
    email_employe = email;
    mdp_employe = mdp;
    img_employe = img;
}
int employe::getId_employe()
{
    return id_employe;
}
void employe::setId_employe(int id_employe)
{
    this->id_employe=id_employe;
}

QString employe::getnom_employe()
{
    return nom_employe;
}
void employe::setnom_employe(QString nom_employe)
{
    this->nom_employe=nom_employe;

}

QString employe::getprenom_employe()
{
    return prenom_employe;
}
void employe::setprenom_employe(QString prenom_employe)
{
    this->prenom_employe=prenom_employe;

}

QDate employe::getdate_embauche_employe()
{
    return date_embauche_employe;
}
void employe::setdate_embauche_employe(QDate date_embauche_employe)

{
    this->date_embauche_employe=date_embauche_employe;

}
QString employe::getsexe_employe()
{
    return sexe_employe;
}
void employe::setsexe_employe(QString sexe_employe)
{
    this->sexe_employe=sexe_employe;
}

int employe::getsalaire_employe()
{
    return salaire_employe;
}
void employe::setsalaire_employe(int salaire_employe)
{
    this->salaire_employe=salaire_employe;
}


QString employe::getposte_employe(){
    return poste_employe;
}
void employe::setposte_employe(QString poste_employe)
{
    this->poste_employe=poste_employe;
}

QString employe::getemail_employe()
{
    return email_employe;
}
void employe::setemail_employe(QString email_employe)
{
    this->email_employe=email_employe;
}

QString employe::getmdp_employe()
{
    return mdp_employe;
}
void employe::setmdp_employe(QString mdp_employe)
{
    this->mdp_employe=mdp_employe;
}

QString employe::getimg_employe()
{
    return img_employe;
}
void employe::setimg_employe(QString img_employe)
{
    this->img_employe=img_employe;
}

QSqlQueryModel * employe::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EMPLOYE,PRENOM_EMPLOYE,DATE_EMBAUCHE_EMPLOYE,SEXE_EMPLOYE,SALAIRE_EMPLOYE,POSTE_EMPLOYE,EMAIL_EMPLOYE FROM EMPLOYE");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date Embauche"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Adresse Mail"));




    return model;




}


bool employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (NOM_EMPLOYE,PRENOM_EMPLOYE,DATE_EMBAUCHE_EMPLOYE,SEXE_EMPLOYE,SALAIRE_EMPLOYE,POSTE_EMPLOYE,EMAIL_EMPLOYE,MDP_EMPLOYE,IMG_EMPLOYE)"
                  "Values(:nom_employe,:prenom,:date,:sexe,:salaire,:poste,:email,:mdp,:img)");
    query.bindValue(":nom_employe",nom_employe);
    query.bindValue(":prenom",prenom_employe);
    query.bindValue(":date",date_embauche_employe);
    query.bindValue(":sexe",sexe_employe);
    query.bindValue(":salaire",salaire_employe);
    query.bindValue(":poste",poste_employe);
    query.bindValue(":email",email_employe);
    query.bindValue(":mdp",mdp_employe);
    query.bindValue(":img",img_employe);



    return query.exec();


}

bool employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM_EMPLOYE=:nom_employe , PRENOM_EMPLOYE=:prenom , DATE_EMBAUCHE_EMPLOYE=:date , SEXE_EMPLOYE=:sexe , SALAIRE_EMPLOYE=:salaire , POSTE_EMPLOYE=:poste , EMAIL_EMPLOYE=:email , MDP_EMPLOYE=:mdp , IMG_EMPLOYE=:img WHERE ID_EMPLOYE=:ID");
    query.bindValue(":nom_employe",nom_employe);
    query.bindValue(":prenom",prenom_employe);
    query.bindValue(":date",date_embauche_employe);
    query.bindValue(":sexe",sexe_employe);
    query.bindValue(":salaire",salaire_employe);
    query.bindValue(":poste",poste_employe);
    query.bindValue(":email",email_employe);
    query.bindValue(":mdp",mdp_employe);
    query.bindValue(":img",img_employe);
    query.bindValue(":ID",id_employe);



    return query.exec();

}

int employe::chercher_IDbyEmail(QString email)
{
    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE FROM EMPLOYE WHERE EMAIL_EMPLOYE=:email");
    query.bindValue(":email",email);
    if (query.exec()&&query.next())
    {
        int ID=query.value(0).toInt();

        return ID;
    }
    return 0;

}

bool employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE  FROM EMPLOYE WHERE ID_EMPLOYE=:id");
    query.bindValue(":id",id);
    return query.exec();

}


QSqlQueryModel * employe::tri(QString choix,QString ordre)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EMPLOYE,PRENOM_EMPLOYE,DATE_EMBAUCHE_EMPLOYE,SEXE_EMPLOYE,SALAIRE_EMPLOYE,POSTE_EMPLOYE,EMAIL_EMPLOYE FROM EMPLOYE ORDER BY "+choix+" "+ordre);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date Embauche"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Adresse Mail"));




    return model;




}

QSqlQueryModel * employe::chercher(QString choix,QString text)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT NOM_EMPLOYE,PRENOM_EMPLOYE,DATE_EMBAUCHE_EMPLOYE,SEXE_EMPLOYE,SALAIRE_EMPLOYE,POSTE_EMPLOYE,EMAIL_EMPLOYE FROM EMPLOYE WHERE "+choix+" LIKE '%"+text+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date Embauche"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Adresse Mail"));




    return model;




}

int employe::countPoste(const QString& poste)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(POSTE_EMPLOYE) FROM EMPLOYE WHERE POSTE_EMPLOYE = :poste");
    query.bindValue(":poste", poste);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}

QString employe::chercher_PathByEmail(QString email)
{
    QSqlQuery query;
    query.prepare("SELECT IMG_EMPLOYE FROM EMPLOYE WHERE EMAIL_EMPLOYE=:email");
    query.bindValue(":email",email);
    if (query.exec()&&query.next())
    {
        QString path=query.value(0).toString();

        return path;
    }
    return "";

}
