#include "MenuInGame.h"
#include "Joueur.h"
#include "Boutique.h"
#include "Safarie.h"

void MenuGame::UpdateMenuGame(myWindow& _window, ModeGame& _mode, Joueur& _joueur, Safarie& safari) {
	timerState += tools::GetTimeDelta();
	if (choixInv == 0 && choixOption == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && iMGchoixMenu > 0 && timerState > 0.3f) {
			iMGchoixMenu -= 1;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && iMGchoixMenu < 2 && timerState > 0.3f) {
			iMGchoixMenu += 1;
			timerState = 0.0f;
		}
		switch (iMGchoixMenu)
		{
		case 0:
			sMGchoixEquipe.setFillColor(sf::Color::Black);
			sMGinventaire.setFillColor(sf::Color::Red);
			sMGoption.setFillColor(sf::Color::Red);
			break;
		case 1:
			sMGchoixEquipe.setFillColor(sf::Color::Red);
			sMGinventaire.setFillColor(sf::Color::Black);
			sMGoption.setFillColor(sf::Color::Red);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				choixInv = 1;
				invDepVertical = 1;
				invDepLateral = 1;
				timerState = 0.0f;
			}
			break;
		case 2:
			sMGchoixEquipe.setFillColor(sf::Color::Red);
			sMGinventaire.setFillColor(sf::Color::Red);
			sMGoption.setFillColor(sf::Color::Black);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				choixOption = 1;
				invDepVerticalOp = 0;
				timerState = 0.0f;
			}
			break;
		default:
			break;
		}
	}
	if (choixOption == 1 && bProfil == false && bAide == false && bQuete == false && bAvatar == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && invDepVerticalOp > 0 && timerState > 0.3f) {
			invDepVerticalOp -= 1;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && invDepVerticalOp < 4 && timerState > 0.3f) {
			invDepVerticalOp += 1;
			timerState = 0.0f;
		}
		switch (invDepVerticalOp)
		{
		case 0:
			pOption = posProfil;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				bProfil = true;
				timerState = 0.0f;
			}
			break;
		case 1:
			pOption = posAide;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				bAide = true;
				timerState = 0.0f;
			}
			break;
		case 2:
			pOption = posQuete;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				bQuete = true;
				timerState = 0.0f;
			}
			break;
		case 3:
			pOption = posAvatar;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				bAvatar = true;
				timerState = 0.0f;
			}
			break;
		case 4:
			pOption = posRetour;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
				choixOption = 0;
				timerState = 0.0f;
			}
			break;
		default:
			break;
		}
	}
	if (choixInv == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && invDepVertical > 1 && timerState > 0.3f) {
			invDepVertical -= 1;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && invDepVertical < 5 && timerState > 0.3f) {
			invDepVertical += 1;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
			choixInv = 0;
			timerState = 0.0f;
		}
		switch (invDepVertical)
		{
		case 1:
			iInvDepEquipement = 1;
			iIvDepLoot = 0;
			iInvDepUtilitaire = 0;
			iInvDepMonstre = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 14 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		case 2:
			iInvDepEquipement = 0;
			iIvDepLoot = 1;
			iInvDepUtilitaire = 0;
			iInvDepMonstre = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 14 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		case 3:
			iInvDepEquipement = 0;
			iIvDepLoot = 0;
			iInvDepUtilitaire = 1;
			iInvDepMonstre = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 15 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		case 4:
			iInvDepEquipement = 0;
			iIvDepLoot = 0;
			iInvDepUtilitaire = 0;
			iInvDepMonstre = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 14 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		case 5:
			iInvDepEquipement = 0;
			iIvDepLoot = 0;
			iInvDepUtilitaire = 0;
			iInvDepMonstre = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && invDepLateral > 1 && timerState > 0.3f) {
				invDepLateral -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && invDepLateral < 14 && timerState > 0.3f) {
				invDepLateral += 1;
				timerState = 0.0f;
			}
			break;
		default:
			break;
		}
	}
	if (bProfil == true) {
		txInfoProfil.setString(_joueur.GetName() + "  Atk: " + std::to_string(_joueur.GetTotAttaque()) + "  Def: " + std::to_string(_joueur.GetTotDefense()) + "  PV: " + std::to_string(_joueur.GetTotPv()) + "  Mana: " + std::to_string(_joueur.GetTotMana()) + "  Argent: " + std::to_string(_joueur.GetTotArgent()) + "\n" +
			_joueur.ArmeEquiper() + _joueur.ArmureEquiper() + "  Element: " + _joueur.GetNomElem() + "\nNiv - " + std::to_string(_joueur.GetNiveau()) + " / Exp - " + std::to_string(_joueur.exp) + " / " + std::to_string(_joueur.expDemande) + "\nNombre de monstre battu :" + std::to_string(_joueur.NbMonstreBattu) +
			"\nNiveau du safari : " + std::to_string((int)safari.iZonzSafari) + "\nNombre d'ennemi battu :" + std::to_string(_joueur.NbEnnemiBattu));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
			bProfil = false;
			timerState = 0.0f;
		}
	}
	if (bAide == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
			bAide = false;
			timerState = 0.0f;
		}
	}
	if (bQuete == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
			bQuete = false;
			timerState = 0.0f;
		}
	}
	if (bAvatar == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
			bAvatar = false;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && iChoixAvatar > 0 && timerState > 0.3f) {
			iChoixAvatar -= 1;
			posRsAvatar.x -= 50.5;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && iChoixAvatar < 8 && timerState > 0.3f) {
			iChoixAvatar += 1;
			posRsAvatar.x += 50.5;
			timerState = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timerState > 0.3f) {
			switch (iChoixAvatar)
			{
			case 0:
				iAvatar = 1;
				break;
			case 1:
				iAvatar = 2;
				break;
			case 2:
				iAvatar = 3;
				break;
			case 3:
				iAvatar = 4;
				break;
			case 4:
				iAvatar = 5;
				break;
			case 5:
				iAvatar = 6;
				break;
			case 6:
				iAvatar = 7;
				break;
			case 7:
				iAvatar = 8;
				break;
			case 8:
				iAvatar = 9;
				break;
			default:
				break;
			}
			timerState = 0.0f;
		}
		AfficheAvatar();
	}
	spAvatar.setPosition(posAvatarP);
	pInvBase = sf::Vector2f(((invDepLateral * 113) + 122) * AjustResoX, ((invDepVertical * 113) + 20) * AjustResoY);
	rInv.setPosition(pInvBase);
	rOption.setPosition(pOption);
	rsChoixAvatar.setPosition(posRsAvatar);
};

void MenuGame::AfficheDescriptionInv(Joueur& _joueur) {

	switch (invDepLateral)
	{
	case 1:
		if (iInvDepEquipement == 1) {
			description = { "Potion PV : \nRestaure des points de vie d'une certaine quantite" };
			descriptionEn = { "Healing potion : \nRestores hit points of a certain quantity" };
			stQteInv = std::to_string(_joueur.SoinPvBuy);
		}
		else if (iIvDepLoot == 1) {
			description = { "Materiaux de fabrication , Fourrure : \nPermet de fabriquer des objets, se recupere apres avoir \nbattu un Loup" };
			descriptionEn = { "Manufacturing materials , Fur: \nAllows to make objects, to recover after having \nbeaten a Wolf" };
			stQteInv = std::to_string(_joueur.GetLootFourrure());
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "Filet de capture : \nPermet de capturer un monstre sous un certain pourcentage" };
			descriptionEn = { "Capture net: \nCaptures a monster below a certain percentage" };
			stQteInv = std::to_string(_joueur.GetFillet());
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : Gobelin\n" };
			descriptionEn = { "Monster : Gobelin\n" };
			stQteInv = std::to_string(_joueur.iCatchGob);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 2:
		if (iInvDepEquipement == 1) {
			description = { "Potion Mana : \nRestaure des points de mana d'une certaine quantite" };
			descriptionEn = { "Mana Potion: \nRestores mana points of a certain amount" };
			stQteInv = std::to_string(_joueur.SoinManaBuy);
		}
		else if (iIvDepLoot == 1) {
			description = { "Materiaux de fabrication , Cuire: \nPermet de fabriquer des objets, se recupere apres avoir \nbattu un Ours" };
			descriptionEn = { "Manufacturing materials , Cook: \nAllows to make objects, to be recovered after having \nbeaten a Bear" };
			stQteInv = std::to_string(_joueur.GetLootCuire());
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "Super Filet de capture : \nUn super filet de capture a un taux de capture superieur a \nun simple filet" };
			descriptionEn = { "Super Catch Net: \nA super catch net has a catch rate greater than \na single net" };
			stQteInv = std::to_string(_joueur.GetSuperFillet());
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : Orc\n" };
			descriptionEn = { "Monster : Orc\n" };
			stQteInv = std::to_string(_joueur.iCatchOrc);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 3:
		if (iInvDepEquipement == 1) {
			description = { "Bombe : \nInflige des degats a un ennemi" };
			descriptionEn = { "Bomb : \nInflicts damage on an enemy" };
			stQteInv = std::to_string(_joueur.BombeBuy);
		}
		else if (iIvDepLoot == 1) {
			description = { "Materiaux de fabrication , Cuivre : \nPermet de fabriquer des objets, se recupere apres avoir \nbattu un Gobelin" };
			descriptionEn = { "Manufacturing materials , Copper : \nAllows to manufacture objects, to be recovered after\nhaving beaten a Goblin" };
			stQteInv = std::to_string(_joueur.GetLootCuivre());
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "Argent : \nL'argent que vous possedez, il permet d'acheter des objets, de changer \nde classe ou d'elements ou bien d'autre chose" };
			descriptionEn = { "Money: \nThe money you have, it allows you to buy items, change class or\nelements or something else" };
			stQteInv = std::to_string(_joueur.GetTotArgent());
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : Loup\n" };
			descriptionEn = { "Monstre : Wolf\n" };
			stQteInv = std::to_string(_joueur.iCatchLoup);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 4:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Armure legere : \nAugmente legerement votre Resistance et moderement votre Mana\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Light Armor: \nSlightly increase your Resistance and moderately your Mana\nE: to equip / R to unequip" };
			stQteInv = std::to_string(_joueur.LegerBuy);
			if (_joueur.bLegerEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipLeger(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipLeger(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "Materiaux de fabrication , Fer : \nPermet de fabriquer des objets, se recupere apres avoir \nbattu un Orc" };
			descriptionEn = { "Manufacturing materials , Iron: \nAllows to make objects, recover after beating\nan Orc" };
			stQteInv = std::to_string(_joueur.GetLootFer());
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : Ours\n" };
			descriptionEn = { "Monstre : Bear\n" };
			stQteInv = std::to_string(_joueur.iCatchOurs);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 5:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Armure Lourde : \nAugmente largement votre Resistance\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Heavy Armor: \nGreatly increase your Resistance\nE: to equip / R to unequip" };
			stQteInv = std::to_string(_joueur.LourdBuy);
			if (_joueur.bLourdEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipLourd(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipLourd(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : GobOurs\nFusion Gobelin + Ours" };
			descriptionEn = { "Monster : GobOurs\nFusion Gobelin + Bear" };
			stQteInv = std::to_string(_joueur.iCatchGobOurs);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 6:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Bouclier : \nAugmente moderement votre Resistance et legerement votre Mana\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Shield: \nModerately increase your Resistance and slightly your Mana\nE: to equip / R to descrew" };
			stQteInv = std::to_string(_joueur.BouclierBuy);
			if (_joueur.bBouclierEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipBouclier(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipBouclier(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : GobLoup\nFusion Gobelin + Loup" };
			descriptionEn = { "Monster : GobLoup\nFusion Gobelin + Wolf" };
			stQteInv = std::to_string(_joueur.iCatchGobLoup);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 7:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Epee : \nAugmente largement votre Attaque\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Sword: \nGreatly increase your Attack\nE: to equip / R to descrew" };
			stQteInv = std::to_string(_joueur.EpeeBuy);
			if (_joueur.bEpeeEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipEpee(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipEpee(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : OursOrc\nFusion Ours + Orc" };
			stQteInv = std::to_string(_joueur.iCatchOursOrc);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 8:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Lance : \nAugmente moderement votre Attaque et legerement votre Mana\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Lance: \nModerately increase your Attack and slightly increase your Mana\nE: to equip / R to descrew" };
			stQteInv = std::to_string(_joueur.LanceBuy);
			if (_joueur.bLanceEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipLance(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipLance(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "Monstre : Louroc\nFusion Orc + Loup" };
			stQteInv = std::to_string(_joueur.iCatchLouRoc);
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 9:
		if (iInvDepEquipement == 1) {
			description = { "Equipement, Bague : \nAugmente legerement votre Attaque et moderement votre Mana\nE : pour equiper / R pour desequiper" };
			descriptionEn = { "Equipment, Ring: \nSlightly increase your Attack and moderately your Mana\nE: to equip / R to descrew" };
			stQteInv = std::to_string(_joueur.BatonBuy);
			if (_joueur.bBagueEquip == true) {
				stEquipeOuNon = "  Deja equiper";
				stEquipeOuNonEn = "Already equipped";
			}
			else
				stEquipeOuNon = "";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f) {
				EquipBague(_joueur);
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f) {
				DesEquipBague(_joueur);
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 10:
		if (iInvDepEquipement == 1) {
			description = { "Potion mysterieuse : Augmente legerement votre niveau\nE : pour utiliser" };
			descriptionEn = { "Mysterious potion: Slightly increases your level\nE: to use" };
			stQteInv = std::to_string(_joueur.iPotionMy);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && timerState > 0.3f && _joueur.iPotionMy > 0) {
				_joueur.iPotionMy -= 1;
				_joueur.Experience(_joueur.MonterNiveau());
				timerState = 0.0f;
			}
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 11:
		if (iInvDepEquipement == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 12:
		if (iInvDepEquipement == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 13:
		if (iInvDepEquipement == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	case 14:
		if (iInvDepEquipement == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iIvDepLoot == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepUtilitaire == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else if (iInvDepMonstre == 1) {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		else {
			description = { "A venir prochainement" };
			descriptionEn = { "Comming soon" };
			stQteInv = { "" };
		}
		break;
	default:
		break;
	}
}

void MenuGame::DisplayMenuGame(myWindow& _window, ModeGame& _mode, Joueur& _joueur) {
	if (_mode == ModeGame::MENU) {
		_window.Draw(MenuGameSprite);
		_window.Draw(sMGinventaire);
		_window.Draw(sMGchoixEquipe);
		_window.Draw(sMGoption);
		spAvatar.setTextureRect(rectAvatar);
		if (iMGchoixMenu == 1) {
			_window.Draw(spAvatar);
			_window.Draw(smgInv);
			if (choixInv == 1) {
				_window.Draw(rInv);
				AfficheDescriptionInv(_joueur);
				tools::ChoixLangue(tools::GetTrad(), txDescriptionInv, "Quantite : " + stQteInv + stEquipeOuNon + "\n" + description, "Quantities : " + stQteInv + stEquipeOuNonEn + "\n" + descriptionEn);
				_window.Draw(txDescriptionInv);
			}
		}
		if (iMGchoixMenu == 2) {
			_window.Draw(spAvatar);
			if (bProfil == false && bAide == false && bQuete == false && bAvatar == false) {

				_window.Draw(txProfil);
				_window.Draw(txAide);
				_window.Draw(txQuete);
				_window.Draw(txAvatar);
				_window.Draw(txRetour);
				_window.Draw(txDesOption);
				if (choixOption == 1) {
					_window.Draw(rOption);
				}
			}
			if (bProfil == true) {
				_window.Draw(txInfoProfil);
			}
			if (bAide == true) {

			}
			if (bQuete == true) {

			}
			if (bAvatar == true) {
				_window.Draw(spAvatarFull);
				_window.Draw(rsChoixAvatar);
			}
		}
	}
}
