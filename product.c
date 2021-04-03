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

	printf("==> 제품 추가됨!\n");

	return 1;
}

void printProduct(Product p){
	printf("\n%.2f\t%d\t%d\t%d\t%s\n", p.weight, p.price, p.rate, p.numRate, p.name);
}

int updateProduct(Product *p){
	int c;
	while((c = getchar()) != '\n' && c != EOF);

	printf("제품의 새 이름 : ");
	scanf("%[^\n]s", p->name);

	printf("제품의 새 무개 : ");
	scanf("%f", &p->weight);

	printf("제품의 새 가격 : ");
	scanf("%d", &p->price);

	printf("==> 제품 수정됨!\n");
	
	return 1;
}

int deleteProduct(Product *p){
	p->name[0] = '\0';
	p->weight = -1.0;
	p->price = -1;
	p->rate = 0;
	p->numRate = 0;

	printf("==> 제품 삭제됨!\n");

	return 1;
}

void uploadProductData(Product *p, int index){
	FILE *fp;
	fp = fopen("productData.txt", "wt");
	for(int i = 0; i < index; i++){
		fprintf(fp, "%.2f %d %d %d %s\n", p->weight, p->price, p->rate, p->numRate, p->name);
	}

	fclose(fp);
	printf("==> 제품  저장됨!\n");
}

int bringProductData(Product *p){
	int count = 0;
	FILE *fp;
	fp = fopen("productData.txt", "rt");
	if(fp == NULL){
		printf("==> 파일 없음!\n");
		return 0;
	}

	//while(1){
		fscanf(fp, "%f", &p->weight);
		//if(feof(fp)) break;
		fscanf(fp, "%d", &p->price);
		fscanf(fp, "%d", &p->rate);
		fscanf(fp, "%d", &p->numRate);
		fscanf(fp, "%[^\n]s", p->name);

		count++;
	//}

	fclose(fp);
	printf("==> 로딩 성공!\n");

	return count;
}
