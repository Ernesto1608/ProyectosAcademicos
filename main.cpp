//
//  main.cpp
//  ProyectoIntegrador
//
//  Created by Ernesto Garcia on 11/17/18.
//  Copyright © 2018 Ernesto Garcia. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdio.h>
using namespace std;
/*
Para poder utilizar srand((int)time(0)); es necesario poner  #include <ctime>
*/
/*
 Yo utilizo como variable global el arreglo cMatTablero (de tipo char) para poner el contenido del tablero; si no hay ficha se coloca un espacio en blanco (' ') y si hay ficha se coloca su caracter.
 */
char cMatTablero[5][8];
/*
 También utilizo el arreglo de una dimensión cArrFiguras(de tipo char) para guardar temporalmente los caracteres que usará mi juego.
*/
char cArrFiguras[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

/*
 Esta función genera aleatoriamente los caracteres para las fichas para el tablero, de manera que en cada juego sean diferentes.
 */
void llenaTablero()
{
    int iR, iC, iContFicha, iValorFicha;
    
    // primero inicializa el arreglo con espacios en blanco
    for (iR = 0; iR < 5; iR++)
        for (iC = 0; iC < 8; iC++)
            cMatTablero[iR][iC] = ' ';
    
    srand((int)time(0));
    for (iValorFicha = 0, iContFicha = 0; iValorFicha < 10;
         iContFicha = 0, iValorFicha++)
    {
        do
        {
            iR = rand() % (5);
            iC = rand() % (8);
            if (cMatTablero[iR][iC] == ' ')
            {
                cMatTablero[iR][iC] = cArrFiguras[iValorFicha];
                iContFicha++;
            }
        } while (iContFicha != 4); // debo poner 4 Fichas de cada numero
    }
}

// Esta función del programa despliega el tablero
int c;
void desplegarTablero(){
    for(int i=0;i<5;i++){
        for(int x=0;x<8;x++){
            c++;
            if(c<10){
                cout << " ( " << c << ")" << cMatTablero[i][x] << " ";
            }
            else
                cout << " (" << c << ")" << cMatTablero[i][x] << " ";
        }
        cout << endl;
    }
    c=0;
}

// Esta función pregunta si quiere seguir jugando y se asegura de que sea una entrada válida
void preguntarSeguir(char &seguirjugando){
    string seguirjugando1;
    cout << "¿Quieres seguir jugando? (s/n)" << endl;
    do{
        cin >> seguirjugando1;
        if(seguirjugando1.size()!=1){
        cout << "Introduce solo una letra" << endl;
        }
        else{
            seguirjugando=seguirjugando1[0];
            if(tolower(seguirjugando)!='n' && tolower(seguirjugando)!='s' ){
            cout << "Introduce solo 's' o 'n'" << endl;
            }
        }
    } while (tolower(seguirjugando)!='n' && tolower(seguirjugando)!='s' );
    desplegarTablero();
}

// Función del juego que realiza todos los procedimientos de validar las casillas
int z,w;
void validarCasillas(int casillasocupadas, int &casilla1, int &casilla2, int &x, int &y, int &x2, int &y2){
    cout << "Quedan " << casillasocupadas << " fichas" << endl;
    cout << "Dame la primer casilla:";
    //En esta primera parte valido las casillas y que no se repitan
    do{
        do{
        cin >> casilla1;
        if (!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        }while(!cin);
        if(casilla1<1 || casilla1>40){
            cout << "Introduce un número de casilla válido" << endl;
        }
        //Aqui asigno valores del arreglo para la primer casilla
        x=((casilla1-1)/8);
        y=((casilla1%8)-1);
        if(casilla1%8==0){
            y=7;
        }
        //Aqui valido si la primer casilla esta vacia o libre
        if((y==0||y==7) && (casilla1>=1 && casilla1<=40) && cMatTablero[x][y]!=' '){
            z++;
        }
        else{
            if(cMatTablero[x][y]!=' ' && (cMatTablero[x][y+1]==' '||cMatTablero[x][y-1]==' ') && (casilla1>=1 && casilla1<=40)){
                z++;
            }
        }
        if(z==0 && (casilla1>=1 && casilla1<=40)){
            cout << "La casilla esta vacía o no esta libre, vuelve a intentarlo" << endl;
        }
    }while (casilla1<1 || casilla1>40 || z==0);
    z=0;
    cout << "Dame la segunda casilla:";
    do{
        do{
            cin >> casilla2;
            if (!cin){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }while(!cin);
        if(casilla2<1 || casilla2>40){
        cout << "Introduce un número de casilla válido" << endl;
        }
        if(casilla2==casilla1){
        cout << "Las casillas no pueden ser iguales, introduce un número de casilla válido" << endl;
        }
        //Aqui asigno valores del arreglo para la segunda casilla
        x2=((casilla2-1)/8);
        y2=((casilla2%8)-1);
        if(casilla2%8==0){
            y2=7;
        }
        //Aqui valido si la segunda casilla esta vacia o libre
        if((y2==0||y2==7) && (casilla2>=1 && casilla2<=40) && cMatTablero[x2][y2]!=' '){
            w++;
        }
        else{
            if(cMatTablero[x2][y2]!=' ' && (cMatTablero[x2][y2+1]==' '||cMatTablero[x2][y2-1]==' ') && (casilla2>=1 && casilla2<=40)){
                w++;
            }
        }
        if(w==0 && (casilla2>=1 && casilla2<=40)){
            cout << "La casilla esta vacía o no esta libre, vuelve a intentarlo" << endl;
        }
    }while (casilla2<1 || casilla2>40 || casilla2==casilla1 || w==0);
    w=0;
}


int casillasocupadas=40,casilla1,casilla2,r,x,y,x2,y2;
char seguirjugando;

int main() {
    llenaTablero();
    do{
        desplegarTablero();
        if(r>0){
        preguntarSeguir(seguirjugando);
        if(tolower(seguirjugando)=='n'){
            return 0;
        }
            seguirjugando='q';
        }
        r++;
        validarCasillas(casillasocupadas,casilla1,casilla2,x,y,x2,y2);
        if(cMatTablero[x][y]==cMatTablero[x2][y2]){
            cMatTablero[x][y]=' ';
            cMatTablero[x2][y2]=' ';
            casillasocupadas-=2;
        }
        else{
            cout << "LAS LETRAS DE LAS CASILLAS NO SON IGUALES, VUELVE A INTENTAR"<< endl;
        }
    }while(casillasocupadas>0);
    cout << "Felicidades ¡GANASTE EL JUEGO!" << endl;
    return 0;
}
