#include "Deanery.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <ctime>

//Class Croup
 
Group::Group(string name) {
	title = name;
}

void Group::addStudent(Student * Groupmember) {
	
	students.push_back(Groupmember);
	num = students.size();
	
}

Student * Group::electHead() {
	int i = rand() % (num - 1) + 0;
	head = students[i];
	return students[i];
}

Student* Group::searchSfio(string name) {
	for (int i = 0; i < num; i++) {
		if(students[i]->fio==name){
			return students[i];
		}
	}
}

Student* Group::searchSid(int numid) {
	for (int i = 0; i < num; i++) {
		if (students[i]->id == numid) {
			return students[i];
		}
	}
}

float Group::averageGroup() {
	int sum=0;
	for (int i = 0; i < num; i++) {
		sum += students[i]->averageMark();
	}
	return sum / num;
}

void Group::exceptionStudent(string name) {
	for (int i = 0; i < num; i++) {
		if (students[i]->fio == name) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				num--;
				electHead();
			}
			else {
				students.erase(students.begin() + i);
				num--;
			}
		}
	}
}