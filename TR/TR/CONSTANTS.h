#pragma once
#include <math.h>	// библиотека математичеких функций
#include <iostream> // библиотека стандартных потоков ввода/вывода

/* Математика */
#define pi 3.141592653589793238
#define a pi/4				// угол 45 градусов
#define phi asin(1/pow(3, 1./2)) * pi / 180 // угол 35 градусов
//#define phi pi/4			// угол 45 градусов (отн. Y)
//#define a pi/6			// угол 30 градусов

/* Размеры окна отображения */
#define WND_X 1500
#define WND_Y 1500

/* Преобразование отображения */
#define MULTIPLIER	10
#define OFFSET_X	400
#define OFFSET_Y	200


/* Веса опорных точек для разных кривых */
#define w_el	0.25
#define w_hyp	1.75
#define w_par	1