#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SPACE 30

typedef struct main{
	char place[SPACE];
	char name[SPACE];
	char cost[SPACE];
}Main;
int menu();
int menu_food();
Main get_order();
void print_menu_c();
void print_menu_p();
void print_menu_h();
void check_order(FILE* fp);
void change_order(FILE* fp);
void menu_pizza(FILE* fp);
void menu_chicken(FILE* fp);
void menu_hamburger(FILE *fp);
int main()
{
	int n, m;	
	FILE *fp = NULL;
	fp = fopen("order.txt", "r+");
	if (fp == NULL){
		fprintf(stderr, "Can not open file\n");
		return 1;
	}
start:
	while(1)
	{
		printf("메뉴를 선택해주세요\n");
		m = menu();
		switch(m)
		{
			case 1:
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
						goto start;
				}
				break;
			case 2:
				check_order(fp);
				break;
			case 3:
				change_order(fp);
				break;
			case 4:
				goto end;
		}
	}
end:
	fclose(fp); 
	return 0;
}
Main get_order()
{
	Main data;
	char name[SPACE];
	int n;
	printf("무슨 음식을 드시겠습니까?\n");
	printf("=======================\n");
	printf("1. 치킨\n2. 피자\n3. 햄버거\n");
	printf("=======================\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			print_menu_c();
			FILE *fpc = NULL;
			fpc = fopen("chicken.txt", "r");
			if (fpc == NULL)
				fprintf(stderr, "Can not open file\n");
			printf("주문하실 음식을 입력해주세요 : ");
			scanf("%s", name);
			fflush(stdin);
			fseek(fpc, 0, SEEK_SET);
			while(!feof(fpc)){
				fscanf(fpc, "%s %s %s\n", data.place, data.name, data.cost);
				if(strcmp(data.name, name) == 0){
					break;
				}
			}
			fflush(stdin);
			break;
		case 2:
			print_menu_p();
			FILE *fpp = NULL;
			fpp = fopen("pizza.txt", "r");
			if (fpp == NULL)
				fprintf(stderr, "Can not open file\n");
			printf("주문하실 음식을 입력해주세요 : ");
			scanf("%s", name);
			fflush(stdin);
			fseek(fpp, 0, SEEK_SET);
			while(!feof(fpp)){
				fscanf(fpp, "%s %s %s\n", data.place, data.name, data.cost);
				if(strcmp(data.name, name) == 0){
					break;
				}
			}
			fflush(stdin);	
			break;
		case 3:
			print_menu_h();
			FILE *fph = NULL;
			fph = fopen("hamburger.txt", "r");
			if (fph == NULL)
				fprintf(stderr, "Can not open file\n");
			printf("주문하실 음식을 입력해주세요 : ");
			scanf("%s", name);
			fflush(stdin);
			fseek(fph, 0, SEEK_SET);
			while(!feof(fph)){
				fscanf(fph, "%s %s %s\n", data.place, data.name, data.cost);
				if(strcmp(data.name, name) == 0){
					break;
				}
			}
			fflush(stdin);
			break;
	}
	return data;
}
int menu()
{
	int m;
	printf("=======================\n");
	printf("1. 주문하기\n2. 주문확인하기\n3. 주문취소하기\n4. 종료하기\n");
	printf("=======================\n");
	scanf("%d", &m);
	fflush(stdin);
	return m;
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
void print_menu_p()
{
	Main data;
	FILE* fpp = NULL;
	fpp = fopen("pizza.txt", "r");
	if (fpp == NULL)
		fprintf(stderr, "Can not open file\n");
	while(!feof(fpp)){
		fscanf(fpp, "%s %s %s\n", data.place, data.name, data.cost);
		printf("%s > %s 가격 : %s\n", data.place, data.name, data.cost);
	}
	fclose(fpp);
}
void print_menu_c()
{
	Main data;
	FILE* fpc = NULL;	
	fpc = fopen("chicken.txt", "r");
	if (fpc == NULL)
		fprintf(stderr, "Can not open file\n");
	while(!feof(fpc)){
		fscanf(fpc, "%s %s %s\n", data.place, data.name, data.cost);
		printf("%s > %s 가격 : %s\n", data.place, data.name, data.cost);
	}
	fclose(fpc);
}
void print_menu_h()
{
	Main data;
	FILE* fph = NULL;
	fph = fopen("hamburger.txt", "r");
	if (fph == NULL)
		fprintf(stderr, "Can not open file\n");
	while(!feof(fph)){
		fscanf(fph, "%s %s %s\n", data.place, data.name, data.cost);
		printf("%s > %s 가격 : %s\n", data.place, data.name, data.cost);
	}
	fclose(fph);
}
void menu_pizza(FILE* fp)
{
	char name[SPACE];
	Main data;
	Main new_data;
	print_menu_p();
	FILE *fpp = NULL;
	fpp = fopen("pizza.txt", "r");
	if (fpp == NULL)
		fprintf(stderr, "Can not open file\n");
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fpp)){
		fscanf(fpp, "%s %s %s\n", data.place, data.name, data.cost);	
		if(strcmp(data.name, name) == 0)
		{
			strcpy(new_data.name, data.name);
			strcpy(new_data.place, data.place);
			strcpy(new_data.cost,data.cost);
			fseek(fp, 0, SEEK_END);
			printf("%s의 %s주문이 완료되었습니다. 금액은 %s원입니다.\n", new_data.place, new_data.name, new_data.cost);
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
	print_menu_c();
	fpc = fopen("chicken.txt", "r");
	if (fpc == NULL)
		fprintf(stderr, "Can not open file\n");
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fpc)){
		fscanf(fpc, "%s %s %s\n", data.place, data.name, data.cost);	
		if(strcmp(data.name, name) == 0)
		{
			strcpy(new_data.name, data.name);
			strcpy(new_data.place, data.place);
			strcpy(new_data.cost,data.cost);	
			fseek(fp, 0, SEEK_END);
			printf("%s의 %s주문이 완료되었습니다. 금액은 %s원입니다.\n", new_data.place, new_data.name, new_data.cost);
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
	print_menu_h();
	fph = fopen("hamburger.txt", "r");
	if (fph == NULL)
		fprintf(stderr, "Can not open file\n");
	printf("주문하실 음식을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fph)){
		fscanf(fph, "%s %s %s\n", data.place, data.name, data.cost);	
		if(strcmp(data.name, name) == 0)
		{
			strcpy(new_data.name, data.name);
			strcpy(new_data.place, data.place);
			strcpy(new_data.cost,data.cost);
			fseek(fp, 0, SEEK_END);
			printf("%s의 %s주문이 완료되었습니다. 금액은 %s원입니다.\n", new_data.place, new_data.name, new_data.cost);
			fwrite(&new_data, sizeof(new_data), 1, fp);
			break;
		}
	}
	fclose(fph);
}
void check_order(FILE* fp)
{
	Main order;
	fseek(fp, 0, SEEK_SET);
	while(!feof(fp)){
		fread(&order, sizeof(order), 1, fp);
		printf("%s > %s 가격 : %s\n", order.place, order.name, order.cost);			
	}	
}
void change_order(FILE* fp)
{
	Main order;
	Main new_order;
	char name[SPACE];
	
	fseek(fp, 0, SEEK_SET);
	printf("수정하고자 하는 주문의 음식명을 입력해주세요 : ");
	scanf("%s", name);
	fflush(stdin);
	while(!feof(fp)){
		fread(&order, sizeof(order), 1, fp);
		if(strcmp(order.name, name) == 0){
			fseek(fp, -90, SEEK_CUR);
			new_order = get_order();
			fwrite(&new_order, sizeof(new_order), 1, fp);
			break;
		}
	}
}
