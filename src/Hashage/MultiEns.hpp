/*
   Fichier MultiEns.hpp

   Définition du type MultiEns
*/

#ifndef MULTIENS_HPP
#define MULTIENS_HPP

#include "Hashage.hpp"

template <typename T>
class MultiEnsemble{


	private :
        Hashage<T,int> ens;

	public :
		MultiEnsemble();//constructeur
		MultiEnsemble(T tab[]); // constructeur prenant une liste en parametre
		~MultiEnsemble();//destructeur
		void ajouter(T elt);//ajoute un élément
		void afficher();// permet d'afficher le multi Ensemble
		void oteUn(T elt);//ote l'élément passé en paramètre
		void oteTous(T elt);//ote tous les éléments elt de l'ensemble
		bool estVide();//vrai si est vide
		int nbOcc(T elt);//retourne le nombre d'occurence d'elt
		void fusionner(MultiEnsemble me);//fusionne deux ensembles
		MultiEnsemble intersecte(MultiEnsemble me);//donne l'intersection de deux ensembles
		void enleve(MultiEnsemble me);//enlève l'intersection de deux ensembles
		bool egal(MultiEnsemble me);//vrai si les ensembles sont équivalents
};

#include "MultiEns.cpp"


/******************************************************************************/

#endif // MULTIENS_HPP


