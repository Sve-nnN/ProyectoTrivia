#include "ManagerPreguntas.h"

ManagerPreguntas::ManagerPreguntas(){
    this->numPreguntas = 0;
}
void ManagerPreguntas::addPregunta(Pregunta pregunta){
    this->preguntas.push_back(pregunta);
    this->numPreguntas++;
}
string ManagerPreguntas::getPregunta(int i){
    return this->preguntas[i];
}
int ManagerPreguntas::getNumPreguntas(){
    return this->numPreguntas;
}
string ManagerPreguntas::getRandomPregunta() {
	srand(time(0));
	int random = rand() % this->numPreguntas;
    respuesta = random;
    return this->preguntas[random];
}   
void ManagerPreguntas::toString(){
    for(int i = 0; i < this->numPreguntas; i++){
        cout << this->preguntas[i] << endl;
    }
}