// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Estructura:
// Representa la estructura general de un código
// Estructura de datos principal:
// - struct - Almacena datos de las características del código
// - std::vector<std::string> - Almacena las lineas de la descripción
// - std::vector<struct> - Almacena structs que contienen datos del código

#pragma once

#include <regex>
#include <string>
#include <vector>

// Almacena el número de linea y el tipo de bucle
struct DatosBucle {
  int linea;
  std::string tipo;
};

// Almacena el número de linea, tipo de dato, nombre y valor de una variable
struct DatosVariable {
  int linea;
  std::string tipo;
  std::string nombre;
  std::string valor = "";
};

// Almacena el número de linea y el comentario
struct DatosComentario {
  int linea;
  std::string comentario;
};

// Primera y ultima linea de la descripcion
struct InicioFinDescripcion {
  int inicio;
  int final;
};

// Primera y ultima linea de los comentarios de varias lineas
struct DatosComentarioLargo {
  int inicio;
  int final;
};

struct DatosSwitch {
  int linea;
  std::string opcion;
  int numero_casos;
};

class Estructura {
  private:
    std::string nombre_programa_;
    std::vector<std::string> descripcion_;
    std::vector<DatosBucle> bucles_;
    std::vector<DatosVariable> variables_;
    std::vector<DatosComentario> comentarios_;
    std::vector<DatosComentarioLargo> comentarios_largos_;
    std::vector<DatosSwitch> switch_;
    InicioFinDescripcion valores_;
    bool main_;

  public:
    void Write(std::ostream& os) const;

    // Sets
    void SetPrograma(std::string& nombre) {nombre_programa_ = nombre;};
    void SetLongitudDescripcion(int x, int y) {valores_ = {x, y};}
    void SetMain(bool condicion) {main_ = condicion;}

    // Push´s
    void PushSwitch(DatosSwitch data) {switch_.push_back(data);}
    void PushBucle(DatosBucle data) {bucles_.push_back(data);}
    void PushVariable(DatosVariable data) {variables_.push_back(data);}
    void PushComentario(DatosComentario data) {comentarios_.push_back(data);}
    void PushDescripcion(std::string linea) {descripcion_.push_back(linea);}
    void PushLongitudComentarios(int x, int y) {comentarios_largos_.push_back({x, y});}  
};

// Sobrecarga de operador
std::ostream& operator<<(std::ostream& os, const Estructura& aux);