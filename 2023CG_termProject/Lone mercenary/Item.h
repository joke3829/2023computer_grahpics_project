//============================================================
// Item.h
// �ʵ� ������ ���
// �ʵ� ������ ����
//============================================================

#include "CharacterBase.h"

class Item : public CharacterBase{
public :
	Item(float hp, float max, float spd, float def, float atk);
	void increse_Max();
	void increse_DEF();
protected:
	float MAX;
	float SPD;
	float DEF;
private:
};