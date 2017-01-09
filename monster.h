#ifndef MONSTER_H
#define MONSTER_H

#include "citizen.h"
#include <vector>
#include <string>

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

    std::string getName() {
		return "Zombie";
	}
};

class Mummy : public Monster {
public:
	Mummy(int health, int age) : Monster(health, age) {
    }

    std::string getName() {
		return "Mummy";
	}
};

class Vampire : public Monster {
public:
	Vampire(int health, int age) : Monster(health, age) {
    }

    std::string getName() {
		return "Vampire";
	}
};

class GroupOfMonsters {
	private:
		std::vector<Monster> monster_list;
		HealthPoints _health;
		AttackPower _attack_power;
	public:
	GroupOfMonsters(std::vector<Monster> _monster_list) {
		this->monster_list = _monster_list;
		int temp_attack = 0;
		int temp_health = 0;
		for (size_t i = 0; i < monster_list.size(); i++) {
			temp_attack += monster_list[i].getAttackPower().getPoints();
			temp_health += monster_list[i].getHealth().getPoints();
		}
		this->_attack_power = AttackPower(temp_attack);
		this->_health = HealthPoints(temp_health);
	}

	 HealthPoints getHealth() const {
        return _health;
    }

    AttackPower getAttackPower() const {
        return _attack_power;
    }

    void takeDamage(AttackPower damage) {
        for (size_t i = 0; i < monster_list.size(); i++) {
			monster_list[i].takeDamage(damage);
			// nie upieram sie przy ponizszej implementacji
			if (monster_list[i].getHealth().getPoints() == 0) {
				int temp_attack = this->getAttackPower().getPoints();
				temp_attack -= monster_list[i].getAttackPower().getPoints();
				this->_attack_power = AttackPower(temp_attack);
				int temp_health = this->getHealth().getPoints();
				temp_health -= monster_list[i].getHealth().getPoints();
				this->_health = HealthPoints(temp_health);
			}
		}
    }

     std::string getName() {
		return "GroupOfMonsters";
	}
};

Vampire createVampire(int health, int attack) {
	return Vampire(health, attack);
}

Mummy createMummy(int health, int attack) {
	return Mummy(health, attack);
}

Zombie createZombie(int health, int attack) {
	return Zombie(health, attack);
}

GroupOfMonsters createGroupOfMonsters(std::vector<Monster> monster_list) {
	return GroupOfMonsters(monster_list);
}

#endif //MONSTER_H
