/*
  Archivo: Main.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-11
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

//Utilidad: DemostraciC3n arreglos bidimensionales

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "notas.h"

using namespace std;

int main()
{
    Notas notas;
    notas.generarListado();
    cout << "El Promedio General del Grupo es: " << notas.promGenGrupo() << endl;
   // cout << "EL Promedio del estudiate es:" << notas.promEstudiante() << endl;
    notas.mejorDef();
    notas.mejorNotaReg();
    notas.promNotas();
    notas.evalMejorProm();
    notas.evalPeorProm();
    notas.ciertaEva(2);
    notas.ciertoEst("Santiago............");
  //  cout << notas.estudiantes[0];
    return 0;
}
