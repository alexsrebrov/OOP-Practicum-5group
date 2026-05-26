#include <functional>
#include <memory>
#include <vector>

template <typename T>
class Repository
{
protected:
    std::vector<std::unique_ptr<T>> data;

public:
    Repository() = default;
    virtual ~Repository() = default;

    void add(std::unique_ptr<T> obj);
    bool removeAt(size_t idx);
    bool update(size_t index, std::unique_ptr<T> item);

    size_t size() const;
    void clear();
    bool isEmpty() const;

    void addAll(std::vector<std::unique_ptr<T>> objects);
    bool contains(std::function<bool(const T&)> pred) const;
    std::vector<const T*> findAll(std::function<bool(const T&)> pred) const;
    bool remove(std::function<bool(const T&)> pred);

    bool updateWhere(std::function<bool(const T&)> pred, std::unique_ptr<T> obj);
};

template <typename T>
void Repository<T>::add(std::unique_ptr<T> obj)
{
    data.push_back(std::move(obj));
}

template <typename T>
bool Repository<T>::removeAt(size_t idx)
{
    if (idx >= data.size())
    {
        return false;
    }
    data.erase(data.begin() + idx);
    return true;
}

template <typename T>
bool Repository<T>::update(size_t index, std::unique_ptr<T> item)
{
    if (index >= data.size())
    {
        return false;
    }

    data[index] = std::move(item);
    return true;
}

template <typename T>
size_t Repository<T>::size() const
{
    return data.size();
}

template <typename T>
bool Repository<T>::isEmpty() const
{
    return data.empty();
}

template <typename T>
void Repository<T>::clear()
{
    data.clear();
}

template <typename T>
void Repository<T>::addAll(std::vector<std::unique_ptr<T>> objects)
{
    for (auto& item : objects)
    {
        data.push_back(std::move(item));
    }
}

template <typename T>
bool Repository<T>::contains(std::function<bool(const T&)> pred) const
{
    for (const auto& item : data)
    {
        if (pred(*item))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
std::vector<const T*> Repository<T>::findAll(std::function<bool(const T&)> pred) const
{
    std::vector<const T*> result;
    for (const auto& item : data)
    {
        if (pred(*item))
        {
            result.push_back(item.get());
        }
    }
    return result;
}

template <typename T>
bool Repository<T>::remove(std::function<bool(const T&)> pred)
{
    size_t removed = std::erase_if(
        data, [&](const std::unique_ptr<T>& ptr) { return pred(*ptr); });

    return removed > 0;
}

template <typename T>
bool Repository<T>::updateWhere(std::function<bool(const T&)> pred, std::unique_ptr<T> obj)
{
    bool hasUpdated = false;
    for (auto& item : data)
    {
        if (pred(*item))
        {
            item = obj;
            hasUpdated = true;
            break;
        }
    }
    return hasUpdated;
}