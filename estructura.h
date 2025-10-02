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
// Representa un alfabeto que contiene símbolos.
// Verifica si una cadena está formada por los símbolos del alfabeto
// Estructura de datos principal:
// - std::set<char> - almacena símbolos de manera ordenada
// Historial de modificaciones:
// Bug fix 1 - Corregida la llamada de funciones en sobrecargas.
// Bug fix 2 - Añado IsEmpty() para vaciar el alfabeto al añadir uno nuevo.
// Bug fix 3 - ComprobarAlfabetoCadena() verifica que los símbolos de las
//             cadenas existen en el alfabeto

#pragma once

#include <fstream>
#include <regex>
#include <string>
#include <vector>

struct DatosBucle {
  int linea;
  std::string tipo;
};

struct DatosVariable {
  int linea;
  std::string tipo;
  std::string nombre;
  std::string valor = "";
};

struct DatosComentario {
  int linea;
  std::string comentario;
};

struct InicioFinDescripcion {
  int inicio;
  int final;
};

struct DatosComentarioLargo {
  int inicio;
  int final;
};

class Estructura {
  private:
    std::string nombre_programa_;
    std::vector<std::string> descripcion_;
    std::vector<DatosBucle> bucles_;
    std::vector<DatosVariable> variables_;
    std::vector<DatosComentario> comentarios_;
    std::vector<DatosComentarioLargo> comentarios_largos_;
    InicioFinDescripcion valores_;
    bool main_;

  public:
    void Write(std::ostream& os) const;

    // Set, Get y Push
    void SetPrograma(std::string& nombre) {nombre_programa_ = nombre;};
    void PushBucle(DatosBucle data) {bucles_.push_back(data);}
    void PushVariable(DatosVariable data) {variables_.push_back(data);}
    void PushComentario(DatosComentario data) {comentarios_.push_back(data);}
    void PushDescripcion(std::string linea) {descripcion_.push_back(linea);}
    void SetLongitudDescripcion(int x, int y) {valores_ = {x, y};}
    void PushLongitudComentarios(int x, int y) {comentarios_largos_.push_back({x, y});}
    void SetMain(bool condicion) {main_ = condicion;}
};

std::ostream& operator<<(std::ostream& os, const Estructura& aux);
