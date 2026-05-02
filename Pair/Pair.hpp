#ifndef PAIR_PAIR_H
#define PAIR_PAIR_H


template <typename P, typename K> class Pair {
    P first;
    K second;
public:
    Pair();
    Pair(const P& p, const K& k);
    void set(const P& p, const K& k);
    P& getFirst();
    K& getSecond();
    bool operator ==(const Pair<P, K>& p) const;
    bool operator !=(const Pair<P, K>& p) const;
};

template<typename P, typename K>
Pair<P, K>::Pair() = default;

template<typename P, typename K>
Pair<P, K>::Pair(const P& p, const K& k) : first(p), second(k) {}

template<typename P, typename K>
void Pair<P, K>::set(const P &p, const K &k) {
    first = p;
    second = k;
}

template<typename P, typename K>
P & Pair<P, K>::getFirst() {
    return first;
}

template<typename P, typename K>
K & Pair<P, K>::getSecond() {
    return second;
}

template<typename P, typename K>
bool Pair<P, K>::operator==(const Pair<P, K>& p) const {
    return first == p.first && second == p.second;
}

template<typename P, typename K>
bool Pair<P, K>::operator!=(const Pair<P, K>& p) const {
    return first != p.first || second != p.second;
}

#endif //PAIR_PAIR_H
