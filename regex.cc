// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "regex.h"

// regex_match -> comprueba si la cadena verifica con el patron
// regex_search -> busca si alguna parte coincide
// regex_replace -> devuelve cadena modificada


const std::regex Regex::variable_patron_(R"(^(int|double)\s[a-z]+(\d+|\d+\.\d+)?;$)");

const std::regex Regex::bucle_patron_(R"(\s+)?(for|while)\s?\()");

const std::regex Regex::main_patron_(R"(^int\smain\s?\(\)\s{)");

/* 
void Regex::BuscarVariables(std::ifstream& archivo_ent, std::ofstream& archivo_sal,
												int i = 1) {

	}
*/
void Regex::BuscarBucles(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i = 1) {
	while(std::getline(archivo_ent, linea_)) {
		if(std::regex_search(linea_, coincidencia_, bucle_patron_)){
			archivo_sal << "[Line " << i << "]" << "LOOP: " << coincidencia_[2] << std::endl;
		}
		i++;
	}
}

/*
void Regex::BuscarComentarios(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i = 1) {

}
*/
