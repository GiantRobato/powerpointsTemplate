//DATA
#include <iostream>
#include <fstream>
#include <string>
#include "dhtml.h"

using namespace std;

int main(int argc, char* argv[]){
	ofstream myfile; //create a output file stream
	myfile.open("testWriteHTML.html"); 					//create file example.txt

	myfile << startHTML();
	myfile << addHead();
	myfile << startReveal();

	//add actual slides here
	//myfile << addSlide("")
	//myfile << loadSection("../data/testSection.html");
	myfile << insertCodeSlide("../src/testWriteHTML.cpp");
	//myfile << insertCodeSlide("./src/testWriteHTML.cpp");

	myfile << endReveal();
	myfile << addRevealIncludes();
	myfile << endHTML();

	myfile.close();
	return 0;
}