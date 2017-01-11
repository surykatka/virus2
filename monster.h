#ifndef MONSTER_H
#define MONSTER_H

#include "citizen.h"
#include <vector>
#include <string>

class IMonster
{
public:
  virtual HealthPoints getHealth() const = 0;
  virtual AttackPower getAttackPower() const = 0;
  virtual void takeDamage(AttackPower damage) = 0;
  virtual std::string getName() = 0;
};

class Monster : public IMonster  {
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

    std::string getName() {
      return "Monster";
    }
};

class Zombie : public Monster{
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

class GroupOfMonsters : public IMonster {
	private:
		std::vector<Monster> monster_list;
	public:
	GroupOfMonsters(std::vector<Monster> _monster_list) {
		this->monster_list = _monster_list;
	}

	 HealthPoints getHealth() const {
        int totalHp = 0;
        for(auto monster : monster_list) {
          totalHp += monster.getHealth().getPoints();
        }
        return HealthPoints(totalHp);
    }

    AttackPower getAttackPower() const {
      int totalAttackPower = 0;
      for(auto monster : monster_list) {
        totalAttackPower += monster.getAttackPower().getPoints();
      }
      return AttackPower(totalAttackPower);
    }

    void takeDamage(AttackPower damage) {

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
