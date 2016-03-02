#include <iostream>
#include <cassert>
#include "Cluster.h"
#include "Point.h"

using namespace std;


namespace Clustering {

// The big three: cpy ctor, overloaded operator=, dtor
    Cluster::Cluster(const Cluster &rhs)
            : __size(rhs.__size)
    {
        __cpy(rhs.__points);
    }

    Cluster &Cluster::operator=(const Cluster &rhs)
    {
       if (*this == rhs)
           return *this;
        else
       {
           LNodePtr cursor = __points;
           LNodePtr nextPnt;

           while ( cursor != NULL )
           {
               nextPnt = cursor->next;
               delete cursor;
               cursor = nextPnt;
               __size--;
           }
       }

        LNodePtr rhsPtr = rhs.__points;
        for (int i=0; i<rhs.getSize(); i++)
        {
            add(rhsPtr->point);
            if (rhsPtr->next != NULL)
                rhsPtr = rhsPtr->next;
        }
        return *this;
    }


    Cluster::~Cluster()
    {

    }

    void Cluster::__del()
    {

    }

    void Cluster:: __cpy(LNodePtr pts)
    {

    }

    bool Cluster::__in(const Point &p) const
    {

    }

    // Getters/setters
    int Cluster::getSize() const // TODO add to the requirements
    {
        return __size;
    }

// Set functions: They allow calling c1.add(c2.remove(p));
    void Cluster::add(const Point &p) // TODO add asc order to the requirements
    {
        LNodePtr newPnt = new LNode(p, NULL);
        LNodePtr cursor;
        LNodePtr prev;
        newPnt->point = p;

        // Check to see if this will be the first node in the list
        if (__points == NULL)
        {
            __points = newPnt;
            newPnt->next = NULL;
        }
        // Or add another node to the existing list
        else
        {
            cursor = __points;
            prev = NULL;

            while (cursor != NULL && cursor->point <= p)
            {
                prev = cursor;
                cursor = cursor->next;
            }


            if (prev == NULL)
            {

                __points = newPnt;
                newPnt->next = cursor;
            }

            else
            {
                prev->next = newPnt;
                newPnt->next = cursor;
            }
        }
        __size++;
    }

    const Point &Cluster::remove(const Point &) {

    }

    bool Cluster:: contains(const Point &){

    }

// Overloaded operators

// Members: Subscript
    const Point &Cluster::operator[](unsigned int index) const // notice: const
    {
        LNodePtr cursor = __points;

        if (cursor != NULL)
        {
            for (int i=0; i<index; i++)
            {
                cursor = cursor->next;
            }
        }
        return cursor->point;

    }

// Members: Compound assignment (Point argument)
    Cluster &Cluster::operator+=(const Point &more)
    {
        LNodePtr cursor = __points;
        cursor->point += more;
    }

    Cluster &Cluster::operator-=(const Point &less)
    {
        LNodePtr cursor = __points;
        cursor->point -= less;
    }

// Members: Compound assignment (Cluster argument)
    Cluster &Cluster::operator+=(const Cluster &) // union
    {

    }

    Cluster &Cluster::operator-=(const Cluster &) // (asymmetric) difference
    {

    }

// Friends: IO
    std::ostream &operator<<(std::ostream &out, const Cluster &c)
    {
        LNodePtr cursor = c.__points;
        for ( ; cursor != NULL; cursor = cursor->next)
            out << cursor->point << endl;
    }

    std::istream &operator>>(std::istream &in, Cluster &c)
    {

    }

// Friends: Comparison
    bool operator==(const Cluster &lhs, const Cluster &rhs)
    {
        if (lhs.__size != rhs.__size)
            return false;

        LNodePtr Lcursor = lhs.__points;
        LNodePtr Rcursor = rhs.__points;
        while (Lcursor != NULL)
        {
            if (Lcursor->point != Rcursor->point )
            {
                return false;
            }
            else
            {
                Rcursor = Rcursor->next;
                Lcursor = Lcursor->next;
            }
        }
        return true;
    }

    bool operator!=(const Cluster &, const Cluster &) {

    }

// Friends: Arithmetic (Cluster and Point)
    const Cluster operator+(const Cluster &, const Point &) {

    }

    const Cluster operator-(const Cluster &, const Point &) {

    }

// Friends: Arithmetic (two Clusters)
    const Cluster operator+(const Cluster &, const Cluster &) // union
    {

    }

    const Cluster operator-(const Cluster &, const Cluster &) // (asymmetric) difference
    {

    }

}
