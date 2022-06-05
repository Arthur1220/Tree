#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int info;
    struct Tree *left;
    struct Tree *right;
    struct Tree *father;
}Tree;

Tree * maketree(int valor, Tree* raiz)
{
    Tree *novo = (Tree*)malloc(sizeof(Tree));
    novo->right = novo->left = NULL;
    novo->father = raiz;
    novo->info = valor;

    return novo;
}

void set(Tree* raiz, int valor)
{
    if(valor < info(raiz))
        if(raiz->left == NULL)
            setleft(raiz, valor);
        else
            set(raiz->left, valor);
    else
        if(raiz->right == NULL)
            setright(raiz, valor);
        else
            set(raiz->right, valor);
}

void setleft(Tree* raiz, int valor)
{
    raiz->left = maketree(valor, raiz);
}

void setright(Tree* raiz, int valor)
{
    raiz->right = maketree(valor, raiz);
}

int info(Tree *raiz)
{
    return raiz->info;
}

Tree * left(Tree *raiz)
{
    return raiz->left;
}

Tree * right(Tree *raiz)
{
    return raiz->right;
}

Tree * father(Tree *raiz)
{
    return raiz->father;
}

int isleft(Tree *raiz)
{
    return left(father(raiz)) == raiz;
}

int isright(Tree *raiz)
{
    return right(father(raiz)) == raiz;
}

int brother(Tree *raiz)
{
    if(isleft(raiz))
        if(right(father(raiz)) != NULL)
            return info(right(father(raiz)));
        else
            return NULL;
            
    if(left(father(raiz)) != NULL)
        return info(left(father(raiz)));
    else
        return NULL;
}

void tabs(int numtabs)
{
    int i;

    for(i=0; i<numtabs; i++)
        printf("\t");
}

void show_rec(Tree *arvore, int level)
{
    if(arvore == NULL)
    {
        tabs(level);
        printf("    --VAZIO--\n");
        return;
    }

    tabs(level);
    printf("Valor = %d\n", arvore->info);

    tabs(level);
    printf("  esquerda\n");
    show_rec(arvore->left, level+1);

    tabs(level);
    printf("  direita\n");
    show_rec(arvore->right, level+1);

    tabs(level);
    printf("    Fim da arvore\n");
}

void show(Tree *arvore)
{
    show_rec(arvore, 0);
}

void preOrdem(Tree *arvore)
{
    if(arvore == NULL)
        return;

    printf("Valor = %d\n", arvore->info);

    preOrdem(arvore->left);
    preOrdem(arvore->right);
}

void posOrdem(Tree *arvore)
{
    if(arvore == NULL)
        return;

    posOrdem(arvore->left);
    posOrdem(arvore->right);

    printf("Valor = %d\n", arvore->info);
}

void emOrdem(Tree *arvore)
{
    if(arvore == NULL)
        return;

    emOrdem(arvore->left);

    printf("Valor = %d\n", arvore->info);
    
    emOrdem(arvore->right);
}

int buscaBin(Tree *arvore, int valor)
{
    if(arvore == NULL)
        return;

    if(valor == arvore->info)
    {
        printf("\n    Valor encontrado!\n\n");
        return;
    }

    buscaBin(arvore->left, valor);
    buscaBin(arvore->right, valor);

    printf("\n    Valor nao encontrado!\n\n");
}

void menu()
{
    int option, valor;

    option = 0;

    system("cls");
    printf("    --Insira o valor da raiz: ");
    scanf("%d", &valor);

    Tree *arvore = maketree(valor, NULL);
    system("cls");

    while(option != 7)
    {
        system("cls");
        printf("    --Arvore Binaria--\n\n");
        printf("[1] - Inserir\n[2] - Mostrar Arvore\n\n[3] - Pre Ordem\n[4] - Pos Ordem\n[5] - Em Ordem\n\n[6] - Buscar por numero\n\n[7] - Sair\n\n");
        printf("-> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            printf("    --Insira o valor a ser inserido: ");
            scanf("%d", &valor);
            set(arvore, valor);
            break;

        case 2:
            system("cls");
            show(arvore);
            system("pause");
            break;

        case 3:
            system("cls");
            printf("    --Pre Ordem\n\n");
            preOrdem(arvore);
            printf("\n");
            system("pause");
            break;

        case 4:
            system("cls");
            printf("    --Pos Ordem\n\n");
            posOrdem(arvore);
            printf("\n");
            system("pause");
            break;

        case 5:
            system("cls");
            printf("    --Em Ordem\n\n");
            emOrdem(arvore);
            printf("\n");
            system("pause");
            break;

        case 6:
            system("cls");
            printf("    --Insira o valor que esta buscando: ");
            scanf("%d", &valor);
            valor = buscaBin(arvore, valor);
            system("pause");
            break;

        case 7:
            system("cls");
            return;
            break;
        
        default:
            system("cls");
            printf("    --Opcao invalida!\n");
            system("pause");
            break;
        }
    }
}

int main()
{
    menu();

    return 0;
}