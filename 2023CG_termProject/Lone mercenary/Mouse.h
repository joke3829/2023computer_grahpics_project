#ifndef MOUSE
#define MOUSE
// 윈도우 마우스좌표를 gl 좌표로 변환해주는 함수 헤더
#pragma once

// 윈도우 x좌표를 gl죄표로 바꿔주는 함수
float x_conversion(int x, int width)
{
	return (static_cast<float>(x) - (width / 2)) / (width / 2);
}

// 윈도우 y좌표를 gl좌표로 바꿔주는 함수
float y_conversion(int y, int height)
{
	return ((static_cast<float>(y) * -1) + (height / 2)) / (height / 2);
}

#endif