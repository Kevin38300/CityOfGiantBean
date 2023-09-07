#include "Taverne.h"
#include "Assassin.h"
#include "Clerc.h"
#include "Guerrier.h"
#include "Magicien.h"

Assassin assassin = Assassin();
Clerc clerc = Clerc();
Guerrier guerrier = Guerrier();
Magicien magicien = Magicien();

sf::Vector2f JobAssassinPos;
sf::Vector2f JobAssassinSize;
sf::RectangleShape JobAssassinShape;
sf::Vector2f JobGuerrierPos;
sf::Vector2f JobGuerrierSize;
sf::RectangleShape JobGuerrierShape;
sf::Vector2f JobClercPos;
sf::Vector2f JobClercSize;
sf::RectangleShape JobClercShape;
sf::Vector2f JobMagicienPos;
sf::Vector2f JobMagicienSize;
sf::RectangleShape JobMagicienShape;
int choixClasse;
int classeDisplay = 0;
int validChoix;
bool choixJob;

int ValidT = 0;
int ChgReussi = 0;
sf::Font fontT;
sf::Text ValidationT;
std::string ValidationTa, ValidationTaDepense, ValidationTatmp;
sf::Text OuiTexteT;
sf::Text NonTexteT;
int OuiNonT = 3;
int PasArgentResteT = 0;
float timerPasArgentT = 0.0f;
sf::Text PasArgentTaverne;
std::string PasDArgentT;
std::string NomJob;

int iPNJ = 0;
std::string stPNJ;
sf::Text txPNJ;
sf::Vector2f TavernePNJsize;
sf::Vector2f TavernePNJpos;
sf::RectangleShape TavernePNJshape;

void initTaverne() {


	TavernePNJsize = { 50,50 };
	TavernePNJpos = { 640,330 };
	TavernePNJshape.setSize(TavernePNJsize);
	TavernePNJshape.setPosition(TavernePNJpos);

	JobAssassinSize = { 100,100 };
	JobAssassinPos = { 1060,230 };
	JobAssassinShape.setSize(JobAssassinSize);
	JobAssassinShape.setPosition(JobAssassinPos);

	JobGuerrierSize = { 100,100 };
	JobGuerrierPos = { 310, 270 };
	JobGuerrierShape.setSize(JobGuerrierSize);
	JobGuerrierShape.setPosition(JobGuerrierPos);

	JobClercSize = { 100,100 };
	JobClercPos = { 845, 560 };
	JobClercShape.setSize(JobClercSize);
	JobClercShape.setPosition(JobClercPos);

	JobMagicienSize = { 100,100 };
	JobMagicienPos = { 290,550 };
	JobMagicienShape.setSize(JobMagicienSize);
	JobMagicienShape.setPosition(JobMagicienPos);

	choixClasse = 0;
	choixJob = false;

	fontT.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	txPNJ.setFont(fontT);
	txPNJ.setOrigin(txPNJ.getGlobalBounds().height / 2, txPNJ.getGlobalBounds().width / 2);
	txPNJ.setPosition(120, 450);
	txPNJ.setFillColor(sf::Color::Red);

	ValidationT.setFont(fontT);
	ValidationT.setOrigin(ValidationT.getGlobalBounds().height / 2, ValidationT.getGlobalBounds().width / 2);
	ValidationT.setPosition(120, 450);
	ValidationT.setFillColor(sf::Color::Red);

	OuiTexteT.setFont(fontT);
	OuiTexteT.setOrigin(OuiTexteT.getGlobalBounds().height / 2, OuiTexteT.getGlobalBounds().width / 2);
	OuiTexteT.setPosition(300, 550);
	OuiTexteT.setFillColor(sf::Color::Red);

	NonTexteT.setFont(fontT);
	NonTexteT.setOrigin(NonTexteT.getGlobalBounds().height / 2, NonTexteT.getGlobalBounds().width / 2);
	NonTexteT.setPosition(400, 550);
	NonTexteT.setFillColor(sf::Color::Red);

	PasArgentTaverne.setFont(fontT);
	PasArgentTaverne.setOrigin(PasArgentTaverne.getGlobalBounds().height / 2, PasArgentTaverne.getGlobalBounds().width / 2);
	PasArgentTaverne.setPosition(150, 450);
	PasArgentTaverne.setFillColor(sf::Color::Red);

	PasDArgentT = "Vous n'avez pas assez d'argent!";
	ValidationTa = "Vous allez change de classe: Classe : ";
	ValidationTaDepense = "\ncela va vous coute 10 000 Gold. Voulez vous continuer ?";
	stPNJ = "Bonjour et bienvenue dans la taverne ! Vous pouvez obtenir\nune classe ou en changer en parlant avec les responsables.\nVos statistiques vont augmenter selon la classe choisis. ";

	OuiTexteT.setString("Oui");
	NonTexteT.setString("Non");
	txPNJ.setString(stPNJ);

	boiteDiscussion::initBoiteDiscussion();
}

void updateTaverne(myWindow& _window, Joueur& _perso1) {

	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, TavernePNJpos, TavernePNJsize))
		iPNJ = 1;
	else
		iPNJ = 0;
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, JobAssassinPos, JobAssassinSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, JobGuerrierPos, JobGuerrierSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 2;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, JobClercPos, JobClercSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 3;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, JobMagicienPos, JobMagicienSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 4;
	}
	switch (choixClasse)
	{
	case 1:
		ValidationTatmp = " Assassin";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Assassin";
				ChgJob(_perso1, assassin);
				if (ChgReussi == 1) {
					classeDisplay = 1;
					ChgReussi = 0;
				}
				if (ChgReussi == 2) {
					NonRetourTaverne();
					ChgReussi = 0;
				}
				//_perso1.SetRect({ 144,0,16,18 });
			}
			if (OuiNonT == 2) {
				NonRetourTaverne();
			}
		}
		break;
	case 2:
		ValidationTatmp = " Guerrier";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Guerrier";
				ChgJob(_perso1, guerrier);
				if (ChgReussi == 1) {
					classeDisplay = 3;
					ChgReussi = 0;
				}
				if (ChgReussi == 2) {
					NonRetourTaverne();
					ChgReussi = 0;
				}
				//_perso1.SetRect({ 0,0,16,18 });
			}
			if (OuiNonT == 2) {
				NonRetourTaverne();
			}
		}
		break;
	case 3:
		ValidationTatmp = " Clerc";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Clerc";
				ChgJob(_perso1, clerc);
				if (ChgReussi == 1) {
					classeDisplay = 2;
					ChgReussi = 0;
				}
				if (ChgReussi == 2) {
					NonRetourTaverne();
					ChgReussi = 0;
				}
				//_perso1.SetRect({ 96,0,16,18 });
			}
			if (OuiNonT == 2) {
				NonRetourTaverne();
			}
		}
		break;
	case 4:
		ValidationTatmp = " Magicien";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Magicien";
				ChgJob(_perso1, magicien);
				//_perso1.SetRect({ 48,0,16,18 });
				if (ChgReussi == 1) {
					classeDisplay = 4;
					ChgReussi = 0;
				}
				if (ChgReussi == 2) {
					NonRetourTaverne();
					ChgReussi = 0;
				}
			}
			if (OuiNonT == 2) {
				NonRetourTaverne();
			}
		}
		break;
	default:
		break;
	}
}

void displayTaverne(myWindow& _window) {
	if (ValidT == 1 || PasArgentResteT == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
	}
	if (ValidT == 1) {
		displayValidationT(_window);
	}
	//_window.draw(JobAssassinShape);
	//_window.draw(JobClercShape);
	//_window.draw(JobMagicienShape);
	//_window.draw(JobGuerrierShape);
	//_window.draw(TavernePNJshape);
	PasArgentTaverne.setString(PasDArgentT);
	if (PasArgentResteT == 1) {
		timerPasArgentT += tools::GetTimeDelta();
		_window.Draw(PasArgentTaverne);
		if (timerPasArgentT >= 1.0f) {
			timerPasArgentT = 0.0f;
			PasArgentResteT = 0;
		}
	}
}

void validationTaverne(myWindow& _window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		OuiNonT = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		OuiNonT = 2;
	}
}

void displayValidationT(myWindow& _window) {

	if (OuiNonT == 1) {
		OuiTexteT.setScale(2, 2);
		NonTexteT.setScale(1, 1);
	}
	if (OuiNonT == 2) {
		OuiTexteT.setScale(1, 1);
		NonTexteT.setScale(2, 2);
	}
	if (OuiNonT == 3) {
		OuiTexteT.setScale(1, 1);
		NonTexteT.setScale(1, 1);
	}
	ValidationT.setString(ValidationTa + ValidationTatmp + ValidationTaDepense);
	_window.Draw(ValidationT);
	_window.Draw(OuiTexteT);
	_window.Draw(NonTexteT);
}

void ChgJob(Joueur& _perso1, Job _job) {
	if (_perso1.GetTotArgent() >= 10000) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - 10000);
		_perso1.SetJob(_job);
		_perso1.DisplayStat();
		std::cout << "Vous avez change de job\nVous etes un " << NomJob << std::endl;
		_perso1.iChgClasse += 1;
		PasArgentResteT = 0;
		ChgReussi = 1;
		NonRetourTaverne();
	}
	else {
		ChgReussi = 2;
		PasArgentResteT = 1;
		NonRetourTaverne();
	}
}

void NonRetourTaverne() {
	OuiNonT = 3;
	ValidT = 0;
	choixClasse = 0;
}


void Tavernier(myWindow& _window) {
	if (iPNJ == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		txPNJ.setString(stPNJ);
		_window.Draw(txPNJ);
	}
}
