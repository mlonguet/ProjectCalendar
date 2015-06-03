#ifndef TD4_LO21_Tache_h
#define TD4_LO21_Tache_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "timing.h"

using namespace std;
using namespace TIME;

class CalendarException{

public:
    CalendarException(const string& message):info(message){}
    string getInfo() const { return info; }

private:
    string info;
};



  /////////      UTILISATION DU DESIGN PATTERN COMPOSITE        //////////
/// avoir une implémentation de type dossier/fichier, afin qu'un ensemble d'élement (dossier) soit traité comme élement unique


class tache
{
	protected:   //permet aux classes filles d'y accéder
		string id;
		string titre;
		Date dispo; //début de la tache
		Date echeance; //fin de la tache

	public:
		//constructeur définit à l'extérieur de la classe
		virtual ~tache() =0;// surcharge nécessaire pour supprimer tout ce que contient composite (ou juste unitaire)a lros verif que la tache est finie ? à voir
		string getId() const {return id;}                  //accesseures en lecture
		string getTitre() const {return titre;}           //accesseures en lecture
		virtual Date getDispo() =0 {return dispo;}           //accesseures en lecture  // à override
		virtual Date getEcheance() =0 {return echeance;}    //accesseures en lecture   // à override
		// gerer les pb de precedence et suivant
		virtual void afficher(ostream& f=cout) const ;

};


class unitaire : public tache
{
		Duree duree;
		bool preempt;
		Horaire debut;

	public:
		unitaire(const string& i, const string& t, const Date& di, const Date& e, const bool p, Duree& du, const Horaire& de); //remarque : durée <12h mais existe que si preemt=1
		~unitaire(); // à voir
		Duree getDuree() const {return duree;}
		Horaire getHoraire() {return debut;}
		Date getDispo() const {return dispo;}           //accesseures en lecture
		Date getEcheance() const {return echeance;}    //accesseures en lecture
		void afficher(ostream& f=cout) const ;
};


class composite : public tache
{
		vector<tache*>children;   //tableau de tache et vector taile variable children = dossier fils je crois
		//composition avec tache unitaire
	public:
		composite(arguments);
		~composite();  // À CHANGER
		Date getDispo() const {return dispo;}           //accesseures en lecture
		Date getEcheance() const {return echeance;}    //accesseures en lecture
        void afficher(ostream& f=cout) const ;
        void Add(tache* ele){
        	children.push_back(ele);
    	}


/*
void printSalary(int level)
    {
        for(int j=0; j < level; ++j) cout << "\t";
        cout << "Manager : " <<  this->m_fullName.c_str() <<
            ",salary: " << m_valueSalary << "$\n";

        if(!m_children.empty())
        {
            for(int x=0; x < level; ++x) cout << "\t";
            cout << "Subordinates  of " <<
                m_fullName.c_str() << ":\n";
            ++level;
            for (int i = 0; i < m_children.size(); ++i)
              m_children[i]->printSalary(level);
        }
    }*/

};

class projet
{
	string titre;
	Date dispo;
	Date echeance;
public:
	projet(arguments);
	~projet();
	string getString() const {return titre;}
	Date getDispo();         //ici les get sont en fait des set, écrivent les dispo et echeance
	Date getEcheance();

	/* data */
};

#endif

//oublie pas de gérer AFFICHAGE !!!!!
