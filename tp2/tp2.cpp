
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
	int flag = 0; // no dots in line
	int lastdot;
	while(file){

		flag = 0;
		lastdot = 0;
		getline(file, buf);
		bufsize = buf.size();
		for (int i = 0; i < bufsize; i++){
			if (buf[i] == '.'){
				sent = sent + buf.substr(lastdot, i+1);
				lastdot = i+1;
				flag = 1;
		        //cout << sent << endl;
				for(int i = 0; i < sent.size(); i++){
					if(sent[i] == ','){
						cout << sent << endl;
						break;
					}
				}
				sent = "";
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



