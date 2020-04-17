// Copyright 2020 Isaev Ilya

#include <initializer_list>
#include <functional>
#include <utility>

template<typename Key, typename Value>
class hashnode {
    public:
        Key key;
        Value value;
        hashnode* next;

        hashnode(const Key& _key, const Value& _value): key(_key), value(_value), next(nullptr){}
};

template<typename Key=int, typename Value=int>
class hashmap {
    using value_type = hashnode<Key, Value>;
    public:
        explicit hashmap() = default;
        hashmap(const int& max_size);
        hashmap(std::initializer_list<value_type> init);
        ~hashmap() {delete[] _buffer;}
        int max_size() {return _max_size;}
        int size() {return _size;}
        void insert(const Key& key, const Value& value);
        Value operator[](const Key& key);
    private:
        int hash(const Key& key) {return std::hash<Key>()(key) % _max_size;}
        int _max_size;
        int _size;
        value_type** _buffer;
};

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(const int& max_size):_max_size(max_size), _size(0) {
    _buffer = new value_type*[max_size];
    for (int i = 0; i < max_size; ++i) {
        _buffer[i] = nullptr;
    }
}

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(std::initializer_list<value_type> init) {
    _max_size = init.size()*2;
    _size = 0;
    _buffer = new value_type*[_max_size];
    for (auto&& i: init) {
        this->insert(i.key, i.value);
    }
}

template <typename Key, typename Value>
Value hashmap<Key, Value>::operator[](const Key& key) {
    auto hashindex = hash(key);
    auto entry = _buffer[hashindex];

    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next; 
    }
    return Value();
}

template <typename Key, typename Value>
void hashmap<Key, Value>::insert(const Key& key, const Value& value) {
    auto hashindex = hash(key);
    auto next = _buffer[hashindex];
    value_type* prev = nullptr;

    while (next != nullptr && next->key != key) {
        prev = next;
        next = next->next;
    }

    if (next == nullptr) {
        next = new value_type(key, value);
        if (prev == nullptr) {
            _buffer[hashindex] = next;
        } else {
            prev->next = next;
        }
    } else {
        next->value = value;
    }
    
    _size++;
}