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

void changerMenu(Plat menu[], int tailleMenu) {
    // Affichez l'ancien menu
    afficherMenu(menu, tailleMenu);

    // Logique pour modifier le menu (ajout, suppression, modification)

    // Enregistrez le nouveau menu dans un fichier
    enregistrerMenu(menu, tailleMenu, "nouveau_menu.txt");
}
void ajouterTables(Restaurant *restaurant) {
    // Affichez l'état actuel des tables
    afficherTables(restaurant);

    // Logique pour ajouter de nouvelles tables
    int nombreNouvellesTables;
    printf("Entrez le nombre de nouvelles tables à ajouter : ");
    scanf("%d", &nombreNouvellesTables);

    // Mettez à jour la structure du restaurant en ajoutant de nouvelles tables
    for (int i = MAX_TABLES; i < MAX_TABLES + nombreNouvellesTables; i++) {
        restaurant->tables[i].numero_table = i + 1;
        restaurant->tables[i].occupee = false;
    }

    // Affichez l'état mis à jour des tables
    printf("Nouvel état des tables :\n");
    afficherTables(restaurant);
}

