#pragma once
#include "Job.h"

class Magicien :   public Job
{
public:
	Magicien();//constructeur 1
	void ChangeStatNiveau(Magicien _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse);
	void DisplayStat();
	void AfficheStatAv(myWindow& _window, sf::Text texte);
};

