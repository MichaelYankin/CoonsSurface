#pragma once
#include <math.h>	// ���������� ������������� �������
#include <iostream> // ���������� ����������� ������� �����/������

/* ���������� */
#define pi 3.141592653589793238
#define a pi/4	// ���� 45 ��������
#define phi asin(1/pow(3, 1./2)) * pi / 180 // ���� 35 ��������
//#define phi pi/4			// ���� 45 �������� (���. Y)

/* ��������� ������� */
#define ellipse_a 40
#define ellipse_b 60
#define ellipse_offset_x 50 // �������� �� ��� �
#define ellipse_offset_z -50

/* ��������� ��������� */
#define hyperbole_a 30
#define hyperbole_b 40
#define hyperbole_offset_x -35
#define hyperbole_offset_z -5

/* ��������� �������� */
#define parabola_offset 40 // �������� �� ��� �
#define parabola_p 88

/* ������� ���� ����������� */
#define WND_X 1500
#define WND_Y 1500

/* �������������� ����������� */
#define MULTIPLIER	10
#define OFFSET_X	400
#define OFFSET_Y	200