/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;
};

#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) { // 传引用？
  // 打开文件
  std::ifstream ifs(filename);
  if(ifs.is_open()) {
    std::cout << "course.csv file is ok" << std::endl;
  } else {
    std::cerr << "course.csv file is shit" << std::endl;
  }

  std::string buf;

  // 读入除第一行之外其他行
  while(std::getline(ifs, buf)) {
    auto readline = split(buf, ',');
    if(readline[0] == "Title") continue;

    Course course{readline[0], readline[1], readline[2]};
    courses.push_back(course);
  }
  ifs.close();
}

/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  std::ofstream ofs(COURSES_OFFERED_PATH);
  if(ofs.is_open()) {
    std::cout << COURSES_OFFERED_PATH << " is ok" << std::endl;
  } else {
    std::cerr << COURSES_OFFERED_PATH << " is shit" << std::endl;
  }

  // 写入行名
  Course headline{"Title", "Number of Units", "Quarter"};
  ofs << headline;
  ofs << '\n';

  std::vector<Course> not_offered;
  for(Course content : all_courses) {
    if(content.quarter != "null") {
      ofs << content;
      ofs << '\n';
      not_offered.push_back(content);
    }
  }

  // 写入完成后再删除
  for(Course content : not_offered) {
    delete_elem_from_vector(all_courses, content);
  }
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
  std::ofstream ofs(COURSES_NOT_OFFERED_PATH);
  if(ofs.is_open()) {
    std::cout << COURSES_OFFERED_PATH << " is ok" << std::endl;
  } else {
    std::cerr << COURSES_OFFERED_PATH << " is shit" << std::endl;
  }

  Course headline{"Title", "Number of Units", "Quarter"};
  ofs << headline;
  ofs << '\n';

  for(Course content : unlisted_courses) {
      ofs << content;
      ofs << '\n';
  }
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
  return 0;
}