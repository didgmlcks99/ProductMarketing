/*
* This is header file of a program that allows users to use the platform of market.
*/

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
* handling : run program if existing menu / none if non-existing menu
*/
int selectMenu();

/*
* This function reads the datas saved in the database 
* bringing it to user usable memory. 
* return : integer that indicates the amount of product in database (index).
* handling : bring data if database exist / none if database doesn't exist
*/
int bringData(Product *p);

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
* This function allow users to update (edit) a product.
* return : integer indicating whether the update was successfull or not.
*          1 : successful update / 0 : failed update
* handling : update if data exist / none if no data
*/
int updateProduct(Product *p);

/*
* This function uploads the data to database allowing reusable data.
* handling : upload if data exist / none if no data
*/
void uploadData(Product *p, int index);

/*
* This function gets user input for certain data to be
* implemented according to input index number.
* return : integer indicating the index number of data chosen by user.
*/
int selectDataNo(Product *p, int index);

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
* with user chosen type from product, (name, weight, price, etc.),
* which then are printed when matching.
* handling : print if found / none if search not found
*/
void searchProduct(Product *p, int index);
