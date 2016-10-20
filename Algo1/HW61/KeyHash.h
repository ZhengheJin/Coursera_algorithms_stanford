// Default hash function class
template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return <unsigned long>(key) % TABLE_SIZE;
    }
};
