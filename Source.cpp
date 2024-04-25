#include <fstream>
#include <iostream>
#include <string>

// incluimos el archivo para usar jsons
#include "ManagerQuestion.h"
#include "json.hpp"
#include "Question.h"
#include "Player.h"
#include "Entity.h"
#include "QuestionData.h"
using json = nlohmann::json;

using namespace std;
using namespace System;

int main() {
	//generar un numero aleatorio
	srand(time(NULL));
	Player* player = new Player(6, 8, 2, 3, 3, 5);

	int aux;
	ManagerQuestion managerPreguntas = ManagerQuestion();
	try {
		// Asegúrate de que los datos JSON estén disponibles y sean válidos
		if (!Data.empty()) {
			json PreguntasJson{ json::parse(Data) };
			// Iterate over the "preguntas" array

			for (const auto& pregunta : PreguntasJson["preguntas"]) {
				// agregamos cada pregunta y respuesta a la clase de pregunta
				string preguntaString = pregunta["pregunta"].get<string>();
				string inco1String = pregunta["incorrecta1"].get<string>();
				string inco2String = pregunta["incorrecta2"].get<string>();

				string inco3String = pregunta["incorrecta3"].get<string>();
				string respuestaString = pregunta["respuesta"].get<string>();



				Question* newQuestion = new Question(preguntaString, respuestaString, inco1String, inco2String, inco3String);
				managerPreguntas.addPregunta(newQuestion);
			}
			// managerPreguntas.toString();
		}
		else {
			cerr << "No data available for parsing" << endl;
			return 1;
		}

	}
	catch (const nlohmann::json::parse_error& e) {
		cerr << "Parsing error: " << e.what() << endl;
		return 1;
	}

	int randNum =rand() % managerPreguntas.getNumPreguntas();



cout << managerPreguntas.getRandomPregunta(randNum, aux) << "\n";
cout << "Cual es la respuesta?\n";

player->draw();

cout << managerPreguntas.getInco1(randNum) << "\n";
cout << managerPreguntas.getInco2(randNum) << "\n";
cout << managerPreguntas.getInco3(randNum) << "\n";
cout << managerPreguntas.getRespuesta(randNum) << "\n";
system("pause");
}
