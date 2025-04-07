#include <stdio.h>
#include <string.h>

//EX1

typedef struct
{
    char nom[30];
    int code;
    int date_fabrication;
    int date_peremption;
    float prix;
    int nbr_vendue;
    int stock_restant;
} Medicament;

typedef struct
{
    char nom[30];
    int code;
    int date_fabrication;
    int date_peremption;
    float prix;
    int nbr_vendue;
    int stock_restant;
    struct Medicament2 *suivant;
} Medicament2;

typedef struct
{
    Medicament2 *premier;
} L;

void afficherTab(Medicament tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("Medicament %d :\n", i + 1);
        printf("Nom : %s  ", tab[i].nom);
        printf("Code : %d  ", tab[i].code);
        printf("Date fabrication : %d  ", tab[i].date_fabrication);
        printf("Date peremption : %d  ", tab[i].date_peremption);
        printf("Prix : %.2f  ", tab[i].prix);
        printf("Nombre vendu : %d  ", tab[i].nbr_vendue);
        printf("Stock restant : %d\n", tab[i].stock_restant);
    }
}

void triPeremptionBulle(Medicament tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {

        Medicament temp;

        printf("Medicament %d\n", i + 1);

        printf("Nom :");
        scanf("%s", temp.nom);
        printf("Code :");
        scanf("%d", &temp.code);
        printf("Date fabrication (annee) :");
        scanf("%d", &temp.date_fabrication);
        printf("Date peremption (annee) :");
        scanf("%d", &temp.date_peremption);
        printf("Prix :");
        scanf("%f", &temp.prix);
        printf("Nombre vendu :");
        scanf("%d", &temp.nbr_vendue);
        printf("Stock restant :");
        scanf("%d", &temp.stock_restant);
        printf("\n");

        tab[i] = temp;
    }

    for (int i = 0; i < taille - 1; i++)
    {
        int trie = 0;
        for (int j = 0; j < taille - i - 1; j++)
        {
            if (tab[j + 1].date_peremption < tab[j].date_peremption)
            {
                Medicament temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                trie = 1;
            }
        }
        if (trie == 0)
            break;
    }
}

void rechercheMedicamentDichotomie(Medicament tab[], int taille, char nom[])
{
    int debut = 0;
    int fin = taille - 1;
    int milieu;

    while (debut <= fin)
    {
        milieu = (debut + fin) / 2;
        if (strcmp(tab[milieu].nom, nom) == 0)
        {
            printf("Medicament trouve : %s, numero : %d\n", tab[milieu].nom, milieu + 1);
            return;
        }
        else if (strcmp(tab[milieu].nom, nom) < 0)
        {
            debut = milieu + 1;
        }
        else
        {
            fin = milieu - 1;
        }
    }
    printf("Medicament non trouve.\n");
}

void afficheMedicamentPlusCher(Medicament tab[], int taille)
{
    float max = 0;
    int index = -1;
    for (int i = 0; i < taille; i++)
    {
        if (tab[i].prix > max)
        {
            max = tab[i].prix;
            index = i;
        }
    }
    if (index != -1)
    {
        printf("Le medicament le plus cher est : %s, numero : %d \n", tab[index].nom, index + 1);
    }
}

int medicamentsVendus(Medicament tab[], int taille)
{
    int tot = 0;
    for (int i = 0; i < taille; i++)
    {
        tot += tab[i].nbr_vendue;
    }
    return tot;
}

void triCodeListeChainee(L liste)
{
    Medicament2 *actuel = liste.premier;
    Medicament2 *suivant = NULL;
    Medicament2 *precedent = NULL;
}



//EX2

typedef struct
{
    char nom[30];
    char prenom[30];
    int matricule;
    int moyenne;
} Etudiant;

void afficherTabEtudiant(Etudiant tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s  ", tab[i].nom);
        printf("Prenom : %s  ", tab[i].prenom);
        printf("Matricule : %d  ", tab[i].matricule);
        printf("Moyenne : %d\n", tab[i].moyenne);
    }
}

void triRapideMoyenne(Etudiant tab[], int debut, int fin)
{
    if (debut < fin)
    {
        int pivot = tab[fin].moyenne;
        int i = debut - 1;
        for (int j = debut; j < fin; j++)
        {
            if (tab[j].moyenne <= pivot)
            {
                i++;
                Etudiant temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
        Etudiant temp = tab[i + 1];
        tab[i + 1] = tab[fin];
        tab[fin] = temp;
        triRapideMoyenne(tab, debut, i);
        triRapideMoyenne(tab, i + 2, fin);
    }
}

void triInsertionAlphabetique(Etudiant tab[], int taille)
{
    for (int i = 1; i < taille; i++)
    {
        Etudiant temp = tab[i];
        int j = i - 1;
        while (j >= 0 && strcmp(tab[j].nom, temp.nom) > 0)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }
}


int main()
{
    //EX1
    // Medicament tab[4];
    // int taille = 4;

    // printf("Tri par date de peremption :\n");
    // triPeremptionBulle(tab, taille);
    // afficherTab(tab, taille);

    // rechercheMedicamentDichotomie(tab, taille, "paracetamol");

    // afficheMedicamentPlusCher(tab, taille);

    // int nbr_vendus = medicamentsVendus(tab, taille);
    // printf("Le brave pharmacien a vendu %d medicaments\n", nbr_vendus);


    //EX2

    Etudiant tabEtud[6] = {
        {"Ali", "Ahmed", 123, 15},
        {"Sara", "Ali", 124, 18},
        {"Omar", "Hassan", 125, 12},
        {"Laila", "Mohamed", 126, 20},
        {"Zainab", "Ali", 127, 17},
        {"Youssef", "Ahmed", 128, 14}};
    int tailleEtud = 6;
    
    printf("Tri par moyenne :\n");
    triRapideMoyenne(tabEtud, 0, tailleEtud - 1);
    afficherTabEtudiant(tabEtud, tailleEtud);

    printf("\nTri par nom :\n");
    triInsertionAlphabetique(tabEtud, tailleEtud);
    afficherTabEtudiant(tabEtud, tailleEtud);


    return 0;
}