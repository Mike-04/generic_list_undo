/*

Solution written by
Ilovan Cristian Daniel

*/

#include "service.h"

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
bool serviceAdauga(Products* p, char* type, char* producedBy, char* model, int price)
{	
	if (!validPrice(price))
		return 0;
	
	Product t, *j;
	
	productConstructor(&t, 0, type, producedBy, model, price, 1, 1);
	
	int i = repositoryExistsAttributes(p, &t);
	
	if (i != -1)
	{
		j = repositoryGetProduct(p, i);
		productSetQuantity(j, productGetQuantity(j) + 1);
		return 1;
	}
	
	// repository part to add the product
	// the service does not know how the
	// repository stores the products
	// therefore the repository adds new products
	i = repositoryAdauga(p, &t);
	productSetI(&p->products[i], i);
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
bool serviceActualizare(Products* p, unsigned int i, unsigned int n, unsigned int j)
{
	if (!repositoryExists(p, i))
		return 0;
	
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
bool serviceSterge(Products* p, unsigned int identification)
{
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
	Product t;
	
	if (c == 1)
	{
		if (a == 1)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetPrice(&p->products[i]);
					qj = productGetPrice(&p->products[j]);
					if (comp(qj,qi))
					{
						productEqualConstructor(&t, &p->products[j]);
						productEqualConstructor(&p->products[j], &p->products[i]);
						productEqualConstructor(&p->products[i], &t);
					}
				}
		}
		
		if (a == 2)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetQuantity(&p->products[i]);
					qj = productGetQuantity(&p->products[j]);
					if (comp(qj,qi))
					{
						productEqualConstructor(&t, &p->products[j]);
						productEqualConstructor(&p->products[j], &p->products[i]);
						productEqualConstructor(&p->products[i], &t);
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
					qi = productGetPrice(&p->products[i]);
					qj = productGetPrice(&p->products[j]);
					if (comp(qi,qj))
					{
						productEqualConstructor(&t, &p->products[j]);
						productEqualConstructor(&p->products[j], &p->products[i]);
						productEqualConstructor(&p->products[i], &t);
					}
				}
		}
		
		if (a == 2)
		{
			for (unsigned int i = 0; i < size; ++i)
				for (unsigned int j = i + 1; j < size; ++j)
				{
					qi = productGetQuantity(&p->products[i]);
					qj = productGetQuantity(&p->products[j]);
					if (comp(qi,qj))
					{
						productEqualConstructor(&t, &p->products[j]);
						productEqualConstructor(&p->products[j], &p->products[i]);
						productEqualConstructor(&p->products[i], &t);
					}
				}
		}
	}
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