#include<stdio.h>
#include"subject.h";
#include<string.h>

// ham nhap mon hoc
void addSubject(Subject* subject) {
	puts("=========THONG TIN MON HOC===========");
	printf("Nhap ten mon hoc: ");
	scanf("%*c%29[^\n]", subject->name);
	printf("So tin chi: ");
	scanf("%d", &subject->credits);
}
// ham hien thi danh sach mon hoc
void showListSubject(Subject* subject, size_t n) {
	if (n > 0) {
		puts("============DANH SACH MON HOC=============");
		printf("%-15s%-30s%-10s\n",
			"Ma HP", "Ten HP", "Tin chi");
		for (size_t i = 0; i < n; i++) {
			puts("----------------------------------------------------");
			printf("%-15s%-30s%-10d\n", subject[i].id,
				subject[i].name, subject[i].credits);
		}
	}
	else {
		puts("============KHONG CO MON HOC NAO TRONG DANH SACH===========");
	}
}
// ham tim kiem mon hoc
int findSubject(Subject* subject, size_t n, char* id) {
	size_t i;
	for (i = 0; i < n; i++) {
		if (strcmp(subject[i].id, id ) == 0) {
			return i;
		}
	}
	return -1;
}
// ham doc file mon hoc
void readFileSubject(Subject* subject, size_t* n) {
	FILE* fin = fopen("SUBJ.TXT", "rb");
	if (fin) {
		Subject s;
		size_t i = 0;
		while (!feof(fin))
		{
			fread(&s, sizeof(Subject), 1, fin);
			if (feof(fin)) {
				break;
			}
			subject[i] = s;
			i++;
		}
		(*n) = i;
		fclose(fin);
	}
	else {
		puts("=============KHONG MO DUOC FILE==============");
	}
}
// ham ghi file mon hoc
void writeFileSubject(Subject* subject, size_t n) {
	FILE* fout = fopen("SUBJ.TXT", "wb");
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++) {
			fwrite(&subject[i], sizeof(Subject), 1, fout);
		}
		fclose(fout);
		puts("============GHI FILE THANH CONG=============");
	}
	else {
		puts("=============LOI.KHONG TAO DUOC FILE==============");
	}
}
