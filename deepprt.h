#ifndef DEEPPRT_H
#define DEEPPRT_H
//richiede che il metodo clone() sia implementato
template <typename T>
class DeepPtr {
private:
    T* ptr;
public:
    DeepPtr(T* = nullptr);
    DeepPtr(const DeepPtr&);
    ~DeepPtr();

    DeepPtr& operator=(const DeepPtr&);
    bool operator==(const DeepPtr&);
    bool operator!=(const DeepPtr&);

    T* operator->() const;
    T& operator*() const;
    T* get() const;

};

template <typename T>
DeepPtr<T>::DeepPtr(T* p) {
    ptr = p->clone();
}

template <typename T>
DeepPtr<T>::DeepPtr(const DeepPtr& dp) {
    ptr = dp.ptr->clone();
}

template <typename T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <typename T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& dp) {
    if (this != &dp) {
        delete ptr;
        ptr = dp.ptr->clone();
    }
    return *this;
}
template <typename T>
bool DeepPtr<T>::operator==(const DeepPtr<T>& dp) {
    return *(dp.ptr) == *ptr;
}

template <typename T>
bool DeepPtr<T>::operator!=(const DeepPtr<T>& dp) {
    return *(dp.ptr) != *ptr;
}

template <typename T>
T* DeepPtr<T>::operator->() const {
    return ptr;
}

template <typename T>
T& DeepPtr<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* DeepPtr<T>::get() const {
    return ptr;
}


#endif // DEEPPRT_H
