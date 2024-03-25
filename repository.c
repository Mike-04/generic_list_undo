/*

Solution written by
Ilovan Cristian Daniel

*/

#include "repository.h"

// constructs products object
// in:
// p is a product object
// out:
// p is a constructed product object
void productsConstructor(Products *p)
{
	p->products = NULL;
	p->size = 0;
}

// destructs
void productsDestructor(Products *p)
{
	if (p->products != NULL)
		free(p->products);
}

// see if there exists an product with
// useful attributes
// in:
// p = repository where to search
// t = product to search
// out:
// returns position if found or false if not
int repositoryExistsAttributes(Products *p, Product* t)
{
	unsigned int size = p->size;
	
	for (unsigned int i = 0; i < size; ++i)
		if (productEqualAttributes(&p->products[i], t))
			return i;
		
	return -1;
}

// see if there is a product with
// search identification
// in:
// p = repository where to search
// identification = identification to search
// out:
// returns position if found or false if not
bool repositoryExists(Products *p, unsigned int identification)
{
	if (identification >= p->size)
		return 0;
	return p->products[identification].memory;
}

// adds a product to repository
// in:
// p = repository to where to add
// t = product to add
// out:
// the product t was added to repository p
unsigned int repositoryAdauga(Products* p, Product* t)
{
	unsigned int n = p->size;
	++(p->size);
	Product *pointer = (Product*)malloc((n + 1) * sizeof(Product));
	for (unsigned int i = 0; i < n; ++i)
		pointer[i] = p->products[i];
	free(p->products);
	p->products = pointer;
	productEqualConstructor(&p->products[n], t);
	return n;
}

// removes the product with identification from repository
// in:
// p = repository where to remove from
// identification = product identification
// out:
// repository = repository - product
bool repositorySterge(Products* p, unsigned int identification)
{
	Product *t = &(p->products[identification]);
	bool r = productGetMemory(t);
	productSetMemory(t, 0);
	return r;
}

// sets the attributes for product with
// identification from repository
// in:
// p = repository
// i = product identification to set attributes
// t = product with new attributes to copy to product with
// i identification
// out:
// the product with i identification has new attributes
void repositorySetProduct(Products* p, unsigned int i, Product* t)
{
	Product *j = &(p->products[i]);
	
	productEqualConstructor(j, t);
}

// returns pointer to product with identification
// in:
// p = repository where to search
// i = identification
// out:
// true
Product* repositoryGetProduct(Products* p, unsigned int i)
{
	return &p->products[i];
}