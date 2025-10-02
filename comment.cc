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
#include <iostream>
#include <regex>
#include <string>

#include "comment.h"

void Comments::BuscarComentarios(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i) {
  std::string linea;
	while(std::getline(archivo_ent, linea)) {
		std::smatch coincidencia;
		if(std::regex_search(linea, coincidencia, patron_)){
			archivo_sal << "[Line " << i << "] " << coincidencia[0] << std::endl;
		}	
		i++;
	}
	
}