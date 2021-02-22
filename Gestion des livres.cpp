#include <iostream>
#include <cstdio>
#include<conio.h>
#include<iomanip>
#include <stdlib.h>
#include"livre.h"
#include"Gestion des livres.h"
#include<fstream>

using namespace std;

void Ajouter_record_livre(livres &l){

char ch;
fstream livres_stream;
    livres_stream.open("liste livres.poc",ios::out|ios::app);
    do
    {
        system("cls");
        l.creer_livre();
        livres_stream.write((char*)&l,sizeof(livres));
        cout<<"\n\nVoulez-vous ajouter plus d'enregistrement..(o/n?)";
        cin>>ch;
    }while(ch=='o'||ch=='O');
    livres_stream.close();
}
void Rechercher_record_livre(livres &l){

     int n;
    int trouve=0;
     cout<<"\n\n\tEntrez le Code du livre";
    cin>>n;
cout<<"\nDÉTAILS DU LIVRE\n";
fstream livres_stream;
    livres_stream.open("liste livres.poc",ios::in);
    while(livres_stream.read((char*)&l,sizeof(livres))&& trouve==0)
    {
        if(l.return_ISBN()==n)
        {
            l.afficher_livre();
             trouve=1;
        }}}
void Modifier_record_livre(livres &l){

    int n;
    int trouve=0;
    system("cls");
    cout<<"\n\n\tMODIFIER L'ENREGISTREMENT DU LIVRE.... ";
    cout<<"\n\n\tEntrez le Code du livre";
    cin>>n;
    fstream livres_stream;
     livres_stream.open("liste livres.poc",ios::in|ios::out);
    while(livres_stream.read((char*)&l,sizeof(livres)) && trouve==0)
    {
        if(l.return_ISBN()==n)
        {
            l.afficher_livre();
            cout<<"\nEntrez les nouveaux détails du livre"<<endl;
            l.modifier_livre();
            int pos=-1*sizeof(l);
                livres_stream.seekp(pos,ios::cur);
                livres_stream.write((char*)&l,sizeof(livres));
                cout<<"\n\n\t Enregistrement mis à jour";
                trouve=1;
        }
    }

        livres_stream.close();
        if(trouve==0)
            cout<<"\n\n Enregistrement non trouve ";
        getch();}
void Supprimer_record_livre(livres &l){

    int n;
    system("cls");
    cout<<"\n\n\n\tSUPPRIMER LE LIVRE ...";
    cout<<"\n\nEnter le Code du livre que vous souhaitez supprimer : ";
    cin>>n;
    fstream livres_stream;
    livres_stream.open("liste livres.poc",ios::in|ios::out);
    fstream temp_stream;
    temp_stream.open("Temp.poc",ios::out);
    livres_stream.seekg(0,ios::beg);
    while(livres_stream.read((char*)&l,sizeof(livres)))
    {
        if(l.return_ISBN()!=n)
        {
            livres_stream.write((char*)&l,sizeof(livres));
        }
    }

        temp_stream.close();
        livres_stream.close();
        remove("liste livres.poc");
        rename("Temp.poc","liste livres.poc");
        cout<<"\n\n\tEnregistrement supprimé ..";
        getch();
}
void Afficher_liste_record_livre(livres &l){

system("cls");
fstream livres_stream;
    livres_stream.open("liste livres.poc",ios::in);
    if(!livres_stream)
    {
        cout<<"ERREUR!!! LE FICHIER NE PEUT PAS ÊTRE OUVERT ";
               getch();
               return;
         }

    cout<<"\n\n\t\t Liste de livres\n\n";
    cout<<"=========================================================================\n";
    cout<<"Code du livre"<<setw(10)<<"Titre du livre"<<setw(15)<<"Titre du livre"<<setw(15)<<"Auteur du livre"<<setw(15)<<""<<setw(15)<<"Année d’édition"<<setw(15)<<"Prix du livre\n";
    cout<<"=========================================================================\n";

    while(livres_stream.read((char*)&l,sizeof(livres)))
    {
        l.largeur_espace();
    }
         livres_stream.close();
         getch();}
void livres_gestion(livres l){
system("cls");
    int choix;
    cout<<"\n\n\n\tGESTION DES LIVRES";
    cout<<"\n\n\t 1.Afficher la liste des livres.";
    cout<<"\n\n\t 2.Ajouter un livre.";
    cout<<"\n\n\t 3.Supprimer un livre.";
    cout<<"\n\n\t 4.Modifier un livre.";
    cout<<"\n\n\t 5.Rechercher un livre.";
    cout<<"\n\n\t 6.Revenir au menu precedent.";
    cout<<"\n\n\t Veuillez saisir votre choix(1-6) ";
    cin>>choix;
    switch(choix)
    {
            case 1:
            Afficher_liste_record_livre(l);break;

            case 2:
            system("cls");
            Ajouter_record_livre(l);break;

            case 3:
            Supprimer_record_livre(l);break;

            case 4:
            Modifier_record_livre(l);break;

            case 5:
            Rechercher_record_livre(l);break;
            case 6: return;
            default:cout<<"\a";
            }
       livres_gestion(l);}
