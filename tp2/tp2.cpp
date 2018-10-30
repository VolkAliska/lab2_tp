
#include "stdafx.h"
using namespace std;

int main() {
	string sent, buf;
	int bufsize;
	ifstream file;
	try{
		file.open("file.txt", ios::in);
	}
	catch(const ifstream::failure& e){
		cout << "Exception opening/reading file";
    }
	int flag, flagz; // no "." / no ","
	int lastdot;
	while(file){
		/*
		В переменную sent помещается обрабатываемое в данный момент предложение.
		Принимается, что предложения разделяются точкой. 
		До момента нахождения следующей точки происходит анализ предложения на наличие запятой.
		*/
		flag = 0;
		lastdot = 0;
		getline(file, buf);
		bufsize = buf.size();
		for (int i = 0; i < bufsize; i++){
			if (buf[i] == ','){
				flagz = 1;
			}
			if (buf[i] == '.'){
				sent = sent + buf.substr(lastdot, i+1);
				lastdot = i+1;
				flag = 1;
				if (flagz == 1)
					cout << sent << endl;
				sent = "";
				flagz = 0;
			}
			else{
				if((buf[i] != ' ') && (buf[i] != '\n'))
					flag = 0;
			}
		}
		if (flag == 0){
			sent = sent + buf.substr(lastdot);
		}
		if (file.eof())
			break;
	}
	file.close();
	return 0; 
}



