// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <array>
#include <fstream>
#include <string>
#include "project.h"

// valid case
TEST_CASE("Project default constructor sets values expected", "[start]") {
  Project project;

  CHECK(project.name() == "unnamed");
  CHECK(project.estimated_time_minutes() == 60);
  CHECK(fabs(project.estimated_time_hours() - 60 / 60.0) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}
TEST_CASE("Project constructor using two arguments sets values expected",
          "[start]") {
  Project project("testing", 373);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 373 * 60);
  CHECK(fabs(project.estimated_time_hours() - 373) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using two arguments sets values expected when "
    "estimated minutes has digits after the decimal place that round up.",
    "[start]") {
  Project project("testing", 36.8);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 36.8 * 60);
  CHECK(fabs(project.estimated_time_hours() - 36.8) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using two arguments sets values expected when "
    "estimated minutes has digits after the decimal place that round down.",
    "[start]") {
  Project project("testing", 36.2);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 36.2 * 60);
  CHECK(fabs(project.estimated_time_hours() - 36.2) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}
TEST_CASE("Project constructor using three arguments sets values expected",
          "[start]") {
  Project project("testing spaces too", 390, 82);

  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using three arguments sets values expected "
    "actual minutes has digits after the decimal place that round up.",
    "[start]") {
  Project project("testing spaces too", 390, 82.9);

  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82.9 * 60);
  CHECK(fabs(project.actual_time_hours() - 82.9) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using three arguments sets values expected "
    "actual minutes has digits after the decimal place that round down.",
    "[start]") {
  Project project("testing spaces too", 390, 82.1);

  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82.1 * 60);
  CHECK(fabs(project.actual_time_hours() - 82.1) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE("Project constructor using four arguments sets values expected",
          "[start]") {
  Project project("testing", 390, 82, 12);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}
TEST_CASE(
    "Project constructor throws out_of_range exception when estimated "
    "time sent is a negative number",
    "[start]") {
  CHECK_THROWS_AS(Project("testing2", -2, 82, 12), std::out_of_range);
}

TEST_CASE(
    "Project constructor throws out_of_range exception when actual time sent "
    "is zero",
    "[start]") {
  CHECK_THROWS_AS(Project("testing2", 0, 8, 12), std::out_of_range);
}

TEST_CASE(
    "Project constructor throws out_of_range exception when actual time sent "
    "is negative",
    "[start]") {
  CHECK_THROWS_AS(Project("testing2", -2, 7, 12), std::out_of_range);
}

TEST_CASE(
    "Project constructor using small argument (.1) for estimated hours sets "
    "values expected",
    "[start]") {
  Project project("testing", .1);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == .1 * 60);
  CHECK(fabs(project.estimated_time_hours() - .1) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using small argument (.75) for estimated hours sets "
    "values expected",
    "[start]") {
  Project project("testing", .75);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == .75 * 60);
  CHECK(fabs(project.estimated_time_hours() - .75) < .0001);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(fabs(project.actual_time_hours() - 0) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using small argument (.6) for actual hours sets "
    "values expected",
    "[start]") {
  Project project("testing", 23, .6);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 23 * 60);
  CHECK(fabs(project.estimated_time_hours() - 23) < .0001);
  CHECK(project.actual_time_minutes() == 36);
  CHECK(fabs(project.actual_time_hours() - .6) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Project constructor using small argument (.2) for actual hours sets "
    "values expected",
    "[start]") {
  Project project("testing", 18, .2);

  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 18 * 60);
  CHECK(fabs(project.estimated_time_hours() - 18) < .0001);
  CHECK(project.actual_time_minutes() == 12);
  CHECK(fabs(project.actual_time_hours() - .2) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

/****************set_name */
TEST_CASE("The name setter changes the name as expected", "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_name("changed up name");
  CHECK(project.name() == "changed up name");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

/***************set_estimated_time_minutes */
TEST_CASE(
    "The estimated_time_minutes setter changes the estimated_time as expected "
    "when time is greater than 60 minutes",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_estimated_time_minutes(128);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 128);
  CHECK(fabs(project.estimated_time_hours() - 128 / 60.0) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "The estimated_time_minutes setter changes the estimated_time as expected "
    "when time is less than 60 minutes",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_estimated_time_minutes(45);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 45);
  CHECK(fabs(project.estimated_time_hours() - 45 / 60.0) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "Estimated_time_minutes setter throws out_of_range exception when "
    "estimated time sent is zero",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_estimated_time_minutes(0), std::out_of_range);
}

TEST_CASE(
    "Estimated_time_minutes setter throws out_of_range exception when "
    "estimated time sent is negative",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_estimated_time_minutes(-22), std::out_of_range);
}
/***************set_estimated_time_hours */

TEST_CASE(
    "The estimated_time_hours setter changes the estimated_time as expected "
    "when time is more than 1 hour",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_estimated_time_hours(6);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 6 * 60);
  CHECK(fabs(project.estimated_time_hours() - 6) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "The estimated_time_hours setter changes the estimated_time as expected "
    "when time is less than 1 hour",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_estimated_time_hours(.2);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == .2 * 60);
  CHECK(fabs(project.estimated_time_hours() - .2) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "The estimated_time_hours setter changes the estimated_time expected "
    "when actual hours has digits after the decimal place that round up.",
    "[start]") {
  Project project("testing spaces too", 390, 63.8);

  project.set_estimated_time_hours(2.6);
  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 2.6 * 60);
  CHECK(fabs(project.estimated_time_hours() - 2.6) < .0001);
  CHECK(project.actual_time_minutes() == 63.8 * 60);
  CHECK(fabs(project.actual_time_hours() - 63.8) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "The estimated_time_hours setter changes the estimated_time expected "
    "when actual hours has digits after the decimal place that round down.",
    "[start]") {
  Project project("testing spaces too", 390, 91.4);

  project.set_estimated_time_hours(2.4);
  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 2.4 * 60);
  CHECK(fabs(project.estimated_time_hours() - 2.4) < .0001);
  CHECK(project.actual_time_minutes() == 91.4 * 60);
  CHECK(fabs(project.actual_time_hours() - 91.4) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Estimated_time_hours setter throws out_of_range exception when "
    "estimated time sent is zero",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_estimated_time_minutes(0), std::out_of_range);
}

TEST_CASE(
    "  setter throws out_of_range exception when "
    "estimated time sent is negative",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_estimated_time_minutes(-22), std::out_of_range);
}

/***************set_estimated_time_minutes */
TEST_CASE(
    "set_actual_time_minutes changes the estimated_time as expected "
    "when time is greater than 60 minutes",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_actual_time_minutes(128);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 128);
  CHECK(fabs(project.actual_time_hours() - 128 / 60.0) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "set_actual_time_minutes changes the estimated_time as expected "
    "when time is less than 60 minutes",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_actual_time_minutes(45);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 45);
  CHECK(fabs(project.actual_time_hours() - .75) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "set_actual_time_minutes throws out_of_range exception when "
    "actual time sent is negative (-1)",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_actual_time_minutes(-1), std::out_of_range);
}

/***************set_actual_time_hours */

TEST_CASE(
    "The set_actual_time_hours changes the actual_time as expected "
    "when time is more than 1 hour",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_actual_time_hours(6);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 6 * 60);
  CHECK(fabs(project.actual_time_hours() - 6) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "The set_actual_time_hours changes the actual_time as expected "
    "when time is less than 1 hour",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_actual_time_hours(.2);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == .2 * 60);
  CHECK(fabs(project.actual_time_hours() - .2) < .0001);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "The set_actual_time_hours changes the actual_time  expected "
    "when actual hours has digits after the decimal place that round up.",
    "[start]") {
  Project project("testing spaces too", 390, 63.8);

  project.set_actual_time_hours(2.6);
  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 2.6 * 60);
  CHECK(fabs(project.actual_time_hours() - 2.6) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "The set_actual_time_hours changes the actual_time  expected "
    "when actual hours has digits after the decimal place that round down.",
    "[start]") {
  Project project("testing spaces too", 390, 91.4);

  project.set_actual_time_hours(2.4);
  CHECK(project.name() == "testing spaces too");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 2.4 * 60);
  CHECK(fabs(project.actual_time_hours() - 2.4) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "Set_actual_time_hours throws out_of_range exception when "
    "estimated time sent is less than zero (-1)",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_actual_time_hours(-1), std::out_of_range);
}

TEST_CASE(
    "Set_actual_time_hours throws out_of_range exception when "
    "estimated time sent is less than zero (-.1)",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_actual_time_hours(-.1), std::out_of_range);
}

/***************set_percent_complete */
TEST_CASE(
    "set_percent_complete changes the percent_complete as "
    "expected "
    "when percent is 18",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_percent_complete(18);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 18);
}

TEST_CASE(
    "set_percent_complete changes the percent_complete as expected "
    "when percent is .5",
    "[start]") {
  Project project("testing", 390, 82, 12);

  project.set_percent_complete(.5);
  CHECK(project.name() == "testing");
  CHECK(project.estimated_time_minutes() == 390 * 60);
  CHECK(fabs(project.estimated_time_hours() - 390) < .0001);
  CHECK(project.actual_time_minutes() == 82 * 60);
  CHECK(fabs(project.actual_time_hours() - 82) < .0001);
  CHECK(project.reported_percent_complete() == 0);
}

TEST_CASE(
    "set_percent_complete throws out_of_range exception when "
    "estimated time sent is zero",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_percent_complete(101), std::out_of_range);
}

TEST_CASE(
    "set_percent_complete throws out_of_range exception when "
    "estimated time sent is negative",
    "[start]") {
  Project project("testing2", 32, 7, 12);
  CHECK_THROWS_AS(project.set_percent_complete(-1), std::out_of_range);
}

/*******************RecordTimeSpentMinutes */

TEST_CASE(
    "RecordTimeSpentMinutes changes actual_time to 1161 and percent complete "
    "to 80 when 45 minutes and 80 percent are recorded",
    "[record_time]") {
  Project project("test", 22, 18.6);

  project.RecordTimeSpentMinutes(45, 80);
  CHECK(project.actual_time_minutes() == 1161);
  CHECK(project.reported_percent_complete() == 80);
}

TEST_CASE(
    "RecordTimeSpentMinutes changes actual_time to 218 and percent complete "
    "to 12 when 98 minutes and 12 percent are recorded",
    "[record_time]") {
  Project project("test", 22, 2);

  project.RecordTimeSpentMinutes(98, 12);
  CHECK(project.actual_time_minutes() == 218);
  CHECK(project.reported_percent_complete() == 12);
}

TEST_CASE(
    "RecordTimeSpentMinutes throws out_of_range exception when "
    "estimated time result is negative",
    "[record_time]") {
  Project project("testing2", 32, 1, 12);
  CHECK_THROWS_AS(project.RecordTimeSpentMinutes(-61, 15), std::out_of_range);
}

/*******************RecordTimeSpentHours */

TEST_CASE(
    "RecordTimeSpentHours changes actual_time to 600 and percent complete "
    "to 50 when 4 hours and 50 percent are recorded",
    "[record_time]") {
  Project project("test", 22, 6);

  project.RecordTimeSpentHours(4, 50);
  CHECK(project.actual_time_minutes() == 600);
  CHECK(project.reported_percent_complete() == 50);
}

TEST_CASE(
    "RecordTimeSpentHours changes actual_time to 210 and percent complete "
    "to 8 when 1.5 hours and 8 percent are recorded",
    "[record_time]") {
  Project project("test", 22, 2);

  project.RecordTimeSpentHours(1.5, 8);
  CHECK(project.actual_time_minutes() == 210);
  CHECK(project.reported_percent_complete() == 8);
}

TEST_CASE(
    "RecordTimeSpentHours changes actual_time to 270 and percent complete "
    "to 6 when .2 hours and 6 percent are recorded",
    "[record_time]") {
  Project project("test", 22, 3);

  project.RecordTimeSpentHours(1.5, 6);
  CHECK(project.actual_time_minutes() == 270);
  CHECK(project.reported_percent_complete() == 6);
}

TEST_CASE(
    "RecordTimeSpentHours throws out_of_range exception when "
    "estimated time result is negative",
    "[record_time]") {
  Project project("testing2", 32, 1, 12);
  CHECK_THROWS_AS(project.RecordTimeSpentMinutes(-1.1, 15),
                    std::out_of_range);
}

/*********************CalculatedPercentComplete */

TEST_CASE("CalculatedPercentComplete returns 75 when result is .75.",
          "[calculated_percent]") {
  Project project("testing2", 96, 72);
  CHECK(project.CalculatedPercentComplete() == 75);
}

TEST_CASE("CalculatedPercentComplete returns 75 when result is .83333.",
          "[calculated_percent]") {
  Project project("testing2", 12, 10);
  CHECK(project.CalculatedPercentComplete() == 83);
}

TEST_CASE("CalculatedPercentComplete returns 75 when result is .6153846.",
          "[calculated_percent]") {
  Project project("testing2", 91, 56);
  CHECK(project.CalculatedPercentComplete() == 62);
}

/*********************ConvertMinutesToString */

TEST_CASE("ConvertMinutesToString returns 2:15 when 135 is sent.",
          "[convert]") {
  Project project;

  CHECK(project.ConvertMinutesToString(135) == "2:15");
}

TEST_CASE("ConvertMinutesToString returns 3:08 when 188 is sent.",
          "[convert]") {
  Project project;

  CHECK(project.ConvertMinutesToString(188) == "3:08");
}

TEST_CASE("ConvertMinutesToString returns 412:16 when 24736 is sent.",
          "[convert]") {
  Project project;

  CHECK(project.ConvertMinutesToString(24736) == "412:16");
}

TEST_CASE("ConvertMinutesToString returns 0:51 when 51 is sent.", "[convert]") {
  Project project;

  CHECK(project.ConvertMinutesToString(51) == "0:51");
}

TEST_CASE("ConvertMinutesToString returns -12:54 when -774 is sent.",
          "[convert]") {
  Project project;

  CHECK(project.ConvertMinutesToString(-774) == "-12:54");
}

TEST_CASE("ConvertMinutesToString works when called without a declared object",
          "[convert]") {
  CHECK(Project::ConvertMinutesToString(188) == "3:08");
}

/**********************TimeLeftOnProject */
TEST_CASE("TimeLeftOnProject reports 32:18 when minutes left is 1944.",
          "[time_left]") {
  Project project("test", 33, .7);

  CHECK(project.estimated_time_minutes() == 33 * 60);
  CHECK(project.actual_time_minutes() == 42);
  CHECK(project.TimeLeftOnProject() == "32:18");
}

TEST_CASE("TimeLeftOnProject reports 0:24 when minutes left is 24.",
          "[time_left]") {
  Project project("test", 1, .6);

  CHECK(project.estimated_time_minutes() == 1 * 60);
  CHECK(project.actual_time_minutes() == 36);
  CHECK(project.TimeLeftOnProject() == "0:24");
}

TEST_CASE("TimeLeftOnProject reports 22:00 when minutes left is 1320.",
          "[time_left]") {
  Project project("test", 22);

  CHECK(project.estimated_time_minutes() == 22 * 60);
  CHECK(project.actual_time_minutes() == 0);
  CHECK(project.TimeLeftOnProject() == "22:00");
}

TEST_CASE(
    "TimeLeftOnProject reports -2:48 when actual time has exceeded expected "
    "time 160 minutes.",
    "[time_left]") {
  Project project("test", 22, 24.8);

  CHECK(project.estimated_time_minutes() == 22 * 60);
  CHECK(project.actual_time_minutes() == 24.8 * 60);
  CHECK(project.TimeLeftOnProject() == "-2:48");
}

/*********************WriteData */

TEST_CASE(
    "WriteData writes data as expected when name is Test Project, estimated "
    "minutes is 1320, actual minutes is 90, and reported percent complete is "
    "12.",
    "[write_data]") {
  Project project("Test Project", 22, 1.5, 12);

  std::ofstream out("test_out.txt");
  project.WriteData(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "1320 90 12");
  getline(in, line);
  CHECK(line == "Test Project");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when name is Fast Project, estimated "
    "minutes is 30, actual minutes is 15, and reported percent complete is 42."
    "12.",
    "[write_data]") {
  Project project("Fast Project", .5, .25, 42);

  std::ofstream out("test_out.txt");
  project.WriteData(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "30 15 42");
  getline(in, line);
  CHECK(line == "Fast Project");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when name is Over Project, estimated "
    "minutes is 360, actual minutes is 450, and reported percent complete is "
    "95.",
    "[write_data]") {
  Project project("Over Project", 6, 7.5, 95);

  std::ofstream out("test_out.txt");
  project.WriteData(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "360 450 95");
  getline(in, line);
  CHECK(line == "Over Project");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when data from three projects is "
    "written to the file.",
    "[write_data]") {
  Project project1("Test Project", 22, 1.5, 12);
  Project project2("Fast Project", .5, .25, 42);
  Project project3("Over Project", 6, 7.5, 95);

  std::ofstream out("test_out.txt");
  project1.WriteData(out);
  project2.WriteData(out);
  project3.WriteData(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "1320 90 12");
  getline(in, line);
  CHECK(line == "Test Project");

  getline(in, line);
  CHECK(line == "30 15 42");
  getline(in, line);
  CHECK(line == "Fast Project");

  getline(in, line);
  CHECK(line == "360 450 95");
  getline(in, line);
  CHECK(line == "Over Project");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

/*********************ProjectReport */

TEST_CASE(
    "ProjectReport reports is as expected when name is Test Project, estimated "
    "minutes is 1320, actual minutes is 90, and reported percent complete is "
    "12.",
    "[reports]") {
  Project project("Test Project", 22, 1.5, 12);

  CHECK(project.ConvertMinutesToString(1320) == "22:00");
  CHECK(project.ConvertMinutesToString(90) == "1:30");
  CHECK(project.CalculatedPercentComplete() == 7);
  CHECK(project.reported_percent_complete() == 12);

  std::ofstream out("test_out.txt");
  project.ProjectReport(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "Test Project");
  getline(in, line);
  CHECK(line == "Estimated time: 22:00");
  getline(in, line);
  CHECK(line == "Actual time spent: 1:30");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 7%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 12%");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "ProjectReport report is as expected when name is Fast Project, estimated "
    "minutes is 30, actual minutes is 15, and reported percent complete is 42.",
    "[reports]") {
  Project project("Fast Project", .5, .25, 42);

  CHECK(project.ConvertMinutesToString(30) == "0:30");
  CHECK(project.ConvertMinutesToString(15) == "0:15");
  CHECK(project.CalculatedPercentComplete() == 50);
  CHECK(project.reported_percent_complete() == 42);

  std::ofstream out("test_out.txt");
  project.ProjectReport(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "Fast Project");
  getline(in, line);
  CHECK(line == "Estimated time: 0:30");
  getline(in, line);
  CHECK(line == "Actual time spent: 0:15");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 50%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 42%");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "ProjectReport report is as expected when name is Over Project, estimated "
    "minutes is 360, actual minutes is 450, and reported percent complete is "
    "95.",
    "[reports]") {
  Project project("Over Project", 6, 7.5, 95);

  CHECK(project.ConvertMinutesToString(360) == "6:00");
  CHECK(project.ConvertMinutesToString(450) == "7:30");
  CHECK(project.CalculatedPercentComplete() == 125);
  CHECK(project.reported_percent_complete() == 95);

  std::ofstream out("test_out.txt");
  project.ProjectReport(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "Over Project");
  getline(in, line);
  CHECK(line == "Estimated time: 6:00");
  getline(in, line);
  CHECK(line == "Actual time spent: 7:30");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 125%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 95%");
  getline(in, line);
  CHECK(line == "");

  in.close();
}

TEST_CASE(
    "ProjectReport reports is as expected when name three projects are written "
    "to the same file",
    "[reports]") {
  Project project1("Over Project", 6, 7.5, 95);
  Project project2("Test Project", 22, 1.5, 12);
  Project project3("Fast Project", .5, .25, 42);

  CHECK(project1.ConvertMinutesToString(360) == "6:00");
  CHECK(project1.ConvertMinutesToString(450) == "7:30");
  CHECK(project1.CalculatedPercentComplete() == 125);
  CHECK(project1.reported_percent_complete() == 95);

  CHECK(project2.ConvertMinutesToString(1320) == "22:00");
  CHECK(project2.ConvertMinutesToString(90) == "1:30");
  CHECK(project2.CalculatedPercentComplete() == 7);
  CHECK(project2.reported_percent_complete() == 12);

  CHECK(project3.ConvertMinutesToString(30) == "0:30");
  CHECK(project3.ConvertMinutesToString(15) == "0:15");
  CHECK(project3.CalculatedPercentComplete() == 50);
  CHECK(project3.reported_percent_complete() == 42);

  std::ofstream out("test_out.txt");
  project1.ProjectReport(out);
  project2.ProjectReport(out);
  project3.ProjectReport(out);
  out.close();
  std::ifstream in("test_out.txt");

  std::string line;
  getline(in, line);
  CHECK(line == "Over Project");
  getline(in, line);
  CHECK(line == "Estimated time: 6:00");
  getline(in, line);
  CHECK(line == "Actual time spent: 7:30");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 125%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 95%");

  getline(in, line);
  CHECK(line == "Test Project");
  getline(in, line);
  CHECK(line == "Estimated time: 22:00");
  getline(in, line);
  CHECK(line == "Actual time spent: 1:30");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 7%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 12%");

  getline(in, line);
  CHECK(line == "Fast Project");
  getline(in, line);
  CHECK(line == "Estimated time: 0:30");
  getline(in, line);
  CHECK(line == "Actual time spent: 0:15");
  getline(in, line);
  CHECK(line == "Calculated percent complete: 50%");
  getline(in, line);
  CHECK(line == "Reported percent complete: 42%");
  getline(in, line);
  CHECK(line == "");

  in.close();
}