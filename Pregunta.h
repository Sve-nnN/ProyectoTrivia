#include <iostream>
#include <String>

class Pregunta{
private:
    string enunciado, respuesta;
public:
    Pregunta(string enunciado, string respuesta);
    string getEnunciado();
    string getRespuesta();
    void setEnunciado(string enunciado);
    void setRespuesta(string respuesta);
    void toString();
};