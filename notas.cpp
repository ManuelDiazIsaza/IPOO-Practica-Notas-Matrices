/*
  Archivo: Notas.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include "notas.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

Notas::Notas()
{
  double notas2[5][4] = {{4.2,5,4.2,5},{2.7,4.6,4.6,5},{2.4,3.6,3.8,4.6},{4.4,2.2,5,4.4},{2.7,4.6,5,4.7}};
  srand(time(NULL))  ;
  int filas = sizeof notas / sizeof *notas;
  int columnas = sizeof notas[0] / sizeof *notas[0];
  for (int i = 0 ; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
        {
            notas[i][j] = notas2[i][j];//generarNota();
        }
  }
    agregarEstudiantes();
    promEstudiante();
}

Notas::~Notas(){
  //Destructor aquí
}

double Notas::generarNota(){
  double nota = (0 + rand() % +(50-0)) / 10.0;
  return  nota;
}

void Notas::agregarEstudiantes(){
  string estudiantes[5] = {"Pedro", "Juan", "Mateo", "Tomas", "Santiago"};
  int filas = sizeof this->estudiantes / sizeof *this->estudiantes;
  for(int i = 0; i< filas; i++){
    this->estudiantes[i] = estudiantes[i];
  }
}

void Notas::generarListado(){
  int filas = sizeof notas / sizeof *notas;
  int columnas = sizeof notas[0] / sizeof *notas[0];
  int longitud=0;
  cout << "Estudiantes" << setw(17) << "N1" << setw(7) << "N2" << setw(7) << "N3" << setw(7) << "N4" << setw(7) << "PROM"<< endl;
  cout << "=====================================================================" << endl;
  for (int i = 0 ; i < filas; i++){
    longitud = estudiantes[i].length();
    cout << estudiantes[i].append(20-longitud,'.') << " : " <<setw(5) ;
    for (int j = 0; j < columnas; j++){
      cout << notas[i][j] << setw(7);
    }
    cout << endl;
  }
}

double Notas::promGenGrupo()
{
  int filas = sizeof notas / sizeof *notas;
  int columnas = sizeof notas[0] / sizeof *notas[0];
  double promEstudiantes[filas];
  double acumPromedios=0;
    for (int i = 0 ; i < filas; i++)
    {
    double acumEst=0;
        for (int j = 0; j < columnas; j++)
        {
        acumEst= acumEst + notas[i][j];
        }
    promEstudiantes[i]=acumEst/columnas;
    acumPromedios = promEstudiantes[i] + acumPromedios;
    }
return acumPromedios/filas;
}

void Notas::promEstudiante()
{
  int filas = sizeof notas / sizeof *notas;
  int columnas = (sizeof notas[0] / sizeof *notas[0]) - 1;
    for (int i = 0 ; i < filas; i++)
    {
    double acumEst=0;
        for (int j = 0; j < columnas; j++)
        {
        acumEst= acumEst + notas[i][j];
        }
    this -> notas[i][4] = acumEst/columnas;
    }
}

void Notas::mejorDef()
{
        double mejorNota=0;
        int posicion=0;
        int filas = sizeof notas / sizeof *notas;
        int columnas = sizeof notas[0] / sizeof *notas[0];
        string mejoresEst[columnas];
        for (int i = 0 ; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if(j==4 && notas[i][j] > mejorNota)
                {
                    mejorNota = notas[i][j];
                }

            }
        }
        for (int i = 0 ; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
             {
                if(j==4 && notas[i][j] == mejorNota)
                {
                mejoresEst[posicion] = this -> estudiantes[i];
                posicion++;
                }
             }
         }
        cout << "La mejor nota definitiva es: " << mejorNota << endl;
        cout << "El/Los Estudiante(s) con la mejor nota definitiva son:" << endl;
        for(int i=0;i<posicion;i++)
        {
            cout << mejoresEst[i] << " - ";
        }


}

void Notas::mejorNotaReg()
{
    double mejorNota=0;
    int posicion=0;
    int filas = sizeof notas / sizeof *notas;
    int columnas = sizeof notas[0] / sizeof *notas[0];
    string mejoresEst[columnas];
    int enQueEv[columnas];
    for (int i = 0 ; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if(notas[i][j] > mejorNota)
            {
                mejorNota = notas[i][j];
            }

        }
    }
    for (int i = 0 ; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if(notas[i][j] == mejorNota)
            {
                mejoresEst[posicion] = this -> estudiantes[i];
                enQueEv[posicion] = j;
                posicion++;
            }
        }
    }
    cout << "La mejor nota registrada es: " << mejorNota << endl;
    cout << "El/Los Estudiante(s) con la mejor nota registrada son:" << endl;
    for(int i=0;i<posicion;i++)
    {
        cout << mejoresEst[i] << " en la N"<<enQueEv[i]+1 << endl;
    }
}