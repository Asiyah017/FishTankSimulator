// Definition for a simple immutable Point class.
//
// Mark A. Sheldon
//

#ifndef POINT_H
#define POINT_H

class Point
{
public:
        Point(int x_coord, int y_coord);
        Point();

        int get_x();
        int get_y();
        Point add(Point other);
        void print();

private:
        int x, y;
};

#endif