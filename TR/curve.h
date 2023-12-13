#pragma once
#include "point.h"
#include <math.h>
#include <vector>
#include "CONSTANTS.h"

class curve
{
protected:
    std::vector<point> points;
public: 
    curve() {
    }
    
    curve(const curve& crv) {
        for (int i = 0; i < 1000; i++) {
            points[i] = crv.points[i];
        }
    }

    point getPoint(int t) {
        return points[t];
    }

    /* ѕоиск точки пересечени€ кривых */
    point findIntersection(curve crv2)
    {
        int i = 0;
        int j = 0;
        point epsPoint(0.01, 0.01, 0.01); //окрестность точки
        
        while (i < points.size())
        {
            while (j < crv2.points.size())
            {
                if ((points[i] - crv2.points[j]).abs() <= epsPoint)
                {
                    return points[i];
                }
                j++;
            }
            i++;
        }
        
        std::cout << "Ќет точек пересечени€ кривых.\n";
        return point(0, 0, 0);
    }

};

class ellipse : public curve {
public:
    ellipse(point startPoint, double offset, double a, double b) {
        points.resize(200);
        for (int t = 0; t < 2*pi; t = t + pi/100)
        {
            points[100*t / pi] = point(startPoint.getX() + offset, 
                startPoint.getY() + a * cos(t),
                startPoint.getZ() + b * sin(t));
        }
    }
};

class parabola : public curve
{
public:
    parabola(point startPoint, double offset, double p)
    {
        points.resize(50);
        for (int t = 0; t < pi / 2; t = t + pi / 100)
        {
            points[100 * t / pi] = point(startPoint.getY() + pow(tan(t / .1000), 2),
                startPoint.getX() + offset,
                startPoint.getZ() + 2 * pow(p * tan(t / .1000), 1 / .2));
        }
    }
};

class hyperbole : public curve {
public:
    hyperbole(point startPoint, double offset, double a, double b)
    {
        points.resize(50);
        for (int t = 0; t < pi / 2; t = t + pi / 100)
        {
            points[100 * t / pi] = point(startPoint.getY() + a / sin(t),
                startPoint.getX() + offset,
                startPoint.getZ() + b * tan(t));
        }
    }
};