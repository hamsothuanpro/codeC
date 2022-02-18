#include<stdio.h>
#include"student.h";
#include<string.h>

// ham them sinh vien
void addStudent(Student* student) {
	puts("===========THONG TIN SINH VIEN==========");
	printf("Nhap ten SV: ");
	scanf("%*c%39[^\n]", student->name);
	printf("Nhap dia chi: ");
	scanf("%*c%39[^\n]", student->address);
	printf("Nhap chuyen nganh: ");
	scanf("%*c%49[^\n]", student->specialized);
}
// ham hien thi danh sach sinh vien
void showListStudent(Student* student, size_t n) {
	if (n > 0) {
		puts("============DANH SACH SINH VIEN=============");
		printf("%-15s%-30s%-30s%-30s\n", "Ma SV", "Ho Ten",
			"Dia Chi", "Chuyen nganh");
		size_t i;
		for (i = 0; i < n; i++) {
			puts("-----------------------------------------------");
			printf("%-15s%-30s%-30s%-30s\n", student[i].id, student[i].name,
				student[i].address, student[i].specialized);
		}
	}
	else {
		puts("==============KHONG CO SINH VIEN TRONG DANH SACH===========");
	}
}
// ham tim kiem sinh vien
int findStudent(Student* student, size_t n, char* id) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (strcmp(student[i].id, id) == 0) {
			return i;
		}
	}
	return -1;
}
// ham doc file sinh vien
void readFileStudent(Student* student, size_t* n) {
	FILE* fin = fopen("STUD.TXT", "rb");
	if (fin) {
		Student s;
		size_t i = 0;
		while (!feof(fin))
		{
			fread(&s, sizeof(Student), 1, fin);
			if (feof(fin)) {
				break;
			}
			student[i] = s;
			i++;
		}
		*n = i;
		fclose(fin);
	}
	else {
		puts("===========KHONG MO DUOC FILE============");
	}
}
// ham ghi file sinh vien
void writeFileStudent(Student* student, size_t n) {
	FILE* fout = fopen("STUD.TXT", "wb");
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++) {
			fwrite(&student[i], sizeof(Student), 1, fout);
		}
		puts("===========GHI FILE THANH CONG===========");
		fclose(fout);
	}
	else {
		puts("=============KHONG TAO DUOC FILE=============");
	}
}

