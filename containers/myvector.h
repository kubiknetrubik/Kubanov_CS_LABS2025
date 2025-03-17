#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 5;

template<class T>
class MyVector {
 protected:
    int max_size;
    int size;
    T* pdata;
    void resize() {
        max_size *= 2;
        T* new_pdata = new T[max_size];
        for (int i = 0; i < size; ++i) {
            new_pdata[i] = pdata[i];
        }

        delete[] pdata;
        pdata = new_pdata;
    }

 public:
    MyVector(T el = NULL, int maxsize = MAX_SIZE) : max_size(maxsize), size(0) {
        pdata = new T[max_size];
        if (el) {
            add_element(el);
        }
    };

    MyVector(const MyVector& v);
    ~MyVector();
    void add_element(T el);
    bool delete_element(int i);
    const T& operator[](int i) const;
    void sort();
    int find(T el);

    MyVector<T>& operator=(const MyVector<T>& v);

    friend std::ostream& operator<<(std::ostream& out, MyVector<T>& v) {
        for (int i = 0; i < v.size; ++i) {
            out << v[i] << ' ';
        }
        out << '\n';
        return out;
    }
};

template <class T>
MyVector<T>::MyVector(const MyVector& v) {
    max_size = v.max_size;
    size = v.size;
    pdata = new T[max_size];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
}

template <class T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}
template <>
MyVector<char*>::~MyVector() {
    for(int i=0;i<size;++i){
        delete[] pdata[i];
    }
    delete[] pdata;
}

template <class T>
void MyVector<T>::add_element(T el) {
    if (size >= max_size) {
        resize();
    }
    pdata[size] = el;
    ++size;
}

template <>
void MyVector<char*>::add_element(char* el) {
    if (size >= max_size) {
        resize();
    }
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    ++size;
}

template <class T>
bool MyVector<T>::delete_element(int i) {
    if (size == 0 || i < 0 || i >= size) {
        return false;
    }
    for (int j = i; j < size; ++j) {
        pdata[j] = pdata[j + 1];
    }
    --size;
    if(size<max_size/4){
        max_size= max_size/2;
    }
    return true;
}

template <>
bool MyVector<char*>::delete_element(int i) {
    if (size == 0 || i < 0 || i >= size) {
        return false;
    }
    delete[] pdata[i];
    for (int j = i; j < size; ++j) {
        delete[] pdata[j];
        pdata[j] =new char[strlen(pdata[j+1]) + 1];
        strcpy(pdata[j], pdata[j+1]);
    }

    --size;
    if(size<max_size/4){
        max_size= max_size/2;
    }
    return true;
}

template <class T>
const T& MyVector<T>::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw std::invalid_argument("Индекс не валидный.");
    }
    return pdata[i];
}
template <class T>
void MyVector<T>::sort() {
    if (!pdata) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pdata[j] > pdata[j + 1]) {
                std::swap(pdata[j], pdata[j + 1]);

            }
        }
    }
}
template <>
void MyVector<char*>::sort() {
    if (!pdata) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(pdata[j + 1],pdata[j]) > 0) {
                std::swap(pdata[j], pdata[j + 1]);

            }
        }
    }
}

template <class T>
int MyVector<T>::find(T el) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (pdata[mid] == el)
            return mid;
        else if (pdata[mid] < el)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template <>
int MyVector<char*>::find(char* el) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (!strcmp(pdata[mid],el)){
            return mid;
        }else if (strcmp(pdata[mid], el)>0){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}


template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
    delete[] pdata;

    this->max_size = v.max_size;
    this->size = v.size;
    this->pdata = new T[max_size];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = v.pdata[i];
    }
    return *this;
}

template <>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& v) {
    delete[] pdata;

    this->max_size = v.max_size;
    this->size = v.size;
    this->pdata = new char*[max_size];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = v.pdata[i];
    }
    return *this;
}
#endif  // INHERITANCE_MYVECTOR_H
