#include <iostream>
#include <vector>

class Shape
{
    public:

    virtual std::ostream& print(std::ostream& out) const = 0; 
    friend std::ostream& operator<< (std::ostream& out, const Shape& p)
    {
        return p.print(out);
    };
    virtual ~Shape() {};
};

class Point 
{
    private: 
    int m_x = 0; 
    int m_y = 0; 
    int m_z = 0; 
    public: 
    Point(int x, int y, int z) 
        : m_x(x), m_y(y), m_z(z) {}
    friend std::ostream& operator<<(std::ostream &out, const Point &p) 
    { 
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")"; 
        return out; 
        } 
};

class Triangle: public Shape
{
    private:
    Point m_a;
    Point m_b;
    Point m_c;

    public:
    Triangle(const Point &a, const Point &b, const Point &c) 
        : m_a(a), m_b(b), m_c(c) {}
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle " << m_a << ", " << m_b << ", " << m_c << ")";
        return out;
    }

};
class Circle: public Shape
{
    private:
    Point m_centre;
    int m_radius;

    public:
    Circle(const Point &centre, int radius) 
        : m_centre(centre), m_radius(radius) {}
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Circle " << m_centre << ", radius " << m_radius;
        return out;
    }
    int getRadius() {return m_radius;}
};

int getLargestRadius(std::vector<Shape*> &v)
{
    int max = 0;
    for (auto const &shape : v)
    {
        Circle *circle = dynamic_cast<Circle*>(shape);
        if (circle)
        {
            if(circle->getRadius() > max)
                max = circle->getRadius();
        }   
    }
    return max;
}

int main() 
{ 
    std::vector<Shape*> v; 
    v.push_back(new Circle(Point(1, 2, 3), 7)); 
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));

    v.push_back(new Circle(Point(4, 5, 6), 3));
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';
    
    for (auto const &element : v) 
        delete element;
    return 0; 
}