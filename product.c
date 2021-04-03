//product.c

#include "product.h"

int selectMenu(){
	int menu;

	printf("\n***** Product Market *****\n");
	printf("1. 메뉴조회\n");
	printf("2. 메뉴추가\n");
	printf("3. 메뉴수정\n");
	printf("4. 메뉴삭제\n");
	printf("5. 메뉴저장\n");
	printf("6. 메뉴검색\n");
	printf("0. 종료\n\n");
	printf("==> 원하는 메뉴는? ");

	scanf("%d", &menu);

	return menu;
}

int createProduct(Product *p){
	int c;
	while((c = getchar()) != '\n' && c != EOF);

	printf("제품의 이름 : ");
	scanf("%[^\n]%*c", p->name);

	printf("제품의 무개 : ");
	scanf("%f", &p->weight);

	printf("제품의 가격 : ");
	scanf("%d", &p->price);

	p->rate = 0;
	p->numRate = 0;

	return 1;
}

void printProduct(Product p){
	printf("\n%s\t%.2f\t%d\t%d\t%d\n", p.name, p.weight, p.price, p.rate, p.numRate);
}

int updateProduct(Product *p){
	int c;
	while((c = getchar()) != '\n' && c != EOF);

	printf("제품의 새 이름 : ");
	scanf("%[^\n]%*c", p->name);

	printf("제품의 새 무개 : ");
	scanf("%f", &p->weight);

	printf("제품의 새 가격 : ");
	scanf("%d", &p->price);

	return 1;
}

int deleteProduct(Product *p){
	p->name[0] = '\0';
	p->weight = -1.0;
	p->price = -1;
	p->rate = 0;
	p->numRate = 0;
	
	return 1;
}
