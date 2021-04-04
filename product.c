//product.c

#include "product.h"

int selectMenu(){
	int menu;

	printf("\n***** Product Market *****\n");
	printf("1. 제품 조회\n");
	printf("2. 제품 추가\n");
	printf("3. 제품 수정\n");
	printf("4. 제품 삭제\n");
	printf("5. 제품 평가\n");
	printf("6. 제품 저장\n");
	printf("0. 종료\n\n");
	printf("==> 원하는 메뉴는? ");

	scanf("%d", &menu);

	return menu;
}

int createProduct(Product *p){
	int c;
	while((c = getchar()) != '\n' && c != EOF);

	printf("제품의 이름 : ");
	scanf("%[^\n]s", p->name);

	printf("제품의 무개 : ");
	scanf("%f", &p->weight);

	printf("제품의 가격 : ");
	scanf("%d", &p->price);

	p->rate = 0.0;
	p->totalRate = 0;
	p->numRate = 0;

	printf("==> 제품 추가됨!\n");

	return 1;
}

void printProduct(Product p){
	printf("\n%.2f\t%d\t%.2f\t%d\t%s\n", p.weight, p.price, p.rate, p.numRate, p.name);
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
	p->rate = -0.0;
	p->totalRate = -1;
	p->numRate = -1;

	printf("==> 제품 삭제됨!\n");

	return 1;
}

int rateProduct(Product *p){
	int rate;
	
	while(1){
		printf("별 1~5 고르시오 : ");
		scanf("%d", &rate);

		if(rate > 0.0 && rate <= 5.0) break;
		
		printf("평가 숫자 1~5 사이로 고르시오!\n");
	}

	p->totalRate += rate;
	p->numRate++;
	p->rate = (float)(p->totalRate) / p->numRate;

	printf("==> 제품 평강 완료!\n");

	return 1;
}

void uploadProductData(Product *p/*, int index*/){
	FILE *fp;
	fp = fopen("productData.txt", "wt");
	// for(int i = 0; i < index; i++){
		fprintf(fp, "%.2f %d %.2f %d %s\n", p->weight, p->price, p->rate, p->numRate, p->name);
	// }

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
		fscanf(fp, "%f ", &p->weight);
		//if(feof(fp)) break;
		fscanf(fp, "%d", &p->price);
		fscanf(fp, "%f", &p->rate);
		fscanf(fp, "%d", &p->numRate);
		fscanf(fp, "%[^\n]s ", p->name);

		count++;
	//}

	fclose(fp);
	printf("==> 로딩 성공!\n");

	return count;
}
