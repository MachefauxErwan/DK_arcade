#ifndef _CWarrior_h
#define _CWarrior_h
#include "CCharacter.h"


class CWarrior : public CCharacter
{
protected:
	int m_attack;
	int m_shield;
	int m_NbTourProtection;
public:
	//setter()
	void setm_attack(int p_attack);
	void setm_shield(int p_shield);
	void setm_NbTourProtection(int p_NbTourProtection);
	void setm_weapon(CSword * p_epee);
	//getter()
	int getm_attack();
	int getm_shield();
	int getm_NbTourProtection();
	// méthodes Masquée 
	void action(CCharacter *p_enemy);
	void unarmedAttack(CCharacter *p_enemy);
	void armedAttack(CCharacter *p_enemy);
	void applyDamage(int p_damage);
	// autre méthode
	void attack();
	void defend();
	void repair();
	CWarrior(std::string p_nom, int p_hpMax, CSword *p_weapon, float p_dodge, int p_attack, int p_shield);
	~CWarrior();
private:
	CWarrior();
};

#endif // !_CWarrior_h
