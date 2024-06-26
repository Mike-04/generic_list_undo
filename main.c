/*

Solution written by
Ilovan Cristian Daniel

*/

#include "tests.h"
#include "ui.h"
#include "repository.h"

/*

Cerinte generale

Creati o aplicatie modulara in C.
Se cere interfata utilizator de tip consola.
Datele introduse de utilizator trebuie validate. 
Folositi athitectura stratificata.
Folositi dezvoltare dirijata de teste (Test Driven Development)
Fiecare metoda din aplicatie trebuie specificat si testat.
Implementati vector dinamic pentru lucru cu liste:
    - in prima saptamana puteti folosi reprezentarea cu un struct ( un vector static si lungime in el)
    - pana in saptamana 2 trebuie folosit alocare dinamica (sa acomodeze oricate elemente)
Timp de lucru 2 saptamani.

8 Magazin electronice

Creati o aplicatie care permite gestiunea stocului de produse intr-un magazin de electronice.
Fiecare produs are un identificator unic, tip (laptop, frigider, televizor,etc), producator, model,
pret, cantitate.
Aplicatia permite:
 a) Adaugarea de noi produse. Daca produsul este deja in stoc trebuie actualizat cantitatea
 b) Actualizare produse (modificare pret sau cantitate)
 c) Stergere produs
 d) Vizualizare produse din stoc, ordonat dupa pret, cantitate (crescator/descrescator)
 e) Vizualizare lista de produse filtrate dupa un criteriu (producator, pret, cantitate)

*/

int main()
{
	
	test();

    DynamicArray *UndoL = createDynamicArray(10);
	Products p;
	productsConstructor(&p);

	//start(&p, UndoL);

    destroyDynamicArray(UndoL, (DestructFunction) destroyDynamicArrayOfProducts);
	productsDestructor(&p);

	return 0;
}