// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025

#include "variable.h"

void Variable::BuscarVariables(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i) {
  while(std::getline(archivo_ent, linea_)) {
		std::smatch coincidencia;
		if(std::regex_search(linea_, coincidencia, patron_)){
			archivo_sal << "[Line " << i << "] LOOP: " << coincidencia[1] << std::endl;
		}
		i++;
	}
}