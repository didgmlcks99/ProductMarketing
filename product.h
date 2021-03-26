#include <stdio.h>

/*
* This is a type defined structure
* making a Product.
*/
typedef struct{
    char name[20];
    float weight;
    int price;
    int rate;
    int numRate;
} Product;


/*
* This function displays given menu,
* and allow the user to choose certain menu program to execute.
* return : integer indicating a certain menu.
*/
int selectMenu();

/*
* 
* return : integer that indicates the amount of product in database (index).
*/
int loadData(Product *p);

/*
* This function allow users to create a product
* with each product type variables.
* return : integer that increments a local variable indicating
*           the last index of a list of product. 
*/
int createProduct(Product *p);

/*
* This function prints a product.
*/
void readProduct(Product p);

/*
* This function list products stored in the database.
*/
int listProduct(Product *p, int index);

/*s
* This function allow the users to search for a product
* with user chosen type from product, (name, weight, price, etc.);
*/
void searchProduct(Product *p, int index);
