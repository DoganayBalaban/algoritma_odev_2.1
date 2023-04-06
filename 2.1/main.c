#include <stdio.h>
#include <stdlib.h>

//Struct tanımladık
struct dugum {
    int data;
    struct dugum* sol;
    struct dugum* sag;
};

void flatten(struct dugum* root)
{
    if (root == NULL)
        return;

    // Sol alt ağacı ve sağ alt ağacı ziyaret etmek için yinelemeli bir yapı kullanıyoruz
    if (root->sol != NULL) {

        // Sol alt ağaç gezisi
        flatten(root->sol);

        // Sol alt ağacın en sağında bulunan düğüme root düğümünü bağlıyoruz
        struct dugum* temp = root->sag;
        root->sag = root->sol;
        root->sol = NULL;

        // Sol alt ağacın en sağında bulunan düğümü bulma
        while (root->sag != NULL)
            root = root->sag;

        // Root düğümüne sağ alt ağacı bağlayın
        root->sag = temp;
    }

    // Sağ alt ağacı ziyaret etmek için yinelemeli bir yapı kullanıyoruz
    flatten(root->sag);
}

// Yeni düğüm oluşturma işlemi
struct dugum* newdugum(int data)
{
    struct dugum* dugum = (struct dugum*)malloc(sizeof(struct dugum));
    dugum->data = data;
    dugum->sol = NULL;
    dugum->sag = NULL;
    return (dugum);
}

// Verilen bir binary tree'nin inorder gösterimini ekrana yazdırır
void printList(struct dugum* dugum)
{
    while (dugum != NULL) {
        printf("%d ", dugum->data);
        dugum = dugum->sag;
    }
}

int main()
{
    //Struct atamaları
    struct dugum* root = newdugum(1);
    root->sol = newdugum(2);
    root->sag = newdugum(5);
    root->sol->sol = newdugum(3);
    root->sol->sag = newdugum(4);
    root->sag->sag = newdugum(6);

    // Binary tree'yi düzleştirdik
    flatten(root);

    // Düzleştirilmiş listeyi ekrana yazdırdık
    printf("Düzleştirilmiş liste: ");
    printList(root);

    return 0;
}
