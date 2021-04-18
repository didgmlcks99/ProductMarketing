//main.c

#include "product.h"
#include "manager.h"

int main(){
#ifdef DEBUG
	printf("==> RUNNING IN DEBUG MODE!\n");
#endif
	Product p[100];
	int count = bringProductData(p);
	int index = count;

	int menu;
	while(1){
		menu = selectMenu();

#ifdef DEBUG
		printf("\n\n=============== DEBUG CHECK ===============\n");
		printf("count : %d\n", count);
		printf("index : %d\n", index);
		printf("menu : %d\n", menu);
		printf("=============== DEBUG CHECK ===============\n\n");
#endif
		if(menu == 0) break;
		if(menu == 1){
			if(count > 0){
				listProduct(p, index);
			}else{ 
				printf("=> 조회 할 데이터 없습니다.\n");
			}
		}else if(menu == 2){
			if(count < 10){
				count += createProduct(&p[index++]);
			}else{
				printf("=> 10개 제품으로 제한 되어서 추가 불가합니다.\n");
			}
		}else if(menu == 3){
			if(count > 0){
				int no = selectProductNo(p, index);
				if(no > index){
					printf("=> 선택된 번호의 제품 존재 하지 않습니다.\n");
				}else if(no > 0){
					updateProduct(&p[no-1]);
				}else{
					printf("=> 취소 되었습니다\n");
				}
			}else{
				printf("=> 수정 할 데이터 없습니다.\n");
			}
		}else if(menu == 4){
			if(count > 0){
				int no = selectProductNo(p, index);
				if(no > index){
					printf("=> 선택된 번호의 제품 존재 하지 않습니다\n");
				}else if(no > 0){
					int delok;
					printf("정말로 삭제하시겠습니까?(1:삭제) ");
					scanf("%d", &delok);
					if(delok == 1){
						deleteProduct(&p[no-1]);
						count--;
					}else{
						printf("=> 삭제 취소 되었습니다.\n");
					}
				}else{
					printf("=> 취소 되었습니다\n");
				}
			}else{
				printf("삭제할 데이터가 없습니다.\n");
			}
		}else if(menu == 5){
			if(count > 0){
				int no = selectProductNo(p, index);
				if(no > index){
					printf("=> 선택된 번호의 제품 존재 하지 않습니다.\n");
				}else if(no > 0){
					rateProduct(&p[no-1]);
				}else{
					printf("=> 취소 되었습니다\n");
				}
			}else{
				printf("=> 평가 할 데이터 없습니다.\n");
			}
		}else if(menu == 6){
			if(count > 0){
				uploadProductData(p, index);
			}else{
				printf("=> 저장 할 데이터 없습니다.\n");
			}
		}else if(menu == 7){
			if(count > 0){
				searchbyName(p, index);
			}else{
				printf("=> 제품 이름으로 검색할 데이터 없습니다.\n");
			}
		}else if(menu == 8){
			if(count > 0){
				searchbyLowerPrice(p, index);
			}else{
				printf("=> 제품 가격으로 검색할 데이터 없습니다.\n");
			}
		}
	}
	return 0;
}
