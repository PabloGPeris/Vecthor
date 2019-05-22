#include "vecthor.h"
#include <iostream>
#include <stdlib.h>



#ifndef _TEST_UNITARIO_
#define _TEST_UNITARIO_
#endif // !_TEST_UNITARIO_

//primera vez que uso una macro para un test unitario en mi vida. No sé si lo he hecho bien


using namespace std;

int main(){
	 
#ifdef _TEST_UNITARIO_
	vecthor<int> mivec(0); //se inicializa con el número 0

	mivec.push_back(1);
	mivec.push_back(2); //añadimos un par
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.pop_back(); // eliminamos el último
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.setsize(14, 5); //añadimos 5s hasta llegar a la longitud de 14
	//si no se pone nada donde el 5, se llena según el constructor por defecto (En el caso de ints, es 0, descubierto ahora mismo)
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.setsize(10); //se reduce la longitud a 10
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.push_back(10);
	mivec.push_back(11);
	mivec.push_back(12); //se añaden cosas en su posición
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.erase(11); //se elimina el elemento de la posición 11, que curiosamente es el 11 antes puesto
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.insert(11, 100); //se inserta en el 11 un número 100
	cout << mivec << endl << "size = " << mivec.size() << endl;

	mivec.erase(0); //se elimina el primero
	cout << mivec << endl << "size = " << mivec.size() << endl;


	vecthor<int> minuevovechtor(mivec); //se comprueba que funciona el CC
	cout << minuevovechtor << endl << "size (COPIA) = " << mivec.size() << endl;
	


	mivec.setsize(0); //se pone con longitud 1 (no se puede poner longitud 0)
	cout << mivec << "size = " << mivec.size() << endl;




#endif // _TEST_UNITARIO_

	system("pause");
	return 0;
}