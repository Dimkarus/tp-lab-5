#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream> 
using namespace std;

class Group;

class Student 
{
	friend class Group;
	friend class Deanery;

private:
	int id; //����������������� �����
	string fio; //������� � ��������
	Group * group; //������ �� ������ (������ Group)
	vector<int> marks; //������ ������
	int num; //���������� ������

public:
	Student(int, string);//�������� �������� � ��������� �� � ���
	void addMark(unsigned int);//���������� ������
	float midMark();//���������� ������� ������
	string getFio();//�������� ���
	int getid();//�������� ID
	vector<int> getMarks();//�������� ������
	void GroupEnter(Group *group);//���������� � ������
	Group * getGroup();//�������� ������
};


class Group {
	friend class Deanery;

private:
	string title; //�������� ������
	vector<Student *> students; //������ �� ������ �� ���������
	Student * head; //������ �� �������� (�� ������ ������)
	int num; //���������� ��������� � ������

public:
	Group(string);//�������� ������ � ��������� ��������
	void addStudent(Student *);//���������� ��������
	Student * electionHead();//�������� ��������
	Student * searchFio(string);//����� �������� �� ���
	Student * searchId(int);//����� �������� �� ��
	float averageGroup();//���������� �������� ����� � ������
	void deductFio(string);//���������� �������� �� ������
	void deductId(int);//���������� �������� �� ������
};



class Deanery {
private:
	string fileStudent, fileGroup;
	vector<Student *> students;//������ ���������
	vector<Group *> groups;//������ �����
	int numStudent, numGroup;

public:
	Deanery(string, string);
	void CreateGroup(); //�������� ����� �� ������ ������ �� �����
	void CreateStudent();//�������� ��������� �� ������ ������ �� �����
	void addRandomMarks();//���������� ��������� ������ ���������
	vector<pair<float, string>> getStatisticStudents();//��������� ���������� �� ������������ ���������
	vector<pair<float, string>> getStatisticGroup();//��������� ���������� �� ������������ �����
	Student * searchFio(string);//����� �������� �� �����
	Group * searchGroup(string);//����� ������
	void changeGroup(string, string);//������� ��������� �� ������ � ������
	void Studentdeduction();//���������� ��������� �� ��������������
	void electionGroupHead();//��������� ������� ������� � �������
	void print();//����� ������ �� �������
	void printFile();//���������� ����������� ������ � ������
};