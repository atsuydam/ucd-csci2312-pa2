#include <iostream>
#include <sstream>
#include "Point.h"
#include "Cluster.h"

using namespace std;


namespace Clustering {

    unsigned int Point::__idGen = 0; // ID generator

    Point::Point(int size)
    {
        __id = __idGen++;
        __dim = size;
        __values = new double[size];
        for (int i = 0; i < size; i++)
        {
            __values[i] = 0;
        }
    }

    Point::Point(int size, double *p)
    {
        // __idGen++;
    }

// Big three: cpy ctor, overloaded operator=, dtor
    Point::Point(const Point &rhs) :
            __dim(rhs.__dim)
    {
        __id = __idGen++;
        __values = new double[__dim];
        for (int i = 0; i < __dim; i++)
        {
            __values[i] = rhs.__values[i];
        }
    }

    Point &Point::operator=(const Point &rhs)
    {
        __id = __idGen++;
        if (this == &rhs)
        {
            return *this;
        }
        else
        {
            this->__dim = rhs.__dim;
            this->__values = new double[__dim];
            for (int i = 0; i < __dim; i++) {
                this->__values[i] = rhs.__values[i];
            }
        }
        return *this;
    }

    Point::~Point()
    {
        delete[] __values;
    }

// Accessors & mutators
    int Point::getId() const
    {
        return __id;
    }

    int Point::getDims() const
    {
        return __dim;
    }

    void Point::setValue(int i, double num)
    {
        __values[i] = num;
    }

    double Point::getValue(int i) const
    {
        return __values[i];
    }

// Functions
    double Point::distanceTo(const Point &rhs) const
    {
        double distance = 0;
        int size;
        size = rhs.__dim;
        for (int i=0; i<size; i++)
        {
            if (rhs.__values[i] == __values[i])
            {
                distance += 0;
            }
            else if (rhs.__values[i] > __values[i])
            {
                distance = rhs.__values[i] - __values[i];
            }
            else
            {
                distance = rhs.__values[0];
                distance += __values[i] - rhs.__values[i];
            }
        }
        return distance;
    }

// Overloaded operators

// Members
    Point &Point::operator*=(double num) // p *= 6; p.operator*=(6);
    {
        int size = __dim;
        for (int i=0; i < size; i++)
        {
            __values[i] *= num;
        }
    }

    Point &Point::operator/=(double num)
    {
        int size = __dim;
        for (int i=0; i < size; i++)
        {
            __values[i] /= num;
        }
    }

    const Point Point::operator*(double num) const // prevent (p1 * 2) = p2;
    {
        int size = __dim;
        Point p(size);

        for (int i=0; i<__dim; i++)
        {
            p.__values[i] = __values[i] * num;
        }
        return p;
    }

    const Point Point::operator/(double num) const // p3 = p2 / 2;
    {
        int size = __dim;
        Point p(size);

        for (int i=0; i<__dim; i++)
        {
            p.__values[i] = __values[i] / num;
        }
        return p;
    }

    double &Point::operator[](int index)
    {
        return __values[index];
    }

// Friends
    Point &operator+=(Point &lhs, const Point &rhs)
    {
       int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            lhs.__values[i] += rhs.__values[i];
        }
        return lhs;
    }

    Point &operator-=(Point &lhs, const Point &rhs)
    {
        int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            lhs.__values[i] -= rhs.__values[i];
        }
        return lhs;
    }

    const Point operator+(const Point &lhs, const Point &rhs)
    {
        int size = (lhs.__dim + rhs.__dim);
        Point p(size);
        for (int i=0; i < size; i++)
        {
            p.__values[i] = lhs.__values[i] + rhs.__values[i];
        }
        return p;
    }

    const Point operator-(const Point &lhs, const Point &rhs)
    {
        int size = (lhs.__dim + rhs.__dim);
        Point p(size);
        for (int i=0; i < size; i++)
        {
            p.__values[i] = lhs.__values[i] - rhs.__values[i];
        }
        return p;
    }

    bool operator==(const Point &lhs, const Point &rhs)
    {
       bool answer = false;
        if (lhs.getDims() == rhs.getDims())
        {
            int dimensions = lhs.getDims();
            answer = true;
            for (int i=0; i < dimensions; i++)
            {
                if (lhs.__values[i] != rhs.__values[i])
                {
                    answer = false;
                    break;
                }
            }
        }
        return answer;
    }

    bool operator!=(const Point &lhs, const Point &rhs)
    {
        bool answer = false;
              int dimensions = lhs.getDims();
            for (int i=0; i < dimensions; i++)
            {
                if (lhs.__values[i] != rhs.__values[i])
                {
                    answer = true;
                    break;
                }
            }
        return answer;
    }

    bool operator<(const Point &lhs, const Point &rhs)
    {
        bool answer = false;
        int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            if ( lhs.__values[i] < rhs.__values[i])
            {
                answer = true;
            }

        }
        return answer;


    }

    bool operator>(const Point &lhs, const Point &rhs)
    {
        bool answer = false;
        int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            if ( lhs.__values[i] > rhs.__values[i])
            {
                answer = true;
            }

        }
        return answer;
    }

    bool operator<=(const Point &lhs, const Point &rhs)
    {
        bool answer = false;
        int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            if ( lhs.__values[i] <= rhs.__values[i])
            {
                answer = true;
            }
        }
        return answer;
    }

    bool operator>=(const Point &lhs, const Point &rhs)
    {
        bool answer = false;
        int size = lhs.__dim;
        for (int i=0; i < size; i++)
        {
            if ( lhs.__values[i] >= rhs.__values[i])
            {
                answer = true;
            }

        }
        return answer;
    }

    std::ostream &operator<<(std::ostream &out, const Point &p)
    {
        int i=0;
        for ( ; i < p.__dim; i++)
            cout << p.__values[i] << ' ';
        return out;
    }

    std::istream &operator>>(std::istream &in, Point &p)
    {
        for (int i=0; i < p.__dim; i++)
            in >> p.__values[i];
        return in;
    }
}