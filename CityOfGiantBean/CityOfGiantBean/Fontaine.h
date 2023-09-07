#pragma once
#include "Joueur.h"
#include "stateManager.h"

void initFontaine();
void updateFontaine(myWindow& _window, Joueur& _perso1);
void displayFontaine(myWindow& _window);
void validationFontaine(myWindow& _window);
void displayValidationF(myWindow& _window);
void ChgElem(Joueur& _perso1, Personnage::Elements _element);
void NonRetourFontaine();