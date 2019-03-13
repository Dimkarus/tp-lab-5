#include "Deanery.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <ctime>

//Class Deanery

Deanery::Deanery(string NameStudents,string NameGroups) {
	fileStudents = NameStudents;
	fileGroups = NameGroups;
}

void Deanery::CreateStudents() {
	ifstream file(fileStudents);
	string fioStudent;
	int id = 100;
	while (getline(file, fioStudent)) {
		id++;
		students.push_back(new Student(id, fioStudent)); //create vector students 
	}
	file.close();

	numSt = students.size();
}

void Deanery::CreateGroups() {
	ifstream file(fileGroups);
	string nameGroup;
	while (getline(file, nameGroup)) {
		groups.push_back(new Group(nameGroup)); // create vector groups
	}
	file.close();

	numGr = groups.size();
	

	int numinGr = numSt / numGr;  //number in group = number of students/number og groups
	for (int i = 0; i < numGr; i++) {        //distribution in groups
		for (int j = i*numinGr; j < (i+1)*numinGr; j++) {
			students[j]->enterGroup(groups[i]); //зачисление в группу
			groups[i]->addStudent(students[j]);    //добалление студента в группу
		}
	}
	int extraSt = numSt % numGr;
	for(int j = 0; j < extraSt; j++ ) {
		students[numinGr*numGr + j]->enterGroup(groups[numGr - 1]); //extra students in last group
		groups[numGr - 1]->addStudent(students[numinGr*numGr + j]);
	}
}

void Deanery::addMarks() {
	int mark;
	for (int i = 0; i < numSt; i++) {
		for (int n = 0; n < 8; n++) {
		
			mark = rand() % 10 + 1;
			students[i]->addMark(mark);
		}
	}
}

void Deanery::changeGroup(string nameSt, string nameNewGr) {
	for (int i = 0; i < numSt; i++) {
		if (students[i]->fio == nameSt) { //search student
			for (int k = 0; k < numGr; k++) {
		        if (groups[k]->title == nameNewGr) {  //search new group 
					Group * presentGr = students[i]->group;
					students[i]->enterGroup(groups[k]);
					groups[k]->addStudent(students[i]);  
					presentGr->exceptionStudent(students[i]->fio);//except from previos group
		        }
	        }
			
		}
	}
}

void Deanery::exceptionStudent() {
	for (int i = 0; i < numSt; i++) {
		if (students[i]->averageMark() < 4) {
			students[i]->group->exceptionStudent(students[i]->fio); //refer to student's group through the pointer to group in the class Student
			students.erase(students.begin() + i);
			numSt--;
			i--;
		}
	}
}

void Deanery::electGhead() {
	for (int i = 0; i < numGr; i++) {
		groups[i]->electHead();
	}
}

void Deanery::getStatistics(string name) {

	for (int i = 0; i < numSt; i++) {  //about all students
		StStat.push_back(pair<float, string>(students[i]->averageMark(), students[i]->fio));
	}sort(StStat.begin(), StStat.end());

	for (int j = 0; j < numGr; j++) {  //about all students
		GrStat.push_back(pair<float, string>(groups[j]->averageGroup(), groups[j]->title));
	}sort(GrStat.begin(), GrStat.end());

	ofstream file;
	file.open(name);
	if (file.is_open())
	{	
		for (int j = 0; j < StStat.size(); j++){
			file << StStat[j].second << "-" << StStat[j].first<< endl;
		}	
		for (int i = 0; i < GrStat.size(); i++) {
			file << GrStat[i].second << "  -  " << GrStat[i].first << endl;
		}
	}file.close();	
}

void Deanery::update(string name) { //writing updated data to file
	ofstream file;
	file.open(name);
	
	if (file.is_open())
	{
		file <<"Number students is  "<<numSt<<endl;
		for (int i = 0; i < numGr; i++) {
			file << "В " << groups[i]->title<<" "<<groups[i]->num<<" человек. "<<" Средний балл по группе "<<groups[i]->averageGroup()<<endl;
			file << "Староста группы " << groups[i]->head->fio << endl;
			for (int j = 0; j < groups[i]->students.size(); j++) {
				file << groups[i]->students[j]->fio<<"-"<<groups[i]->students[j]->averageMark()<<"   ";
				for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
					file << groups[i]->students[j]->marks[h]<<" ";
				}
				file << endl;
			}
			file << endl;
		}
	}file.close();
}

void Deanery::printinfo() {
	cout << "Number students is  " << numSt << endl;
	
	for (int i = 0; i < numGr; i++) {
		cout << "В " << groups[i]->title << " " << groups[i]->num << " человек. " << " Средний балл по группе " << groups[i]->averageGroup() << endl;
		cout << "Староста группы "<<groups[i]->head->fio<<endl;
		for (int j = 0; j < groups[i]->students.size(); j++) {
			cout << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->averageMark()<<"    ";
			for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
				cout << groups[i]->students[j]->marks[h]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout<< endl << "Statistics" << endl;
	for (int j = 0; j < StStat.size(); j++) {
		cout << StStat[j].second << "-" << StStat[j].first << endl;
	}

	for (int i = 0; i < GrStat.size(); i++) {
		cout << GrStat[i].second << "  -  " << GrStat[i].first << endl;	
	}
}
