#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#define PI 3.14159

using namespace std;
enum DataType {tnone, tTriangle, tCircle, tSquare, tSphere, tCube, tTetrahedron};

class Point2d
{
public:
    float m_x, m_y;
    Point2d() : m_x(0), m_y(0) {};
    Point2d(float x, float y) : m_x(x),m_y(y){};
};

class Point3d
{
public:
    float m_x, m_y, m_z;
    Point3d() : m_x(0),m_y(0), m_z(0){};
    Point3d(float x, float y, float z) : m_x(x),m_y(y),m_z(z){};
};

class Tetrahedron
{
private:
    float m_edge1, m_edge2, m_edge3, m_edge4, m_edge5, m_edge6;
    float m_p1, m_p2, m_p3, m_p4;

public:
    float Area;
    Tetrahedron (): m_p1(0), m_p2(0), m_p3(0),m_p4(0){};
    Tetrahedron (float m_p1, float m_p2,float m_p3, float m_p4);
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4);
    float CalcArea();

};

class Circle
{
private:
    float m_ratio;
public:
    float Area;
    Circle() : m_ratio(0) {};
    Circle(float ratio) : m_ratio(ratio){Area = PI*m_ratio*m_ratio;};
    float CalcArea() const {return PI*m_ratio*m_ratio;};

};
class Square
{
private:
    float m_edge;
public:
    float Area;
    Square() : m_edge(0) {};
    Square(float edge) : m_edge(edge){Area=m_edge*m_edge;};
    float CalcArea() const {return m_edge*m_edge;};

};
class Sphere
{
private:
    float m_ratio;
public:
    float Area;
    Sphere() : m_ratio(0) {};
    Sphere(float ratio) : m_ratio(ratio){Area = 4*PI*m_ratio*m_ratio;};
    float CalcArea() const {return 4*PI*m_ratio*m_ratio;};

};
class Cube
{
private:
    float m_edge;
public:
    float Area;
    Cube() : m_edge(0) {};
    Cube(float edge) : m_edge(edge) {Area = 6*m_edge*m_edge;};
    float CalcArea() const {return 6*m_edge*m_edge;};

};

class Triangle
{
private:
    float m_edge1, m_edge2, m_edge3;

public:
    float Area;
    Triangle() : m_edge1(0), m_edge2(0), m_edge3(0) {};
    Triangle(float e1,float e2,float e3) : m_edge1(e1), m_edge2(e2), m_edge3(e3){Area = this->CalcArea(); };
    Triangle(Point2d p1,Point2d p2,Point2d p3);
    float CalcArea();
};




class GenericShape
{
private:
    void* m_data;
    DataType m_dataType;
    
public:
    GenericShape()                  { m_data = NULL;                m_dataType=tnone; };
    GenericShape(Triangle v)        { m_data = new Triangle(v);     m_dataType=tTriangle; };
    GenericShape(Circle v)          { m_data = new Circle(v);        m_dataType=tCircle; };
    GenericShape(Square v)          { m_data = new Square(v);       m_dataType=tSquare; };
    GenericShape(Sphere v)          { m_data = new Sphere(v);         m_dataType=tSphere; };
    GenericShape(Cube v)            { m_data = new Cube(v);       m_dataType=tCube; };
    GenericShape(Tetrahedron v)     { m_data = new Tetrahedron(v);      m_dataType=tTetrahedron; };
    
    ~GenericShape() {
    };
    
        
    string ShowInfo() {
        stringstream sst;
        //sst << "Object #" << m_dataType;
        if(m_dataType == tnone)   cout << " is -> NULL";
        if(m_dataType == tTriangle)    cout << " is triangle -> "  << ((Triangle*) m_data)->Area;
        if(m_dataType == tCircle)  cout << " is circle -> " << ((Circle*) m_data)->Area;
        if(m_dataType == tSquare) cout << " is square -> "  << fixed <<((Square*) m_data)->Area;
        if(m_dataType == tSphere)   cout << " is sphere -> " << ((Sphere*) m_data)->Area;
        if(m_dataType == tCube) cout << " is cube -> " << ((Cube*) m_data)->Area;
        if(m_dataType == tTetrahedron) cout << " is tetrahedron -> " << ((Tetrahedron*) m_data)->Area;

        
        return sst.str();
    };
};



#endif
