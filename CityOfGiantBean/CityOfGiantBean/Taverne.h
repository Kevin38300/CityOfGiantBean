#pragma once
#include "Joueur.h"
#include "stateManager.h"

void initTaverne(Joueur& _perso1);
void updateTaverne(myWindow& _window, Joueur& _perso1);
void displayTaverne(myWindow& _window);

void Tavernier(myWindow& _window);

void validationTaverne(myWindow& _window);
void displayValidationT(myWindow& _window);
void ChgJob(Joueur& _perso1, Job _job);
void NonRetourTaverne();