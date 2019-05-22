# Vecthor

Ejercicio de evaluación continua por Pablo García Peris - 53310 - EE309

Similar a la clase vector de la stl, pero creado por mí con memoria dinámica mediante el método de una lista enlazada.

La idea surgió de mezclar la lista de objetos "dinámica" creada, pero limitada a un número máximo decidido al crear el objeto,
juntándolo con lo visto sobre listas enlazadas. Todo es una plantilla, y es igual de útil y cómodo que un vector cualquiera al
tener sobrecargado el operador [] (más o menos). Probablemente falten cosas por hacer o pulir, pero de momento funciona.

Se llama Vecthor porque ya existe el vector de la stl (aunque en el momento de comenzar a hacer esto, no lo sabía, pero imaginaba que debía
existir algo así).

Hay funciones como push_back, pop_back, insert, erase, operadores [] y <<, constructor copia y destructor.

En vecthor.h está el código de verdad, de la librería; en main.cpp, un test "unitario" donde se prueban varias funcionalidades.
