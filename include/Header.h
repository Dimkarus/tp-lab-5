#pragma once
#include <iostream>
#include <string>
#include <vector>

class Group;

class Student {
	friend Group;
private:
	int id;
	std::string fio;
	Group *group;
	std::vector<int> marks;
	int num;
	double avgMarks;
public:
	Student(int id, std::string fio);
	void addGroup(Group *tmp_group);
	void addMark(int tmp_mark);
	double averMarks();
};

class Group {
private:
	std::string title;
	std::vector<Student *> students;
	Student *head;
	int num;

public: 
	Group(std::string tmp_title);
	void addStudent(Student * tmp_student);
	Student * searchStudent(int tmp_id);
	double avgGroup();
	void kickStudent(int tmp_id);
	void electHead();
};