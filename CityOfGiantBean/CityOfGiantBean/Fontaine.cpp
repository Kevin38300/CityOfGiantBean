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

std::string NomElement{ "none" }, NomElementtmp{ "none" }, NomElementEn{ "none" }, NomElementtmpEn{ "none" };

sf::Font fontF;

sf::Text ValidationFontaine;
sf::Text PasArgentFontaine;
sf::Text ArgentRestant;
sf::Text ObtenuElementTexte;
sf::Text OuiTexteF;
sf::Text NonTexteF;
std::string PasDArgentF, PasDArgentFEn;
std::string ValidElem, validDepense, ValidElemEn, validDepenseEn;
int OuiNonF = 3;
int ValidF = 0;
int ValidReussi = 0;
int PasArgentResteF = 0;
float timerPasArgentF{ 0.0f }, timerValidResussi{ 0.0f };

int choixElement;

void initFontaine() {

	FontaineElemSize = { AjustResoX * 93,AjustResoY * 80 };

	FontaineFeuPos = { AjustResoX * 844,AjustResoY * 285 };
	FontaineFeuShape.setSize(FontaineElemSize);
	FontaineFeuShape.setPosition(FontaineFeuPos);

	FontaineEauPos = { AjustResoX * 627,AjustResoY * 485 };
	FontaineEauShape.setSize(FontaineElemSize);
	FontaineEauShape.setPosition(FontaineEauPos);

	FontaineVentPos = { AjustResoX * 1070,AjustResoY * 489 };
	FontaineVentShape.setSize(FontaineElemSize);
	FontaineVentShape.setPosition(FontaineVentPos);

	FontaineTerrePos = { AjustResoX * 845,AjustResoY * 711 };
	FontaineTerreShape.setSize(FontaineElemSize);
	FontaineTerreShape.setPosition(FontaineTerrePos);

	choixElement = 0;

	fontF.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	ValidationFontaine.setFont(fontF);
	ValidationFontaine.setOrigin(ValidationFontaine.getGlobalBounds().height / 2, ValidationFontaine.getGlobalBounds().width / 2);
	ValidationFontaine.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ValidationFontaine.setFillColor(sf::Color::Black);

	OuiTexteF.setFont(fontF);
	OuiTexteF.setOrigin(OuiTexteF.getGlobalBounds().height / 2, OuiTexteF.getGlobalBounds().width / 2);
	OuiTexteF.setPosition(AjustResoX * 600.0f, AjustResoY * 950.0f);
	OuiTexteF.setFillColor(sf::Color::Red);

	NonTexteF.setFont(fontF);
	NonTexteF.setOrigin(NonTexteF.getGlobalBounds().height / 2, NonTexteF.getGlobalBounds().width / 2);
	NonTexteF.setPosition(AjustResoX * 700.0f, AjustResoY * 950.0f);
	NonTexteF.setFillColor(sf::Color::Red);

	PasArgentFontaine.setFont(fontF);
	PasArgentFontaine.setOrigin(PasArgentFontaine.getGlobalBounds().height / 2, PasArgentFontaine.getGlobalBounds().width / 2);
	PasArgentFontaine.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	PasArgentFontaine.setFillColor(sf::Color::Black);

	ArgentRestant.setFont(fontF);
	ArgentRestant.setOrigin(ArgentRestant.getGlobalBounds().height / 2, ArgentRestant.getGlobalBounds().width / 2);
	ArgentRestant.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ArgentRestant.setFillColor(sf::Color::Black);

	ObtenuElementTexte.setFont(fontF);
	ObtenuElementTexte.setOrigin(ObtenuElementTexte.getGlobalBounds().height / 2, ObtenuElementTexte.getGlobalBounds().width / 2);
	ObtenuElementTexte.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ObtenuElementTexte.setFillColor(sf::Color::Black);

	PasDArgentF = "Vous n'avez pas assez d'argent!";
	ValidElem = "Vous allez change d'element. Element choisi : ";
	validDepense = "\ncela va vous coute 5 000 Gold. Voulez vous continuer ? ";
	PasDArgentFEn = "You don't have enough gold!";
	ValidElemEn = "You will change element. Element chosen: ";
	validDepenseEn = "\nit will cost you 5,000 Gold. Do you want to continue ? ";


	boiteDiscussion::initBoiteDiscussion();
}

void updateFontaine(myWindow& _window, Joueur& _perso1) {

	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineFeuPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ValidF = 1;
		choixElement = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineVentPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ValidF = 1;
		choixElement = 2;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineTerrePos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ValidF = 1;
		choixElement = 3;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, FontaineEauPos, FontaineElemSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ValidF = 1;
		choixElement = 4;
	}

	switch (choixElement) {
	case 1:
		NomElementtmp = "Feu";
		NomElementtmpEn = "Fire";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Feu";
			NomElementEn = "Fire";
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
		NomElementtmpEn = "Wind";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Vent";
			NomElementEn = "Wind";
			ChgElem(_perso1, Personnage::Vent);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	case 3:
		NomElementtmp = "Terre";
		NomElementtmpEn = "Earth";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Terre";
			NomElementEn = "Earth";
			ChgElem(_perso1, Personnage::Terre);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	case 4:
		NomElementtmp = "Eau";
		NomElementtmpEn = "Water";
		validationFontaine(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 1) {
			NomElement = "Eau";
			NomElementEn = "Water";
			ChgElem(_perso1, Personnage::Eau);
			_perso1.iChgElem += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNonF == 2) {
			NonRetourFontaine();
		}
		break;
	default:
		break;
	}
}

void ChgElem(Joueur& _perso1, Personnage::Elements _element) {
	if (_perso1.GetTotArgent() >= 5000) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - 5000);
		_perso1.SetElement(_element);
		tools::ChoixLangue(tools::GetTrad(), ObtenuElementTexte, "Vous avez change d'element\nVous avez l'element " + NomElement, "You have changed element\nYou have the element" + NomElementEn);
		tools::ChoixLangue(tools::GetTrad(), ArgentRestant, "\n\nOr restant : " + std::to_string((int)_perso1.GetTotArgent()), "\n\nGold remaining " + std::to_string((int)_perso1.GetTotArgent()));
		//_perso1.DisplayStat();
		PasArgentResteF = 0;
		ValidReussi = 1;
		NonRetourFontaine();
		if (save::getTutoNb() == 9)
			save::setTutoNb(10);
	}
	else {
		PasArgentResteF = 1;
		NonRetourFontaine();
	}
}

void displayFontaine(myWindow& _window) {
	/*_window.Draw(FontaineFeuShape);
	_window.Draw(FontaineEauShape);
	_window.Draw(FontaineTerreShape);
	_window.Draw(FontaineVentShape);*/
	if (ValidF == 1 || PasArgentResteF == 1 || ValidReussi == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		boiteDiscussion::setBoolDiscu(true);
	}
	else
	{
		boiteDiscussion::setBoolDiscu(false);
	}
	if (ValidF == 1) {
		displayValidationF(_window);
	}
	tools::ChoixLangue(tools::GetTrad(), PasArgentFontaine, PasDArgentF, PasDArgentFEn);
	if (PasArgentResteF == 1) {
		timerPasArgentF += tools::GetTimeDelta();
		_window.Draw(PasArgentFontaine);
		if (timerPasArgentF >= 1.0f) {
			timerPasArgentF = 0.0f;
			PasArgentResteF = 0;
		}
	}
	if (ValidReussi == 1) {
		timerValidResussi += tools::GetTimeDelta();
		_window.Draw(ObtenuElementTexte);
		_window.Draw(ArgentRestant);
		if (timerValidResussi >= 1.0f) {
			timerValidResussi = 0.0f;
			ValidReussi = 0;
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
	tools::ChoixLangue(tools::GetTrad(), OuiTexteF, "Oui", "Yes");
	tools::ChoixLangue(tools::GetTrad(), NonTexteF, "Non", "No");

	if (OuiNonF == 3) {
		OuiTexteF.setScale(1, 1);
		NonTexteF.setScale(1, 1);
	}
	tools::ChoixLangue(tools::GetTrad(), ValidationFontaine, ValidElem + NomElementtmp + validDepense, ValidElemEn + NomElementtmpEn + validDepenseEn);
	_window.Draw(ValidationFontaine);
	_window.Draw(OuiTexteF);
	_window.Draw(NonTexteF);
}

void NonRetourFontaine() {
	ValidF = 0;
	choixElement = 0;
	OuiNonF = 3;
}