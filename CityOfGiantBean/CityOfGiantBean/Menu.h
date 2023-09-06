#pragma once
#include "stateManager.h"


enum class StateMenu {
	MENU,
	GAME
};

class Menu : public State
{
private:

	sf::Texture ttMenu;
	sf::Sprite spMenu;
	sf::Vector2f posTitre, posSouris;
	sf::Vector2i mousePosition;
	float fClickMenu;

	sf::Font fontMenu;
	sf::Text txMTitre, txMNew, txMCharge, txMOption, txMQuitter, txMOvolSon, txMOvolMusic, txMOpe, txMOaide, txMOlangue, txMOmoinSon, txMOmoinMus, txMOplusSon, txMOplusMus;
	sf::Vector2f posMTitre, posMNew, posMCharge, posMOption, posMQuitter, posMOvolSon, posMOvolMusic, posMOpe, posMOaide, posMOlangue, posMOmoinSon, posMOmoinMus, posMOplusSon, posMOplusMus;
	sf::Text txVerifNew, txVerifOui, txVerifNon;
	sf::Vector2f posVerifNew, posVerifOui, posVerifNon;

	bool bOption, bVerifNew;
	sf::Color _white, _black, _green, _red, _transparent, _blue, _cyan;

	StateMenu stateMenu;
public:
	Menu();
	Menu(StateMenu _stateMenu, myWindow& _window);
	void init(myWindow& _window) override;
	void update(myWindow& _window) override;
	void updateEvent(myWindow& _window) override;
	void draw(myWindow& _window) override;
	void destroy() override;

};

