#ifndef CITIZEN_H
#define CITIZEN_H

class AttackPower {
	private: 
		int attackPower;
	public:
		AttackPower() {
			this->attackPower = 0;
		}
		AttackPower(int _attackPower) {
			this->attackPower = _attackPower;
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
	// nie będę się upierać przy poniższej implementacji :p
	int takePoints(HealthPoints loss) {
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
};

class Citizen {
private:
	Age age;
	HealthPoints health;
public:
	Citizen(int _health, int _age) {
        //TODO tu asercja o wiek?
        this->age = Age(_age);
        this->health = HealthPoints(_health);
    }
    HealthPoints getHealth() const {
        return health;
    }

    Age getAge() const {
        return age;
    }
    
    void takeDamage(HealthPoints damage) {
		this->health.takePoints(damage);
	}
};

class Adult : public Citizen {
public:
	Adult(int health, int age) : Citizen(health, age) {
    }
};

class Teenager : public Citizen {
public:
	Teenager(int health, int age) : Citizen(health, age) {
    }
};

class Sheriff : public Citizen {
private:
	AttackPower attackPower;
public:
	Sheriff(int health, int age, int _attackPower) : Citizen(health, age) {
		this->attackPower = AttackPower(_attackPower);
    }
	AttackPower getAttackPower() const {
        return attackPower;
    }
};

#endif //CITIZEN_H
