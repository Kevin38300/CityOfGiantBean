#include "Fontaine.h"

sf::Vector2f FontaineElemSize;

sf::Vector2f FontaineFeuPos;
sf::RectangleShape FontaineFeuShape;
sf::Vector2f FontaineEauPos;
sf::RectangleShape FontaineEauShape;
sf::Vector2f FontaineVentPos;
sf::RectangleShape FontaineVentShape;
sf::Vector2f FontaineTerrePos;
sf::RectangleShape FontaineTerreShape;

std::string NomElement, NomElementtmp;

sf::Font fontF;

sf::Text ValidationFontaine;
sf::Text PasArgentFontaine;
sf::Text ObtenuElementTexte;
sf::Text OuiTexteF;
sf::Text NonTexteF;
std::string PasDArgentF;
std::string ValidElem, validDepense;
int OuiNonF = 3;
int ValidF = 0;
int PasArgentResteF = 0;
float timerPasArgentF;

int choixElement;

void initFontaine() {

	FontaineElemSize = { 60,60 };

	FontaineFeuPos = { 580,183 };
	FontaineFeuShape.setSize(FontaineElemSize);
	FontaineFeuShape.setPosition(FontaineFeuPos);

	FontaineEauPos = { 426,315 };
	FontaineEauShape.setSize(FontaineElemSize);
	FontaineEauShape.setPosition(FontaineEauPos);

	FontaineVentPos = { 730,317 };
	FontaineVentShape.setSize(FontaineElemSize);
	FontaineVentShape.setPosition(FontaineVentPos);

	FontaineTerrePos = { 570,458 };
	FontaineTerreShape.setSize(FontaineElemSize);
	FontaineTerreShape.setPosition(FontaineTerrePos);

	choixElement = 0;

	fontF.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	ValidationFontaine.setFont(fontF);
	ValidationFontaine.setOrigin(ValidationFontaine.getGlobalBounds().height / 2, ValidationFontaine.getGlobalBounds().width / 2);
	ValidationFontaine.setPosition(150, 450);
	ValidationFontaine.setFillColor(sf::Color::Red);

	OuiTexteF.setFont(fontF);
	OuiTexteF.setOrigin(OuiTexteF.getGlobalBounds().height / 2, OuiTexteF.getGlobalBounds().width / 2);
	OuiTexteF.setPosition(300, 550);
	OuiTexteF.setFillColor(sf::Color::Red);

	NonTexteF.setFont(fontF);
	NonTexteF.setOrigin(NonTexteF.getGlobalBounds().height / 2, NonTexteF.getGlobalBounds().width / 2);
	NonTexteF.setPosition(400, 550);
	NonTexteF.setFillColor(sf::Color::Red);

	PasArgentFontaine.setFont(fontF);
	PasArgentFontaine.setOrigin(PasArgentFontaine.getGlobalBounds().height / 2, PasArgentFontaine.getGlobalBounds().width / 2);
	PasArgentFontaine.setPosition(150, 450);
	PasArgentFontaine.setFillColor(sf::Color::Red);

	PasDArgentF = "Vous n'avez pas assez d'argent!";
	ValidElem = "Vous allez change d'element. Element choisi : ";
	validDepense = "\ncela va vous coute 5 000 Gold. Voulez vous continuer ? ";


	boiteDiscussion::initBoiteDiscussion();
}

void updateFontaine(myWindow& _window, Joueur& _perso1) {

	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineFeuPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidF = 1;
		choixElement = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineVentPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidF = 1;
		choixElement = 2;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineTerrePos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidF = 1;
		choixElement = 3;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineEauPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ValidF = 1;
		choixElement = 4;
	}

	switch (choixElement) {
	case 1:
		NomElementtmp = "Feu";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Feu";
			ChgElem(_perso1, Personnage::Feu);
			_perso1.iChgElem += 1;
			ValidF = 0;
			OuiNonF = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	case 2:
		NomElementtmp = "Vent";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Vent";
			ChgElem(_perso1, Personnage::Vent);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	case 3:
		NomElementtmp = "Terre";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Terre";
			ChgElem(_perso1, Personnage::Terre);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	case 4:
		NomElementtmp = "Eau";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Eau";
			ChgElem(_perso1, Personnage::Eau);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	default:
		NomElement = "none";
		break;
	}
}

void ChgElem(Joueur& _perso1, Personnage::Elements _element) {
	if (_perso1.GetTotArgent() >= 5000) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - 5000);
		_perso1.SetElement(_element);
		_perso1.DisplayStat();
		std::cout << "Vous avez change d'element\nVous avez l'element " << NomElement << std::endl;
		PasArgentResteF = 0;
		NonRetourFontaine();
	}
	else {
		PasArgentResteF = 1;
		NonRetourFontaine();
	}
}

void displayFontaine(myWindow& _window) {
	if (ValidF == 1 || PasArgentResteF == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
	}
	if (ValidF == 1) {
		displayValidationF(_window);
	}
	PasArgentFontaine.setString(PasDArgentF);
	if (PasArgentResteF == 1) {
		timerPasArgentF += tools::GetTimeDelta();
		_window.Draw(PasArgentFontaine);
		if (timerPasArgentF >= 1.0f) {
			timerPasArgentF = 0.0f;
			PasArgentResteF = 0;
		}
	}
}

void validationFontaine(myWindow& _window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		OuiTexteF.setScale(2, 2);
		NonTexteF.setScale(1, 1);
		OuiNonF = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		OuiTexteF.setScale(1, 1);
		NonTexteF.setScale(2, 2);
		OuiNonF = 2;
	}
}

void displayValidationF(myWindow& _window) {
	OuiTexteF.setString("Oui");
	NonTexteF.setString("Non");

	if (OuiNonF == 3) {
		OuiTexteF.setScale(1, 1);
		NonTexteF.setScale(1, 1);
	}
	ValidationFontaine.setString(ValidElem + NomElementtmp + validDepense);
	_window.Draw(ValidationFontaine);
	_window.Draw(OuiTexteF);
	_window.Draw(NonTexteF);
}

void NonRetourFontaine() {
	ValidF = 0;
	choixElement = 0;
	OuiNonF = 3;
}