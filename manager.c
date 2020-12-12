#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SPACE 30

typedef struct main{
	char place[SPACE];
	char name[SPACE];
	int cost;
}Main;
int menu_food();
void print_menu(FILE* fp);
void menu_pizza(FILE* fp);
void menu_chicken(FILE* fp);
void menu_hamburger(FILE *fp);
int main()
{
	int n;	
	Main* order;
	FILE *fp = NULL;
	fp = fopen("order.txt", "a+");
	if (fp == NULL){
		fprintf(stderr, "Can not open file\n");
		return 1;
	}
	while(1)
	{
		printf("무슨 음식을 드시겠습니까?\n");
		n = menu_food();
		switch(n)
		{
			case 1:
				menu_chicken(fp);	
				break;
			case 2:
				menu_pizza(fp);
				break;
			case 3:
				menu_hamburger(fp);
				break;
			case 4:
				goto end;
		}
	}
end:
	fclose(fp); 
	return 0;
}
int menu_food()
{
	int n;
	printf("=======================\n");
	printf("1. 치킨\n2. 피자\n3. 햄버거\n4. 종료하기\n");
	printf("=======================\n");
	scanf("%d", &n);
	return n;
}
void menu_pizza(FILE* fp)
{
	char name[SPACE];
	Main data;
	Main new_data;
	FILE *fpp = NULL;
	fpp = fopen("pizza.txt", "r");
	if (fpp == NULL)
		fprintf(stderr, "Can not open file\n");
	print_menu(fpp);
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fpp)){
		fread(&data, sizeof(data), 1, fpp);
		if(strcmp(data.name, name) == 0)
		{
			new_data.place[SPACE] = *data.place;
			new_data.name[SPACE] = *data.name;
			new_data.cost = data.cost;
			fseek(fp, 0, SEEK_SET);
			fwrite(&new_data, sizeof(new_data), 1, fp);
			break;
		}
	}
	fclose(fpp);
}
void menu_chicken(FILE* fp)
{
	char name[SPACE];
	Main data;
	Main new_data;
	FILE *fpc = NULL;
	fpc = fopen("chicken.txt", "r");
	if (fpc == NULL)
		fprintf(stderr, "Can not open file\n");
	print_menu(fpc);	
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fpc)){
		fread(&data, sizeof(data), 1, fpc);
		if(strcmp(data.name, name) == 0)
		{
			new_data.place[SPACE] = *data.place;
			new_data.name[SPACE] = *data.name;
			new_data.cost = data.cost;
			fseek(fp, 0, SEEK_SET);
			fwrite(&new_data, sizeof(new_data), 1, fp);
			break;
		}
	}
	fclose(fpc);
}
void menu_hamburger(FILE* fp)
{
	char name[SPACE];
	Main data;
	Main new_data;
	FILE *fph = NULL;
	fph = fopen("hamburger.txt", "r");
	if (fph == NULL)
		fprintf(stderr, "Can not open file\n");
	while(!feof(fph)){
		fscanf(fph, "%s %s %d\n", data.place, data.name, &data.cost);
		printf("%s > %s 가격 : %d\n", data.place, data.name, data.cost);
	}
	fclose(fph);
	fph = fopen("hamburger.txt", "r");
	if (fph == NULL)
		fprintf(stderr, "Can not open file\n");
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fph)){
		fscanf(fph, "%s %s %d\n", data.place, data.name, &data.cost);	
		if(strcmp(data.name, name) == 0)
		{
			new_data.place[SPACE] = *data.place;
			//new_data.place = data.place;
			new_data.name[SPACE] = *data.name;
			new_data.cost = data.cost;
			fseek(fp, 0, SEEK_SET);
			printf("%s %s %d\n", new_data.place, new_data.name, new_data.cost);
			fwrite(&new_data, sizeof(new_data), 1, fp);
			break;
		}
	}
	fclose(fph);
}
void print_menu(FILE *fp)
{
	Main data;
	while(!feof(fp)){
		fscanf(fp, "%s %s %d\n", data.place, data.name, &data.cost);
		printf("%s > %s 가격 : %d\n", data.place, data.name, data.cost);
	}
}
