#include "Game.h"
#include "Map.h"
#include "Joueur.h"
#include "Taverne.h"
#include "Fontaine.h"
#include "Boutique.h"
#include "Alchime.h"
#include "Safarie.h"
#include "MenuInGame.h"
#include "Hotel.h"
#include "Aventure.h"
#include "Tuto.h"

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
Aventure aventure;
MenuGame menuGame;
Safarie safarie;
Consos conso;
Hotel hotel;
//Villagois villagois = Villagois();

extern float timerAff;

void Game::init(myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);

	initTuto();
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
	hotel.initHotel();
	aventure.initEnnemi();

	SonG_wooshBuff.loadFromFile("..\\Ressources\\Audio\\Whoosh3.wav");
	SonG_woosh.setBuffer(SonG_wooshBuff);
	SonG_AktPBuff.loadFromFile("..\\Ressources\\Audio\\AtkP.wav");
	SonG_AktP.setBuffer(SonG_AktPBuff);
	SonG_AtkMBuff.loadFromFile("..\\Ressources\\Audio\\AtkM.wav");
	SonG_AtkM.setBuffer(SonG_AtkMBuff);
	SonG_PVpBuff.loadFromFile("..\\Ressources\\Audio\\pvP.wav");
	SonG_PVp.setBuffer(SonG_PVpBuff);
	SonG_PVmBuff.loadFromFile("..\\Ressources\\Audio\\pvM.wav");
	SonG_PVm.setBuffer(SonG_PVmBuff);
	SonG_LvlUpBuff.loadFromFile("..\\Ressources\\Audio\\LvlUp.wav");
	SonG_LvlUp.setBuffer(SonG_LvlUpBuff);

	tools::SetFirstInM(false);
	musiqueGame.openFromFile("..\\Ressources\\Audio\\Shop.ogg");
	musiqueGame.setLoop(true);
	musiqueCombatAv.openFromFile("..\\Ressources\\Audio\\CombatAv.ogg");
	musiqueCombatAv.setLoop(true);
	musiqueCombatSa.openFromFile("..\\Ressources\\Audio\\CombatSa.ogg");
	musiqueCombatSa.setLoop(true);
	musiqueShop.openFromFile("..\\Ressources\\Audio\\Libre.ogg");
	musiqueShop.setLoop(true);
}

void Game::update(myWindow& _window) {

	if (tools::GetFirstInM() == false) {
		if (mapGame == MapGame::SHOP) {
			musiqueGame.stop();
			musiqueCombatAv.stop();
			musiqueCombatSa.stop();
			musiqueShop.play();
			tools::SetFirstInM(true);
		}
		if (mapGame == MapGame::RDC || mapGame == MapGame::MONTE) {
			musiqueGame.play();
			musiqueCombatAv.stop();
			musiqueCombatSa.stop();
			musiqueShop.stop();
			tools::SetFirstInM(true);
		}
		if (mapGame == MapGame::AVENTURE) {
			musiqueGame.stop();
			musiqueCombatAv.play();
			musiqueCombatSa.stop();
			musiqueShop.stop();
			tools::SetFirstInM(true);
		}
		if (mapGame == MapGame::SAFARIE) {
			musiqueGame.stop();
			musiqueCombatAv.stop();
			musiqueCombatSa.play();
			musiqueShop.stop();
			tools::SetFirstInM(true);
		}

	}

	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();
	updateCarte(_window, mapGame, shopGame, aventureGame, modeGame, persoMain.persoPosition);
	menuGame.UpdateMenuGame(_window, modeGame, persoMain, safarie);
	updateTuto(mapGame, shopGame, aventureGame, modeGame);
	if (modeGame == ModeGame::LIBRE && (save::getTutoNb() >= 4 || save::getTuto() == false)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::MENU;
			fClickMenu = 0.0f;
			timerAff = 0.0f;
		}
	}
	if (modeGame == ModeGame::MENU) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::LIBRE;
			fClickMenu = 0.0f;
			timerAff = 0.0f;
		}
	}
	if (modeGame == ModeGame::QUETE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::LIBRE;
			fClickMenu = 0.0f;
			timerAff = 0.0f;
		}
	}
	if (modeGame == ModeGame::SKILL_TREE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fClickMenu > 0.3f) {
			modeGame = ModeGame::LIBRE;
			fClickMenu = 0.0f;
			timerAff = 0.0f;
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
		aventure.UpdateAventure(persoMain, modeGame, conso, aventureGame);
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
			hotel.update(persoMain, modeGame, safarie, aventure);
		}
	}

	music::SetVolume(musiqueGame);
	music::SetVolume(musiqueShop);
	music::SetVolume(musiqueCombatAv);
	music::SetVolume(musiqueCombatSa);
	music::SetSon(SonG_AktP);
	music::SetSon(SonG_AtkM);
	music::SetSon(SonG_PVm);
	music::SetSon(SonG_PVp);
	music::SetSon(SonG_LvlUp);
}

void Game::updateEvent(myWindow& _window) {
}

void Game::draw(myWindow& _window) {
	displayCarte(_window, mapGame, shopGame, aventureGame, modeGame);
	if (mapGame == MapGame::RDC) {
		//ShowCursor(true);
	}
	if (mapGame == MapGame::SAFARIE) {
		//ShowCursor(false);
		safarie.drawSafari(_window, modeGame, persoMain);
	}
	if (mapGame == MapGame::MONTE) {
		//ShowCursor(true);

	}
	if (mapGame == MapGame::AVENTURE) {
		//ShowCursor(false);
		persoMain.displayPerso(_window, modeGame);
		aventure.displayAventure(_window, modeGame, persoMain, aventureGame);
	}
	if (mapGame == MapGame::SHOP) {
		//ShowCursor(false);
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
			hotel.displayHotel(_window, modeGame, persoMain);
		}
	}
	if (modeGame == ModeGame::LIBRE) {
		if (save::getTuto() == true) {
			drawTuto(_window);
		}
	}
	menuGame.DisplayMenuGame(_window, modeGame, persoMain);
}

void Game::destroy() {
}
