/*

Solution written by
Ilovan Cristian Daniel

*/

#include "repository.h"
#include <stdio.h>
// constructs products object
// in:
// p is a product object
// out:
// p is a constructed product object
void productsConstructor(Products *p)
{
	p->products = createDynamicArray();
    p->size = p->products->size;
}

// destructs
void productsDestructor(Products *p)
{
	destroyDynamicArray(p->products, (DestructFunction)productDestructor);
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
		if (productEqualAttributes(get(p->products,i), t))
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
    if(identification >= p->size)
        return 0;
    for (unsigned int i = 0; i < p->size; ++i)
        if (productGetI(get(p->products, i)) == identification) {
//            printf("%d %s %s %s %d %d %d\n", productGetI(get(p->products, i)), productGetType(get(p->products, i)),
//                   productGetProducedBy(get(p->products, i)), productGetModel(get(p->products, i)),
//                   productGetPrice(get(p->products, i)), productGetQuantity(get(p->products, i)),
//                   productGetMemory(get(p->products, i)));
            return 1;
        }
    return 0;
}

// adds a product to repository
// in:
// p = repository to where to add
// t = product to add
// out:
// the product t was added to repository p
unsigned int repositoryAdauga(Products* p, Product* t)
{
    //printf("%d %s %s %s %d %d %d\n", productGetI(t), productGetType(t), productGetProducedBy(t), productGetModel(t), productGetPrice(t), productGetQuantity(t), productGetMemory(t));
	//copy the product
    add(p->products, t);
    p->size = p->products->size;
    //t= get(p->products, p->size-1);
    //printf("%d %s %s %s %d %d %d\n", productGetI(t), productGetType(t), productGetProducedBy(t), productGetModel(t), productGetPrice(t), productGetQuantity(t), productGetMemory(t));
    return p->size-1;

}

// removes the product with identification from repository
// in:
// p = repository where to remove from
// identification = product identification
// out:
// repository = repository - product
bool repositorySterge(Products* p, unsigned int identification)
{
	if (identification >= p->size)
        return 0;

    delete(p->products, identification);
    p->size = p->products->size;
    return 1;
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
    update(p->products, i, t);
}

// returns pointer to product with identification
// in:
// p = repository where to search
// i = identification
// out:
// true
Product* repositoryGetProduct(Products* p, unsigned int i)
{
    Product *t = get(p->products, i);
    //printf("%d %s %s %s %d %d %d\n", productGetI(t), productGetType(t), productGetProducedBy(t), productGetModel(t), productGetPrice(t), productGetQuantity(t), productGetMemory(t));
    return t;
}