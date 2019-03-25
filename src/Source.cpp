#include "Header.h"


Student::Student(int tmp_id, std::string tmp_fio) {
	id = tmp_id;
	fio = tmp_fio;
}

void Student::addGroup(Group *tmp_group) {
	this->group = tmp_group;
}

void Student::addMark(int tmp_mark) {
	marks.push_back(tmp_mark);
	num = marks.size();
}

double Student::averMarks() {
	int sum = 0;
	for (int i = 0; i < num;i++)
		sum += marks[i];
	return sum / num;
}

Group::Group(std::string tmp_title) {
	title = tmp_title;
}

void Group::addStudent(Student * tmp_student) {
	students.push_back(tmp_student);
	num = students.size();
}

Student * Group::searchStudent(int tmp_id) {
	for (int i = 0; i < num; i++) {
		if (students[i]->id == tmp_id) {
			std::cout << "Student searched" << "\n";
			return students[i];
		}
		else
			std::cout << "Student not find" << "\n";
	}
}

double Group::avgGroup() {
	double sum = 0;
	for (int i = 0; i < num; i++) 
		sum += students[i]->avgMarks;
	return sum / num;
}

void Group::electHead() {
	if (students.size() == 0)
		head = students[0];
	else
		head = students[rand() % students.size()];
}

void Group::kickStudent(int tmp_id) {
	for (int i = 0; i < num; i++) {

	}
}