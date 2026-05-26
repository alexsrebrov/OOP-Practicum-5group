#include "StickerRepository.h"

Sticker* StickerRepository::findByNum(unsigned num) const
{
    for (auto& item : data)
    {
        if (*item == num)
        {
            return item.get();
        }
    }
    return nullptr;
}

void StickerRepository::trade(unsigned num, std::unique_ptr<Sticker> sticker)
{
    updateWhere([num](const Sticker& sticker) { return sticker == num; }, std::move(sticker));
}