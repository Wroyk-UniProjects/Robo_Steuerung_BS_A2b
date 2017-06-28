#ifndef COORD_H
#define COORD_H


class coord
{
    private: double x,y,z;

    public:
        coord();
        coord(double x, double y, double z);
        coord(const coord&);
        ~coord();


        double getX() const;
        double getY() const;
        double getZ() const;
        void setX(double x);
        void setY(double y);
        void setZ(double z);

};

#endif // COORD_H
