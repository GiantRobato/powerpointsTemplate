#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* arv[]){
	ofstream myfile; //create a output file stream
	myfile.open("example.txt"); //create file example.txt
	myfile << "Writing this to file.";
	myfile.close();
	return 0;
}