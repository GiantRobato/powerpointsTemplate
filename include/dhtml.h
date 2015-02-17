#ifndef __DHTML__
#define __DHTML__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string startHTML();
string addHead();
string addP();
string startReveal();
string endReveal();
string reformatString(string s);
string loadSection(string fname);
string loadFileIntoString(string fname);
string insertCodeSlide(string fname);
string generateHead(string fname);
//string loadFormattedSection(string fname); //TODO this one
string addRevealIncludes();
string endHTML();

#endif