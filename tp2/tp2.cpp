
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
		exit(EXIT_FAILURE);
    }
	int isPointInLine, isCommaInSent; // no "." / no ","
	int lastdot;
	while(file){
		/*
		� ���������� sent ���������� �������������� � ������ ������ �����������.
		�����������, ��� ����������� ����������� ������. 
		�� ������� ���������� ��������� ����� ���������� ������ ����������� �� ������� �������.
		*/
		isPointInLine = 0;
		lastdot = 0;
		getline(file, buf);
		bufsize = buf.size();
		for (int i = 0; i < bufsize; i++){
			if (buf[i] == ','){
				isCommaInSent = 1;
			}
			if (buf[i] == '.'){
				sent = sent + buf.substr(lastdot, i+1);
				lastdot = i+1;
				isPointInLine = 1;
				if (isCommaInSent == 1)
					cout << sent << endl;
				sent = "";
				isCommaInSent = 0;
			}
		}
		if (isPointInLine == 0){
			sent = sent + buf.substr(lastdot);
		}
		if (file.eof())
			break;
	}
	file.close();
	return 0; 
}



