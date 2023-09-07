#pragma once
#include "Tools.h"
#include "Joueur.h"
#include "StateMana.h"

void initFontaine();
void updateFontaine(sf::RenderWindow& _window, Joueur& _perso1);
void displayFontaine(sf::RenderWindow& _window);
void validationFontaine(sf::RenderWindow& _window);
void displayValidationF(sf::RenderWindow& _window);
void ChgElem(Joueur& _perso1, Personnage::Elements _element);
void NonRetourFontaine();