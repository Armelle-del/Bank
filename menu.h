int authentification(Agent agent){
    FILE *fichier = fopen ("agent.txt", "r");
    if (fichier == NULL){
        printf("Erreur d'ouverture\n")
        return 1; 

    }
    char id[5],  pseudo[50];
    while(fscanf(fichier,"%S %S %S", id, psaud,mdp) !=  EOF){
        if (strcomp(agent.pseudo,pseudo) == 0 && strcmp(agent.mdp,mdp) == 0)
            return 0
    }
    return 1 ;
}
// verification de l'existance de compte
long long int dernierIdCompt(){
    FILE *fichiern = fopen ("compte.txt ", "r");
    long long int valretour;
    if (fichier == NULL){
        printf("Erreur d'ouverture\n");
        exit (0);
    }
    char id [50], solde[50] , idagent[50];
    while(1){
        if (fscanf(fichier, "%S %S %S" id , solde, idagent) == EOF)
            break;
    }
    fclose(fichier);
    valretour = atoll(id);
    return valretour;
} 
//permet de crée un compte bancaire 
void createcompte(personne *pers,int idagent){
    FILE fichier personne = fopen("personne.txt", "a+");
    FILE *fichierCompte = fopen("compte.txt", "a+");

    if (fichierpersonne == NULL || fichierCompte == NULL){
        printf("Erreur d'ouverture\n");
        exit (0);
    
    }
    compte cpt ;
    cpt.id = dernierIdCompt () + 1;
    cpt.solde = 5;
    cpt.idagent = idagent ;
    //Attribution du compte au user
    pers -> idCpt  = cpt.id;
    // enregistrement de la personne et du compte
    char idComp[14];
    char soldeCompte[50];
    // conversion des entier en chaine de caractère
    sprintf(idAg, "%d", cpt.idagent);
    sprintf (idComp, "%lld", pers->idCpt);
    sprintf(soldeCompte, "%S %S %S %S %S %S %S %S\n" , pers -> nom, pers  -> postnom, pers -> prenom);
    

    fclose(fichierCompte);
    fclose(fichierpersonne);
    
}
// Ca permet de faire un depot
void depot(char)idCpt[14], int montant ){
    FILE * fichierCompte = fopen ("compte.txt","r+")
    FILE * fichierCompte = fopen ("temp.txt","a+").;
    
    if fichierCompte == NULL || fichiertemp == NULL){
        printf("Erreur d'ouverture\n");
        exit(0);
    }
    char ligne[100];
    char id[4];
    char solde[100];
    char idAg[50] ;
    // Lire le contenu du fichier
     while (fget(ligne,sizeof(ligne),fichierCompte)){

        sscanf(ligne," %s %s %s ", id) == 0 ){
            int sold = atoi(solde);
            montant += sold;

            sprintf(solde, "%d",montant)

        }
        fprintf (fichiertemp,  "%s %s %s\n", id ,solde,idAg);
     }
     fclose(fichiertemp);
     fclose(fichierCompte);
     // suprimer l'anciant compte
     remove("compte.txt")
     rename("temp.txt","compte.txt");

 }
