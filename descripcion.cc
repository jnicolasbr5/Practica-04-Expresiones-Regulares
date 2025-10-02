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

#include "descripcion.h"

void Description::BuscarDescripcion(std::ifstream& archivo_ent, Estructura& est, int i) {
	int inicio, final;
	bool comprobar_descripcion = false;
  std::string linea;
	while(std::getline(archivo_ent, linea)) {
		std::smatch coincidencia;
		if(std::regex_search(linea, coincidencia, patron_)){
			comprobar_descripcion = true;
			est.PushDescripcion(coincidencia[0].str());
			if (coincidencia[1].matched) {
				inicio = i;
			}	else if (coincidencia[3].matched) {
				final = i;
			}
		}	
		i++;
	}
	if (comprobar_descripcion) est.SetLongitudDescripcion(inicio, final);
}