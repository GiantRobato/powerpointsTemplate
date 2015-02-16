#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* arv[]){
	ofstream myfile; //create a output file stream
	ifstream input("../tests/testHTML.data"); 		//create input file
	myfile.open("testHTML.html"); 					//create file example.txt

	//go through each line
	string line;
	while(getline(input, line)){
		myfile << line;
		if(input.eof()) break; 	//break right after copying last line in order
								//to not output final \n which causes cmp in
								//testing script to fail
		myfile << "\n";
	}
	myfile.close();
	return 0;
}