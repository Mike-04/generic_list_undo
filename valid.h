/*

Solution written by
Ilovan Cristian Daniel

*/

#ifndef VALID_H
#define VALID_H

#include <stdbool.h>
#include "domain.h"
#include "repository.h"

// validate product
// in: product
// out: returns true if product is valid
// and false if not
bool validProduct(Product*);

// validate price
bool validPrice(int price);

// validate identification
// in: unsigned int identification
// out: returns true if identification is valid
// and false if not
bool validIdentification(unsigned int);

// validate action
// in: action
// out: returns true if action is valid
// and false if not
bool validAction(unsigned int);

// validate filterAction
// in: filterAction
// out: returns true if filterAction is valid
// and false if not
bool validFilterAction(unsigned int);

// validate sortAction
// in: sortAction
// out: returns true if sortAction is valid
// and false if not
bool validSortActions(unsigned int i, unsigned int j);

#endif