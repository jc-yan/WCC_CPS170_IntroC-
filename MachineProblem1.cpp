#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
    //set up the input value
    double len_cm = 0;
    cout << "Geometry formulas by Jiachen Yan\n";
    cout << "Enter one floating point number for length: ";
    cin >> len_cm;

    double len_m = len_cm/100.0; // transfer centimeters to meters
    const double pi = 3.14159; //pi
    double radius = len_m/2; //the radius of the circle
    double len_m_down = floor(len_m); //the round down length
    double len_m_up = ceil(len_m); //the round up length

    //print the output results
    cout << "\nThe number you entered is " << len_cm << " cm or " << len_m << " m.\n";
    cout << "Area of square: " << pow(len_m, 2) << " sq. m.\n"; //area of the square
    cout << "Area of circle: " << pi * pow(radius, 2) << " sq. m.\n"; //area of the circle
    cout << "Difference is " << pow(len_m, 2) - pi * pow(radius, 2) << " sq. m.\n"; //difference in square & circle

    cout << "\nCube volume rounded down is " << pow(len_m_down, 3) << " cu. m.\n";
    cout << "Cube volume rounded up is " << pow(len_m_up, 3) << " cu. m.\n"; 

    //end the program
    cout << "Press any key to continue\n";
    cin.ignore();
    cin.get();
}