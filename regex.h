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
#include <regex>
#include <string>
#include <vector>

struct Variable {
	int linea;
	std::string tipo;
	int valor;
}; 

struct Statement {
	int linea;
	std::string tipo;
};

class Regex {
	private:
		static const std::regex variable_patron_;
		static const std::regex bucle_patron_;
		static const std::regex main_patron_;
		std::string linea_;
		std::smatch coincidencia_;
		bool main_ = false;
		std::vector<Variable> variables_;
		std::vector<Statement> statements_;

	public:
		bool IsMain() {return main_;}
	//	void BuscarVariables(std::ifstream& archivo_ent, std::ofstream& archivo_sal,
											//	int i = 1);
		void BuscarBucles(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i);
	//	void BuscarComentarios(std::ifstream& archivo_ent, std::ofstream& archivo_sal, int i = 1);
};