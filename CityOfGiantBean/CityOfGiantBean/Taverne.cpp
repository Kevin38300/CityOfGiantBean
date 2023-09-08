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
std::string ValidationTa, ValidationTaDepense, ValidationTatmp, ValidationTaEn, ValidationTaDepenseEn, ValidationTatmpEn;
sf::Text OuiTexteT;
sf::Text NonTexteT;
int OuiNonT = 3;
int PasArgentResteT = 0;
int ValidReussiT = 0;
float timerPasArgentT = 0.0f, timerValidReussiT = 0.0f;
sf::Text PasArgentTaverne;
sf::Text ArgentRestantT;
sf::Text ObtenuClasseTexte;
std::string PasDArgentT, PasDArgentTEn;
std::string NomJob, NomJobEn;

int iPNJ = 0;
std::string stPNJ, stPNJEn;
sf::Text txPNJ;
sf::Vector2f TavernePNJsize;
sf::Vector2f TavernePNJpos;
sf::RectangleShape TavernePNJshape;

void initTaverne() {


	TavernePNJsize = {AjustResoX * 105,AjustResoY * 80 };
	TavernePNJpos = { AjustResoX * 925,AjustResoY * 530 };
	TavernePNJshape.setSize(TavernePNJsize);
	TavernePNJshape.setPosition(TavernePNJpos);
	TavernePNJshape.setFillColor(sf::Color::Red);

	JobAssassinSize = { AjustResoX * 157,AjustResoY * 119 };
	JobAssassinPos = { AjustResoX * 1519,AjustResoY * 328 };
	JobAssassinShape.setSize(JobAssassinSize);
	JobAssassinShape.setPosition(JobAssassinPos);
	JobAssassinShape.setFillColor(sf::Color::Red);

	JobGuerrierSize = { AjustResoX * 126,AjustResoY * 73 };
	JobGuerrierPos = { AjustResoX * 453,AjustResoY * 388 };
	JobGuerrierShape.setSize(JobGuerrierSize);
	JobGuerrierShape.setPosition(JobGuerrierPos);
	JobGuerrierShape.setFillColor(sf::Color::Red);

	JobClercSize = { AjustResoX * 226,AjustResoY * 85 };
	JobClercPos = { AjustResoX * 1263,AjustResoY * 880 };
	JobClercShape.setSize(JobClercSize);
	JobClercShape.setPosition(JobClercPos);
	JobClercShape.setFillColor(sf::Color::Red);

	JobMagicienSize = { AjustResoX * 117,AjustResoY * 130 };
	JobMagicienPos = { AjustResoX * 411,AjustResoY * 842 };
	JobMagicienShape.setSize(JobMagicienSize);
	JobMagicienShape.setPosition(JobMagicienPos);
	JobMagicienShape.setFillColor(sf::Color::Red);

	choixClasse = 0;
	choixJob = false;

	fontT.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	txPNJ.setFont(fontT);
	txPNJ.setOrigin(txPNJ.getGlobalBounds().height / 2, txPNJ.getGlobalBounds().width / 2);
	txPNJ.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	txPNJ.setFillColor(sf::Color::Red);

	ValidationT.setFont(fontT);
	ValidationT.setOrigin(ValidationT.getGlobalBounds().height / 2, ValidationT.getGlobalBounds().width / 2);
	ValidationT.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ValidationT.setFillColor(sf::Color::Red);

	OuiTexteT.setFont(fontT);
	OuiTexteT.setOrigin(OuiTexteT.getGlobalBounds().height / 2, OuiTexteT.getGlobalBounds().width / 2);
	OuiTexteT.setPosition(AjustResoX * 600.0f, AjustResoY * 950.0f);
	OuiTexteT.setFillColor(sf::Color::Red);

	NonTexteT.setFont(fontT);
	NonTexteT.setOrigin(NonTexteT.getGlobalBounds().height / 2, NonTexteT.getGlobalBounds().width / 2);
	NonTexteT.setPosition(AjustResoX * 700.0f, AjustResoY * 950.0f);
	NonTexteT.setFillColor(sf::Color::Red);

	PasArgentTaverne.setFont(fontT);
	PasArgentTaverne.setOrigin(PasArgentTaverne.getGlobalBounds().height / 2, PasArgentTaverne.getGlobalBounds().width / 2);
	PasArgentTaverne.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	PasArgentTaverne.setFillColor(sf::Color::Red);


	ArgentRestantT.setFont(fontT);
	ArgentRestantT.setOrigin(ArgentRestantT.getGlobalBounds().height / 2, ArgentRestantT.getGlobalBounds().width / 2);
	ArgentRestantT.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ArgentRestantT.setFillColor(sf::Color::Red);

	ObtenuClasseTexte.setFont(fontT);
	ObtenuClasseTexte.setOrigin(ObtenuClasseTexte.getGlobalBounds().height / 2, ObtenuClasseTexte.getGlobalBounds().width / 2);
	ObtenuClasseTexte.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ObtenuClasseTexte.setFillColor(sf::Color::Red);

	PasDArgentT = "Vous n'avez pas assez d'argent!";
	ValidationTa = "Vous allez change de classe: Classe : ";
	ValidationTaDepense = "\ncela va vous coute 10 000 Gold. Voulez vous continuer ?";
	stPNJ = "Bonjour et bienvenue dans la taverne ! Vous pouvez obtenir\nune classe ou en changer en parlant avec les responsables.\nVos statistiques vont augmenter selon la classe choisis. ";
	PasDArgentTEn = "You don't have enough gold!";
	ValidationTaEn = "You will change class: Class:";
	ValidationTaDepenseEn = "\nit will cost you 10,000 Gold. Do you want to continue ? ";;
	stPNJEn = "Hello and welcome to the tavern! You can get a class or \nchange it by talking with the leaders. \nYour statistics will increase depending on the class chosen.";

	tools::ChoixLangue(tools::GetTrad(), OuiTexteT, "Oui", "Yes");
	tools::ChoixLangue(tools::GetTrad(), NonTexteT, "Non", "No");
	tools::ChoixLangue(tools::GetTrad(), txPNJ, stPNJ, stPNJEn);

	boiteDiscussion::initBoiteDiscussion();
}

void updateTaverne(myWindow& _window, Joueur& _perso1) {

	if (tools::CircleRect_Collision(_perso1.persoPosition, 10, TavernePNJpos, TavernePNJsize))
		iPNJ = 1;
	else
		iPNJ = 0;
	if (tools::CircleRect_Collision(_perso1.persoPosition, 10, JobAssassinPos, JobAssassinSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 1;
	}
	if (tools::CircleRect_Collision(_perso1.persoPosition, 10, JobGuerrierPos, JobGuerrierSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 2;
	}
	if (tools::CircleRect_Collision(_perso1.persoPosition, 10, JobClercPos, JobClercSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 3;
	}
	if (tools::CircleRect_Collision(_perso1.persoPosition, 10, JobMagicienPos, JobMagicienSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidT = 1;
		choixClasse = 4;
	}
	switch (choixClasse)
	{
	case 1:
		ValidationTatmp = " Assassin";
		ValidationTatmpEn = " Murderer";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Assassin";
				NomJobEn = "Murderer";
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
		ValidationTatmpEn = " Warrior";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Guerrier";
				NomJobEn = "Warrior";
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
		ValidationTatmpEn = " Cleric";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Clerc";
				NomJobEn = "Cleric";
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
		ValidationTatmpEn = " Magician";
		validationTaverne(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (OuiNonT == 1) {
				NomJob = "Magicien";
				NomJobEn = "Magician";
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
	if (ValidT == 1 || PasArgentResteT == 1 || ValidReussiT == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		boiteDiscussion::setBoolDiscu(true);
	}
	else
	{
		boiteDiscussion::setBoolDiscu(false);
	}
	if (ValidT == 1) {
		displayValidationT(_window);
	}
	Tavernier(_window);
	PasArgentTaverne.setString(PasDArgentT);
	if (PasArgentResteT == 1) {
		timerPasArgentT += tools::GetTimeDelta();
		_window.Draw(PasArgentTaverne);
		if (timerPasArgentT >= 1.0f) {
			timerPasArgentT = 0.0f;
			PasArgentResteT = 0;
		}
	}
	if (ValidReussiT == 1) {
		timerValidReussiT += tools::GetTimeDelta();
		_window.Draw(ObtenuClasseTexte);
		_window.Draw(ArgentRestantT);
		if (timerValidReussiT >= 1.0f) {
			timerValidReussiT = 0.0f;
			ValidReussiT = 0;
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
	tools::ChoixLangue(tools::GetTrad(), ValidationT, ValidationTa + ValidationTatmp + ValidationTaDepense, ValidationTaEn + ValidationTatmpEn + ValidationTaDepenseEn);
	_window.Draw(ValidationT);
	_window.Draw(OuiTexteT);
	_window.Draw(NonTexteT);
}

void ChgJob(Joueur& _perso1, Job _job) {
	if (_perso1.GetTotArgent() >= 10000) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - 10000);
		_perso1.SetJob(_job);
		_perso1.iChgClasse += 1;
		tools::ChoixLangue(tools::GetTrad(), ObtenuClasseTexte, "Vous avez change de classe \nVous etes : " + NomJob, "You have changed classe \nYou are :" + NomJobEn);
		tools::ChoixLangue(tools::GetTrad(), ArgentRestantT, "\n\nOr restant : " + std::to_string((int)_perso1.GetTotArgent()), "\n\nGold remaining " + std::to_string((int)_perso1.GetTotArgent()));
		PasArgentResteT = 0;
		ValidReussiT = 1;
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
		_window.Draw(txPNJ);
	}
}
