#include "Pregunta.h"

#include <iostream>

using namespace std;

Pregunta::Pregunta(string enunciado, string respuesta){
    this->enunciado = enunciado;
    this->respuesta = respuesta;
}
string Pregunta::getEnunciado(){
    return enunciado;
}
string Pregunta::getRespuesta(){
    return respuesta;
    }
void Pregunta::setEnunciado(string enunciado){
    this->enunciado = enunciado;
    }
void Pregunta::setRespuesta(string respuesta){
    this->respuesta = respuesta;}
void Pregunta::toString(){
    cout << "Enunciado: " << enunciado << endl;
    cout << "Respuesta: " << respuesta << endl;}