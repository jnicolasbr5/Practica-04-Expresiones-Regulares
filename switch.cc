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

#include "switch.h"
#include "estructura.h"

// Detecta bucles y los almacena en Estructura
void Switch::BuscarSwitch(std::ifstream& archivo_ent, Estructura& est, int i, int j) {
  std::string linea;
  std::string opcion;
  int numero_linea;
	while(std::getline(archivo_ent, linea)) {
		std::smatch coincidencia;
		if(std::regex_search(linea, coincidencia, patron_)){
            opcion = coincidencia[1].str();
            numero_linea = i;
		} else if (std::regex_match(linea, patron_casos_)) {
            j++;
    } else if(std::regex_match(linea, default_)) {
            est.PushSwitch(DatosSwitch{numero_linea, opcion, j});
            j = 0;
    }
		i++;
	}
}