#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EMPRUNTS 100   // nombre maximum d’emprunts
#define COLONNES 8         // N_CIN, N_livre, J1, M1, A1, J2, M2, A2
#define MAX_LIVRES 100



int T_NLivre[MAX_LIVRES];
char T_Titre[MAX_LIVRES][20];  // 20 caractères max par titre
int T_Nbr_exp[MAX_LIVRES];
int n = 0; // nombre de livres actuels

//int emprunts[MAX_EMPRUNTS][COLONNES];

void menuBibliotheque();
void menuEmprunts();
void menuStatistiques();


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

int main() {
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

void supprimerLivre(){
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

void LivreDispo(){
}

void menuBibliotheque() {
    int choix;
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
                supprimerLivre();
                break;
            case 4:
                modifierNbrExemplaire();
                break;
            case 5:
                rechercherLivre();
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
        }while(choix != 0);


}

void menuStatistiques() {
        int choix;
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
}
