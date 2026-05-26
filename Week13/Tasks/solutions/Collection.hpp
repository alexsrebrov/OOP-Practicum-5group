#pragma once

template <typename T>
class Stream;

template <typename T>
class Collection {
public:
    virtual ~Collection() = default;

    virtual Stream<T> stream() = 0;
};