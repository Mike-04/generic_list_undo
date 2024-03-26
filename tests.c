/*

Solution written by
Ilovan Cristian Daniel

*/

#include "tests.h"
#include <assert.h>
#include <string.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "DynamicArray.h"
#include <stdio.h>

// domain

// product

// constructors

// test productConstructor function
// in: true
// out: true
void testProductConstructor()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productGetI(&p) == 1);
	assert(!strcmp(productGetType(&p),"a"));
	assert(!strcmp(productGetProducedBy(&p),"b"));
	assert(!strcmp(productGetModel(&p),"c"));
	assert(productGetPrice(&p) == 2);
	assert(productGetQuantity(&p) == 3);
	assert(productGetMemory(&p) == 1);
}

// test productEqualConstructor function
// in: true
// out: true
void testproductEqualConstructor()
{
	Product p, t;
	
	productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
	
	productEqualConstructor(&p, &t);
	
	assert(productGetI(&p) == 1);
	assert(!strcmp(productGetType(&p),"a"));
	assert(!strcmp(productGetProducedBy(&p),"b"));
	assert(!strcmp(productGetModel(&p),"c"));
	assert(productGetPrice(&p) == 2);
	assert(productGetQuantity(&p) == 3);
	assert(productGetMemory(&p) == 1);
}





// set functions

// test productSetI function
// in: true
// out: true
void testProductSetI()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetI(&p, 5);
	
	assert(productGetI(&p) == 5);
}

// test productSetType function
// in: true
// out: true
void testProductSetType()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetType(&p, "z");
	
	assert(!strcmp(productGetType(&p), "z"));
}

// test productSetProducedBy function
// in: true
// out: true
void testProductSetProducedBy()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetProducedBy(&p, "z");
	
	assert(!strcmp(productGetProducedBy(&p), "z"));
}

// test productSetModel function
// in: true
// out: true
void testProductSetModel()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetModel(&p, "z");
	
	assert(!strcmp(productGetModel(&p), "z"));
}

// test productSetPrice function
// in: true
// out: true
void testProductSetPrice()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetPrice(&p, 5);
	
	assert(productGetPrice(&p) == 5);
}

// test productSetQuantity function
// in: true
// out: true
void testProductSetQuantity()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetQuantity(&p, 5);
	
	assert(productGetQuantity(&p) == 5);
}

// test productSetMemory function
// in: true
// out: true
void testProductSetMemory()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	productSetMemory(&p, 0);
	
	assert(productGetMemory(&p) == 0);
}





// get functions

// test productGetI function
// in: true
// out: true
void testProductGetI()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productGetI(&p) == 1);
}

// test productGetType function
// in: true
// out: true
void testProductGetType()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(!strcmp(productGetType(&p),"a"));
}

// test productGetProducedBy function
// in: true
// out: true
void testProductGetProducedBy()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(!strcmp(productGetProducedBy(&p),"b"));
}

// test productGetModel function
// in: true
// out: true
void testProductGetModel()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(!strcmp(productGetModel(&p),"c"));
}

// test productGetPrice function
// in: true
// out: true
void testProductGetPrice()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productGetPrice(&p) == 2);
}

// test productGetQuantity function
// in: true
// out: true
void testProductGetQuantity()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productGetQuantity(&p) == 3);
}

// test productGetMemory function
// in: true
// out: true
void testProductGetMemory()
{
	Product p;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productGetMemory(&p) == 1);
}





// operator functions

// test productEqualAttributes function
// in: true
// out: true
void testProductEqualAttributes()
{
	Product p, t;
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
	
	assert(productEqualAttributes(&p, &t));
	
	productConstructor(&p, 1, "a", "b", "c", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "c", 2, 3, 1);
	
	assert(productEqualAttributes(&p, &t));
	
	productConstructor(&p, 1, "a", "b", "c", 5, 3, 1);
	productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
	
	assert(!productEqualAttributes(&p, &t));
	
	productConstructor(&p, 1, "a", "b", "c", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "z", 2, 3, 1);
	
	assert(!productEqualAttributes(&p, &t));
	
	productConstructor(&p, 1, "z", "b", "c", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "z", 2, 3, 1);
	
	assert(!productEqualAttributes(&p, &t));
	
	productConstructor(&p, 1, "a", "z", "z", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "z", 2, 3, 1);
	
	assert(!productEqualAttributes(&p, &t));
}





// test product function
// in: true
// out: true
void testProduct()
{
	// constructors
	testProductConstructor();
	testproductEqualConstructor();

	// set functions
	testProductSetI();
	testProductSetType();
	testProductSetProducedBy();
	testProductSetModel();
	testProductSetPrice();
	testProductSetQuantity();
	testProductSetMemory();

	// get functions
	testProductGetI();
	testProductGetType();
	testProductGetProducedBy();
	testProductGetModel();
	testProductGetPrice();
	testProductGetQuantity();
	testProductGetMemory();

	// operator functions
	testProductEqualAttributes();
}





// repository

// products

// test productsConstructor function
// in: true
// out: true
void testProductsConstructor()
{
	Products p;
	
	productsConstructor(&p);
	
	assert(p.size == 0);
	assert(p.products == NULL);
}

// test repositoryExistsAttributes function
// in: true
// out: true
void testRepositoryExistsAttributes()
{
	Products r;
	Product p, t;
	
	productsConstructor(&r);
	
	// test 1
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExistsAttributes(&r, &t) == 0);
	repositorySterge(&r, 0);
	
	productsDestructor(&r);
	productsConstructor(&r);
	
	// test 2
	productConstructor(&p, 1, "a", "b", "c", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExistsAttributes(&r, &t) == 0);
	repositorySterge(&r, 0);
	
	productsDestructor(&r);
	productsConstructor(&r);
	
	// test 3
	productConstructor(&p, 1, "a", "b", "c", 5, 3, 1);
	productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExistsAttributes(&r, &t) == -1);
	repositorySterge(&r, 0);
	
	productsDestructor(&r);
	productsConstructor(&r);
	
	// test 4
	productConstructor(&p, 1, "a", "b", "c", 2, 1, 1);
	productConstructor(&t, 0, "a", "b", "z", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExistsAttributes(&r, &t) == -1);
	repositorySterge(&r, 0);
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testRepositoryExists()
{
	Products r;
	Product p;
	
	productsConstructor(&r);
	
	// test 1
	assert(!repositoryExists(&r, 0));
	productConstructor(&p, 0, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExists(&r, 0));
	
	// test 2
	assert(!repositoryExists(&r, 1));
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExists(&r, 1));
	
	// test 3
	assert(!repositoryExists(&r, 2));
	productConstructor(&p, 2, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExists(&r, 2));
	
	// test 4
	assert(!repositoryExists(&r, 3));
	productConstructor(&p, 3, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	assert(repositoryExists(&r, 3));
	repositorySterge(&r, 3);
	assert(!repositoryExists(&r, 3));
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testRepositoryAdauga()
{
	Products r;
	Product p, *t;
	
	productsConstructor(&r);
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	
	t = repositoryGetProduct(&r, 0);
	
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 3);
	assert(productGetMemory(t) == 1);
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testRepositorySterge()
{
	Products r;
	Product p, *t;
	
	productsConstructor(&r);
	
	productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
	repositoryAdauga(&r, &p);
	repositorySterge(&r, 0);
	
	t = repositoryGetProduct(&r, 0);
	
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 3);
	assert(productGetMemory(t) == 0);
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testRepositorySetProduct()
{
	Products r;
	Product p, *t;
	
	productsConstructor(&r);
	
	productConstructor(&p, 0, "a", "b", "z", 2, 3, 1);
	repositoryAdauga(&r, &p);
	productConstructor(&p, 0, "a", "b", "c", 2, 3, 1);
	repositorySetProduct(&r, 0, &p);
	
	assert(repositoryExists(&r, 0));
	
	t = repositoryGetProduct(&r, 0);
	
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 3);
	assert(productGetMemory(t) == 1);
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testRepositoryGetProduct()
{
	Products r;
	Product p, *t;
	
	productsConstructor(&r);
	
	productConstructor(&p, 0, "a", "b", "z", 2, 3, 1);
	repositoryAdauga(&r, &p);
	productConstructor(&p, 0, "a", "b", "c", 2, 3, 1);
	repositorySetProduct(&r, 0, &p);
	
	assert(repositoryExists(&r, 0));
	
	t = repositoryGetProduct(&r, 0);
	
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 3);
	assert(productGetMemory(t) == 1);
	
	productsDestructor(&r);
}

// tests a products (repository) function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testProducts()
{
	testProductsConstructor();

	testRepositoryExistsAttributes();
	testRepositoryExists();
	testRepositoryAdauga();
	testRepositorySterge();

	testRepositorySetProduct();
	testRepositoryGetProduct();
}





// service

// tests a service function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testServiceAdauga()
{
	Products r;
	Product *p;
	
	productsConstructor(&r);
	serviceAdauga(&r, "a", "b", "c", 1);
	
	assert(repositoryExists(&r, 0));
	
	p = repositoryGetProduct(&r, 0);
	
	assert(productGetI(p) == 0);
	assert(!strcmp(productGetType(p),"a"));
	assert(!strcmp(productGetProducedBy(p),"b"));
	assert(!strcmp(productGetModel(p),"c"));
	assert(productGetPrice(p) == 1);
	assert(productGetQuantity(p) == 1);
	assert(productGetMemory(p) == 1);
	
	assert(!serviceAdauga(&r, "a", "b", "c", -1));
	
	productsDestructor(&r);
}

// tests a service function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testServiceActualizare()
{
	Products r;
	Product *p;
	
	productsConstructor(&r);
	serviceAdauga(&r, "a", "b", "c", 1);
	serviceActualizare(&r, 0, 2, 0);
	serviceActualizare(&r, 0, 3, 1);
	p = repositoryGetProduct(&r, 0);
	
	assert(productGetI(p) == 0);
	assert(!strcmp(productGetType(p),"a"));
	assert(!strcmp(productGetProducedBy(p),"b"));
	assert(!strcmp(productGetModel(p),"c"));
	assert(productGetPrice(p) == 2);
	assert(productGetQuantity(p) == 3);
	assert(productGetMemory(p) == 1);
	
	assert(serviceActualizare(&r, 1, 1, 1) == 0);
	
	productsDestructor(&r);
}

// tests a service function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testServiceSterge()
{
	Products r;
	
	productsConstructor(&r);
	serviceAdauga(&r, "a", "b", "c", 1);
	assert(repositoryExists(&r, 0));
	serviceSterge(&r, 0);
	assert(!repositoryExists(&r, 0));
	productsDestructor(&r);
}

// tests a service function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testServiceSort1()
{
	Products p;
	Product *t;
	
	productsConstructor(&p);
	serviceAdauga(&p, "a", "b", "c", 1);
	serviceAdauga(&p, "a", "b", "c", 1);
	serviceAdauga(&p, "a", "b", "z", 2);
	
	// test 1
	serviceSort(&p, 1, 1, compInt);
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 2
	serviceSort(&p, 1, 2, compInt);
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 2
	serviceSort(&p, 2, 2, compInt);
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 4
	serviceSort(&p, 2, 1, compInt);
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	productsDestructor(&p);
}

void testServiceSort2()
{Products p;
	Product *t;
	
	productsConstructor(&p);
	serviceAdauga(&p, "a", "b", "z", 2);
	serviceAdauga(&p, "a", "b", "c", 1);
	serviceAdauga(&p, "a", "b", "c", 1);
	
	// test 1
	serviceSort(&p, 1, 1, compInt);
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 2
	serviceSort(&p, 1, 2, compInt);
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 2
	serviceSort(&p, 2, 2, compInt);
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	// test 4
	serviceSort(&p, 2, 1, compInt);
	t = repositoryGetProduct(&p, 1);
	assert(productGetI(t) == 1);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"c"));
	assert(productGetPrice(t) == 1);
	assert(productGetQuantity(t) == 2);
	assert(productGetMemory(t) == 1);
	
	t = repositoryGetProduct(&p, 0);
	assert(productGetI(t) == 0);
	assert(!strcmp(productGetType(t),"a"));
	assert(!strcmp(productGetProducedBy(t),"b"));
	assert(!strcmp(productGetModel(t),"z"));
	assert(productGetPrice(t) == 2);
	assert(productGetQuantity(t) == 1);
	assert(productGetMemory(t) == 1);
	
	productsDestructor(&p);
}

void testServiceSort()
{
	testServiceSort1();
	testServiceSort2();
}

// tests a service function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testServiceFilter()
{
	bool s[7];
	
	// test 1
	for (unsigned int i = 0; i < 7; ++i)
		s[i] = 0;
	serviceFilter(s, 1);
	for (unsigned int i = 0; i < 7; ++i)
		if (i == 2)
			assert(s[i]);
		else
			assert(!s[i]);
		
	// test 2
	for (unsigned int i = 0; i < 7; ++i)
		s[i] = 0;
	serviceFilter(s, 2);
	for (unsigned int i = 0; i < 7; ++i)
		if (i == 4)
			assert(s[i]);
		else
			assert(!s[i]);
		
	// test 3
	for (unsigned int i = 0; i < 7; ++i)
		s[i] = 0;
	serviceFilter(s, 3);
	for (unsigned int i = 0; i < 7; ++i)
		if (i == 5)
			assert(s[i]);
		else
			assert(!s[i]);
		
	// test 4
	for (unsigned int i = 0; i < 7; ++i)
		s[i] = 0;
	serviceFilter(s, 0);
	for (unsigned int i = 0; i < 7; ++i)
		assert(!s[i]);
}

// test valid

// tests a valid function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testValidProduct()
{
	Product p;
	productConstructor(&p, 0, "a", "b", "c", 3, 5, 1);
	assert(validProduct(&p));
}

// tests a valid function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testValidIdentification()
{
	for (int i = -SIZE; i < 0; ++i)
		assert(!validIdentification(i));
	for (unsigned int i = 0; i < SIZE; ++i)
		assert(validIdentification(i));
}

// tests a valid function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testValidAction()
{
	for (unsigned int i = 0; i <= 5; ++i)
		assert(validAction(i));
	assert(validAction(10));
	for (unsigned int i = 11; i <= 1000; ++i)
		assert(!validAction(i));
}

// tests a valid function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testValidFilterAction()
{
	for (int i = -1000; i < 0; ++i)
		assert(!validFilterAction(i));
	for (unsigned int i = 0; i <= 3; ++i)
		assert(validFilterAction(i));
	for (unsigned int i = 4; i <= 1000; ++i)
		assert(!validFilterAction(i));
}

// tests a valid function
// the name of the function is after
// "test" from the name of this function
// in: true
// out: true
void testValidSortActions()
{
	for (int i = -100; i <= 100; ++i)
		for (int j = -100; j <= 100; ++j)
			if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
				assert(validSortActions(i, j));
			else
				assert(!validSortActions(i, j));
}




// parts

// test domain
// in: true
// out: domain was tested
void testDomain()
{
	testProduct();
}

// test repository
// in: true
// out: repository was tested
void testRepository()
{
	testProducts();
}

// test service
// in: true
// out: service was tested
void testService()
{
	testServiceAdauga();
	testServiceActualizare();
	testServiceSterge();
	testServiceSort();
	testServiceFilter();
}

// test valid
// in: true
// out: valid was tested
void testValid()
{
	testValidProduct();
	testValidIdentification();
	testValidAction();
	testValidFilterAction();
	testValidSortActions();
}


void testAddUpdateDeleteDynamicArray(){
    //function that tests the add, update and delete functions of the dynamic array
    DynamicArray* da = createDynamicArray();
    Product p, t, u,l;
    // test 1
    productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
    productConstructor(&t, 2, "a", "b", "c", 2, 3, 1);
    productConstructor(&u, 3, "a", "b", "c", 2, 3, 1);
    add(da, &p);
    add(da, &t);
    add(da, &u);
    display(da);
    assert(da->size == 3);
    printf("\n");
    // test 2
    productConstructor(&l, 2, "a2", "b2", "c2", 2, 3, 1);
    update(da, 1, &l);
    display(da);
    assert(da->size == 3);
    printf("\n");
    // test 3
    delete(da, 1);
    display(da);
    assert(da->size == 2);
    printf("\n");
    destroyDynamicArray(da, productDestructor);
}


void testDynamicArraySimple(){
    //fucntion that creates some products and adds them to the dynamic array
    DynamicArray* da = createDynamicArray();
    Product p, t;
    // test 1
    productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
    productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
    add(da, &p);
    add(da, &t);
    assert(da->size == 2);

    destroyDynamicArray(da, productDestructor);
}

void testDynamicArrayOfDynamicArrays(){
    //create a dynamic array of dynamic arrays
    DynamicArray* da = createDynamicArray();
    DynamicArray* da1 = createDynamicArray();
    DynamicArray* da2 = createDynamicArray();
    Product p, t;
    // test 1
    productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
    productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);

    add(da1, &p);
    add(da1, &t);
    add(da, da1);
    add(da, da2);
    display(da1);
    assert(da->size == 2);
    //destroy the dynamic array of dynamic arrays
    destroyDynamicArray(da, destroyDynamicArrayOfProducts);
}

void testcopyDynamicArrayofProducts(){
    //create a dynamic array of products and copy it
    DynamicArray* da = createDynamicArray();
    Product p, t;
    // test 1
    productConstructor(&p, 1, "a", "b", "c", 2, 3, 1);
    productConstructor(&t, 1, "a", "b", "c", 2, 3, 1);
    add(da, &p);
    add(da, &t);
    DynamicArray* da1 = copyDynamicArrayofProducts(da);
    destroyDynamicArray(da, productDestructor);
    assert(da1->size == 2);
    display(da1);
    destroyDynamicArray(da1, productDestructor);
}

// main

// test domain, repository and service
// in: true
// out: domain, repository and service were tested
void test()
{
    testAddUpdateDeleteDynamicArray();
    testDynamicArraySimple();
	testDynamicArrayOfDynamicArrays();
    testcopyDynamicArrayofProducts();
    testDomain();
	testRepository();
	testService();
	testValid();
}