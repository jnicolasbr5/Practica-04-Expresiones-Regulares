// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Description:
// Representa una expresión regular de los comentarios de multiples lineas.
// Verifica si el código contiene comentarios de varias lineas y los almacena

#pragma once

#include <fstream>
#include <regex>

#include "estructura.h"

class Description {
  private:
    std::regex patron_;

  public:
    Description() : patron_(R"((^\s*/\*\**.*$)|(^\s*\*[^/].*$)|(^\s*\*/))") {}
    void BuscarDescripcion(std::ifstream& archivo_ent, Estructura& est, int i = 1);
  };