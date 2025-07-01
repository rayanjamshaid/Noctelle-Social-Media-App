#pragma once
template<class T>
class C_Array
{
private:
    int size;
    T* arr;
protected:
public:
    C_Array();
    C_Array(const C_Array& other);
    C_Array& operator=(const C_Array& other);
    C_Array(int _size);
    ~C_Array();
    void push(T obj);
    void pop();
    T& operator[](int index);
    void del(int index);
    int getlength();
};

template<class T>
inline C_Array<T>::C_Array() : size(0), arr(nullptr)
{
}

template<class T>
inline C_Array<T>::C_Array(const C_Array& other)
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

template<class T>
inline C_Array<T>& C_Array<T>::operator=(const C_Array& other)
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

template<class T>
inline C_Array<T>::C_Array(int _size)
{
    this->size = _size;
    if (this->size > 0) {
        this->arr = new T[size];
    }
    else {
        this->arr = nullptr;
    }
}

template<class T>
inline C_Array<T>::~C_Array()
{
    delete[] arr;
}

template<class T>
inline void C_Array<T>::push(T obj)
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

template<class T>
inline void C_Array<T>::pop()
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

template<class T>
inline T& C_Array<T>::operator[](int index)
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

template<class T>
inline void C_Array<T>::del(int index)
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

template<class T>
inline int C_Array<T>::getlength()
{
    return this->size;
}