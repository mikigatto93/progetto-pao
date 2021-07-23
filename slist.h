#ifndef SLIST_H
#define SLIST_H


template <typename T>
class SList {
    friend class Nodo;
private:
    class Nodo {
    public:
        T info;
        Nodo* next;
        Nodo(const T&, Nodo* next = nullptr);
    };

    Nodo *head, *tail;
    unsigned int count;
    static void deep_destroy(Nodo*);
    static void deep_copy(Nodo*, Nodo*&, Nodo*&);
    Nodo* getNodeAt(unsigned int) const;


public:

    SList();
    SList(const T&, unsigned int);
    SList(const SList&);
    ~SList();

    T getHead() const;
    T getTail() const;
    T pushFront(const T&);
    T pushBack(const T&);

    bool popFront();
    bool popBack();
    bool Remove(const T&);
    bool RemoveAt(unsigned int);
    bool insertAt(const T&, unsigned int);
    bool Swap(unsigned int, unsigned int);


    bool isEmpty() const;
    unsigned int Size() const;
    bool Search(const T&) const;
    const T& get(unsigned int) const;

    bool operator==(const SList&) const;
    bool operator!=(const SList&) const;
    SList<T> operator=(const SList&);

    class iterator {
        friend class SList<T>;
    private:
        Nodo* punt;
        bool past_the_end;
        iterator(Nodo*, bool pte = false);
    public:
        iterator();
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        iterator& operator++();
        iterator operator++(int);
        T* operator->() const;
        T& operator*() const;

    };

    class const_iterator {
        friend class SList<T>;
    private:
        const Nodo* punt;
        bool past_the_end;
        const_iterator(Nodo*, bool pte = false);
    public:
        const_iterator();
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const T* operator->() const;
        const T& operator*() const;
    };

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

};

template <typename T>
typename SList<T>::Nodo* SList<T>::getNodeAt(unsigned int i) const {
    if (isEmpty() || i >= count) return nullptr;
    unsigned int j = 0;
    Nodo* temp = head;
    while(j != i) {
        temp = temp->next;
        j++;
    }

    return temp;
}

template <typename T>
void SList<T>::deep_destroy(SList<T>::Nodo* n) {
    if (n != nullptr) {
        deep_destroy(n->next);
        delete n;
    }
}

template<typename T>
void SList<T>::deep_copy(SList<T>::Nodo* n, SList<T>::Nodo*& head, SList<T>::Nodo*& tail) {
    if (n == nullptr)
        head = tail = nullptr;
    else {
        head = new SList<T>::Nodo(n->info);
        Nodo* succ = n->next;
        tail = head;
        Nodo* temp = head;
        while (succ != nullptr) {
            temp->next = new Nodo(succ->info);
            temp = temp->next;
            tail = succ;
            succ = succ->next;
        }

    }
}

template <typename T>
SList<T>::Nodo::Nodo(const T& e, SList<T>::Nodo* _next): info(e), next(_next) {}

template <typename T>
SList<T>::SList(): head(nullptr), tail(nullptr), count(0) {}

template <typename T>
SList<T>::SList(const T& e, unsigned int _count): head(nullptr), tail(nullptr), count(_count) {

    for(int i = 0; i < _count; i++) {
        pushFront(e);
    }
    count = _count; // resetto perchè pushFront incrementa anche count
}

template <typename T>
SList<T>::SList(const SList& sl) {
    deep_copy(sl.head, head, tail);
    count = sl.count;
}

template <typename T>
SList<T>::~SList() {
    deep_destroy(head);
}

template <typename T>
T SList<T>::getHead() const {
    return head->info;
}

template <typename T>
T SList<T>::getTail() const {
    return tail->info;
}

template <typename T>
T SList<T>::pushFront(const T& e) {
    if (isEmpty()) {
        tail = head = new Nodo(e);
    } else {
        head = new Nodo(e, head);
    }
    count++;
    return e;
}

template <typename T>
T SList<T>::pushBack(const T& e) {
    if (isEmpty()) {
        tail = head = new Nodo(e);
    } else {
        tail->next = new Nodo(e);
        tail = tail->next;
    }
    count++;
    return e;
}

template <typename T>
bool SList<T>::insertAt(const T& e, unsigned int i) {
    if (i < count) {

        if (i == 0) {
            return pushFront(e);
        } else if (i == count - 1) {
            return pushBack(e);
        }

        unsigned int j = 0;
        Nodo* temp = head;
        Nodo* prev = nullptr;
        while (j != i) {
            prev = temp;
            temp = temp->next;
            j++;
        }
        prev->next = new Nodo(e, temp);
        count++;
        return true;
    } else
        return false;
}

template <typename T>
bool SList<T>::Remove(const T& e) {
    if (!isEmpty()) {

        if (e == head->info) {
            if (count == 1) {
                delete head;
                tail = head = nullptr;
                count--;
                return true;
            } else {
                //count > 1
                Nodo* temp = head;
                delete head;
                head = temp->next;
                count--;
                return true;
            }

        } else {

            Nodo* temp = head;
            Nodo* prev = nullptr;
            while (temp != nullptr && temp->info != e) {
                prev = temp;
                temp = temp->next;
            }

            if (temp->next == nullptr)
                return false;
            else {
                Nodo* succ = temp->next;
                delete temp;
                prev->next = succ;
                if (succ == nullptr)
                    tail = prev;
                count--;
                return true;
            }
        }
    }
}

template <typename T>
bool SList<T>::RemoveAt(unsigned int i) {
    if (count > i) {

        if (i == 0) {
            return popFront();
        } else if (i == count - 1) {
            return popBack();
        }

        unsigned int j = 0;
        Nodo* temp = head;
        Nodo* prev = nullptr;
        while (j != i) {
            prev = temp;
            temp = temp->next;
            j++;
        }
        Nodo* succ = temp->next;
        delete temp;
        prev->next = succ;
        count--;
        return true;
    } else
        return false;


}

template <typename T>
bool SList<T>::popFront() {
    if (!isEmpty()) {
        Nodo* temp = head->next;
        delete head;
        head = temp;
        if (count == 1)
            tail = nullptr;
        count--;
        return true;

    } else
        return false;
}

template <typename T>
bool SList<T>::popBack() {
    if (!isEmpty()) {

        if (count == 1) {
            delete tail;
            tail = head = nullptr;
            count--;
            return true;
        } else {

            Nodo* temp = head;
            Nodo* prev = nullptr;
            while(temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = nullptr;
            tail = prev;
            count--;
            return true;
        }

    } else
        return false;
}

template <typename T>
bool SList<T>::Swap(unsigned int i, unsigned int j) {
    if (i < count && j < count) {
        T dato = getNodeAt(i)->info;
        getNodeAt(i)->info = getNodeAt(j)->info;
        getNodeAt(j)->info = dato;
        return true;
    }
    return false;
}

template <typename T>
bool SList<T>::isEmpty() const {
    return (count == 0);
}

template <typename T>
unsigned int SList<T>::Size() const {
    return count;
}

template <typename T>
bool SList<T>::Search(const T& e) const {
    Nodo* temp = head;
    while(temp != nullptr) {
        if(temp->info != e)
            return true;
        temp = temp->next;
    }
    return false;
}

template<typename T>
SList<T> SList<T>::operator=(const SList& sl) {
    if (this != &sl) {
        deep_destroy(head);
        deep_copy(sl.head, head, tail);
        count = sl.count;
    }
    return *this;
}

template<typename T>
const T& SList<T>::get(unsigned int i) const {
    return getNodeAt(i)->info;
}

template <typename T>
bool SList<T>::operator==(const SList& sl) const {
    if (sl.count == count) {
        for (int i = 0; i < count; i++) {
            if (sl.getNodeAt(i)->info != getNodeAt(i)->info)
                return false;
        }
        return true;

    } else
        return false;

}

template <typename T>
bool SList<T>::operator!=(const SList& sl) const {
    return !(this->operator==(sl));
}



template <typename T>
SList<T>::iterator::iterator(Nodo* x, bool pte): punt(x), past_the_end(pte) {}

template <typename T>
SList<T>::iterator::iterator(): punt(nullptr), past_the_end(false) {}

template <typename T>
bool SList<T>::iterator::operator==(const iterator& it) const {
    return punt == it.punt;
}

template <typename T>
bool SList<T>::iterator::operator!=(const iterator& it) const {
    return punt != it.punt;
}

template <typename T> //prefisso
typename SList<T>::iterator& SList<T>::iterator::operator++() {
    if (punt!= nullptr) {
        if (!past_the_end) {
            if (punt->next != nullptr)
                punt = punt->next;
            else {
                punt = nullptr;
                past_the_end = true;
            }
        }
    }
    return *this;
}

template <typename T> //postfisso
typename SList<T>::iterator SList<T>::iterator::operator++(int) {
    iterator aux(*this);
    if (punt != nullptr) {
        if (!past_the_end) {
            if (punt->next != nullptr)
                punt = punt->next;
            else {
                punt = nullptr;
                past_the_end = true;
            }
        }
    }
    return aux;
}

template <typename T>
T* SList<T>::iterator::operator->() const {
    return &(punt->info);
}

template <typename T>
T& SList<T>::iterator::operator*() const {
    return punt->info;
}



template <typename T>
SList<T>::const_iterator::const_iterator(Nodo* x, bool pte): punt(x), past_the_end(pte) {}

template <typename T>
SList<T>::const_iterator::const_iterator(): punt(nullptr), past_the_end(false) {}

template <typename T>
bool SList<T>::const_iterator::operator==(const const_iterator& it) const {
    return punt == it.punt;
}

template <typename T>
bool SList<T>::const_iterator::operator!=(const const_iterator& it) const {
    return punt != it.punt;
}

template <typename T> //prefisso
typename SList<T>::const_iterator& SList<T>::const_iterator::operator++() {
    if (punt != nullptr) {
        if (!past_the_end) {
            if (punt->next != nullptr)
                punt = punt->next;
            else {
                punt = nullptr;
                past_the_end = true;
            }
        }
    }
    return *this;
}

template <typename T> //postfisso
typename SList<T>::const_iterator SList<T>::const_iterator::operator++(int) {
    const_iterator aux(*this);
    if (punt != nullptr) {
        if (!past_the_end) {
            if (punt->next != nullptr)
                punt = punt->next;
            else {
                punt = nullptr;
                past_the_end = true;
            }
        }
    }
    return aux;
}

template <typename T>
const T* SList<T>::const_iterator::operator->() const {
    return &(punt->info);
}

template <typename T>
const T& SList<T>::const_iterator::operator*() const {
    return punt->info;
}

template <typename T>
typename SList<T>::iterator SList<T>::begin() {
    return iterator(head);
}

template <typename T>
typename SList<T>::iterator SList<T>::end() {
    return iterator(nullptr, true);
}

template <typename T>
typename SList<T>::const_iterator SList<T>::begin() const {
    return const_iterator(head);
}

template <typename T>
typename SList<T>::const_iterator SList<T>::end() const {
    return const_iterator(nullptr, true);
}


#endif // SLIST_H
