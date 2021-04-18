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

void uploadProductData(Product *p, int index){
        FILE *fp;
        fp = fopen("productData.txt", "wt");
        
	for(int i = 0; i < index; i++){
		if(p[i].price < 0) continue;
                fprintf(fp, "%.2f %d %.2f %d %s\n", p[i].weight, p[i].price, p[i].rate, p[i].numRate, p[i].name);
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

        for(int i = 0; i < 100; i++){
                fscanf(fp, "%f ", &p[i].weight);
                if(feof(fp)) break;
                fscanf(fp, "%d", &p[i].price);
                fscanf(fp, "%f", &p[i].rate);
                fscanf(fp, "%d", &p[i].numRate);
                fscanf(fp, "%[^\n]s ", p[i].name);

		p[i].totalRate = p[i].rate;

                count++;
        }

        fclose(fp);
        printf("==> 로딩 성공!\n");

        return count;
}
