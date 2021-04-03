//product.h
#include <stdio.h>

/*
* This is a header file of a program that allows users to use the platform of market.
*/

/*
* This is a type defined structure
* making a Product.
*/
typedef struct{
    char name[40];    // name of the product in integer
    float weight;     // weight of the product in float
    int price;        // price of product in integer
    float rate;   // rating of product in integer limit to 1~5
    int totalRate;
    int numRate;      // number of rating of product in integer
} Product;

/*
* This is a type defined structure
* making a user account.
*/
typedef struct{
    char id[20];
    char pw[20];
    int wallet;
} User;

/*
* This function reads the user account datas saved in the database 
* bringing it to user usable memory. 
* return : integer that indicates the amount of user in database (index).
* handling : bring data if database exist / none if database doesn't exist
*/
int bringUserData(User *u);

/*
* This function allow users to create a account for this program.
* return : integer that increments a local variable indicating
*           the last index of a list of users.
*           1 : successful creation / 0 : failed creation
* handling : create if memory not full / none if memory is full
*/
int createUser(User *u);

/*
* This function uploads the data to database allowing reusable data.
* handling : upload if data exist / none if no data
*/
void uploadUserData(User *u, int index);

/*
* This function allow users to delete a current user account.
* return : integer that decrements a local variable indicating
*           the last index of a list of users.
*           1 : successful deletion / 0 : failed deletion
* handling : delete if data exist / none if no data
*/
int deleteUser(User *u);

/*
* This function allow users to update (edit) a user account data.
* return : integer indicating whether the update was successfull or not.
*          1 : successful update / 0 : failed update
* handling : update if data exist / none if no data
*/
int updateUser(User *u);

/*
* This function logs in a user account to program through id and password
* created and saved in database.
* handling : decline login if not existing id | password is wrong
*/
void login(User *u);

/*
* This function logs out user from the program.
*/
void logout(User *u);

/*
* This function allows user to deposit money to wallet.
*/
void deposit(User *u);

/*
* This function displays given menu,
* and allow the user to choose certain menu program to execute.
* return : integer indicating a certain menu.
* handling : run program if existing menu / none if non-existing menu
*/
int selectMenu();

/*
* This function reads the product datas saved in the database 
* bringing it to user usable memory. 
* return : integer that indicates the amount of product in database (index).
* handling : bring data if database exist / none if database doesn't exist
*/
int bringProductData(Product *p);

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
* This function allow user to buy a product 
* by choosing from listed product (not available product).
* User 'MUST' have appropiate amount of money to buy product.
* handling : buy if data exist / none if no data
*/
void buyProduct(Product *p, User *u);

/*
* This function allow user to rate a product
* chosen from listed product (number of rate incremented).
* handling : limit rating to integer between 1 and 5 / stop if not
*/
int rateProduct(Product *p);

/*
* This function uploads the data to database allowing reusable data.
* handling : upload if data exist / none if no data
*/
void uploadProductData(Product *p/*, int index*/);

/*
* This function gets user input for certain data to be
* implemented according to input index number.
* return : integer indicating the index number of data chosen by user.
*/
int selectProductNo(Product *p, int index);

/*
* This function prints a product.
* handling : printf if data exist / none if no data
*/
void printProduct(Product p);

/*
* This function list products stored in the database.
* handling : list if data exist / none if no data
*/
void listProduct(Product *p, int index);

/*
* This function allow the users to search for a product
* by name, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyName(Product *p, int index);

/*
* This function allow the users to search for a product
* by weight, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyWeight(Product *p, int index);

/*
* This function allow the users to search for a product
* by price, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyPrice(Product *p, int index);

/*
* This function allow the users to search for a product
* by rate, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyRate(Product *p, int index);

/*
* This function allow the users to search for a product
* by number of rates, which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchbyNumRate(Product *p, int index);
