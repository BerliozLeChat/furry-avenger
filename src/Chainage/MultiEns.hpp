/*
   Fichier MultiEns.hpp

   Définition du type MultiEns
*/

#ifndef MULTIENS_HPP
#define MULTIENS_HPP

#include <string> // pour le type std::string

template <typename T>
class MultiEnsemble{


	private :

		struct _maille{
			T elt;
			_maille * suivant;
		};
		typedef struct _maille _maille;

		_maille * tete;
		int nbElement;

	public :
		MultiEnsemble();//constructeur
		MultiEnsemble(T tab[]); // constructeur avec liste en parametre
		void ajouter(T elt);//ajoute un élément
		void oteUn(T elt);//ote l'élément passé en paramètre
		void oteTous(T elt);//ote tous les éléments elt de l'ensemble
		bool estVide();//vrai si est vide
		int nbOcc(T elt);//retourne le nombre d'occurence d'elt
		void fusionner(MultiEnsemble me);//fusionne deux ensembles
		MultiEnsemble intersecte(MultiEnsemble me);//donne l'intersection de deux ensembles
		void enleve(MultiEnsemble me);//enlève l'intersection de deux ensembles
		bool egal(MultiEnsemble me);//vrai si les ensembles sont équivalents
};



/******************************************************************************/
#include "MultiEns.cpp"
#endif // MULTIENS_HPP


