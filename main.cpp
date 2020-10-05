#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Play_list
{
    char musica[30];
    char Artista[30];
    float duracao;
    struct Play_list *proximo;
};

struct Play_list * cria(void)
{
    return NULL;
}

struct Play_list * insere(struct Play_list * l, char * musica, char * Artista, float duracao)
{
    struct Play_list * novo = (struct Play_list *) malloc(sizeof(struct Play_list));
    strcpy(novo->musica, musica);
    strcpy(novo->Artista, Artista);
    novo->duracao = duracao;
    novo->proximo = l;
    return novo;
}
void imprime(struct Play_list * l)
{
    struct Play_list * p;
    for(p = l; p != NULL; p = p->proximo)
    {
        printf("Musica : %s \n", p->musica);
        printf("ARTISTA : %s \n", p->Artista);
        printf("Duracao : %.2f \n", p->duracao);
    }
}
int busca(struct Play_list * l, char * musica)
{
    struct Play_list * p;
    int i = 1;
    for(p = l; p != NULL; p = p->proximo)
    {
        if(strcmp(musica, p->musica) == 0)
        {
            printf("Musica: %s %s %s \n", p->musica);
            return i;
        }
        i++;
    }
    return 0;
}

main()
{
    char grupo[30], artista[30];
    float duracao;
    struct Play_list * l;
    char resp = 's';
    char procura[30];

    printf(" ************************ \n");
    printf("|    PLAYER              |\n");
    printf("|          DE            |\n");
    printf("|             MUSICAS    |\n");
    printf("|                        |\n");
    printf(" ************************ \n");
    printf("\n\n");


    l = cria();
    while(resp != 'n')
    {
        printf("Qual eh a Musica? \n");
        scanf("%[^\n]", grupo);
        fflush(stdin);
        printf("De quem eh a musica? \n");
        scanf("%[^\n]", artista);
        fflush(stdin);
        printf("Qual eh o duracao? \n");
        scanf("%f", &duracao);
        fflush(stdin);
        l = insere(l, grupo, artista, duracao);
        printf("Continua? s/n \n");
        scanf("%c", &resp);
        fflush(stdin);
    }
    imprime(l);
    printf("Qual musica quer ouvir? \n");
    scanf("%s", procura);
    printf("Esta musica esta na posicao %d da play list\n", busca(l, procura));
    system("pause");
}
