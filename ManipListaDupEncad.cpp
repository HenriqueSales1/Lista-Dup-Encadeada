#include <iostream>
using namespace std;

typedef struct Item
{
    int id;
    string nome;
};

typedef struct Elemento *Apontador;

typedef struct Elemento
{
    Item item;
    Apontador ant;
    Apontador prox;
};

typedef struct Lista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};

void CriaListaVazia(Lista *lista)
{
    lista->primeiro = new Elemento;
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->tamanho = 0;
}

void InsereItemPrimeiro(Lista *lista, Item *item)
{
    Apontador aux = new Elemento;
    aux->item = *item;
    aux->prox = lista->primeiro->prox;
    aux->ant = lista->primeiro->ant;
    lista->primeiro->prox = aux;
    if (lista->primeiro == lista->ultimo)
    {
        lista->ultimo = aux;
    }
    else
    {
        aux->prox->ant = aux;
    }
    lista->tamanho++;
}

void InsereItemUltimo(Lista *lista, Item *item)
{
    Apontador aux = new Elemento;
    aux->item = *item;
    aux->prox = NULL;
    aux->ant = lista->ultimo;
    lista->ultimo->prox = aux;
    lista->ultimo = aux;
    lista->tamanho++;
}

void ImprimeLista(Lista lista)
{
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        aux = aux->prox;
    }
    system("PAUSE");
}

int ListaTamanho(Lista *lista)
{
    return lista->tamanho;
}

void ConcatenaLista(Lista *lista1, Lista *lista2, Lista *lista3)
{
    Apontador aux;
    Item item;

    aux = lista1->primeiro->prox;
    while (aux != NULL)
    {
        item = aux->item;
        InsereItemUltimo(lista3, &item);
        aux = aux->prox;
    }

    aux = lista2->primeiro->prox;
    while (aux != NULL)
    {
        item = aux->item;
        InsereItemUltimo(lista3, &item);
        aux = aux->prox;
    }
}

void DivideLista(Lista *lista3, Lista *lista4, Lista *lista5)
{
    Apontador aux = lista3->primeiro->prox;
    Item item;
    int tam = ListaTamanho(lista3);
    for (int i = 0; i < tam / 2; i++)
    {
        item = aux->item;
        InsereItemPrimeiro(lista4, &item);
        aux = aux->prox;
    }
    for (int i = tam / 2; i < tam; i++)
    {
        item = aux->item;
        InsereItemPrimeiro(lista5, &item);
        aux = aux->prox;
    }
}

void OrdenaLista(Lista *lista)
{
    Apontador aux1, aux2;
    Item item;
    aux1 = lista->primeiro->prox;
    while (aux1 != NULL)
    {
        aux2 = aux1->prox;
        while (aux2 != NULL)
        {
            if (aux1->item.id < aux2->item.id)
            {
                item = aux1->item;
                aux1->item = aux2->item;
                aux2->item = item;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

void ListaOrdenada(Lista *lista4, Lista *lista5, Lista *lista6)
{
    Apontador aux1;
    Apontador aux2;
    Item item;

    OrdenaLista(lista4);
    OrdenaLista(lista5);

    aux1 = lista4->primeiro->prox;
    aux2 = lista5->primeiro->prox;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->item.id > aux2->item.id)
        {
            item = aux1->item;
            InsereItemPrimeiro(lista6, &item);
            aux1 = aux1->prox;
        }
        else
        {
            item = aux2->item;
            InsereItemPrimeiro(lista6, &item);
            aux2 = aux2->prox;
        }
    }
    while (aux1 != NULL)
    {
        item = aux1->item;
        InsereItemPrimeiro(lista6, &item);
        aux1 = aux1->prox;
    }
    while (aux2 != NULL)
    {
        item = aux2->item;
        InsereItemPrimeiro(lista6, &item);
        aux2 = aux2->prox;
    }
}

void InverteLista(Lista *lista6, Lista *lista7)
{
    Apontador aux = lista6->ultimo;
    Item item;
    while (aux != NULL)
    {
        item = aux->item;
        InsereItemUltimo(lista7, &item);
        aux = aux->ant;
    }
}

int main()
{
    Lista lista1, lista2, lista3, lista4, lista5, lista6, lista7;
    Item item;

    CriaListaVazia(&lista1);
    CriaListaVazia(&lista2);
    CriaListaVazia(&lista3);
    CriaListaVazia(&lista4);
    CriaListaVazia(&lista5);
    CriaListaVazia(&lista6);
    CriaListaVazia(&lista7);

    item.id = 10;
    item.nome = "Henrique";
    InsereItemUltimo(&lista1, &item);

    item.id = 2;
    item.nome = "Igor";
    InsereItemUltimo(&lista1, &item);

    item.id = 5;
    item.nome = "Lucas";
    InsereItemUltimo(&lista2, &item);

    item.id = 4;
    item.nome = "Tiago";
    InsereItemUltimo(&lista2, &item);

    cout << "Lista 1: \n";
    ImprimeLista(lista1);
    cout << "--------------------------------------------\n\n";
    cout << "Lista 2: \n";
    ImprimeLista(lista2);
    cout << endl;
    cout << "--------------------------------------------\n\n";
    ConcatenaLista(&lista1, &lista2, &lista3);
    cout << "Lista 3 (concatenada): \n";
    ImprimeLista(lista3);
    cout << "--------------------------------------------\n\n";
    DivideLista(&lista3, &lista4, &lista5);

    cout << "Lista 4 (dividida):\n";
    ImprimeLista(lista4);
    cout << "--------------------------------------------\n\n";
    cout << "Lista 5 (dividida):\n";
    ImprimeLista(lista5);
    cout << "--------------------------------------------\n\n";
    cout << "Lista 6 (ordenada):\n";
    ListaOrdenada(&lista4, &lista5, &lista6);
    ImprimeLista(lista6);
    cout << "--------------------------------------------\n\n";
    cout << "Lista 7 (invertida):\n";
    InverteLista(&lista6, &lista7);
    ImprimeLista(lista7);
}