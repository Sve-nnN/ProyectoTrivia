#include <fstream>
#include <iostream>
#include <string>

// incluimos el archivo para usar jsons
#include "ManagerQuestion.h"
#include "json.hpp"
#include "Question.h"
#include "QuestionData.h"
using json = nlohmann::json;

using namespace std;

int main() {
    //generar un numero aleatorio
    srand(time(NULL));
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
                string respuestaString = pregunta["respuesta"].get<string>();
                Question* newQuestion = new Question(preguntaString, respuestaString);
                managerPreguntas.addPregunta(newQuestion);
            }
            int randNum= rand() % managerPreguntas.getNumPreguntas();
            cout<<managerPreguntas.getRandomPregunta(randNum, aux)<<"\n";
            cout<<"Cual es la respuesta?\n";
            cout<<managerPreguntas.getRespuesta(rand() % managerPreguntas.getNumPreguntas()) << "\n";
            cout << managerPreguntas.getRespuesta(rand() % managerPreguntas.getNumPreguntas()) << "\n";
            cout << managerPreguntas.getRespuesta(rand() % managerPreguntas.getNumPreguntas()) << "\n";
            cout << managerPreguntas.getRespuesta(randNum) << "\n";




            // managerPreguntas.toString();
            system("pause");
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
}
