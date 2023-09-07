#pragma once
#include "Job.h"

class Guerrier :  public Job
{
public:
	Guerrier();//constructeur 1
	void ChangeStatNiveau(Guerrier _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse);
	void DisplayStat();
	void AfficheStatAv(myWindow& _window, sf::Text texte);
};

