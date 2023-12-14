#pragma once
#include "CONSTANTS.h"

class matrix
{

private:
	double** elements;
	int col, row;
public:
	
	/* Конструктор класса - создается двумерный массив заданной размерности */
	matrix(int rows, int columns) {
		col = columns;
		row = rows;
		
		elements = new double* [row];
		for (int i = 0; i < row; i++) {
			elements[i] = new double[col];
		}
	}

	/* Конструктор копирования - создает копию матрицы */
	/* Нужен для передачи матрицы в качестве аргумента функции */
	matrix(matrix& matr) {
		col = matr.col;
		row = matr.row;

		/* Создаем новую матрицу */
		elements = new double* [row];
		for (int i = 0; i < row; i++) {
			elements[i] = new double[col];
		}
		
		/* Присваиваем значения элементов старой матрицы новым */
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				elements[i][j] = matr.at(i, j);
			}
		}
	}

	/* Деструктор - удаляет объект класса, освобождает память */
	~matrix() {
		for (int i = 0; i < row; i++) {
			delete[] elements[i];
		}
		delete[] elements;
		col = 0; row = 0;
	}

	/* Конструктор для создания матриц определенных типов */
	matrix(char symbol) {
		switch (symbol) {
		case 'i':		// матрица изометрической проекции
			row = 4; col = 4;
			elements = new double* [4]; // создаем матрицу 4х4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// обнуляем все элементы

			elements[0][0] = cos(a); elements[0][1] = sin(a) * sin(phi);	// cos(a)  sin(a)*sin(phi) 0 0
			elements[1][1] = cos(phi);										//		0		  cos(phi) 0 0
			elements[2][0] = sin(a); elements[2][1] = -sin(phi) * cos(a);	// sin(a) -sin(phi)*cos(a) 0 0
			elements[3][3] = 1;												//		0				 0 0 1
			break;

		case 'r':		// матрица вращения вокруг оси Z на 90 градсов
			row = 4; col = 4;
			elements = new double* [4]; // создаем матрицу 4х4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// обнуляем все элементы

			elements[0][2] = -1;	// 0 0 -1 0
			elements[1][1] = 1;		// 0 1  0 0
			elements[2][0] = 1;		// 1 0  0 0
			elements[3][3] = 1;		// 0 0  0 1
			break;

		default:
			row = 4; col = 4;
			elements = new double* [4]; // создаем матрицу 4х4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// обнуляем все элементы
			break;
		}
	}

	/* Инициализация матрицы нулями */
	void init() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				elements[i][j] = 0;
			}
		}
	}

	/* Фунция, возвращающая ссылку на элемент матрицы */
	double& at(int r, int c) {
		return elements[r][c];
	}

	/* Перегрузка операторов */

	/* Произведение матриц */
	matrix operator*(matrix matr2) {
		matrix tmp(row, matr2.col);
		tmp.init();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < matr2.col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					tmp.elements[i][j] += elements[i][k] * matr2.elements[k][j];
				}
			}
		}
		return tmp;
	}

};

