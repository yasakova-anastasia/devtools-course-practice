// Copyright 2020 Isaev Ilya

#include <initializer_list>
#include <utility>

template<typename Key=int, typename Value=int>
class hashmap {
    using value_type = std::pair<Key, Value>;
    public:
        explicit hashmap() = default;
        hashmap(const int& max_size);
        hashmap(std::initializer_list<value_type> init);
        int max_size() {return _max_size;}
    private:
        int _max_size;
};

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(const int& max_size):_max_size(max_size) {

}

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(std::initializer_list<value_type> init) {

}