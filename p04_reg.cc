// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025

// Archivo cya-P02-strings.cc: programa cliente.
// Función main del proyecto:
// Usa las clases Alfabeto, Cadena y Lenguaje para:
// Leer datos por un archivo de entrada, realizar las operaciones
// deseadas, y escribir los resultados en un archivo de salida.
// Referencias:
// Regex -> https://learn.microsoft.com/es-es/cpp/standard-library/regex-functions?view=msvc-170
// Smatch -> https://www.geeksforgeeks.org/cpp/smatch-regex-regular-expressions-in-c/
// static const regex -> https://stackoverflow.com/questions/51396538/is-it-good-idea-to-make-stdregex-static
// Historial de revisiones:
// Main -> https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes
// 30/09/2025 - Creación (primera versión) del código 
// -> https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia1
// 01/10/2025 - Segunda versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia2
// 02/09/2025 - Tercera versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia3
// ./p02_strings filein.txt fileout.txt codigo_operacion

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "bucle.h"
#include "comment.h"
#include "descripcion.h"
#include "main.h"
#include "variable.h"

//./ p04_code_analyzer code.cc codescheme.txt


// regex_match -> comprueba si la cadena verifica con el patron
// regex_search -> busca si alguna parte coincide
// regex_replace -> devuelve cadena modificada

void MostrarError() {
	std::cerr << "Error" << std::endl;
}

void ReiniciarArchivo(std::ifstream& archivo_ent) {
	archivo_ent.clear();
	archivo_ent.seekg(0, std::ios::beg);
}

int main (int argc, char* argv[]) {
	if (argc != 3) {
		//MostrarError();
		return 1;
  }	
	std::ifstream archivo_entrada(argv[1]);
	if (!archivo_entrada.is_open()) {
		std::cerr << "El archivo de entrada no pudo ser abierto" << std::endl;
		return 1;
	}
	std::ofstream archivo_salida(argv[2]);
	if (!archivo_salida.is_open()) {
		std::cerr << "El archivo de salida no pudo ser abierto" << std::endl;
		return 1;
	}
	Statement bucle;
	archivo_salida << "PROGRAM: " << argv[1] << std::endl;
	Description descr;
	archivo_salida << "DESCRIPTION: " << std::endl;
	descr.BuscarDescripcion(archivo_entrada, archivo_salida);
	ReiniciarArchivo(archivo_entrada);
  Variable var;
	archivo_salida << "\nVARIABLES: " << std::endl;
	var.BuscarVariables(archivo_entrada, archivo_salida);
	ReiniciarArchivo(archivo_entrada);
	archivo_salida << "\nSTATEMENTS: " << std::endl;
	bucle.BuscarBucles(archivo_entrada, archivo_salida);
	ReiniciarArchivo(archivo_entrada);
	Main main;
	archivo_salida << "\nMAIN: " << std::endl;
	main.BuscarMain(archivo_entrada, archivo_salida);
	ReiniciarArchivo(archivo_entrada);
	Comments comentario;
	archivo_salida << "\nCOMMENTS: " << std::endl;
	archivo_salida << "Line [" << descr.GetInicio() << " - " << descr.GetFinal()
								<< "] DESCRIPTION" <<std::endl;
	comentario.BuscarComentarios(archivo_entrada, archivo_salida);
	return 0;
}



