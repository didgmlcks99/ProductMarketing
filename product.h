//product.h

#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <stdio.h>

/*
* This is a header file of a program that allows users to use the platform of market.
*/

/*
* This is a type defined structure
* making a Product.
*/
typedef struct{
    char name[40];	// name of the product in integer
    float weight;	// weight of the product in float
    int price;		// price of product in integer
    float rate;		// rating of product in integer limit to 1~5
    int totalRate ;	//for calculation average to number of ratings
    int numRate;	// number of rating of product in integer
} Product;

/*
* This function displays given menu,
* and allow the user to choose certain menu program to execute.
* return : integer indicating a certain menu.
* handling : run program if existing menu / none if non-existing menu
*/
int selectMenu();

/*
* This function allow users to create a product
* return : integer that increments a local variable indicating
*           the last index of a list of product.
*           1 : successful creation / 0 : failed creation
* handling : create if memory not full / none if memory is full
*/
int createProduct(Product *p);

/*
* This function allow users to delete a product.
* return : integer that decrements a local variable indicating
*           the last index of a list of product.
*           1 : successful deletion / 0 : failed deletion
* handling : delete if data exist / none if no data
*/
int deleteProduct(Product *p);

/*
* This function allow users to update (edit) a product data.
* return : integer indicating whether the update was successfull or not.
*          1 : successful update / 0 : failed update
* handling : update if data exist / none if no data
*/
int updateProduct(Product *p);

/*
* This function allow user to rate a product
* chosen from listed product (number of rate incremented).
* handling : limit rating to integer between 1 and 5 / stop if not
*/
int rateProduct(Product *p);

/*
* This function prints a product.
* handling : printf if data exist / none if no data
*/
void printProduct(Product p);

#endif
