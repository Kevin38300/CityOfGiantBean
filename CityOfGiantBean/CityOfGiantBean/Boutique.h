#pragma once
#include "Tools.h"
#include "Joueur.h"

void loadBoutique();
void initBoutique(Joueur& _perso1);
void updateBoutique(myWindow& _window, Joueur& _perso1);
void NonRetourBoutique();
void validationShop(myWindow& _window);
void displayValidation(myWindow& _window);
void AchatArmes(Joueur& _perso1, Armes _armes);
void EquipLeger(Joueur& _perso1);
void EquipLourd(Joueur& _perso1);
void EquipBouclier(Joueur& _perso1);
void EquipEpee(Joueur& _perso1);
void EquipLance(Joueur& _perso1);
void EquipBague(Joueur& _perso1);
void DesEquipLeger(Joueur& _perso1);
void DesEquipLourd(Joueur& _perso1);
void DesEquipBouclier(Joueur& _perso1);
void DesEquipEpee(Joueur& _perso1);
void DesEquipLance(Joueur& _perso1);
void DesEquipBague(Joueur& _perso1);
void AchatArmures(Joueur& _perso1, Armures _armures);
void AchatConsos(Joueur& _perso1, Consos _consos);
void displayBoutique(myWindow& _window, Joueur& _perso1);
void Vendeur(myWindow& _window);