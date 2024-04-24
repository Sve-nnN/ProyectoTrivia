#pragma once
#include <iostream>
#include <string>

using namespace std;

class Question {
private:
	string enunciado, respuesta;

public:
	Question(string enunciado, string respuesta);
	string getEnunciado();
	string getRespuesta();
	void setEnunciado(string enunciado);
	void setRespuesta(string respuesta);
	void toString();
};