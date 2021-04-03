//main.c

#include "product.h"

int main(){
	Product p;

	int menu;
	int count = 0;

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
		}
	}
	return 0;
}
