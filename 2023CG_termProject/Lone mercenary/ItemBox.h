//=================================================
// ItemBox.h
// �ʵ忡 ����� ������ �ڽ��� �����.
//=================================================
#pragma once
#include "stdafx.h"
#include "Mesh.h"
class ItemBox {
public:
	ItemBox();
	~ItemBox();

	void Render();
private:
	Mesh* box;

};
