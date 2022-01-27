#include "CArcher.h"

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_agility de la classe CArcher
avec le param�tre de cette m�thode
@p_agility r�el permetant d'innitialiser le membre m_agility
*/
void CArcher::setm_agility(float p_agility)
{
	m_agility = p_agility;
}

/*Cette m�thode est un getter()
Elle retourne un r�el du membre proteg� m_agility de la classe CArcher
*/
float CArcher::getm_agility()
{
	return m_agility;
}

/*Cette m�thode affiche sur la console le menu des
actions du personnage pendant son tour de jeu.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CArcher::action(CCharacter * p_enemy)
{
	int menu;
	if (((CBow*)m_weapon)->haveArrows())
	{
		std::cout << "taper 1 :Attaque a main nue" << std::endl;
		std::cout << "taper 2 :Decocher une fleche" << std::endl;
		std::cout << "taper 3 :Aide a la visee" << std::endl;
		std::cin >> menu;

		switch (menu)
		{
		case 1: {
			std::cout << "Attaque a main nue" << std::endl;
			unarmedAttack(p_enemy);
			break;
		}
		case 2: {

			std::cout << "Decocher une fleche" << std::endl;
			armedAttack(p_enemy);
			break;
		}
		case 3:
		{
			std::cout << "Aide a la visee activee" << std::endl;
			aim();
			break;
		}
		default:
		{
			std::cout << "passe son tour" << std::endl;
		}
		}
	}
	else
	{
		std::cout << "taper 1 :Attaque a main nue" << std::endl;
		std::cout << "taper 2 :Aide a la visee" << std::endl;
		std::cin >> menu;

		switch (menu)
		{
		case 1: {
			std::cout << "Attaque a main nue" << std::endl;
			unarmedAttack(p_enemy);
			break;
		}
		case 2:
		{
			std::cout << "Aide a la visee activee" << std::endl;
			aim();
			break;
		}
		default:
		{
			std::cout << "passe son tour" << std::endl;
		}
		}
	}

	std::cout << "" << std::endl;
}

/*Cette m�thode calcule les dommages sans arme du personnage.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CArcher::unarmedAttack(CCharacter * p_enemy)
{
	std::cout << "dommage a main nue " << (getm_agility() * 0.50) << std::endl;
	p_enemy->applyDamage((int)(getm_agility() * 0.50));
}

/*Cette m�thode calcule les dommages avec arme du personnage.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CArcher::armedAttack(CCharacter * p_enemy)
{
	if (m_weapon->criticalStrike())
	{
		if (m_aimingAid == true)
		{
			std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << (int)(((((getm_agility()*1.33) + m_weapon->getm_dommage())) * 0.90) * 2) << std::endl;
			p_enemy->applyDamage((int)(((getm_agility()*1.33) + m_weapon->getm_dommage()) * 0.90) * 2);
			((CBow*)m_weapon)->setm_nbArrow(((CBow*)m_weapon)->getm_nbArrow() - 1);
			m_aimingAid = false;
		}
		else
		{
			std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << (int)((((getm_agility() + m_weapon->getm_dommage())) * 0.90) * 2) << std::endl;
			p_enemy->applyDamage((int)(((getm_agility() + m_weapon->getm_dommage()) * 0.90) * 2));
			((CBow*)m_weapon)->setm_nbArrow(((CBow*)m_weapon)->getm_nbArrow() - 1);
		}
	}
	else {

		if (m_aimingAid == true)
		{
			std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << ((int)(((getm_agility()*1.33) + m_weapon->getm_dommage())) * 0.90) << std::endl;
			p_enemy->applyDamage((int)(((getm_agility()*1.33) + m_weapon->getm_dommage()) * 0.90));
			((CBow*)m_weapon)->setm_nbArrow(((CBow*)m_weapon)->getm_nbArrow() - 1);
			m_aimingAid = false;
		}
		else
		{
			std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << ((int)((getm_agility() + m_weapon->getm_dommage())) * 0.90) << std::endl;
			p_enemy->applyDamage((int)((getm_agility() + m_weapon->getm_dommage()) * 0.90));
			((CBow*)m_weapon)->setm_nbArrow(((CBow*)m_weapon)->getm_nbArrow() - 1);
		}
	}
}

/*Cette m�thode applique les dommages au personnage.
@p_damage entier permetant d'innitialiser les dommages.
*/
void CArcher::applyDamage(int p_damage)
{
	if (dodge())
	{
		std::cout << getm_nom() << " a eviter l'attaque" << std::endl;
	}
	else
	{
		std::cout << "dommage recu " << (p_damage) << std::endl;
		setm_hp(getm_hp() - p_damage);
	}

}

/*Cette m�thode permet � l'archer d'obtenir un bonus de d�gats.*/
void CArcher::aim()
{
	m_aimingAid = true;
}

/*Cette m�thode est le constructeur surcharg� de la classe.
Elle initialise les membres proteg�s de la classe CWarrior
avec les diff�rents param�tres de cette m�thode
@p_nom string permetant d'innitialiser le membre m_nom
@p_hpMax entier permetant d'innitialiser le membre m_hpMax
@arc pointeur sur l'objet CBow permetant d'innitialiser le membre m_weapon;
@p_dodge r�el permetant d'innitialiser le membre m_dodge
@p_agility r�el permetant innitialiser le membre m_agility
*/
CArcher::CArcher(std::string p_nom, int p_hpMax, CBow * arc, float p_dodge, float p_agility) 
{
	setm_nom(p_nom);
	setm_hpMax(p_hpMax);
	setm_weapon(arc);
	setm_hp(p_hpMax + arc->getm_bonus());
	setm_dodge(p_dodge);
	setm_agility(p_agility);
	m_aimingAid = false;
}


CArcher::~CArcher()
{

}
