#include "factorial.ipp"

template <typename T>
T comb(factorial<T>& fact, int entire, int part) {
    return fact.f(entire) / (fact.f(entire - part) * fact.f(part));
}
