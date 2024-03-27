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
	Product *j = get(p->products,i);

	if (s[0])
		printf("%20u", productGetI(j));

	if (s[1])
		printf("%20s", productGetType(j));

	if (s[2])
		printf("%20s", productGetProducedBy(j));

	if (s[3])
		printf("%20s", productGetModel(j));

	if (s[4])
		printf("%20u", productGetPrice(j));

	if (s[5])
		printf("%20u", productGetQuantity(j));

	if (s[6])
		printf("%20u", productGetMemory(j));

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
void adaugare(DynamicArray *UndoL)
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

	bool r = serviceAdauga(p, type, producedBy, model, price, UndoL);

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
void actualizare(DynamicArray *UndoL)
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

		r = serviceActualizare(p, i, n, 0,UndoL);

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

	r = serviceActualizare(p, i, n, 1,UndoL);

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
void sterge(DynamicArray *UndoL)
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

	r = serviceSterge(p, i,UndoL);

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

void filter_price()
{
    int min,max;
    printf("Introduceti pretul minim:");
    scanf("%d",&min);
    printf("Introduceti pretul maxim:");
    scanf("%d",&max);
    Products p1 = filter_by_price_range(p,min,max);
    writeStart((bool[]){1,1,1,1,1,1,1});
    for (unsigned int i = 0; i < p1.size; ++i)
    {
        Product *j = get(p1.products,i);
        printf("%20u", productGetI(j));
        printf("%20s", productGetType(j));
        printf("%20s", productGetProducedBy(j));
        printf("%20s", productGetModel(j));
        printf("%20u", productGetPrice(j));
        printf("%20u", productGetQuantity(j));
        printf("%s", "\n");
    }
    productsDestructor(&p1);
}

// wait, read and write loop
// in: true
// out: true
void mainWhile(DynamicArray *UndoL)
{
	char s[] = "0 = iesire\n1 = adauga\n2 = actualizare\n3 = sterge\n4 = vizualizare\n5 = filtru\n6 = undo\n7 = filter_price\n";

	unsigned int action;

	printf("%s", s);
	scanf("%u", &action);

	while (action)
	{
		if (validAction(action))
		{
			if (action == 1)
				adaugare(UndoL);

			if (action == 2)
				actualizare(UndoL);

			if (action == 3)
				sterge(UndoL);

			if (action == 4)
				sort();

			if (action == 5)
				filter();

            if (action == 6)
                serviceUndo(p,UndoL);

            if (action == 7)
                filter_price();

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
void start(Products *products,DynamicArray *UndoL)
{
	p = products;
	mainWhile(UndoL);
}