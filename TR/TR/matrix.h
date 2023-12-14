#pragma once
#include "CONSTANTS.h"

class matrix
{

private:
	double** elements;
	int col, row;
public:
	
	/* ����������� ������ - ��������� ��������� ������ �������� ����������� */
	matrix(int rows, int columns) {
		col = columns;
		row = rows;
		
		elements = new double* [row];
		for (int i = 0; i < row; i++) {
			elements[i] = new double[col];
		}
	}

	/* ����������� ����������� - ������� ����� ������� */
	/* ����� ��� �������� ������� � �������� ��������� ������� */
	matrix(matrix& matr) {
		col = matr.col;
		row = matr.row;

		/* ������� ����� ������� */
		elements = new double* [row];
		for (int i = 0; i < row; i++) {
			elements[i] = new double[col];
		}
		
		/* ����������� �������� ��������� ������ ������� ����� */
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				elements[i][j] = matr.at(i, j);
			}
		}
	}

	/* ���������� - ������� ������ ������, ����������� ������ */
	~matrix() {
		for (int i = 0; i < row; i++) {
			delete[] elements[i];
		}
		delete[] elements;
		col = 0; row = 0;
	}

	/* ����������� ��� �������� ������ ������������ ����� */
	matrix(char symbol) {
		switch (symbol) {
		case 'i':		// ������� �������������� ��������
			row = 4; col = 4;
			elements = new double* [4]; // ������� ������� 4�4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// �������� ��� ��������

			elements[0][0] = cos(a); elements[0][1] = sin(a) * sin(phi);	// cos(a)  sin(a)*sin(phi) 0 0
			elements[1][1] = cos(phi);										//		0		  cos(phi) 0 0
			elements[2][0] = sin(a); elements[2][1] = -sin(phi) * cos(a);	// sin(a) -sin(phi)*cos(a) 0 0
			elements[3][3] = 1;												//		0				 0 0 1
			break;

		case 'r':		// ������� �������� ������ ��� Z �� 90 �������
			row = 4; col = 4;
			elements = new double* [4]; // ������� ������� 4�4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// �������� ��� ��������

			elements[0][2] = -1;	// 0 0 -1 0
			elements[1][1] = 1;		// 0 1  0 0
			elements[2][0] = 1;		// 1 0  0 0
			elements[3][3] = 1;		// 0 0  0 1
			break;

		default:
			row = 4; col = 4;
			elements = new double* [4]; // ������� ������� 4�4
			for (int i = 0; i < 4; i++) {
				elements[i] = new double[4];
			}
			(*this).init();			// �������� ��� ��������
			break;
		}
	}

	/* ������������� ������� ������ */
	void init() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				elements[i][j] = 0;
			}
		}
	}

	/* ������, ������������ ������ �� ������� ������� */
	double& at(int r, int c) {
		return elements[r][c];
	}

	/* ���������� ���������� */

	/* ������������ ������ */
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

