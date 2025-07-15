#pragma once
#include "LinkedList.h"

template<typename T>
class LQueue {
private:
    LinkedList<T> data;

public:
    LQueue() = default;

    int GetCount() const {
        return data.GetCount();
    }

    void Enqueue(const T& value) {
        data.PushBack(value);
    }

    T Dequeue() {
        return data.PopFront();
    }

    T& Front() {
        return data.Front();
    }

    bool IsEmpty() const {
        return data.IsEmpty();
    }
};
