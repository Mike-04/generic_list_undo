typedef void* Element;
typedef void (*DestructFunction)(Element);

typedef struct {
    Element* elems;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray();

void destroyDynamicArray(DynamicArray* arr, DestructFunction f);

void destroyDynamicArrayOfProducts(DynamicArray *arr);


void add(DynamicArray* arr, Element e);

void delete(DynamicArray* arr, int pos);

void update(DynamicArray* arr, int pos, Element e);

void display(DynamicArray *arr);

DynamicArray *copyDynamicArrayofProducts(DynamicArray *arr);

int getSize(DynamicArray* arr);

Element get (DynamicArray* arr, int pos);