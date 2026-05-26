#include "Repository.hpp"
#include "Sticker.h"


class StickerRepository : public Repository<Sticker>
{
public:
    Sticker* findByNum(unsigned num) const;
    void trade(unsigned num, std::unique_ptr<Sticker> sticker);
};