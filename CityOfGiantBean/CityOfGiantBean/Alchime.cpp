#include "Alchime.h"
#include "Joueur.h"

void Alchimie::initAlchimie() {
	fA.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	posrsPNJForge = { AjustResoX * 1139.0f, AjustResoY * 673.0f };
	rsPNJForge.setSize(sf::Vector2f(AjustResoX * 158, AjustResoY * 260));
	rsPNJForge.setPosition(posrsPNJForge);
	rsPNJForge.setFillColor(sf::Color::Cyan);

	posText = { AjustResoX * 150.0f, AjustResoY * 850.0f };
	txPnj.setFont(fA);
	txPnj.setFillColor(sf::Color::Black);
	txPnj.setPosition(posText);

	txDecr.setFont(fA);
	txDecr.setOrigin(txDecr.getGlobalBounds().height / 2, txDecr.getGlobalBounds().width / 2);
	txDecr.setPosition(AjustResoX * 150.0f, AjustResoY * 900.0f);
	txDecr.setFillColor(sf::Color::Red);

	txRetour.setFont(fA);
	txRetour.setOrigin(txRetour.getGlobalBounds().height / 2, txRetour.getGlobalBounds().width / 2);
	txRetour.setPosition(AjustResoX * 150.0f, AjustResoY * 950.0f);
	txRetour.setFillColor(sf::Color::Red);

	txDescForge.setFont(fA);
	txDescForge.setOrigin(txDescForge.getGlobalBounds().height / 2, txDescForge.getGlobalBounds().width / 2);
	txDescForge.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	txDescForge.setFillColor(sf::Color::Black);

	rInv.setFillColor(sf::Color(0, 255, 0, 100));
	rInv.setSize(sf::Vector2f(AjustResoX * 72.0f, AjustResoY * 73.0f));

	boiteDiscussion::initBoiteDiscussion();

	stPnj = ("Bonjour, bienvenu a la forge.");
	stRep = ("Bonjour, montrez moi ce que je peux forger.");
	stPnjEn = ("Hello, welcome to the forge.");
	stRepEn = ("Hello, show me what I can forge.");


	tools::ChoixLangue(tools::GetTrad(), txDecr, stRep, stRepEn);
	tools::ChoixLangue(tools::GetTrad(), txRetour, "Au revoir", "See you later");
	tools::ChoixLangue(tools::GetTrad(), txPnj, stPnj, stPnj);
	timerState = 0.0f;
}

void Alchimie::updateAlchimie(myWindow& _window, ModeGame& _mode, Joueur& _perso1) {
	timerState += tools::GetTimeDelta();
	if (_mode == ModeGame::LIBRE) {
		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJForge, sf::Vector2f(AjustResoX * 158, AjustResoY * 260)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || bPnj == true) {
			bPnj = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				OuiNonAl = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				OuiNonAl = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (OuiNonAl == 1) {
					_mode = ModeGame::FORGE;
					timerState = 0.0f;
					return;
				}
				if (OuiNonAl == 2) {
					timerState = 0.0f;
					bPnj = false;
				}
			}
		}
	}
	if (_mode == ModeGame::FORGE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && timerState > 0.3f) {
			_mode = ModeGame::LIBRE;
			timerState = 0.0f;
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && timerState > 0.3f && invDepLateral < 4) {
			invDepVertical = 1;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && timerState > 0.3f) {
			invDepVertical = 2;
			timerState = 0.0f;
		}
		switch (invDepVertical)
		{
		case 1:
			iFObjet = 1;
			iFMonstre = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 3 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		case 2:
			iFObjet = 0;
			iFMonstre = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 4 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		default:
			break;
		}
		pInvBase = sf::Vector2f(((invDepLateral * 110) + 147), ((invDepVertical * 111) + 35));
		rInv.setPosition(pInvBase);
	}
}

void Alchimie::displayAlchimie(myWindow& _window, ModeGame& _mode, Joueur& _perso1) {
	if (_mode == ModeGame::LIBRE) {
		//_window.Draw(rsPNJForge);
		if (bPnj == true) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			boiteDiscussion::setBoolDiscu(true);

			if (OuiNonAl == 1) {
				txDecr.setCharacterSize(40);
				txRetour.setCharacterSize(30);
			}
			if (OuiNonAl == 2) {
				txDecr.setCharacterSize(30);
				txRetour.setCharacterSize(40);
			}
			_window.Draw(txPnj);
			_window.Draw(txDecr);
			_window.Draw(txRetour);

		}
		else {
			boiteDiscussion::setBoolDiscu(false);
		}
	}
	if (_mode == ModeGame::FORGE) {

		_window.Draw(rInv);
		AffDesc(_perso1);
		tools::ChoixLangue(tools::GetTrad(), txDescForge, "Quantite : " + stQteInv + "\n" + description, "Quantities : " + stQteInv + "\n" + descriptionEn);
		_window.Draw(txDescForge);
	}
}

void Alchimie::AffDesc(Joueur& _perso1) {
	switch (invDepLateral)
	{
	case 1:
		if (iFObjet == 1) {
			stTmp = { " Cuivre : " + _perso1.GetLootCuivre() };
			description = { "Filet : \nFusion Fourrure + cuivre\nFourrure : " + std::to_string(_perso1.GetLootFourrure()) + stTmp };
			stQteInv = std::to_string(_perso1.GetFillet());
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.GetLootFourrure() > 0 && _perso1.GetLootCuivre() > 0) {
					_perso1.SetLootFourrure(_perso1.GetLootFourrure() - 1);
					_perso1.SetLootCuivre(_perso1.GetLootCuivre() - 1);
					_perso1.SetFillet(_perso1.GetFillet() + 1);
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else if (iFMonstre == 1) {
			stTmp = { " Ours : " + std::to_string(_perso1.iCatchOurs) };
			description = { "GobOurs : \nFusion Gobelin + Ours\nGobelin : " + std::to_string(_perso1.iCatchGob) + stTmp };
			stQteInv = std::to_string(_perso1.iCatchGobOurs);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.iCatchOurs > 0 && _perso1.iCatchGob > 0) {
					_perso1.iCatchGob -= 1;
					_perso1.iCatchOurs -= 1;
					_perso1.iCatchGobOurs -= 1;
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else {
			description = { "A venir prochainement" };
			stQteInv = { "" };
		}
		break;
	case 2:
		if (iFObjet == 1) {
			stTmp = { " Fer : " + std::to_string(_perso1.GetLootFer()) };
			description = { "Super Filet : \nFusion Cuire + Fer\nCuire : " + std::to_string(_perso1.GetLootCuire()) + stTmp };
			stQteInv = std::to_string(_perso1.GetSuperFillet());
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.GetLootFer() > 0 && _perso1.GetLootCuire() > 0) {
					_perso1.SetLootCuire(_perso1.GetLootCuire() - 1);
					_perso1.SetLootFer(_perso1.GetLootFer() - 1);
					_perso1.SetSuperFillet(_perso1.GetSuperFillet() + 1);
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else if (iFMonstre == 1) {
			stTmp = { " Loup : " + std::to_string(_perso1.iCatchLoup) };
			description = { "GobLoup : \nFusion Gobelin + Loup\nGobelin : " + std::to_string(_perso1.iCatchGob) + stTmp };
			stQteInv = std::to_string(_perso1.iCatchGobLoup);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.iCatchLoup > 0 && _perso1.iCatchGob > 0) {
					_perso1.iCatchGob -= 1;
					_perso1.iCatchLoup -= 1;
					_perso1.iCatchGobLoup -= 1;
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else {
			description = { "A venir prochainement" };
			stQteInv = { "" };
		}
		break;
	case 3:
		if (iFObjet == 1) {
			stTmp = { " Potion Mana : " + std::to_string(_perso1.SoinManaBuy) };
			description = { "Potion mysterieuse : \nFusion Potion PV + potion Mana\nPotion PV : " + std::to_string(_perso1.SoinPvBuy) + stTmp };
			stQteInv = std::to_string(_perso1.iPotionMy);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.SoinPvBuy > 0 && _perso1.SoinManaBuy > 0) {
					_perso1.SoinPvBuy -= 1;
					_perso1.SoinManaBuy -= 1;
					_perso1.iPotionMy += 1;
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else if (iFMonstre == 1) {
			stTmp = { " Orc : " + std::to_string(_perso1.iCatchOrc) };
			description = { "OursOrc : \nFusion Ours + Orc\nOurs : " + std::to_string(_perso1.iCatchOurs) + stTmp };
			stQteInv = std::to_string(_perso1.iCatchOursOrc);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.iCatchOurs > 0 && _perso1.iCatchOrc > 0) {
					_perso1.iCatchOrc -= 1;
					_perso1.iCatchOurs -= 1;
					_perso1.iCatchOursOrc -= 1;
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else {
			description = { "A venir prochainement" };
			stQteInv = { "" };
		}
		break;
	case 4:
		if (iFObjet == 1) {
			description = { "A venir prochainement" };
			stQteInv = { "" };
		}
		else if (iFMonstre == 1) {
			stTmp = { " Orc : " + std::to_string(_perso1.iCatchOrc) };
			description = { "Lourc : \nFusion Loup + Orc\nLoup : " + std::to_string(_perso1.iCatchLoup) + stTmp };
			stQteInv = std::to_string(_perso1.iCatchLouRoc);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				if (_perso1.iCatchLoup > 0 && _perso1.iCatchGob > 0) {
					_perso1.iCatchGob -= 1;
					_perso1.iCatchLoup -= 1;
					_perso1.iCatchLouRoc -= 1;
					timerState = 0.0f;
				}
				timerState = 0.0f;
			}
		}
		else {
			description = { "A venir prochainement" };
			stQteInv = { "" };
		}
		break;
	}
}
