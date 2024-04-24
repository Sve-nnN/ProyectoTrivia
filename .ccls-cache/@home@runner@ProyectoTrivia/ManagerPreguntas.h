#include "Pregunta.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ManagerPreguntas {
private:
  vector<Pregunta *> preguntas;

public:
  ManagerPreguntas();
  void addPregunta(Pregunta *pregunta);
  string getPregunta(int i);
  string getRandomPregunta();
  int getNumPreguntas();
  void toString();
};