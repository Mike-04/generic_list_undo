/*

Solution written by
Ilovan Cristian Daniel

*/
#include "domain.h"
#include "service.h"
#include <stdio.h>

// adds new product with attributs
// in:
// p = repository
// type = char pointer to CHARSIZE array for product type
// producedBy = char pointer to CHARSIZE array for product proudcedBy
// model = char pointer to CHARSIZE array for product model
// price = unsigned int value for product price
// out:
// if the validation functions return true
// the repository p will have a new product
// with the attributes or the quantity of
// existing product with the same attribute will increase
// and the function returns true
// if the validation functions return false
// the repository does not change and the function
// returns false

void serviceUndo(Products* p,DynamicArray* UndoL)
{
    destroyDynamicArray(p->products, (DestructFunction)productDestructor);
    p->products = copyDynamicArrayofProducts(get(UndoL, UndoL->size-1));
    p->size = p->products->size;
    destroyDynamicArray(get(UndoL, UndoL->size-1), (DestructFunction)productDestructor);
//    for (int i = UndoL->size-1; i < UndoL->size - 1; i++)
//        UndoL->elems[i] = UndoL->elems[i + 1];
    UndoL->size--;

}

bool serviceAdauga(Products* p, char* type, char* producedBy, char* model, int price, DynamicArray* UndoL)
{
	if (!validPrice(price))
		return 0;
    DynamicArray * l = copyDynamicArrayofProducts(p->products);
    add(UndoL, l);
    //display the undo list
    for(int i = 0; i < UndoL->size; i++)
    {
        DynamicArray * t = get(UndoL, i);
        display(t);
    }
    //display(UndoL);
	Product *j;
    int id;
    id = p->size;
	Product * t=productConstructor(id, type, producedBy, model, price, 1, 1);
	int i = repositoryExistsAttributes(p, t);
	if (i != -1)
	{
		j = repositoryGetProduct(p, i);
		productSetQuantity(j, productGetQuantity(j) + 1);
        productDestructor(t);
		return 1;
	}
    //printf("%d %s %s %s %d %d %d\n", productGetI(&t), productGetType(&t), productGetProducedBy(&t), productGetModel(&t), productGetPrice(&t), productGetQuantity(&t), productGetMemory(&t));

    // repository part to add the product
	// the service does not know how the
	// repository stores the products
	// therefore the repository adds new products
	repositoryAdauga(p, t);
    //t = repositoryGetProduct(p, p->size-1);
    //printf("%d %s %s %s %d %d %d\n", productGetI(t), productGetType(t), productGetProducedBy(t), productGetModel(t), productGetPrice(t), productGetQuantity(t), productGetMemory(t));

//	productSetI(&p->products[i], i);
	return 1;
}

// updates existing product
// in:
// p = repository where to update
// i = unsigned int identification
// n = value to update
// j = what to update
// out:
// the product with identification from repository
// will be updated if the validation functions return true
// and the function returns true
// if the validation functions return false
// the function returns false
bool serviceActualizare(Products* p, unsigned int i, unsigned int n, unsigned int j,DynamicArray* UndoL)
{
	if (!repositoryExists(p, i))
		return 0;

    DynamicArray * l = copyDynamicArrayofProducts(p->products);
    add(UndoL, l);

	Product *t = repositoryGetProduct(p, i);

	if (j == 0)
		productSetPrice(t, n);

	if (j == 1)
		productSetQuantity(t, n);

	return 1;
}

// removes product from repository
// in:
// p = repository
// identification = product identification to remove
// out:
// the product from repository is removed
// only by setting attribute memory of the product = 0
// the function returns valid function value
bool serviceSterge(Products* p, unsigned int identification,DynamicArray * UndoL)
{
    DynamicArray * l = copyDynamicArrayofProducts(p->products);
    add(UndoL, l);
	return repositorySterge(p, identification);
}

bool compInt(unsigned int a, unsigned int b)
{
	return a < b;
}

// sorts products
// in:
// p = repository
// a = sort attribute
// c = sort order
// out:
// p is sorted
void serviceSort(Products* p, unsigned int a, unsigned int c,
	bool (*comp)(unsigned int, unsigned int))
{
	unsigned int size = p->size, qi, qj;
	Product * t = productConstructor(0, "", "", "", 0, 0, 0);

	if (c == 1)
	{
		if (a == 1)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetPrice(repositoryGetProduct(p,i));
					qj = productGetPrice(repositoryGetProduct(p,j));
					if (comp(qj,qi))
					{
						//swap products
                        productEqualConstructor(t, repositoryGetProduct(p, j));
                        productEqualConstructor(repositoryGetProduct(p,j), repositoryGetProduct(p,i));
                        productEqualConstructor(repositoryGetProduct(p,i), t);
					}
				}
		}

		if (a == 2)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetQuantity(repositoryGetProduct(p, i));
					qj = productGetQuantity(repositoryGetProduct(p, j));
					if (comp(qj,qi))
					{
						productEqualConstructor(t, repositoryGetProduct(p, j));
						productEqualConstructor(repositoryGetProduct(p,j), repositoryGetProduct(p,i));
						productEqualConstructor(repositoryGetProduct(p,i), t);
					}
				}
		}
	}



	if (c == 2)
	{
		if (a == 1)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetPrice(repositoryGetProduct(p,i));
					qj = productGetPrice(repositoryGetProduct(p,j));
					if (comp(qi,qj))
					{
                        productEqualConstructor(t, repositoryGetProduct(p, j));
                        productEqualConstructor(repositoryGetProduct(p,j), repositoryGetProduct(p,i));
                        productEqualConstructor(repositoryGetProduct(p,i), t);
					}
				}
		}

		if (a == 2)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetQuantity(repositoryGetProduct(p,i));
					qj = productGetQuantity(repositoryGetProduct(p,j));
					if (comp(qi,qj))
					{
                        productEqualConstructor(t, repositoryGetProduct(p, j));
                        productEqualConstructor(repositoryGetProduct(p,j), repositoryGetProduct(p,i));
                        productEqualConstructor(repositoryGetProduct(p,i), t);
					}
				}
		}
	}
    productDestructor(t);
}


Products filter_by_price_range(Products* p,int min,int max)
{
    Products f;
    productsConstructor(&f);
    unsigned int size = p->size;
    for (unsigned int i = 0; i < size; ++i)
    {
        Product * t = repositoryGetProduct(p, i);
        if (productGetPrice(t) >= min && productGetPrice(t) <= max)
        {
            Product *j = productConstructor(productGetI(t), productGetType(t), productGetProducedBy(t), productGetModel(t), productGetPrice(t), productGetQuantity(t), productGetMemory(t));
            add(f.products, j);
            f.size = f.products->size;
        }
    }
    return f;
}

// saves the filters in s for a filter action
// in:
// i = filter action
// s = array of size >= 7
// out:
// s = filters
void serviceFilter(bool *s, unsigned int i)
{
	for (unsigned int i = 0; i < 7; ++i)
		s[i] = 0;

	if (i == 1)
		s[2] = 1;

	if (i == 2)
		s[4] = 1;

	if (i == 3)
		s[5] = 1;
}