// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 07/10/2025
// Archivo p04_reg.cc: programa cliente.
// Función main del proyecto:
// Usa las clases Statement, Comment, Description, Main y Variable
// Que contienen expresiones regulares y detectan coincidencias en el código de entrada
// Para almacenarlas en la clase Estructura y posteriormente mostrar
// La estructura general del código en un archivo de salida
// Referencias:
// Regex -> https://learn.microsoft.com/es-es/cpp/standard-library/regex-functions?view=msvc-170
// Smatch -> https://www.geeksforgeeks.org/cpp/smatch-regex-regular-expressions-in-c/
// Struct -> https://www.w3schools.com/cpp/cpp_structs.asp
// Historial de revisiones:
// 01/10/2025 - Primera versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia2
// 02/09/2025 - Segunda versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia3


#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "bucle.h"
#include "comment.h"
#include "descripcion.h"
#include "estructura.h"
#include "main.h"
#include "variable.h"

void MostrarError() {
	std::cerr << "Error de parámetros" << std::endl;
	std::cerr << "Modo de uso: ./p04.reg codigo.cc archivo_salida.txt" << std::endl;
}

// Reinicia la lectura de un archivo
void ReiniciarArchivo(std::ifstream& archivo_ent) {
	archivo_ent.clear(); // Limpia los errores
	archivo_ent.seekg(0, std::ios::beg); // Vuelve a apuntar al inicio del archivo
}

int main (int argc, char* argv[]) {
	if (argc != 3) {
		MostrarError();
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
	std::string nombre_archivo = argv[1];
	Estructura estructura;
	estructura.SetPrograma(nombre_archivo);
	Description descr;
	descr.BuscarDescripcion(archivo_entrada, estructura);
	ReiniciarArchivo(archivo_entrada);
  Variable var;
	var.BuscarVariables(archivo_entrada, estructura);
	ReiniciarArchivo(archivo_entrada);
	Statement bucle;
	bucle.BuscarBucles(archivo_entrada, estructura);
	ReiniciarArchivo(archivo_entrada);
	Main main;
	main.BuscarMain(archivo_entrada, estructura);
	ReiniciarArchivo(archivo_entrada);
	Comments comentario;
	comentario.BuscarComentarios(archivo_entrada, estructura);
	archivo_salida << estructura << std::endl;
	return 0;
}