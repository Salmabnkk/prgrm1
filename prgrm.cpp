#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure de voiture
typedef struct {
    char ID[50];
    char nom_utilisateur[50];
    char type_carburant[50];
    int nbre_places;
    char transmission[50];
    char dispo[50];
    char marque[50];
    char modele[50];
    float prix;
} Voiture;

// Fonction pour afficher une voiture
void afficherVoiture(Voiture v) {
    printf("Identifiant: %s\n", v.ID);
    printf("Nom_utilisateur: %s\n", v.nom_utilisateur);
    printf("Marque: %s\n", v.marque);
    printf("Modèle: %s\n", v.modele);
    printf("Type de carburant: %s\n", v.type_carburant);
    printf("Nombre de place: %d\n", v.nbre_places);
    printf("Transmission: %s\n", v.transmission);
    printf("Disponibilité: %s\n", v.dispo);
    printf("Prix: %.2f\n", v.prix);
    printf("\n");
}

// Fonction de recherche par marque
void rechercherParMarque(Voiture listeVoitures[], int nbVoitures) {
    char marqueRecherchee[50];
    printf("Veuillez entrer la marque que vous cherchez: ");
    scanf("%s", marqueRecherchee);
    printf("\nRésultats de la recherche pour la marque '%s':\n", marqueRecherchee);
    int found = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (strcmp(listeVoitures[i].marque, marqueRecherchee) == 0) {
            afficherVoiture(listeVoitures[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucune voiture de la marque '%s' n'a été trouvée.\n", marqueRecherchee);
    }
}

// Fonction de recherche par disponibilité
void rechercherParDisponibilite(Voiture listeVoitures[], int nbVoitures) {
    char disponibiliteRecherchee[50];
    printf("Veuillez entrer la disponibilité que vous cherchez ('disponible' ou 'non-disponible'): ");
    scanf("%s", disponibiliteRecherchee);
    printf("\nRésultats de la recherche pour la disponibilité '%s':\n", disponibiliteRecherchee);
    int found = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (strcmp(listeVoitures[i].dispo, disponibiliteRecherchee) == 0) {
            afficherVoiture(listeVoitures[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucune voiture avec la disponibilité '%s' n'a été trouvée.\n", disponibiliteRecherchee);
    }
}

// Fonction de comparaison pour le tri par marque
int comparerParMarque(const void *a, const void *b) {
    Voiture *voitureA = (Voiture *)a;
    Voiture *voitureB = (Voiture *)b;
    return strcmp(voitureA->marque, voitureB->marque);
}

// Fonction de comparaison pour le tri par prix
int comparerParPrix(const void *a, const void *b) {
    Voiture *voitureA = (Voiture *)a;
    Voiture *voitureB = (Voiture *)b;
    if (voitureA->prix < voitureB->prix) return -1;
    if (voitureA->prix > voitureB->prix) return 1;
    return 0;
}

int main() {
    char nomUtilisateur[50];
    int numeroVoiture;
    printf("Bienvenue dans notre agence de location de voitures !\n");
    printf("Veuillez saisir votre nom: ");
    scanf("%s", nomUtilisateur);

    Voiture listeVoitures[100]; // On suppose qu'il y a jusqu'à 100 voitures
    int nbVoitures = 0; // Nombre de voitures actuellement dans la liste

    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Modifier une voiture\n");
        printf("3. Supprimer une voiture\n");
        printf("4. Afficher la liste des voitures disponibles\n");
        printf("5. Rechercher des voitures par marque\n");
        printf("6. Rechercher des voitures par disponibilité\n");
        printf("7. Trier des voitures par marque\n");
        printf("8. Trier des voitures par prix de location par jour\n");
        printf("9. Quitter\n");
        printf("\nVotre choix: ");
        scanf("%d", &choix);

        switch (choix) {
             case 1:
                printf("\nAjout d'une nouvelle voiture:\n");
                printf("ID: ");
                scanf("%s", listeVoitures[nbVoitures].ID);
                printf("Nom_utilisateur: ");
                 scanf("%s", listeVoitures[nbVoitures].nom_utilisateur);
                printf("Marque: ");
                scanf("%s", listeVoitures[nbVoitures].marque);
                printf("Modele: ");
                scanf("%s", listeVoitures[nbVoitures].modele);   
                printf("Type de carburant: ");
                scanf("%s", listeVoitures[nbVoitures].type_carburant);
                printf("Nombre de places: ");
                scanf("%d", &listeVoitures[nbVoitures].nbre_places);
                printf("Transmission: ");
                scanf("%s", listeVoitures[nbVoitures].transmission);
                 printf("Disponibilité: ");
                scanf("%s", listeVoitures[nbVoitures].dispo);
                printf("Prix: ");
                scanf("%f", &listeVoitures[nbVoitures].prix);
                nbVoitures++;
                break;
            case 2:
              if (nbVoitures == 0) {
                    printf("Aucune voiture disponible pour le moment.\n");
                    break;
                }
                printf("\nModification d'une voiture:\n");
                printf("Indiquez le numéro de la voiture à modifier (entre 1 et %d): ", nbVoitures);
               
                scanf("%d", &numeroVoiture);
                if (numeroVoiture < 1 || numeroVoiture > nbVoitures) {
                    printf("Numéro de voiture invalide.\n");
                    break;
                }
                
                printf("ID: ");
                scanf("%s", listeVoitures[numeroVoiture-1].ID);
                printf("Nom_utilisateur: ");
                 scanf("%s", listeVoitures[numeroVoiture-1].nom_utilisateur);
                printf("Marque: ");
                scanf("%s", listeVoitures[numeroVoiture-1].marque);
                printf("Modele: ");
                scanf("%s", listeVoitures[numeroVoiture-1].modele);   
                printf("Type de carburant: ");
                scanf("%s", listeVoitures[numeroVoiture-1].type_carburant);
                printf("Nombre de places: ");
                scanf("%d", &listeVoitures[numeroVoiture-1].nbre_places);
                printf("Transmission: ");
                scanf("%s", listeVoitures[numeroVoiture-1].transmission);
                 printf("Disponibilité: ");
                scanf("%s", listeVoitures[numeroVoiture-1].dispo);
                printf("Prix: ");
                scanf("%f", &listeVoitures[numeroVoiture-1].prix);
                
                break;
                 case 3:
                if (nbVoitures == 0) {
                    printf("Aucune voiture disponible pour le moment.\n");
                    break;
                }
                printf("\nSuppression d'une voiture:\n");
                printf("Indiquez le numéro de la voiture à supprimer (entre 1 et %d): ", nbVoitures);
                int numeroVoiture;
                scanf("%d", &numeroVoiture);
                if (numeroVoiture < 1 || numeroVoiture > nbVoitures) {
                    printf("Numéro de voiture invalide.\n");
                    break;
                }
                // Déplacer les voitures suivantes d'une position vers le haut
                for (int i = numeroVoiture - 1; i < nbVoitures - 1; i++) {
                    listeVoitures[i] = listeVoitures[i + 1];
                }
                nbVoitures--; // Réduire le nombre total de voitures
                printf("Voiture supprimée avec succès.\n");
                break;
            case 4:
                printf("\nListe des voitures disponibles:\n");
                for (int i = 0; i < nbVoitures; i++) {
                    printf("Voiture %d:\n", i + 1);
                    afficherVoiture(listeVoitures[i]);
                }
                break;
            case 5:
                rechercherParMarque(listeVoitures, nbVoitures);
                break;
            case 6:
                rechercherParDisponibilite(listeVoitures, nbVoitures);
                break;
            case 7:
                qsort(listeVoitures, nbVoitures, sizeof(Voiture), comparerParMarque);
                printf("\nListe des voitures triées par marque:\n");
                for (int i = 0; i < nbVoitures; i++) {
                    printf("Voiture %d:\n", i + 1);
                    afficherVoiture(listeVoitures[i]);
                }
                break;
            case 8:
                qsort(listeVoitures, nbVoitures, sizeof(Voiture), comparerParPrix);
                printf("\nListe des voitures triées par prix de location par jour:\n");
                for (int i = 0; i < nbVoitures; i++) {
                    printf("Voiture %d:\n", i + 1);
                    afficherVoiture(listeVoitures[i]);
                }
                break;
            case 9:
                printf("Merci, au revoir %s !\n", nomUtilisateur);
                break;
            default:
                printf("Choix invalide. Veuillez saisir un numéro valide.\n");
        }
    } while (choix != 9);
    // Écriture des données dans un fichier CSV
    FILE *fichier = fopen("voitures.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        return 1;
    }

    // Écriture de l'en-tête du fichier CSV
    fprintf(fichier, "ID,Nom_utilisateur,Marque,Modèle,Type_carburant,Nombre_places,Transmission,Disponibilité,Prix\n");

    // Écriture des données de chaque voiture dans le fichier CSV
    for (int i = 0; i < nbVoitures; i++) {
        fprintf(fichier, "%s,%s,%s,%s,%s,%d,%s,%s,%.2f\n", listeVoitures[i].ID, listeVoitures[i].nom_utilisateur,
                listeVoitures[i].marque, listeVoitures[i].modele, listeVoitures[i].type_carburant,
                listeVoitures[i].nbre_places, listeVoitures[i].transmission, listeVoitures[i].dispo,
                listeVoitures[i].prix);
    }

    // Fermeture du fichier
    fclose(fichier);


    return 0;
}
