/*

Solution written by
Ilovan Cristian Daniel

*/

#ifndef DOMAIN_H
#define DOMAIN_H

#define CHARSIZE 100

#include <stdbool.h>

typedef struct
{
	unsigned int i; // identification
	char type[CHARSIZE];
	char producedBy[CHARSIZE];
	char model[CHARSIZE];
	unsigned int price;
	unsigned int quantity;
	bool memory; // 0 if the memory is free
	
} Product;



// constructors

// constructs Product object
// in:
// 1 address to Product to construct
// 2 unsigned int unique identification
// 3 address to char type
// 4 address to char producedBy
// 5 address to char model
// 6 unsigned int price
// 7 unsigned int quantity
// 8 bool mememory (true if the memory is occupied or false if the
// memory is available)
// out:
// the Product object at address has
// new unsigned int unique identification, type, producedBy,
// model, unsigned int price, unsigned int quantity, memory
void productConstructor(Product*, unsigned int, char*, char*, char*, unsigned int, unsigned int, bool);

// constucts Product object using another Product object
// in:
// 1 address to Product object to construct
// 2 address to Product object to copy
// out:
// product object to construct will have the same
// attributes as product object to copy
void productEqualConstructor(Product*, Product*);

void productDestructor(Product*);

// set functions

// sets Product object i attribute
// in:
// 1 address to Product object to set
// 2 unsigned int i value
// out:
// the Product object from address has
// new i value
void productSetI(Product*, unsigned int);

// sets Product object type attribute
// in:
// 1 address to Product object to set
// 2 address to type to copy
// out:
// the Product object from address has
// new type
void productSetType(Product*, char*);

// sets Product object producedBy attribute
// in:
// 1 address to Product object to set
// 2 address to producedBy to copy
// out:
// the Product object from address has
// new producedBy
void productSetProducedBy(Product*, char*);

// sets Product object model attribute
// in:
// 1 address to Product object to set
// 2 address to model to copy
// out:
// the Product object from address has
// new model
void productSetModel(Product*, char*);

// sets Product object price attribute
// in:
// 1 address to Product object to set
// 2 unsigned int price value
// out:
// the Product object from address has
// new price value
void productSetPrice(Product*, unsigned int);

// sets Product object quantity attribute
// in:
// 1 address to Product object to set
// 2 unsigned int quantity value
// out:
// the Product object from address has
// new quantity value
void productSetQuantity(Product*, unsigned int);

// sets Product object memory attribute
// in:
// 1 address to Product object to set
// 2 bool memory value
// out:
// the Product object from address has
// new memory value
void productSetMemory(Product*, bool);





















// get functions

// get Product object i attribute
// in:
// 1 address to Product object
// out:
// returns i attribute for object from address
unsigned int productGetI(Product*);

// get Product object type attribute
// in:
// 1 address to Product object
// out:
// returns type attribute for object from address
char* productGetType(Product*);

// get Product object producedBy attribute
// in:
// 1 address to Product object
// out:
// returns producedBy attribute for object from address
char* productGetProducedBy(Product*);

// get Product object model attribute
// in:
// 1 address to Product object
// out:
// returns model attribute for object from address
char* productGetModel(Product*);

// get Product object price attribute
// in:
// 1 address to Product object
// out:
// returns price attribute for object from address
unsigned int productGetPrice(Product*);

// get Product object quantity attribute
// in:
// 1 address to Product object
// out:
// returns quantity attribute for object from address
unsigned int productGetQuantity(Product*);

// get Product object memory attribute
// in:
// 1 address to Product object
// out:
// returns memory attribute for object from address
bool productGetMemory(Product*);





















// operator functions

// equal operator for products
// in:
// 1 address to Product object
// 2 address to Product object
// out:
// returns true if the objects from addresses
// have the same attributes or false if not
bool productEqualAttributes(Product*, Product*);





















#endif