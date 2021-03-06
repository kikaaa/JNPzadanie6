#ifndef MONSTER_H
#define MONSTER_H

#include "helper.h"
#include <algorithm>
#include <memory>
#include <vector>

class Monster : public Attacker {
public:
    Monster(HealthPoints health, AttackPower attack_power, std::string name);

    HealthPoints getHealth() const;
    void takeDamage(HealthPoints damage);
    const std::string& getName() const;

private:
    HealthPoints _health;
    std::string _name;
};

class Mummy : Monster {
public:
    Mummy(HealthPoints health, AttackPower attack_power);

    const std::string& getName() const;

private:
    const std::string _name;
};

class Vampire : Monster {
public:
    Vampire(HealthPoints health, AttackPower attack_power);

    const std::string& getName() const;

private:
    const std::string _name;
};

class Zombie : Monster {
public:
    Zombie(HealthPoints health, AttackPower attack_power);

    const std::string& getName() const;

private:
    const std::string _name;
};

class GroupOfMonsters {
public:
    GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters);
    GroupOfMonsters(const std::vector<std::shared_ptr<Monster>>& monsters);
    GroupOfMonsters(std::vector<std::shared_ptr<Monster>>&& monsters);

    HealthPoints getHealth() const;
    AttackPower getAttackPower() const;
    void takeDamage(AttackPower damage);
    const std::string& getName() const;

private:
    const std::vector<std::shared_ptr<Monster>> _monsters;
    const std::string _name;
};

std::shared_ptr<Mummy>
        createMummy(HealthPoints healthPoints, AttackPower attack_power);

std::shared_ptr<Vampire>
        createVampire(HealthPoints healthPoints, AttackPower attack_power);

std::shared_ptr<Zombie>
        createZombie(HealthPoints healthPoints, AttackPower attack_power);

std::shared_ptr<GroupOfMonsters>
        createGroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters);

std::shared_ptr<GroupOfMonsters>
        createGroupOfMonsters(const std::vector<std::shared_ptr<Monster>>& monsters);

std::shared_ptr<GroupOfMonsters>
        createGroupOfMonsters(std::vector<std::shared_ptr<Monster>>&& monsters);

#endif // MONSTER_H