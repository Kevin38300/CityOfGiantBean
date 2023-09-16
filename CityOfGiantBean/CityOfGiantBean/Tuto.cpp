#include "Tuto.h"


sf::Vector2f posText;
sf::Font fontTuto;
sf::Text txTuto;
float timerAff{ 0.0f };

void initTuto() {

	fontTuto.loadFromFile("../Ressources/Fonts/YOZAKURA-Regular.otf");
	posText = { AjustResoX * 150, AjustResoY * 850 };
	txTuto.setFont(fontTuto);
	txTuto.setFillColor(sf::Color::Black);
	txTuto.setCharacterSize(50);
	txTuto.setPosition(posText);

	boiteDiscussion::initBoiteDiscussion();
}

void updateTuto(MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode) {
	timerAff += tools::GetTimeDelta();
	if (save::getTutoNb() == 1) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "Bienvenu a la cite celeste\nSi vous avez besoin d'un guide appuyer sur ''Entrer'', sinon ''suppr''", "Welcome to the celeste city\nIf you need a guide press ''Enter'', otherwise ''delete''");
		timerAff = 0.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			save::setTutoNb(2);
			timerAff = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			save::setTuto(false);
			timerAff = 0.0f;
		}
	}
	if (save::getTutoNb() == 2) {
		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Pour commencer click sur l'hotel le batiment en haut a gauche", "To start click on the hotel the building at the top left");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "allez verifier le tableau de quete en parlant au au perso en haut a gauche, puis sortez du batiment", "Go check the quest board by talking to the personal at the top left, then exit the building");
		}

	}
	if (save::getTutoNb() == 3) {

		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Maintenant allons chasser au safari, prenez le pont en haut a droite", "Now let's go hunting on safari, take the bridge at the top right");
		}
		if (_map == MapGame::SAFARIE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Affrontez le gobelin, contentez vous de l'attaquer, vous ne disposez pas d'obbet ou de skill\npuis revenez en ville", "Fight the goblin, just attack him, you don't have an item or skill\nthen come back to town");
		}
	}
	if (save::getTutoNb() == 4) {

		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Allons maintenant acheter de l'equipement, dans le batiment sous l'hotel", "Let's now go buy equipment, in the building under the hotel");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Une fois l'equipement acheter vous pouvez l'equiper depuis votre inventaire en appuyant sur Echap\nequipez vous puis retourner au safarie", "Once the equipment is purchased you can equip it from your inventory by pressing Esc");
		}
	}
	if (save::getTutoNb() == 5) {

		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Retournez au safari", "Go back to the safari");
		}
		if (_map == MapGame::SAFARIE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Affrontez le Loup, puis revenez en ville", "Fight the wolf, then come back to town");
		}
	}
	if (save::getTutoNb() == 6) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "", "");

	}
	if (save::getTutoNb() == 7) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "", "");

	}
	if (save::getTutoNb() == 8) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "", "");

	}
	if (save::getTutoNb() == 9) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "", "");

	}
	if (save::getTutoNb() == 10) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "", "");

	}
}

void drawTuto(myWindow& _window) {
	if (timerAff <= 3.0f) {

		if (save::getTutoNb() == 1) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);
		}
		if (save::getTutoNb() == 2) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 3) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 4) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 5) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 6) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 7) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 8) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 9) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
		if (save::getTutoNb() == 10) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			_window.Draw(txTuto);

		}
	}
}
