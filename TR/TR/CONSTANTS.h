#pragma once
#include <math.h>	// ���������� ������������� �������
#include <iostream> // ���������� ����������� ������� �����/������

/* ���������� */
#define pi 3.141592653589793238
#define a pi/4				// ���� 45 ��������
#define phi asin(1/pow(3, 1./2)) * pi / 180 // ���� 35 ��������
//#define phi pi/4			// ���� 45 �������� (���. Y)
//#define a pi/6			// ���� 30 ��������

/* ������� ���� ����������� */
#define WND_X 1500
#define WND_Y 1500

/* �������������� ����������� */
#define MULTIPLIER	10
#define OFFSET_X	400
#define OFFSET_Y	200


/* ���� ������� ����� ��� ������ ������ */
#define w_el	0.25
#define w_hyp	1.75
#define w_par	1