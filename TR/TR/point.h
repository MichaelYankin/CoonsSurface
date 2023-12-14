#pragma once

class point
{
private:
    double x; // координаты точки
    double y;
    double z;

public:

    /* Конструктор по умолчанию - точка (0, 0, 0) */
    point() {
        x = 0;
        y = 0;
        z = 0;
    }

    /* Конструктор, создающий точку с заданными координатами */
    point(double inX, double inY, double inZ)
    {
        x = inX;
        y = inY;
        z = inZ;
    }

    /* Констуктор копирования, для передачи объекта класса в качестве аргумента функции*/
    point(const point& pt) {
        x = pt.x;
        y = pt.y;
        z = pt.z;
    }

    /* Функции, возвращающие конкретные координаты точки */
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    /* перегрузка операторов */
    point operator +(point b)
    {
        return point(x + b.x, y + b.y, z + b.z);
    }

    point operator -(point b)
    {
        return point(x - b.x, y - b.y, z - b.z);
    }

    /* Умножение на число */
    point operator *(double a)
    {
        return point(x * a, y * a, z * a);
    }

    /* Скалярное произведение */
    double operator *(point b) {
        return x * b.x + y * b.y + z * b.z;
    }

    point operator /(double a) {
        return point(x / a, y / a, z / a);
    }

};

    