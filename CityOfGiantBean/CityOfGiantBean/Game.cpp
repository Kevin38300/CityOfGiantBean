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
#include "Save.h"
#include "Assassin.h"
#include "Clerc.h"
#include "Guerrier.h"
#include "Magicien.h"

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

	initCarte();
	persos.push_back(&persoMain);
	persoMain.initPerso();
	//persoMain.SetJob(villagois);
	initFontaine();
	initTaverne(persoMain);
	initBoutique(persoMain);
	alchimie.initAlchimie();
	menuGame.InitMenuGame();
	safarie.initSafari();
	hotel.initHotel();
	aventure.initEnnemi();

	if (save::GetNew() == true) {
		initTuto();
	}
	else if (save::GetNew() == false) {

		aventure.iZoneAv = save::getNivAventure();
		safarie.iZonzSafari = save::getNivSafarie();
	}


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
	////////////////////////// Play music
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
	///////////////////////// Changement de mode
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
	///////////////////////////Update
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
	/////////Sauvegarde avant que la fentre se ferme
	if (_window.GetEvent().type == sf::Event::Closed)
	{
		initSave();
		Sauvegarde::SaveGame(save::getpseudo1(), save::getSexe(), save::getMap(), save::getAventure(), save::getShop(), save::getMode(), save::getClasse(), save::getElement(), save::getNiveau(), save::getNbEpee(), save::getNbLance(), save::getNbBague(), save::getNbLourd(), save::getNbLeger(),
			save::getNbBouclier(), save::getNbPotionPv(), save::getNbPotionMana(), save::getNbBombe(), save::getNbPotionMy(), save::getArmeEquipe(), save::getArmureEquipe(), save::getSkill1(), save::getSkill2(), save::getSkill3(), save::getSkill4(), save::getXp(), save::getSkillpoint(),
			save::getCatchGob(), save::getCatchLoup(), save::getCatchOurs(), save::getCatchOrc(), save::getCatchGobOurs(), save::getCatchGobLoup(), save::getCatchOursOrc(), save::getCatchLoupRoc(), save::getNbMonstreBattu(), save::getNbEnnemiBattu(), save::getNbMonstreCatch(), save::getNbGob(),
			save::getNbLoup(), save::getNbOurs(), save::getNbOrc(), save::getNbPersoBattu(), save::getNbMag(), save::getNbGuer(), save::getNbAss(), save::getNbClerc(), save::getChgElement(), save::getChgClass(), save::getIAchat(), save::getIFabrique(), save::getIBossAv(), save::getNivAventure(),
			save::getNivSafarie(), save::getcuivre(), save::getcuire(), save::getfer(), save::getFourrure(), save::getfillet(), save::getsuperfillet(), save::getArgent());
	}

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

void Game::initSave() {
	/////////////////// Save des donnes en int avant Sauvegarde dans fichier
	if (mapGame == MapGame::RDC)
		save::setMap(1);
	if (mapGame == MapGame::SAFARIE)
		save::setMap(2);
	if (mapGame == MapGame::MONTE)
		save::setMap(3);
	if (mapGame == MapGame::AVENTURE)
		save::setMap(4);
	if (mapGame == MapGame::SHOP)
		save::setMap(5);

	if (aventureGame == AventureGame::ZONE_MAGE)
		save::setAventure(1);
	if (aventureGame == AventureGame::ZONE_GUERRIER)
		save::setAventure(2);
	if (aventureGame == AventureGame::ZONE_ASSASSIN)
		save::setAventure(3);
	if (aventureGame == AventureGame::ZONE_CLERC)
		save::setAventure(4);
	if (aventureGame == AventureGame::AVENTURE)
		save::setAventure(5);
	if (aventureGame == AventureGame::NONE)
		save::setAventure(6);

	if (shopGame == ShopGame::HOTEL)
		save::setShop(1);
	if (shopGame == ShopGame::BOUTIQUE)
		save::setShop(2);
	if (shopGame == ShopGame::ALCHIMIE)
		save::setShop(3);
	if (shopGame == ShopGame::FONTAINE)
		save::setShop(4);
	if (shopGame == ShopGame::TAVERNE)
		save::setShop(5);
	if (shopGame == ShopGame::NONE)
		save::setShop(6);

	if (modeGame == ModeGame::LIBRE)
		save::setMode(1);
	if (modeGame == ModeGame::AVE)
		save::setMode(2);
	if (modeGame == ModeGame::LOOT)
		save::setMode(3);
	if (modeGame == ModeGame::SKILL_TREE)
		save::setMode(4);
	if (modeGame == ModeGame::QUETE)
		save::setMode(5);
	if (modeGame == ModeGame::FORGE)
		save::setMode(6);
	if (modeGame == ModeGame::CHASSE)
		save::setMode(7);
	if (modeGame == ModeGame::DUEL)
		save::setMode(8);
	if (modeGame == ModeGame::MENU)
		save::setMode(9);
	if (modeGame == ModeGame::TUTO)
		save::setMode(10);

	save::setNiveau(persoMain.GetNiveau());
	save::setNbEpee(persoMain.EpeeBuy);
	save::setNbLance(persoMain.LanceBuy);
	save::setNbBague(persoMain.BatonBuy);
	save::setNbLourd(persoMain.LourdBuy);
	save::setNbLeger(persoMain.LegerBuy);
	save::setNbBouclier(persoMain.BouclierBuy);
	save::setNbPotionPv(persoMain.SoinPvBuy);
	save::setNbPotionMana(persoMain.SoinManaBuy);
	save::setNbBombe(persoMain.BombeBuy);
	save::setNbPotionMy(persoMain.iPotionMy);

	save::setXp(persoMain.exp);
	save::setSkillpoint(persoMain.GetSkillPoint());

	save::setCatchGob(persoMain.iCatchGob);
	save::setCatchLoup(persoMain.iCatchLoup);
	save::setCatchOurs(persoMain.iCatchOurs);
	save::setCatchOrc(persoMain.iCatchOrc);
	save::setCatchGobOurs(persoMain.iCatchGobOurs);
	save::setCatchGobLoup(persoMain.iCatchGobLoup);
	save::setCatchOursOrc(persoMain.iCatchOursOrc);
	save::setCatchLoupRoc(persoMain.iCatchLouRoc);

	save::setNbMonstreBattu(persoMain.NbMonstreBattu);
	save::setNbEnnemiBattu(persoMain.NbEnnemiBattu);
	save::setNbMonstreCatch(persoMain.NbMonstreCapture);

	save::setNbGob(persoMain.NbGob);
	save::setNbLoup(persoMain.NbLoup);
	save::setNbOurs(persoMain.NbOurs);
	save::setNbOrc(persoMain.NbOrc);

	save::setNbPersoBattu(persoMain.NbPersoBattu);

	save::setNbMag(persoMain.NbMag);
	save::setNbGuer(persoMain.NbGuer);
	save::setNbAss(persoMain.NbAss);
	save::setNbClerc(persoMain.NbClerc);

	save::setChgElement(persoMain.iChgElem);
	save::setChgClass(persoMain.iChgClasse);

	save::setIAchat(persoMain.iAchat);
	save::setIFabrique(persoMain.iFabrique);
	save::setIBossAv(persoMain.iBossAv);
	save::setNivAventure(aventure.iZoneAv);
	save::setNivSafarie(safarie.iZonzSafari);

	save::setcuivre(persoMain.GetLootCuivre());
	save::setcuire(persoMain.GetLootCuire());
	save::setfer(persoMain.GetLootFer());
	save::setFourrure(persoMain.GetLootFourrure());

	save::setfillet(persoMain.GetFillet());
	save::setsuperfillet(persoMain.GetSuperFillet());

	save::setArgent(persoMain.GetTotArgent());
}
