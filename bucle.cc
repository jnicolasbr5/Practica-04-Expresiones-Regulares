// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Descripción Clase Regex:
// Representa un alfabeto que contiene símbolos.
// Verifica si una cadena está formada por los símbolos del alfabeto
// Estructura de datos principal:
// - std::set<char> - almacena símbolos de manera ordenada
// Historial de modificaciones:
// Bug fix 1 - Corregida la llamada de funciones en sobrecargas.
// Bug fix 2 - Añado IsEmpty() para vaciar el alfabeto al añadir uno nuevo.
// Bug fix 3 - ComprobarAlfabetoCadena() verifica que los símbolos de las
//             cadenas existen en el alfabeto

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "bucle.h"

void Statement::BuscarBucles(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i) {
  std::string linea;
	while(std::getline(archivo_ent, linea)) {
		std::smatch coincidencia;
		if(std::regex_search(linea, coincidencia, patron_)){
			archivo_sal << "[Line " << i << "] LOOP: " << coincidencia[1] << std::endl;
		}
		i++;
	}
}