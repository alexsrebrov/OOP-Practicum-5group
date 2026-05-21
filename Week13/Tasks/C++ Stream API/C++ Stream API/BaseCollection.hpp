#pragma once
template <typename T> class Stream;

template <typename T>
class BaseCollection
{
protected:

public:

	virtual ~BaseCollection() = default;
	virtual Stream<T> stream() = 0;
};

