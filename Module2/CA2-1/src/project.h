#ifndef PROJECT_H
#define PROJECT_H

#include <fstream>
#include <iostream>
#include <string>

class Project {
 private:
  // Data members
  std::string name_;
  int estimated_time_;
  int actual_time_;
  int reported_percent_complete_;

 public:
  // Constructors
  Project()
      : name_("unnamed"),
        estimated_time_(60.0),
        actual_time_(0.0),
        reported_percent_complete_(0){};
  Project(std::string name, double estimated_time_hours,
          double actual_time_hours = 0, int percent_complete = 0);

  // Destructor
  ~Project(){};

  // Accessors
  std::string name() const { return name_; };
  int estimated_time_minutes() const { return estimated_time_; };
  double estimated_time_hours() const { return estimated_time_ / 60.0; };
  int actual_time_minutes() const { return actual_time_; };
  double actual_time_hours() const { return actual_time_ / 60.0; };
  int reported_percent_complete() const { return reported_percent_complete_; }

  // Mutators
  void set_name(std::string name) { name_ = name; }
  void set_estimated_time_minutes(int estimated_time_minutes);
  void set_estimated_time_hours(double estimated_time_hours);
  void set_actual_time_minutes(int actual_time_hours);
  void set_actual_time_hours(double actual_time_minutes);
  void set_percent_complete(int percent_complete);

  // Additional Methods
  void RecordTimeSpentMinutes(int minutes, int percent_complete);
  void RecordTimeSpentHours(double hours, int percent_complete);
  int CalculatedPercentComplete() const;
  static std::string ConvertMinutesToString(int minutes);
  std::string TimeLeftOnProject() const;
  void WriteData(std::ostream&) const;
  void ProjectReport(std::ostream&) const;
};

#endif