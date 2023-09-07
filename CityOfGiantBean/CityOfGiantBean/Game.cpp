#include "Game.h"
#include "Map.h"

Game::Game() {
}

Game::Game(MapGame _mapGame, ModeGame _modeGame, AventureGame _aventureGame, ShopGame _shopGame, myWindow& _window) {
	mapGame = _mapGame;
	modeGame = _modeGame;
	shopGame = _shopGame;
	aventureGame = _aventureGame;
}

void Game::init(myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);


	initCarte();

	if (mapGame == MapGame::RDC) {

	}
	if (mapGame == MapGame::SAFARIE) {

	}
	if (mapGame == MapGame::MONTE) {

	}
	if (mapGame == MapGame::AVENTURE) {

	}
	if (mapGame == MapGame::SHOP) {

	}
}

void Game::update(myWindow& _window) {

	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();
	updateCarte(_window, mapGame, shopGame, aventureGame, modeGame, posSouris);
	if (mapGame == MapGame::RDC) {

	}
	if (mapGame == MapGame::SAFARIE) {

	}
	if (mapGame == MapGame::MONTE) {

	}
	if (mapGame == MapGame::AVENTURE) {

	}
	if (mapGame == MapGame::SHOP) {

	}
}

void Game::updateEvent(myWindow& _window) {
}

void Game::draw(myWindow& _window) {
	displayCarte(_window, mapGame, shopGame, aventureGame, modeGame);
	if (mapGame == MapGame::RDC) {
	}
	if (mapGame == MapGame::SAFARIE) {

	}
	if (mapGame == MapGame::MONTE) {

	}
	if (mapGame == MapGame::AVENTURE) {

	}
	if (mapGame == MapGame::SHOP) {

	}
}

void Game::destroy() {
}
