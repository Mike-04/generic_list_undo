/*

Solution written by
Ilovan Cristian Daniel

*/

#ifndef REPOSITORY_H
#define REPOSITORY_H

#define SIZE 100

#include "domain.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct
{
	Product *products;
	unsigned int size;
	
} Products;

// constructs products object
// in:
// p is a product object
// out:
// p is a constructed product object
void productsConstructor(Products*);

void productsDestructor(Products*);

// see if there exists an product with
// useful attributes
// in:
// p = repository where to search
// t = product to search
// out:
// returns position if found or false if not
int repositoryExistsAttributes(Products*, Product*);


// see if there is a product with
// search identification
// in:
// p = repository where to search
// identification = identification to search
// out:
// returns position if found or false if not
bool repositoryExists(Products*, unsigned int);


// adds a product to repository
// in:
// p = repository to where to add
// t = product to add
// out:
// the product t was added to repository p
unsigned int repositoryAdauga(Products*, Product*);

// removes the product with identification from repository
// in:
// p = repository where to remove from
// identification = product identification
// out:
// repository = repository - product
bool repositorySterge(Products*, unsigned int);

// sets the attributes for product with
// identification from repository
// in:
// p = repository
// i = product identification to set attributes
// t = product with new attributes to copy to product with
// i identification
// out:
// the product with i identification has new attributes
void repositorySetProduct(Products*, unsigned int, Product*);

// returns pointer to product with identification
// in:
// p = repository where to search
// i = identification
// out:
// true
Product* repositoryGetProduct(Products*, unsigned int);

#endif