#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

class clients{
int IDC;
char Nom[20];
char Adresse[50];
int  Tel;
char Anciente[50];
public:
void creer_client();
void modifier_client();
void afficher_client();
int return_IDC();
void largeur_espace();
};

#endif // CLIENT_H_INCLUDED
