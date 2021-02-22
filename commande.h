#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

class commandes{
int IDCM;
int IDCCM;
char Date[20];
float totale;
public:
void creer_commande();
void modifier_commande();
void afficher_commande();
int return_IDCM();
void largeur_espace();
};

#endif // COMMANDE_H_INCLUDED
