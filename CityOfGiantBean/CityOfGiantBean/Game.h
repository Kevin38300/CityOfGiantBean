#pragma once
#include "stateManager.h"


enum class StateGame {
	NEW,
	CONTINU
};

class Game : public State
{
private:

	sf::Texture ttMenu;
	sf::Sprite spMenu;
	sf::Vector2f posTitre, posSouris;
	sf::Vector2i mousePosition;
	float fClickMenu;
	sf::Font fontMenu;

	sf::Text txMTitre;
	sf::Vector2f posMTitre;

	sf::Color _white, _black, _green, _red, _transparent, _blue, _cyan;

	StateGame stateGame;
public:
	Game();
	Game(StateGame _stateGame, myWindow& _window);
	void init(myWindow& _window) override;
	void update(myWindow& _window) override;
	void updateEvent(myWindow& _window) override;
	void draw(myWindow& _window) override;
	void destroy() override;

};

