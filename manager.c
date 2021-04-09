//manager.c

#include "manager.h"


void listProduct(Product *p, int index){
	printf("No. weight(g)  price(w)    rate(1~5)    #rates      name\n");
	printf("==============================================================\n");
	for(int i = 0; i < index; i++){
		if(p[i].price < 0) continue;
		printf("%d    ", i+1);
		printProduct(p[i]);
	}
}

int selectProductNo(Product *p, int index){
	int no = 0;
	listProduct(p, index);
	printf("\n번호는 (취소:0) : ");
	scanf("%d", &no);
	return no;
}
