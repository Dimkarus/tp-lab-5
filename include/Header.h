#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Group;
class Deanery;

//       ///		STUDENT		///		///		///	

class Student {
	friend Group;
	friend Deanery;
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

//		///			GROUP		///		///		///

class Group {
	friend Deanery;
private:
	std::string title;
	std::vector<Student *> students;		// students in group
	Student *head;							// headman
	int num;								// number of students

public: 
	Group(std::string tmp_title);
	void addStudent(Student * tmp_student);
	void searchStudent(int tmp_id);
	double avgGroup();
	void kickStudent(int tmp_id);
	void electHead();
};

//		///			DEANERY		///		///		///

class Deanery {
private:
	std::vector<Group*> groups;				// all groups
	std::vector<Student*> students;			// all students
	int num_stud, num_group;				// number of students and groups
	std::string fileStud;
	std::string fileGroup;

public:
	Deanery(std::string, std::string);
	void create_students();
	void create_groups();
	void add_marks();
	void get_stat();
	void move_student(std::string, std::string);
	void kick_student();
	void update();
	void init_head();
	void print();
};