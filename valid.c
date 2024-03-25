/*

Solution written by
Ilovan Cristian Daniel

*/

#include "valid.h"

// validate product
// in: product
// out: returns true if product is valid
// and false if not
bool validProduct(Product *p)
{
	return 1;
}

// validate identification
// in: unsigned int identification
// out: returns true if identification is valid
// and false if not
bool validIdentification(unsigned int i)
{
	return i >= 0 && i < SIZE;
}

// validate price
bool validPrice(int price)
{
	return price >= 0;
}

// validate action
// in: action
// out: returns true if action is valid
// and false if not
bool validAction(unsigned int action)
{
	return (action >= 0 && action <= 5) || action == 10;
}

// validate filterAction
// in: filterAction
// out: returns true if filterAction is valid
// and false if not
bool validFilterAction(unsigned int action)
{
	return action >= 0 && action <= 3;
}

// validate sortAction
// in: sortAction
// out: returns true if sortAction is valid
// and false if not
bool validSortActions(unsigned int i, unsigned int j)
{
	return i >= 0 && i <= 2 && j >= 0 && j <= 2;
}