#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include <string>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include <iostream>

class Status {
//TODO
	public:
		std::string getMonsterName() {
			//TODO
			return "";
		}

		int getMonsterHealth() {
			//TODO
			return -1;
		}
		
		int getAliveCitizens() {
			//TODO
			return -1;
		}

};

class SmallTown {
	private:
		std::vector<Citizen> citizens;
		std::vector<Monster> monsters;
		int t1;
		int t2;
	public:
		void tick(int timestep) {
			//TODO
		}

		Status getStatus() {
			//TODO
			return Status();
		}

		SmallTown(std::vector<Citizen> _citizens, std::vector<Monster> _monsters,
			int _t1, int _t2) {
		}
	class Builder {
		private:
			std::vector<Citizen> citizens;
			std::vector<Monster> monsters;
			int t1;
			int t2;
		public:
			Builder monster(Monster _monster) {
				//TODO - dodaj monster do listy
				return *this;
			}

			Builder monster(GroupOfMonsters _monsters) {
				//TODO - dodaj monsters do listy
				return *this;
			}

			Builder citizen(Citizen _citizen) {
				//TODO - dodaj monster do listy
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
				return SmallTown(citizens, monsters, t1, t2);
			}
	};

};

#endif //SMALLTOWN_H
