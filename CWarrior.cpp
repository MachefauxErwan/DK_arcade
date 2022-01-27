#include "CWarrior.h"

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_attack de la classe CWarrior
avec le param�tre de cette m�thode
@p_attack entier permetant d'innitialiser le membre m_attack
*/
void CWarrior::setm_attack(int p_attack)
{
	m_attack = p_attack;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_shield de la classe CWarrior
avec le param�tre de cette m�thode
@p_shield entier permetant d'innitialiser le membre m_shield
*/
void CWarrior::setm_shield(int p_shield)
{
	m_shield = p_shield;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_NbTourProtection de la classe CWarrior
avec le param�tre de cette m�thode
@p_NbTourProtection entier permetant d'innitialiser le membre m_NbTourProtection
*/
void CWarrior::setm_NbTourProtection(int p_NbTourProtection)
{
	if (p_NbTourProtection >= 0 && p_NbTourProtection <= 3)
	{
		m_NbTourProtection = p_NbTourProtection;
	}
	else
	{
		std::cerr << "Error setm_NbTourProtection : p_NbTourProtection inferieur a 0 ou p_NbTourProtection superieur a 3" << std::endl;
		m_NbTourProtection = 0;
	}

}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_attack de la classe CWarrior
*/
int CWarrior::getm_attack()
{
	return m_attack;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_shield de la classe CWarrior
*/
int CWarrior::getm_shield()
{
	return m_shield;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_NbTourProtection de la classe CWarrior
*/
int CWarrior::getm_NbTourProtection()
{
	return m_NbTourProtection;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_weapon de la classe CWarrior
avec le param�tre de cette m�thode
@p_epee pointeur sur l'objet CSword permetant d'innitialiser le membre m_weapon;
*/
void CWarrior::setm_weapon(CSword * p_epee)
{
	m_weapon = p_epee;
}

/*Cette m�thode affiche sur la console le menu des 
actions du personnage pendant son tour de jeu.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CWarrior::action(CCharacter *p_enemy)
{
	int menu;
	if (((CSword*)m_weapon)->isBroken())
	{
		std::cout << "taper 1 :Attaque a main nue" << std::endl;
		std::cout << "taper 2 :defend" << std::endl;
		std::cout << "taper 3 :repare l'arme" << std::endl;
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
			std::cout << "defend" << std::endl;
			defend();
			break;
		}
		case 3:
		{
			std::cout << "repare l'arme" << std::endl;
			repair();
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
		std::cout << "taper 2 :Attaque avec epee" << std::endl;
		std::cout << "taper 3 :defend" << std::endl;
		std::cout << "taper 4 :repare l'arme" << std::endl;
		std::cin >> menu;

		switch (menu)
		{
		case 1: {
			std::cout << "Attaque a main nue" << std::endl;
			unarmedAttack(p_enemy);
			break;
		}
		case 2: {
			std::cout << "Attaque avec epee" << std::endl;
			armedAttack(p_enemy);
			break;
		}
		case 3:
		{
			std::cout << "defend" << std::endl;
			defend();
			break;
		}
		case 4:
		{
			std::cout << "repare l'arme" << std::endl;
			repair();
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
void CWarrior::unarmedAttack(CCharacter *p_enemy)
{
	std::cout << "dommage a main nue " << ((int)(getm_attack() * 0.66)) << std::endl;
	p_enemy->applyDamage((int)(getm_attack() * 0.66));
}
/*Cette m�thode calcule les dommages avec arme du personnage.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CWarrior::armedAttack(CCharacter *p_enemy)
{
	if (m_weapon->criticalStrike())
	{
		std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << ((int)(((getm_attack() + m_weapon->getm_dommage()) * 0.75) * 2)) << std::endl;
		p_enemy->applyDamage((int)((getm_attack() + m_weapon->getm_dommage()) * 0.75) * 2);
		attack();
	}
	else
	{
		std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << ((int)((getm_attack() + m_weapon->getm_dommage()) * 0.75)) << std::endl;
		p_enemy->applyDamage((int)((getm_attack() + m_weapon->getm_dommage()) * 0.75));
		attack();
	}

}

/*Cette m�thode applique les dommages au personnage.
@p_damage entier permetant d'innitialiser les dommages.
*/
void CWarrior::applyDamage(int p_damage)
{
	if (dodge())
	{
		std::cout << getm_nom() << " a eviter l'attaque" << std::endl;
	}
	else
	{
		std::cout << "dommage recu " << (p_damage) << std::endl;
		if (getm_NbTourProtection() == 0)
		{
			setm_hp(getm_hp() - p_damage);
		}
		else
		{
			std::cout << "dommage reduit " << (0.25 * getm_shield()) << std::endl;
			setm_hp(getm_hp() - (p_damage - ((int)(0.25 * getm_shield()))));
			setm_NbTourProtection(getm_NbTourProtection() - 1);
		}
	}
}

/*Cette m�thode permet d'utiliser l'�p�e.*/
void CWarrior::attack()
{
	std::cout << "l'epee a ete utiliser" << std::endl;
	((CSword*)m_weapon)->use();
}

/*Cette m�thode permet d'obtenir une r�duction des d�gats 
pendant un nombre de tour al�atoire entre 1 � 3 tour.*/
void CWarrior::defend()
{
	srand((unsigned)time(0));
	int nombre_aleatoire = 0;
	nombre_aleatoire = 1 + rand() % 3;
	setm_NbTourProtection(nombre_aleatoire);
	if (nombre_aleatoire > 1)
	{
		std::cout << "Protection pendant " << getm_NbTourProtection() << " tours : " << std::endl;
	}
	else
	{
		std::cout << "Protection pendant " << getm_NbTourProtection() << " tour : " << std::endl;
	}

}

/*Cette m�thode permet de r�parer l'�p�e.
- si l'�p�e a �t� cass� pr�cedement la valeur de la durabilit� de l'arme montera de 1
- si l'�p�e n'a pas �t� cass� pr�cedement la valeur de la 
durabilit� de l'arme montera  d'un entier entre 3 � 15 sans d�passer sa durabilit� maximun.
*/
void CWarrior::repair()
{
	srand((unsigned)time(0));
	int nombre_aleatoire = 0;
	if (((CSword*)m_weapon)->isBroken() == true)
	{
		((CSword*)m_weapon)->setm_durability((((CSword*)m_weapon)->getm_durability()) + 1);
	}
	else
	{

		if (((CSword*)m_weapon)->getm_durabilityMax() < ((CSword*)m_weapon)->getm_durability())
		{
			nombre_aleatoire = 3 + rand() % 15;
			((CSword*)m_weapon)->setm_durability((((CSword*)m_weapon)->getm_durability()) + nombre_aleatoire);
		}
		else
		{
			std::cout << " votre arme est d�ja r�parer au maximun " << std::endl;
		}
	}


}

/*Cette m�thode est le constructeur surcharg� de la classe.
Elle initialise les membres proteg�s de la classe CWarrior
avec les diff�rents param�tres de cette m�thode
@p_nom string permetant d'innitialiser le membre m_nom
@p_hpMax entier permetant d'innitialiser le membre m_hpMax
@arme pointeur sur l'objet CSword permetant d'innitialiser le membre m_weapon;
@p_dodge r�el permetant d'innitialiser le membre m_dodge
@p_attack entier permetant innitialiser le membre m_attack
@p_shield entier permetant innitialiser le membre m_shield
*/
CWarrior::CWarrior(std::string p_nom, int p_hpMax, CSword *arme, float p_dodge, int p_attack, int p_shield) 
{
	
	setm_nom(p_nom);
	setm_hpMax(p_hpMax);
	setm_weapon(arme);
	setm_hp(p_hpMax + arme->getm_bonus());
	setm_dodge(p_dodge);
	setm_attack(p_attack);
	setm_shield(p_shield);
	setm_NbTourProtection(0);
	//((CSword*) m_weapon)
}

CWarrior::~CWarrior()
{
}
