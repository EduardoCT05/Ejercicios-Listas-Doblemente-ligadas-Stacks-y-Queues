#pragma once
#include <forward_list>
#include <stdexcept>

template<typename T>
class LStack {
private:
    std::forward_list<T> data;
    int                  count = 0;

public:
    LStack() = default;

    void Push(const T& value) {
        data.push_front(value);
        ++count;
    }

    T Pop() {
        if (count == 0)
            throw std::out_of_range("Pop en pila vacía");
        T val = data.front();
        data.pop_front();
        --count;
        return val;
    }

    T Peak() const {
        if (count == 0)
            throw std::out_of_range("Peak en pila vacía");
        return data.front();
    }

    int Count() const {
        return count;
    }

    bool IsEmpty() const {
        return count == 0;
    }
};
