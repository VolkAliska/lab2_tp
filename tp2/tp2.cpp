
#include "stdafx.h"
using namespace std;

int main() {
	string sent, buf;
	ifstream file;
	file.open("file.txt", ios::in);
	if(!file){
		cout << "error" << endl;
	}
	cout << "reading" << endl;
	
	getline(file, sent);
	cout << sent;
	file.close();
	return 0; 
}



