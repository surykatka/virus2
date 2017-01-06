#ifndef MONSTER_H
#define MONSTER_H

#include "citizen.h"
#include <vector>

class Monster {
private:
    HealthPoints _health;
    AttackPower _attackPower;
public:
    Monster(HealthPoints health, AttackPower attackPower) : _health(health),
                                       _attackPower(attackPower) { }

    HealthPoints getHealth() const {
        return _health;
    }

    AttackPower getAttackPower() const {
        return _attackPower;
    }

    void takeDamage(AttackPower damage) {
        this->_health.takePoints(damage);
    }
};

class Zombie : public Monster {
public:
	Zombie(int health, int age) : Monster(health, age) {
    }
};

class Mummy : public Monster {
public:
	Mummy(int health, int age) : Monster(health, age) {
    }
};

class Vampire : public Monster {
public:
	Vampire(int health, int age) : Monster(health, age) {
    }
};

class GroupOfMonsters {
	private:
		std::vector<Monster> monster_list;
		HealthPoints _health;
		AttackPower _attackPower;
	public:
	GroupOfMonsters(std::vector<Monster> _monster_list) {
		this->monster_list = _monster_list;
		//TODO sum health
		//TODO sum attack
	}
	
	 HealthPoints getHealth() const {
        return _health;
    }

    AttackPower getAttackPower() const {
        return _attackPower;
    }

    void takeDamage(AttackPower damage) {
        //TODO damage
    }
};

#endif //MONSTER_H
