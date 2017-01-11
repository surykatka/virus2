#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include <string>
#include <tuple>
#include <exception>
#include <iostream>
#include "citizen.h"
#include "monster.h"

class Status {
	std::string monsterName;
	int monsterHealth;
	int aliveCitizens = 0;

	public:
		Status(IMonster &monster, std::vector<Citizen> &citizens) {
			monsterName = monster.getName();
			monsterHealth = monster.getHealth().getPoints();
			for(auto citizen : citizens) {
				if(citizen.isAlive())
					aliveCitizens++;
			}
		}

		std::string getMonsterName() {
			return monsterName;
		}

		int getMonsterHealth() {
			return monsterHealth;
		}

		int getAliveCitizens() {
			return aliveCitizens;
		}

};

class SmallTown {
	private:
		std::vector<Citizen> citizens;
		IMonster& monster;
		int t1;
		int t2;
	public:
		void tick(int timestep) {
			//TODO
		}

		Status getStatus() {
			return Status(monster, citizens);
		}

		SmallTown(std::vector<Citizen> _citizens, IMonster& _monster,
			int _t1, int _t2) : citizens(_citizens) , monster(_monster) {}

	class Builder {
		private:
			std::vector<Citizen> citizens;
			IMonster* monsters;
			int t1;
			int t2;
		public:
			Builder(){}

			Builder monster(IMonster& _monster) {
				monsters = &_monster;
				return *this;
			}

			Builder citizen(Citizen _citizen) {
				citizens.push_back(_citizen);
				return *this;
			}

			Builder startTime(int _t1) {
				this->t1 = _t1;
				return *this;
			}

			Builder maxTime(int _t2) {
				this->t2 = _t2;
				return *this;
			}

			SmallTown build() {
				if(monsters == NULL)
					throw std::invalid_argument
					  ( "monster must be set before building smalltown" );
				return SmallTown(citizens, *monsters, t1, t2);
			}
	};

};

#endif //SMALLTOWN_H
