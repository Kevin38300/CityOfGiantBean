#include "Menu.h"
#include "Game.h"

int main() {

	myWindow window("City_Of_Giant_Bean", sf::Vector2u(GetSystemMetrics(SM_CXFULLSCREEN), (GetSystemMetrics(SM_CYFULLSCREEN) + 63)));
	stateManager* State = new stateManager(new Menu(StateMenu::MENU, window), window);
	tools::SetChoixMu(0);
	tools::SetTrad(0);
	tools::SetFirstInM(false);
	//music::SetVolSonMusBase(0.0f, 0.f);
	music::SetVolSonMusBase(50.0f, 60.f);
	//window.ToggleFullscreen();
	while (!window.IsDone())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
		{
			window.ToggleFullscreen();
		}
		tools::restartClock();

		//update and request
		window.Update();
		State->RequestUpdate(window);
		State->RequestUpdateEvent(window);

		//draw and request
		window.BeginDraw();
		State->RequestDraw(window);

		window.EndDraw();

	}
}
