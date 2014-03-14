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
            this->ens.associer(elt,this->ens.valeurAssociee(elt)-1);//-1 si il y a plus de 2 occurrences
        }
        else{
            this->ens.dissocier(elt);//sinon on supprime la clé
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
	me.ens.trousseau(clefs,N);//on récupère les clés
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){//si elle est clé
			this->ens.associer(clefs[i],this->ens.valeurAssociee(clefs[i])+me.ens.valeurAssociee(clefs[i]));//on additionne les valeurs associées
		}
		else{
			this->ens.associer(clefs[i],me.ens.valeurAssociee(clefs[i]));//sinon on crée la clé
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
	me.ens.trousseau(clefs,N); //on récupère les clés de me
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){//si elle appartient a this
			occurence = this->ens.valeurAssociee(clefs[i])-me.ens.valeurAssociee(clefs[i]);//on soustrait les valeurs associées
			if(occurence<=0){
				this->ens.dissocier(clefs[i]);//si c'est inférieur ou égal a 0 on supprime la clé
			}else{
				this->ens.associer(clefs[i],occurence);//sinon  on modifie la valeur associée
			}
		}
	}
}

template <typename T>
bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents
	bool res=true;
	int i;
	T * clefs = new T[1000];
	//l'galité de 2 ensembles correspond a la double inclusion
	//on teste l'inclusion dans un sens
	int N=0;
	me.ens.trousseau(clefs,N);//on récupère les clé
	for(i=0;i<N;++i){ 
		if(this->ens.estClef(clefs[i])){//si la clé appartient
			if(this->ens.valeurAssociee(clefs[i])!=me.ens.valeurAssociee(clefs[i])){//on compare les occurrences
				res = false;
			}
		}
		else{
			res=false;//la clé n'appartient pas
		}
	}
	
	//puis dans l'autre
	N=0;
	clefs = new T[1000];
	this->ens.trousseau(clefs,N);
	for(i=0;i<N;++i){ 
		if(me.ens.estClef(clefs[i])){
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
