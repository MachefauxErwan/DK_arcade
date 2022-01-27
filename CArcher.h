#ifndef _CArcher_h
#define _CArcher_h
#include "CCharacter.h"


class CArcher : public CCharacter
{
protected:
	float m_agility;
	bool m_aimingAid;
public:
	//setter()
	void setm_agility(float p_agility);
	//getter()
	float getm_agility();
	// m�thodes Masqu�e 
	void action(CCharacter *p_enemy);
	void unarmedAttack(CCharacter *p_enemy);
	void armedAttack(CCharacter *p_enemy);
	void applyDamage(int p_damage);
	// autre m�thode
	void aim();
	CArcher(std::string p_nom, int p_hpMax, CBow *arc, float p_dodge, float p_agility);
	~CArcher();
private:
	CArcher();
};

#endif // !_CArcher_h
