#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>  
#include "Classes.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	Student stud1(10001, "��������� ��������� ���������");
	Student stud2(10002, "���-�� ��� ���");

	stud1.addMark(5);
	stud1.addMark(4);
	stud1.addMark(5);
	stud2.addMark(3);
	stud2.addMark(4);
	stud2.addMark(5);

	float a1 = stud1.averageMark();
	float a2 = stud2.averageMark();
	cout << "������� ������ ���������� = " << a1 << endl;
	cout << "������� ������ ����-�� ��� = " << a2 << endl;

	cout << "Id ����������: " << stud1.getId() << endl;

	
	Group gr1("17���-1");
	gr1.addStudent(&stud1);
	gr1.addStudent(&stud2);
	
	Student * headd = gr1.electHead();
	cout << "�������� ������1 - " << headd->getFio() << endl;

	cout << "������� ������ � ������1 = " << gr1.averageGroup() << endl;
	gr1.deductFio("��������� ��������� ���������");
	cout << "������� ������ � ������1 ����� ���������� ����������= " << gr1.averageGroup() << endl;


	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;


	Deanery dean("students.txt", "groups.txt");
	dean.addGr();
	dean.addSt();
	dean.addRMarks();
	dean.electGrHead();
	cout << "����� ������\n" << endl;
	dean.print();
	dean.deductSt();
	cout << "\n\n����� ������ ����� ���������� ������������\n" << endl;
	dean.print();
	dean.printFile("outf.txt");
	
	system("pause");
}