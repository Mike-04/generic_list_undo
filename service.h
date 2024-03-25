/*

Solution written by
Ilovan Cristian Daniel

*/

#ifndef SERVICE_H
#define SERVICE_H

#include "repository.h"
#include "valid.h"

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
bool serviceAdauga(Products*, char*, char*, char*, int);

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
bool serviceActualizare(Products*, unsigned int, unsigned int, unsigned int);

// removes product from repository
// in:
// p = repository
// identification = product identification to remove
// out:
// the product from repository is removed
// only by setting attribute memory of the product = 0
// the function returns valid function value
bool serviceSterge(Products*, unsigned int);

bool compInt(unsigned int a, unsigned int b);

// sorts products
// in:
// p = repository
// a = sort attribute
// c = sort order
// out:
// p is sorted
void serviceSort(Products* p, unsigned int a, unsigned int c,
	bool (*comp)(unsigned int, unsigned int));

// saves the filters in s for a filter action
// in:
// i = filter action
// s = array of size >= 7
// out:
// s = filters
void serviceFilter(bool*, unsigned int);

#endif