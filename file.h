#pragma once

typedef struct {
	char id[20];
	char name[40];
	char address[40];
	char specialized[50];
}Student;

// ham them sinh vien
void addStudent(Student* student);
// ham hien thi danh sach sinh vien
void showListStudent(Student* student, size_t n);
// ham tim kiem sinh vien
int findStudent(Student* student, size_t n, char*id);
// ham doc file sinh vien
void readFileStudent(Student* student, size_t* n);
// ham ghi file sinh vien
void writeFileStudent(Student* student, size_t n);


#pragma once

typedef struct {
	char id[10];
	char name[30];
	int credits;
}Subject;

// ham nhap mon hoc
void addSubject(Subject* subject);
// ham hien thi danh sach mon hoc
void showListSubject(Subject* subject, size_t n);
// ham tim kiem mon hoc
int findSubject(Subject* subject, size_t n, char* id);
// ham doc file mon hoc
void readFileSubject(Subject* subject, size_t* n);
// ham ghi file mon hoc
void writeFileSubject(Subject* subject, size_t n);


#pragma once
#include<stdio.h>
#include"student.h";
#include"subject.h";
#include<string.h>

typedef struct {
	char id[10];
	Student student;
	Subject subject;
	float grades10;
	float grades20;
	float grades30;
	float grades40;
	float grades;
	char rank[10];
}Transcript;

// ham nhap diem mon hoc
void enterGrades(Transcript* transcript);
// ham hien thi bang diem
void showTranscript(Transcript* transcript, size_t n);
// ham tim kiem bang dien
int findTranscript(Transcript* transcript, size_t n, char* id);
// ham doc bang diem tu file
void readFileTranscript(Transcript* transcript, size_t* n);
// ham ghi bang diem ra file
void writeFileTranscript(Transcript* transcript, size_t n);

//int findStudentAndSubject(Student* student, Subject* subject, char* idStudent, char* idSubject, size_t n);

int testSubjectAndStudentInTranscript(Transcript* transcript, size_t n, char* idStudent, char* idSubject);
// tinh diem tong ket
void calculatorGrades(Transcript* transcript, size_t n);
// kiem tra xep loai
void calculatorRanking(Transcript* transcript, size_t n);
// hien thi bang diem
void showTranscript(Transcript* transcript, size_t n);
// sap xep bang diem
void sortTranscript(Transcript* transcript, size_t n);

void findStudentGrades(Transcript* transcript, size_t n, float x);

void findStudentRank(Transcript* transcript, size_t n, char* r);

void updateGrades(Transcript* transcript, float newGrades10, float newGrades20, float newGrades30,
	float newGrades40);
