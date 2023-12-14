#include <Windows.h> 

#include "point.h" // ����� �����
#include "matrix.h" // ����� �������
#include "CONSTANTS.h" // �������� ��������

/* ��������� ������ �� ����������, ������������ ������������ ���������� */
/* �� ���� ������� �������� �������� t (0..1)   */
/* �� ������ ���������� ����� � ������������    */

/* ���������� ������� - ������������ ������ ����� 2�� ������� */

/* ��������� ������� �� ��������� YZ (x = 0) */
point ellipse1(double u, double v) {
    double t = v;
    return point((point(0, 40, 0) * pow(1 - t, 2) + point(0, 40, 60) * 2 * t * (1 - t) * w_el + point(0, 0, 60) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_el + t * t));
}

/* ��������� ��������� �� ��������� XZ (y = 0) */
point hyperbole(double u, double v) {
    double t = u;

    return point((point(0, 0, 60) * pow(1 - t, 2) + point(0, 0, 10) * 2 * t * (1 - t) * w_hyp + point(50, 0, 10) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_hyp + t * t));
}

/* ��������� ������� �� ��������� YZ (x = 50) */
point ellipse2(double u, double v) {
    double t = v;
    return point((point(50, 40, -50) * pow(1 - t, 2) + point(50, 40, 10) * 2 * t * (1 - t) * w_el + point(50, 0, 10) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_el + t * t));
}

/* ��������� �������� �� ��������� XZ (y = 40) */
point parabola(double u, double v) {
    double t = u;
    return point((point(0, 40, 0) * pow(1 - t, 2) + point(0, 40, -50) * 2 * t * (1 - t) * w_par + point(50, 40, -50) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_par + t * t));
}

/* ��������� ����������� ����� */
/* �� ����� - �������� ���������� u, v (0 <= u, v <= 1)*/
/* �� ������ - ����� � ������������ */
inline point Q(double u, double v) {
    return parabola(u, 0) * (1 - v) + hyperbole(u, 1) * v + ellipse1(0, v) * (1 - u) + ellipse2(1, v) * u
        - point(0, 40, 0) * (1 - u) * (1 - v) - point(50, 40, -50) * u * (1 - v)
        - point(0, 0, 60) * (1 - u) * v       - point(50, 0, 10) * u * v;
}

/* ������� ��������� */
int main()
{

    /* ��������� ��������� � ������� */
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    /* ������� ��� �������������� �������� */
    matrix isometricMatrix('i');

    /* ������� �������� ������ ��� Z �� 90 �������� */
    matrix rotationMatrics('r');

    HWND hwnd = GetConsoleWindow();         // �������� �������� ����
    HDC hdc = GetDC(hwnd);                  // �������� �������� �����������
    RECT wnd = { WND_X, WND_Y };            // ������������� ������� ���� �����������
    //HBRUSH brush;                         // ����� �������� ���������
    
    /* ��� ������� �������� ���������� u, v � ����� 0.005/0.01 �������� �������� ����� ����������� � ������������ */
    for (double x = 0; x <= 1; x = x + 0.005) {
        for (double y = 0; y <= 1; y = y + 0.01) {

            point tmpPoint = Q(x, y);           // �������� �����
            matrix pointMatrix(1, 4);           // ������� ������� [x, y, z, 1] ��� ����������� ��������

            pointMatrix.at(0, 0) = tmpPoint.getX();
            pointMatrix.at(0, 1) = tmpPoint.getY();
            pointMatrix.at(0, 2) = tmpPoint.getZ();
            pointMatrix.at(0, 3) = 1;

            /* �������� ������� - �������������� �������� �� ���� ������������ ������ */
            matrix resMatrix = pointMatrix * isometricMatrix;

            /* � ��������� ����������� ������ ����� � ��������������� ���������� */
            SetPixel(hdc, OFFSET_X + MULTIPLIER * resMatrix.at(0, 0), OFFSET_Y + MULTIPLIER * resMatrix.at(0, 1), RGB(255, 128, 64));

        }
    }

    /* �������� ����� */
    int exitCode;
    std::cin >> exitCode;

    /* ����������� �������� ����������� */
    ReleaseDC(hwnd, hdc);
    return 0;
}

