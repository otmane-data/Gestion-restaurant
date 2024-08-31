#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_TABLES 10
#define MAX_COMMANDS 100

 typedef struct Table{
     int numero_table;
     bool occupee;
 }Table;

 // Structure pour représenter le restaurant
 typedef struct Restaurant {
     Table tables[MAX_TABLES];
 }Restaurant;
 // Structure pour stocker les informations sur les plats
 typedef struct {
    char nom[100];
    float prix;
} Plat;

// Structure pour stocker les informations sur la commande
 typedef struct {
    Plat plat;
    int quantite;
    int numero_table;
} Commande;

 typedef struct {
    char nom[100];
    int quantite;
} StockItem;
 void afficherMenu(Plat menu[], int tailleMenu) {
    printf("============Menu=================\n");
    for (int i = 0; i < tailleMenu; ++i) {
        printf("%d. %s - %.2f DH\n", i + 1, menu[i].nom, menu[i].prix);
    }
    printf("\n");
}
// Initialiser les tables du restaurant
 void initialiserTables(Restaurant *restaurant) {
    for (int i = 0; i < MAX_TABLES; i++) {
        restaurant->tables[i].numero_table = i + 1;
        restaurant->tables[i].occupee = false;
    }
}
 void displayTableState(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("\n\t          _______________________________________");
        printf("\n\t         |  Erreur lors de l'ouverture du fichier| ");
        printf("\n\t         |_______________________________________|");
        exit(1);
    }
    printf("\n\t              ____________________________________________________");
    printf("\n\t             |  Etat des tables dans le fichier %s :              |", fileName);
    printf("\n\t             | ___________________________________________________|\n");
    int tableNumber;
    char state[20];  // Adjust the size based on your file content
    while (fscanf(fp, "%d %s", &tableNumber, state) == 2) {
        printf("\n\t\t      _______________            ");
        printf("\n\t\t     | %d  : %s    |\n", tableNumber, state);
        printf("\n\t\t     |_______________|");
    }

    fclose(fp);
}


// Afficher l'état actuel des tables
 void afficherTables(struct Restaurant *restaurant) {
    printf("\n\t           _________________________________");
    printf("\n\t          |   État actuel des tables :      |");
    printf("\n\t          |_________________________________|");

    for (int i = 0; i < MAX_TABLES; ++i) {
            printf("\n\t           ________________");
            printf("\n\t          |Table %d : %s  |", restaurant->tables[i].numero_table,restaurant->tables[i].occupee? "Occupee" : "Libre");
            printf("\n\t          |________________|");
        }

    }

 void changerStatutTable(Restaurant *restaurant, int numeroTable, bool occupee) {
    if (numeroTable >= 1 && numeroTable <= MAX_TABLES) {
        restaurant->tables[numeroTable - 1].occupee = occupee;
        printf("\n\t           ____________________________________________");
        printf("\n\t          |Le statut de la table %d a ete mis a jour.  |", numeroTable);
        printf("\n\t          |____________________________________________|");
    }
    else
        printf("\n\t           _________________________________");
        printf("\n\t          |   Numero de table invalide.     |");
        printf("\n\t          |_________________________________|");
}
// Enregistrer l'état des tables dans un fichier
 void enregistrerEtatTables(Restaurant *restaurant,  char *nomFichier) {
    FILE *fp = fopen(nomFichier, "wt");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier ");
       exit(1);
    }
    for (int i = 0; i < MAX_TABLES; ++i) {
        fprintf(fp,"%d %s\n", restaurant->tables[i].numero_table,restaurant->tables[i].occupee? "Occupee" : "Libre");
    }
    fclose(fp);
}

 void infoTables(){
      Restaurant monRestaurant;
      int numeroTable;
      char occupee;
      int choix;
      initialiserTables(&monRestaurant);
       do {
           printf("\n                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
           printf("                 @                   ------------MENU PRINCIPAL------------                           @\n");
           printf("                 @                         1. . Afficher l'etat des tables                            @\n");
           printf("                 @                         2. Changer le statut d'une table                           @\n");
           printf("                 @                         3. Enregistrer l'etat des tables dans un fichier           @\n");
           printf("                 @                         0. Sortir et retourner au menu                             @\n");
           printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
           printf("\n\t                                      ___________");
           printf("\n\t                                     |   Choix:  |");
           printf("\n\t                                     |___________|");
           scanf("%d", &choix);
        switch (choix) {
            case 1:
                   displayTableState("etat_tables.txt");
                    break;

            case 2: {
                    printf("\n\t           ______________________ ");
                    printf("\n\t          |  Numero de table :   | ");
                     printf("\n\t          |______________________|");
                    scanf("%d", &numeroTable);
                    while (getchar() != '\n');
                    printf("\n\t          _________________________________________________________ ");
                    printf("\n\t         |  La table est-elle occupee ? (o pour oui, n pour non) : |");
                    printf("\n\t         |_________________________________________________________|");
                    scanf("%c", &occupee);
                    changerStatutTable(&monRestaurant, numeroTable, (occupee == 'o' || occupee == 'O'));
                    break;
                }

            case 3: enregistrerEtatTables(&monRestaurant, "etat_tables.txt");
                    printf("\n\t          _______________________________________________________________________ ");
                    printf("\n\t         |  L'etat des tables a ete enregistre dans le fichier 'etat_tables.txt'.|");
                    printf("\n\t         |_______________________________________________________________________|");
                    break;

            case 0: printf("\n\t               _____________");
                    printf("\n\t              |  Au revoir !|");
                    printf("\n\t              |_____________|");
                    break;

            default:printf("\n\t            _______________________________________");
                    printf("\n\t           |    Choix invalide. Veuillez reessayer.|");
                    printf("\n\t           |_______________________________________|");
        }
    } while(choix != 0);
    }
 void enregistrerMenu(Plat menu[],int tailleMenu,char *fichier){
         FILE *fp=fopen(fichier,"wt");
         if(fp==NULL){
            printf("erreur lors d'ouverture");
            exit(1);
           }
         for (int i = 0; i < tailleMenu; ++i) {
                fprintf(fp, "%d. %s - %.2f DH\n", i + 1, menu[i].nom, menu[i].prix);
            }
            fclose(fp);
}
 Commande passerCommande(Plat menu[], int tailleMenu) {
    Commande nouvelleCommande;
    // Afficher le menu
    afficherMenu(menu, tailleMenu);
    // Sélectionner un plat
    int choix;
    printf("\n\t               ______________________________ ");
    printf("\n\t              |  Choisissez un plat (1-%d) : |", tailleMenu);
    printf("\n\t              |______________________________|");
    scanf("%d", &choix);
    // Demander la quantité
    printf("\n\t                   ________________________ ");
    printf("\n\t                  |   Entrez la quantite : |");
    printf("\n\t                  |________________________|");
    scanf("%d", &nouvelleCommande.quantite);
    // Enregistrer le plat choisi et la quantité dans la commande
    nouvelleCommande.plat = menu[choix - 1];
    return nouvelleCommande;
}
 void afficherFacture(Commande commandes[], int tailleCommandes) {
        printf("\n\t                   _______________");
        printf("\n\t                  |     Facture : |");
        printf("\n\t                  |_______________|\n");
        float total = 0;
        for (int i = 0; i < tailleCommandes; ++i) {
            printf("\n\t          ______________________________________    ");
            printf("\n\t         |   %s : x%d - %.2f DH                 |", commandes[i].plat.nom, commandes[i].quantite, commandes[i].plat.prix * commandes[i].quantite);
            printf("\n\t         |______________________________________|");
            total += commandes[i].plat.prix * commandes[i].quantite;
        }
        printf("\n\t                   ___________________");
        printf("\n\t                  |  Total : %.2f DH|", total);
        printf("\n\t                  |___________________|");
}
 void infoCommandes(){
        Plat menu[] = {{"Pizza Margherita\t", 80.99}, {"Burger Classique\t", 60.49}, {"Salade Cesar   \t", 50.99}, {"couscous     \t",40.54},
                {"Tacos        \t",100.00},{"Tajine de poulet\t",80.00},{"jus de fraise\t",20.0},{"jus de mangue\t",20.0},{"jus d'avocat  \t",18.0},
                {"Rayeb beldi  \t",5.0},{"salade fruit  \t",13.0}};

     // Tableau pour stocker les commandes
        Commande commandes[10];  // Supposons que le restaurant puisse gérer jusqu'à 10 commandes simultanément
        int tailleMenu = 11;
        int choixUtilisateur;
        int tailleCommandes = 0;
     do {
        // Menu principal
   printf("\n                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   printf("                 @                   ------------Restaurant Management System------------   @\n");
   printf("                 @                         1. Passer une commande                           @\n");
   printf("                 @                         2. Afficher la facture                           @\n");
   printf("                 @                         3.  Quitter et retour au menu                    @\n");
   printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   printf("\n\t                                     _________________");
   printf("\n\t                                    |      Choix      |");
   printf("\n\t                                    |_________________|");
   scanf("%d", &choixUtilisateur);
   switch (choixUtilisateur) {
                case 1:if (tailleCommandes < 10) {
                            commandes[tailleCommandes] = passerCommande(menu, tailleMenu);
                            tailleCommandes++;
                      }

                       break;

                case 2:afficherFacture(commandes, tailleCommandes);
                       break;
                case 3:printf("\n\t             ______________________________________________________________");
                       printf("\n\t            | Merci d'avoir utilise cette option de gestion de restaurant. |");
                       printf("\n\t            |______________________________________________________________|");
                       break;
            default:printf("\n\t             _______________________________________________________");
                    printf("\n\t            | Choix invalide. Veuillez choisir une option valide.   | ");
                    printf("\n\t            |_______________________________________________________|");
        }

    } while (choixUtilisateur != 3);
}
 void EnregistrerHistorique(Commande commandes[], int tailleCommandes,char *file){

    FILE *fp=fopen(file,"at");
    if(fp==NULL){
        printf("impossible ");
        exit(1);
    }

 for (int i = 0; i < tailleCommandes; ++i) {
    printf("Writing to file: %s x%d - %.2f DH\n", commandes[i].plat.nom, commandes[i].quantite, commandes[i].plat.prix * commandes[i].quantite);
    fprintf(fp, "%s x%d - %.2f DH\n", commandes[i].plat.nom, commandes[i].quantite, commandes[i].plat.prix * commandes[i].quantite);
}

fclose(fp);
}


void modifierPrix(Plat menu[], int tailleMenu) {
    int choixPlat;
    printf("\n\t                    ________________    ");
    printf("\n\t                   | Menu actuel :  |");
    printf("\n\t                   |________________|\n");
    afficherMenu(menu, tailleMenu);
    printf("\n\t                     _________________________________________________________ ");
    printf("\n\t                    |  Choisissez le plat que vous souhaitez modifier (1-%d) :| ", tailleMenu);
    printf("\n\t                    |_________________________________________________________|");
    scanf("%d", &choixPlat);

    if (choixPlat >= 1 && choixPlat <= tailleMenu) {
        printf("\n\t               _________________________________________");
        printf("\n\t              |    Modification du plat %s:|", menu[choixPlat - 1].nom);
        printf("\n\t              |_________________________________________|");

        // Par exemple, pour changer le prix :
        printf("\n\t                   ____________________________");
        printf("\n\t                  |  Entrez le nouveau prix :  |");
        printf("\n\t                  |____________________________|");
        scanf("%f", &menu[choixPlat - 1].prix);
        printf("\n\t               _____________________________________");
        printf("\n\t              |   Le plat a ete modifie avec succes |");
        printf("\n\t              |_____________________________________|");
        printf("\n\t                   ___________________");
        printf("\n\t                  |    Nouveau menu : |");
        printf("\n\t                  |___________________|\n");
        afficherMenu(menu, tailleMenu);
    } else {
        printf("\n\t                   _______________________________________");
        printf("\n\t                  |   Choix invalide. Veuillez reessayer. |");
        printf("\n\t                  |_______________________________________|");
    }
}

 void changerMenu(Plat menu[], int tailleMenu) {
    // Affichez l'ancien menu
    afficherMenu(menu, tailleMenu);
    // Enregistrez le nouveau menu dans un fichier
    enregistrerMenu(menu, tailleMenu, "nouveau_menu.txt");
}

 void ajouterAliment(char *fichier) {
    int tailleMenu;
    Plat menu[] = {
        {"Pizza Margherita\t", 80.99},
        {"Burger Classique\t", 60.49},
        {"Salade Cesar   \t", 50.99},
        {"couscous     \t", 40.54},
        {"Tacos        \t", 100.00},
        {"Tajine de poulet\t", 80.00},
        {"jus de fraise\t", 20.0},
        {"jus de mangue\t", 20.0},
        {"jus d'avocat  \t", 18.0},
        {"Rayeb beldi  \t", 5.0},
        {"salade fruit  \t", 13.0}
    };

    FILE *fp = fopen(fichier, "a");  // Mode ajout
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    Plat nouvelAliment;
    printf("\n\t                  __________________________________");
    printf("\n\t                 | Entrez le nom du nouvel aliment :| ");
    printf("\n\t                 |__________________________________|");
    scanf("%s", nouvelAliment.nom);
    printf("\n\t                 _____________________________________");
    printf("\n\t                |  Entrez le prix du nouvel aliment : |");
    printf("\n\t                |_____________________________________|");
    scanf("%f", &nouvelAliment.prix);

    // Ajouter le nouvel aliment au menu
    if (tailleMenu < sizeof(menu) / sizeof(menu[0])) {
        menu[tailleMenu] = nouvelAliment;
        tailleMenu++;
        printf("\n\t             ___________________________");
        printf("\n\t            | %s a ete ajoute au menu.  |", nouvelAliment.nom);
        printf("\n\t            |___________________________|\n");

        // Enregistrer le menu après l'ajout d'un aliment
        enregistrerMenu(menu, tailleMenu, "les nouveaux aliments.txt");
        afficherMenu(menu, tailleMenu);
    } else {
           printf("Le menu est plein, impossible d'ajouter un nouvel aliment.\n");
    }

    fclose(fp);

}
 int annulerAliment(Plat menu[], int tailleMenu) {
    printf("\n\t                    __________________________________________________________  ");
    printf("\n\t                   |  Choisissez le plat que vous souhaitez supprimer (1-%d) :| ", tailleMenu);
    printf("\n\t                   |__________________________________________________________|");

    int choixPlat;
    scanf("%d", &choixPlat);

    if (choixPlat >= 1 && choixPlat <= tailleMenu) {
        printf("\nSuppression du plat \"%s\" du menu.\n", menu[choixPlat - 1].nom);

        // Shift elements to fill the gap
        for (int i = choixPlat - 1; i < tailleMenu - 1; ++i) {
            menu[i] = menu[i + 1];
        }

        // Display the updated menu
        printf("\n\t                      ______________________________________ ");
        printf("\n\t                     |  Le plat a ete supprime avec succes. |");
        printf("\n\t                     |______________________________________|");
        printf("Nouveau menu :\n");
        afficherMenu(menu, tailleMenu);

        // Return the updated size
        return tailleMenu - 1;
    } else {
        printf("Choix invalide. Veuillez reessayer.\n");

        // Return the original size
        return tailleMenu;
    }
}


 int main()
 {
    Restaurant monRestaurant;
    Plat plat;
    int commandes;
    int tailleCommandes;
    int choice;
    int numero_table;
    int tailleMenu = 11;
  Plat menu[] = {{"Pizza Margherita\t", 80.99}, {"Burger Classique\t", 60.49}, {"Salade Cesar   \t", 50.99}, {"couscous     \t",40.54},
            {"Tacos        \t",100.00},{"Tajine de poulet\t",80.00},{"jus de fraise\t",20.0},{"jus de mangue\t",20.0},{"jus d'avocat  \t",18.0},

            {"Rayeb beldi  \t",5.0},{"salade fruit  \t",13.0}};
debut:
   printf("\n\t                       ::::::::::::::::::::::::::::::::::::::::::");
   printf("\n\t                       ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ::");
   printf("\n\t                       ::     @                           @    ::");
   printf("\n\t                       ::     @        Bienvenu dans      @    ::");
   printf("\n\t                       ::     @                           @    ::");
   printf("\n\t                       ::     @      votre restaurant     @    ::");
   printf("\n\t                       ::     @                           @    ::");
   printf("\n\t                       ::     @                           @    ::");
   printf("\n\t                       ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ::");
   printf("\n\t                       ::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   printf("                 @                   ------------GESTION DE RESTAURANT------------                 @\n");
   printf("                 @                         1. Enregistrer des  tables                              @\n");
   printf("                 @                         2. Affichage  les aliments                              @\n");
   printf("                 @                         3. Enregistrer les commandes                            @\n");
   printf("                 @                         4. Gerant                                               @\n");
   printf("                 @                         5. Sortir                                               @\n");
   printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   printf("\n\t                           _____________________________________");
   printf("\n\t                          |        Choisir une option:          |");
   printf("\n\t                          |_____________________________________| ");
   scanf("%d", &choice);
   printf("\n");

    switch (choice) {
        case 1:
               printf("\n\t\t                    _________________________________");
               printf("\n\t\t                   | Enregistrement des tables:      |");
               printf("\n\t\t                   | ________________________________|");
               infoTables();
               goto debut;
               break;

        case 2:
            printf("\n\t                      _____________________________ ");
            printf("\n\t                     |Affichage des aliments:     |");
            printf("\n\t                     |_____________________________|\n");
            enregistrerMenu(menu,tailleMenu,"les aliments.txt");
            afficherMenu(menu,tailleMenu);
            goto debut;
            break;
        case 3:printf("\n\t\t                          _________________________________");
               printf("\n\t\t                         |Enregistrement des commandes:    |");
               printf("\n\t\t                         |_________________________________|");
               infoCommandes();
               goto debut;

        case 4:
                fin:
               printf("\n               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
               printf("                 @                   ------------Menu du gerant------------                 @\n");
               printf("                 @                         1. changer le prix                               @\n");
               printf("                 @                         2. ajouter un element                            @\n");
               printf("                 @                         3. supprimer un element                          @\n");
               printf("                 @                         4.Retourner au menu principale                   @\n");
               printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
               printf("                                         _______________________");
               printf("\n\t                               | Choix :               |");
               printf("\n\t                               |______________________ |");
               scanf("%d", &choice);

               switch (choice) {
                case 1:
                        modifierPrix(menu,tailleMenu);
                        changerMenu(menu, tailleMenu);
                        goto fin;
                        break;

                case 2:
                        ajouterAliment("les nouveaux aliments.txt");
                        goto fin;
                        break;

                case 3:tailleMenu = annulerAliment(menu, tailleMenu);

                       goto debut;
                       break;

                case 4 :printf("\n\t              _________________________________");
                        printf("\n\t            | Retourner au menu principale    |");
                        printf("\n\t            | ________________________________|");
                        break;
                default:printf("\n\t           __________________________________");
                        printf("\n\t          |Choix invalide. Veuillez réessayer|");
                        printf("\n\t          | _________________________________|");
            }
            break;

        case 5: printf("\n\t            ___________________________");
                printf("\n\t           |     Sortir du systeme:    |");
                printf("\n\t           |     Deconnexion.......    |");
                printf("\n\t           |___________________________|");
                exit(0);
        default:printf("\n\t            _____________________________________ ");
                printf("\n\t           | Option invalide. Essayez a nouveau. |");
                printf("\n\t           |_____________________________________|");

    return 0;
}
}
