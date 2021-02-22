#include <iostream>
#include <cstdio>
#include<conio.h>
#include<iomanip>
#include <stdlib.h>
#include"commande.h"
#include"Gestion des commandes.h"
#include<fstream>

using namespace std;

void Ajouter_record_commande(commandes &l){

char ch;
fstream commandes_stream;
    commandes_stream.open("liste commandes.poc",ios::out|ios::app);
    do
    {
        system("cls");
        l.creer_commande();
        commandes_stream.write((char*)&l,sizeof(commandes));
        cout<<"\n\nVoulez-vous ajouter plus d'enregistrement..(o/n?)";
        cin>>ch;
    }while(ch=='o'||ch=='O');
    commandes_stream.close();
}
void Rechercher_record_commande(commandes &l){

     int n;
    int trouve=0;
     cout<<"\n\n\tEntrez l'identifiant du commande";
    cin>>n;
cout<<"\nDÉTAILS DU commande\n";
fstream commandes_stream;
    commandes_stream.open("liste commandes.poc",ios::in);
    while(commandes_stream.read((char*)&l,sizeof(commandes))&& trouve==0)
    {
        if(l.return_IDCM()==n)
        {
            l.afficher_commande();
             trouve=1;
        }}}
void Modifier_record_commande(commandes &l){

    int n;
    int trouve=0;
    system("cls");
    cout<<"\n\n\tMODIFIER L'ENREGISTREMENT DU commande.... ";
    cout<<"\n\n\tEntrez l'identifiant du commande";
    cin>>n;
    fstream commandes_stream;
     commandes_stream.open("liste commandes.poc",ios::in|ios::out);
    while(commandes_stream.read((char*)&l,sizeof(commandes)) && trouve==0)
    {
        if(l.return_IDCM()==n)
        {
            l.afficher_commande();
            cout<<"\nEntrez les nouveaux détails du commande"<<endl;
            l.modifier_commande();
            int pos=-1*sizeof(l);
                commandes_stream.seekp(pos,ios::cur);
                commandes_stream.write((char*)&l,sizeof(commandes));
                cout<<"\n\n\t Enregistrement mis à jour";
                trouve=1;
        }
    }

        commandes_stream.close();
        if(trouve==0)
            cout<<"\n\n Enregistrement non trouve ";
        getch();}
void Supprimer_record_commande(commandes &l){

    int n;
    system("cls");
    cout<<"\n\n\n\tSUPPRIMER LE commande ...";
    cout<<"\n\nEnter l'identifiant du commande que vous souhaitez supprimer : ";
    cin>>n;
    fstream commandes_stream;
    commandes_stream.open("liste commandes.poc",ios::in|ios::out);
    fstream temp_stream;
    temp_stream.open("Temp.poc",ios::out);
    commandes_stream.seekg(0,ios::beg);
    while(commandes_stream.read((char*)&l,sizeof(commandes)))
    {
        if(l.return_IDCM()!=n)
        {
            commandes_stream.write((char*)&l,sizeof(commandes));
        }
    }

        temp_stream.close();
        commandes_stream.close();
        remove("liste commandes.poc");
        rename("Temp.poc","liste commandes.poc");
        cout<<"\n\n\tEnregistrement supprimé ..";
        getch();
}
void Afficher_liste_record_commande(commandes &l){

system("cls");
fstream commandes_stream;
    commandes_stream.open("book.dat",ios::in);
    if(!commandes_stream)
    {
        cout<<"ERREUR!!! LE FICHIER NE PEUT PAS ÊTRE OUVERT ";
               getch();
               return;
         }

    cout<<"\n\n\t\t Liste de commandes\n\n";
    cout<<"=========================================================================\n";
    cout<<"Identifiant du commande"<<setw(10)<<"Identifiant du client"<<setw(15)<<"Date du commande"<<setw(15)<<"Prix du commande\n";
    cout<<"=========================================================================\n";

    while(commandes_stream.read((char*)&l,sizeof(commandes)))
    {
        l.largeur_espace();
    }
         commandes_stream.close();
         getch();}
void commandes_gestion(commandes l){
system("cls");
    int choix;
    cout<<"\n\n\n\tGESTION DES COMMANDES";
    cout<<"\n\n\t 1.Afficher la liste des commandes.";
    cout<<"\n\n\t 2.Ajouter un commande.";
    cout<<"\n\n\t 3.Supprimer un commande.";
    cout<<"\n\n\t 4.Modifier un commande.";
    cout<<"\n\n\t 5.Rechercher un commande.";
    cout<<"\n\n\t 6.Revenir au menu precedent.";
    cout<<"\n\n\t Veuillez saisir votre choix(1-6) ";
    cin>>choix;
    switch(choix)
    {
            case 1:
            Afficher_liste_record_commande(l);break;

            case 2:
            system("cls");
            Ajouter_record_commande(l);break;

            case 3:
            Supprimer_record_commande(l);break;

            case 4:
            Modifier_record_commande(l);break;

            case 5:
            Rechercher_record_commande(l);break;
            case 6: return;
            default:cout<<"\a";
            }
       commandes_gestion(l);}
