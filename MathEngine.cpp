// MathEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"
#include "Matrix3.h"
#include "Quaternion3.h"

int main()
{
	//declare 2 vectors
	/*Engine::Vector3 Vec1(2, 3, 1);
	Engine::Vector3 Vec2(1, 2, 0);

	Vec1.print();
	Vec2.print();

	Engine::Vector3 Vec3;

	float s = 2.0;

	Vec3 = Vec1 % Vec2;
	Vec3.print();

	std::cout << "The magnitude of Vec1: " << Vec1.magnitude() << std::endl;
	//std::cout << dot << " " << std::endl;
	Vec1.normalize();
	Vec1.print();*/

	Engine::Matrix3 mat1{ 2,1,4,3,4,1,2,1,1 };
	Engine::Matrix3 mat2{ 3,2,1,5,3,3,4,2,1 };
	Engine::Vector3 v{ 0,1,0 };

	Engine::Vector3 axis{1,0,0};
	//Engine::Quaternion3 quat{ 90, axis };
	
	//mat1 = mat1 + mat2;
	//Engine::Matrix3 res = mat1 * mat2;
	
	//mat1.getInverseMatrix();
	//res = mat1 * v;

	//mat1.print();

	//rotate the vector v by axis by 90 degrees
	Engine::Vector3 rotatedV = v.rotateVec(90, axis);

	v.print();
	rotatedV.print();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
