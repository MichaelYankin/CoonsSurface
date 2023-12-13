#pragma once
#include <math.h>	// библиотека математичеких функций
#include <iostream> // библиотека стандартных потоков ввода/вывода

/* Математика */
#define pi 3.141592653589793238
#define a pi/4	// угол 45 градусов
#define phi asin(1/pow(3, 1./2)) * pi / 180 // угол 35 градусов
//#define phi pi/4			// угол 45 градусов (отн. Y)

/* Параметры эллипса */
#define ellipse_a 40
#define ellipse_b 60
#define ellipse_offset_x 50 // смещение по оси х
#define ellipse_offset_z -50

/* Параметры гиперболы */
#define hyperbole_a 30
#define hyperbole_b 40
#define hyperbole_offset_x -35
#define hyperbole_offset_z -5

/* Параметры параболы */
#define parabola_offset 40 // смещение по оси у
#define parabola_p 88

/* Размеры окна отображения */
#define WND_X 1500
#define WND_Y 1500

/* Преобразование отображения */
#define MULTIPLIER	10
#define OFFSET_X	400
#define OFFSET_Y	200