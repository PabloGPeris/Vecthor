#pragma once

#include <iostream>
#include <ostream>
//es el Dios del Trueno y los Vectores, el gran VecThor

using namespace std;

template <typename T> class vecthor {
private:
	T valor;
	vecthor* siguiente;

public:
	//Constructor y destructor
	vecthor() : valor(), siguiente(NULL) { ; }
	vecthor(const vecthor<T> & c); //constructor copia definido luego
	vecthor(T valor_inicial) : valor(valor_inicial), siguiente(NULL) { ; }

	virtual ~vecthor(){ //he descubierto hoy (tras el examen) para qué sirve el destructor virtual
		if (siguiente != NULL) {
			delete this->siguiente; //se destruye recursivamente
			//siguiente = NULL; //¿innecesario? 
		}
	}

	//Funciones básicas
	size_t size();

	vecthor* push_back(const T& a = T());
	vecthor* pop_back();
	vecthor* setsize(size_t lon, const T& a = T());
	vecthor* erase(unsigned int pos);
	vecthor* insert(unsigned int pos, const T& a);


	ostream& print(ostream& ost = cout);



	//Operadores
	T& operator [] (unsigned int pos);

};

/*----------------------------------
--------  C . C O P I A    ---------
----------------------------------*/


template <typename T> vecthor<T>::vecthor(const vecthor<T> & c) { //constructor copia definido luego
	const vecthor* vc = &c;
	this->valor = vc->valor;
	vecthor* vt = this;
	while (vc->siguiente != NULL) {
		vc = vc->siguiente;	
		vt->siguiente = new vecthor<T>(vc->valor);
		vt = vt->siguiente;
	}
}



/*----------------------------------
-------- F U N C I O N E S ---------
----------------------------------*/

//AÑADE UN VALOR AL VECTOR AL FINAL
template <typename T> vecthor<T> * vecthor<T>::push_back(const T& a) {
	vecthor *vt;
	vt = this;
	while (vt->siguiente != NULL) { //llega hasta el final
		vt = vt->siguiente;
	}
	vt->siguiente = new vecthor(a); //crea el valor
	return vt ->siguiente;
}

//IMPRIME EL VECTOR EN UN OSTREAM
template <typename T> ostream& vecthor<T>::print(ostream& ost) {
	int l = size();
	vecthor *vt;
	vt = this;

	for (int i = 0; i < l; i++) {
		ost << vt->valor << ' ';
		vt = vt->siguiente;
		//ost << this->operator[] (i) << ' '; otra forma muy fea de hacerlo pero que funciona :) y que es menos rápida computacionalmente hablando
	} 
	return ost;
}

//DEVUELVE LA LONGITUD DEL VECTOR
template <typename T> size_t vecthor<T>::size() {
	vecthor* vt;
	vt = this;
	int i = 1; //empieza en 1
	while (vt->siguiente != NULL) {
		vt = vt->siguiente;
		i++;
	} 
	return i;
}

//RECORTA O AUMENTA EL VECTHOR HASTA LAS DIMENSIONES NECESARIAS
template <typename T> vecthor<T>* vecthor<T>::setsize(size_t ln, const T& a) {
	int la = size(); //longitud actual --- ln = longitud nueva
	vecthor* vt = this;
	//if (ln <= 0) ln = 1; //innecesario
	if (ln < la) { //si es menor, se va hasta la posición de la longitud pedida, y destruye lo siguiente
		for (int i = 1; i < ln; i++) { //i empieza en 1
			vt = vt->siguiente;
		}
		delete vt->siguiente;
		vt->siguiente = NULL;
	}
	else if (ln > la) { //si es mayor, se crean más, tantos como diferencia haya entre lo deseado y lo actual
		for (int i = 0; i < ln - la; i++) {
			push_back(a);
		}
	}
	return vt;
}

//ELIMINA EL ÚLTIMO
template <typename T> vecthor<T>* vecthor<T>::pop_back() {
	vecthor* vt;
	vecthor* vt_anterior = this;
	vt = this;
	if (vt->siguiente == NULL) return vt; //no se puede eliminar el primer valor si es el último también.
	while (vt->siguiente != NULL) {
		vt_anterior = vt;
		vt = vt->siguiente;
	}
	delete vt;
	vt_anterior->siguiente = NULL;
	return vt_anterior;
}

//ELIMINA EL QUE ESTÁ EN LA POSICIÓN PEDIDA
template <typename T> vecthor<T>* vecthor<T>::erase(unsigned int pos) {
	vecthor* vt;
	vecthor* vt_anterior;
	vt = this;
	vt_anterior = this; //me daba error de compilación si no lo incializaba

	if (pos >= size()) return NULL; //no puedes eliminar algo que no existe
	if (pos == 0) { //si quieres eliminar el primero, hay que hacerlo especial
		if (vt->siguiente == NULL) return NULL; //no puedes eliminar el primero si no hay un segundo
		vt = vt->siguiente;
		vt_anterior->valor = vt->valor; //la primera posición adquiere el valor de la siguiente
		vt_anterior->siguiente = vt->siguiente; 
		vt->siguiente = NULL; //necesario, ya que si no, elimina todo lo siguiente (véase el destructor)
		delete vt; //se elimina la segunda posición
		return vt_anterior;
	} 
	for (int i = 0; i < pos; i++) {
		vt_anterior = vt;
		vt = vt->siguiente;
	}
	vt_anterior->siguiente = vt->siguiente;
	vt->siguiente = NULL; //necesario, ya que si no, elimina todo lo siguiente (véase el destructor)
	delete vt;
	return vt_anterior;
}

//INSERTA UN NUEVO VALOR EN LA POSICIÓN PEDIDA
template <typename T> vecthor<T>* vecthor<T>::insert(unsigned int pos, const T& a) {
	vecthor* vt;
	vecthor* vt_anterior;
	vt = this;
	vt_anterior = this;
	if (pos < 0) return NULL;
	if (pos >= size()) return setsize(pos, a); //si pones un valor mayor, rellena hasta dicho valor
	if (pos == 0) {
		vt = vt->siguiente;
		vt_anterior->siguiente = new vecthor(vt_anterior->valor); //crea uno nuevo en la segunda posición con el valor del primero
		vt_anterior->siguiente->siguiente = vt;
		vt_anterior->valor = a;
	}
	for (int i = 0; i < pos; i++) {
		vt_anterior = vt;
		vt = vt->siguiente;
	}
	vt_anterior->siguiente = new vecthor(a); //crea un valor nuevo
	vt_anterior->siguiente->siguiente = vt; //cierra el hueco creado, enlazanco el nuevo valor con lo siguiente
	return vt->siguiente;
}

/*----------------------------------
------ S O B R E C A R G A ---------
----------------------------------*/

//print - VERSIÓN PARA char (sin espacios)
ostream& vecthor<char>::print(ostream& ost) {
	int l = size();
	for (int i = 0; i < l; i++) {
		ost << this->operator[] (i); //forma muy fea de hacerlo pero que funciona :)
	}
	return ost;
}
//también medio hice una versión para matrices ( vector<vector<T>> ) pero mejor eso ya lo hago bien en verano... si eso

/*----------------------------------
-------- O P E R A D O R E S -------
----------------------------------*/

//DEVUELVE (POR REFERENCIA) EL VALOR DE LA POSICIÓN [i]
template <typename T> T& vecthor<T>::operator [] (unsigned int pos) {
	vecthor *vt;
	vt = this;
	for (int i = 0; i < pos; i++) {
		if (vt->siguiente == NULL) break;//si te pasas, devuelve el valor del último.
		else vt = vt->siguiente;
	}
	return vt->valor; 
}

//lo defino fuera
template <typename T> ostream&  operator << (ostream& o, vecthor<T>& v) {
	v.print(o);
	return o;
}