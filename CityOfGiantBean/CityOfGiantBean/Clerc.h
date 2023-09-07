#pragma once
#include "Job.h"

class Clerc :   public Job
{
public:
	Clerc();//constructeur 1
	void ChangeStatNiveau(Clerc _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse);
	void DisplayStat();
	void AfficheStatAv(myWindow& _window, sf::Text texte);
};

