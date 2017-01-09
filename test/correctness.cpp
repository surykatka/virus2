#define BOOST_TEST_MODULE Correctness
#include <boost/test/unit_test.hpp>

#include "../citizen.h"
#include "../monster.h"
#include "../smalltown.h"

#include <iostream>
#include <string>
#include <vector>

BOOST_AUTO_TEST_CASE(monster_attack_power_assigns_values)
{
  Zombie z(3, 4);
  BOOST_CHECK_EQUAL(z.getHealth().getPoints(), HealthPoints(3).getPoints());
  BOOST_CHECK_EQUAL(z.getAttackPower().getPoints(), AttackPower(4).getPoints());
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
