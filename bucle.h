// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025

#include <fstream>
#include <regex>
#include <string>

class Statement {
  private:
    std::regex patron_;
    std::string linea_;

  public:
    Statement() : patron_(R"(\s*(for|while)\s*\([^\)]*\))") {}
    void BuscarBucles(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i = 1);
};