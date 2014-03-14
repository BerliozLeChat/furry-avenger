/*
   Fichier MultiEns.cpp

   Définition des méthodes de MultiEns

   Antoine Boutruche & François Hallereau & Sébastien Vallée
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
		_maille * maillon = new _maille();
		maillon->elt = elt;
		maillon->suivant=NULL;
		_maille * pointeur = this->tete;
		if(this->estVide()){//si la liste est vide
			this->tete=maillon;//on ajoute a la tete
		}
		else{
			while(pointeur->suivant!=NULL){//sinon on parcour l ensemble jusqu au dernier maillon
				pointeur=pointeur->suivant;
			}
			pointeur->suivant=maillon;//on ajoute l'objet
		}

		this->nbElement=this->nbElement+1;// on augmente le nombre d element de 1

	}

template <typename T>
   void MultiEnsemble<T>::afficher(){
        _maille * pointeur = this->tete;
        cout<<"[";
        while(pointeur!=NULL){//on parcour l ensemble
            if(pointeur->suivant!=NULL)//si il y a encore des element, on met une virgule pour separer de l element suivant
                cout<<pointeur->elt<<",";
            else //sinon on ne met pas de virgule
                cout<<pointeur->elt;
            pointeur=pointeur->suivant;
        }
        cout<<"]"<<endl;;
    }

template <typename T>
	void MultiEnsemble<T>::oteUn(T elt){//ote l'élément passé en paramètre
		if(this->nbElement!=0){
				_maille * pointeurPrecedent=NULL;
				_maille * pointeur=this->tete;
				bool trouve = false;//variable permettant de ne supprimer q une occurence
				while(pointeur!=NULL && trouve==false){
					if(pointeur->elt==elt){//si une occurence est trouve
						if(pointeurPrecedent!=NULL){//si l occurence est a la tete
							trouve=true;
							_maille * tmp=pointeur->suivant;
							delete(pointeur);//on supprime l occurence
							this->nbElement=this->nbElement-1;
							pointeurPrecedent->suivant=tmp;
						}
						else{
							this->tete=pointeur->suivant;
							delete(pointeur);//on supprime l occurence
							this->nbElement=this->nbElement-1;
							trouve=true;
						}
					}
					pointeurPrecedent=pointeur;
					pointeur=pointeur->suivant;

				}

		}
	}
	template <typename T>
	void MultiEnsemble<T>::oteTous(T elt){//Ote tous les éléments elt de l'ensemble
		if(this->nbElement!=0){
				_maille * pointeurPrecedent=NULL;
				_maille * pointeur=this->tete;
				while(pointeur!=NULL){//par cour de this

					if(pointeur->elt==elt){//si une occurence est trouve
						if(pointeurPrecedent!=NULL){//si l occurence se trouve a la tete
							_maille * tmp=pointeur->suivant;
							delete(pointeur);//on la supprime
							this->nbElement=this->nbElement-1;
							pointeurPrecedent->suivant=tmp;
						}
						else{//si l occurence est au minimum en deuxieme position
							this->tete=pointeur->suivant;
							delete(pointeur);//on la supprime
							this->nbElement=this->nbElement-1;
						}
					}
					pointeurPrecedent=pointeur;
					pointeur=pointeur->suivant;

				}

		}
	}
	template <typename T>
	bool MultiEnsemble<T>::estVide(){//Vrai si est vide
		return (this->nbElement==0);
	}
	template <typename T>
	int MultiEnsemble<T>::nbOcc(T elt){//Retourne le nombre d'occurence d'elt
        int compteur=0;
		if(this->nbElement!=0){//si l ensemble n est pas vide
				_maille * pointeur=this->tete;
                while(pointeur!=NULL){//parcour de l ensemble

					if(pointeur->elt==elt){//si une occurence trouver
						compteur = compteur+1;
					}
					pointeur=pointeur->suivant;

				}
        }
        return compteur;
	}
	template <typename T>
	void MultiEnsemble<T>::fusionner(MultiEnsemble me){//fusionne deux ensembles
			_maille * pointeur =  me.tete;

			while(pointeur!=NULL){//parcour de l ensemble me
					this->ajouter(pointeur->elt);
					pointeur=pointeur->suivant;
			}

	}
	template <typename T>
	MultiEnsemble<T> MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
			MultiEnsemble<T> * iste = new MultiEnsemble<T>();

            MultiEnsemble<T> * copie = new MultiEnsemble<T>();//copie de l ensemble passe en parametre
            copie->fusionner(me);

			_maille * pointeurThis = this->tete;
			_maille * pointeurMe = copie->tete;

			while(pointeurThis!=NULL){//parcour de l instance this
				T recherche = pointeurThis->elt;
				bool trouve=false;
					while(pointeurMe!=NULL && trouve == false){parcour de me
						if(pointeurMe->elt==recherche){//si un element commun est trouve
								trouve = true;
								iste->ajouter(recherche);//ajout dans l intersection
								copie->oteUn(recherche);//on retire l element commun dans la copie
								/*******modifier le MultiEnsemble passé en paramètre ?? *******/
						}else
							pointeurMe = pointeurMe->suivant;
					}

					pointeurMe = copie->tete;
					pointeurThis = pointeurThis->suivant;
			}
			cout<<endl;

			return *iste;


	}
	template <typename T>
	void MultiEnsemble<T>::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles

            _maille * pointeurMe = me.tete;

			while(pointeurMe!=NULL){//parcour du Multi ensemble me
				this->oteUn(pointeurMe->elt);
				pointeurMe = pointeurMe->suivant;
			}
	}
	template <typename T>
	bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents

            MultiEnsemble<T> * copie = new MultiEnsemble<T>();//creation d'une copie de l'ensemble passe en parametre
            copie->fusionner(me);
            _maille * pointeurThis = this->tete;
			_maille * pointeurMe = copie->tete;

			bool resultat=false;

			if(this->nbElement == copie->nbElement){//s'ils ont le meme nombre d element, ils ont des chances d etre egaux
				bool trouve;
				while(pointeurThis!=NULL){//parcour de tous les elements de l'instance this
					T recherche = pointeurThis->elt;
					trouve=false;
						while(pointeurMe!=NULL && trouve == false){//parcour de la copie de me
							if(pointeurMe->elt==recherche){
									trouve = true;
                                    copie->oteUn(recherche);//on retire l element commun
							}else
								pointeurMe = pointeurMe->suivant;

						}

						pointeurMe = copie->tete;
						pointeurThis = pointeurThis->suivant;

				}
				if(copie->estVide()){//si tous les elements de la copie sont enleve, les ensemble sont egaux (ils ont le même nombre d element)
					resultat = true;
				}
			}

			return resultat;
	}
