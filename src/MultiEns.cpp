/* 
   Fichier MultiEns.cpp

   Définition des méthodes de MultiEns
   
   Antoine Boutruche & François Hallereau & Sébastien Vallée
   
   par les créateur de furry-hypster, ils reviennent encore plus fort. #furry-avenger
     
*/


 // utile pour les fonctions mathématique
#include <sstream> // pour les conversions en chaine



using namespace std;

template <typename T>
	MultiEnsemble<T>::MultiEnsemble(){//constructeur
		this->tete=NULL;
		this->nbElement=0;
	}
	template <typename T>
	void MultiEnsemble<T>::ajouter(T elt){//ajoute un élément
		_maille * maillon;
		maillon->elt = elt;
		maillon->suivant=NULL;
		_maillon * pointeur = this->tete;
		if(this->nbELement==0){
			this->tete=maillon;
		}
		else{
			while(pointeur->suivant!=NULL){
				pointeur=pointeur->suivant;
			}
			pointeur->suivant=maillon;
		}
		
		this->nbElement=this->nbElement+1;
			
	}	
	template <typename T>
	void MultiEnsemble<T>::oteUn(T elt){//ote l'élément passé en paramètre
		if(this->nbElement!=0){
				_maille * pointeurPrecedent=NULL;
				_maille * pointeur=this->tete;
				bool trouve = false;
				while(pointeur!=NULL && trouve==false){
					
					if(pointeur->elt==elt){
						if(pointeurPrecedent!=NULL){
							trouve=true;
							_maille * tmp=pointeur->suivant;
							delete(pointeur);
							pointeurPrecedent->suivant=tmp;
						}
						else{
							this->tete=pointeur->suivant;
							delete(pointeur);
						}
					}
					pointeurPrecedent=pointeur;
					pointeur=pointeur->suivant;
						
				}
				
		}
	}
	template <typename T>
	void MultiEnsemble<T>::oteTous(T elt){//Ote tous les éléments elt de l'ensemble
		return 0;
	}
	template <typename T>
	bool MultiEnsemble<T>::estVide(){//Vrai si est vide
		return 0;
	}
	template <typename T>
	int MultiEnsemble<T>::nbOcc(T elt){//Retourne le nombre d'occurence d'elt
		return 0;
	}
	template <typename T>
	void MultiEnsemble<T>::fusionner(MultiEnsemble me){//fusionne deux ensembles
			return 0;
	}
	template <typename T>
	MultiEnsemble MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
			return 0;
	}
	template <typename T>
	void MultiEnsemble<T>::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles
			return 0;
	}
	template <typename T>
	bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents
			return 0;
	}
