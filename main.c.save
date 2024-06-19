

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPTES 100
#define NUM_COMPTE_START 10000000000000ULL

typedef struct {
    char nom[50];
    char postnom[50];
    char prenom[50];
    char date_naissance[11]; // format: YYYY-MM-DD
    char lieu_naissance[50];
    char adresse_actuelle[100];
    char telephone[15];
} Client;

typedef struct {
    unsigned long long numero_compte;
    Client client;
    double solde;
    char date_creation[11]; // format: YYYY-MM-DD
} CompteBancaire;

typedef struct {
    unsigned long long numero_compte;
    char type_transaction[10]; // "depot" ou "retrait"
    double montant;
    char date_transaction[11]; // format: YYYY-MM-DD
} Transaction;

void creer_compte();
void effectuer_depot();
void effectuer_retrait();
void afficher_menu();
void sauvegarder_compte(CompteBancaire compte);
void sauvegarder_transaction(Transaction transaction);
int charger_comptes(CompteBancaire comptes[], int taille_max);
void afficher_transactions();

unsigned long long dernier_numero_compte = NUM_COMPTE_START;

int main() {
    int choix;
    do {
        afficher_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' après scanf

        switch (choix) {
            case 1:
                creer_compte();
                break;
            case 2:
                effectuer_depot();
                break;
            case 3:
                effectuer_retrait();
                break;
            case 4:
                afficher_transactions();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choix != 0);

    return 0;
}

void afficher_menu() {
    printf("\nMenu de gestion bancaire:\n");
    printf("1. Créer un compte bancaire\n");
    printf("2. Effectuer un dépôt\n");
    printf("3. Effectuer un retrait\n");
    printf("4. Visualiser les transactions\n");
    printf("0. Quitter\n");
}

void creer_compte() {
    static int compte_crees_aujourdhui = 0;
    if (compte_crees_aujourdhui >= MAX_COMPTES) {
        printf("Limite de comptes créés par jour atteinte.\n");
        return;

CompteBancaire compte;
    compte.numero_compte = dernier_numero_compte++;

    printf("Entrez les informations du client:\n");
    printf("Nom: ");
    fgets(compte.client.nom, 50, stdin);
    strtok(compte.client.nom, "\n"); // Pour enlever le '\n' de la fin

    printf("Postnom: ");
    fgets(compte.client.postnom, 50, stdin);
    strtok(compte.client.postnom, "\n");

    printf("Prénom: ");
    fgets(compte.client.prenom, 50, stdin);
    strtok(compte.client.prenom, "\n");

    printf("Date de naissance (YYYY-MM-DD): ");
    fgets(compte.client.date_naissance, 11, stdin);
    strtok(compte.client.date_naissance, "\n");

    printf("Lieu de naissance: ");
    fgets(compte.client.lieu_naissance, 50, stdin);
    strtok(compte.client.lieu_naissance, "\n");

    printf("Adresse actuelle: ");
    fgets(compte.client.adresse_actuelle, 100, stdin);
    strtok(compte.client.adresse_actuelle, "\n");

    printf("Numéro de téléphone: ");
    fgets(compte.client.telephone, 15, stdin);
    strtok(compte.client.telephone, "\n");

    compte.solde = 0.0;

    // Obtention de la date actuelle pour la date de création
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(compte.date_creation, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    sauvegarder_compte(compte);
    compte_crees_aujourdhui++;
    printf("Compte créé avec succès. Numéro de compte : %llu\n", compte.numero_compte);
}

void effectuer_depot() {
    unsigned long long numero_compte;
    double montant;

    printf("Entrez le numéro de compte: ");
    scanf("%llu", &numero_compte);
    printf("Entrez le montant à déposer: ");
    scanf("%lf", &montant);
    getchar(); // Pour consommer le '\n' après scanf

    CompteBancaire comptes[MAX_COMPTES];
    int nb_comptes = charger_comptes(comptes, MAX_COMPTES);
    int trouve = 0;

    for (int i = 0; i < nb_comptes; i++) {
        if (comptes[i].numero_compte == numero_compte) {
            comptes[i].solde += montant;
            sauvegarder_compte(comptes[i]);

            Transaction transaction;
            transaction.numero_compte = numero_compte;
            strcpy(transaction.type_transaction, "depot");
            transaction.montant = montant;

            // Obtention de la date actuelle pour la date de transaction
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            sprintf(transaction.date_transaction, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

            sauvegarder_transaction(transaction);

            printf("Dépôt effectué avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Numéro de compte introuvable.\n");
    }
}

void effectuer_retrait() {
    unsigned long long numero_compte;
    double montant;

    printf("Entrez le numéro de compte: ");
    scanf("%llu", &numero_compte);
    printf("Entrez le montant à retirer: ");
    scanf("%lf", &montant);
    getchar(); // Pour consommer le '\n' après scanf

    if (montant <= 0) {
        printf("Montant invalide.\n");
        return;
    }

    CompteBancaire comptes[MAX_COMPTES];
    int nb_comptes = charger_comptes(comptes, MAX_COMPTES);
    int trouve = 0;

    for (int i = 0; i < nb_comptes; i++) {
        if (comptes[i].numero_compte == numero_compte) {
            if (comptes[i].solde < montant + 5) {
                printf("Solde insuffisant. Un minimum de 5 USD doit être conservé.\n");
            } else {
                comptes[i].solde -= montant;
                sauvegarder_compte(comptes[i]);

                Transaction transaction;
                transaction.numero_compte = numero_compte;
                strcpy(transaction.type_transaction, "retrait");
                transaction.montant = montant;

                // Obtention de la date actuelle pour la date de transaction
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(transaction.date_transaction, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

                sauvegarder_transaction(transaction);

               printf("Retrait effectué avec succès.\n");
                trouve = 1;
            }
            break;
        }
    }

    if (!trouve) {
        printf("Numéro de compte introuvable.\n");
    }
}

void sauvegarder_compte(CompteBancaire compte) {
    FILE *file = fopen("comptes.txt", "a");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier comptes.txt.\n");
        return;
    }

    fprintf(file, "%llu|%s|%s|%s|%s|%s|%s|%s|%.2f|%s\n",
            compte.numero_compte,
            compte.client.nom,
            compte.client.postnom,
            compte.client.prenom,
            compte.client.date_naissance,
            compte.client.lieu_naissance,
            compte.client.adresse_actuelle,
            compte.client.telephone,
            compte.solde,
            compte.date_creation);

    fclose(file);
}

void sauvegarder_transaction(Transaction transaction) {
    FILE *file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier transactions.txt.\n");
        return;
    }

    fprintf(file, "%llu|%s|%.2f|%s\n",
            transaction.numero_compte,
            transaction.type_transaction,
            transaction.montant,
            transaction.date_transaction);

    fclose(file);
}

int charger_comptes(CompteBancaire comptes[], int taille_max) {
    FILE *file = fopen("comptes.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier comptes.txt.\n");
        return 0;
    }

    int i = 0;
    while (i < taille_max && fscanf(file, "%llu|%49[^|]|%49[^|]|%49[^|]|%10[^|]|%49[^|]|%99[^|]|%14[^|]|%lf|%10[^\n]\n",
                                    &comptes[i].numero_compte,
                                    comptes[i].client.nom,
                                    comptes[i].client.postnom,
                                    comptes[i].client.prenom,
                                    comptes[i].client.date_naissance,
                                    comptes[i].client.lieu_naissance,
                                    comptes[i].client.adresse_actuelle,
                                    comptes[i].client.telephone,
                                    &comptes[i].solde,
                                    comptes[i].date_creation) == 10) {
        i++;
    }

    fclose(file);
    return i;
}

void afficher_transactions() {
    unsigned long long numero_compte;
    printf("Entrez le numéro de compte: ");
    scanf("%llu", &numero_compte);
    getchar(); // Pour consommer le '\n' après scanf

    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier transactions.txt.\n");
        return;
    }

    Transaction transaction;
    int trouve = 0;

    printf("Transactions pour le compte %llu:\n", numero_compte);
    while (fscanf(file, "%llu|%9[^|]|%lf|%10[^\n]\n",
                  &transaction.numero_compte,
                  transaction.type_transaction,
                  &transaction.montant,
                  transaction.date_transaction) == 4) {
        if (transaction.numero_compte == numero_compte) {
            printf("%s de %.2f USD le %s\n",
                   strcmp(transaction.type_transaction, "depot") == 0 ? "Dépôt" : "Retrait",
                   transaction.montant,
                   transaction.date_transaction);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune transaction trouvée pour ce compte.\n");
    }

    fclose(file);
}}
