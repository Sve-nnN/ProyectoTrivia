#include "ManagerQuestion.h"
#include "Question.h"
ManagerQuestion::ManagerQuestion() {
    this->numPreguntas = 0;
}
void ManagerQuestion::addPregunta(Question* pregunta) {
    this->questions.push_back(pregunta);
    this->numPreguntas++;
}
string ManagerQuestion::getPregunta(int i) {
    return this->questions[i]->getEnunciado();
}
int ManagerQuestion::getNumPreguntas() {
    return this->numPreguntas;
}
string ManagerQuestion::getInco1(int i) {
    return this->questions[i]->getIncorrecta1();
}
string ManagerQuestion::getInco2(int i) {
    return this->questions[i]->getIncorrecta2();
}
string ManagerQuestion::getInco3(int i) {
    return this->questions[i]->getIncorrecta3();
}
//Se puede usar sin pasarle parametros
string ManagerQuestion::getRandomPregunta() {
    srand(time(0));
    int random = rand() % this->numPreguntas;
    return this->questions[random]->getEnunciado();
}
string ManagerQuestion::getRandomPregunta(int random, int respuesta) {
    srand(time(0));
    respuesta = random;
    return this->questions[random]->getEnunciado();
}
string ManagerQuestion::getRespuesta(int i) {
    //Imprimir la respuesta segun el indice de ka pregunta
    return this->questions[i]->getRespuesta();

}
void ManagerQuestion::toString() {
    for (int i = 0; i < this->numPreguntas; i++) {
        cout << this->questions[i] << endl;
    }
}