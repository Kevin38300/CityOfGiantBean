#pragma once
#include "Job.h"

class Assassin : public Job
{
public:
	Assassin();//constructeur 1
	void ChangeStatNiveau(Assassin _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse);
	void DisplayStat();
	void AfficheStatAv(myWindow& _window, sf::Text texte);

};