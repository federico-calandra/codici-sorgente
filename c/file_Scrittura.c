#include<stdio.h>

void main(){

	FILE *filewr;
	char str[10];
	printf("Parola da salvare:");
	scanf("%s",str);

	filewr=fopen("file_Scrittura.dat","wb");
	fwrite(&str, sizeof(str), 1,filewr);
	fclose(filewr);

	/* filerd=fopen("file_Scrittura.dat","rb");
	fread(*/
}
