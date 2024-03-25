/*

Solution written by
Ilovan Cristian Daniel

*/
#include "domain.h"
#include <string.h>


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
void productConstructor(Product* p, unsigned int i, char* type, char* producedBy, char* model, unsigned int price, unsigned int quantity, bool memory)
{
	productSetI(p, i);
	productSetType(p, type);
	productSetProducedBy(p, producedBy);
	productSetModel(p, model);
	productSetPrice(p, price);
	productSetQuantity(p, quantity);
	productSetMemory(p, memory);
}

// constucts Product object using another Product object
// in:
// 1 address to Product object to construct
// 2 address to Product object to copy
// out:
// product object to construct will have the same
// attributes as product object to copy
void productEqualConstructor(Product* p, Product* t)
{
	productSetI(p, t->i);
	productSetType(p, t->type);
	productSetProducedBy(p, t->producedBy);
	productSetModel(p, t->model);
	productSetPrice(p, t->price);
	productSetQuantity(p, t->quantity);
	productSetMemory(p, t->memory);
}





// set functions

// sets Product object i attribute
// in:
// 1 address to Product object to set
// 2 unsigned int i value
// out:
// the Product object from address has
// new i value
void productSetI(Product* p, unsigned int i)
{
	p->i = i;
}

// sets Product object type attribute
// in:
// 1 address to Product object to set
// 2 address to type to copy
// out:
// the Product object from address has
// new type
void productSetType(Product* p, char* type)
{
	strcpy(p->type, type);
}

// sets Product object producedBy attribute
// in:
// 1 address to Product object to set
// 2 address to producedBy to copy
// out:
// the Product object from address has
// new producedBy
void productSetProducedBy(Product* p, char* producedBy)
{
	strcpy(p->producedBy, producedBy);
}

// sets Product object model attribute
// in:
// 1 address to Product object to set
// 2 address to model to copy
// out:
// the Product object from address has
// new model
void productSetModel(Product* p, char* model)
{
	strcpy(p->model, model);
}

// sets Product object price attribute
// in:
// 1 address to Product object to set
// 2 unsigned int price value
// out:
// the Product object from address has
// new price value
void productSetPrice(Product* p, unsigned int price)
{
	p->price = price;
}

// sets Product object quantity attribute
// in:
// 1 address to Product object to set
// 2 unsigned int quantity value
// out:
// the Product object from address has
// new quantity value
void productSetQuantity(Product* p, unsigned int quantity)
{
	p->quantity = quantity;
}

// sets Product object memory attribute
// in:
// 1 address to Product object to set
// 2 bool memory value
// out:
// the Product object from address has
// new memory value
void productSetMemory(Product* p, bool memory)
{
	p->memory = memory;
}





// get functions

// get Product object i attribute
// in:
// 1 address to Product object
// out:
// returns i attribute for object from address
unsigned int productGetI(Product* p)
{
	return p->i;
}

// get Product object type attribute
// in:
// 1 address to Product object
// out:
// returns type attribute for object from address
char* productGetType(Product* p)
{
	return p->type;
}

// get Product object producedBy attribute
// in:
// 1 address to Product object
// out:
// returns producedBy attribute for object from address
char* productGetProducedBy(Product* p)
{
	return p->producedBy;
}

// get Product object model attribute
// in:
// 1 address to Product object
// out:
// returns model attribute for object from address
char* productGetModel(Product* p)
{
	return p->model;
}

// get Product object price attribute
// in:
// 1 address to Product object
// out:
// returns price attribute for object from address
unsigned int productGetPrice(Product* p)
{
	return p->price;
}

// get Product object quantity attribute
// in:
// 1 address to Product object
// out:
// returns quantity attribute for object from address
unsigned int productGetQuantity(Product* p)
{
	return p->quantity;
}

// get Product object memory attribute
// in:
// 1 address to Product object
// out:
// returns memory attribute for object from address
bool productGetMemory(Product* p)
{
	return p->memory;
}





// operator functions

// equal operator for products
// in:
// 1 address to Product object
// 2 address to Product object
// out:
// returns true if the objects from addresses
// have the same attributes or false if not
bool productEqualAttributes(Product *first, Product *second)
{
	if (strcmp(first->type, second->type))
		return 0;
	
	if (strcmp(first->producedBy, second->producedBy))
		return 0;
	
	if (strcmp(first->model, second->model))
		return 0;
	
	if (first->price != second->price)
		return 0;
	
	return 1;
}