#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ManagerPreguntas{
    private:
        vector<string> preguntas;
        vector<string> respuestas;
    public:
        ManagerPreguntas();
        void addPregunta(string pregunta);
        void addRespuesta(string respuesta);
        string getPregunta(int i);
        string getRespuesta(int i);
        int getNumPreguntas();
        int getNumRespuestas(); 
        void toString();
}