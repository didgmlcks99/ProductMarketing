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
