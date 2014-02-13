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
		typedef struct _maille _maille;
		struct _maille{
			T elt;
			_maille * suivant;	
		};
		
		_maille * tete;
		int nbElement;

	public :
		MultiEnsemble();//constructeur
		void ajouter(T elt);//ajoute un élément
		~ oteUn(T elt);//ote l'élément passé en paramètre
		~ oteTous(T elt);//ote tous les éléments elt de l'ensemble
		bool estVide();//vrai si est vide
		int nbOcc(T elt);//retourne le nombre d'occurence d'elt
		void fusionner(MultiEnsemble me);//fusionne deux ensembles
		MultiEnsemble intersecte(MultiEnsemble me);//donne l'intersection de deux ensembles
		void enleve(MultiEnsemble me);//enlève l'intersection de deux ensembles
		bool egal(MultiEnsemble me);//vrai si les ensembles sont équivalents
}



/******************************************************************************/

#endif // MULTIENS_HPP
