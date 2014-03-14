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
	MultiEnsemble<T>::MultiEnsemble(T tab[]){//constructeur

		this->nbElement=0;
		this->tete=NULL;
		for (int i = 0; i <= (int)sizeof(tab); i++){
			this->ajouter(tab[i]);
		}

	}



template <typename T>
	void MultiEnsemble<T>::ajouter(T elt){//ajoute un élément
		_maille * maillon = new _maille();
		maillon->elt = elt;
		maillon->suivant=NULL;
		_maille * pointeur = this->tete;
		if(this->estVide()){
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
   void MultiEnsemble<T>::afficher(){
        _maille * pointeur = this->tete;
        cout<<"[";
        while(pointeur!=NULL){
            if(pointeur->suivant!=NULL)
                cout<<pointeur->elt<<",";
            else
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
				bool trouve = false;
				while(pointeur!=NULL && trouve==false){
					if(pointeur->elt==elt){
						if(pointeurPrecedent!=NULL){
							trouve=true;
							_maille * tmp=pointeur->suivant;
							delete(pointeur);
							this->nbElement=this->nbElement-1;
							pointeurPrecedent->suivant=tmp;
						}
						else{
							this->tete=pointeur->suivant;
							delete(pointeur);
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
				while(pointeur!=NULL){

					if(pointeur->elt==elt){
						if(pointeurPrecedent!=NULL){
							_maille * tmp=pointeur->suivant;
							delete(pointeur);
							this->nbElement=this->nbElement-1;
							pointeurPrecedent->suivant=tmp;
						}
						else{
							this->tete=pointeur->suivant;
							delete(pointeur);
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
		if(this->nbElement!=0){
				_maille * pointeur=this->tete;
                while(pointeur!=NULL){

					if(pointeur->elt==elt){
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

			while(pointeur!=NULL){
					this->ajouter(pointeur->elt);
					pointeur=pointeur->suivant;
			}

	}
	template <typename T>
	MultiEnsemble<T> MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
			MultiEnsemble<T> * iste = new MultiEnsemble<T>();

            MultiEnsemble<T> * copie = new MultiEnsemble<T>();
            copie->fusionner(me);

			_maille * pointeurThis = this->tete;
			_maille * pointeurMe = copie->tete;

			while(pointeurThis!=NULL){
				T recherche = pointeurThis->elt;
				bool trouve=false;
					while(pointeurMe!=NULL && trouve == false){
						if(pointeurMe->elt==recherche){
								trouve = true;
								iste->ajouter(recherche);
								copie->oteUn(recherche);
								/*******modifier le MultiEnsemble passé en paramètre ?? *******/
						}else
							pointeurMe = pointeurMe->suivant;
					}

					pointeurMe = copie->tete;
					pointeurThis = pointeurThis->suivant;
			}
			cout<<"blabla";
			copie->afficher();
			cout<<endl;

			return *iste;


	}
	template <typename T>
	void MultiEnsemble<T>::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles

            _maille * pointeurMe = me.tete;

			while(pointeurMe!=NULL){
				this->oteUn(pointeurMe->elt);
				pointeurMe = pointeurMe->suivant;
			}
	}
	template <typename T>
	bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents

            MultiEnsemble<T> * copie = new MultiEnsemble<T>();
            copie->fusionner(me);
            _maille * pointeurThis = this->tete;
			_maille * pointeurMe = copie->tete;

			bool resultat=false;

			if(this->nbElement == copie->nbElement){
				bool trouve;
				while(pointeurThis!=NULL){
					T recherche = pointeurThis->elt;
					trouve=false;
						while(pointeurMe!=NULL && trouve == false){
							if(pointeurMe->elt==recherche){
									trouve = true;
                                    copie->oteUn(recherche);
									cout<<"trouve"<<endl;
							}else
								pointeurMe = pointeurMe->suivant;

						}

						pointeurMe = copie->tete;
						pointeurThis = pointeurThis->suivant;

				}
				if(copie->estVide()){
					resultat = true;
				}
			}

			return resultat;
	}
