#include <iostream>
using namespace std;
//#include "Chainage/MultiEns.hpp"
#include "Hashage/MultiEns.hpp"


int main(){
	bool vide;
	MultiEnsemble<int> * monEnsemble4 = new MultiEnsemble<int>();
	vide=monEnsemble4->estVide();
	cout<<vide<<endl;
	monEnsemble4->ajouter(1);
	monEnsemble4->afficher();
	return 0;
}
