#include "Menu.h"
#include "Chargement.h"

Menu::Menu() {
}

Menu::Menu(StateMenu _stateMenu, myWindow& _window) {
	_white = sf::Color::White;
	_black = sf::Color::Black;
	_green = sf::Color::Green;
	_red = sf::Color::Red;
	_blue = sf::Color::Blue;
	_cyan = sf::Color::Cyan;
	_transparent = sf::Color(0.0, 0.0, 0.0, 0.0);

	posVerifNew = sf::Vector2f(AjustResoX * 150.0f, AjustResoY * 850.0f);
	posVerifOui = sf::Vector2f(AjustResoX * 800.0f, AjustResoY * 900.0f);
	posVerifNon = sf::Vector2f(AjustResoX * 900.0f, AjustResoY * 900.0f);

	posAideCombat = sf::Vector2f(AjustResoX * 600.0f, AjustResoY * 100.0f);
	posAideDir = sf::Vector2f(AjustResoX * 850.0f, AjustResoY * 100.0f);

	posAide = sf::Vector2f(AjustResoX * 500.0f, AjustResoY * 200.0f);

	posTitre = sf::Vector2f(AjustResoX * 700.0f, AjustResoY * 10.0f);
	posMNew = sf::Vector2f(AjustResoX * 50.0f, AjustResoY * 100.0f);
	posMCharge = sf::Vector2f(AjustResoX * 50.0f, AjustResoY * 150.0f);
	posMOption = sf::Vector2f(AjustResoX * 50.0f, AjustResoY * 200.0f);
	posMQuitter = sf::Vector2f(AjustResoX * 50.0f, AjustResoY * 250.0f);

	posMOvolSon = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 200.0f);
	posMOvolMusic = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 250.0f);
	posMOpe = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 300.0f);
	posMOaide = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 350.0f);
	posMOlangue = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 400.0f);

	fClickMenu = 0.0f;
	bOption = false;
	bVerifNew = false;

	stateMenu = _stateMenu;

	tools::SetChoixMu(1);
}

void Menu::init(myWindow& _window) {


	ttAideCom.loadFromFile("../Ressources/Textures/MENU/commandeCombat.png");
	spAideCom.setTexture(ttAideCom);
	spAideCom.setPosition(posAide);
	spAideCom.setScale(1 * AjustResoX, 1 * AjustResoY);
	ttAideComEn.loadFromFile("../Ressources/Textures/MENU/commandeCombatEn.png");
	spAideComEn.setTexture(ttAideComEn);
	spAideComEn.setPosition(posAide);
	spAideComEn.setScale(1 * AjustResoX, 1 * AjustResoY);

	ttAideDir.loadFromFile("../Ressources/Textures/MENU/commandeDir.png");
	spAideDir.setTexture(ttAideDir);
	spAideDir.setPosition(posAide);
	spAideDir.setScale(1 * AjustResoX, 1 * AjustResoY);
	ttAideDirEn.loadFromFile("../Ressources/Textures/MENU/commandeDirEn.png");
	spAideDirEn.setTexture(ttAideDirEn);
	spAideDirEn.setPosition(posAide);
	spAideDirEn.setScale(1 * AjustResoX, 1 * AjustResoY);


	ttMenu.loadFromFile("../Ressources/Textures/MENU/MenuCeleste.jpg");
	spMenu.setTexture(ttMenu);
	spMenu.setScale(1 * AjustResoX, 1 * AjustResoY);

	fontMenu.loadFromFile("../Ressources/Fonts/YOZAKURA-Regular.otf");

	txMTitre.setFont(fontMenu);
	txMTitre.setFillColor(_black);
	txMTitre.setPosition(posTitre);
	txMTitre.setCharacterSize(75 * AjustReso);

	txMNew.setFont(fontMenu);
	txMNew.setFillColor(_black);
	txMNew.setPosition(posMNew);
	txMNew.setCharacterSize(35 * AjustReso);

	txMCharge.setFont(fontMenu);
	txMCharge.setFillColor(_black);
	txMCharge.setPosition(posMCharge);
	txMCharge.setCharacterSize(35 * AjustReso);

	txMOption.setFont(fontMenu);
	txMOption.setFillColor(_black);
	txMOption.setPosition(posMOption);
	txMOption.setCharacterSize(35 * AjustReso);

	txMQuitter.setFont(fontMenu);
	txMQuitter.setFillColor(_black);
	txMQuitter.setPosition(posMQuitter);
	txMQuitter.setCharacterSize(35 * AjustReso);

	txMOvolSon.setFont(fontMenu);
	txMOvolSon.setFillColor(_black);
	txMOvolSon.setPosition(posMOvolSon);
	txMOvolSon.setCharacterSize(35 * AjustReso);

	txMOvolMusic.setFont(fontMenu);
	txMOvolMusic.setFillColor(_black);
	txMOvolMusic.setPosition(posMOvolMusic);
	txMOvolMusic.setCharacterSize(35 * AjustReso);

	txMOpe.setFont(fontMenu);
	txMOpe.setFillColor(_black);
	txMOpe.setPosition(posMOpe);
	txMOpe.setCharacterSize(35 * AjustReso);

	txMOaide.setFont(fontMenu);
	txMOaide.setFillColor(_black);
	txMOaide.setPosition(posMOaide);
	txMOaide.setCharacterSize(35 * AjustReso);

	txMOlangue.setFont(fontMenu);
	txMOlangue.setFillColor(_black);
	txMOlangue.setPosition(posMOlangue);
	txMOlangue.setCharacterSize(35 * AjustReso);

	txMOmoinMus.setFont(fontMenu);
	txMOmoinMus.setFillColor(_black);
	txMOmoinMus.setCharacterSize(35 * AjustReso);

	txMOmoinSon.setFont(fontMenu);
	txMOmoinSon.setFillColor(_black);
	txMOmoinSon.setCharacterSize(35 * AjustReso);

	txMOplusMus.setFont(fontMenu);
	txMOplusMus.setFillColor(_black);
	txMOplusMus.setCharacterSize(35 * AjustReso);

	txMOplusSon.setFont(fontMenu);
	txMOplusSon.setFillColor(_black);
	txMOplusSon.setCharacterSize(35 * AjustReso);

	txVerifNew.setFont(fontMenu);
	txVerifNew.setFillColor(_red);
	txVerifNew.setPosition(posVerifNew);
	txVerifNew.setCharacterSize(50 * AjustReso);

	txVerifOui.setFont(fontMenu);
	txVerifOui.setFillColor(_red);
	txVerifOui.setPosition(posVerifOui);
	txVerifOui.setCharacterSize(50 * AjustReso);

	txVerifNon.setFont(fontMenu);
	txVerifNon.setFillColor(_red);
	txVerifNon.setPosition(posVerifNon);
	txVerifNon.setCharacterSize(50 * AjustReso);

	txAideCombat.setFont(fontMenu);
	txAideCombat.setFillColor(_red);
	txAideCombat.setPosition(posAideCombat);
	txAideCombat.setCharacterSize(50 * AjustReso);

	txAideDir.setFont(fontMenu);
	txAideDir.setFillColor(_red);
	txAideDir.setPosition(posAideDir);
	txAideDir.setCharacterSize(50 * AjustReso);

	boiteDiscussion::initBoiteDiscussion();

	tools::SetFirstInM(false);
	musiqueMenu.openFromFile("..\\Ressources\\Audio\\Menu.ogg");
	musiqueMenu.setLoop(true);
	SonMenuBuffer.loadFromFile("..\\Ressources\\Audio\\Whoosh3.wav");
	SonMenu.setBuffer(SonMenuBuffer);
}

void Menu::update(myWindow& _window) {

	std::ifstream Save("..\\Ressources\\Save\\Save.txt", std::ios::in);
	if (!Save.is_open()) {
		bSave = false;
	}
	else {
		bSave = true;
	}

	if (tools::GetFirstInM() == false) {
		musiqueMenu.play();
		tools::SetFirstInM(true);
	}
	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();
	posMOmoinSon = sf::Vector2f(posMOvolSon.x + txMOvolSon.getGlobalBounds().width, posMOvolSon.y);
	posMOplusSon = sf::Vector2f(posMOmoinSon.x + txMOmoinSon.getGlobalBounds().width * 2, posMOmoinSon.y);
	posMOmoinMus = sf::Vector2f(posMOvolMusic.x + txMOvolMusic.getGlobalBounds().width, posMOvolMusic.y);
	posMOplusMus = sf::Vector2f(posMOmoinMus.x + txMOmoinMus.getGlobalBounds().width * 2, posMOmoinMus.y);

	if (bOption == true) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
			if (bAide == false) {

				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOption.x, posMOption.y + txMOption.getGlobalBounds().height), sf::Vector2f(txMOption.getGlobalBounds().width, txMOption.getGlobalBounds().height))) {
					bOption = false;
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOaide.x, posMOaide.y + txMOaide.getGlobalBounds().height), sf::Vector2f(txMOaide.getGlobalBounds().width, txMOaide.getGlobalBounds().height))) {
					bAide = true;
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOpe.x, posMOpe.y + txMOpe.getGlobalBounds().height), sf::Vector2f(txMOpe.getGlobalBounds().width, txMOpe.getGlobalBounds().height))) {
					_window.ToggleFullscreen();
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOmoinSon.x, posMOmoinSon.y + 30), sf::Vector2f(txMOmoinSon.getGlobalBounds().width, txMOmoinSon.getGlobalBounds().height)) && music::GetVolumeSon() > 0) {
					music::AddVolumeSon(-5);
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOplusSon.x, posMOplusSon.y + txMOplusSon.getGlobalBounds().height), sf::Vector2f(txMOplusSon.getGlobalBounds().width, txMOplusSon.getGlobalBounds().height)) && music::GetVolumeSon() < 100) {
					music::AddVolumeSon(5);
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOmoinMus.x, posMOmoinMus.y + 30), sf::Vector2f(txMOmoinMus.getGlobalBounds().width, txMOmoinMus.getGlobalBounds().height)) && music::GetVolumeMusique() > 0) {
					music::AddVolumeMusique(-5);
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOplusMus.x, posMOplusMus.y + txMOplusMus.getGlobalBounds().height), sf::Vector2f(txMOplusMus.getGlobalBounds().width, txMOplusMus.getGlobalBounds().height)) && music::GetVolumeMusique() < 100) {
					music::AddVolumeMusique(5);
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOlangue.x, posMOlangue.y + txMOlangue.getGlobalBounds().height), sf::Vector2f(txMOlangue.getGlobalBounds().width, txMOlangue.getGlobalBounds().height))) {
					if (tools::GetTrad() == 0) {
						tools::SetTrad(1);
					}
					else if (tools::GetTrad() == 1) {
						tools::SetTrad(0);
					}
					fClickMenu = 0.0f;
				}
			}
			else {
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOaide.x, posMOaide.y + txMOaide.getGlobalBounds().height), sf::Vector2f(txMOaide.getGlobalBounds().width, txMOaide.getGlobalBounds().height))) {
					bAide = false;
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAideCombat.x, posAideCombat.y + txAideCombat.getGlobalBounds().height), sf::Vector2f(txAideCombat.getGlobalBounds().width, txAideCombat.getGlobalBounds().height))) {
					iAide = 1;
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAideDir.x, posAideDir.y + txAideDir.getGlobalBounds().height), sf::Vector2f(txAideDir.getGlobalBounds().width, txAideDir.getGlobalBounds().height))) {
					iAide = 2;
					fClickMenu = 0.0f;
				}
			}
		}
	}
	else {
		if (bVerifNew) {

			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posVerifOui.x, posVerifOui.y + txVerifOui.getGlobalBounds().height), sf::Vector2f(txVerifOui.getGlobalBounds().width, txVerifOui.getGlobalBounds().height))) {
				txVerifOui.setCharacterSize(75);
				posVerifOui = sf::Vector2f(AjustResoX * 800.0f, AjustResoY * 875.0f);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					fClickMenu = 0.0f;
					this->stateManager_->TransitionTo(new Chargement(StateChargement::NEW, _window), _window);
					return;
				}
			}
			else {
				txVerifOui.setCharacterSize(50);
				posVerifOui = sf::Vector2f(AjustResoX * 800.0f, AjustResoY * 900.0f);
			}
			if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posVerifNon.x, posVerifNon.y + txVerifNon.getGlobalBounds().height), sf::Vector2f(txVerifNon.getGlobalBounds().width, txVerifNon.getGlobalBounds().height))) {
				txVerifNon.setCharacterSize(75);
				posVerifNon = sf::Vector2f(AjustResoX * 900.0f, AjustResoY * 875.0f);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
					fClickMenu = 0.0f;
					bVerifNew = false;
				}
			}
			else {
				txVerifNon.setCharacterSize(50);
				posVerifNon = sf::Vector2f(AjustResoX * 900.0f, AjustResoY * 900.0f);
			}
			tools::ChoixLangue(tools::GetTrad(), txVerifNew, "Vous allez commencer une nouvelle partie\nVous etes sur de vouloir continuer ?", "You are going to start a new game\nAre you sure you want to continue?");
			tools::ChoixLangue(tools::GetTrad(), txVerifOui, "Oui", "Yes");
			tools::ChoixLangue(tools::GetTrad(), txVerifNon, "Non", "No");
		}
		else {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {

				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMOption.x, posMOption.y + txMOption.getGlobalBounds().height), sf::Vector2f(txMOption.getGlobalBounds().width, txMOption.getGlobalBounds().height))) {
					bOption = true;
					fClickMenu = 0.0f;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMNew.x, posMNew.y + txMNew.getGlobalBounds().height), sf::Vector2f(txMNew.getGlobalBounds().width, txMNew.getGlobalBounds().height))) {
					fClickMenu = 0.0f;
					bVerifNew = true;
				}
				if (bSave) {
					if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMCharge.x, posMCharge.y + txMCharge.getGlobalBounds().height), sf::Vector2f(txMCharge.getGlobalBounds().width, txMCharge.getGlobalBounds().height))) {
						fClickMenu = 0.0f;
						this->stateManager_->TransitionTo(new Chargement(StateChargement::CONTINU, _window), _window);
						return;
					}
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posMQuitter.x, posMQuitter.y + txMQuitter.getGlobalBounds().height), sf::Vector2f(txMQuitter.getGlobalBounds().width, txMQuitter.getGlobalBounds().height))) {
					_window.SetIsDone(true);
					fClickMenu = 0.0f;
				}
			}
		}
	}

	music::SetVolume(musiqueMenu);

	tools::ChoixLangue(tools::GetTrad(), txAideCombat, "Aide combat", "Help fight");
	tools::ChoixLangue(tools::GetTrad(), txAideDir, "Aide direction", "Help direction");
	tools::ChoixLangue(tools::GetTrad(), txMTitre, "Cite de l'haricot geant", "City Of Giant Bean");
	tools::ChoixLangue(tools::GetTrad(), txMNew, "Nouvelle partie", "New Game");
	tools::ChoixLangue(tools::GetTrad(), txMCharge, "Charger la partie", "Charge game");
	tools::ChoixLangue(tools::GetTrad(), txMOption, "Options", "Settings");
	tools::ChoixLangue(tools::GetTrad(), txMQuitter, "Quitter", "Exit");
	tools::ChoixLangue(tools::GetTrad(), txMOvolSon, "Volume Sons ", "Volume Sounds ");
	txMOmoinSon.setString("- ");
	txMOmoinSon.setPosition(posMOmoinSon);
	txMOplusSon.setString("+  " + std::to_string((int)music::GetVolumeSon()));
	txMOplusSon.setPosition(posMOplusSon);
	tools::ChoixLangue(tools::GetTrad(), txMOvolMusic, "Volume Musiques", "Volume Musics");
	txMOmoinMus.setString("- ");
	txMOmoinMus.setPosition(posMOmoinMus);
	txMOplusMus.setString("+  " + std::to_string((int)music::GetVolumeMusique()));
	txMOplusMus.setPosition(posMOplusMus);
	tools::ChoixLangue(tools::GetTrad(), txMOpe, "Plein Ecran", "Fullscreen");
	tools::ChoixLangue(tools::GetTrad(), txMOaide, "Aide", "Help");
	tools::ChoixLangue(tools::GetTrad(), txMOlangue, "Langue : Francais", "Language : English");
}

void Menu::updateEvent(myWindow& _window) {
}

void Menu::draw(myWindow& _window) {
	_window.Draw(spMenu);
	_window.Draw(txMTitre);
	_window.Draw(txMNew);
	if (bSave)
		_window.Draw(txMCharge);
	_window.Draw(txMOption);
	_window.Draw(txMQuitter);
	if (bVerifNew) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		_window.Draw(txVerifNew);
		_window.Draw(txVerifOui);
		_window.Draw(txVerifNon);
	}
	if (bOption) {
		_window.Draw(txMOvolSon);
		_window.Draw(txMOmoinSon);
		_window.Draw(txMOplusSon);
		_window.Draw(txMOvolMusic);
		_window.Draw(txMOmoinMus);
		_window.Draw(txMOplusMus);
		_window.Draw(txMOpe);
		_window.Draw(txMOaide);
		_window.Draw(txMOlangue);
		if (bAide == true) {
			_window.Draw(txAideCombat);
			_window.Draw(txAideDir);
			if (iAide == 1) {
				if (tools::GetTrad() == 0)
					_window.Draw(spAideCom);
				if (tools::GetTrad() == 1)
					_window.Draw(spAideComEn);
			}
			if (iAide == 2) {
				if (tools::GetTrad() == 0)
					_window.Draw(spAideDir);
				if (tools::GetTrad() == 1)
					_window.Draw(spAideDirEn);
			}
		}
	}
}

void Menu::destroy() {
}
