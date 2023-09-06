#include "Chargement.h"
#include "Menu.h"
#include "Game.h"

Chargement::Chargement() {
}

Chargement::Chargement(StateChargement _stateChargement, myWindow& _window) {
	stateChargement = _stateChargement;
	posTitre = sf::Vector2f(AjustResoX * 700.0f, AjustResoY * 10.0f);
	fClickMenu = 0.0f;
	bValid = false;
	bValidPerso = false;
	bValidPseudo = false;
}

void Chargement::init(myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);

	ttMenu.loadFromFile("../Ressources/Textures/MENU/MenuCeleste.jpg");
	spMenu.setTexture(ttMenu);
	fontMenu.loadFromFile("../Ressources/Fonts/YOZAKURA-Regular.otf");

	txMTitre.setFont(fontMenu);
	txMTitre.setFillColor(_black);
	txMTitre.setPosition(posTitre);
	txMTitre.setCharacterSize(75);

	if (stateChargement == StateChargement::NEW) {
		posNewChoixS = sf::Vector2f(AjustResoX * 700.0f, AjustResoY * 100.0f);
		posNewPersoM = sf::Vector2f(AjustResoX * 600.0f, AjustResoY * 170.0f);
		posNewPersoF = sf::Vector2f(AjustResoX * 950.0f, AjustResoY * 170.0f);
		posNewPseudo = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 300.0f);
		posNewRetour = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 400.0f);
		posNewPseudoVerif = sf::Vector2f(AjustResoX * 200.0f, AjustResoY * 850.0f);
		posNewPersoVerif = sf::Vector2f(AjustResoX * 150.0f, AjustResoY * 850.0f);
		posNewTxVerif = sf::Vector2f(AjustResoX * 150.0f, AjustResoY * 900.0f);
		posNewTxVerifOui = sf::Vector2f(posNewTxVerif.x + txNewVerif.getGlobalBounds().height, posNewTxVerif.y);
		//posNewTxVerifOui = sf::Vector2f(AjustResoX * 600.0f, AjustResoY * 900.0f);
		posNewTxVerifNon = sf::Vector2f(AjustResoX * 700.0f, AjustResoY * 900.0f);

		persoRect = { 192,36,16,18 };

		ttPersoM.loadFromFile("..\\Ressources\\Textures\\CLASSE\\PersoMale.png");
		spPersoM.setTexture(ttPersoM);
		spPersoM.setPosition(posNewPersoM);
		spPersoM.setTextureRect(persoRect);
		spPersoM.setScale(3, 3);

		ttPersoF.loadFromFile("..\\Ressources\\Textures\\CLASSE\\PersoFemale.png");
		spPersoF.setTexture(ttPersoF);
		spPersoF.setPosition(posNewPersoF);
		spPersoF.setTextureRect(persoRect);
		spPersoF.setScale(3, 3);

		spPerso.setPosition(posNewPersoVerif);


		txNewChoixS.setFont(fontMenu);
		txNewChoixS.setFillColor(_black);
		txNewChoixS.setPosition(posNewChoixS);
		txNewChoixS.setCharacterSize(50);

		txNewPseudo.setFont(fontMenu);
		txNewPseudo.setFillColor(_black);
		txNewPseudo.setPosition(posNewPseudo);
		txNewPseudo.setCharacterSize(50);

		txNewRetour.setFont(fontMenu);
		txNewRetour.setFillColor(_black);
		txNewRetour.setPosition(posNewRetour);
		txNewRetour.setCharacterSize(50);

		txNewVerif.setFont(fontMenu);
		txNewVerif.setFillColor(_black);
		txNewVerif.setPosition(posNewTxVerif);
		txNewVerif.setCharacterSize(50);

		txNewVerifOui.setFont(fontMenu);
		txNewVerifOui.setFillColor(_black);
		txNewVerifOui.setPosition(posNewTxVerifOui);
		txNewVerifOui.setCharacterSize(50);

		txNewVerifNon.setFont(fontMenu);
		txNewVerifNon.setFillColor(_black);
		txNewVerifNon.setPosition(posNewTxVerifNon);
		txNewVerifNon.setCharacterSize(50);

		txNewPseudoVerif.setFont(fontMenu);
		txNewPseudoVerif.setFillColor(_black);
		txNewPseudoVerif.setPosition(posNewPseudoVerif);
		txNewPseudoVerif.setCharacterSize(50);
	}
	if (stateChargement == StateChargement::CONTINU) {

	}
	boiteDiscussion::initBoiteDiscussion();
}

void Chargement::update(myWindow& _window) {

	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();
	if (stateChargement == StateChargement::NEW) {
		if (bTextEnter) {
			txNewPseudo.setCharacterSize(75);
			posNewPseudo = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 275.0f);
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewPseudo.x, posNewPseudo.y + txNewPseudo.getGlobalBounds().height), sf::Vector2f(txNewPseudo.getGlobalBounds().width, txNewPseudo.getGlobalBounds().height))) {

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					stPseudo = stTextEnter;
					bTextEnter = false;
					bValidPseudo = true;
					fClickMenu = 0.0f;
				}

			}
		}
		else {

			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewPersoM.x, posNewPersoM.y), sf::Vector2f(spPersoM.getGlobalBounds().width, spPersoM.getGlobalBounds().height))) {

				posNewPersoM = sf::Vector2f(AjustResoX * 600.0f, AjustResoY * 150.0f);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					iChoixSexe = 1;
					spPerso.setTexture(ttPersoM);
					spPerso.setTextureRect(persoRect);
					spPerso.setScale(3, 3);
					bValidPerso = true;
					fClickMenu = 0.0f;
				}
			}
			else {
				spPersoM.setScale(3, 3);
				posNewPersoM = sf::Vector2f(AjustResoX * 600.0f, AjustResoY * 170.0f);
			}
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewPersoF.x, posNewPersoF.y), sf::Vector2f(spPersoF.getGlobalBounds().width, spPersoF.getGlobalBounds().height))) {
				posNewPersoF = sf::Vector2f(AjustResoX * 950.0f, AjustResoY * 150.0f);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					iChoixSexe = 2;
					spPerso.setTexture(ttPersoF);
					spPerso.setTextureRect(persoRect);
					spPerso.setScale(3, 3);
					bValidPerso = true;
					fClickMenu = 0.0f;
				}

			}
			else {
				spPersoF.setScale(3, 3);
				posNewPersoF = sf::Vector2f(AjustResoX * 950.0f, AjustResoY * 170.0f);
			}
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewRetour.x, posNewRetour.y + txNewRetour.getGlobalBounds().height), sf::Vector2f(txNewRetour.getGlobalBounds().width, txNewRetour.getGlobalBounds().height))) {
				txNewRetour.setCharacterSize(75);
				posNewRetour = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 375.0f);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					fClickMenu = 0.0f;
					this->stateManager_->TransitionTo(new Menu(StateMenu::MENU, _window), _window);
					return;
				}
			}
			else {
				txNewRetour.setCharacterSize(50);
				posNewRetour = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 400.0f);
			}
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewPseudo.x, posNewPseudo.y + txNewPseudo.getGlobalBounds().height), sf::Vector2f(txNewPseudo.getGlobalBounds().width, txNewPseudo.getGlobalBounds().height))) {
				txNewPseudo.setCharacterSize(75);
				posNewPseudo = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 275.0f);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					bTextEnter = true;
					fClickMenu = 0.0f;
				}

			}
			else {
				txNewPseudo.setCharacterSize(50);
				posNewPseudo = sf::Vector2f(AjustResoX * 100.0f, AjustResoY * 300.0f);
			}
		}
		if (iChoixSexe == 1) {
			spPersoM.setScale(5, 5);
		}
		if (iChoixSexe == 2) {
			spPersoF.setScale(5, 5);
		}
		if (bValidPerso == true && bValidPseudo == true) {
			bValid = true;
		}
		posNewTxVerifOui = sf::Vector2f(posNewTxVerif.x + txNewVerifOui.getGlobalBounds().width + txNewVerif.getGlobalBounds().width, posNewTxVerif.y);
		posNewTxVerifNon = sf::Vector2f(posNewTxVerif.x + txNewVerifNon.getGlobalBounds().width *3+ txNewVerif.getGlobalBounds().width, posNewTxVerif.y);
		if (bValid) {
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewTxVerifOui.x, posNewTxVerifOui.y + txNewVerifOui.getGlobalBounds().height), sf::Vector2f(txNewVerifOui.getGlobalBounds().width, txNewVerifOui.getGlobalBounds().height))) {
			}
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posNewTxVerifNon.x, posNewTxVerifNon.y + txNewVerifNon.getGlobalBounds().height), sf::Vector2f(txNewVerifNon.getGlobalBounds().width, txNewVerifNon.getGlobalBounds().height))) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					fClickMenu = 0.0f;
					this->stateManager_->TransitionTo(new Menu(StateMenu::MENU, _window), _window);
					return;
				}
			}
		}
		txNewPseudoVerif.setString(stPseudo);
		tools::ChoixLangue(tools::GetTrad(), txMTitre, "Nouvelle Partie", "New Game");
		tools::ChoixLangue(tools::GetTrad(), txNewChoixS, "Choix du Sexe", "Sex Choice");
		tools::ChoixLangue(tools::GetTrad(), txNewPseudo, "Pseudo : " + stTextEnter, "Pseudo : " + stTextEnter);
		tools::ChoixLangue(tools::GetTrad(), txNewRetour, "Retour", "Back");
		tools::ChoixLangue(tools::GetTrad(), txNewVerif, "Voulez vous continuer ?", "nAre you sure you want to continue ?");
		tools::ChoixLangue(tools::GetTrad(), txNewVerifOui, "Oui", "Yes");
		tools::ChoixLangue(tools::GetTrad(), txNewVerifNon, "Non", "No");
		txNewVerifOui.setPosition(posNewTxVerifOui);
		txNewVerifNon.setPosition(posNewTxVerifNon);
	}
	if (stateChargement == StateChargement::CONTINU) {
		tools::ChoixLangue(tools::GetTrad(), txMTitre, "Chargement de la partie", "Load Game");

	}
}

void Chargement::updateEvent(myWindow& _window) {

	if (_window.GetEvent().type == sf::Event::TextEntered) {
		if (_window.GetEvent().text.unicode >= 33 && _window.GetEvent().text.unicode <= 126) {
			if (bTextEnter == true && stTextEnter.size() <= (char)9)
				stTextEnter += (char)(_window.GetEvent().text.unicode);
		}
		if (_window.GetEvent().text.unicode == 8) {
			if (bTextEnter == true && stTextEnter.size() > 0)
				stTextEnter.pop_back();
		}
		if (_window.GetEvent().text.unicode == 32) {
			if (bTextEnter == true && stTextEnter.size() <= (char)9)
				stTextEnter += (char)(_window.GetEvent().text.unicode);
		}
	}
}

void Chargement::draw(myWindow& _window) {
	_window.Draw(spMenu);
	_window.Draw(txMTitre);
	if (stateChargement == StateChargement::NEW) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		_window.Draw(txNewChoixS);
		_window.Draw(spPersoM);
		_window.Draw(spPersoF);
		_window.Draw(txNewPseudo);
		_window.Draw(txNewRetour);
		if (bValid) {
			_window.Draw(spPerso);
			_window.Draw(txNewPseudoVerif);
			_window.Draw(txNewVerif);
			_window.Draw(txNewVerifOui);
			_window.Draw(txNewVerifNon);
		}
	}
	if (stateChargement == StateChargement::CONTINU) {

	}
}

void Chargement::destroy() {
}
