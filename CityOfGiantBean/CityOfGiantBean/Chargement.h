#pragma once
#include "stateManager.h"


enum class StateChargement {
	NEW,
	CONTINU
};

class Chargement : public State
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

	sf::Texture ttPersoM, ttPersoF;
	sf::Sprite spPersoM, spPersoF, spPerso;
	sf::Text txNewChoixS, txNewPseudo, txNewPseudoVerif, txEntrePseudo, txNewRetour, txNewVerif, txNewVerifOui, txNewVerifNon;
	sf::Vector2f posNewChoixS, posNewPseudo, posNewRetour, posEntrePseudo, posNewPersoM, posNewPersoF, posNewPersoVerif, posNewPseudoVerif, posNewTxVerif, posNewTxVerifOui, posNewTxVerifNon;
	int iChoixSexe{ 0 };
	sf::IntRect persoRect;
	bool bValid, bValidPerso, bValidPseudo, bTextEnter;
	std::string stTextEnter, stPseudo;

	sf::Color _white, _black, _green, _red, _transparent, _blue, _cyan;

	StateChargement stateChargement;
public:
	Chargement();
	Chargement(StateChargement _stateChargement, myWindow& _window);
	void init(myWindow& _window) override;
	void update(myWindow& _window) override;
	void updateEvent(myWindow& _window) override;
	void draw(myWindow& _window) override;
	void destroy() override;

};

