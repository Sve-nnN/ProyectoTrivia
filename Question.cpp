#include "Question.h"

#include <iostream>

using namespace std;

Question::Question(string enunciado, string respuesta, string incorrecta1, string incorrecta2, string incorrecta3) {
    this->enunciado = enunciado;
    this->respuesta = respuesta;
    this->incorrecta1 = incorrecta1;
    this->incorrecta2 = incorrecta2;
    this->incorrecta3 = incorrecta3;
}
string Question::getEnunciado() {
    return enunciado;
}
string Question::getRespuesta() {
    return respuesta;
}
string Question::getIncorrecta1() {
    return incorrecta1;
}
string Question::getIncorrecta2() {
    return incorrecta2;
}
string Question::getIncorrecta3() {
    return incorrecta3;
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