// this tells catch to provide a main()
// only do this in one cpp file
#include "../externals/catch2/catch.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "load.h"

//*************constructor, getters ********************
TEST_CASE(
    "Default constructor sets total volume to 0, total weight to 0, and "
    "count to 0",
    "[load],[start]") {
  Load load;

  CHECK(load.count() == 0);
  CHECK(load.total_volume() == 0);
  CHECK(load.total_weight() == 0);
}

//*********** other methods **************************
//*******FillLoad, DisplayNextDelivery,ItemDelivered,NotDeliverable  **********
//******* HowManyDelivered, HowManyNotDelivered **************************
TEST_CASE(
    "FillLoad creates shipping items and accumulates count, total weight, and "
    "total volume. ItemDelivered sets delivered to true and increments count. "
    "NotDeliverable increments count. HowManyDelivered and HowManyNotDelivered "
    "count items with delivered set to true and false respectively.",
    "[load],[fill_load]") {
  Load load;
  load.FillLoad("../tests/load_test.txt");

  CHECK(fabs(load.count() - 6) < .001);
  CHECK(fabs(load.total_volume() - 16601.372442) < .1);
  CHECK(fabs(load.total_weight() - 103.58) < .001);

  std::ofstream out("../tests/output.txt");
  load.DisplayNextDelivery(out);
  CHECK(load.HowManyDelivered() == 0);
  CHECK(load.HowManyNotDelivered() == 6);
  load.ItemDelivered();
  CHECK(load.HowManyDelivered() == 1);
  CHECK(load.HowManyNotDelivered() == 5);
  load.DisplayNextDelivery(out);
  load.NotDeliverable();
  CHECK(load.HowManyDelivered() == 1);
  CHECK(load.HowManyNotDelivered() == 5);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  CHECK(load.HowManyDelivered() == 2);
  CHECK(load.HowManyNotDelivered() == 4);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  CHECK(load.HowManyDelivered() == 3);
  CHECK(load.HowManyNotDelivered() == 3);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  CHECK(load.HowManyDelivered() == 4);
  CHECK(load.HowManyNotDelivered() == 2);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  CHECK(load.HowManyDelivered() == 5);
  CHECK(load.HowManyNotDelivered() == 1);

  out.close();

  std::ifstream in("../tests/output.txt");
  std::string line;

  std::getline(in, line);
  CHECK(line == "Renee Javens");
  std::getline(in, line);
  CHECK(line == "281 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Carton: 42.0 lbs. 24.0 x 18.0 x 18.0");
  std::getline(in, line);
  CHECK(line == "Rose Harrison");
  std::getline(in, line);
  CHECK(line == "302 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Flat: 0.7 lbs. 12.0 x 9.0 x 0.3");
  std::getline(in, line);
  CHECK(line == "Jeff Allen");
  std::getline(in, line);
  CHECK(line == "162 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Tube: 4.7 lbs. 19.0 x 6.3");
  std::getline(in, line);
  CHECK(line == "Cathy Setzer");
  std::getline(in, line);
  CHECK(line == "320 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Flat: 2.4 lbs. 14.0 x 8.0 x 0.5");
  std::getline(in, line);
  CHECK(line == "Gordon Pike");
  std::getline(in, line);
  CHECK(line == "328 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Carton: 51.0 lbs. 32.5 x 16.2 x 16.2");
  std::getline(in, line);
  CHECK(line == "Jeff Allison");
  std::getline(in, line);
  CHECK(line == "172 South Main");
  std::getline(in, line);
  CHECK(line == "Ogden, UT 84408");
  std::getline(in, line);
  CHECK(line == "Tube: 2.8 lbs. 28.0 x 8.2");
}