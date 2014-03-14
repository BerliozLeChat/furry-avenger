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

		_maille * tete; //pointeur sur le maillon de la chaine
		int nbElement;// le nombre d'elements presents dans le chainage

	public :
		MultiEnsemble();//constructeur
		void ajouter(T elt);//ajoute un élément{pre-condition : None; post-condition: element ajoute, nbElement+1}
		void afficher(); // permet d'afficher le multi Ensemble{pre-condition : None; post-condition: MultiEnsemble affiche}
		void oteUn(T elt);//ote l'élément passé en paramètre{pre-condition : None; post-condition: None}
		void oteTous(T elt);//ote tous les éléments elt de l'ensemble{pre-condition : None; post-condition: None}
		bool estVide();//vrai si est vide{pre-condition : None; post-condition: None}
		int nbOcc(T elt);//retourne le nombre d'occurence d'elt{pre-condition : None; post-condition: None}
		void fusionner(MultiEnsemble me);//fusionne deux ensembles{pre-condition : None; post-condition: this->nbelement =this->nbElement+me->nbElement ,me->nbElement= me->nbElement }
		MultiEnsemble intersecte(MultiEnsemble me);//donne l'intersection de deux ensembles{pre-condition : None; post-condition: intersection->nbElement<=this->nbElement, intersection->nbElement<=me->nbElement, me et this conservé}
		void enleve(MultiEnsemble me);//enlève l'intersection de deux ensembles{pre-condition : None; post-condition: me conserve}
		bool egal(MultiEnsemble me);//vrai si les ensembles sont équivalents{pre-condition : None; post-condition: me et this conserve}
};



/******************************************************************************/
#include "MultiEns.cpp"
#endif // MULTIENS_HPP


