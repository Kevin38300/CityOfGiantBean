#pragma once
#include "Game.h"
#include "Tools.h"

class Joueur;
class Safarie;

class MenuGame {

	sf::Texture MenuInGameTexture, tmgInventaire, ttAvatar;

	sf::Sprite MenuGameSprite, smgInv, spAvatarFull;

	std::string description, stQteInv, stEquipeOuNon ;

	sf::Text sMGinventaire, sMGchoixEquipe, sMGoption, txDescriptionInv, txDesOption, txProfil, txAide, txQuete, txRetour, txAvatar, txInfoProfil;

	sf::Font fMG;

	int iMGchoixMenu{ 1 }, choixInv{ 0 }, iAvatar{0}, iChoixAvatar{0}, choixOption{0}, iInvDepEquipement, iIvDepLoot, iInvDepUtilitaire, iInvDepMonstre, invDepVertical, invDepVerticalOp, invDepLateral;

	sf::RectangleShape rInv, rOption, rsChoixAvatar;

	sf::Vector2f pInvBase, pOption, posRsAvatar{ 250,93 }, posDesOption, posProfil, posAide, posQuete, posRetour, posAvatar, posAvatarP{ 50,50 };

	bool bProfil{ false }, bAide{ false }, bAvatar{ false }, bQuete{ false }, BAva[7]{ false };
	float timerState{ 0.0f };
	sf::IntRect rectAvatar{ 450,0,50,50 };
public:
	sf::Sprite spAvatar;
	MenuGame() {};
	~MenuGame() {};

	void InitMenuGame() {
		MenuInGameTexture.loadFromFile("..\\Ressources\\Textures\\MENU\\MenuGame.png");
		MenuGameSprite.setTexture(MenuInGameTexture);

		tmgInventaire.loadFromFile("..\\Ressources\\Textures\\MENU\\Inventaire.png");
		smgInv.setTexture(tmgInventaire);
		smgInv.setPosition(sf::Vector2f(150, 80));

		ttAvatar.loadFromFile("..\\Ressources\\Textures\\Logo\\AvatarProfil.png");
		spAvatarFull.setTexture(ttAvatar);
		spAvatar.setTexture(ttAvatar);
		spAvatarFull.setPosition(sf::Vector2f(250, 90));

		fMG.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

		sMGoption.setString("Option");
		sMGoption.setFont(fMG);
		sMGoption.setOrigin(sMGoption.getGlobalBounds().height / 2, sMGoption.getGlobalBounds().width / 2);
		sMGoption.setPosition(1100, 90);

		sMGinventaire.setString("Inventaire");
		sMGinventaire.setFont(fMG);
		sMGinventaire.setOrigin(sMGinventaire.getGlobalBounds().height / 2, sMGinventaire.getGlobalBounds().width / 2);
		sMGinventaire.setPosition(600, 120);

		sMGchoixEquipe.setString("Choix de l'equipe");
		sMGchoixEquipe.setFont(fMG);
		sMGchoixEquipe.setOrigin(sMGchoixEquipe.getGlobalBounds().height / 2, sMGchoixEquipe.getGlobalBounds().width / 2);
		sMGchoixEquipe.setPosition(150, 175);

		txDescriptionInv.setFont(fMG);
		txDescriptionInv.setOrigin(txDescriptionInv.getGlobalBounds().height / 2, txDescriptionInv.getGlobalBounds().width / 2);
		txDescriptionInv.setPosition(100, 500);
		txDescriptionInv.setFillColor(sf::Color::Black);

		txDesOption.setFont(fMG);
		txDesOption.setOrigin(txDesOption.getGlobalBounds().height / 2, txDesOption.getGlobalBounds().width / 2);
		txDesOption.setPosition(100, 500);
		txDesOption.setFillColor(sf::Color::Black);

		txInfoProfil.setFont(fMG);
		txInfoProfil.setOrigin(txDesOption.getGlobalBounds().height / 2, txDesOption.getGlobalBounds().width / 2);
		txInfoProfil.setPosition(200, 100);
		txInfoProfil.setFillColor(sf::Color::Black);

		rInv.setFillColor(sf::Color(0, 255, 0, 100));
		rInv.setSize(sf::Vector2f(51, 50));


		rOption.setFillColor(sf::Color(100, 255, 0, 100));
		rOption.setSize(sf::Vector2f(110, 50));

		rsChoixAvatar.setFillColor(sf::Color(0, 0, 0, 0));
		rsChoixAvatar.setOutlineThickness(5);
		rsChoixAvatar.setOutlineColor(sf::Color::Blue);
		rsChoixAvatar.setSize(sf::Vector2f(45, 45));

		invDepVertical = 1;
		invDepVerticalOp = 0;
		invDepLateral = 1;

		txProfil.setString("Profil");
		txProfil.setFont(fMG);
		posProfil = { 300,100 };
		txProfil.setPosition(posProfil);
		txProfil.setFillColor(sf::Color::Black);
		txAide.setString("Aide");
		txAide.setFont(fMG);
		posAide = { 300,150 };
		txAide.setPosition(posAide);
		txAide.setFillColor(sf::Color::Black);
		txQuete.setString("Quete");
		txQuete.setFont(fMG);
		posQuete = { 300,200 };
		txQuete.setPosition(posQuete);
		txQuete.setFillColor(sf::Color::Black);
		txAvatar.setString("Avatar");
		txAvatar.setFont(fMG);
		posAvatar = { 300,250 };
		txAvatar.setPosition(posAvatar);
		txAvatar.setFillColor(sf::Color::Black);
		txRetour.setString("Retour");
		txRetour.setFont(fMG);
		posRetour = { 300,300 };
		txRetour.setPosition(posRetour);
		txRetour.setFillColor(sf::Color::Black);
	};

	void UpdateMenuGame(myWindow& _window, ModeGame& _mode, Joueur& _joueur, Safarie& safari);

	void AfficheAvatar() {
		switch (iAvatar)
		{
		case 1:
			rectAvatar = {0,0,50,50};
			break;
		case 2:
			rectAvatar = { 50,0,50,50 };
			break;
		case 3:
			rectAvatar = { 100,0,50,50 };
			break;
		case 4:
			rectAvatar = { 150,0,50,50 };
			break;
		case 5:
			rectAvatar = { 200,0,50,50};
			break;
		case 6:
			rectAvatar = { 250,0,50,50 };
			break;
		case 7:
			rectAvatar = { 300,0,50,50 };
			break;
		case 8:
			rectAvatar = { 350,0,50,50 };
			break;
		case 9:
			rectAvatar = { 400,0,50,50 };
			break;
		default:
			break;
		}
		
		spAvatar.setTextureRect(rectAvatar);
	}

	void AfficheDescriptionInv(Joueur& _joueur);

	void DisplayMenuGame(myWindow& _window, ModeGame& _mode, Joueur& _joueur);
};