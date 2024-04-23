#include <iostream>
#include <string>

using namespace std;

class Pregunta{
    private:
        string enunciado;
        string respuesta;
    public:
        Pregunta();
        Pregunta(string enunciado, string respuesta);
        string getEnunciado();
        string getRespuesta();
        void setEnunciado(string enunciado);
        void setRespuesta(string respuesta);
        void toString();
};
