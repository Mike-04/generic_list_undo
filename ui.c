/*

Solution written by
Ilovan Cristian Daniel

*/

#include "ui.h"
#include <stdio.h>
#include "repository.h"
#include "service.h"
#include "domain.h"
#include <stdbool.h>

#define CHARSIZE 100

Products *p;

// write one product attributes
// in:
// i = valid product identification
// s = valid attributes numbers to write
// out:
// writes attributes of product with identificaiton i
void writeOne(unsigned int i, bool *s)
{
	Product j = p->products[i];
	
	if (s[0])
		printf("%20u", productGetI(&j));
	
	if (s[1])
		printf("%20s", productGetType(&j));
	
	if (s[2])
		printf("%20s", productGetProducedBy(&j));
	
	if (s[3])
		printf("%20s", productGetModel(&j));
	
	if (s[4])
		printf("%20u", productGetPrice(&j));
	
	if (s[5])
		printf("%20u", productGetQuantity(&j));
	
	if (s[6])
		printf("%20u", productGetMemory(&j));
	
	printf("%s", "\n");
}

// write start
// in:
// s = valid attributes numbers to write
// out:
// true
void writeStart(bool *s)
{
	if (s[0])
		printf("%20s", "identification");
	
	if (s[1])
		printf("%20s", "type");
	
	if (s[2])
		printf("%20s", "producedBy");
	
	if (s[3])
		printf("%20s", "model");
	
	if (s[4])
		printf("%20s", "price");
	
	if (s[5])
		printf("%20s", "quantity");
	
	if (s[6])
		printf("%20s", "memory");
	
	printf("%s", "\n");
}

// writes everything from memory to n
// or writes existing products
// s = valid attributes numbers to write
// out:
// true 
void write(bool *s)
{
	unsigned int n = p->size;
	
	writeStart(s);
	
	if (s[6])
	{
		for (unsigned int i = 0; i < n; ++i)
			writeOne(i, s);
		return;
	}
	
	for (unsigned int i = 0; i < n; ++i)
		if (productGetMemory(repositoryGetProduct(p, i)))
			writeOne(i, s);
}

// reads new prouct attrbitues an adds
// the product to memory if valid functions
// return true
// in: true
// out: true
void adaugare()
{
	char type[CHARSIZE], producedBy[CHARSIZE],
	model[CHARSIZE];
	int price;
	
	printf("%s", "se asteapta tipul\n");
	scanf("%s", type);
	
	printf("%s", "se asteapta producatorul\n");
	scanf("%s", producedBy);
	
	printf("%s", "se asteapta modelul\n");
	scanf("%s", model);
	
	printf("%s", "se asteapta pretul\n");
	scanf("%d", &price);
	
	bool r = serviceAdauga(p, type, producedBy, model, price);
	
	if (r)
		printf("%s\n", "adaugare completa");
	else
		printf("%s\n", "adaugarea nu a avut loc");
}


// updates new prouct attrbitues
// if valid functions
// return true
// in: true
// out: true
void actualizare()
{
	unsigned int action, i, n;
	
	printf("%s", "0 = iesire\n1 = pret\n2 = cantitate");
	scanf("%u", &action);
	
	if (action == 0)
		return;
	
	printf("%s", "se asteapta identificatorul\n");
	scanf("%u", &i);
	
	bool r = validIdentification(i);
	
	if (!r)
	{
		printf("%s", "identificatorul nu apartine intervalului\n");
		printf("%s", "actualizarea nu a avut loc\n");
		return;
	}
	
	if (action == 1)
	{
		printf("%s", "se asteapta noul pret\n");
		scanf("%u", &n);
		
		r = serviceActualizare(p, i, n, 0);
		
		if (!r)
		{
			printf("%s", "nu exista produsul\n");
			printf("%s", "actualizarea nu a avut loc\n");
			return;
		}
		
		printf("%s", "actualizare completa\n");
		return;
	}
	
	printf("%s", "se asteapta noua cantitate\n");
	scanf("%u", &n);
	
	r = serviceActualizare(p, i, n, 1);
	
	if (!r)
	{
		printf("%s", "nu exista produsul\n");
		printf("%s", "actualizarea nu a avut loc\n");
		return;
	}
	
	printf("%s", "actualizare completa\n");
}

// reads product identification and
// removes product if valid functions
// return true
// in: true
// out: true
void sterge()
{
	unsigned int i;
	
	printf("%s", "se asteapta identificatorul unic\n");
	scanf("%u", &i);
	
	bool r = validIdentification(i);
	
	if (!r)
	{
		printf("%s", "identificatorul nu apartine intervalului\n");
		printf("%s", "stergerea nu a avut loc\n");
		return;
	}
	
	r = serviceSterge(p, i);
	
	if (r)
		printf("%s\n", "stergerea completa");
	else
		printf("%s\n", "stergearea nu a avut loc");
}

// sorts the products and writes
// the products on screen
// if valid functions return true
// in: true
// out: true
void sort()
{
	unsigned int i, j;
	
	printf("%s", "0 = iesire\n1 = pret\n2 = cantitate\n");
	scanf("%u", &i);
	
	if (i == 0)
		return;
	
	printf("%s", "0 = iesire\n1 = crescator\n2 = descrescator\n");
	scanf("%u", &j);
	
	if (j == 0)
		return;
	
	if (!validSortActions(i, j))
	{
		printf("%s", "minim o actiune nu exista\n");
		printf("%s", "sortarea nu a avut loc\n");
		return;
	}
	
	serviceSort(p, i, j, compInt);
	
	bool s[] = {1, 1, 1, 1, 1, 1};
	
	write(s);
}

// filter the products
// and write on screen
// if the valid function return true
// in: true
// out: true
void filter()
{
	unsigned int i;
	
	printf("%s", "0 = iesire\n1 = producator\n2 = pret\n3 = cantitate\n");
	
	scanf("%u", &i);
	
	if (!validFilterAction(i))
	{
		printf("%s", "actiunea nu exista\n");
		printf("%s", "filtrarea nu a avut loc\n");
		return;
	}
	
	if (i == 0)
		return;
	
	bool s[7];
	serviceFilter(s, i);
	write(s);
}

// writes the memory
// created to be used by the programmer
// the user may use it as well if needed
// in: true
// out: true
void writeAll()
{
	bool s[] = {1, 1, 1, 1, 1, 1, 1};
	write(s);
}

// wait, read and write loop
// in: true
// out: true
void mainWhile()
{
	char s[] = "0 = iesire\n1 = adauga\n2 = actualizare\n3 = sterge\n4 = vizualizare\n5 = filtru\n";
	
	unsigned int action;
	
	printf("%s", s);
	scanf("%u", &action);
	
	while (action)
	{
		if (validAction(action))
		{
			if (action == 1)
				adaugare();
			
			if (action == 2)
				actualizare();
			
			if (action == 3)
				sterge();

			if (action == 4)
				sort();
			
			if (action == 5)
				filter();
			
			if (action == 10)
				writeAll();
		}
		else
			printf("%s", "actiunea nu exista\n");
		
		printf("%s", s);
		scanf("%u", &action);
	}
}

// the main function to run the application as ui console
// in: products = address to Products object to modify
// out: products = address to Products object that was modified
void start(Products *products)
{
	p = products;
	mainWhile();
}