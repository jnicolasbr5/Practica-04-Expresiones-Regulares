// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025

#include <iostream>

#include "estructura.h"

// Muestra por pantalla la estructura general del código
void Estructura::Write(std::ostream& os) const {
  os << "PROGRAMM: " << nombre_programa_ << std::endl;
  os << "DESCRIPTION:" << std::endl;
  for (size_t i = 0; i < descripcion_.size(); i++) {
    os << descripcion_[i] << std::endl;
  }
  os << "\nVARIABLES:" << std::endl;
  for (size_t i = 0; i < variables_.size(); i++) {
    os << "[Line " << variables_[i].linea << "] " << variables_[i].tipo
       << ": " << variables_[i].nombre;
    if (!variables_[i].valor.empty()) {
      os << " = " << variables_[i].valor;
    }
    os << std::endl;
  }
  os << "\nSTATEMENTS:" << std::endl;
  for (size_t i = 0; i < bucles_.size(); i++) {
    os << "[Line " << bucles_[i].linea << "] LOOP: " << bucles_[i].tipo << std::endl;
  }
  os << "\nMAIN:" << std::endl;
  if (main_) os << "True" << std::endl;
  else os << "False" << std::endl;
  os << "\nCOMMENTS:" << std::endl;
  if (!descripcion_.empty()) {
    os << "[Line " << valores_.inicio << "-" << valores_.final << "] DESCRIPTION" << std::endl;
  }
  for (size_t i = 0; i < comentarios_largos_.size(); i++) {
    os << "[Line " << comentarios_largos_[i].inicio << "-" << comentarios_largos_[i].final
       << "] COMMENT" << std::endl; 
  }
  for (size_t i = 0; i < comentarios_.size(); i++) {
    os << "[Line " << comentarios_[i].linea << "] " << comentarios_[i].comentario << std::endl; 
  }
}

std::ostream& operator<<(std::ostream& os, const Estructura& aux) {
  aux.Write(os);
  return os;
}