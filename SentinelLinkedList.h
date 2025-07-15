#pragma once

#include <iostream>
using namespace std;

/**
 * @brief Lista ligada con centinela (doblemente enlazada circular).
 */
template <typename T>
class SentinelLinkedList
{
private:
    /**
     * @brief Nodo interno de la lista.
     */
    template <typename U>
    class Node
    {
    public:
        U data;
        Node<U>* next;
        Node<U>* prev;

        Node()
            : next(nullptr), prev(nullptr)
        {}

        Node(const U& value)
            : data(value), next(nullptr), prev(nullptr)
        {}
    };

    Node<T>* NIL;   ///< Centinela, conecta primer y último nodo.
    int count;      ///< Número de elementos en la lista.

public:
    SentinelLinkedList()
        : count(0)
    {
        NIL = new Node<T>();
        NIL->next = NIL;
        NIL->prev = NIL;
    }

    ~SentinelLinkedList()
    {
        // Eliminar todos los nodos
        Node<T>* current = NIL->next;
        while (current != NIL) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        delete NIL;
    }

    int GetCount() const { return count; }
    bool IsEmpty() const { return count == 0; }

    // Inserciones y eliminaciones
    void PushBack(const T& value);
    void PushFront(const T& value);
    T PopBack();
    T PopFront();

    // Operaciones de acceso
    T Front() const;
    T Back() const;

    // Métodos de búsqueda
    Node<T>* FindNode(const T& value) const;

    // Eliminación por valor
    void Remove(const T& value);

    // Contador de operaciones (opcional)
    int operationCounter;
};

// === Implementaciones ===

template<typename T>
void SentinelLinkedList<T>::PushBack(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = NIL;
    newNode->prev = NIL->prev;
    NIL->prev->next = newNode;
    NIL->prev = newNode;
    ++count;
}

template<typename T>
void SentinelLinkedList<T>::PushFront(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->prev = NIL;
    newNode->next = NIL->next;
    NIL->next->prev = newNode;
    NIL->next = newNode;
    ++count;
}

template<typename T>
T SentinelLinkedList<T>::PopBack()
{
    if (count == 0) {
        cout << "Warning: PopBack on empty list.\n";
        return T();
    }
    Node<T>* last = NIL->prev;
    T value = last->data;
    NIL->prev = last->prev;
    last->prev->next = NIL;
    delete last;
    --count;
    return value;
}

template<typename T>
T SentinelLinkedList<T>::PopFront()
{
    if (count == 0) {
        cout << "Warning: PopFront on empty list.\n";
        return T();
    }
    Node<T>* first = NIL->next;
    T value = first->data;
    NIL->next = first->next;
    first->next->prev = NIL;
    delete first;
    --count;
    return value;
}

template<typename T>
T SentinelLinkedList<T>::Front() const
{
    if (count == 0) {
        cout << "Warning: Front on empty list.\n";
        return T();
    }
    return NIL->next->data;
}

template<typename T>
T SentinelLinkedList<T>::Back() const
{
    if (count == 0) {
        cout << "Warning: Back on empty list.\n";
        return T();
    }
    return NIL->prev->data;
}

template<typename T>
typename SentinelLinkedList<T>::template Node<T>* SentinelLinkedList<T>::FindNode(const T& value) const
{
    Node<T>* current = NIL->next;
    while (current != NIL) {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return nullptr;
}

template<typename T>
void SentinelLinkedList<T>::Remove(const T& value)
{
    Node<T>* toDelete = FindNode(value);
    if (toDelete == nullptr)
        return;
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    delete toDelete;
    --count;
}
