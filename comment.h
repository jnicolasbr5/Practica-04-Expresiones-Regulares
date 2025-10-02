// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Comments:
// Representa una expresión regular de comentarios de una línea ´//´.
// Verifica si el código contiene comentarios y los almacena

#pragma once

#include <fstream>
#include <regex>

#include "estructura.h"

class Comments {
  private:
    std::regex patron_;

  public:
    Comments() : patron_(R"(//\s+.*$)") {}
    void BuscarComentarios(std::ifstream& archivo_ent, Estructura& est, int i = 1);
};