#pragma once
#include "Tools.h"
#include "Game.h"

class Joueur;
class Safarie;
class Aventure;
class Hotel
{
private:
	sf::RectangleShape rsPNJquete, rsPNJskill, rsPNJversus, rsPNJ1, rsPNJ2,rsPNJ3, rsOnglet, rsDepQuete;

	sf::CircleShape csSkill1, csSkill21, csSkill22, csSkill31, csSkill32, csSkill33, csSkill34, csSkill41, csSkill42;

	sf::Vector2f posrsPNJquete, posrsPNJskill, posrsPNJversus, posrsPNJ1, posrsPNJ2, posrsPNJ3, posText, posSkill1, posSkill21, posSkill22, posSkill31, posSkill32, posSkill33, posSkill34, posSkill41, posSkill42, posrsOnglet{ 190,60 }, posrsDepQuete{100,100};

	sf::Vector2f rsize{ 50,50 };

	sf::Font fontS;

	bool bPNJBase, bReset, bPNJquete, bPNJskill, bPNJversus, bPNJ1, bPNJ2, bPNJ3, bChoixAction{ false }, bChoixAction2{ false }, bChoixAction3{ false }, bQLieux{ false }, bQSafari{ false }, bQAventure{ false }, bQL1{false}, bQL2{false}, bQL3{false}, bQL4{false}, bQS1{false}, bQS2{false}, bQS3{false}, bQS4{false}, bQA1{false}, bQA2{false}, bQA3{false}, bQA4{false};

	std::string stBasePNJ, stReponse1, stReponse2, stReponse3, stReponseBase, stDescSkillTree, stDebutDecr, stDecrValid, stPasPoint, stPasNiveau, stInfoValid, stInfoQuete;
	std::string stBasePNJEn, stReponse1En, stReponse2En, stReponse3En, stReponseBaseEn, stDescSkillTreeEn, stDebutDecrEn, stDecrValidEn, stPasPointEn, stPasNiveauEn, stInfoValidEn, stInfoQueteEn;

	sf::Text txBasePNJ, txReponse1, txReponse2, txReponse3, txReponseBase, txDetailReponse, txDescSkillTree, txDescQuete, txQFontaine, txQQuit, txQTaverne, txQShop, txQForge, txQChasseur, txQPasDeQuartier, txQCapture, txQElevation, txQElimination, txQDetrousseur, txQBoss, txQEtage, txQRetour, txInfoQuete, txLevelUpH;

	float timerChoixActionH{0.0f}, timerSkill{ 0.0f };
	float timerState{ 0.0f };
	int choixActionH{ 0 }, choixActionH2{ 0 }, choixActionH3{ 0 }, iSkill124{ 3 }, iSkill3{ 0 }, iDepOnglet{ 0 }, iVertiOnglet{ 0 };

public:
	
	void initSkillTree();
	void initQuete();
	void initHotel();
	void update(Joueur& _perso1, ModeGame& _modeGame, Safarie& safarie, Aventure& aventure);
	void displayHotel(myWindow& _window, ModeGame& _modeGame, Joueur& _perso1);
	void ChoixActionPNJ1();
	void ChoixActionPNJQuete();
	void ChoixActionPNJSkill();
	void displaySkillTree(myWindow& _window, Joueur& _perso1);
	void displayQuete(myWindow& _window, Joueur& _perso1);
	void ResetSkill(Joueur& _perso1);
};
