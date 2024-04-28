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
#include "GameService.h"
using json = nlohmann::json;

using namespace std;
using namespace System;

ManagerQuestion agregarPreguntasManager(ManagerQuestion managerPreguntas) {
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
				return managerPreguntas;
			}
			// managerPreguntas.toString();
		}
		else {
			cerr << "No data available for parsing" << endl;
		}

	}
	catch (const nlohmann::json::parse_error& e) {
		cerr << "Parsing error: " << e.what() << endl;
	}
}

/*
Para imprimir una pregunta y respuestas hacemos asi:
	int randNum = rand() % preguntas.getNumPreguntas();


	cout << preguntas.getRandomPregunta(randNum, aux) << "\n";
	cout << "Cual es la respuesta?\n";

	player->draw();

	cout << preguntas.getInco1(randNum) << "\n";
	cout << preguntas.getInco2(randNum) << "\n";
	cout << preguntas.getInco3(randNum) << "\n";
	cout << preguntas.getRespuesta(randNum) << "\n";
*/
int main() {
	Console::SetWindowSize(120, 30);
	Console::CursorVisible = false;
	srand(time(NULL));

	int aux;
	int key;
	ManagerQuestion managerPreguntas = ManagerQuestion();
	//Le asignamos a la variable preguntas todas las funciones que tiene el manager, para asi pasar el codigo a una funcion y no ejecutarlo todo desde el main
	ManagerQuestion preguntas = agregarPreguntasManager(managerPreguntas);

	GameService* gameService = new GameService();
	while (true) {
		//Logica del game service
		gameService->eraseEntities();
		gameService->detectCollisions();
		gameService->addEntities();
		gameService->checkGameResult();

		//logica del movimiento
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			gameService->getPlayer()->move(key);
		}

		_sleep(100);
	}

	delete gameService;
	system("pause");
	return 0;
}
