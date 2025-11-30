#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_EMPRUNTS 100   // nombre maximum d’emprunts
#define COLONNES 8         // N_CIN, N_livre, J1, M1, A1, J2, M2, A2
#define MAX_LIVRES 100

int Emprunts[MAX_EMPRUNTS][8];
int nbEmprunts = 0;
int T_NLivre[MAX_LIVRES];
char T_Titre[MAX_LIVRES][20];  // 20 caractères max par titre
int T_Nbr_exp[MAX_LIVRES];
int n = 0; // nombre de livres actuels
// Historique des emprunts terminés
int EmpruntsHistorique[MAX_EMPRUNTS][8];
int nbEmpruntsHistorique = 0;
//int emprunts[MAX_EMPRUNTS][COLONNES];
void menuBibliotheque();
void menuEmprunts();
void menuStatistiques();
void initialiserLivres() {
    T_NLivre[0] = 1;
    strcpy(T_Titre[0], "C_Prog");
    T_Nbr_exp[0] = 5;

    T_NLivre[1] = 2;
    strcpy(T_Titre[1], "Algorithms");
    T_Nbr_exp[1] = 3;

    T_NLivre[2] = 3;
    strcpy(T_Titre[2], "Java_Prog");
    T_Nbr_exp[2] = 4;

    n = 3;
}
void afficherMenu() {
    printf("||----------------------------------------------------------------------------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||--------------  Bienvenue dans le menu principal de la bibliotheque  -------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||-------------------------  Veuillez choisir  -------------------------------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||                        1. Gestion de la bibliotheque                       ||\n");
    printf("||                        2. Gestion des emprunts                             ||\n");
    printf("||                        3. Statistiques                                     ||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||----------------------------------------------------------------------------||\n");
    printf("||                        4. Quitter l'application                            ||\n");
    printf("||----------------------------------------------------------------------------||\n");
}
int existeEmprunt(int numLivre) {
    for (int i = 0; i < nbEmprunts; i++) {
        if (Emprunts[i][1] == numLivre) {
            return 1;
        }
    }
    return 0;
}
void initialiserEmprunts() {
    // Premier emprunt
    Emprunts[0][0] = 1;  // CIN
    Emprunts[0][1] = 1;  // Num livre
    Emprunts[0][2] = 5;  // Jour emprunt
    Emprunts[0][3] = 11; // Mois emprunt
    Emprunts[0][4] = 2023;// Annee emprunt
    Emprunts[0][5] = 5;  // Jour retour prévu
    Emprunts[0][6] = 12; // Mois retour
    Emprunts[0][7] = 2023;// Annee retour

    // Deuxième emprunt
    Emprunts[1][0] = 1;
    Emprunts[1][1] = 2;
    Emprunts[1][2] = 9;
    Emprunts[1][3] = 3;
    Emprunts[1][4] = 2024;
    Emprunts[1][5] = 9;
    Emprunts[1][6] = 4;
    Emprunts[1][7] = 2024;

    nbEmprunts = 2; // Nombre d'emprunts initialisés
}
int main() {
    initialiserLivres();
    initialiserEmprunts();
    int choix;

    do {
        afficherMenu();
        printf("\nVotre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                menuBibliotheque();
                break;
            case 2:
                menuEmprunts();
                break;
            case 3:
                menuStatistiques();
                break;
            case 4:
                printf("\nAu revoir !\n");
                break;
            default:
                printf("\n️ Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 4);

    return 0;
}
void listeLivre() {
    if (n == 0) {
        printf("\nPas de livre dans la bibliothèque !!!\n");
        return;
    }

    printf("\n================= Liste des Livres =================\n");
    for (int i = 0; i < n; i++) {
        printf("\n Numero : %i | Titre : %s | Nb d'examplaire : %i  \n",T_NLivre[i],T_Titre[i],T_Nbr_exp[i]);
    }
    printf("----------------------------------------------------\n");
}
void ajouterLivre() {
    if (n >= MAX_LIVRES) {
        printf("Bibliothèque pleine !\n");
        return;
    }

    int num;
    printf("Donner le numéro du livre : ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++) {
        if (T_NLivre[i] == num) {
            printf(" numéro de livre existe déjà !\n");
            return;
        }
    }

    T_NLivre[n] = num;
    getchar(); // vider le \n

    printf("Donner le titre du livre : ");
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < 19) {
        T_Titre[n][i++] = c;
    }
    T_Titre[n][i] = '\0';

    printf("Donner le nombre d'exemplaires : ");
    scanf("%d", &T_Nbr_exp[n]);

    n++;
    printf("Livre ajouté avec succès !\n");
}
void supprimerLivre(int num){
if(existeEmprunt(num)==1){
printf("On peut pas supprimer ,il est emprunté !!!\n");
return;
}

 int pos = -1;
    for (int i = 0; i < n; i++) {
        if (T_NLivre[i] == num) {
            pos = i;
            break;
        }
    }
if (pos == -1) {
        printf("livre introuvable, suppression impossible.\n");
        return;
    }
for(int i=pos;i<n-1;i++){
T_NLivre[i]=T_NLivre[i+1];
strcpy(T_Titre[i],T_Titre[i+1]);
T_Nbr_exp[i]=T_Nbr_exp[i+1];
}
n--;
}
void modifierNbrExemplaire(int num,int nb){
int trouve=0;
for(int i=0;i<n;i++){
    if(T_NLivre[i]==num){
    T_Nbr_exp[i]=nb;
    trouve=1;
    printf("\nLivre bien modifiée\n");
    break;
    }
}
if(trouve!=1){
    printf("\nLivre n'existe pas!!!.\n");
}
}
bool rechercherLivreNumero(int num) {
    for(int i = 0; i < n; i++) {
        if(T_NLivre[i] == num) {
            return true;
        }
    }
    return false;
}
bool rechercherLivreTitre(char titre[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(T_Titre[i], titre) == 0) {
            return true;
        }
    }
    return false;
}
void LivreDispo() {
    int trouve = 0;

    printf("\n========= LIVRES DISPONIBLES =========\n");

    for(int i = 0; i < n; i++) {
        if(T_Nbr_exp[i] > 0) {
            printf("Num : %d | Titre : %s | Exemplaires disponibles : %d\n",
                   T_NLivre[i], T_Titre[i], T_Nbr_exp[i]);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("\n Aucun livre disponible pour l'instant.\n");
    }

    printf("=======================================\n");
}
void menuBibliotheque() {
    int choix,numLiv,nbex,choixRech;
    do {
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||---------------------   Gestion de la bibliotheque  ------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||-------------------------  Veuillez choisir  -------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||                        1. AFFICHER TOUS LES LIVRES DE LA BIBLIOTHEQUE      ||\n");
        printf("||                        2. AJOUTER UN NOUVEAU LIVRE                         ||\n");
        printf("||                        3. SUPPRIMER UN LIVRE                               ||\n");
        printf("||                        4. MODIFIER LE NOMBRE D'EXEMPLAIRES D'UN LIVRE      ||\n");
        printf("||                        5. RECHERCHER UN LIVRE                              ||\n");
        printf("||                        6. AFFICHER LES LIVRES DISPONIBLES                  ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||                        7.MENU PRINCIPAL                                    ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                listeLivre();
                break;
            case 2:
                ajouterLivre();
                break;
            case 3:
                printf("Donner num de livre : \n");
                scanf("%d",&numLiv);
               supprimerLivre(numLiv);
                break;
            case 4:
                printf("Donner num de livre : \n");
                scanf("%d",&numLiv);
                 printf("Donner nombre d'exemplaire : \n");
                scanf("%d",&nbex);
                modifierNbrExemplaire(numLiv,nbex);
                break;
            case 5:
                printf("Choisir 1 si tu veux chercher avec numero 2 avec titre : ");
                scanf("%d",&choixRech);
                if(choixRech==1){
                    printf("Donner num de livre : \n");
                    scanf("%d",&numLiv);
                    if (rechercherLivreNumero(numLiv))
                        printf("Livre trouvé !\n");
                    else
                        printf("Livre introuvable !\n");
                }
                else{char titreLivre[20];
                    getchar(); // vider le \n
                    printf("Donner le titre du livre : ");
                    int i = 0;
                    char c;
                    while ((c = getchar()) != '\n' && i < 19) {
                        titreLivre[i++] = c;
                    }
                    titreLivre[i] = '\0';

                    if (rechercherLivreTitre(titreLivre))
                        printf("Livre trouvé !\n");
                    else
                        printf("Livre introuvable !\n");
                }
                break;
            case 6:
                LivreDispo();
                break;
            case 7:
            break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);
}
int nbEmpruntsAdherent(int cin) {
    int count = 0;
    for(int i = 0; i < nbEmprunts; i++) {
        if(Emprunts[i][0] == cin) count++;
    }
    return count;
}
void ajouterEmprunt() {
    int cin, numLivre, jour, mois, annee;

    printf("Entrer le CIN de l'adherent : ");
    scanf("%d", &cin);

    // Vérifier limite d’emprunts
    if(nbEmpruntsAdherent(cin) >= 7) {
        printf("⚠ Cet adherent a déjà atteint le maximum d'emprunts.\n");
        return;
    }

    printf("Entrer le numero du livre : ");
    scanf("%d", &numLivre);

    // Vérifier disponibilité
    int posLivre = -1;
    for(int i = 0; i < n; i++)
        if(T_NLivre[i] == numLivre) posLivre = i;

    if(posLivre == -1) {
        printf("Livre introuvable.\n");
        return;
    }

    if(T_Nbr_exp[posLivre] == 0) {
        printf("Aucun exemplaire disponible.\n");
        return;
    }

    printf("Entrer la date d'emprunt (jj mm aaaa) : ");
    scanf("%d %d %d", &jour, &mois, &annee);

    // Enregistrement
    Emprunts[nbEmprunts][0] = cin;
    Emprunts[nbEmprunts][1] = numLivre;
    Emprunts[nbEmprunts][2] = jour;
    Emprunts[nbEmprunts][3] = mois;
    Emprunts[nbEmprunts][4] = annee;

    // Date de retour (1 mois après)
    Emprunts[nbEmprunts][5] = jour;
    Emprunts[nbEmprunts][6] = mois + 1;
    Emprunts[nbEmprunts][7] = annee;

    // Gérer le passage à l'année suivante
    if(Emprunts[nbEmprunts][6] > 12) {
        Emprunts[nbEmprunts][6] = 1;
        Emprunts[nbEmprunts][7]++;
    }

    // Mise à jour inventaire
    T_Nbr_exp[posLivre]--;
    nbEmprunts++;

    printf("✔ Emprunt enregistré avec succès.\n");
}
void consulterEmpruntsAdherent() {
    int cin, trouve = 0;
    printf("Entrer CIN adhérent : ");
    scanf("%d", &cin);

    printf("\n=== Emprunts de %d ===\n", cin);

    for(int i = 0; i < nbEmprunts; i++) {
        if(Emprunts[i][0] == cin) {
            printf("Livre %d | Retour prevu : %02d/%02d/%04d\n",
                Emprunts[i][1], Emprunts[i][5], Emprunts[i][6], Emprunts[i][7]);
            trouve = 1;
        }
    }

    if(!trouve) {
    printf("Aucun emprunt trouvé.\n");
    }
}
void retourLivre() {
    int cin, numLivre, i, j;
    int pos = -1;

    printf("Entrer le CIN de l'adherent : ");
    scanf("%d", &cin);

    printf("Entrer le numero du livre : ");
    scanf("%d", &numLivre);

    /* Recherche de l'emprunt */
    for(i = 0; i < nbEmprunts; i++) {
        if(Emprunts[i][0] == cin && Emprunts[i][1] == numLivre) {
            pos = i;
            break;
        }
    }

    /* Si non trouvé */
    if(pos == -1) {
        printf("\n⚠ Aucun emprunt correspondant trouvé.\n");
        return;
    }

    /* Rendre l'exemplaire */
    for(j = 0; j < n; j++) {
        if(T_NLivre[j] == numLivre) {
            T_Nbr_exp[j]++;
            break;
        }
    }

    /* Copier l'emprunt dans EmpruntsHistorique */
    for(int k = 0; k < 8; k++)
        EmpruntsHistorique[nbEmpruntsHistorique][k] = Emprunts[pos][k];
    nbEmpruntsHistorique++;

    /* Suppression ==> decalage) */
    for(j = pos; j < nbEmprunts - 1; j++) {
        for(int k = 0; k < 8; k++)
            Emprunts[j][k] = Emprunts[j + 1][k];
    }

    nbEmprunts--;

    printf("\n✔ Le retour du livre a été enregistré avec succès.\n");
}
void afficherEmpruntsEnCours() {
    if(nbEmprunts == 0) {
        printf("Aucun emprunt.\n");
        return;
    }

    printf("\n===== EMPRUNTS EN COURS =====\n");
    for(int i = 0; i < nbEmprunts; i++) {
        printf("CIN %d | Livre %d | Retour prevu : %02d/%02d/%04d\n",
            Emprunts[i][0], Emprunts[i][1],
            Emprunts[i][5], Emprunts[i][6], Emprunts[i][7]);
    }
}
int comparerDate(int j1, int m1, int a1, int j2, int m2, int a2) {
    if(a1 != a2) return (a1 < a2) ? -1 : 1;
    if(m1 != m2) return (m1 < m2) ? -1 : 1;
    if(j1 != j2) return (j1 < j2) ? -1 : 1;
    return 0;
}
void afficherRetards() {
    int j, m, a;
    printf("Entrer la date courante (j m a) : ");
    scanf("%d %d %d", &j, &m, &a);

    printf("\n Livres en retard :\n");

    for(int i = 0; i < nbEmprunts; i++) {
        if(comparerDate(Emprunts[i][5], Emprunts[i][6], Emprunts[i][7], j, m, a) < 0){
            printf("CIN %d | Livre %d\n", Emprunts[i][0], Emprunts[i][1]);
            }
    }
}
void afficherParDateRetour() {
    int j, m, a;
    printf("Entrer une date (j m a) : ");
    scanf("%d %d %d", &j, &m, &a);

    printf("\n Emprunts prevus pour cette date : \n");

    for(int i = 0; i < nbEmprunts; i++) {
        if(Emprunts[i][5] == j && Emprunts[i][6] == m && Emprunts[i][7] == a)
            printf("CIN %d | Livre %d\n", Emprunts[i][0], Emprunts[i][1]);
    }
}
void supprimerEmpruntsPeriode() {

    int j1, m1, a1, j2, m2, a2;

    printf("\n--- Saisie Periode ---\n");
    printf("Date debut (JJ MM AAAA) : ");
    scanf("%d %d %d", &j1, &m1, &a1);

    printf("Date fin   (JJ MM AAAA) : ");
    scanf("%d %d %d", &j2, &m2, &a2);

    printf("\n--- Emprunts Avant Suppression ---\n");
    afficherTousEmprunts();

    int i = 0;
    while(i < nbEmprunts) {

        int cmpDebut = comparerDate(Emprunts[i][2], Emprunts[i][3], Emprunts[i][4], j1, m1, a1);
        int cmpFin   = comparerDate(Emprunts[i][5], Emprunts[i][6], Emprunts[i][7], j2, m2, a2);

        // supprimer si : date_emprunt >= début ET date_retour <= fin
        if(cmpDebut >= 0 && cmpFin <= 0) {

            // restaurer exemplaire
            for(int k = 0; k < n; k++)
                if(T_NLivre[k] == Emprunts[i][1]) T_Nbr_exp[k]++;

            // suppression en décalant
            for(int v = i; v < nbEmprunts - 1; v++)
                memcpy(Emprunts[v], Emprunts[v+1], sizeof(Emprunts[0]));

            nbEmprunts--;
        } else {
            i++; // seulement si pas supprimé
        }
    }

    printf("\n--- Emprunts Après Suppression ---\n");
    afficherTousEmprunts();

    printf("\n✔ Suppression terminée.\n");
}
void afficherTousEmprunts() {

    if(nbEmprunts == 0) {
        printf("(Aucun emprunt)\n");
        return;
    }

    for(int i = 0; i < nbEmprunts; i++) {
        printf("CIN:%d | Livre:%d | %02d/%02d/%04d → %02d/%02d/%04d\n",
            Emprunts[i][0], Emprunts[i][1],
            Emprunts[i][2], Emprunts[i][3], Emprunts[i][4],
            Emprunts[i][5], Emprunts[i][6], Emprunts[i][7]);
    }
}
void menuEmprunts() {
    int choix;
    do {
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||------------------   GESTION DES EMPRUNTS   --------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||--------------------  Veuillez choisir  ------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||               1. AJOUTER UN EMPRUNT                                        ||\n");
        printf("||               2. CONSULTER LES EMPRUNS D'UN ADHERENT                       ||\n");
        printf("||               3. ENREGISTRER LE RETOUR D'UN LIVRE                          ||\n");
        printf("||               4. AFFICHER LA LISTE DES EMPRUNTS EN COURS                   ||\n");
        printf("||               5. AFFICHER LES LIVRES EN RETARD DE RETOUR                   ||\n");
        printf("||               6. AFFICHER LES EMPRUNTS RELATIFS A UNE DATE DE RETOUR PREVUE||\n");
        printf("||               7. SUPPRIMER UN ENSEMBLE D'EMPRUNTS                          ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||               8.MENU PRINCIPAL                                            ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterEmprunt(); break;
            case 2: consulterEmpruntsAdherent(); break;
            case 3: retourLivre(); break;
            case 4: afficherEmpruntsEnCours(); break;
            case 5: afficherRetards(); break;
            case 6: afficherParDateRetour(); break;
            case 7: supprimerEmpruntsPeriode(); break;
            case 8: break;

            default:
                printf("Choix invalide.\n");
        }

        }while(choix != 8);


}
//pour accéder aux données
void getEmpruntGlobal(int i, int e[8]) {
    if(i < nbEmprunts) {
        for(int k = 0; k < 8; k++)
            e[k] = Emprunts[i][k];
    } else {
        for(int k = 0; k < 8; k++)
            e[k] = EmpruntsHistorique[i - nbEmprunts][k];
    }
}
//Compter totaux
void compterTotaux() {
    int nbAdherents = 0;
    int totalEmprunts = nbEmprunts + nbEmpruntsHistorique;

    for(int i = 0; i < totalEmprunts; i++) {
        int e[8];
        getEmpruntGlobal(i, e);

        int dejaCompte = 0;
        for(int j = 0; j < i; j++) {
            int ej[8];
            getEmpruntGlobal(j, ej);
            if(ej[0] == e[0]) { dejaCompte = 1; break; }
        }
        if(!dejaCompte) nbAdherents++;
    }

    printf("Nombre total de livres : %d\n", n);
    printf("Nombre total d'adhérents ayant emprunté : %d\n", nbAdherents);
    printf("Nombre total d'emprunts : %d\n", totalEmprunts);
}
//Livre le plus emprunté
void livrePlusEmprunte() {
    int compteur[n];
    for(int i = 0; i < n; i++) compteur[i] = 0;

    int totalEmprunts = nbEmprunts + nbEmpruntsHistorique;

    for(int i = 0; i < totalEmprunts; i++) {
        int e[8];
        getEmpruntGlobal(i, e);

        int num = e[1];
        for(int j = 0; j < n; j++)
            if(T_NLivre[j] == num) compteur[j]++;
    }

    int max = 0;
    for(int i = 0; i < n; i++)
        if(compteur[i] > max) max = compteur[i];

    printf("Livre(s) le(s) plus emprunté(s) (%d emprunts) :\n", max);
    for(int i = 0; i < n; i++)
        if(compteur[i] == max)
            printf("Livre %d\n", T_NLivre[i]);
}
// Livres jamais empruntés
void livresJamaisEmpruntes() {
    int compteur[n];
    for(int i = 0; i < n; i++) compteur[i] = 0;

    int totalEmprunts = nbEmprunts + nbEmpruntsHistorique;

    for(int i = 0; i < totalEmprunts; i++) {
        int e[8];
        getEmpruntGlobal(i, e);
        int num = e[1];

        for(int j = 0; j < n; j++)
            if(T_NLivre[j] == num) compteur[j]++;
    }

    printf("Livre(s) jamais emprunté(s) :\n");
    for(int i = 0; i < n; i++)
        if(compteur[i] == 0)
            printf("Livre %d\n", T_NLivre[i]);
}
//Livre le plus emprunté dans une période
void livrePlusEmpruntePeriode() {
    int j1, m1, a1, j2, m2, a2;
    printf("Saisir la période (JJ MM AAAA JJ MM AAAA) : ");
    scanf("%d %d %d %d %d %d", &j1, &m1, &a1, &j2, &m2, &a2);

    int compteur[n];
    for(int i = 0; i < n; i++) compteur[i] = 0;

    int totalEmprunts = nbEmprunts + nbEmpruntsHistorique;

    for(int i = 0; i < totalEmprunts; i++) {
        int e[8];
        getEmpruntGlobal(i, e);

        int cmpDebut = comparerDate(e[2], e[3], e[4], j1, m1, a1);
        int cmpFin   = comparerDate(e[2], e[3], e[4], j2, m2, a2);

        if(cmpDebut >= 0 && cmpFin <= 0) {
            int num = e[1];
            for(int j = 0; j < n; j++)
                if(T_NLivre[j] == num) compteur[j]++;
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++)
        if(compteur[i] > max) max = compteur[i];

    printf("Livre(s) le(s) plus emprunté(s) dans cette période (%d emprunts) :\n", max);
    for(int i = 0; i < n; i++)
        if(compteur[i] == max)
            printf("Livre %d\n", T_NLivre[i]);
}
// Adhérent le plus fréquent
void adherentPlusFrequent() {
    int compteur[1000] = {0};
    int max = 0;

    int totalEmprunts = nbEmprunts + nbEmpruntsHistorique;

    for(int i = 0; i < totalEmprunts; i++) {
        int e[8];
        getEmpruntGlobal(i, e);

        compteur[e[0]]++;
        if(compteur[e[0]] > max) max = compteur[e[0]];
    }

    printf("Emprunteur(s) le(s) plus fréquent(s) (%d emprunts) :\n", max);
    for(int i = 0; i < 1000; i++)
        if(compteur[i] == max)
            printf("CIN %d\n", i);
}
void menuStatistiques() {
        int choix;
        do{
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||------------------      STATISTIQUES      ----------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||--------------------  Veuillez choisir  ------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||   1. AFFICHER LE NOMBRE TOTALE DE LIVRES,D'ADHERENTS ET D'EMPRUNTS         ||\n");
        printf("||   2. AFFICHER LE(S) LIVRE(S) LE PLUS EMPRUNTE(S)                           ||\n");
        printf("||   3. AFFICHER LE(S) LIVRE(S) JAMAIS EMPRUNTE(S)                            ||\n");
        printf("||   4. AFFICHER LE(S) LIVRE(S) LE(S) PLUS EMPRUNTE(S) DANS UN PERIODE DONNEE ||\n");
        printf("||   5. AFFICHER LE(S) EMPRUNTEUR(S) LE(S) PLUS FREQUENT(S)                   ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("||   6.MENU PRINCIPAL                                                         ||\n");
        printf("||----------------------------------------------------------------------------||\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1: compterTotaux(); break;
            case 2: livrePlusEmprunte(); break;
            case 3: livresJamaisEmpruntes(); break;
            case 4: livrePlusEmpruntePeriode(); break;
            case 5: adherentPlusFrequent(); break;
            case 6:break;
            default:
                printf("Choix invalide.\n");
        }

        }while(choix != 6);

}
