#include "Header.h"


//       ///		STUDENT		///		///		///		

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
	avgMarks = sum / num;
	return sum / num;
}

//		///			GROUP		///		///		///

Group::Group(std::string tmp_title) {
	title = tmp_title;
}

void Group::addStudent(Student * tmp_student) {
	students.push_back(tmp_student);
	num = students.size();
}

void Group::searchStudent(int tmp_id) {
	for (int i = 0; i < num; i++) {
		if (students[i]->id == tmp_id) {
			std::cout << "Student searched" << "\n";
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
		if (students[i]->id == tmp_id) {
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

//		///			DEANERY		///		///		///


Deanery::Deanery(std::string students, std::string groups) {
	fileGroup = groups;
	fileStud = students;
}

void Deanery::create_students() {
	std::ifstream file(fileStud);
	std::string fio;
	int id = 0;
	while (std::getline(file, fio)) {
		id++;
		students.push_back(new Student(id, fio));
	}
	file.close();
	num_stud = students.size();
}

void Deanery::create_groups() {
	std::ifstream file(fileGroup);
	std::string title;
	while (std::getline(file, title)) {
		groups.push_back(new Group(title));
	}
	file.close();
	num_group = groups.size();
	int n = num_stud / num_group;
	for (int i = 0; i < num_group; i++) {
		for (int j = i * n; j < (i + 1)* n; j++) {
			students[j]->addGroup(groups[i]);
			groups[i]->addStudent(students[j]);
		}
	}
}


void Deanery::add_marks() {
	for (int i = 0; i < num_stud; i++) {
		for (int j = 0; j < 4; j++) {
			students[i]->addMark(rand() % 5 + 1);
		}
	}
}

void Deanery::get_stat() {

	std::ofstream file;
	file.open("statistics.txt");
	file << "STUDENTS" << std::endl;
	if (file.is_open()) {
		for (int i = 0; i < num_stud; i++) {
			file << students[i]->fio << " - " << students[i]->averMarks() << std::endl;
		}
		for (int i = 0; i < num_group; i++) {
			file << groups[i]->title << " - " << groups[i]->avgGroup() << std::endl;
		}
	}
	file.close();
}


void Deanery::move_student(std::string fio, std::string new_group) {
	for (int i = 0; i < num_stud; i++) {
		if (students[i]->fio == fio) {
			for (int j = 0; j < num_group; j++) {
				if (groups[j]->title == new_group) {
					students[i]->group->kickStudent(students[i]->id);
					students[i]->addGroup(groups[j]);
					groups[j]->addStudent(students[i]);
					break;
				}
			}
		}
	}
}


void Deanery::kick_student() {
	for (int i = 0; i < num_stud; i++) {
		if (students[i]->averMarks() < 2) {
			students[i]->group->kickStudent(students[i]->id);
			students.erase(students.begin() + i);
			num_stud--;
		}
	}
}

void Deanery::update() {

}

void Deanery::init_head() {
	for (int i = 0; i < num_group; i++) {
		groups[i]->electHead();
	}
}

void Deanery::print() {
	std::cout << "Number of students is" << num_stud << std::endl;
	for (int i = 0; i < num_group; i++) {
		std::cout << " In group: "<< groups[i]->title << " Students: " << groups[i]->num << " Average in group: " << groups[i]->avgGroup() <<
			" Headman: "<< groups[i]->head->fio << std::endl;
		for (int j = 0; j < groups[i]->num; j++) {
			std::cout << groups[i]->students[j]->fio << " average mark: " << groups[i]->students[j]->averMarks() << " ID: " << groups[i]->students[j]->id << std::endl;
			std::cout << "All marks: ";
			for (int k = 0; k < groups[i]->students[j]->marks.size(); k++) {
				std::cout << groups[i]->students[j]->marks[k] << " ";
			}
			std::cout << std::endl;
		}
	}
}