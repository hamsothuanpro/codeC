#include<stdio.h>
#include<string.h>
#include"student.h";
#include"subject.h";
#include"transcript.h";

// ham nhap diem mon hoc
void enterGrades(Transcript* transcript) {
	puts("=============THONG TIN BANG DIEM SINH VIEN===============");
	printf("Nhap diem chuyen can: ");
	scanf("%f", &transcript->grades10);
	printf("Nhap diem kt giua ky: ");
	scanf("%f", &transcript->grades20);
	printf("Nhap diem BT lon: ");
	scanf("%f", &transcript->grades30);
	printf("Nhap diem kt cuoi ky: ");
	scanf("%f", &transcript->grades40);
	transcript->grades = 0;
	transcript->rank[0] = "\0";

}
// ham hien thi bang diem
/*
void showTranscript(Transcript* transcript, size_t n) {
	if (n > 0) {
		puts("=========DANH SACH BANG DIEM===========");
		printf("%-15s%-15s%-15s%-15s%-15s%-15s\n",
			"Chuyen can", "Giua ky", "Bai tap", "Cuoi ky", "Tong ket", "Xep loai");
		size_t i;
		for (i = 0; i < n; i++) {
			puts("---------------------------------------------------------------");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", transcript[i].grades10, transcript[i].grades20,
				transcript[i].grades30, transcript[i].grades40, transcript[i].grades,
				transcript[i].rank);
		}
	}
	else {
		puts("===========KHONG CO BANG DIEM CUA SINH VIEN NAO===========");
	}
}*/
// ham tim kiem bang dien
int findTranscript(Transcript* transcript, size_t n, char* id) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (strcmp(transcript[i].id, id) == 0) {
			return i;
		}
	}
	return -1;
}
// ham doc bang diem tu file
void readFileTranscript(Transcript* transcript, size_t* n) {
	FILE* fin = fopen("TRANS.TXT", "rb");
	if (fin) {
		Transcript trans;
		size_t i = 0;
		while (!feof(fin)) {
			fread(&trans, sizeof(Transcript), 1, fin);
			if (feof(fin)) {
				break;
			}
			transcript[i] = trans;
			i++;
		}
		*n = i;
		fclose(fin);
	}
	else {
		puts("============KHONG MO DUOC FILE==============");
	}
}
// ham ghi bang diem ra file
void writeFileTranscript(Transcript* transcript, size_t n) {
	FILE* fout = fopen("TRANS.TXT", "wb");
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++) {
			fwrite(&transcript[i], sizeof(Transcript), 1, fout);
		}
		puts("============GHI FILE THANH CONG============");
		fclose(fout);
	}
	else {
		puts("============KHONG TAO DUOC FILE===============");
	}
}

/*int findStudentAndSubject(Student* student, Subject* subject, char* idStudent, char* idSubject, size_t n) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (student[i].id == idStudent && subject[i].id == idSubject) {
			return i;
		}
	}
	return -1;
}*/

int testSubjectAndStudentInTranscript(Transcript* transcript, size_t n, char* idStudent, char* idSubject) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (strcmp(transcript[i].student.id, idStudent) == 0 &&
			strcmp(transcript[i].subject.id, idSubject) == 0) {
			return i;
		}
	}
	return -1;
}

void calculatorGrades(Transcript*transcript, size_t n) {
	size_t i;
	for (i = 0; i < n; i++) {
		transcript[i].grades = (transcript[i].grades10 * 0.1
			+ transcript[i].grades20 * 0.2 + transcript[i].grades30 * 0.3
			+ transcript[i].grades40 * 0.4);
	}
}

void calculatorRanking(Transcript* transcript, size_t n) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (transcript[i].grades < 4) {
			strcpy(transcript[i].rank, "F");
		}
		else if (transcript[i].grades < 5) {
			strcpy(transcript[i].rank, "D");
		}
		else if (transcript[i].grades < 5.5) {
			strcpy(transcript[i].rank, "D+");
		}
		else if (transcript[i].grades < 6.5) {
			strcpy(transcript[i].rank, "C");
		}
		else if (transcript[i].grades < 7) {
			strcpy(transcript[i].rank, "C+");
		}
		else if (transcript[i].grades < 8) {
			strcpy(transcript[i].rank, "B");
		}
		else if (transcript[i].grades < 8.5) {
			strcpy(transcript[i].rank, "B+");
		}
		else if (transcript[i].grades < 9.5) {
			strcpy(transcript[i].rank, "A");
		}
		else {
			strcpy(transcript[i].rank, "A+");
		}
	}
}

void showTranscript(Transcript* transcript, size_t n) {
	size_t i;
	if (n > 0) {
		puts("============THONG TIN BANG DIEM============");
		printf("%-10s%-10s%-20s%-15s%-15s%-15s%-15s%-15s%-15s%-20s%-15s\n",
			"ID", "Ma HP", "Mon hoc", "Chuyen can", "Giua ki", "Bai tap", "Cuoi ki",
			"Tong ket","Ma SV", "Ho ten", "Xep loai");
		//puts("-------------------------------------------"
			//"---------------------------------------------");
		for (i = 0; i < n; i++) {
			puts("-------------------------------------------"
				"---------------------------------------------"
				"------------------------------------------------"
				"---------------------------");
			printf("%-10s%-10s%-20s%-15f%-15f%-15f%-15f%-15f%-15s%-20s%-15s\n",
				transcript[i].id, transcript[i].subject.id, transcript[i].subject.name,
				transcript[i].grades10, transcript[i].grades20, transcript[i].grades30,
				transcript[i].grades40, transcript[i].grades, transcript[i].student.id,
				transcript[i].student.name, transcript[i].rank);
		}
		puts("-------------------------------------------"
			"---------------------------------------------"
			"------------------------------------------------"
			"---------------------------");
	}
	else {
		puts("===========DANH SACH TRONG==========");
	}
}


void sortTranscript(Transcript* transcript, size_t n) {
	void swapGrades(Transcript*, Transcript*);
	size_t i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (transcript[j].grades > transcript[j - 1].grades) {
				swapGrades(&transcript[j], &transcript[j - 1]);
			}
		}
	}
}

void swapGrades(Transcript* a, Transcript* b) {
	Transcript x = *a;
	*a = *b;
	*b = x;
}

void findStudentGrades(Transcript* transcript, size_t n, float x) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (transcript[i].grades == x) {
			printf("%s\n", transcript[i].student.name);
		}
	}
}

void findStudentRank(Transcript* transcript, size_t n, char* r) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (strcmp(transcript[i].rank, r) == 0) {
			printf("%s\n", transcript[i].student.name);
		}
	}
}

void updateGrades(Transcript* transcript, float newGrades10, float newGrades20,float newGrades30,
	float newGrades40) {
	transcript->grades10 = newGrades10;
	transcript->grades20 = newGrades20;
	transcript->grades30 = newGrades30;
	transcript->grades40 = newGrades40;
}
