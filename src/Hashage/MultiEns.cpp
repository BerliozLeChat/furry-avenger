/*
   Fichier MultiEns.cpp

   Définition des méthodes de MultiEns

   Antoine Boutruche & François Hallereau & Sébastien Vallée

*/


 // utile pour les fonctions mathématique
#include <sstream> // pour les conversions en chaine
#include <iostream>


template <typename T>
MultiEnsemble<T>::MultiEnsemble(){
	}//constructeur
	
template <typename T>
	MultiEnsemble<T>::MultiEnsemble(T tab[]){//constructeur

		for (int i = 0; i < sizeof(tab); i++){
			this->ens.ajouter(tab[i]);
		}

	}

template <typename T>
MultiEnsemble<T>::~MultiEnsemble(){
	
	}//destructeur


template <typename T>
void MultiEnsemble<T>::ajouter(T elt){//ajoute un élément
    if(this->ens.estClef(elt)){//il faut incrémenter si présent
        
        this->ens.associer(elt,this->ens.valeurAssociee(elt)+1);
    }
    else{
        this->ens.associer(elt,1); //sinon on l'ajoute
    }

}

template <typename T>
void MultiEnsemble<T>::afficher(){
		cout<<"[";
		this->ens.afficher();
		cout<<"]"<<endl;
}



template <typename T>
void MultiEnsemble<T>::oteUn(T elt){//ote l'élément passé en paramètre
    if(this->ens.estClef(elt)){
        if(this->ens.valeurAssociee(elt)>1){
            this->ens.associer(elt,this->ens.valeurAssociee(elt)-1);
        }
        else{
            this->ens.dissocier(elt);
        }
    }
}

template <typename T>
void MultiEnsemble<T>::oteTous(T elt){//Ote tous les éléments elt de l'ensemble
    if(this->ens.estClef(elt)){
        this->ens.dissocier(elt);
    }
}

template <typename T>
bool MultiEnsemble<T>::estVide(){//Vrai si est vide
    return this->ens.estVide();
}

template <typename T>
int MultiEnsemble<T>::nbOcc(T elt){//Retourne le nombre d'occurence d'elt
    int nb;
    if(this->ens.estClef(elt))
        nb = this->ens.valeurAssociee(elt);
    else
        nb = 0;
    return nb;
}

template <typename T>
void MultiEnsemble<T>::fusionner(MultiEnsemble me){//fusionne deux ensembles
	T * clefs = new T[1000];
	int N=0;
	int i;
	me.ens.trousseau(clefs,N);
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){
			this->ens.associer(clefs[i],this->ens.valeurAssociee(clefs[i])+me.ens.valeurAssociee(clefs[i]));
		}
		else{
			this->ens.associer(clefs[i],me.ens.valeurAssociee(clefs[i]));
		}
	}

}

template <typename T>
MultiEnsemble<T> MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
	int M =0;	
	int i;
	MultiEnsemble<T> * inter = new MultiEnsemble<T>();
	T * clefs = new T[1000];
	this->ens.trousseau(clefs,M);
	for(i=0;i<M;++i){//pour toutes les clés de this
		if(me.ens.estClef(clefs[i])){ //on teste si elles sont dans me
			if(this->ens.valeurAssociee(clefs[i])>me.ens.valeurAssociee(clefs[i])){//on ajoute la cle dans inter avec sa valeur (plus petite occurence des deux MultiEns) 
				inter->ens.associer(clefs[i],me.ens.valeurAssociee(clefs[i]));
			}
			else{
				inter->ens.associer(clefs[i],this->ens.valeurAssociee(clefs[i]));
			}
		}
		
	}
	return *inter;
}

template <typename T>
void MultiEnsemble<T>::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles
	int occurence;
	T * clefs = new T[1000];
	int N=0;
	int i;
	me.ens.trousseau(clefs,N);
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){
			occurence = this->ens.valeurAssociee(clefs[i])-me.ens.valeurAssociee(clefs[i]);
			if(occurence<=0){
				this->ens.dissocier(clefs[i]);
			}else{
				this->ens.associer(clefs[i],occurence);
			}
		}
	}
}

template <typename T>
bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents
	bool res=true;
	int i;
	T * clefs = new T[1000];
	int N=0;
	me.ens.trousseau(clefs,N);
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){
			if(this->ens.valeurAssociee(clefs[i])!=me.ens.valeurAssociee(clefs[i])){
				res = false;
			}
		}
		else{
			res=false;
		}
	}
	return res;
}
