#pragma once
#include <iostream>
#include <string>

using namespace std;

class Question {
private:
	string enunciado, respuesta, incorrecta1, incorrecta2, incorrecta3;

public:
	Question(string enunciado, string respuesta, string incorrecta1, string incorrecta2, string incorrecta3);
	string getEnunciado();
	string getRespuesta();
	string getIncorrecta1();
	string getIncorrecta2();
	string getIncorrecta3();
	void setEnunciado(string enunciado);
	void setRespuesta(string respuesta);
	void toString();
};