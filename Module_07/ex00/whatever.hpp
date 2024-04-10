#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T> void swap(T &swap_1, T &swap_2) {
  swap_1 = swap_1 + swap_2;
  swap_2 = swap_1 - swap_2;
  swap_1 = swap_1 - swap_2;
}


template<typename T> const T min(const T& min_1, const T& min_2) {
    return (min_1 < min_2 ? min_1 : min_2);
}


template<typename T> const T max(const T& max_1, const T& max_2) {
    return (max_1 > max_2 ? max_1 : max_2);
}

#endif // WHATEVER_HPP
