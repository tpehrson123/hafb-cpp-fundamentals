#include "project.h"

#include <cmath>
#include <fstream>
#include <string>

using namespace std;

Project::Project(std::string name, double estimated_time_hours,
                 double actual_time_hours, int percent_complete) {
  name_ = name;
  try {
    set_estimated_time_hours(estimated_time_hours);
    set_actual_time_hours(actual_time_hours);
    set_percent_complete(percent_complete);
  } catch (const out_of_range& e) {
    throw;
  }
}

void Project::set_estimated_time_minutes(int estimated_time_minutes) {
  if (estimated_time_minutes > 0) {
    estimated_time_ = estimated_time_minutes;
  } else {
    throw out_of_range(to_string(estimated_time_minutes) +
                       ": Estimated time must be greater than zero.");
  }
}

void Project::set_estimated_time_hours(double estimated_time_hours) {
  try {
    set_estimated_time_minutes(round(estimated_time_hours * 60));
  } catch (const out_of_range& e) {
    throw;
  }
}

void Project::set_actual_time_minutes(int actual_time) {
  if (actual_time < 0) {
    throw out_of_range("Actual time spent must be zero or greater.");
  } else {
    actual_time_ = actual_time;
  }
}
void Project::set_actual_time_hours(double actual_time) {
  try {
    set_actual_time_minutes(round(actual_time * 60));
  } catch (const out_of_range& e) {
    throw;
  }
}

void Project::set_percent_complete(int percent_complete) {
  if (percent_complete < 0 || percent_complete > 100) {
    throw out_of_range("Percent complete must be between 0-100");
  } else {
    reported_percent_complete_ = percent_complete;
  }
}

void Project::RecordTimeSpentMinutes(int minutes, int percent_complete) {
  string error_message;
  if (minutes < 0) {
    error_message = "Time reported must be greater than zero. ";
  } else {
    try {
      set_actual_time_minutes(actual_time_ + minutes);
    } catch (const out_of_range& e) {
      error_message += e.what();
    }
  }

  try {
    set_percent_complete(percent_complete);
  } catch (const out_of_range& e) {
    error_message += e.what();
  }

  if (error_message == "") {
    return;
  } else {
    throw out_of_range(error_message);
  }
}

void Project::RecordTimeSpentHours(double hours, int percent_complete) {
  try {
    RecordTimeSpentMinutes(hours * 60, percent_complete);
  } catch (const out_of_range& e) {
    throw;
  }
}

int Project::CalculatedPercentComplete() const {
  return round(actual_time_ * 100.0 / estimated_time_);
}

string Project::ConvertMinutesToString(int minutes) {
  // use integer division to get hours
  int hours = minutes / 60;
  int just_minutes = abs(minutes % 60);
  string time = to_string(hours) + ":";
  // add a leading zero when minutes is less than 10
  if (just_minutes < 10) {
    time += "0";
  }
  time += to_string(just_minutes);

  return time;
}

string Project::TimeLeftOnProject() const {
  int time = estimated_time_ - actual_time_;
  return ConvertMinutesToString(time);
}

void Project::WriteData(ostream& out) const {
  out << estimated_time_ << " " << actual_time_ << " "
      << reported_percent_complete_ << endl
      << name_ << endl;
}

void Project::ProjectReport(ostream& out) const {
  string estimated_time = ConvertMinutesToString(estimated_time_);
  string actual_time = ConvertMinutesToString(actual_time_);
  out << name_ << "\nEstimated time: " << estimated_time
      << "\nActual time spent: " << actual_time
      << "\nCalculated percent complete: "
      << to_string(CalculatedPercentComplete()) << "%\n"
      << "Reported percent complete: " << to_string(reported_percent_complete())
      << "%\n";
}
