//main.c

#include "product.h"

int main(){
	Product p;

	int menu;
	int count = bringProductData(&p);
	//int index = count;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1){
			printProduct(p);
		}else if(menu == 2){
			count += createProduct(&p);
		}else if(menu == 3){
			updateProduct(&p);
		}else if(menu == 4){
			count -= deleteProduct(&p);
		}else if(menu == 5){
			rateProduct(&p);
		}else if(menu == 6){
			uploadProductData(&p/*, count*/);
		}
	}
	return 0;
}
