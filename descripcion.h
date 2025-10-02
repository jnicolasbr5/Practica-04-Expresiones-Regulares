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


class Description {
  private:
    std::regex patron_;
    int inicio_descripcion_;
    int final_descripcion_;

  public:
    Description() : patron_(R"((^\s*/\*\*.*$)|(^\s*\*.*$)|(^\s*\*/))") {}
    void BuscarDescripcion(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i = 1);
    int GetInicio() const {return inicio_descripcion_;}
    int GetFinal() const {return final_descripcion_;}
  };
			/** */
   //   ^\/\*(\s*\S*)*\*\/$