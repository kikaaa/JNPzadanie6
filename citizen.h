#ifndef CITIZEN_H
#define CITIZEN_H

#include "citizen.h"
#include "helper.h"
#include <algorithm>
#include <memory>
#include <type_traits>

const Age MIN_ADULT_AGE = 18;
const Age MAX_ADULT_AGE = 100;
const Age MIN_TEENAGER_AGE = 11;
const Age MAX_TEENAGER_AGE = 17;

class Citizen {
private:
    Age _age;
    HealthPoints _health;
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Sheriff : public Citizen, Attacker {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attack_power);

    void fightBack(Attacker& who_attacked);
};

std::shared_ptr<Adult>
        createAdult(HealthPoints healthPoints, Age age);

std::shared_ptr<Teenager>
        createTeenager(HealthPoints healthPoints, Age age);

std::shared_ptr<Sheriff>
        createSheriff(HealthPoints healthPoints, Age age);

#endif // CITIZEN_H
