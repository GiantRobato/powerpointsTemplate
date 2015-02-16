//DATA
#include <iostream>
#include <fstream>
#include <string>
#include "dhtml.h"

using namespace std;

int main(int argc, char* argv[]){
	string s;
	string x;
	s.append("<<d");
	cout << s << endl;
	for(unsigned int i = 0; i < s.length(); i++){
		char c = s.at(i);
		if(c == '<'){
			cout << "&lt;" << endl;
			x.append("&lt;");
		} else if (c == '>'){
			cout << "&gt;" << endl;
			x.append("&gt;");
		} else {
			x += c;
		}
		//x +=c;
	}

	cout << x << endl;

	return 0;
}