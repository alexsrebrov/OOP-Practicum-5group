#pragma once
#include <string>
#include <iostream>

enum class Rarity {
    Rare = 1,
    SuperRare,
    Epic,
    Mythic,
    Legendary
};

inline std::string rarityToString(Rarity r) {
    switch (r) {
    case Rarity::Rare:       return "Rare";
    case Rarity::SuperRare:  return "SuperRare";
    case Rarity::Epic:       return "Epic";
    case Rarity::Mythic:     return "Mythic";
    case Rarity::Legendary:  return "Legendary";
    }
    return "Unknown";
}

inline Rarity rarityFromString(const std::string& s) {
    if (s == "Rare")       return Rarity::Rare;
    if (s == "SuperRare")  return Rarity::SuperRare;
    if (s == "Epic")       return Rarity::Epic;
    if (s == "Mythic")     return Rarity::Mythic;
    if (s == "Legendary")  return Rarity::Legendary;
    throw std::invalid_argument("Unknown rarity: " + s);
}