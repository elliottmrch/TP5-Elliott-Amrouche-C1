#include <stdio.h>

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

void afficherTab(Medicament tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("Medicament %d :\n", i + 1);
        printf("Nom : %s  ", tab[i].nom);
        printf("Code : %d  ", tab[i].code);
        printf("Date fabrication : %d  ", tab[i].date_fabrication);
        printf("Date peremption : %d  ", tab[i].date_peremption);
        printf("Prix : %0.2f  ", tab[i].prix);
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

int main()
{
    Medicament tab[4];
    int taille = 4;

    printf("Tri par date de peremption :\n");
    triPeremptionBulle(tab, 4);
    afficherTab(tab, taille);

    return 0;
}