#pragma once
#include "Game.h"
#include "Tools.h"

class Joueur;
class Safarie;

class MenuGame {

	sf::Texture MenuInGameTexture, tmgInventaire, ttAvatar;

	sf::Sprite MenuGameSprite, smgInv, spAvatarFull;

	std::string description, stQteInv, stEquipeOuNon ;
	std::string descriptionEn, stEquipeOuNonEn ;

	sf::Text sMGinventaire, sMGchoixEquipe, sMGoption, txDescriptionInv, txDesOption, txProfil, txAide, txQuete, txRetour, txAvatar, txInfoProfil, txQuit, txAideDir, txAideCombat;

	sf::Font fMG;

	int iMGchoixMenu{ 1 }, choixInv{ 0 }, iAvatar{0}, iChoixAvatar{0}, choixOption{0}, iInvDepEquipement, iIvDepLoot, iInvDepUtilitaire, iInvDepMonstre, invDepVertical, invDepVerticalOp, invDepLateral;

	sf::RectangleShape rInv, rOption, rsChoixAvatar;

	sf::Vector2f pInv, pInvBase, pOption, posRsAvatar{ AjustResoX * 300, AjustResoY * 202.5f }, posDesOption, posProfil, posAide, posQuete, posRetour, posQuit, posAvatar, posAvatarP{ AjustResoX * 75, AjustResoY * 60 }, posAideCom;

	sf::Texture ttMenu, ttAideDir, ttAideCom, ttAideDirEn, ttAideComEn;
	sf::Sprite spMenu, spAideDir, spAideCom, spAideDirEn, spAideComEn;

	sf::Vector2f posAideDir, posAideCombat;

	bool bProfil{ false }, bAide{ false }, bAvatar{ false }, bQuete{ false }, BAva[7]{ false };
	int iAideMenu;
	sf::IntRect rectAvatar{ 450,0,50,50 };
public:
	float timerState{ 0.0f };
	sf::Sprite spAvatar;
	MenuGame() {};
	~MenuGame() {};

	void InitMenuGame() {

		posAideCom = sf::Vector2f(AjustResoX * 500.0f, AjustResoY * 200.0f);
		fMG.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

		ttAideCom.loadFromFile("../Ressources/Textures/MENU/commandeCombat.png");
		spAideCom.setTexture(ttAideCom);
		spAideCom.setPosition(posAideCom);
		spAideCom.setScale(1 * AjustResoX, 1 * AjustResoY);
		ttAideComEn.loadFromFile("../Ressources/Textures/MENU/commandeCombatEn.png");
		spAideComEn.setTexture(ttAideComEn);
		spAideComEn.setPosition(posAideCom);
		spAideComEn.setScale(1 * AjustResoX, 1 * AjustResoY);

		ttAideDir.loadFromFile("../Ressources/Textures/MENU/commandeDir.png");
		spAideDir.setTexture(ttAideDir);
		spAideDir.setPosition(posAideCom);
		spAideDir.setScale(1 * AjustResoX, 1 * AjustResoY);
		ttAideDirEn.loadFromFile("../Ressources/Textures/MENU/commandeDirEn.png");
		spAideDirEn.setTexture(ttAideDirEn);
		spAideDirEn.setPosition(posAideCom);
		spAideDirEn.setScale(1 * AjustResoX, 1 * AjustResoY);


		posAideCombat = sf::Vector2f(AjustResoX * 500.0f, AjustResoY * 100.0f);
		posAideDir = sf::Vector2f(AjustResoX * 1200.0f, AjustResoY * 100.0f);

		txAideCombat.setFont(fMG);
		txAideCombat.setFillColor(sf::Color::Black);
		txAideCombat.setPosition(posAideCombat);
		txAideCombat.setCharacterSize(35 * AjustReso);

		txAideDir.setFont(fMG);
		txAideDir.setFillColor(sf::Color::Black);
		txAideDir.setPosition(posAideDir);
		txAideDir.setCharacterSize(35 * AjustReso);

		MenuInGameTexture.loadFromFile("..\\Ressources\\Textures\\MENU\\MenuGame.png");
		MenuGameSprite.setTexture(MenuInGameTexture);
		MenuGameSprite.setScale(AjustReso * 1, AjustReso * 1);

		tmgInventaire.loadFromFile("..\\Ressources\\Textures\\MENU\\Inventaire.png");
		smgInv.setTexture(tmgInventaire);
		smgInv.setPosition(sf::Vector2f(AjustResoX * 207, AjustResoY * 102));
		smgInv.setScale(AjustReso * 1, AjustReso * 1);

		ttAvatar.loadFromFile("..\\Ressources\\Textures\\Logo\\AvatarProfil.png");
		spAvatarFull.setTexture(ttAvatar);
		spAvatar.setTexture(ttAvatar);
		spAvatarFull.setPosition(sf::Vector2f(AjustResoX * 300, AjustResoY * 200));
		spAvatar.setScale(AjustReso * 1, AjustReso * 1);
		spAvatarFull.setScale(AjustReso * 1, AjustReso * 1);


		sMGoption.setFont(fMG);
		sMGoption.setOrigin(sMGoption.getGlobalBounds().height / 2, sMGoption.getGlobalBounds().width / 2);
		sMGoption.setPosition(AjustResoX * 1551, AjustResoY * 58);
		tools::ChoixLangue(tools::GetTrad(), sMGoption, "Options", "Settings");
		sMGoption.setCharacterSize(35 * AjustReso);

		sMGinventaire.setFont(fMG);
		sMGinventaire.setOrigin(sMGinventaire.getGlobalBounds().height / 2, sMGinventaire.getGlobalBounds().width / 2);
		sMGinventaire.setPosition(AjustResoX * 896, AjustResoY * 58);
		tools::ChoixLangue(tools::GetTrad(), sMGinventaire, "Inventaire", "Inventory");
		sMGinventaire.setCharacterSize(35 * AjustReso);

		sMGchoixEquipe.setFont(fMG);
		sMGchoixEquipe.setOrigin(sMGchoixEquipe.getGlobalBounds().height / 2, sMGchoixEquipe.getGlobalBounds().width / 2);
		sMGchoixEquipe.setPosition(AjustResoX * 214, AjustResoY * 58);
		tools::ChoixLangue(tools::GetTrad(), sMGchoixEquipe, "Choix de l'equipe", "Team choice");
		sMGchoixEquipe.setCharacterSize(35 * AjustReso);

		txDescriptionInv.setFont(fMG);
		txDescriptionInv.setOrigin(txDescriptionInv.getGlobalBounds().height / 2, txDescriptionInv.getGlobalBounds().width / 2);
		txDescriptionInv.setPosition(AjustResoX * 150, AjustResoY * 800);
		txDescriptionInv.setFillColor(sf::Color::Black);
		txDescriptionInv.setCharacterSize(35 * AjustReso);

		txDesOption.setFont(fMG);
		txDesOption.setOrigin(txDesOption.getGlobalBounds().height / 2, txDesOption.getGlobalBounds().width / 2);
		txDesOption.setPosition(AjustResoX * 150, AjustResoY * 800);
		txDesOption.setFillColor(sf::Color::Black);
		txDesOption.setCharacterSize(35 * AjustReso);

		txInfoProfil.setFont(fMG);
		txInfoProfil.setOrigin(txDesOption.getGlobalBounds().height / 2, txDesOption.getGlobalBounds().width / 2);
		txInfoProfil.setPosition(AjustResoX * 200, AjustResoY * 150);
		txInfoProfil.setFillColor(sf::Color::Black);
		txInfoProfil.setCharacterSize(35 * AjustReso);

		rInv.setFillColor(sf::Color(0, 255, 0, 100));
		rInv.setSize(sf::Vector2f(AjustResoX * 69, AjustResoY * 70));


		rOption.setFillColor(sf::Color(100, 255, 0, 100));
		rOption.setSize(sf::Vector2f(AjustResoX * 110, AjustResoY * 50));

		rsChoixAvatar.setFillColor(sf::Color(0, 0, 0, 0));
		rsChoixAvatar.setOutlineThickness(AjustReso * 5);
		rsChoixAvatar.setOutlineColor(sf::Color::Blue);
		rsChoixAvatar.setSize(sf::Vector2f(AjustResoX * 45, AjustResoY * 45));

		invDepVertical = 1;
		invDepVerticalOp = 0;
		invDepLateral = 1;

		tools::ChoixLangue(tools::GetTrad(), txProfil, "Profil", "Profil");
		txProfil.setFont(fMG);
		posProfil = { AjustResoX * 200,AjustResoY * 150 };
		txProfil.setPosition(posProfil);
		txProfil.setFillColor(sf::Color::Black);
		txProfil.setCharacterSize(35 * AjustReso);
		tools::ChoixLangue(tools::GetTrad(), txAide, "Aide", "Help");
		txAide.setFont(fMG);
		posAide = { AjustResoX * 200,AjustResoY * 200 };
		txAide.setPosition(posAide);
		txAide.setFillColor(sf::Color::Black);
		txAide.setCharacterSize(35 * AjustReso);
		tools::ChoixLangue(tools::GetTrad(), txQuete, "Quete", "Quest");
		txQuete.setFont(fMG);
		posQuete = { AjustResoX * 200,AjustResoY * 250 };
		txQuete.setPosition(posQuete);
		txQuete.setFillColor(sf::Color::Black);
		txQuete.setCharacterSize(35 * AjustReso);
		tools::ChoixLangue(tools::GetTrad(), txAvatar, "Avatar", "Avatar");
		txAvatar.setFont(fMG);
		posAvatar = { AjustResoX * 200,AjustResoY * 300 };
		txAvatar.setPosition(posAvatar);
		txAvatar.setFillColor(sf::Color::Black);
		txAvatar.setCharacterSize(35 * AjustReso);
		tools::ChoixLangue(tools::GetTrad(), txRetour, "Retour", "Back");
		txRetour.setFont(fMG);
		posRetour = { AjustResoX * 200,AjustResoY * 350 };
		txRetour.setPosition(posRetour);
		txRetour.setFillColor(sf::Color::Black);
		txRetour.setCharacterSize(35 * AjustReso);
		tools::ChoixLangue(tools::GetTrad(), txQuit, "Quitter le jeu", "Exit game");
		txQuit.setFont(fMG);
		posQuit = { AjustResoX * 200,AjustResoY * 400 };
		txQuit.setPosition(posQuit);
		txQuit.setFillColor(sf::Color::Black);
		txQuit.setCharacterSize(35 * AjustReso);
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