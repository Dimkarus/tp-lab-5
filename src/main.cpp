#include "Header.h"



int main() {
	Deanery deanery("Students.txt", "Groups.txt");
	deanery.create_students();
	deanery.create_groups();
	deanery.add_marks();
	deanery.init_head();
	deanery.kick_student();
	deanery.get_stat();
	deanery.print();
	system("pause");
	return 0;
}