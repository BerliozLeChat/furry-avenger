/*
* File : AList.hpp
* Fichier contenant la déclaration de la classe AList
* Authors : Francois Hallereau & Sébastien Vallée
*/


#ifndef ALIST_H
#define ALIST_H
#include <vector>
#include <iostream>

//---------------------------------------


template <typename K, typename V>
struct maillon{
	K clf;
	V elt;
	maillon * suivant;
};


template <typename K, typename V>
class AList{
	private:
		struct maillon<K,V> * tete;
		int nb;

	public :

		AList();// constructeur, crée une AListe vide
		~AList(); // destructeur, libère la mémoire
		void associer(K clf,V valr); //ajoute le couple (clf,valr) ou change la valeur associée à clf s'il y en avait une
		void afficher();//permet d'afficher la liste
		bool estALVide(); //VRAI ssi aucun couple n'est stocké
		V valeurAssociee(K clf); //donne la valeur associée à la clef clf
		void dissocier(K clf);//supprime le couple (clf,.) ; ne fait rien s'il n'y en a pas
		bool estClef(K clf); //teste l'existence d'un couple (clf,.)
		void trousseau(K* clfs, int &N ); // mets les clefs présentes dans le tableau pointé par clfs (à déclarer à l'extérieur) et mets dans N leur nombre

};

#include "AList.cpp"
//---------------------------------------
#endif
