#ifndef CITIZEN_H
#define CITIZEN_H

#include <cassert>
#include <stdexcept>

class AttackPower {
	private:
		int attackPower;
	public:
		AttackPower() {
			this->attackPower = 0;
		}
		AttackPower(int _attackPower) {
			if(_attackPower < 0) {
				throw std::invalid_argument( "attack power cannot be negative" );
			}
			this->attackPower = _attackPower;
		}

		int getPoints() {
			return this->attackPower;
		}
};

class HealthPoints {
private:
	int healthPoints;
public:
	HealthPoints() {
	}
	HealthPoints(int healthPoints) {
		this->healthPoints = healthPoints;
	}

	int takePoints(AttackPower loss) {
		if (this->healthPoints > 0) {
			this->healthPoints = this->healthPoints - loss.getPoints() < 1
				? 0 : this->healthPoints - loss.getPoints();
		}
		return this->healthPoints;
	}

	int getPoints() {
		return this->healthPoints;
	}
};

class Age {
private:
	int age;
public:
	Age() {
		this->age = 0;
	}
	Age(int age) {
		this->age = age;
	}
	bool operator <= (const Age &a1) {
		return (this->age <= a1.age);
	}
	int getPoints() {
		return this->age;
	}
};

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
    HealthPoints getHealth() const {
        return health;
    }

    Age getAge() const {
        return age;
    }

    void takeDamage(AttackPower damage) {
			this->health.takePoints(damage);
		}

		bool isAlive() {
			return age.getPoints() > 0;
		}
};

class Adult : public Citizen {
	bool isAgeValid(Age _age) {
		auto points = _age.getPoints();
		return ( 18 <= points && points <= 100 );
	}
public:
	Adult(HealthPoints health, Age age) : Citizen(health, age) {
		if( !isAgeValid(age)) {
			throw std::invalid_argument( "invalid age" );}
	}
};

class Teenager : public Citizen {
	bool isAgeValid(Age _age) {
		auto points = _age.getPoints();
		return ( 11 <= points && points <= 17 );
	}
public:
	Teenager(HealthPoints health, Age age) : Citizen(health, age) {
		if( !isAgeValid(age)) {
	 		throw std::invalid_argument( "invalid age" );}
		}
};

class Sheriff : public Citizen {
private:
	AttackPower attackPower;
public:
	Sheriff(HealthPoints health, Age age, AttackPower _attackPower) : Citizen(health, age) {
		this->attackPower = _attackPower;
    }
	AttackPower getAttackPower() const {
        return attackPower;
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

#endif //CITIZEN_H
