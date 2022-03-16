#include "SHAPES.HPP"
#include <cmath>

Triangle::Triangle(Point2d p1,Point2d p2,Point2d p3)
{
    float e3 = sqrt((p1.m_x-p2.m_x)*(p1.m_x-p2.m_x)+(p1.m_y-p2.m_y)*(p1.m_y-p2.m_y));
    float e2 = sqrt((p1.m_x-p3.m_x)*(p1.m_x-p3.m_x)+(p1.m_y-p3.m_y)*(p1.m_y-p3.m_y));
    float e1 = sqrt((p2.m_x-p3.m_x)*(p2.m_x-p3.m_x)+(p2.m_y-p3.m_y)*(p2.m_y-p3.m_y));
m_edge1 = e1;
m_edge2 = e2;
m_edge3 = e3;
Area = this->CalcArea();


}
float Triangle::CalcArea()
{
    float s= (m_edge1+m_edge2+m_edge3)/2;
    float A= sqrt(s*(s-m_edge1)*(s-m_edge2)*(s-m_edge3));
    
    return A;
}

Tetrahedron::Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4)
{
    float A = sqrt ((p1.m_x-p2.m_x)*(p1.m_x-p2.m_x) + (p1.m_y-p2.m_y)*(p1.m_y-p2.m_y) + (p1.m_z-p2.m_z)*(p1.m_z-p2.m_z));

    float B = sqrt ((p1.m_x-p3.m_x)*(p1.m_x-p3.m_x) + (p1.m_y-p3.m_y)*(p1.m_y-p3.m_y) + (p1.m_z-p3.m_z)*(p1.m_z-p3.m_z));

    float C = sqrt ((p1.m_x-p4.m_x)*(p1.m_x-p4.m_x) + (p1.m_y-p4.m_y)*(p1.m_y-p4.m_y) + (p1.m_z-p4.m_z)*(p1.m_z-p4.m_z));

    float D = sqrt ((p3.m_x-p4.m_x)*(p3.m_x-p4.m_x) + (p3.m_y-p4.m_y)*(p3.m_y-p4.m_y) + (p3.m_z-p4.m_z)*(p3.m_z-p4.m_z));

    float E = sqrt ((p2.m_x-p3.m_x)*(p2.m_x-p3.m_x) + (p2.m_y-p3.m_y)*(p2.m_y-p3.m_y) + (p2.m_z-p3.m_z)*(p2.m_z-p3.m_z));

    float F = sqrt ((p2.m_x-p4.m_x)*(p2.m_x-p4.m_x) + (p2.m_y-p4.m_y)*(p2.m_y-p4.m_y) + (p2.m_z-p4.m_z)*(p2.m_z-p4.m_z));


    m_edge1 = A;
    m_edge2 = B;
    m_edge3 = C;
    m_edge4 = D;
    m_edge5 = E;
    m_edge6 = F;
    Area = this->CalcArea();
}

float Tetrahedron:: CalcArea()
{
    float area1, area2, area3, area4, areaTotal;
    float p1, p2, p3, p4;

    p1 = (m_edge2 + m_edge3 + m_edge4)/2;
    area1= sqrt(p1*(p1-m_edge2)*(p1-m_edge3)*(p1-m_edge4));

    p2 = (m_edge5 + m_edge4 + m_edge6)/2;
    area2= sqrt(p2*(p2-m_edge5)*(p2-m_edge4)*(p2-m_edge6));

    p3 = (m_edge1 + m_edge3 + m_edge6)/2;
    area3= sqrt(p3*(p3-m_edge1)*(p3-m_edge3)*(p3-m_edge6));

    p4 = (m_edge1 + m_edge2 + m_edge5)/2;
    area4= sqrt(p4*(p4-m_edge1)*(p4-m_edge2)*(p4-m_edge5));

    areaTotal = area1 + area2 + area3 + area4;

    return areaTotal;
}