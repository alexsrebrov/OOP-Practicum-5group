#include "GameHouse.h"

#include <print>

void GameHouse::showGameHistory() const {
    for (auto& game: games) {
        std::print("Winner: {}, id: {}, game type: ", game.getWinnerName(), game.getWinnerId());
        if (game.getType() == Type::Poker) {
            std::println("poker");
        }
        else if (game.getType() == Type::Blackjack) {
            std::println("blackjack");
        }
        else {
            std::println("slots");
        }
    }
}

void GameHouse::showPlayers() const {
    for (const auto& player: players) {
        std::println("Name: {}, money: {}, aura: {}, id: {}, luck: {}, nonchalant skill: {}",
            player -> getName(), player -> getMoney(), player -> getAura(),
            player -> getID(), player -> getLuck(), player -> getNonchalantSkill());
    }
}

void GameHouse::play(const Game& game) {
    if (game.getType() == Type::Poker) {
        int maxAura = 0;
        for (const auto& player: players) {
            if (player -> getAura() > maxAura) {
                maxAura = player -> getAura();
            }
        }
        double allBets = 0;
        for (auto&[first, second]: game.getPlayers()) {
            allBets += second;
            first.subtractMoney(second);
            second = 0;
        }
        for (const auto& player: players) {
            if (player -> getAura() == maxAura) {
                player -> addMoney(0.8 * allBets);
                break;
            }
        }
        this -> profits.push_back(0.2 * allBets);
        std::erase_if(players, [](const std::shared_ptr<Player>& p) {
            return p -> getMoney() < 0;
        });
    }
    else if (game.getType() == Type::Blackjack) {
        int maxNonchalantSkill = 0;
        for (const auto& player: players) {
            if (player -> getNonchalantSkill() > maxNonchalantSkill) {
                maxNonchalantSkill = player -> getNonchalantSkill();
            }
        }
        double allBets = 0;
        for (auto&[first, second]: game.getPlayers()) {
            allBets += second;
            first.subtractMoney(second);
            second = 0;
        }
        for (const auto& player: players) {
            if (player -> getNonchalantSkill() == maxNonchalantSkill) {
                player -> addMoney(0.7 * allBets);
                break;
            }
        }
        this -> profits.push_back(0.3 * allBets);
        std::erase_if(players, [](const std::shared_ptr<Player>& p) {
            return p -> getMoney() < 0;
        });
    }
    else {
        int maxLuck = 0;
        for (const auto& player: players) {
            if (player -> getLuck() > maxLuck) {
                maxLuck = player -> getLuck();
            }
        }
        double allBets = 0;
        for (auto&[first, second]: game.getPlayers()) {
            allBets += second;
            first.subtractMoney(second);
            second = 0;
        }
        for (const auto& player: players) {
            if (player -> getLuck() == maxLuck) {
                player -> addMoney(0.65 * allBets);
                break;
            }
        }
        this -> profits.push_back(0.35 * allBets);
        std::erase_if(players, [](const std::shared_ptr<Player>& p) {
            return p -> getMoney() < 0;
        });
    }
    games.emplace_back(game);
}