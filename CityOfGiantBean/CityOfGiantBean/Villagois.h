#pragma once
#include "Job.h"

class Villagois :  public Job
{
public:

	Villagois();//constructeur 1
	void ChangeStatNiveau(Villagois _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse);
	void DisplayStat();
	void AfficheStatAv(myWindow& _window, sf::Text texte);
	void SetStatVillagois(int _pv, int _mana, int _atk, int _def, int _endurance, int _vitesse);
};

