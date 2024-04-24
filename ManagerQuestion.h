#pragma once
#include "Question.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ManagerQuestion {
private:
	int numPreguntas;
	vector<Question*> questions;

public:
	ManagerQuestion();
	void addPregunta(Question* pregunta);
	string getPregunta(int i);
	string getRespuesta(int i);
	string getRandomPregunta();
	string getRandomPregunta(int random,int respuesta);
	int getNumPreguntas();
	void toString();
};