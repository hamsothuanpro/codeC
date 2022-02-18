#include<stdio.h>
#include"student.h";
#include"subject.h";
#include"transcript.h";

int main() {
	int choice;
	Subject subject[20];
	size_t numOfsubject = 0;
	Student student[100];
	size_t numOfstudent = 0;
	Transcript transcript[100];
	size_t numOftranscript = 0;
	do
	{
		puts("=============QUAN LY BANG DIEM SINH VIEN============");
		puts("1.Them thong tin mon hoc vao danh sach");
		puts("2.Hien thi danh sach mon hoc");
		puts("3.Them thong tin sinh vien moi");
		puts("4.Hien thi danh sach sinh vien");
		puts("5.Tao bang diem cho sinh vien");
		puts("6.Tinh diem tong ket va xep loai");
		puts("7.Hien thi thong tin bang diem");
		puts("8.Sap xep bang diem giam dan diem tong ket");
		puts("9.Tim cac sinh vien co diem tong ket bang x trong bang diem");
		puts("10.Tim cac sinh vien xep loai y");
		puts("11.Cap nhat diem sinh vien");
		puts("12.Ghi du lieu ra FILE");
		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			puts("============CAM ON QUY KHACH DA SU DUNG DICH VU=============");
			break;
		case 1:
		{
			system("cls");
			//Subject sub;
			char idSub[10];
			printf("Nhap ID mon hoc: ");
			scanf("%9s", idSub);
			int indexSubject = findSubject(subject, numOfsubject, idSub);
			if (indexSubject > -1) {
				puts("==========MON HOC DA DUOC TAO TRUOC DO=============");
			}
			else {
				strcpy(subject[numOfsubject].id, idSub);
				addSubject(&subject[numOfsubject]);
				//subject[numOfsubject++] = sub;
				numOfsubject++;
			}
			break;
		}
		case 2: 
		{
			system("cls");
			showListSubject(subject, numOfsubject);
			break;
		}
		case 3:
		{
			system("cls");
			char idStudent[20];
			printf("Nhap ID sinh vien: ");
			scanf("%19s", idStudent);
			int index = findStudent(student, numOfstudent, idStudent);
			if (index > -1) {
				puts("===========SINH VIEN DA DUOC TAO TRUOC DO============");
			}
			else {
				strcpy(student[numOfstudent].id, idStudent);
				addStudent(&student[numOfstudent]);
				numOfstudent++;
			}
			break;
		}
		case 4:
		{
			system("cls");
			showListStudent(student, numOfstudent);
			break;
		}
		case 5:
		{
			system("cls");
			char idTrans[10];
			printf("Nhap ID bang diem: ");
			scanf("%9s", idTrans);
			int index = findTranscript(transcript, numOftranscript, idTrans);
			if (index > -1) {
				puts("=========BANG DIEM DA DUOC TAO TRUOC DO=============");
			}
			else {
				char idStudent[20];
				printf("Nhap ID sinh vien: ");
				scanf("%19s", idStudent);
				int checkStudent = findStudent(student, numOfstudent, idStudent);
				if (checkStudent == -1) {
					puts("===============SINH VIEN NAY KHONG CO TRONG DANH SACH============");
					break;
				}
				char idSubject[10];
				printf("Nhap ID mon hoc: ");
				scanf("%9s", idSubject);
				int checkSubject = findSubject(subject, numOfsubject, idSubject);
				if (checkSubject == -1) {
					puts("============MON HOC KHONG CO TRONG DANH SACH=============");
					break;
				}
				int check = testSubjectAndStudentInTranscript(transcript, numOftranscript, idStudent, idSubject);
				if (check > -1) {
					puts("==========SINH VIEN NAY DA DUOC TAO TRONG BANG DIEM KHAC===========");
				}
				else {
					strcpy(transcript[numOftranscript].id, idTrans);
					transcript[numOftranscript].subject = subject[checkSubject];
					transcript[numOftranscript].student = student[checkStudent];
					enterGrades(&transcript[numOftranscript]);
					numOftranscript++;
				}
			}
			break;
		}
		case 6:
		{
			system("cls");
			calculatorGrades(transcript, numOftranscript);
			calculatorRanking(transcript, numOftranscript);
			puts("=========TINH DIEM TONG KET VA XEP LOAI XONG============");
			break;
		}
		case 7:
		{
			system("cls");
			showTranscript(transcript, numOftranscript);
			break;
		}
		case 8:
		{
			system("cls");
			sortTranscript(transcript, numOftranscript);
			puts("============SAP XEP THANH CONG=============");
			showTranscript(transcript, numOftranscript);
			break;
		}
		case 9:
		{
			system("cls");
			float x;
			printf("Nhap diem sinh vien: ");
			scanf("%f", &x);
			//findStudentGrades(transcript, numOftranscript, x);
			printf("Cac sinh vien co diem tong ket bang %f:\n", x);
			findStudentGrades(transcript, numOftranscript, x);
			break;
		}
		case 10:
		{
			system("cls");
			char r[10];
			printf("Nhap xep loai sinh vien: ");
			scanf("%9s", r);
			printf("Cac sinh vien co xep loai %s:\n ",r);
			findStudentRank(transcript, numOftranscript, r);
			break;
		}
		case 11:
		{
			system("cls");
			float grades10, grades20, grades30, grades40;
			char idTranscript[10];
			printf("Nhap ma bang diem: ");
			scanf("%9s", idTranscript);
			int index = findTranscript(transcript, numOftranscript,idTranscript);
			if (index > -1) {
				puts("===========THONG TIN MOI VE DIEM SINH VIEN=============");
				printf("Diem chuyen can: ");
				scanf("%f", &grades10);
				printf("Diem gk: ");
				scanf("%f", &grades20);
				printf("Diem bai tap: ");
				scanf("%f", &grades30);
				printf("Diem cuoi ki: ");
				scanf("%f", &grades40);
				updateGrades(transcript, grades10, grades20, grades30, grades40);
				puts("=============DA CAP NHAT XONG=============");
			}
			else {
				puts("=============BANG DIEM KHONG TON TAI==============");
			}
			break;
		}
		default:
			break;
		}

	} while (choice!=0);
	return 0;
}
