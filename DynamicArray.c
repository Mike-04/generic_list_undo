#include "DynamicArray.h"
#include <stdlib.h>
#include "domain.h"
#include <stdio.h>

DynamicArray *createDynamicArray()
{
    DynamicArray *arr =malloc(sizeof(DynamicArray));
    arr->size = 0;
    arr->capacity = 10;
    arr->elems = malloc(sizeof(Element) * arr->capacity);
    return arr;
}

void destroyDynamicArray(DynamicArray *arr, DestructFunction destructF)
{
    for (int i = 0; i < arr->size; i++)
        destructF(arr->elems[i]);
    free(arr->elems);
    free(arr);
}

void destroyDynamicArrayOfProducts(DynamicArray *arr)
{
    destroyDynamicArray(arr, productDestructor);
}

void resize(DynamicArray *arr)
{
    arr->capacity *= 2;
    Element *newElems = malloc(sizeof(Element) * arr->capacity);
    for (int i = 0; i < arr->size; i++)
        newElems[i] = arr->elems[i];
    free(arr->elems);
    arr->elems = newElems;
}

void add(DynamicArray *arr, Element e)
{
    //print element
    //printf("Product %d: %s %s %s %d %d\n", ((Product *)e)->i, ((Product *)e)->type, ((Product *)e)->producedBy, ((Product *)e)->model, ((Product *)e)->price, ((Product *)e)->quantity);
    if (arr->size == arr->capacity)
        resize(arr);
    arr->elems[arr->size++] = e;
    //e = get(arr, arr->size - 1);
    //printf("Product %d: %s %s %s %d %d\n", ((Product *)e)->i, ((Product *)e)->type, ((Product *)e)->producedBy, ((Product *)e)->model, ((Product *)e)->price, ((Product *)e)->quantity);
}

void delete(DynamicArray *arr,unsigned int pos)
{
    productDestructor(arr->elems[pos]);
    for (int i = pos; i < arr->size - 1; i++)
        arr->elems[i] = arr->elems[i + 1];
    arr->size--;
}

void update(DynamicArray *arr,unsigned int pos, Element e)
{
    productDestructor(arr->elems[pos]);
    arr->elems[pos] = e;
}

int getSize(DynamicArray *arr)
{
    return arr->size;
}

Element get(DynamicArray *arr,unsigned int pos)
{
    return arr->elems[pos];
}

void display(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        Product *p = (Product *)arr->elems[i];
        printf("Product %d: %s %s %s %d %d\n", p->i, p->type, p->producedBy, p->model, p->price, p->quantity);
    }
}

DynamicArray *copyDynamicArrayofProducts(DynamicArray *arr)
{
    DynamicArray *newArr = createDynamicArray();
    for (int i = 0; i < arr->size; i++)
    {
        Element p = get(arr, i);
        add(newArr, p);
    }
    return newArr;
}