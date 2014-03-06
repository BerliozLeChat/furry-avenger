/*
* File : AList.cpp
* Fichier contenant l'implémentation de la classe AList
* Authors : Francois Hallereau & Sébastien Vallée
*/

#include "AList.hpp"

template <typename K, typename V>
AList<K,V>::AList(){
	this->tete = NULL;
	this->queue=NULL;
	this->nb=0;
}

template <typename K, typename V>
AList<K,V>::~AList(){

}
template <typename K, typename V>
void AList<K,V>::associer(K clf,V valr){
	bool trouve=false;
	maillon<K,V> * courant = this->tete;
		while(courant != NULL && trouve==false){
				if(courant->clf==clf){
					trouve=true;
				}
				else{
					courant = courant->suivant;
				}
		}
		if(trouve==false){
			maillon<K,V> * mama;
			mama->suivant=NULL;
			mama->clf=clf;
			mama->elt=valr;
			this->queue=mama;
			this->nb++;
		}
		else{
			courant->elt=valr;
		}
}

template <typename K, typename V>
bool AList<K,V>::estALVide(){
		return(this->nb==0);
}

template <typename K, typename V>
V AList<K,V>::valeurAssociee(K clf){
	if(this->nb!=0){
        bool trouve=false;
		maillon<K,V> * courant = this->tete;
		while(courant != NULL && trouve==false){
			if(courant->clf==clf){
				trouve=true;
			}
			else{
				courant = courant->suivant;
			}
		}
		if(trouve==true){
				return courant->elt;
			}
		else
			return NULL;
	}
}
template <typename K, typename V>
void AList<K,V>::dissocier(K clf){
    bool trouve=false;
	maillon<K,V> * courant = this->tete;
		if(this->nb >= 1){
			courant=this->tete;
			if(courant->clf == clf){
				this->tete=courant->suivant;
				delete(courant);
			}
			else{
					trouve=false;
					while(courant->suivant != NULL && trouve ==false){
						if(courant->suivant->clf==clf){
							trouve=true;
						}
						else{
							courant=courant->suivant;
						}
					}
					if(trouve==true){
							maillon<K,V> * tmp = courant->suivant->suivant;
							delete(courant->suivant);
							courant->suivant=tmp;
					}
			}
		}
}

template <typename K, typename V>
bool AList<K,V>::estClef(K cle){

		if(this->nb==0){
			return false;
		}
		else{
				bool trouve=false;
				maillon<K,V> * courant = this->tete;
				while(courant != NULL && trouve==false){
						if(courant->clf==cle){
							trouve=true;
						}
					courant = courant->suivant;
				}
				return trouve;
		}
}
template <typename K, typename V>
void AList<K,V>::trousseau(K* clfs, int N ){
		if(this->nb!=0){
				maillon<K,V> * courant=this->tete;
				N=0;

				while(courant != NULL){
					clfs[N] = courant->clf;
					N = N + 1;
					courant=courant->suivant;
				}

		}
		else{
				N=0;
		}
}


