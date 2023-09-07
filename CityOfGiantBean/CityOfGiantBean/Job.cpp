#include "Job.h"

Job::Job() {
	nameJob = "Default";
	pv = 0;
	defense = 0;
	attaque = 0;
	//argent = 0;
	mana = 0;
	endurance = 0; // /100
	vitesse = 0; // /100
}
Job::~Job() {
}
void Job::DisplayStat() {
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;
}