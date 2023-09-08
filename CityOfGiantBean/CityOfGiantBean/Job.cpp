#include "Job.h"

Job::Job() {
	nameJob = "Villagois";
	pv = 200;
	defense = 50;
	attaque = 100;
	//argent = 0;
	mana = 50;
	endurance = 10; // /100
	vitesse = 5; // /100
}
Job::~Job() {
}
void Job::DisplayStat() {
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;
}