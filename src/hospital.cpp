//============================================================================
// Name        : hospital.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int,deque<string>>specLimit;
deque<int> temp;
void read();
bool validSpec(int spec){
	return spec>0 && spec<21;
}
bool validStatus(int status) {
	return status==0 || status==1;
}
void addNewPatient() {
	int spec,status;
	string name;
	cout<<"Enter specialization, name, status:";
	cin>>spec>>name>>status;
	if(validStatus(status) && validSpec(spec)){
		if(specLimit[spec].size()<5){
			if(status==0){
				specLimit[spec].push_back(name);
			}else
				specLimit[spec].push_front(name);
		}else{
			cout<<"No more patient";
		}
		read();
	}else{
		addNewPatient();
	}
}
void printAllPatients() {
	for(auto i : specLimit){
		cout<<"specialization: "<<i.first<<endl;
		deque<string>temp = i.second;
		int j=1;
		while(!temp.empty()) {
			cout<<j<<"- "<<temp.front()<<endl;
			temp.pop_front();
			j++;
		}
	}
	read();
}
void getNextPatient() {
	int spec;
	cout<<"Enter specialization:";
	cin>>spec;
	if(specLimit.find(spec) == specLimit.end()){
		cout<<"no patients";
		read();
		return;
	}
	deque<string>patients = specLimit[spec];
	if(patients.size()==0){
		cout<<"no patients";
	}else{
		cout<<"Please "<<patients.front()<<" go to doctor";
		patients.pop_front();
		specLimit[spec] = patients;
	}
	read();
}
void read() {
	int choice = -1;
	while(choice == -1){
		cout<<"Enter your choice:"<<endl;
		cout<<"1) Add new patient"<<endl;
		cout<<"2) Print all patients"<<endl;
		cout<<"3) Get next patient"<<endl;
		cout<<"4) Exit"<<endl;
		cin>>choice;
		if(choice == 1){
			addNewPatient();
		}else if(choice == 2){
			printAllPatients();
		}else if(choice==3){
			getNextPatient();
		}else if(choice == 4){
			break;
		}else{
			choice=-1;
		}
	}
	return;
}
int main() {

	read();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
