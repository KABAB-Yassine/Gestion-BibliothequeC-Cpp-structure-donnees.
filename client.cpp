#include <iostream>
#include <cstdio>
#include"client.h"
#include<iomanip>
using namespace std;

void clients::creer_client(){
        cout<<"\n NOUVELLE ENTRÉE DE client...\n";
        cout<<"\nEntrez Identifiant du client.  :";
        cin>>IDC;
        cout<<"\n\nEntrez le Nom du client :";
        gets(Nom);
        cout<<"\n\nEntrez L'Adresse du client. :";
        gets(Adresse);
        cout<<"\n\n\nEntrez le Numéro de téléphone du client. :";
        cin>>Tel;
        cout<<"\n\n\n\nEntrez la Date d’inscription du client. :";
        gets(Anciente);
        cout<<"\n\n\n client créé..";
}
void clients::afficher_client(){
        cout<<"\n Identifiant du client.  :"<<IDC;
        cout<<"\n\n le Nom du client :";
        puts(Nom);
        cout<<"\n\n L'Adresse du client. :";
        puts(Adresse);
        cout<<"\n\n\n le Numéro de téléphone du client. :"<<Tel;
        cout<<"\n\n\n\n la Date d’inscription du client. :";
        puts(Anciente);
}
void clients::modifier_client(){
    cout<<"\n Identifiant du client.  :"<<IDC;
        cout<<"\nEntrez Nouveau Identifiant du client.  :";
        cin>>IDC;
        cout<<"\n\nEntrez le nouveaux Nom du client :";
        gets(Nom);
        cout<<"\n\nEntrez La nouvelle Adresse du client. :";
        gets(Adresse);
        cout<<"\n\n\nEntrez le nouveaux Numéro de téléphone du client. :";
        cin>>Tel;
        cout<<"\n\n\n\nEntrez la nouvelle Date d’inscription du client. :";
        gets(Anciente);
                cout<<"\n\n\n client modifié..";

}

int clients::return_IDC(){return IDC;}

void clients::largeur_espace(){
    cout<<IDC<<setw(20)<<Nom<<setw(20)<<Adresse<<setw(20)<<Tel<<setw(20)<<Anciente<<endl;}


