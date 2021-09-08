#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char nword[20];

int swap(int i, int move, int lette)
{
    int rep=0, x, y;
    x = lette + move;
    nword[i] =x;

}

void caesar(int move, int en_de)
{
    int rep, i, lette;

    if(en_de == 1)
    {
        move = move * (-1);
    }

    for(i = 0; i < 20; i++)
    {
        lette = getchar();

        if (lette == 10)
        {
            printf("encrypted text: ");
            for(rep = 0; rep < i; rep++)
                printf("%c", nword[rep]);
            printf("\n");\
            break;
        }

        if (lette == ' ')
        {
            nword[i] = ' ';
        }
        else
        {
            swap(i, move, lette);
        }
    }
}

int main()
{
    int ln=0, move, en_de=0;
    char command;

    while (1)
    {
        printf ("q - quit\n");
        printf ("c - caesar cypher\n");
        printf ("l - list\n");
        printf ("\n");
        ln = 0;
        printf("> ");
        command = getchar();
        printf("\n");

        if(command != 10)
            while(getchar() != 10);

        if(command == 'q')
        {
            exit(0);
        }

        else if (command == 'c')
        {
            printf ("encrypt=0 / decrypt=1: ");
            scanf ("%d", &en_de);
            printf("%d", en_de);
            printf("\n");
            while(getchar() != 10);
            printf ("displacement: ");
            scanf ("%d", &move);
            while(getchar() != 10);
            printf("word / sentence: ");
            caesar(move, en_de);

            ln = 1;
            en_de = 0;
        }

        if(ln == 1)
            printf("\n");
        command = 0;
    }

}
