//
// Created by bienu on 5/21/2022.
//

#ifndef ARRAY_H_DICTIONARY_H
#define ARRAY_H_DICTIONARY_H

#include "array.h"
#include "Node.h"
#include "iostream"

template<class T, class V>
class Dictionary {
private:
    Node<T, V> *head;
    int size;
public:
    Dictionary() {
        this->head = nullptr;
        size = 0;
    }

    void add(T key, V value) {
        /*
         *-parametrii de intrare: - key - element de tip T care va fi cheia, value - element de tip V
         * care va fi valoarea noului element din dictionar;
         * -return: -
         * -se va adauga un nou element cu cheia key si valoarea value;
         * -se verifica daca dictionarul este neinitializat, daca este, se va initializa head,
         * daca nu, se va aduga in cintinuarea ultimului element;
         */
        if (head == nullptr) {
            head = new Node<T, V>(key, value);
            this->size++;
        } else {
            Node<T, V> *p = head;
            while (p->next != nullptr && p->key != key) {
                p = p->next;
            }
            if (p->key == key) p->value = value;
            else p->next = new Node<T, V>(key, value), this->size++;
        }
    }

    void update(T key1, V value1, T key2, V value2) {
        /*
         *-parametrii de intrare: - doua chei de tip T si doua valori de tip V; respectiv primul element
         * ce va fi actualizat cu al doilea element
         * -return: -
         * - se efectueaza cautarea primului element si inlocuirea cu noul element
         */
        Node<T, V> *p = head;
        while (p != nullptr) {
            if (p->key == key1) {
                p->key = key2;
                p->value = value2;
            }
            p = p->next;
        }
    }

    void deleting(T key, V value) {
        /*
         *-parametrii de intrare: - cheie de tip T si valoarea de tip T a cheii;
         * -return: -
         * -se efectueaza cautarea elementului dat prin cheie si valoare; la gasirea
         * acestuia, va avea loc stergerea din dictionar;
         */
        Node<T, V> *p = head;
        Node<T, V> t;
        if(p->key==key)
        {
            head=p->next;
            this->size--;
        } else
        while (p->next != nullptr) {
            if (p->next->key == key) {
                p = p->next;
                p->next=p->next->next;
                this->size--;
            }
            else
                p=p->next;
        }
    }

    V search(T key) {
        /*
         *-parametrii de intrare: - cheie de tip T;
         * -return: -valoare de tip V;
         * -are loc cautarea unui element din dictionar dupa cheie si se va
         * returna valoarea aferenta;
         */
        Node<T, V> *p = head;
        while (p != nullptr) {
            if (p->key == key)
                return p->value;
            p = p->next;
        }
        return {};
    }

    int getSize() {
        /*
         *-parametrii de intrare: -
         * -return: - tip int, va reprezenta nr de elemente ale dictionarului;
         */
        return this->size;
    }

    Array<T> getKeys() {
        /*
         *-parametrii de intrare: -
         * -return: - un array cu cheile dictionarului;
         */
        Array<T> result;
        Node<T, V> *p = head;
        while (p != nullptr) {
            result.add(p->key);
            p = p->next;
        }
        return result;
    }

    Array<V> getValues() {
        /*
         *-parametrii de intrare: -
         * -return: - un aray cu valorile dictionarului;
         */
        Array<V> result;
        Node<T, V> *p = head;
        while (p != nullptr) {
            result.add(p->value);
            p = p->next;
        }
        return result;
    }
};


#endif //ARRAY_H_DICTIONARY_H
