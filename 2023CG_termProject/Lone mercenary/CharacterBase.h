//============================================================
// CharacterBase.h
// ĳ���Ͱ� �ߺ����� ������ ������ �����ϴ� ��� Ŭ����
// ��ӽ��� ����Ѵ�
//============================================================
#pragma once
#include "stdafx.h"

class CharacterBase {
public:
	CharacterBase() = default;
	CharacterBase(float, float, float, float, float);				// �ʱ�ȭ
	virtual ~CharacterBase();
	void Update_HP(float);				// ü�� ���� ��� ATK�� �޾ƿͼ� ���
	bool Death_check();					// ü���� 0���ϸ� true ��ȯ

	float getHP();
protected:
	float HP{};				// ü��
	float MAXHP{};			// �ִ� ü��
	float speed{};			// �̵� �ӵ�
	float DEF{};			// ����
	float ATK{};			// �÷��̾��� ��� ���� �� ������ ���ݷ��� �޾ƿ´�.
private:
};