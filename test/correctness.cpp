#define BOOST_TEST_MODULE Correctness
#include <boost/test/unit_test.hpp>

#include "../citizen.h"
#include "../monster.h"
#include "../smalltown.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

BOOST_AUTO_TEST_CASE(test_z_tresci)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(90, 1),
      createZombie(20, 1),
      createVampire(30, 1)
  });
  auto smallTown = SmallTown::Builder()
      .monster(groupOfMonsters)
      .startTime(3)
      .maxTime(27)
      .citizen(createSheriff(100, 35, 20))
      .citizen(createAdult(100, 21))
      .citizen(createTeenager(50, 14))
      .build();

  smallTown.tick(18);
  smallTown.tick(3);

  auto status = smallTown.getStatus();
  BOOST_CHECK_EQUAL(status.getMonsterName() ,"GroupOfMonsters");
  BOOST_CHECK_EQUAL(status.getMonsterHealth() ,80);
  BOOST_CHECK_EQUAL(status.getAliveCitizens() , 3);
}

BOOST_AUTO_TEST_CASE(group_of_monsters_get_health)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(90, 1),
      createZombie(20, 1),
      createVampire(30, 1)
  });
  BOOST_CHECK_EQUAL(groupOfMonsters.getHealth().getPoints(), 140);
}

BOOST_AUTO_TEST_CASE(group_of_monsters_get_attach)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(90, 1),
      createZombie(20, 1),
      createVampire(30, 1)
  });
  BOOST_CHECK_EQUAL(groupOfMonsters.getAttackPower().getPoints(), 3);
}

BOOST_AUTO_TEST_CASE(monster_attack_power_assigns_values)
{
  Zombie z(3, 4);
  BOOST_CHECK_EQUAL(z.getHealth().getPoints(), HealthPoints(3).getPoints());
  BOOST_CHECK_EQUAL(z.getAttackPower().getPoints(), AttackPower(4).getPoints());
}

BOOST_AUTO_TEST_CASE(adult_does_not_allow_age_below_18)
{
  BOOST_CHECK_THROW(
    Adult(HealthPoints(42), Age(17)),
    exception
  );
}

BOOST_AUTO_TEST_CASE(adult_does_not_allow_age_over_100)
{
  BOOST_CHECK_THROW(
    Adult(HealthPoints(42), Age(101)),
    exception
  );
}

BOOST_AUTO_TEST_CASE(teemager_does_not_allow_age_below_11)
{
  BOOST_CHECK_THROW(
    Teenager(HealthPoints(42), Age(10)),
    exception
  );
}

BOOST_AUTO_TEST_CASE(teemager_does_not_allow_age_over_17)
{
  BOOST_CHECK_THROW(
    Teenager(HealthPoints(42), Age(18)),
    exception
  );
}

BOOST_AUTO_TEST_CASE(get_age_returns_age)
{
  Adult a(HealthPoints(13), Age(19));
  BOOST_CHECK_EQUAL(a.getAge().getPoints(), Age(19).getPoints());
}

BOOST_AUTO_TEST_CASE(adult_take_damage_takes_hitpoints)
{
  Adult a(HealthPoints(13), Age(19));
  a.takeDamage(AttackPower(3));
  BOOST_CHECK_EQUAL(a.getHealth().getPoints(), HealthPoints(10).getPoints());
}

BOOST_AUTO_TEST_CASE(after_take_damage_health_is_nonnegative)
{
  Adult a(HealthPoints(13), Age(19));
  a.takeDamage(AttackPower(30));
  BOOST_CHECK_EQUAL(a.getHealth().getPoints(), HealthPoints(0).getPoints());
}

BOOST_AUTO_TEST_CASE(negative_attack_throws)
{
  BOOST_CHECK_THROW(AttackPower(-1), exception);
}

BOOST_AUTO_TEST_CASE(monster_name_is_correct_for_group)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(90, 1),
      createZombie(20, 1),
      createVampire(30, 1)
  });
  auto smalltown = SmallTown::Builder()
    .monster(groupOfMonsters).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getMonsterName(), "GroupOfMonsters");
}

BOOST_AUTO_TEST_CASE(monster_name_is_correct_for_mummy)
{
  auto mummy = createMummy(90, 1);
  auto smalltown = SmallTown::Builder()
    .monster(mummy).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getMonsterName(), "Mummy");
}

BOOST_AUTO_TEST_CASE(alive_citizens_is_0_when_no_added)
{
  auto mummy = createMummy(90, 1);
  auto smalltown = SmallTown::Builder()
    .monster(mummy).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getAliveCitizens(), 0);
}

BOOST_AUTO_TEST_CASE(alive_citizens_returns_correct_value_for_1_citizen)
{
  auto mummy = createMummy(90, 1);
  auto cit = createAdult(20, 23);
  auto smalltown = SmallTown::Builder().citizen(cit).monster(mummy).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getAliveCitizens(), 1);
}

BOOST_AUTO_TEST_CASE(smalltown_check_for_adding_same_citizens)
{
  auto cit = createAdult(20, 23);
  auto mummy = createMummy(90, 1);
  auto smalltown = SmallTown::Builder()
    .monster(mummy)
    .citizen(cit).citizen(cit).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getAliveCitizens(), 1);
}

BOOST_AUTO_TEST_CASE(smalltown_get_monster_health_returns_correctly)
{
  auto mummy = createMummy(90, 1);
  auto smalltown = SmallTown::Builder()
    .monster(mummy).build();
  BOOST_CHECK_EQUAL(smalltown.getStatus().getMonsterHealth(), 90);
}

BOOST_AUTO_TEST_CASE(get_attack_is_correct_for_group)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(1, 10),
      createZombie(2, 20),
      createVampire(3, 30)
  });

  BOOST_CHECK_EQUAL(groupOfMonsters.getAttackPower().getPoints(), 60);
}

BOOST_AUTO_TEST_CASE(get_health_is_correct_for_group)
{
  auto groupOfMonsters = createGroupOfMonsters({
      createMummy(1, 10),
      createZombie(2, 20),
      createVampire(3, 30)
  });

  BOOST_CHECK_EQUAL(groupOfMonsters.getHealth().getPoints(), 6);
}
