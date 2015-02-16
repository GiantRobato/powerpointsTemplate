#include "dhtml.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string startHTML(){
	string x;
	x.append("<!DOCTYPE html>\n<html>\n");
	return x;
}

string addHead(){
	string x;
	x.append(loadFileIntoString("../data/head.data"));
	x.append("\n");

	return x;
}

string startReveal(){
	string x;
	x.append(loadFileIntoString("../data/startReveal.data"));
	x.append("\n");

	return x;
}

string endReveal(){
	string x;
	x.append(loadFileIntoString("../data/endReveal.data"));
	x.append("\n");
	return x;
}

string loadSection(string fname){
	string x;
	x.append(loadFileIntoString(fname));
	x.append("\n");
	return x;
}

string reformatString(string s){
	string x;
	for(unsigned int i = 0; i < s.length(); i++){
		char c = s.at(i);
		if(c == '<'){
			x.append("&lt;");
		} else if (c == '>'){
			x.append("&gt;");
		} else {
			x += c;
		}
	}
	return x;
}

string insertCodeSlide(string fname){
	string x;
	x.append(loadFileIntoString("../data/startCodeSection.data"));
	ifstream input(fname.c_str());

	//go through each line
	string line;
	while(getline(input, line)){
		//replace < with &lt; and > with &gt;
		line = reformatString(line);
		x.append(line);
		if(input.eof()) break; 	//break right after copying last line in order
								//to not output final \n which causes cmp in
								//testing script to fail
		x.append("\n");
	}
	x.append(loadFileIntoString("../data/endCodeSection.data"));

	return x;
}


string loadFileIntoString(string fname){
	string x;
	ifstream input(fname.c_str());

	//go through each line
	string line;
	while(getline(input, line)){
		x.append(line);
		if(input.eof()) break; 	//break right after copying last line in order
								//to not output final \n which causes cmp in
								//testing script to fail
		x.append("\n");
	}
	return x;
}

string addRevealIncludes(){
	string x;
	x.append(loadFileIntoString("../data/includesForReveal.data"));
	return x;
}

string addP(){
	string x;
	x.append("HTML");
	return x;
}

string endHTML(){
	string x;
	x.append("</html>");
	return x;
}