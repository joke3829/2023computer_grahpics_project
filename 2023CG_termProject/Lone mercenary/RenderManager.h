//============================================================
// RenderManager.h
// 모든 렌더링을 관리
//============================================================

#include "stdafx.h"

class RenderManager {
public:
	void Render();
	void setGame_state(int);
protected:
private:
	int game_state;

};