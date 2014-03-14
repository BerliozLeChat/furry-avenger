#include <iostream>
using namespace std;
#include "Chainage/MultiEns.hpp"
//#include "Hashage/MultiEns.hpp"


int main(){
	//creation des multi Ensemble necessaire à l'application//
	//int qq[7]={1,2,3,4,5,6,7};
	MultiEnsemble<int> * Quentin = new MultiEnsemble<int>();
		Quentin->ajouter(1);
		Quentin->ajouter(2);
		Quentin->ajouter(3);
		Quentin->ajouter(4);
		Quentin->ajouter(5);
		Quentin->ajouter(6);
		Quentin->ajouter(7);

	MultiEnsemble<int> * Pierre = new MultiEnsemble<int>();

	//int aa[5]={5,8,7,4,2};
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

	//debut de traitement//

	cout<<" [{ Pierre est-il vide ?: 	vrai attendu! }] "<<endl;
		if(Pierre->estVide())//si pierre est vide
				cout<<"Pierre qui roule n amasse pas mousse"<<endl;
		else
			cout<<"La nature est incomprehensible"<<endl;
		cout<<endl;

	cout<<"[{ affichage d Alexis : 7 élements attendu ! }]"<<endl;
		Alexis->afficher();
	cout<<endl;

	cout<<"[{Alexis est-il egal a Quentin ? : vrai attendu ! }]"<<endl;
        Alexis->   afficher();
        Quentin->afficher();
		cout<<Alexis->egal(*Quentin)<<endl;
		Alexis->afficher();
        Quentin->afficher();
	cout<<"[{ Mais... l'inverse est-il vrai ?: vrai attendu ! }]"<<endl;//permet de voir que l integrite de Quentin est conserve
		Alexis->afficher();
        Quentin->afficher();
		cout<<Quentin->egal(*Alexis)<<endl;
		Alexis->afficher();
        Quentin->afficher();
	cout<<endl;

	cout<<"[{ Et qu en est il de Camille et Antoine ?: faux attendu ! }]"<<endl;
		cout<<Camille->egal(*Antoine)<<endl;
	cout<<"[{ Non... ont-il tout de meme des elements communs ?: 5 elements attendus }]"<<endl;
		MultiEnsemble<int>  intersectionCA = Camille->intersecte(*Antoine);
		intersectionCA.afficher();
	cout<<"[{ Bon soit, et que donnerait une fusion des deux ?: 11 elements attendus }]"<<endl;
		Camille->fusionner(*Antoine);
		Camille->afficher();
	cout<<"[{ D accord... mais si on enleve tous ce qui fait Antoine de Camille... ?: 6 elements attendus }]"<<endl;
		Camille->enleve(*Antoine);
		Camille->afficher();
	cout<<"[{ interessant... et l inverse, ca doit donc donner... ?: 0 elements attendus }]"<<endl;
		Antoine->enleve(*Camille);
		Antoine->afficher();
	cout<<endl;

	cout<<"[{ Bien, maintenant est-il possible d'avoir autre chose qu un ensemble vide avec Pierre si on lui ote un element au hasard ?: 0 element attendu }]"<<endl;
		Pierre->oteTous(3);cout<<"on lui ote tous les 3"<<endl;
		Pierre->afficher();
	cout<<"[{ Ajoutons des éléments à Pierre et comptons le nombre d'occurence de certains nombres ?: resultat 3 attendu |resultat 1 attendu |resultat 0 attendu }]"<<endl;
		Pierre->ajouter(1);cout<<"on ajoute 1"<<endl;
		Pierre->ajouter(1);cout<<"on ajoute 1"<<endl;
        Pierre->ajouter(5);cout<<"on ajoute 5"<<endl;
		Pierre->ajouter(1);cout<<"on ajoute 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | nombre de 5 :"<<Pierre->nbOcc(5)<<" | nombre de 8 :"<<Pierre->nbOcc(8)<<endl;;
	cout<<"[{ C est genial... affinons notre apport ?: resultat 2 attendu | resultat 0 attendu | resultat 1 attendu }]"<<endl;
		Pierre->oteUn(1);cout<<"on lui ote une occurence de 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | ";

		Pierre->oteTous(1);cout<<"on lui ote tous ses 1"<<endl;
		cout<<"nombre de 1 :"<<Pierre->nbOcc(1)<<" | ";

		cout<<"nombre de 5 :"<<Pierre->nbOcc(5)<<endl;;
	cout<<endl;

	cout<<"[{ ------Testons quelques axiomes et nous libererons les sujets------ }]"<<endl;
	//oteTous(ajouter(mul,x),x)=oteTous(mul,x)
		cout<<"axiome => oteTous(ajouter(mul,x),x)=oteTous(mul,x) "<<endl;
		cout<<" sujet 1 avant manipulation genetique "<<endl;
		Quentin->afficher();
		cout<<" sujet 2 avant manipulation genetique "<<endl;
		Alexis->afficher();
		cout<<" sujet 1 apres manipulation genetique ?:  "<<endl;
		Quentin->ajouter(3);
		Quentin->oteTous(3);
		Quentin->afficher();
		cout<<" sujet 2 apres manipulation genetique ?:  "<<endl;
		Alexis->oteTous(3);
		Alexis->afficher();
		cout<<" l operation est-elle un succes ?: vrai attendu "<<endl;
			cout<<Quentin->egal(*Alexis)<<endl;
		cout<<endl;

		cout<<"axiome => oteTous(ajouter(mul,x),x)=oteTous(mul,x) "<<endl;
		cout<<" sujet 1 avant manipulation genetique "<<endl;
		Quentin->afficher();
		cout<<" sujet 2 avant manipulation genetique "<<endl;
		Alexis->afficher();
		cout<<" sujet 1 apres manipulation genetique ?:  "<<endl;
		Quentin->ajouter(3);
		Quentin->oteTous(3);
		Quentin->afficher();
		cout<<" sujet 1 apres manipulation genetique ?:  "<<endl;
		Alexis->oteTous(3);
		Alexis->afficher();
		cout<<" l operation est-elle un succes ?: resultat positif attendu "<<endl;
			cout<<Quentin->egal(*Alexis)<<endl;
		cout<<endl;



	return 0;
}
