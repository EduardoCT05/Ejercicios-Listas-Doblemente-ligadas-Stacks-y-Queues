#pragma once
#include <stdexcept>

template<typename T>
class SentinelLinkedList {
private:
    struct Node {
        T      data;
        Node*  next;
        Node(const T& d = T(), Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* sentinel;    // nodo centinela (no guarda dato útil)
    Node* tail;        // apunta al último nodo real
    int   count;       // número de elementos almacenados

public:
    // Constructor: crea solo el centinela, tail apunta a él, count = 0
    SentinelLinkedList()
        : sentinel(new Node()), tail(sentinel), count(0) {}

    // Destructor: borra todos los nodos reales y luego el centinela
    ~SentinelLinkedList() {
        while (!IsEmpty())
            PopFront();
        delete sentinel;
    }

    // Inserta al final (push back)
    void PushBack(const T& value) {
        Node* node = new Node(value);
        tail->next = node;
        tail = node;
        ++count;
    }

    // Elimina y retorna el último (pop back)
    T PopBack() {
        if (IsEmpty()) throw std::out_of_range("List is empty");
        Node* prev = sentinel;
        while (prev->next != tail)
            prev = prev->next;
        Node* del = tail;
        T     val = del->data;
        tail = prev;
        tail->next = nullptr;
        delete del;
        --count;
        return val;
    }

    // Inserta al frente (push front)
    void PushFront(const T& value) {
        Node* node = new Node(value, sentinel->next);
        sentinel->next = node;
        if (tail == sentinel)
            tail = node;
        ++count;
    }

    // Elimina y retorna el primero (pop front)
    T PopFront() {
        if (IsEmpty()) throw std::out_of_range("List is empty");
        Node* node = sentinel->next;
        T     val  = node->data;
        sentinel->next = node->next;
        if (node == tail)
            tail = sentinel;
        delete node;
        --count;
        return val;
    }

    // Obtiene el dato del primer nodo sin eliminar
    T& Front() {
        if (IsEmpty()) throw std::out_of_range("List is empty");
        return sentinel->next->data;
    }

    // Obtiene el dato del último nodo sin eliminar
    T& Back() {
        if (IsEmpty()) throw std::out_of_range("List is empty");
        return tail->data;
    }

    // Devuelve el número de elementos
    int GetCount() const {
        return count;
    }

    // ¿Está vacía?
    bool IsEmpty() const {
        return count == 0;
    }

    // *** Funciones adicionales de utilidad ***

    // Vacía la lista (borra todos los nodos reales)
    void Clear() {
        while (!IsEmpty())
            PopFront();
    }

    // Recorre la lista y aplica un callback a cada elemento
    template<typename Func>
    void ForEach(Func fn) const {
        Node* cur = sentinel->next;
        while (cur) {
            fn(cur->data);
            cur = cur->next;
        }
    }

    // Busca el primer nodo cuyo dato compare igual, retorna true si lo elimina
    bool RemoveFirst(const T& value) {
        Node* prev = sentinel;
        Node* cur  = sentinel->next;
        while (cur) {
            if (cur->data == value) {
                prev->next = cur->next;
                if (cur == tail)
                    tail = prev;
                delete cur;
                --count;
                return true;
            }
            prev = cur;
            cur  = cur->next;
        }
        return false;
    }
};
