#include "Leitura.hpp"
#include <vector>


using namespace std;
bool FileReading(string PATH, vector<GenericShape>&Shapes)
{

ifstream FileReader;
    float teste3, teste4;
    FileReader.open(PATH);
    
    string number_as_string;
    string tmp;
    
    


    while (getline(FileReader, tmp))
    {
        float temp;
        vector<float> numbers;
        if (tmp == "triangle"){
        for (size_t i=0; i<3; i++ )
        {
            getline(FileReader, number_as_string);
            stringstream in(number_as_string);
            while (in >> temp) {
            numbers.push_back(temp);
            if (in.peek()== ',')
            in.ignore();

        }
        }
        
        if (numbers.size()<4)
        {
            Triangle blah (numbers[0], numbers[1], numbers[2]);
            Shapes.push_back(blah);
        }
        
        if (numbers.size()>3)
        {
            Triangle blah (Point2d(numbers[0], numbers[1]),Point2d(numbers[2], numbers[3]), Point2d(numbers[4], numbers[5]));
            Shapes.push_back(blah);

        }
        }
        if (tmp == "circle")
        {
            getline(FileReader, number_as_string);
            stringstream in(number_as_string);
            in >> temp;
            Circle blah (temp);
            Shapes.push_back(blah);
            

        }
        if (tmp == "sphere")
        {
            FileReader >> temp;
            Sphere blah (temp);
            GenericShape generictmp(blah);
            Shapes.push_back(blah);

            
            
        }
        if (tmp == "square")
        {
            FileReader >> temp;
           Square blah(temp);
           GenericShape generictmp(blah);
           Shapes.push_back(blah);
            
        }
        if (tmp == "cube")
        {
            FileReader >> temp;
            Cube blah(temp);
            GenericShape generictmp(blah);
            Shapes.push_back(blah);
            

        }
        if (tmp == "tetrahedron")
        {
            for (size_t i=0; i< 4 ;  i++ )
            {

            string number_as_string;
            getline(FileReader, number_as_string);
            stringstream in(number_as_string);
            while (in >> temp) {
            numbers.push_back(temp);
            if (in.peek()== ',')
            in.ignore();
            }
            }
            Tetrahedron blah(Point3d(numbers[0],numbers[1],numbers[2]),Point3d(numbers[3],numbers[4],numbers[5]),Point3d(numbers[6],numbers[7],numbers[8]),Point3d(numbers[9],numbers[10],numbers[11]));
            GenericShape generictmp(blah);
            Shapes.push_back(blah);
            
        }


        
    }
    
    return true;
}
