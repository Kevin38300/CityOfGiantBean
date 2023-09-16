#pragma once
#include "stateManager.h"


enum class StateMenu {
	MENU,
	GAME
};

class Menu : public State
{
private:

	sf::Texture ttMenu, ttAideDir, ttAideCom, ttAideDirEn, ttAideComEn;
	sf::Sprite spMenu, spAideDir, spAideCom, spAideDirEn, spAideComEn;
	sf::Vector2f posTitre, posSouris, posAide;
	sf::Vector2i mousePosition;
	float fClickMenu;

	sf::Font fontMenu;
	sf::Text txMTitre, txMNew, txMCharge, txMOption, txMQuitter, txMOvolSon, txMOvolMusic, txMOpe, txMOaide, txMOlangue, txMOmoinSon, txMOmoinMus, txMOplusSon, txMOplusMus;
	sf::Vector2f posMTitre, posMNew, posMCharge, posMOption, posMQuitter, posMOvolSon, posMOvolMusic, posMOpe, posMOaide, posMOlangue, posMOmoinSon, posMOmoinMus, posMOplusSon, posMOplusMus;
	sf::Text txVerifNew, txVerifOui, txVerifNon, txAideDir, txAideCombat;
	sf::Vector2f posVerifNew, posVerifOui, posVerifNon, posAideDir, posAideCombat;

	bool bOption, bVerifNew, bSave, bAide;
	int iAide{ 0 };
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

