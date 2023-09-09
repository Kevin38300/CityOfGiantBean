#include "Game.h"
#include "Map.h"
#include "Joueur.h"
#include "Taverne.h"
#include "Fontaine.h"
#include "Boutique.h"
#include "Alchime.h"
#include "Safarie.h"
#include "MenuInGame.h"
//#include "Villagois.h"

Game::Game() {
}

Game::Game(MapGame _mapGame, ModeGame _modeGame, AventureGame _aventureGame, ShopGame _shopGame, myWindow& _window) {
	mapGame = _mapGame;
	modeGame = _modeGame;
	shopGame = _shopGame;
	aventureGame = _aventureGame;
}

Joueur persoMain;
Alchimie alchimie;
MenuGame menuGame;
Safarie safarie;
Consos conso;
//Villagois villagois = Villagois();

void Game::init(myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);

	initCarte();
	persos.push_back(&persoMain);
	persoMain.initPerso();
	//persoMain.SetJob(villagois);
	initFontaine();
	initTaverne();
	initBoutique();
	alchimie.initAlchimie();
	menuGame.InitMenuGame();
	safarie.initSafari();
}

void Game::update(myWindow& _window) {

	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();
	updateCarte(_window, mapGame, shopGame, aventureGame, modeGame, persoMain.persoPosition);
	menuGame.UpdateMenuGame(_window, modeGame, persoMain, safarie);
	if (modeGame == ModeGame::LIBRE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::MENU;
			fClickMenu = 0.0f;
		}
	}
	if (modeGame == ModeGame::MENU) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::LIBRE;
			fClickMenu = 0.0f;
		}
	}
	if (mapGame == MapGame::RDC) {

	}
	if (mapGame == MapGame::SAFARIE) {
		persoMain.updatePerso(_window, modeGame);
		safarie.updateSafari(persoMain, modeGame, conso);
	}
	if (mapGame == MapGame::MONTE) {

	}
	if (mapGame == MapGame::AVENTURE) {
		persoMain.updatePerso(_window, modeGame);

	}
	if (mapGame == MapGame::SHOP) {
		persoMain.updatePerso(_window, modeGame);
		if (shopGame == ShopGame::TAVERNE) {
			updateTaverne(_window, persoMain);
		}
		if (shopGame == ShopGame::ALCHIMIE) {
			alchimie.updateAlchimie(_window, modeGame, persoMain);
		}
		if (shopGame == ShopGame::BOUTIQUE) {
			updateBoutique(_window, persoMain);
		}
		if (shopGame == ShopGame::FONTAINE) {
			updateFontaine(_window, persoMain);
		}
		if (shopGame == ShopGame::HOTEL) {
		}
	}
}

void Game::updateEvent(myWindow& _window) {
}

void Game::draw(myWindow& _window) {
	displayCarte(_window, mapGame, shopGame, aventureGame, modeGame);
	if (mapGame == MapGame::RDC) {
	}
	if (mapGame == MapGame::SAFARIE) {
		safarie.drawSafari(_window, modeGame, persoMain);
	}
	if (mapGame == MapGame::MONTE) {

	}
	if (mapGame == MapGame::AVENTURE) {
		persoMain.displayPerso(_window, modeGame);

	}
	if (mapGame == MapGame::SHOP) {
		persoMain.displayPerso(_window, modeGame);

		if (shopGame == ShopGame::TAVERNE) {
			displayTaverne(_window);
		}
		if (shopGame == ShopGame::ALCHIMIE) {
			alchimie.displayAlchimie(_window, modeGame, persoMain);
		}
		if (shopGame == ShopGame::BOUTIQUE) {
			displayBoutique(_window, persoMain);
		}
		if (shopGame == ShopGame::FONTAINE) {
			displayFontaine(_window);
		}
		if (shopGame == ShopGame::HOTEL) {
		}
	}
	menuGame.DisplayMenuGame(_window, modeGame, persoMain);
}

void Game::destroy() {
}
