#ifndef PASSIVESYSTEM_H
#define PASSIVESYSTEM_H

#include <string>
#include <sstream>
#include <vector>

// Define triggers for passives
enum class PassiveTrigger {
    NONE,
    ON_WIN_ROCK,
    ON_WIN_PAPER,
    ON_WIN_SCISSORS,
    ON_LOSE_ROCK,
    ON_LOSE_PAPER,
    ON_LOSE_SCISSORS,
    ON_TIE,
    ON_HP_BELOW_PERCENT,
    ON_TURN_START,
    AFTER_ANY_ATTACK,
    AFTER_TAKING_HIT
};

// Define effects of passives
enum class PassiveEffect {
    NONE,
    HEAL_SELF_FLAT,
    DAMAGE_OPPONENT_FLAT,
    INCREASE_NEXT_ATTACK_FLAT,
    INCREASE_ROCK_DMG_PERM,
    INCREASE_PAPER_DMG_PERM,
    INCREASE_SCISSORS_DMG_PERM,
    HEAL_SELF_PERCENT_CURRENT,
    DAMAGE_OPPONENT_PERCENT_CURRENT
};

// Structure to hold passive details
struct Passive {
    PassiveTrigger trigger = PassiveTrigger::NONE;
    PassiveEffect effect = PassiveEffect::NONE;
    int value = 0;
    int threshold = 0;
    bool triggeredThisTurn = false;

    Passive() = default;

    Passive(PassiveTrigger t, PassiveEffect e, int v, int th = 0)
        : trigger(t), effect(e), value(v), threshold(th), triggeredThisTurn(false) {
    }

    std::string toString() const;
    static Passive fromString(const std::string& s);
    std::string getDescription() const;
};

#endif // PASSIVESYSTEM_H