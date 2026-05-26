#include <string>

class Sticker
{
private:
    static unsigned counter;
    unsigned number;
    std::string name;

public:
    Sticker(std::string& name);
    virtual void printInfo() const;

    virtual ~Sticker() = default;

    bool operator==(unsigned num) const;
};