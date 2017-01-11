#ifndef CITIZEN_H
#define CITIZEN_H

#include <cassert>
#include <stdexcept>
#include "monster.h"

class Citizen {
private:
  Age age;
  HealthPoints health;

protected:
public:
  Citizen(HealthPoints _health, Age _age) {
    this->age = _age;
    this->health = _health;
  }
  HealthPoints getHealth() const { return health; }

  Age getAge() const { return age; }

  void takeDamage(AttackPower damage) { this->health.takePoints(damage); }

	void attackMonster(IMonster& monster) {	}

  bool isAlive() { return age.getPoints() > 0; }
};

class Adult : public Citizen {
  bool isAgeValid(Age _age) {
    auto points = _age.getPoints();
    return (18 <= points && points <= 100);
  }

public:
  Adult(HealthPoints health, Age age) : Citizen(health, age) {
    if (!isAgeValid(age)) {
      throw std::invalid_argument("invalid age");
    }
  }
};

class Teenager : public Citizen {
  bool isAgeValid(Age _age) {
    auto points = _age.getPoints();
    return (11 <= points && points <= 17);
  }

public:
  Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    if (!isAgeValid(age)) {
      throw std::invalid_argument("invalid age");
    }
  }
};

class Sheriff: public Citizen {
public:
private:
  AttackPower attackPower;

public:
  Sheriff(HealthPoints health, Age age, AttackPower attackPower)
      : Citizen(health, age), attackPower(attackPower) {
  }
  AttackPower getAttackPower() const { return attackPower; }

	void attackMonster(IMonster& monster) {
		monster.takeDamage(attackPower);
	}
};

Sheriff createSheriff(int health, int age, int attack) {
  return Sheriff(HealthPoints(health), Age(age), AttackPower(attack));
}

Teenager createTeenager(int health, int age) {
  return Teenager(HealthPoints(health), Age(age));
}

Adult createAdult(int health, int age) {
  return Adult(HealthPoints(health), Age(age));
}

#endif // CITIZEN_H
