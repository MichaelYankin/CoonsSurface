#pragma once

class point
{
private:
    double x; // ���������� �����
    double y;
    double z;

public:

    /* ����������� �� ��������� - ����� (0, 0, 0) */
    point() {
        x = 0;
        y = 0;
        z = 0;
    }

    /* �����������, ��������� ����� � ��������� ������������ */
    point(double inX, double inY, double inZ)
    {
        x = inX;
        y = inY;
        z = inZ;
    }

    /* ���������� �����������, ��� �������� ������� ������ � �������� ��������� �������*/
    point(const point& pt) {
        x = pt.x;
        y = pt.y;
        z = pt.z;
    }

    /* �������, ������������ ���������� ���������� ����� */
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    /* ���������� ���������� */
    point operator +(point b)
    {
        return point(x + b.x, y + b.y, z + b.z);
    }

    point operator -(point b)
    {
        return point(x - b.x, y - b.y, z - b.z);
    }

    /* ��������� �� ����� */
    point operator *(double a)
    {
        return point(x * a, y * a, z * a);
    }

    /* ��������� ������������ */
    double operator *(point b) {
        return x * b.x + y * b.y + z * b.z;
    }

    point operator /(double a) {
        return point(x / a, y / a, z / a);
    }

};

    