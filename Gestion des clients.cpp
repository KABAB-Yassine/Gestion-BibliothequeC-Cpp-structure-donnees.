#include <iostream>
#include <cstdio>
#include<conio.h>
#include<iomanip>
#include <stdlib.h>
#include"client.h"
#include"Gestion des clients.h"
#include<fstream>

using namespace std;

void Ajouter_record_client(clients &l){

char ch;
fstream clients_stream;
    clients_stream.open("liste clients.poc",ios::out|ios::app);
    do
    {
        system("cls");
        l.creer_client();
        clients_stream.write((char*)&l,sizeof(clients));
        cout<<"\n\nVoulez-vous ajouter plus d'enregistrement..(o/n?)";
        cin>>ch;
    }while(ch=='o'||ch=='O');
    clients_stream.close();
}
void Rechercher_record_client(clients &l){

     int n;
    int trouve=0;
     cout<<"\n\n\tEntrez l'identifiant du client";
    cin>>n;
cout<<"\nDÉTAILS DU client\n";
fstream clients_stream;
    clients_stream.open("liste clients.poc",ios::in);
    while(clients_stream.read((char*)&l,sizeof(clients))&& trouve==0)
    {
        if(l.return_IDC()==n)
        {
            l.afficher_client();
             trouve=1;
        }}}
void Modifier_record_client(clients &l){

    int n;
    int trouve=0;
    system("cls");
    cout<<"\n\n\tMODIFIER L'ENREGISTREMENT DU client.... ";
    cout<<"\n\n\tEntrez l'identifiant du client";
    cin>>n;
    fstream clients_stream;
     clients_stream.open("liste clients.poc",ios::in|ios::out);
    while(clients_stream.read((char*)&l,sizeof(clients)) && trouve==0)
    {
        if(l.return_IDC()==n)
        {
            l.afficher_client();
            cout<<"\nEntrez les nouveaux détails du client"<<endl;
            l.modifier_client();
            int pos=-1*sizeof(l);
                clients_stream.seekp(pos,ios::cur);
                clients_stream.write((char*)&l,sizeof(clients));
                cout<<"\n\n\t Enregistrement mis à jour";
                trouve=1;
        }
    }

        clients_stream.close();
        if(trouve==0)
            cout<<"\n\n Enregistrement non trouve ";
        getch();}
void Supprimer_record_client(clients &l){

    int n;
    system("cls");
    cout<<"\n\n\n\tSUPPRIMER LE client ...";
    cout<<"\n\nEnter l'identifiant du client que vous souhaitez supprimer : ";
    cin>>n;
    fstream clients_stream;
    clients_stream.open("liste clients.poc",ios::in|ios::out);
    fstream temp_stream;
    temp_stream.open("Temp.poc",ios::out);
    clients_stream.seekg(0,ios::beg);
    while(clients_stream.read((char*)&l,sizeof(clients)))
    {
        if(l.return_IDC()!=n)
        {
            clients_stream.write((char*)&l,sizeof(clients));
        }
    }

        temp_stream.close();
        clients_stream.close();
        remove("liste clients.poc");
        rename("Temp.poc","liste clients.poc");
        cout<<"\n\n\tEnregistrement supprimé ..";
        getch();
}
void Afficher_liste_record_client(clients &l){

system("cls");
fstream clients_stream;
    clients_stream.open("liste clients.poc",ios::in);
    if(!clients_stream)
    {
        cout<<"ERREUR!!! LE FICHIER NE PEUT PAS ÊTRE OUVERT ";
               getch();
               return;
         }

    cout<<"\n\n\t\t Liste de clients\n\n";
    cout<<"=========================================================================\n";
    cout<<"Identifiant du client"<<setw(10)<<"Nom du client"<<setw(15)<<"Adresse du client"<<setw(15)<<"Telephone du client"<<setw(15)<<""<<setw(15)<<"Date d’inscription du client\n";
    cout<<"=========================================================================\n";

    while(clients_stream.read((char*)&l,sizeof(clients)))
    {
        l.largeur_espace();
    }
         clients_stream.close();
         getch();}
void clients_gestion(clients l){
system("cls");
    int choix;
    cout<<"\n\n\n\tGESTION DES CLIENTSS";
    cout<<"\n\n\t 1.Afficher la liste des clients.";
    cout<<"\n\n\t 2.Ajouter un client.";
    cout<<"\n\n\t 3.Supprimer un client.";
    cout<<"\n\n\t 4.Modifier un client.";
    cout<<"\n\n\t 5.Rechercher un client.";
    cout<<"\n\n\t 6.Revenir au menu precedent.";
    cout<<"\n\n\t Veuillez saisir votre choix(1-6) ";
    cin>>choix;
    switch(choix)
    {
            case 1:
            Afficher_liste_record_client(l);break;

            case 2:
            system("cls");
            Ajouter_record_client(l);break;

            case 3:
            Supprimer_record_client(l);break;

            case 4:
            Modifier_record_client(l);break;

            case 5:
            Rechercher_record_client(l);break;
            case 6: return;
            default:cout<<"\a";
            }
       clients_gestion(l);}
