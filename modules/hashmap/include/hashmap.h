// Copyright 2020 Isaev Ilya

#include <initializer_list>
#include <functional>
#include <utility>

template<typename Key=int, typename Value=int>
class hashmap {
    using value_type = std::pair<Key, Value>;
    public:
        explicit hashmap() = default;
        hashmap(const int& max_size);
        hashmap(std::initializer_list<value_type> init);
        ~hashmap() {delete[] _buffer;}
        int max_size() {return _max_size;}
        void insert(const Key& key, const Value& value);
        Value& operator[](const Key& key);
    private:
        int hash(const Key& key) {return std::hash<Key>()(key) % _max_size;}
        int _max_size;
        value_type** _buffer;
};

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(const int& max_size):_max_size(max_size) {
    _buffer = new value_type*[max_size];
    for (int i = 0; i < max_size; ++i) {
        _buffer[i] = nullptr;
    }
}

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(std::initializer_list<value_type> init) {
    _max_size = init.size()*2;
    _buffer = new value_type*[_max_size];
    for (auto&& i: init) {
        auto hashIndex = hash(i.first);
        _buffer[hashIndex] = new value_type(i.first, i.second);
    }
}

template <typename Key, typename Value>
Value& hashmap<Key, Value>::operator[](const Key& key) {
    return _buffer[hash(key)]->second;
}

template <typename Key, typename Value>
void hashmap<Key, Value>::insert(const Key& key, const Value& value) {
    _buffer[hash(key)] = new value_type(key, value);
}