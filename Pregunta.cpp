Pregunta(){
    enunciado = "";
    respuesta = "";
}
Pregunta(string enunciado, string respuesta){
    this->enunciado = enunciado;
    this->respuesta = respuesta;
}
string getEnunciado(){
    return enunciado;
}
string getRespuesta(){
    return respuesta;
    }
void setEnunciado(string enunciado){
    this->enunciado = enunciado;
    }
void setRespuesta(string respuesta){
    this->respuesta = respuesta;}
void toString(){
    cout << "Enunciado: " << enunciado << endl;
    cout << "Respuesta: " << respuesta << endl;}