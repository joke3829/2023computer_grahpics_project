#ifndef MOUSE
#define MOUSE
// ������ ���콺��ǥ�� gl ��ǥ�� ��ȯ���ִ� �Լ� ���
#pragma once

// ������ x��ǥ�� gl��ǥ�� �ٲ��ִ� �Լ�
float x_conversion(int x, int width)
{
	return (static_cast<float>(x) - (width / 2)) / (width / 2);
}

// ������ y��ǥ�� gl��ǥ�� �ٲ��ִ� �Լ�
float y_conversion(int y, int height)
{
	return ((static_cast<float>(y) * -1) + (height / 2)) / (height / 2);
}

#endif