#pragma once
#include "Tools.h"
#include "Game.h"
class Joueur;
class Alchimie
{
private:
float timerState;
	sf::RectangleShape rsPNJForge, rInv;

	sf::Vector2f posrsPNJForge, posText, pInvBase;

	sf::Font fA;

	std::string stPnj, stRep, stPnjEn, stRepEn, stChoixFusion, description, descriptionEn, stQteInv, stTmp;

	sf::Text txPnj, txDecr, txDescForge, txRetour;

	bool bPnj{ false };

	int invDepVertical{1}, invDepLateral{ 1 }, iFObjet{ 0 }, iFMonstre{ 0 }, OuiNonAl{ 0 };

public:
	void initAlchimie();
	void updateAlchimie(myWindow& _window, ModeGame& _mode, Joueur& _perso1);
	void displayAlchimie(myWindow& _window, ModeGame& _mode, Joueur& _perso1);
	void AffDesc(Joueur& _perso1);
};
