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

class Main {
  private:
    std::regex patron_;

  public:
    Main() : patron_(R"(^\s*int\smain\s*\(.*\)\s*\{)") {}
    void BuscarMain(std::ifstream& archivo_ent, std::ofstream& archivo_sal);
};