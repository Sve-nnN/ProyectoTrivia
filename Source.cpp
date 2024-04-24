#include <iostream>
#include <fstream>
#include <string>

//incluimos el archivo para usar jsons
#include "json.hpp"
#include "preguntas.h"
#include "ManagerPreguntas.h"
#include "Pregunta.h"
using json = nlohmann::json;

using namespace std;



int main() {
	ManagerPreguntas managerPreguntas = ManagerPreguntas();
	try {
		json PreguntasJson{ json::parse(Data) };
		// Iterate over the "preguntas" array

		for (const auto& pregunta : PreguntasJson["preguntas"]) {
			//agregamos cada pregunta y respuesta a la clase de pregunta
			string preguntaString = pregunta["pregunta"];
			string respuestaString = pregunta["respuesta"];
			Pregunta* nuevaPregunta = new Pregunta(preguntaString, respuestaString);
		}
		//managerPreguntas.toString();

	}
	catch (const nlohmann::json::parse_error& e) {
		cerr << "Parsing error: " << e.what() << endl;
		return 1;
	}


}
