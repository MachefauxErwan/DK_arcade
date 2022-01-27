#include "CMage.h"

/*Cette méthode est un setter()
Elle initialise le membre protegé m_intellect de la classe CMage
avec le paramètre de cette méthode
@p_intellect entier permetant d'innitialiser le membre m_intellect
*/
void CMage::setm_intellect(int p_intellect)
{
	m_intellect = p_intellect;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_mana de la classe CMage
avec le paramètre de cette méthode
@p_mana entier permetant d'innitialiser le membre m_mana
*/
void CMage::setm_mana(int p_mana)
{
	m_mana = p_mana;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_manaMax de la classe CMage
avec le paramètre de cette méthode
@p_manaMax entier permetant d'innitialiser le membre m_manaMax
*/
void CMage::setm_manaMax(int p_manaMax)
{
	m_manaMax = p_manaMax;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_intellect de la classe CMage
*/
int CMage::getm_intellect()
{
	return m_intellect;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_mana de la classe CMage
*/
int CMage::getm_mana()
{
	return m_mana;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_manaMax de la classe CMage
*/
int CMage::getm_manaMax()
{
	return m_manaMax;
}

/*Cette méthode affiche sur la console le menu des
actions du personnage pendant son tour de jeu.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CMage::action(CCharacter * p_enemy)
{
	int menu;
	if (haveMana())
	{
		std::cout << "taper 1 :Attaque a main nue" << std::endl;
		std::cout << "taper 2 :Attaque avec le baton" << std::endl;
		std::cout << "taper 3 :recuperer du mana" << std::endl;
		std::cin >> menu;

		switch (menu)
		{
		case 1: {
			std::cout << "Attaque a main nue" << std::endl;
			unarmedAttack(p_enemy);
			break;
		}
		case 2: {
			std::cout << "Attaque avec le baton" << std::endl;
			armedAttack(p_enemy);
			break;
		}
		case 3:
		{
			std::cout << "recuperer du mana" << std::endl;
			ManaRegeneration();
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
		std::cout << "taper 2 :recuperer du mana" << std::endl;
		std::cin >> menu;


		switch (menu)
		{
		case 1: {
			std::cout << "Attaque a main nue" << std::endl;
			unarmedAttack(p_enemy);
			break;
		}
		case 2: {
			std::cout << "recuperer du mana" << std::endl;
			ManaRegeneration();
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

/*Cette méthode calcule les dommages sans arme du personnage.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CMage::unarmedAttack(CCharacter * p_enemy)
{
	std::cout << "dommage a main nue " << ((int)(getm_intellect() / 3)) << std::endl;
	p_enemy->applyDamage(((int)(getm_intellect() / 3)));
}

/*Cette méthode calcule les dommages avec arme du personnage.
@p_enemy pointeur pointeur sur l'objet CCharacter permetant d'affecter les dommages au personnage adverse.
*/
void CMage::armedAttack(CCharacter * p_enemy)
{
	if (m_weapon->criticalStrike())
	{
		std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << ((int)((getm_intellect() + m_weapon->getm_dommage() + 0.5*(((CStaff*)m_weapon)->getm_manaCost()) * 1.10) * 2)) << std::endl;
		p_enemy->applyDamage((int)((getm_intellect() + m_weapon->getm_dommage() + 0.5*(((CStaff*)m_weapon)->getm_manaCost()) * 1.10) * 2));
		setm_mana(getm_mana() - ((CStaff*)m_weapon)->getm_manaCost());
	}
	else
	{
		std::cout << "dommage avec " << m_weapon->getm_nom() << " : " << (int)((getm_intellect() + m_weapon->getm_dommage() + 0.5*(((CStaff*)m_weapon)->getm_manaCost()) * 1.10)) << std::endl;
		p_enemy->applyDamage((int)(getm_intellect() + m_weapon->getm_dommage() + 0.5*(((CStaff*)m_weapon)->getm_manaCost()) * 1.10));
		setm_mana(getm_mana() - ((CStaff*)m_weapon)->getm_manaCost());
	}
}

/*Cette méthode applique les dommages au personnage.
@p_damage entier permetant d'innitialiser les dommages.
*/
void CMage::applyDamage(int p_damage)
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

/*Cette méthode permet de récupéré le niveau de mana d'un entier entre 2 et 7 
sans dépasser le mana maximun du personnage.
*/
void CMage::ManaRegeneration()
{
	srand((unsigned)time(0));
	int nombre_aleatoire = 0;
	nombre_aleatoire = 2 + rand() % 7;
	setm_mana(getm_mana() + nombre_aleatoire);
	if (getm_mana() >= getm_manaMax())
	{
		std::cout << "mna regenere au maximun" << std::endl;
		setm_mana(getm_manaMax());
	}
}

/*Cette méthode indique si le mage à encore du mana.*/
bool CMage::haveMana()
{
	if (getm_mana() < (((CStaff*)m_weapon)->getm_manaCost()))
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*Cette méthode est le constructeur surchargé de la classe.
Elle initialise les membres protegés de la classe CMage
avec les différents paramètres de cette méthode
@p_nom string permetant d'innitialiser le membre m_nom
@p_hpMax entier permetant d'innitialiser le membre m_hpMax
@baton pointeur sur l'objet CStaff permetant d'innitialiser le membre m_weapon;
@p_dodge réel permetant d'innitialiser le membre m_dodge
@p_intellect entier permetant innitialiser le membre m_intellect
@p_manaMax entier permetant innitialiser le membre m_manaMax
*/
CMage::CMage(std::string p_nom, int p_hpMax, CStaff * baton, float p_dodge, int p_intellect, int p_manaMax) 
{
	setm_nom(p_nom);
	setm_hpMax(p_hpMax);
	setm_weapon(baton);
	setm_hp(p_hpMax + baton->getm_bonus());
	setm_dodge(p_dodge);
	setm_intellect(p_intellect);
	setm_manaMax(p_manaMax);
	setm_mana(p_manaMax);
}

CMage::~CMage()
{

}
