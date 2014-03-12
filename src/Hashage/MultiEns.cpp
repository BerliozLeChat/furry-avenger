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
    if(this->ens.estCle(elt))
        nb = this->ens.valeurAssociee(elt);
    else
        nb = 0;
    return nb;
}

template <typename T>
void MultiEnsemble<T>::fusionner(MultiEnsemble me){//fusionne deux ensembles
	vector<T> clefs();
	int N=0;
	me->ens.trousseau(clefs,&N);
	for(T clef : clefs){ 
		//TODO A finir
	}

}

template <typename T>
MultiEnsemble<T> MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
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
