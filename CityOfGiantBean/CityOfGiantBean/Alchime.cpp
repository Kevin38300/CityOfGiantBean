//#include "Alchime.h"
//#include "Joueur.h"
//
//void Alchimie::initAlchimie() {
//	fA.loadFromFile("../Ressources/Fonts/Typewriter.ttf");
//
//	posrsPNJForge = { 785,565 };
//	rsPNJForge.setSize(sf::Vector2f(70, 45));
//	rsPNJForge.setPosition(posrsPNJForge);
//	rsPNJForge.setFillColor(sf::Color::Cyan);
//
//	posText = { 100,470 };
//	txPnj.setFont(fA);
//	txPnj.setFillColor(sf::Color::Black);
//	txPnj.setPosition(120, 325);
//
//	rsFondTexte.setSize(sf::Vector2f(1280, 60));
//	rsFondTexte.setPosition(10, 375);
//	rsFondTexte.setFillColor(sf::Color::White);
//
//	txDecr.setFont(fA);
//	txDecr.setOrigin(txDecr.getGlobalBounds().height / 2, txDecr.getGlobalBounds().width / 2);
//	txDecr.setPosition(120, 375);
//	txDecr.setFillColor(Color::Black);
//
//	txDescForge.setFont(fA);
//	txDescForge.setOrigin(txDescForge.getGlobalBounds().height / 2, txDescForge.getGlobalBounds().width / 2);
//	txDescForge.setPosition(120, 500);
//	txDescForge.setFillColor(Color::Black);
//
//	rInv.setFillColor(sf::Color(0, 255, 0, 100));
//	rInv.setSize(sf::Vector2f(51, 50));
//
//	boiteDiscussion::initBoiteDiscussion();
//}
//
//void Alchimie::updateAlchimie(sf::RenderWindow& _window, StateManager& _state, Joueur& _perso1) {
//
//	if (_state.getModeJeu() == ModeJeu::LIBRE) {
//		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJForge, sf::Vector2f(50, 50))) {
//			bPnj = true;
//			stPnj = ("Bonjour, bienvenu a la forge.");
//			stRep = ("1: Bonjour, montrez moi ce que je peux forger.");
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
//				_state.ChangeModeJeu(ModeJeu::FORGE);
//			}
//		}
//		else
//			bPnj = false;
//	}
//	if (_state.getModeJeu() == ModeJeu::FORGE) {
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && timerState > 0.3f) {
//			_state.ChangeModeJeu(ModeJeu::LIBRE);
//			timerState = 0.0f;
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && timerState > 0.3f && invDepLateral < 4) {
//			invDepVertical = 1;
//			timerState = 0.0f;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && timerState > 0.3f) {
//			invDepVertical = 2;
//			timerState = 0.0f;
//		}
//		switch (invDepVertical)
//		{
//		case 1:
//			iFObjet = 1;
//			iFMonstre = 0;
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
//				invDepLateral -= 1;
//				timerState = 0.0f;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 3 && timerState > 0.3f) {
//				invDepLateral += 1;
//				timerState = 0.0f;
//			}
//			break;
//		case 2:
//			iFObjet = 0;
//			iFMonstre = 1;
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
//				invDepLateral -= 1;
//				timerState = 0.0f;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 4 && timerState > 0.3f) {
//				invDepLateral += 1;
//				timerState = 0.0f;
//			}
//			break;
//		default:
//			break;
//		}
//		pInvBase = sf::Vector2f(((invDepLateral * 73.5) + 91.5), ((invDepVertical * 71.2) + 24.8));
//		rInv.setPosition(pInvBase);
//	}
//}
//
//void Alchimie::displayAlchimie(sf::RenderWindow& _window, StateManager& _state, Joueur& _perso1) {
//	if (_state.getModeJeu() == ModeJeu::LIBRE) {
//		_window.draw(rsPNJForge);
//		if (bPnj == true) {
//			boiteDiscussion::displayBoiteDiscussion(_window);
//			txPnj.setPosition(posText);
//			txPnj.setString(stPnj);
//			txDecr.setString(stRep);
//			_window.draw(rsFondTexte);
//			_window.draw(txPnj);
//			_window.draw(txDecr);
//		}
//	}
//	if (_state.getModeJeu() == ModeJeu::FORGE) {
//
//		_window.draw(rInv);
//		AffDesc(_perso1);
//		txDescForge.setString("Quantite : " + stQteInv + "\n" + description);
//		_window.draw(txDescForge);
//	}
//}
//
//void Alchimie::AffDesc(Joueur& _perso1) {
//	switch (invDepLateral)
//	{
//	case 1:
//		if (iFObjet == 1) {
//			stTmp = { " Cuivre : " + _perso1.GetLootCuivre() };
//			description = { "Filet : \nFusion Fourrure + cuivre\nFourrure : " + std::to_string(_perso1.GetLootFourrure()) + stTmp };
//			stQteInv = std::to_string(_perso1.GetFillet());
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.GetLootFourrure() > 0 && _perso1.GetLootCuivre() > 0) {
//					_perso1.SetLootFourrure(_perso1.GetLootFourrure() - 1);
//					_perso1.SetLootCuivre(_perso1.GetLootCuivre() - 1);
//					_perso1.SetFillet(_perso1.GetFillet() + 1);
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else if (iFMonstre == 1) {
//			stTmp = { " Ours : " + std::to_string(_perso1.iCatchOurs) };
//			description = { "GobOurs : \nFusion Gobelin + Ours\nGobelin : " + std::to_string(_perso1.iCatchGob) + stTmp };
//			stQteInv = std::to_string(_perso1.iCatchGobOurs);
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.iCatchOurs > 0 && _perso1.iCatchGob > 0) {
//					_perso1.iCatchGob -= 1;
//					_perso1.iCatchOurs -= 1;
//					_perso1.iCatchGobOurs -= 1;
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else {
//			description = { "A venir prochainement" };
//			stQteInv = { "" };
//		}
//		break;
//	case 2:
//		if (iFObjet == 1) {
//			stTmp = { " Fer : " + std::to_string(_perso1.GetLootFer()) };
//			description = { "Super Filet : \nFusion Cuire + Fer\nCuire : " + std::to_string(_perso1.GetLootCuire()) + stTmp };
//			stQteInv = std::to_string(_perso1.GetSuperFillet());
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.GetLootFer() > 0 && _perso1.GetLootCuire() > 0) {
//					_perso1.SetLootCuire(_perso1.GetLootCuire() - 1);
//					_perso1.SetLootFer(_perso1.GetLootFer() - 1);
//					_perso1.SetSuperFillet(_perso1.GetSuperFillet() + 1);
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else if (iFMonstre == 1) {
//			stTmp = { " Loup : " + std::to_string(_perso1.iCatchLoup) };
//			description = { "GobLoup : \nFusion Gobelin + Loup\nGobelin : " + std::to_string(_perso1.iCatchGob) + stTmp };
//			stQteInv = std::to_string(_perso1.iCatchGobLoup);
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.iCatchLoup > 0 && _perso1.iCatchGob > 0) {
//					_perso1.iCatchGob -= 1;
//					_perso1.iCatchLoup -= 1;
//					_perso1.iCatchGobLoup -= 1;
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else {
//			description = { "A venir prochainement" };
//			stQteInv = { "" };
//		}
//		break;
//	case 3:
//		if (iFObjet == 1) {
//			stTmp = { " Potion Mana : " + std::to_string(_perso1.SoinManaBuy) };
//			description = { "Potion mysterieuse : \nFusion Potion PV + potion Mana\nPotion PV : " + std::to_string(_perso1.SoinPvBuy) + stTmp };
//			stQteInv = std::to_string(_perso1.iPotionMy);
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.SoinPvBuy > 0 && _perso1.SoinManaBuy > 0) {
//					_perso1.SoinPvBuy -= 1;
//					_perso1.SoinManaBuy -= 1;
//					_perso1.iPotionMy += 1;
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else if (iFMonstre == 1) {
//			stTmp = { " Orc : " + std::to_string(_perso1.iCatchOrc) };
//			description = { "OursOrc : \nFusion Ours + Orc\nOurs : " + std::to_string(_perso1.iCatchOurs) + stTmp };
//			stQteInv = std::to_string(_perso1.iCatchOursOrc);
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.iCatchOurs > 0 && _perso1.iCatchOrc > 0) {
//					_perso1.iCatchOrc -= 1;
//					_perso1.iCatchOurs -= 1;
//					_perso1.iCatchOursOrc -= 1;
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else {
//			description = { "A venir prochainement" };
//			stQteInv = { "" };
//		}
//		break;
//	case 4:
//		if (iFObjet == 1) {
//			description = { "A venir prochainement" };
//			stQteInv = { "" };
//		}
//		else if (iFMonstre == 1) {
//			stTmp = { " Orc : " + std::to_string(_perso1.iCatchOrc) };
//			description = { "Lourc : \nFusion Loup + Orc\nLoup : " + std::to_string(_perso1.iCatchLoup) + stTmp };
//			stQteInv = std::to_string(_perso1.iCatchLouRoc);
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
//				if (_perso1.iCatchLoup > 0 && _perso1.iCatchGob > 0) {
//					_perso1.iCatchGob -= 1;
//					_perso1.iCatchLoup -= 1;
//					_perso1.iCatchLouRoc -= 1;
//					timerState = 0.0f;
//				}
//				timerState = 0.0f;
//			}
//		}
//		else {
//			description = { "A venir prochainement" };
//			stQteInv = { "" };
//		}
//		break;
//	}
//}
