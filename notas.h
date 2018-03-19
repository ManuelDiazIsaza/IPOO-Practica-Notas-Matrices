/*
  Archivo: Notas.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2018-02-09
  Fecha Última modificación: 2018-02-09
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Notas
// Responsabilidad: Gestionar las notas de los estudiantes
// ColaboraciÃ³n: ninguna


#ifndef NOTAS_H_H
#define NOTAS_H_H

#include <string>
using namespace std;

class Notas{
  private:
    double notas[5][5];
    double promedios[5];
    string estudiantes[5];
    double generarNota();
    void agregarEstudiantes();

  public:
    Notas();
    ~Notas();
    void generarListado();
    double promGenGrupo();
    void promEstudiante();
};

#endif