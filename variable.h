// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Variable:
// Representa una expresión regular de una variable.
// Verifica si el código tiene variables y las almacena


#pragma once

#include <fstream>
#include <regex>

#include "estructura.h"

class Variable {
  private:
    std::regex patron_;

  public:
    Variable() : patron_(R"(^\s*(int|double)\s+([a-z_]+)\s*=?\s*([0-9]+|[0-9]+\.[0-9]+)?\s*;)") {}
    void BuscarVariables(std::ifstream& archivo_ent, Estructura& est, int i = 1);
};
