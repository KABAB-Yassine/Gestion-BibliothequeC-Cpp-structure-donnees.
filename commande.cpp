#include <iostream>
#include <cstdio>
#include"commande.h"
#include<iomanip>
using namespace std;

void commandes::creer_commande(){
        cout<<"\n NOUVELLE ENTRÉE DE COMMANDE...\n";
        cout<<"\nEntrez Identifiant de commande:";
        cin>>IDCM;
        cout<<"\nEntrez Identifiant du client ayant passé la commande:";
        cin>>IDCCM;
        cout<<"\n\nEntrez la Date du commande :";
        gets(Date);
        cout<<"\n\n\nEntrez le Prix totale du commande. :";
        cin>>totale;
        cout<<"\n\n\n commande créé..";
}
void commandes::afficher_commande(){
        cout<<"\nl'Identifiant de commande:"<<IDCM;
        cout<<"\nl'Identifiant du client ayant passé la commande:"<<IDCCM;
        cout<<"\n\nla Date du commande :";
        puts(Date);
        cout<<"\n\n\nle Prix totale du commande. :"<<totale;
}
void commandes::modifier_commande(){
    cout<<"\n Identifiant du commande.  :"<<IDCM;
    cout<<"\nEntrez Nouveaux Identifiant de commande:";
        cin>>IDCM;
        cout<<"\nEntrez Nouveaux Identifiant du client ayant passé la commande:";
        cin>>IDCCM;
        cout<<"\n\nEntrez Nouvelle Date du commande :";
        gets(Date);
        cout<<"\n\n\nEntrez Nouveaux le Prix totale du commande. :";
        cin>>totale;
        cout<<"\n\n\n commande modifié..";

}

int commandes::return_IDCM(){return IDCM;}

void commandes::largeur_espace(){
    cout<<IDCM<<setw(20)<<IDCCM<<setw(20)<<Date<<setw(20)<<totale<<endl;}


