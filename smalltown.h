#ifndef _SMALLTOWN_H_
#define _SMALLTOWN_H_

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include "monster.h"
#include "citizen.h"
#include "helper.h"

/* Przerzucić gdzieś indziej */

using MonsterPtr = std::shared_ptr<Monster>;
using CitizenPtr = std::shared_ptr<Citizen>;

class AttackTimeStrategy {
public:
    virtual bool isAttackTime(Time t) const = 0;
};

class DefaultStrategy : public AttackTimeStrategy {
    bool isAttackTime(Time t) const override;
};

class Status {
private:
    std::string _monsterName;
    HealthPoints _monsterHP;
    size_t _citizensAlive;
public:
    Status(std::string monsterName, HealthPoints monsterHP,
           size_t citizensAlive);

    const std::string & getMonsterName() const;
    HealthPoints getMonsterHP() const;
    size_t getCitizensAlive() const;
};

class SmallTown {
private:
    MonsterPtr _monster;
    std::vector<CitizenPtr> _citizens;
    Time _time, _maxTime;
    AttackTimeStrategy* _strategy;
    size_t _citizensAlive;
    void performAttack();
public:
    SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
              Time t0, Time t1);

    SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
              Time t0, Time t1, AttackTimeStrategy* strategy);

    Status getStatus() const;

    void tick(Time timeStep);

    class Builder {
    private:
        MonsterPtr _monster;
        std::vector<CitizenPtr> _citizens;
        Time _t0, _t1;
    public:
        Builder();

        Builder & monster(MonsterPtr monster);
        Builder & citizen(CitizenPtr citizen);
        Builder & startTime(Time t0);
        Builder & maxTime(Time t1);

        SmallTown build();
    };
};

#endif // SMALLTOWN_H
