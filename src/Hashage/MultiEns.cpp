/*
   Fichier MultiEns.cpp

   Définition des méthodes de MultiEns

   Antoine Boutruche & François Hallereau & Sébastien Vallée

*/


 // utile pour les fonctions mathématique
#include <sstream> // pour les conversions en chaine
#include <iostream>
#include <algorithm> 


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
	me.ens.trousseau(clefs,&N);
	cout<<"{"<<N<<"}"<<endl;
	for(T clef:clefs){ 
		if(this->ens.estCle(clef)){
			this->ens.associer(clef,this->ens.valeurAssociee(clef)+me.ens.valeurAssociee(clef));
		}
		else{
			this->ens.associer(clef,me.ens.valeurAssociee(clef));
		}
	}

}

template <typename T>
MultiEnsemble<T> MultiEnsemble<T>::intersecte(MultiEnsemble me){//donne l'intersection de deux ensembles
	int N =0;
	int M =0;	
	MultiEnsemble<T> * inter = new MultiEnsemble<T>();
	vector<T> this_clefs();
	vector<T> me_clefs();
	vector<T> res;
	typename vector<T>::iterator iterateur;
	me.ens.trousseau(me_clefs,&N);
	this->ens.trousseau(this_clefs,&M);
	iterateur=set_intersection (this_clefs.begin(), this_clefs.end(), me_clefs.begin(), me_clefs.end(), res.begin());
	for(iterateur=res.begin(); iterateur!=res.end(); ++iterateur)
		inter->ens.associer(iterateur,this->ens.valeurAssociee(iterateur)+me.ens.valeurAssociee(iterateur));
	return inter;
}

template <typename T>
void MultiEnsemble<T>::enleve(MultiEnsemble me){//enlève l'intersection de deux ensembles
	int occurence;
	vector<T> clefs();
	int N=0;
	me.ens.trousseau(clefs,&N);
	cout<<"{"<<N<<"}"<<endl;
	for(T clef:clefs){ 
		if(this->ens.estCle(clef)){
			occurence = this->ens.valeurAssociee(clef)-me.ens.valeurAssociee(clef);
			if(occurence<=0){
				this->ens.dissocier(clef);
			}else{
				this->ens.associer(clef,occurence);
			}
		}
	}
}

template <typename T>
bool MultiEnsemble<T>::egal(MultiEnsemble me){//vrai si les ensembles sont équivalents
	return true;
}
