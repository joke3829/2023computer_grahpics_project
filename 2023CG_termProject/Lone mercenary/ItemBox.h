//=================================================
// ItemBox.h
// 필드에 사용할 아이템 박스를 만든다.
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
