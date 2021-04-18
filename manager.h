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
