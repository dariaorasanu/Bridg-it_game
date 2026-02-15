#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include<stdio.h>
#include<conio.h> // AfiseazaCastigator
#include <chrono> //delay
#include <thread> //delay
#include <stdlib.h>
#include <cstdlib>
#include <dos.h>
#include <string>
#include <fstream>
using namespace std;

// Tabla de joc - Reprezentata printr-o matrice
int Tabla[15][15];

//Dimensiunea tablei
int N = 9;

// O matrice de vizitare pentru a verifica cautarea DFS;
int Matrice_DFS_Vizitare[15][15] = {0};

//Conditii de castigare a fiecarui jucator
bool Castig_Player1_YJos, Castig_Player1_YSus;
bool Castig_player2_XStanga, Castig_player2_XDreapta;


//Pozitiile curente ale jucatorului
int Player_X_Curent = 0;
int Player_Y_Curent = 0;
int PlayerCurent = 1;

//
int coordonate_tabla_x_graphics = 40, coordonate_tabla_y_graphics = 40;
int Optiune;

int CuloarePlayer1 = 0;
int CuloarePlayer2 = 0;

/*void Sunet()
{
	byte i;
	for (i=1; i<=25; i++)
	{
		sound(300+20*i);
		delay(30);
	}
	nosound();
}
*/
int OptiuneJucator = 0;
int OptiuneDificultate = 0;
void AlegeOponent()
{
    cleardevice();
    setcolor(LIGHTGREEN);
    settextstyle(1,HORIZ_DIR,4);

    settextjustify(CENTER_TEXT,CENTER_TEXT);

    outtextxy(500, 30, "ALEGE OPONENTUL:");

    setbkcolor(RED);
    outtextxy(500, 130, "1. PLAYER");
    setbkcolor(BLUE);
    outtextxy(500, 230, "2. COMPUTER");

    OptiuneJucator = 1;
    char tasta;
    bool optiune_valida = false;

    while (!optiune_valida)
    {
        tasta = getch();

        if (tasta == KEY_DOWN && OptiuneJucator == 1)
        {
            OptiuneJucator = 2;

            setbkcolor(BLUE);
            outtextxy(500, 130, "1. PLAYER");
            setbkcolor(RED);
            outtextxy(500, 230, "2. COMPUTER");
        }

        else if (tasta == KEY_UP && OptiuneJucator == 2)
        {
            OptiuneJucator = 1;

            setbkcolor(RED);
            outtextxy(500, 130, "1. PLAYER");
            setbkcolor(BLUE);
            outtextxy(500, 230, "2. COMPUTER");


        }


        else if (tasta == 13)
        {
            optiune_valida = true;
            setbkcolor(BLACK);
        }

    }
}

void AlegeDificultate()
{
    cleardevice();
    setcolor(LIGHTGREEN);
    settextstyle(1,HORIZ_DIR,4);

    settextjustify(CENTER_TEXT,CENTER_TEXT);

    outtextxy(500, 30, "ALEGE DIFICULTATEA:");

    setbkcolor(RED);
    outtextxy(500, 130, "1. EASY");
    setbkcolor(BLUE);
    outtextxy(500, 230, "2. HARD");

    OptiuneDificultate = 1;

    char tasta;
    bool optiune_valida = false;

    while (!optiune_valida)
    {
        tasta = getch();
        if (tasta == KEY_DOWN && OptiuneDificultate == 1)
        {
            OptiuneDificultate = 2;

            setbkcolor(BLUE);
            outtextxy(500, 130, "1. EASY");
            setbkcolor(RED);
            outtextxy(500, 230, "2. HARD");
        }

        else if (tasta == KEY_UP && OptiuneDificultate == 2)
        {
            OptiuneDificultate = 1;

            setbkcolor(RED);
            outtextxy(500, 130, "1. EASY");
            setbkcolor(BLUE);
            outtextxy(500, 230, "2. HARD");


        }


        else if (tasta == 13)
        {
            optiune_valida = true;
            setbkcolor(BLACK);
        }


    }



    delay(500);
}
void AlegeDimensiuneTabla() //Daria
{
    int DimensiuneTabla[3] = {5,7,9};
    int indice_meniu = 0;
    int key;

    cleardevice();
    settextstyle(1,HORIZ_DIR,3);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(MAGENTA);
    //setbkcolor(RED);
    outtextxy(500,30,"INTRODUCETI DIMENSIUNEA TABLEI:");


    setcolor(LIGHTCYAN);

    settextstyle(1,HORIZ_DIR,4);
    setbkcolor(RED);
    outtextxy(450, 70, "5");

    setbkcolor(BLUE);
    outtextxy(500, 70, "7");
    outtextxy(550, 70, "9");


    int dimensiune_selectata = 0;
    bool dimensiune_valida = false;

    while (dimensiune_valida != true)
    {
        key = getch();

        if (key == KEY_LEFT && indice_meniu > 0 && indice_meniu <= 2)
        {
            indice_meniu--;

            if (indice_meniu == 0)
            {


                setbkcolor(RED);
                outtextxy(450, 70, "5");
                setbkcolor(BLUE);
                outtextxy(550, 70, "9");
                outtextxy(500, 70, "7");

            }


            else if (indice_meniu == 1)
            {

                setbkcolor(BLUE);
                outtextxy(450, 70, "5");
                setbkcolor(RED);
                outtextxy(500, 70, "7");

                setbkcolor(BLUE);
                outtextxy(550, 70, "9");

            }

        }

        else if (key == KEY_RIGHT && indice_meniu < 2 && indice_meniu >= 0)
        {

            ++indice_meniu;

            if (indice_meniu == 1)
            {


                setbkcolor(BLUE);
                outtextxy(450, 70, "5");
                outtextxy(550, 70, "9");

                setbkcolor(RED);
                outtextxy(500, 70, "7");

            }


            else if (indice_meniu == 2)
            {


                setbkcolor(BLUE);
                outtextxy(450, 70, "5");
                outtextxy(500, 70, "7");

                setbkcolor(RED);
                outtextxy(550, 70, "9");

            }

        }

        else if (key == 13 )
        {
            N = DimensiuneTabla[indice_meniu];
            dimensiune_valida = true;
            setbkcolor(BLACK);
        }


    }

}
void Initializare(int x[15][15]) //Daria
{
    for (int i = 0; i <= N; i +=2)
        for (int j = 1; j <= N; j ++)
        {
            if (j % 2 == 0 || i == 0)
                x[i][j] = 0;
            else
                x[i][j] = 2;
        }

    for (int i = 1; i <= N; i +=2)
        for (int j = 0; j <= N; j ++)
        {
            if (j % 2 == 0 && j != 0)
                x[i][j] = 1;
            else
                x[i][j] = 0;
        }

    for (int i = 0; i<=N; i++)
        x[i][0]=i;
    for (int j=0; j<=N; j++)
        x[0][j]=j;
}

void afisareTabla(int x[15][15])
{

    for(int i=0; i<= N; i++)
    {
        for(int j=0; j<= N; j++)
            cout<<x[i][j]<<"  ";

        cout<<endl<<endl;

    }
}

void Parcurgere_DFS_Player1(int x[15][15], int X, int Y) // Cristi
{

    if (x[Y][X] == 1)
    {
        Matrice_DFS_Vizitare[Y][X] = 1;

        if (Y == 1)
            Castig_Player1_YSus = true;
        if (Y == N)
            Castig_Player1_YJos = true;

        int Y_Jos = Y;
        int Y_Sus = Y;
        int X_Stanga = X;
        int X_Dreapta = X;

        if (Y < N)
            Y_Jos = Y + 1;

        if (Y>1)
            Y_Sus = Y - 1;

        if (X>1)
            X_Stanga = X - 1;

        if(X<N)
            X_Dreapta = X + 1;


        if (x[Y_Jos][X] == 1 && Matrice_DFS_Vizitare[Y_Jos][X] == 0)
            Parcurgere_DFS_Player1(x,X,Y_Jos);

        if (x[Y_Sus][X] == 1 && Matrice_DFS_Vizitare[Y_Sus][X] == 0)
            Parcurgere_DFS_Player1(x,X,Y_Sus);

        if (x[Y][X_Stanga] == 1 && Matrice_DFS_Vizitare[Y][X_Stanga] == 0)
            Parcurgere_DFS_Player1(x,X_Stanga,Y);

        if (x[Y][X_Dreapta] == 1 && Matrice_DFS_Vizitare[Y][X_Dreapta] == 0)
            Parcurgere_DFS_Player1(x,X_Dreapta,Y);
    }

}

bool DFS_Player_1(int x[15][15], int X, int Y) //Cristi
{
    for (int i = 0; i<=N; i++)
        for (int j = 0; j<=N; j++)
            Matrice_DFS_Vizitare[i][j] = 0;


    Castig_Player1_YJos=0;
    Castig_Player1_YSus=0;


    Parcurgere_DFS_Player1(x,X,Y);

    afisareTabla(Matrice_DFS_Vizitare);

    cout<<endl<<"Conditia Castig: "<<Castig_Player1_YJos<<" "<<Castig_Player1_YSus<<endl;


    if (Castig_Player1_YJos == true && Castig_Player1_YSus == true)
        return true;
    else
        return false;
}

void parcurgere_DFS_player2 (int x[15][15], int X, int Y) // Daria
{


    if (x[Y][X] == 2)
    {
        Matrice_DFS_Vizitare[Y][X] = 2;

        if (X == 1)
            Castig_player2_XStanga = true;
        else if (X == N)
            Castig_player2_XDreapta = true;

        int X_stanga = X, X_dreapta = X, Y_sus = Y, Y_jos = Y;

        if (X > 1)
            X_stanga = X - 1;
        if (X < N)
            X_dreapta = X + 1;
        if (Y > 1)
            Y_sus = Y - 1;
        if (Y < N)
            Y_jos = Y  + 1;
        if (x[Y][X_stanga] == 2 && Matrice_DFS_Vizitare[Y][X_stanga] == 0)
            parcurgere_DFS_player2(x, X_stanga, Y);

        if (x[Y][X_dreapta] == 2 && Matrice_DFS_Vizitare[Y][X_dreapta] == 0)
            parcurgere_DFS_player2(x, X_dreapta, Y);

        if (x[Y_sus][X] == 2 && Matrice_DFS_Vizitare[Y_sus][X] == 0)
            parcurgere_DFS_player2(x, X, Y_sus);

        if (x[Y_jos][X] == 2 && Matrice_DFS_Vizitare[Y_jos][X] == 0)
            parcurgere_DFS_player2(x, X, Y_jos);

    }

}
bool DFS_Player_2 (int x[15][15], int X, int Y) // Daria
{
    for (int i = 0; i <= N; i ++)
        for (int j = 0; j <= N; j ++)
            Matrice_DFS_Vizitare[i][j] = 0; // reinitializare matrice de viz
    Castig_player2_XStanga = Castig_player2_XDreapta = 0;

    parcurgere_DFS_player2(x, X, Y);

    afisareTabla(Matrice_DFS_Vizitare); //matrice de vizitare
    if (Castig_player2_XStanga== true && Castig_player2_XDreapta == true)
        return true;
    return false;

}

void DeseneazaBridge(int x, int y, int player_curent) //Daria
{

    int x1 = x * coordonate_tabla_x_graphics + coordonate_tabla_x_graphics / 2;
    int y1 = y * coordonate_tabla_y_graphics + coordonate_tabla_y_graphics / 2;


    if (player_curent == 1)
    {
        setlinestyle(SOLID_LINE, 0, 9); //grosime
        setcolor(CuloarePlayer1);
    }
    else
    {
        setlinestyle(SOLID_LINE, 0, 9);
        setcolor(CuloarePlayer2);
    }

    int x2, y2;

    if (Tabla[y - 1][x] == player_curent)
    {
        // Pod vertical (sus-jos)
        x2 = x1;
        y2 = (y - 1) * coordonate_tabla_y_graphics + coordonate_tabla_y_graphics / 2;
        line(x1, y1, x2, y2);
    }

    if (Tabla[y + 1][x] == player_curent)
    {
        // Pod vertical (jos-sus)
        x2 = x1;
        y2 = (y + 1) * coordonate_tabla_y_graphics + coordonate_tabla_y_graphics / 2;
        line(x1, y1, x2, y2);
    }

    if (Tabla[y][x - 1] == player_curent)
    {
        // Pod orizontal (stânga-dreapta)
        x2 = (x - 1) * coordonate_tabla_x_graphics + coordonate_tabla_x_graphics / 2;
        y2 = y1;
        line(x1, y1, x2, y2);
    }

    if (Tabla[y][x + 1] == player_curent)
    {
        // Pod orizontal (dreapta-stânga)
        x2 = (x + 1) * coordonate_tabla_x_graphics + coordonate_tabla_x_graphics / 2;
        y2 = y1;
        line(x1, y1, x2, y2);
    }
}
void MiscareGresita() // Cristi
{
    if (PlayerCurent == 1)
        setcolor(CuloarePlayer1);

    else
        setcolor(CuloarePlayer2);


    outtextxy(20,450,"Coordonate Gresite.");
    this_thread::sleep_for(chrono::seconds(1));

    setcolor(BLACK);
    outtextxy(20,450,"Coordonate Gresite.");

}

void puneBridge(int x[15][15], int playerCurent) // Cristi + Daria
{

    int X = 2;
    int Y = 2;


    if (playerCurent == 1)
        setcolor(CuloarePlayer1);
    else
        setcolor(CuloarePlayer2);

    int pusBridge = 0;

    while(pusBridge == 0)
    {

        outtextxy( 40*N + 54, 40*Y + 25, "<");

        int tasta = 0;

        while (tasta != 13)
        {

            tasta = getch();

            if (tasta == KEY_DOWN && Y < N - 1)
            {
                setcolor(BLACK);
                outtextxy( 40*N + 54, 40*Y + 25, "<");

                Y++;

                if (playerCurent == 1)
                    setcolor (CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);

                outtextxy( 40*N + 54, 40*Y + 25, "<");

            }

            if (tasta == KEY_UP && Y > 2)
            {
                setcolor(BLACK);
                outtextxy( 40*N + 54, 40*Y + 25, "<");

                Y--;

                if (playerCurent == 1)
                    setcolor (CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);

                outtextxy( 40*N + 54, 40*Y + 25, "<");

            }

            if (tasta == 13)
            {

                setcolor(BLACK);
                outtextxy( 40*N + 54, 40*Y + 25, "<");

                if (playerCurent == 1)
                    setcolor (CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);
            }



        }

        tasta = 0;

        while (tasta != 13)
        {

            outtextxy( 40*X + 14, 40*N + 65, "A");

            tasta = getch();


            if (tasta == KEY_LEFT && X > 2)
            {

                setcolor(BLACK);
                outtextxy( 40*X + 14, 40*N + 65, "A");

                X--;

                if (playerCurent == 1)
                    setcolor(CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);

                outtextxy( 40*X + 14, 40*N + 65, "A");
            }


            if (tasta == KEY_RIGHT && X < N - 1)
            {
                setcolor(BLACK);
                outtextxy( 40*X + 14, 40*N + 65, "A");

                X++;

                if (playerCurent == 1)
                    setcolor(CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);

                outtextxy( 40*X + 14, 40*N + 65, "A");
            }

            if (tasta == 13)
            {

                setcolor(BLACK);
                outtextxy( 40*X + 14, 40*N + 65, "A");

                if (playerCurent == 1)
                    setcolor (CuloarePlayer1);
                else
                    setcolor(CuloarePlayer2);
            }

        }



        Player_X_Curent = X;
        Player_Y_Curent = Y;

        if (x[Y][X]==0)
        {
            if ( (x[Y+1][X] == playerCurent && x[Y-1][X] == playerCurent && Y!=1) || (x[Y][X+1] == playerCurent && x[Y][X-1] == playerCurent && X!=1))
            {
                DeseneazaBridge(X,Y,playerCurent);
                x[Y][X] = playerCurent;
                pusBridge = 1;

            }
        }


    }
}

void DeseneazaTabla()//Daria
{

    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
    settextjustify(0,1);
    for (int i = 1; i<= N ; i++)
        for (int j = 1; j<= N; j++)
        {
            int x1 = coordonate_tabla_x_graphics * i; // coltul stanga sus
            int x2 = coordonate_tabla_x_graphics * (i + 1);//colt dreapta jos
            int y1 = coordonate_tabla_y_graphics * j;//colt stanga sus
            int y2 = coordonate_tabla_y_graphics * (j + 1);//colt dreapta jos

            rectangle(x1,y1,x2,y2);


        }

    for (int i = 1; i <=N; i++)
        for (int j = 1; j <=N ; j++)
        {

            int x = coordonate_tabla_x_graphics * i + 20;
            int y = coordonate_tabla_y_graphics * j + 20;

            if ((i+j)%2==1)
            {
                if (i%2==1)
                    setfillstyle(SOLID_FILL, CuloarePlayer2);
                else
                    setfillstyle(SOLID_FILL, CuloarePlayer1);

                circle(x,y,10);
                fillellipse(x,y,10,10);
            }

        }

    if (PlayerCurent == 1)
    {
        setcolor (CuloarePlayer1);
        outtextxy(40,20,"PLAYER CURENT: 1");

        setcolor (WHITE);
        setbkcolor(BLUE);
        outtextxy(500,50,"1.PUNE BRIDGE");
        setbkcolor(BLACK);
        outtextxy(500,100,"2.IESI DIN PROGRAM");
    }


}

void AfiseazaCastigator(int player_curent) //Cristi
{

    this_thread::sleep_for(chrono::seconds(1));
    cleardevice();
    if (player_curent == 1)
        outtextxy(250,250,"A castigat player 1!");

    else
        outtextxy(250,250,"A castigat player 2!");

    getch();

}

void DeseneazaMeniu()//Cristi
{
    int gdriver = DETECT, gmode;
    initwindow(1000,700,"Bridg-it");
    settextstyle(1,HORIZ_DIR,4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(LIGHTRED);
    outtextxy(500,30,"BRIDG-IT");
    setcolor (WHITE);
    setbkcolor(RED);
    outtextxy(500,130,"1.PLAY");
    setbkcolor(BLUE);
    outtextxy(500,230,"2.OPTIUNI");
    outtextxy(500,330,"3.EXIT");

    int OptiuneMeniu = 1;
    bool selectat = false;
    int key = 0;
    while(selectat != true)
    {

        key = getch();

        if (key == KEY_DOWN && OptiuneMeniu < 3)
        {
            if (OptiuneMeniu == 1)
            {

                setbkcolor(BLUE);
                outtextxy(500,130,"1.PLAY");
                setbkcolor(RED);
                outtextxy(500,230,"2.OPTIUNI");
            }

            else if (OptiuneMeniu == 2)
            {
                setbkcolor(BLUE);
                outtextxy(500,230,"2.OPTIUNI");
                setbkcolor(RED);
                outtextxy(500,330,"3.EXIT");
            }

            OptiuneMeniu++;

        }

        if (key == KEY_UP && OptiuneMeniu > 1)
        {
            if (OptiuneMeniu == 2)
            {
                setbkcolor(RED);
                outtextxy(500,130,"1.PLAY");
                setbkcolor(BLUE);
                outtextxy(500,230,"2.OPTIUNI");
            }


            else if (OptiuneMeniu == 3)
            {
                setbkcolor(RED);
                outtextxy(500,230,"2.OPTIUNI");
                setbkcolor(BLUE);
                outtextxy(500,330,"3.EXIT");
            }

            OptiuneMeniu--;
        }

        if (key == 13 && OptiuneMeniu == 1)
        {
            Optiune = '1';
            selectat = 1;
            setbkcolor(BLACK);
        }
        else if (key == 13 && OptiuneMeniu == 2)
        {
            Optiune = '2';
            selectat = 1;
            setbkcolor(BLACK);
        }

        else if (key == 13 && OptiuneMeniu == 3)
        {
            Optiune = '3';
            selectat = 1;
            setbkcolor(BLACK);
        }
    }
}

void DeseneazaOptiuni()//Cristi
{
    cleardevice();
    settextstyle(1,HORIZ_DIR,4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(LIGHTRED);
    outtextxy(500,30,"ALEGE PLAYERUL");
    setcolor (WHITE);
    setbkcolor(RED);
    outtextxy(500,130,"PLAYER 1");
    setbkcolor(BLUE);
    outtextxy(500,230,"PLAYER 2");
    setbkcolor(BLACK);

    int OptiuneMeniu = 1;
    bool selectat = false;
    int key = 0;

    while(selectat != true)
    {

        key = getch();

        if (key == KEY_DOWN && OptiuneMeniu < 2)
        {
            if (OptiuneMeniu == 1)
            {

                setbkcolor(BLUE);
                outtextxy(500,130,"PLAYER 1");
                setbkcolor(RED);
                outtextxy(500,230,"PLAYER 2");
            }

            OptiuneMeniu++;

        }

        if (key == KEY_UP && OptiuneMeniu > 1)
        {
            if (OptiuneMeniu == 2)
            {
                setbkcolor(RED);
                outtextxy(500,130,"PLAYER 1");
                setbkcolor(BLUE);
                outtextxy(500,230,"PLAYER 2");
            }

            OptiuneMeniu--;
        }

        if (key == 13 && OptiuneMeniu == 1)
        {
            int SelectatCuloare = 0;
            while(SelectatCuloare == 0)
            {
                cleardevice();
                setbkcolor(BLACK);

                settextstyle(1,HORIZ_DIR,4);
                settextjustify(CENTER_TEXT,CENTER_TEXT);
                setcolor(LIGHTRED);
                outtextxy(500,30,"ALEGE CULOAREA");

                settextstyle(1,HORIZ_DIR,2);
                setcolor(WHITE);
                outtextxy(300,100,"0 - BLACK");
                outtextxy(300,150,"1 - BLUE");
                outtextxy(300,200,"2 - GREEN");
                outtextxy(300,250,"3 - CYAN");
                outtextxy(300,300,"4 - RED");

                outtextxy(600,100,"5 - MAGENTA");
                outtextxy(600,150,"6 - BROWN");
                outtextxy(600,200,"7 - LIGHT GRAY");
                outtextxy(600,250,"8 - DARK GRAY");
                outtextxy(600,300,"9 - LIGHT BLUE");

                char culoare = getch();

                fstream OptiuniJoc("OptiuniJocTemp.txt");
                fstream RescrieOptiuni("OptiuniJoc.txt");

                char CuloareJucatori[5][50];
                int i = 1;
                if (OptiuniJoc.is_open())
                {
                    char LinieOptiuniJoc[50];

                    while (OptiuniJoc.getline(LinieOptiuniJoc, 50))
                    {
                        strcpy(CuloareJucatori[i],LinieOptiuniJoc);
                        i++;

                    }

                }

                CuloareJucatori[1][17] = culoare;

                RescrieOptiuni<<CuloareJucatori[1]<<endl;
                RescrieOptiuni<<CuloareJucatori[2]<<endl;

                OptiuniJoc<<CuloareJucatori[1]<<endl;
                OptiuniJoc<<CuloareJucatori[2]<<endl;

                SelectatCuloare = 1;
                selectat = 1;

            }



        }
        else if (key == 13 && OptiuneMeniu == 2)
        {
            int SelectatCuloare = 0;
            while(SelectatCuloare == 0)
            {


                cleardevice();
                setbkcolor(BLACK);

                settextstyle(1,HORIZ_DIR,4);
                settextjustify(CENTER_TEXT,CENTER_TEXT);
                setcolor(LIGHTRED);
                outtextxy(500,30,"ALEGE CULOAREA");

                settextstyle(1,HORIZ_DIR,2);
                setcolor(WHITE);
                outtextxy(300,100,"0 - BLACK");
                outtextxy(300,150,"1 - BLUE");
                outtextxy(300,200,"2 - GREEN");
                outtextxy(300,250,"3 - CYAN");
                outtextxy(300,300,"4 - RED");

                outtextxy(600,100,"5 - MAGENTA");
                outtextxy(600,150,"6 - BROWN");
                outtextxy(600,200,"7 - LIGHT GRAY");
                outtextxy(600,250,"8 - DARK GRAY");
                outtextxy(600,300,"9 - LIGHT BLUE");

                char culoare = getch();

                fstream OptiuniJoc("OptiuniJocTemp.txt");
                fstream RescrieOptiuni("OptiuniJoc.txt");

                char CuloareJucatori[5][50];
                int i = 1;

                if (OptiuniJoc.is_open())
                {
                    char LinieOptiuniJoc[50];

                    while (OptiuniJoc.getline(LinieOptiuniJoc, 50))
                    {
                        strcpy(CuloareJucatori[i],LinieOptiuniJoc);
                        i++;
                    }

                }

                CuloareJucatori[2][17] = culoare;
                RescrieOptiuni<<CuloareJucatori[1]<<endl;
                RescrieOptiuni<<CuloareJucatori[2]<<endl;


                SelectatCuloare = 1;
                selectat = 1;

                OptiuniJoc.close();
                RescrieOptiuni.close();
            }

        }
    }
}

void CalculatorRandom(int x[15][15]) // Cristi
{


    int pusBridge = 0;

    while (pusBridge == 0)
    {

        srand(time(0));

        int pozX = rand() % N + 1;
        int pozY = rand() % N + 1;

        if (pozX == N)
            pozX--;

        if (pozY == N)
            pozY--;

        if (x[pozY][pozX] == 0)
        {


            if ( (x[pozY+1][pozX] == 2  && x[pozY-1][pozX] == 2 && pozY!=1) || (x[pozY][pozX+1] == 2 && x[pozY][pozX-1] == 2 && pozX!=1))
            {
                DeseneazaBridge(pozX,pozY,2);
                x[pozY][pozX] = 2;
                pusBridge = 1;

            }

            if (pusBridge == 1)
                DFS_Player_2(x,pozX,pozY);
        }


    }

}
//partea de strategie sa incerce sa castige
int EvaluareTabla(int x[15][15], int jucator)//Daria
{
    int scor = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (x[i][j] == jucator)
            {
                scor += 1;

                // Verificăm piese consecutive
                if (x[i][j + 1] == jucator) scor += 2;
                if (x[i + 1][j] == jucator) scor += 2;
                if (x[i + 1][j + 1] == jucator) scor += 2;
                if (x[i + 1][j - 1] == jucator) scor += 2;
            }
        }
    }
    return scor;
}
void CalculatorStrategie (int x[15][15], int X, int Y)//Daria
{
    int cnt = 2;
    int ok = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (x[i][j] == 0)
            {
                x[i][j] = 2;
                if (DFS_Player_2(x, i, j) == true)
                {
                    DeseneazaBridge(i, j, 2);
                    Player_X_Curent = i;
                    Player_Y_Curent = j;
                    x[Player_Y_Curent][Player_X_Curent] = 2;
                    ok = 1;
                    break;
                }
                x[i][j] = 0;
            }

    while (cnt <= N && !ok)
    {
        int y1 = Y - cnt;
        int y2 = Y + cnt;
        if (y1 > 1 && y1 < N)
        {
            if (x[y1][X] == 0)
            {

                Player_X_Curent = X;
                Player_Y_Curent = y1;
                x[Player_Y_Curent][Player_X_Curent] = 2;

                DeseneazaBridge(X, y1, 2);
                ok = 1;
                break;
            }

        }
        else
        {
            if (y2 > 1 && y2 < N)
                if (x[y2][X] == 0)
                {
                    DeseneazaBridge(X, y2, 2);
                    Player_X_Curent = X;
                    Player_Y_Curent = y2;
                    x[Player_Y_Curent][Player_X_Curent] = 2;
                    ok = 1;
                    break;
                }
        }
        cnt += 2;
    }

    // tot partea de strategie
    if (!ok)
    {
        int bestX = -1, bestY = -1;
        int bestScore = -1000;

        // Verificăm toate pozițiile libere
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (x[i][j] == 0)
                {
                    x[i][j] = 2; // temporar


                    int score = EvaluareTabla(x, 2) - EvaluareTabla(x, 1);

                    x[i][j] = 0; // Revenim la starea inițială

                    if (DFS_Player_2(x, i, j) == true)
                    {
                        bestX = i;
                        bestY = j;
                        ok = 1;
                    }
                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestX = j;
                        bestY = i;
                    }
                }
            }
        }
        if (bestX != -1 && bestY != -1)
        {
            DeseneazaBridge(bestX, bestY, 2);
            Player_X_Curent = bestX;
            Player_Y_Curent = bestY;
            x[Player_Y_Curent][Player_X_Curent] = 2;
        }
    }

}

int main()
{

    int contor = 0;
    for (int i =300 ; i<=600; i = i + 100)
        Beep(i,50);



    //OptiuniJoc.close();


    Initializare(Tabla);

    DeseneazaMeniu ();

    if (Optiune == '3')
        return 0;


    if (Optiune == '2')
    {
        DeseneazaOptiuni();
        return 0;


    }



    ifstream OptiuniJoc("OptiuniJoc.txt");

    if (OptiuniJoc.is_open())
    {
        char LinieOptiuniJoc[50];

        while (OptiuniJoc.getline(LinieOptiuniJoc, 50))
        {


            if (LinieOptiuniJoc[13] == '1')
                CuloarePlayer1 = LinieOptiuniJoc[17] - '0';
            else if (LinieOptiuniJoc[13] == '2')
                CuloarePlayer2 = LinieOptiuniJoc[17] - '0';
        }


    }




    OptiuneJucator = 0;
    AlegeOponent();


    int coordonataX = 0, coordonataY = 0;

    Beep(465,50);
    Beep(365,50);


    if (OptiuneJucator == 1)
    {
        AlegeDimensiuneTabla();
        DeseneazaTabla();
        while(Optiune!='2' && Optiune != 2)
        {


            afisareTabla(Tabla);

            int tasta = 0;

            Optiune = 1;
            while (tasta != 13)

            {
                tasta = getch();

                if (tasta == KEY_DOWN && Optiune != 2)
                {
                    Optiune = 2;
                    setcolor (WHITE);
                    setbkcolor(BLACK);
                    outtextxy(500,50,"1.PUNE BRIDGE");
                    setbkcolor(BLUE);
                    outtextxy(500,100,"2.IESI DIN PROGRAM");

                }

                else if (tasta == KEY_UP && Optiune != 1)
                {
                    Optiune = 1;
                    setcolor (WHITE);
                    setbkcolor(BLUE);
                    outtextxy(500,50,"1.PUNE BRIDGE");
                    setbkcolor(BLACK);
                    outtextxy(500,100,"2.IESI DIN PROGRAM");
                }
            }

            Beep(465,50);
            Beep(365,50);

            if (Optiune == 1)
            {
                puneBridge(Tabla, PlayerCurent);

                if (PlayerCurent == 1)
                    if ( DFS_Player_1(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                    {
                        AfiseazaCastigator(PlayerCurent);

                        return 1;
                    }


                if (PlayerCurent == 2)
                    if (DFS_Player_2(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                    {
                        AfiseazaCastigator(PlayerCurent);

                        return 2;
                    }

                if (PlayerCurent == 1)
                {
                    PlayerCurent = 2;
                    setcolor (CuloarePlayer2);
                    outtextxy(40,20,"PLAYER CURENT: 2");
                }
                else
                {
                    PlayerCurent = 1;
                    setcolor (CuloarePlayer1);
                    outtextxy(40,20,"PLAYER CURENT: 1");
                }

            }

        }
    }

    else if (OptiuneJucator == 2)
    {
        AlegeDificultate();
        AlegeDimensiuneTabla();
        DeseneazaTabla();
        while (Optiune != '2' && Optiune != 2)
        {

            afisareTabla(Tabla);


            if (PlayerCurent == 1)
            {
                int tasta = 0;
                Optiune = 1;
                while (tasta != 13)

                {
                    tasta = getch();

                    if (tasta == KEY_DOWN && Optiune != 2)
                    {
                        Optiune = 2;
                        setcolor (WHITE);
                        setbkcolor(BLACK);
                        outtextxy(500,50,"1.PUNE BRIDGE");
                        setbkcolor(BLUE);
                        outtextxy(500,100,"2.IESI DIN PROGRAM");

                    }

                    else if (tasta == KEY_UP && Optiune != 1)
                    {
                        Optiune = 1;
                        setcolor (WHITE);
                        setbkcolor(BLUE);
                        outtextxy(500,50,"1.PUNE BRIDGE");
                        setbkcolor(BLACK);
                        outtextxy(500,100,"2.IESI DIN PROGRAM");
                    }
                }

                Beep(465,50);
                Beep(365,50);
            }

            if (OptiuneDificultate == 1)
            {

                if (Optiune == 1 && PlayerCurent == 1)
                {
                    puneBridge(Tabla, PlayerCurent);



                    if (DFS_Player_1(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                    {
                        AfiseazaCastigator(PlayerCurent);

                        return 1;
                    }


                    if (PlayerCurent == 1)
                    {
                        PlayerCurent = 2;
                        setcolor (CuloarePlayer2);
                        outtextxy(40,20,"PLAYER CURENT: 2");
                    }
                }

                else if (PlayerCurent == 2)
                {
                    CalculatorRandom(Tabla);
                    PlayerCurent = 1;
                    setcolor (CuloarePlayer1);
                    outtextxy(40,20,"PLAYER CURENT: 1");
                    if (DFS_Player_2(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                    {
                        AfiseazaCastigator(PlayerCurent);
                        return 2;
                    }
                    PlayerCurent = 1;
                    setcolor (CuloarePlayer1);
                    outtextxy(40,20,"PLAYER CURENT: 1");
                }

            }
            else if (OptiuneDificultate == 2)
            {
                //strategie
                if (Optiune == 1 && PlayerCurent == 1)
                {
                    puneBridge(Tabla, PlayerCurent);



                    if (DFS_Player_1(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                    {
                        AfiseazaCastigator(PlayerCurent);

                        return 1;
                    }


                    if (PlayerCurent == 1)
                    {
                        PlayerCurent = 2;
                        setcolor (CuloarePlayer2);
                        outtextxy(40,20,"PLAYER CURENT: 2");
                    }
                }

                else if (PlayerCurent == 2)
                {

                        CalculatorStrategie(Tabla, Player_X_Curent, Player_Y_Curent);
                        if (DFS_Player_2(Tabla,Player_X_Curent,Player_Y_Curent) == true)
                        {
                            AfiseazaCastigator(PlayerCurent);
                            return 2;
                        }
                        PlayerCurent = 1;
                        setcolor (CuloarePlayer1);
                        outtextxy(40,20,"PLAYER CURENT: 1");


                }
            }
        }

    }

}
