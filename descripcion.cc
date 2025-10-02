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
  std::string linea;
	bool descripcion_detectada = false;
	while(std::getline(archivo_ent, linea)) {
		std::smatch coincidencia;
		if (std::regex_search(linea, coincidencia, patron_)){
			if (!descripcion_detectada) {	
				est.PushDescripcion(coincidencia[0].str());
				if (coincidencia[1].matched) {
					inicio = i;
				}	else if (coincidencia[3].matched) {
					final = i;
					est.SetLongitudDescripcion(inicio, final);
					descripcion_detectada = true;
				}
			} else {
				if (coincidencia[1].matched) {
					inicio = i;
				}	else if (coincidencia[3].matched) {
					final = i;
					est.PushLongitudComentarios(inicio, final);
				}
			}
		}	
		i++;
	}	
}
