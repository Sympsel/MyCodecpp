#ifndef P3_27_STACK_H
#define P3_27_STACK_H

#include "iostream"
#include "exception"

using namespace std;

typedef int ElementType;

class Stack {
public:
    explicit Stack(int size = 10) {
        top_ = -1;
        size_ = size;
        data_ = new ElementType[size_];
    }

    ~Stack() { delete[] data_; }

    void push(ElementType e) {
        if (top_ >= size_ - 1) {
            size_ = size_ + size_ / 2;
            resize(size_);
        }
        data_[++top_] = e;
    }

    ElementType pop() {
        if (isEmpty())throw runtime_error("isEmpty: Stack is empty");
        return data_[top_--];
    }

    void show() const {
        for (int i = 0; i < top_ + 1; ++i) {
            cout << data_[i] << " ";
        }
    }

    [[nodiscard]] bool isEmpty() const { return top_ == -1; }

    [[nodiscard]] int getSize() const { return size_; }

    [[nodiscard]] int getTop() const { return top_; }

private:
    int top_{};
    int size_;
    ElementType *data_;

    void resize(int newSize) {
        auto *newData = new ElementType[newSize];
        for (int i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        size_ = newSize;
    }
};
//   ++
//  [===]
//   -+-
//    |

#endif //P3_27_STACK_H
