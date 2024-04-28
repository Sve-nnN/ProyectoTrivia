#include "GameService.h"

GameService::GameService(){
	//int x, int y, int dx, int height, int width, int lives
	player = new Player(10, 10, 1, 3, 3, 3);
	currentLevel = 0;

	//Nivel, enemigos, preguntas, tiempo
	levels.push_back(Level(1, 3, 5, 30)); //Nivel 1


	timeT = time(0);


}

GameService::~GameService(){}

Level* GameService::getCurrentLevelInfo() {
	if (currentLevel >= 0 && currentLevel < levels.size()) {
		return &levels[currentLevel];
	}
	else {
		return nullptr;
	
	}
}

void GameService::addEntities() {
	int enemyCount = 0;
	int questionCount = 0;
	Level* currentLevelInfo = getCurrentLevelInfo();


	for (Entity* entity : entities) {
		if (dynamic_cast<Enemy*>(entity)) {
			enemyCount++;
		}
	}

}



bool GameService::advanceToNextLevel() {
	currentLevel++; // Aumentar el índice del nivel actual

	if (currentLevel < levels.size()) {
		// Si hay más niveles disponibles, el jugador avanzó al siguiente nivel
		return true;
	}
	else {
		// No hay más niveles disponibles, el jugador ha ganado el juego
		return false;
	}
}

void GameService::deleteEntities() {
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}
void GameService::resetGame() {
	// Reiniciar las vidas, tesoros recogidos, y otras variables del juego
	player->setLives(3);
	player->setPreguntasContestadas(0);

	deleteEntities();

	addEntities();
}
void GameService::endGame() {
	Console::ForegroundColor = ConsoleColor::Cyan;
	system("cls");
	Console::SetCursorPosition(42, 12);
	cout << "--HAS GANADO EL JUEGO--";
	Console::SetCursorPosition(41, 14);
	cout << "Presiona una tecla para salir...";
	_getch();

}



void GameService::checkGameResult() {
	if (player->getPreguntasContestadas() == getCurrentLevelInfo()->getRequiredQuestions()) {
		// Se cumplio la meta para avanzar

		//Pantalla de ganaste
		Console::ForegroundColor = ConsoleColor::Green;
		system("cls");
		Console::SetCursorPosition(45, 12);
		cout << "--GANASTE EL NIVEL--";
		Console::SetCursorPosition(41, 14);
		cout << "Presiona una tecla para continuar...";
		_getch();
		system("cls");

		// Continuar o finalizar
		if (advanceToNextLevel()) {
			resetGame();
		}
		else {
			// Si no hay mas niveles se finaliza
			endGame();
		}
	}

	if (player->getLives() == 0) {
		// El jugador ha perdido todas sus vidas

		//Pantalla de perdiste
		Console::ForegroundColor = ConsoleColor::Red;
		system("cls");
		Console::SetCursorPosition(38, 12);
		cout << "--TERMINO EL JUEGO--";
		Console::SetCursorPosition(41, 14);
		cout << "Presiona una tecla para salir...";
		_getch();

	}
}

void GameService::moveEntities() {
	for (Entity* entity : entities) {
		if (dynamic_cast<Enemy*>(entity)) {
			dynamic_cast<Enemy*>(entity)->move();
		}
	}
}
void GameService::eraseEntities() {
	player->erase();

	for (Entity* entity : entities) {
		entity->erase();
	}

}
void GameService::drawEntities() {
	Console::ForegroundColor = ConsoleColor::White;
	//Pintamos las estadisticas
	Console::SetCursorPosition(109, 1);
	cout << "Tiempo: " << clock() / 1000;
	Console::SetCursorPosition(109, 2);
	cout << "Vidas: " << player->getLives();
	Console::SetCursorPosition(109, 3);
	cout << "Tesoros: " << player->getPreguntasContestadas();
	Console::SetCursorPosition(109, 4);
	cout << "Nivel: " << levels[currentLevel].getNumber();

	//Pintamos el player
	player->draw();

	//Pintamos los enemigos
	for (Entity* entity : entities) {
		entity->draw();
	}
}
void GameService::detectCollisions() {

	for (Entity* entity : entities) {
		if (player->getRectangle().IntersectsWith(entity->getRectangle())) {

			Enemy* enemy = dynamic_cast<Enemy*>(entity);

			if (enemy) {
				player->substractLive();

				if (player->getLives() > 0) {
					player->setX(2);
					player->setY(12.0);
				}
				else {
					Console::ForegroundColor = ConsoleColor::DarkRed;
					system("cls");
					//Pantalla de juego terminado
					Console::SetCursorPosition(38, 12);
					cout << "--TERMINO EL JUEGO--";
					Console::SetCursorPosition(41, 14);
					cout << "Presiona una tecla para salir...";
					_getch();
					exit(0); // Sale del juego
				}
			}

		}

	}
}


Player* GameService::getPlayer() {
	return player;
}