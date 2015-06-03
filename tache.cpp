#include "tache.h"


// ///////                        CONSTRUCTEUR TACHE
tache::tache(const string& i, const string& t, const Date& d, const Date& e){
	if (e<d) { //opérateur < renvoie true si e avant d (op < surchargé dans timing.h)
		this->id=i;
		this->titre=t;
		this->dispo=d;
		this->echeance=e;
	}
	//ne pas initialiser contructeur renvoyer erreur
	else cout<<"Erreur d'intialisation"<<endl;
	//est ce qu'on le ferait pas plutot avec exception ?
}

/////                           CONSTRUCTEUR DE UNITAIRE

unitaire::unitaire(const string& i, const string& t, const Date& di, const Date& e, const bool p, Duree& du, const Horaire& de){
	tache::tache(i, t, di, e);
	this->preempt=p;
	if (this->preempt)	  //verification de prempt avant de changer duree
		this->duree=du;
    else this->duree=-1;
	this->debut=de;
}

////    PERMET QU UN PROJET AIT SA DISPO = AU MIN DES DISPO DE SES TACHES UNITAIRE ET DE MEME POUR ECHANCHE (AVEC MAX)
/*
Date projet::getDispo(){ //dispo de tache composite = min de toutes les dispo qu'elle contient
	Date min= children[0]->getDispo();
	for (int i = 1; i < children.size(); i++){
		Date tmp=children[i]->getDispo();
		if(tmp<min)
			min=tmp;
	}
	return min;
}

Date projet::getEcheance(){ //eche de tache composite = max de toutes les eche qu'elle contient
	Date max= children[0]->getEcheance();
		for (int i = 1; i < children.size(); i++){
			Date tmp=children[i]->getEcheance();
			if(tmp>max)
				max=tmp;
		}
	return max;
}*/

///// AFFICHAGE ////

void unitaire::afficher(ostream& f=cout){
	f<<"Nom de la tâche : "<<titre<<endl;
	f<<"Début : "<<dispo<<endl;
	f<<"Fin : "<<echeance<<endl;
	if(preempt) //pq pas utilisation de this ici ?
		f<<"Tâche preemptive d'une durée de : "<<duree<<"h"<<endl;
	else f<<"Tâche non preemptive"<<endl;
	f<<"Heure de début : "<<debut<<endl;
}

void composite::afficher(ostream& f=cout){
	f<<"Nom de la tâche : "<<titre<<endl;
	f<<"Début : "<<dispo<<endl;
	f<<"Fin : "<<echeance<<endl;
}
