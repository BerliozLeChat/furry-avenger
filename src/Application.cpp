#include <iostream>
using namespace std;
//#include "Chainage/MultiEns.hpp" //MultiEns utilisant le chainage
#include "Hashage/MultiEns.hpp"    //MultiEns utilisant une table de hashage


int main(){
//creation des multiEnsembles necessaires à l'application//
	MultiEnsemble<int> * Quentin = new MultiEnsemble<int>();
		Quentin->ajouter(1);
		Quentin->ajouter(2);
		Quentin->ajouter(3);
		Quentin->ajouter(4);
		Quentin->ajouter(5);
		Quentin->ajouter(6);
		Quentin->ajouter(54);

	MultiEnsemble<int> * Pierre = new MultiEnsemble<int>();

	MultiEnsemble<int> * Antoine = new MultiEnsemble<int>();
		Antoine->ajouter(5);
		Antoine->ajouter(8);
		Antoine->ajouter(7);
		Antoine->ajouter(4);
		Antoine->ajouter(2);

	MultiEnsemble<int> * Camille = new MultiEnsemble<int>();
		Camille->ajouter(4);
		Camille->ajouter(5);
		Camille->ajouter(8);
		Camille->ajouter(7);
		Camille->ajouter(2);
		Camille->ajouter(2);

	MultiEnsemble<int> * Alexis = new MultiEnsemble<int>();
		Alexis->ajouter(1);
		Alexis->ajouter(3);
		Alexis->ajouter(5);
		Alexis->ajouter(7);
		Alexis->ajouter(2);
		Alexis->ajouter(4);
		Alexis->ajouter(6);

	//debut du traitement//
	cout<<" [{ Voici nos ensembles de départ : }] "<<endl;
		cout<<"Quentin :";Quentin->afficher();cout<<endl;
		cout<<"Pierre :";Pierre->afficher();cout<<endl;
		cout<<"Antoine :";Antoine->afficher();cout<<endl;
		cout<<"Camille :";Camille->afficher();cout<<endl;
		cout<<"Alexis :";Alexis->afficher();cout<<endl;
	cout<<endl;
	

	cout<<" [{ Pierre est-il vide ?: 	vrai attendu! }] "<<endl;
		if(Pierre->estVide())//si pierre est vide
				cout<<"Pierre qui roule n amasse pas mousse"<<endl;
		else//s'il n'est pas vide
			cout<<"La nature est incomprehensible"<<endl;
		cout<<endl;

	cout<<"[{ affichage d Alexis : 7 élements attendu ! }]"<<endl;
		Alexis->afficher();
	cout<<endl;

	cout<<"[{Alexis est-il egal a Quentin ? : vrai(1) attendu ! }]"<<endl;
        cout<<"Alexis : ";Alexis->afficher();
        cout<<"Quentin : ";Quentin->afficher();
		cout<<"TEST EGALITE :"<<Alexis->egal(*Quentin)<<endl;
	cout<<"[{ Mais... l'inverse est-il vrai ?: vrai(1) attendu ! }]"<<endl;//permet de voir que l integrite de Quentin a ete conserve
		cout<<"TEST EGALITE :"<<Quentin->egal(*Alexis)<<endl;
	cout<<endl;

	cout<<"[{ Et qu en est il de Camille et Antoine ?: faux(0) attendu ! }]"<<endl;
		cout<<"Camille : ";Camille->afficher();
		cout<<"Antoine : ";Antoine->afficher();
		cout<<"TEST EGALITE :"<<Camille->egal(*Antoine)<<endl;
	cout<<"[{ Non... ont-il tout de meme des elements communs ?: 5 elements attendus }]"<<endl;
		MultiEnsemble<int>  intersectionCA = Camille->intersecte(*Antoine);
		cout<<"INTERSECTION :";intersectionCA.afficher();
	cout<<"[{ Bon soit, et que donnerait une fusion des deux ?: 11 elements attendus }]"<<endl;
		Camille->fusionner(*Antoine);
		cout<<"Camille :";Camille->afficher();
	cout<<"[{ D accord... mais si on enleve tous ce qui fait Antoine de Camille... ?: 6 elements attendus }]"<<endl;
		Camille->enleve(*Antoine);
		cout<<"Camille :";Camille->afficher();
	cout<<"[{ interessant... et l inverse, ca doit donc donner... ?: 0 elements attendus }]"<<endl;
		Antoine->enleve(*Camille);
		cout<<"Antoine :";Antoine->afficher();
	cout<<endl;

	cout<<"[{ Bien, maintenant est-il possible d'avoir autre chose qu un ensemble vide avec Pierre si on lui ote un element au hasard ?: 0 element attendu }]"<<endl;
		Pierre->oteTous(3);cout<<"--on lui ote tous les 3"<<endl;
		cout<<"Pierre :";Pierre->afficher();
	cout<<"[{ Ajoutons des éléments à Pierre et comptons le nombre d'occurence de certains nombres ?: resultat 3 attendu |resultat 1 attendu |resultat 0 attendu }]"<<endl;
		Pierre->ajouter(1);cout<<"--on lui ajoute 1"<<endl;
		Pierre->ajouter(1);cout<<"--on lui ajoute 1"<<endl;
        Pierre->ajouter(5);cout<<"--on lui ajoute 5"<<endl;
		Pierre->ajouter(1);cout<<"--on lui ajoute 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | nombre de 5 :"<<Pierre->nbOcc(5)<<" | nombre de 8 :"<<Pierre->nbOcc(8)<<endl;
	cout<<"[{ C est genial... affinons notre apport ?: resultat 2 attendu | resultat 0 attendu | resultat 1 attendu }]"<<endl;
		Pierre->oteUn(1);cout<<"--on lui ote une occurence de 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | "<<endl;

		Pierre->oteTous(1);cout<<"--on lui ote tous ses 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | ";

		cout<<"nombre de 5 :"<<Pierre->nbOcc(5)<<endl;
	cout<<endl;

	cout<<"[{ ------Testons quelques axiomes et nous libererons les sujets------ }]"<<endl;
	//oteTous(ajouter(mul,x),x)=oteTous(mul,x)
		cout<<"axiome => oteTous(ajouter(mul,x),x)=oteTous(mul,x) "<<endl;
			cout<<"[{ sujet 1 avant manipulation genetique }]"<<endl;
				Quentin->afficher();
			cout<<"[{ sujet 2 avant manipulation genetique }]"<<endl;
				Alexis->afficher();
			cout<<"[{ Avant l operation, les sujets sont-il égaux ?: vrai(1) attendu }]"<<endl;
				cout<<"TEST EGALITE :"<<Quentin->egal(*Alexis)<<endl;
			cout<<"[{ sujet 1 apres manipulation genetique ?:  }]"<<endl;
				cout<<"--on lui ajoute 3";Quentin->ajouter(3);cout<<endl;
				cout<<"--on lui ote tous ses 3";Quentin->oteTous(3);cout<<endl;
				Quentin->afficher();
			cout<<"[{ sujet 2 apres manipulation genetique ?:  }]"<<endl;
				cout<<"--on lui ote tous ses 3";Alexis->oteTous(3);cout<<endl;
				Alexis->afficher();
			cout<<"[{ l operation est-elle un succes ?: vrai(1) attendu }]"<<endl;
				cout<<"TEST EGALITE :"<<Quentin->egal(*Alexis)<<endl;
		cout<<endl;



	return 0;
}
