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
	printf("7. 제품 이름으로 검색\n");
	printf("8. 해당 가격보다 저렴한 제품 검색\n");
	printf("9. 해당 평가보다 높거나 같은 제품 검색\n");
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

	printf("제품의 무개(g) : ");
	scanf("%f", &p->weight);

	printf("제품의 가격(w) : ");
	scanf("%d", &p->price);

	p->rate = 0.0;
	p->totalRate = 0.0;
	p->numRate = 0;

	printf("==> 제품 추가됨!\n");

	return 1;
}

void printProduct(Product p){
	printf("%6.1f %9d %10.1f %11d %15s\n", p.weight, p.price, p.rate, p.numRate, p.name);
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
	p->totalRate = -1.0;
	p->numRate = -1;

	printf("==> 제품 삭제됨!\n");

	return 1;
}

int rateProduct(Product *p){
	float rate;
	
	while(1){
		printf("별 1~5 고르시오 : ");
		scanf("%f", &rate);

		if(rate > 0.0 && rate <= 5.0) break;

		printf("평가 숫자 1~5 사이로 고르시오!\n");
	}

	p->totalRate += rate;
	p->numRate++;
	p->rate = (p->totalRate) / p->numRate;

	printf("==> 제품 평가 완료!\n");

	return 1;
}
