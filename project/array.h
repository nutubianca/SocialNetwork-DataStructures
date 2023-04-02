#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <iostream>

template<typename T>
class Array {
private:
    int maxSize;
    int currentSize;
    T *array;
public:
    Array() {
        this->maxSize = 25;
        this->currentSize = 0;
        this->array = new T[this->maxSize];
    }

    ~Array() {
        if (!this->currentSize)
            delete[] this->array;
    }

    void resize() {
        /*
         * parametrii de intrare: -
         * return:-
         * -resize pentru array-ul alocat dinamic;
         * -se apeleaza cand maxSize este atins si se dubleaza;
         * marimea array-ului, alocandu-se spatiu;
         */
        this->maxSize = this->maxSize * 2;
        T *newArr = new T[this->maxSize];
        memcpy(newArr, this->array, this->maxSize * sizeof(T));
        delete[]this->array;
        this->array = newArr;
    }

    int size() {
        /*
         * parametrii de intrare: -
         * return: atributul currentSize de tip int;
         * -dimensiunea array-ului;
         */
        return this->currentSize;
    }

    void add(const T &element) {
        /*
         * -parametrii de intrare: -
         * -return: -
         * -adaugarea in array a unui element de tip T;
         * -se verifica daca se depaseste sau nu maxSize
         * cu acest nou element; in caz afirmativ, va avea loc resize()
         * care va aloca mai mult spatiu;
         */
        if (this->currentSize > this->maxSize)
            resize();
        this->array[this->currentSize++] = element;
    }

    void update(T &oldOne, const T &newOne) {
        /*
         * -parametrii de intrare: - element de tip T transmis prin referinta oldOne,
         * reprezinta elementul ce va fi inlocuit;
         * -element de tip T transmis prin referinta newOne,
         * reprezinta elementul ce va fi inlocuit;
         * -return: -
         * -are loc actualizarea datelor elementului oldOne;
         * -se verifica existenta si se cauta pozitia elementului oldOne, in caz
         * ca acesta exista, va avea loc actualizarea;
         */
        int index = findPosisiton(oldOne);
        if (index != -1)
            this->array[index] = newOne;
    }

    void deleting(const T &element) {
        /*
          * -parametrii de intrare: - element de tip T transmis prin referinta element,
          * reprezinta elementul ce va fi sters;
          * -return: -
          * -se verifica existenta si se cauta pozitia elementului element, in caz
         * ca acesta exista, va avea loc stergerea;
          */
        int index = findPosisiton(element);
        for (int i = index; i < this->currentSize; i++)
            this->array[i] = this->array[i + 1];
        this->currentSize--;
    }

    int findPosisiton(const T &element) {
        /*
         * -parametrii de intrare: -element de tip T transmis prin referinta element;
         * -return: - tip int, un nr ce va reprezenta pozitia elementului dat in array;
         * -se parcurge array-ul; daca elementul este gasit, se returneaza pozitia, in
         * caz contrar, se va returna -1;
         */
        for (int i = 0; i < this->currentSize; i++)
            if (this->array[i] == element)
                return i;
        return -1;
    }

    int exists(const T &element) {
        /*
         * -parametrii de intrare: -element de tip T transmis prin referinta element;
         * -return: - tip int, un nr ce va reprezenta valoarea de adevar a existentei
         * elementului in array;
         * -se parcurge array-ul; daca elementul este gasit, se returneaza 1, in
         * caz contrar, se va returna 0;
         */
        for (int i = 0; i < this->currentSize; i++)
            if (this->array[i] == element)
                return 1;
        return 0;
    }

    T getElement(int i) {
        /*
         * -parametrii de intrare: -de tip int, reprezinta pozitia elementului dorit;
         * -return: - tip T, elementul ce va fi gasit pe pozitia i;
         */
        return this->array[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Array<T> &a) {
        /*
         * -supraincarcarea operatoului de iesire;
         */
        for (int i = 0; i < a.currentSize; i++)
            os << a.array[i] << std::endl;
        return os;
    }
};

#endif //PROJECT_ARRAY_H
