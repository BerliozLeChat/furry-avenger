/* 
   Fichier MultiEns.cpp

   Définition des méthodes de MultiEns
   
   Antoine Boutruche & François Hallereau & Sébastien Vallée
   
   par les créateur de furry-hypster, ils reviennent encore plus fort. #furry-avenger
     
*/

#include "MultiEns.hpp"
#include <cmath> // utile pour les fonctions mathématique
#include <sstream> // pour les conversions en chaine



using namespace std;

class MultiEnsemble{
		private :
			
		
		public :
	
}

	MultiEnsemble::MultiEnsemble(){//constructeur
	}
	void MultiEnsemble::ajouter(T elt){//ajoute un élément
	}	
	~ MultiEnsemble::oteUn(T elt){//ote l'élément passé en paramètre
	}
	~ MultiEnsemble::oteTous(T elt){//Ote tous les éléments elt de l'ensemble
	}
	bool MultiEnsemble::estVide(){//Vrai si est vide
	}
	int MultiEnsemble::nbOcc(T elt){//Retourne le nombre d'occurence d'elt
	}
	void MultiEnsemble::fusionner(MultiEnsemble me){//fusionne deux ensembles
	}
	MultiEnsemble MultiEnsemble::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
	}
	void MultiEnsemble::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles
	}
	bool MultiEnsemble::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents
	}
