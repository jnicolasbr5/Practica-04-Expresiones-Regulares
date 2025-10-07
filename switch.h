// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Bucle:
// Representa una expresión regular de un bucle.
// Verifica si el código tiene bucles y los almacena

#pragma once

#include <fstream>
#include <regex>

#include "estructura.h"

class Switch {
  private:
    std::regex patron_;
    std::regex patron_casos_;
    std::regex default_;

  public:
    Switch() : patron_(R"(\s*switch\s*\((.*)\))"), patron_casos_(R"(\s*case\s*.*$)"), default_(R"(\s*default\s*:)"){}

    void BuscarSwitch(std::ifstream& archivo_ent, Estructura& est, int i = 1, int j = 0);
};