/*
* File : Hashage.hpp
* Fichier contenant la déclaration de la classe Hashage
* Authors : Francois Hallereau & Sébastien Vallée
*/


#ifndef HASHAGE_H
#define HASHAGE_H

#include "AList.hpp"
#define TAILLE 50 //taille fixe de la table de hashage

//---------------------------------------




template <typename K,typename V>
class Hashage{
	private:

		AList<K,V> list[TAILLE];

	public :
		Hashage();
		~Hashage();
		int hash(K clf);
		void associer(K clf,V valr); //ajoute le couple (clf,valr) ou change la valeur associée à clf s'il y en avait une
		void afficher();//permet d'afficher la table de hashage
		bool estVide(); //VRAI ssi aucun couple n'est stocké
		V valeurAssociee(K clf); //donne la valeur associée à la clef clf
		void dissocier(K clf); //supprime le couple (clf,.) ; ne fait rien s'il n'y en a pas
		bool estClef(K clf); //teste l'existence d'un couple (clf,.)
		void trousseau(K* clfs, int &N ); // mets les clefs présentes dans le tableau pointé par clfs (à déclarer à l'extérieur) et mets dans N leur nombre

};

#include "Hashage.cpp"

//---------------------------------------
#endif
