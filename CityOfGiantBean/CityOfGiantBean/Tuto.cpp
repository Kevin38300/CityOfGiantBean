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
	txTuto.setCharacterSize(40);
	txTuto.setPosition(posText);

	boiteDiscussion::initBoiteDiscussion();
}

void updateTuto(MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode) {
	timerAff += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
		save::setTuto(false);
		timerAff = 0.0f;
	}
	if (save::getTutoNb() == 1) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "Bienvenu a la cite celeste\nSi vous avez besoin d'un guide appuyer sur ''Entrer'', sinon ''suppr''\nVous pouvez arretez le tuto a tous moment en appuyant sur ''suppr''", "Welcome to the celeste city\nIf you need a guide press ''Enter'', otherwise ''delete''\nYou can stop the tutorial at any time by pressing ''delete''");
		timerAff = 0.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			save::setTutoNb(2);
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
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Battez le gobelin, contentez vous de l'attaquer, vous ne disposez pas d'obbet ou de skill\npuis revenez en ville", "Defeated the goblin, just attack him, you don't have an item or skill\nthen come back to town");
		}
	}
	if (save::getTutoNb() == 4) {

		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Allons maintenant acheter de l'equipement, dans le batiment sous l'hotel\nAcheter une bombe", "Let's now go buy equipment, in the building under the hotel\nBuy a bomb");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Une fois l'equipement acheter vous pouvez l'equiper depuis votre inventaire en appuyant sur Echap\nequipez vous puis retourner au safarie", "Once the equipment is purchased you can equip it from your inventory by pressing Esc\nEquip yourself and then return to the safari");
		}
	}
	if (save::getTutoNb() == 5) {

		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Retournez au safari", "Go back to the safari");
		}
		if (_map == MapGame::SAFARIE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Battez le Loup, puis revenez en ville, utilisez la bombe en cas de besoin", "Defeated the wolf, then come back to town, use a bomb if needed");
		}
	}
	if (save::getTutoNb() == 6) {
		if (_map == MapGame::SAFARIE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Retournez en ville", "Go back the town");
		}
		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Felicitation ! Maintenant que vous avez augmenter votre niveau, vous pouvez obtenir un skill.\nRetournez a l'hotel", "Congratulations! Now that you have increased your level, you can get a skill.\nReturn to the hotel");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Allez verifier l'arbre des skill en parlant au au perso en haut a droite\npuis obtenez en un", "Check the skill tree by talking to the personal at the top right\nthen get one");
		}
	}
	if (save::getTutoNb() == 7) {
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Sortez puis dirigez vous vers l'haricot geant. Direction l'Aventure !", "Get out and head to the giant bean. Let's go for the adventure!");
		}
		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Vous pourrez choisir une zone d'aventure, l'aventure permet d'augmenter son niveau d'aventure\nles autres zone permettent d'obtenir differentes recompense et leur niveau est lie a l'aventure\nCommencons par la zone d'aventure", "You will be able to choose an adventure zone, the adventure allows you to increase your level of adventure\nThe other areas allow you to obtain different rewards and their level is linked to the adventure\nLet's start with the adventure zone");
		}
		if (_map == MapGame::AVENTURE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Affrontez le guerrier si il est trop fort, fuyez et rtournez en ville", "Face the warrior if he is too strong, flee and return to the city");
		}

	}
	if (save::getTutoNb() == 8) {
		if (_map == MapGame::AVENTURE) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Retournez en ville", "Go back the town");
		}
		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Pour devenir plus fort, je conseil d'obtenir une classe\nPour ca direction la taverne, le batiment a droite sous le pont", "To become stronger, I advise to get a class\nFor that go to the tavern, the building on the right under the bridge");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Parlez a un aventurier pour obtenir une classe puis retournez en ville", "Talk to an adventurer to get a class and go back to the town");
		}
	}
	if (save::getTutoNb() == 9) {
		if (_map == MapGame::RDC) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Je conseil aussi d'obtenir un element\nPour ca direction la fontaine, le batiment a droite sous la taverne", "I advise also to get an element\nFor that go to the fountain, the building on the right under the tavern");
		}
		if (_map == MapGame::SHOP) {
			tools::ChoixLangue(tools::GetTrad(), txTuto, "Dirigez vous vers l'element souhaitez puis obtenez le", "Head to the desired element and then get the");
		}
	}
	if (save::getTutoNb() == 10) {
		tools::ChoixLangue(tools::GetTrad(), txTuto, "Vous etes fin pret pour partir vivre votre aventure.\nVous avez encore des chose a decouvrir par vous meme, bon courage !", "You are ready to go live your adventure.\nYou still have things to discover by yourself, good luck !");
	}
	if (save::getTutoNb() == 11) {
			save::setTuto(false);
	}
}

void drawTuto(myWindow& _window) {
	if (timerAff <= 4.0f) {

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
