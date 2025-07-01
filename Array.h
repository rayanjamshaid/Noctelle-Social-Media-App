#pragma once
template<typename T>
class Array
{
private:
    int size;
    T* arr;
protected:
public:
    Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(int _size);
    ~Array();
    void push(T obj);
    void pop();
    T& operator[](int index);
    void del(int index);
    int getlength();
};

template<typename T>
inline Array<T>::Array() : size(0), arr(nullptr)
{
}

template<typename T>
inline Array<T>::Array(const Array& other)
{
    this->size = other.size;
    if (this->size > 0) {
        this->arr = new T[this->size];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    else {
        this->arr = nullptr;
    }
}

template<typename T>
inline Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] this->arr;
        this->size = other.size;
        if (this->size > 0) {
            this->arr = new T[this->size];
            for (int i = 0; i < size; i++)
            {
                this->arr[i] = other.arr[i];
            }
        }
        else {
            this->arr = nullptr;
        }
    }
    return *this;
}

template<typename T>
inline Array<T>::Array(int _size)
{
    this->size = _size;
    if (this->size > 0) {
        this->arr = new T[size];
    }
    else {
        this->arr = nullptr;
    }
}

template<typename T>
inline Array<T>::~Array()
{
    delete[] arr;
}

template<typename T>
inline void Array<T>::push(T obj)
{
    T* temp = new T[this->size + 1];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = this->arr[i];
    }
    temp[this->size] = obj;
    this->size++;
    delete[] this->arr;
    this->arr = temp;
}

template<typename T>
inline void Array<T>::pop()
{
    if (this->size > 0) {
        T* temp = new T[this->size - 1];
        for (int i = 0; i < this->size - 1; i++)
        {
            temp[i] = this->arr[i];
        }
        this->size--;
        delete[] this->arr;
        this->arr = temp;
    }
}

template<typename T>
inline T& Array<T>::operator[](int index)
{
    if (index >= 0 && index < this->size)
    {
        return this->arr[index];
    }
    // Need to handle out of bounds access properly
    // For now, return the first element as a fallback
    // A better approach would be to throw an exception or use assertions
    return this->arr[0];
}

template<typename T>
inline void Array<T>::del(int index)
{
    if (index >= 0 && index < size)
    {
        T* temp = new T[size - 1];
        for (int i = 0, j = 0; i < size; i++)
        {
            if (i == index)
            {
                continue;
            }
            temp[j++] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = temp;
        size--;
    }
}

template<typename T>
inline int Array<T>::getlength()
{
    return this->size;
}