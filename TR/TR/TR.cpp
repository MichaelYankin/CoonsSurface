#include <Windows.h> 

#include "point.h" // класс точка
#include "matrix.h" // класс матрица
#include "CONSTANTS.h" // описание констант

/* Уравнения кривых на плоскостях, параллельных координатным плоскостям */
/* На вход функции подается параметр t (0..1)   */
/* На выходе получается точка в пространстве    */

/* Конические сечения - рациональные кривые Безье 2го порядка */

/* Уравнение эллипса на плоскости YZ (x = 0) */
point ellipse1(double u, double v) {
    double t = v;
    return point((point(0, 40, 0) * pow(1 - t, 2) + point(0, 40, 60) * 2 * t * (1 - t) * w_el + point(0, 0, 60) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_el + t * t));
}

/* Уравнение гиперболы на плоскости XZ (y = 0) */
point hyperbole(double u, double v) {
    double t = u;

    return point((point(0, 0, 60) * pow(1 - t, 2) + point(0, 0, 10) * 2 * t * (1 - t) * w_hyp + point(50, 0, 10) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_hyp + t * t));
}

/* Уравнение эллипса на плоскости YZ (x = 50) */
point ellipse2(double u, double v) {
    double t = v;
    return point((point(50, 40, -50) * pow(1 - t, 2) + point(50, 40, 10) * 2 * t * (1 - t) * w_el + point(50, 0, 10) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_el + t * t));
}

/* Уравнение параболы на плоскости XZ (y = 40) */
point parabola(double u, double v) {
    double t = u;
    return point((point(0, 40, 0) * pow(1 - t, 2) + point(0, 40, -50) * 2 * t * (1 - t) * w_par + point(50, 40, -50) * t * t) /
        (pow(1 - t, 2) + 2 * t * (1 - t) * w_par + t * t));
}

/* Уравнение поверхности Кунса */
/* На входе - значение параметров u, v (0 <= u, v <= 1)*/
/* На выходе - точка в пространстве */
inline point Q(double u, double v) {
    return parabola(u, 0) * (1 - v) + hyperbole(u, 1) * v + ellipse1(0, v) * (1 - u) + ellipse2(1, v) * u
        - point(0, 40, 0) * (1 - u) * (1 - v) - point(50, 40, -50) * u * (1 - v)
        - point(0, 0, 60) * (1 - u) * v       - point(50, 0, 10) * u * v;
}

/* Главная программа */
int main()
{

    /* Поддержка кириллицы в консоли */
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    /* Матрица для изометрической проекции */
    matrix isometricMatrix('i');

    /* Матрица поворота вокруг оси Z на 90 градусов */
    matrix rotationMatrics('r');

    HWND hwnd = GetConsoleWindow();         // получаем контекст окна
    HDC hdc = GetDC(hwnd);                  // получаем контекст отображения
    RECT wnd = { WND_X, WND_Y };            // устанавливаем размеры окна отображения
    //HBRUSH brush;                         // выбор средства рисования
    
    /* Для каждого значения параметров u, v с шагом 0.005/0.01 получаем значения точек поверхности в пространстве */
    for (double x = 0; x <= 1; x = x + 0.005) {
        for (double y = 0; y <= 1; y = y + 0.01) {

            point tmpPoint = Q(x, y);           // получаем точку
            matrix pointMatrix(1, 4);           // создаем матрицу [x, y, z, 1] для отображения проекции

            pointMatrix.at(0, 0) = tmpPoint.getX();
            pointMatrix.at(0, 1) = tmpPoint.getY();
            pointMatrix.at(0, 2) = tmpPoint.getZ();
            pointMatrix.at(0, 3) = 1;

            /* Получаем матрицу - изометрическую проекцию за счет произведения матриц */
            matrix resMatrix = pointMatrix * isometricMatrix;

            /* В контексте отображения ставим точку в соответствующей координате */
            SetPixel(hdc, OFFSET_X + MULTIPLIER * resMatrix.at(0, 0), OFFSET_Y + MULTIPLIER * resMatrix.at(0, 1), RGB(255, 128, 64));

        }
    }

    /* Ожидание ввода */
    int exitCode;
    std::cin >> exitCode;

    /* Освобождаем контекст отображения */
    ReleaseDC(hwnd, hdc);
    return 0;
}

