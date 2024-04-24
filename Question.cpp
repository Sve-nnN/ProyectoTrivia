#include "Question.h"

#include <iostream>

using namespace std;

Question::Question(string enunciado, string respuesta) {
    this->enunciado = enunciado;
    this->respuesta = respuesta;
}
string Question::getEnunciado() {
    return enunciado;
}
string Question::getRespuesta() {
    return respuesta;
}
void Question::setEnunciado(string enunciado) {
    this->enunciado = enunciado;
}
void Question::setRespuesta(string respuesta) {
    this->respuesta = respuesta;
}
void Question::toString() {
    cout << "Enunciado: " << enunciado << endl;
    cout << "Respuesta: " << respuesta << endl;
}