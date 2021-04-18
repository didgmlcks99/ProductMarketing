//manager.h

#include "product.h" 

/*
* This function list products stored in the database.
* handling : list if data exist / none if no data
*/
void listProduct(Product *p, int index);

/*
* This function gets user input for certain data to be
* implemented according to input index number.
* return : integer indicating the index number of data chosen by user.
*/
int selectProductNo(Product *p, int index);

/*
* This function reads the product datas saved in the database
* bringing it to user usable memory.
* return : integer that indicates the amount of product in database (index).
* handling : bring data if database exist / none if database doesn't exist
*/
int bringProductData(Product *p);

/*
* This function uploads the data to database allowing reusable data.
* handling : upload if data exist / none if no data
*/
void uploadProductData(Product *p, int index);

/*
* This function allow the users to search for a product
* by name, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyName(Product *p, int index);

/* This function allow the users to search for a product
 * cheaper than chosen price. When a product is cheaper than
 * the chosen price, it will be printed.
 * handling : print if cheaper product exist / none if none exist
*/
void searchbyLowerPrice(Product *p, int index);

/* This function allow the users to search for a product
 * with a rate higher than the chosen rate. When a product has a 
 * rate that is higher than the user chosen rate, it will be printed
 * handling : printf if product with higher rate exist / none if none exist
*/
void searchbyHigherRate(Product *p, int index);
