#include "Game.h"

Game::Game() {
}

Game::Game(StateGame _stateGame, myWindow& _window) {
	_stateGame = stateGame;
}

void Game::init(myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);

	ttMenu.loadFromFile("../Ressources/Textures/MENU/MenuCeleste.jpg");
	spMenu.setTexture(ttMenu);

	if (stateGame == StateGame::NEW) {

	}
	if (stateGame == StateGame::CONTINU) {

	}
}

void Game::update(myWindow& _window) {

	if (stateGame == StateGame::NEW) {

	}
	if (stateGame == StateGame::CONTINU) {

	}
}

void Game::updateEvent(myWindow& _window) {
}

void Game::draw(myWindow& _window) {
	_window.Draw(spMenu);
	_window.Draw(txMTitre);
	if (stateGame == StateGame::NEW) {
	}
	if (stateGame == StateGame::CONTINU) {

	}
}

void Game::destroy() {
}
