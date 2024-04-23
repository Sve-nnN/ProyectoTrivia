#include "ManagerPreguntas.h"

ManagerPreguntas(){
    this->numPreguntas = 0;
    this->numRespuestas = 0;
}
void addPregunta(string pregunta){
    this->preguntas.push_back(pregunta);
    this->numPreguntas++;
}
void addRespuesta(string respuesta){
    this->respuestas.push_back(respuesta);
    this->numRespuestas++;
}
string getPregunta(int i){
    return this->preguntas[i];
}
string getRespuesta(int i){
    return this->respuestas[i];
}
int getNumPreguntas(){
    return this->numPreguntas;
}
int getNumRespuestas(){
    return this->numRespuestas;
}
void toString(){
    for(int i = 0; i < this->numPreguntas; i++){
        cout << this->preguntas[i] << endl;
    }
    for(int i = 0; i < this->numRespuestas; i++){
        cout << this->respuestas[i] << endl;
    }
}