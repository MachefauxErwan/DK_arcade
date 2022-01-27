#ifndef _CMage_h
#define _CMage_h
#include "CCharacter.h"


class CMage : public CCharacter
{
protected:
	int m_intellect;
	int m_mana;
	int m_manaMax;
public:
	//setter()
	void setm_intellect(int p_intellect);
	void setm_mana(int p_mana);
	void setm_manaMax(int p_manaMax);
	//getter()
	int getm_intellect();
	int getm_mana();
	int getm_manaMax();
	// m�thodes Masqu�e 
	virtual void action(CCharacter *p_enemy);
	virtual void unarmedAttack(CCharacter *p_enemy);
	virtual void armedAttack(CCharacter *p_enemy);
	virtual void applyDamage(int p_damage);
	// autre m�thode
	void ManaRegeneration();
	bool haveMana();
	CMage(std::string p_nom, int p_hpMax, CStaff * baton, float p_dodge, int p_intellect, int p_manaMax);
	~CMage();
private:
	CMage();
};

#endif // !_CMage_h
