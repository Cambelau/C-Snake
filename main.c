#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define DROITE 0
#define BAS 1
#define GAUCHE 2
#define HAUT 3

typedef struct snake_xy
{
    unsigned int x;
    unsigned int y;

}t_snake_xy;

int main()
{
    char serpent = 'X';
    int move = DROITE;
    char key;
    int vitesse  = 200;
    t_snake_xy coords;
    t_snake_xy oldcoords;
    t_snake_xy objet;
    t_snake_xy accel;
    tableau();
    srand(time(NULL));
    int score =0;

    coords.x=7;
    coords.y=50;

    objet.x=rand()%(19-5+1)+5;
    objet.y=rand()%(99-41+1)+41;

    accel.x=rand()%(19-5+1)+5;
    accel.y=rand()%(99-41+1)+41;

    gotoligcol(objet.x,objet.y);
    printf("%c",155);

    gotoligcol(accel.x,accel.y);
    printf("%c",160);

    FILE* fichier = NULL;



    do{
        if(key=='c')
        {
                fichier = fopen("text.txt","w");

                if (fichier != NULL)
                {
                    fprintf(fichier,"%d",score);
                    gotoligcol(15,0);
                    printf("Partie sauvegardee : score %d",score);

                }
            else
            {
                printf("Impossible d'ouvrir le fichier test.txt");
            }
               fclose(fichier);
        }

        if(key=='v')
            {
                fichier = fopen("text.txt","r");

                fscanf(fichier,"%d",&score);
                gotoligcol(17,0);
                printf("Partie chargee : score %d",score);

                fclose(fichier);
            }

        oldcoords.x=coords.x;
        oldcoords.y=coords.y;

        if (move ==BAS)
           coords.x++;

        if (move ==HAUT)
            coords.x--;

        if (move ==DROITE)
            coords.y++;

        if (move ==GAUCHE)
            coords.y--;

        if(key == 'p')
           {
               move=55;
               gotoligcol(5,0);
               printf("PAUSE");
           }

            if(coords.x==4)
            coords.x=19;

            if(coords.x==20)
            coords.x=5;

            if(coords.y==40)
            coords.y=99;

            if(coords.y==100)
            coords.y=41;

            if(objet.x==coords.x && objet.y==coords.y)
            {
                objet.x=rand()%(19-5+1)+5;
                objet.y=rand()%(99-41+1)+41;
                score++;
                gotoligcol(objet.x,objet.y);
                printf("%c",155);
            }

            if(accel.x==coords.x && accel.y==coords.y)
            {
                accel.x=rand()%(19-5+1)+5;
                accel.y=rand()%(99-41+1)+41;
                if (vitesse> 50)
                {vitesse = vitesse - 20;
                gotoligcol(accel.x,accel.y);
                printf("%c",100);
                }
            }

        gotoligcol(oldcoords.x,oldcoords.y);
        printf(" ");

        gotoligcol(coords.x,coords.y);
        printf("%c",serpent);
        Sleep(vitesse);

        gotoligcol(0,0);
        printf("%d / ",coords.x);
        printf("%d",coords.y);
        printf("\n%d / ",oldcoords.x);
        printf("%d",oldcoords.y);
        printf("\n\t\t\t\t\t\t\t  Le score est de [%d]",score);printf("%d",vitesse);

   /*--------------------------------------------------------------------------------------------------------*/
                if(kbhit())
        {
           key=getch();
           switch(key)
           {
               case 's' : move=BAS;
               break;
               case 'd' : move=DROITE;
               break;
               case 'q' : move=GAUCHE;
               break;
               case 'z' : move=HAUT;
               break;
               case 't' : serpent = 5;
               break;
           }
        }
    }while(serpent!=5);
    //------------------------------------------------------------------------------------------------------------

    gotoligcol(30,0);
    printf("zbebzbezeb");
    return 0;
}

void tableau()
{
    int i;

    for(i=0;i<15;i++)
    {
        gotoligcol(5+i,40);
        printf("|");
        gotoligcol(5+i,100);
        printf("|");
    }


    for(i=0;i<61;i++)
    {
        gotoligcol(4,40+i);
        printf("-");
        gotoligcol(20,40+i);
        printf("-");
    }
}

void gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
