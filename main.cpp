#include <iostream>
//Dependencia para usar JSONS
#include <nlohmann/json.hpp>

#include "ManagerPreguntas.h"
using namespace std;

nlohmann::json preguntasJson = nlohmann::json::parse("preguntas.json");

int main() {
	ManagerPreguntas managerPreguntas= new ManagerPreguntas();
	//Tomamos las preguntas del JSON y las guardamos en el vector de preguntas
	for (int i = 0; i < preguntasJson.preguntas.size(); i++) {
		managerPreguntas.addPregunta(preguntasJson.preguntas[i].pregunta);
	}
	//mostramos las preguntas
	managerPreguntas.mostrarPreguntas();
}
