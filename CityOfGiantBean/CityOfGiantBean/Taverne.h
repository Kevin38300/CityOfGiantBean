#pragma once
#include "Tools.h"
#include "Joueur.h"
#include "StateMana.h"

void initTaverne();
void updateTaverne(sf::RenderWindow& _window, Joueur& _perso1);
void displayTaverne(sf::RenderWindow& _window);

void Tavernier(sf::RenderWindow& _window);

void validationTaverne(sf::RenderWindow& _window);
void displayValidationT(sf::RenderWindow& _window);
void ChgJob(Joueur& _perso1, Job _job);
void NonRetourTaverne();