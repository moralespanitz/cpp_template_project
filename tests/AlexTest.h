/**
 * @file AlexTest.h
 * @author Alexander Morales Panitz (@moralespanitz)
 * @brief General class for testing
 * @version 0.1
 * @date 2022-05-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ALEXTEST_H
#define ALEXTEST_H

#include "../tools/Color.h"
#include <iostream>
#include <tuple>
namespace CLI {
class StatusProgressBar {
public:
  StatusProgressBar();
  ~StatusProgressBar();
  std::string GetSucessBar(int test_number, int percent);
  std::string GetFailedBar(int test_number, int percent);
};

StatusProgressBar::StatusProgressBar() {}

StatusProgressBar::~StatusProgressBar() {}

std::string StatusProgressBar::GetSucessBar(int test_number) {
  return Color::getColor(Color::GREEN) + "████████████████████ : TEST_NUMBER " +
         std::to_string(test_number);
}
std::string StatusProgressBar::GetSucessBar(int test_number) {
  return Color::getColor(Color::RED) + "████████████████████ : TEST_NUMBER " +
         std::to_string(test_number);
}
} // namespace CLI

namespace AlexTest {
template <typename T> class AlexTest {
private:
  int number_of_tests;
  int number_of_errors;
  int number_of_passed;
  CLI::StatusProgressBar progress_bar;
  std::vector < std::pair<T, T> pair_outputs public : AlexTest() {
    number_of_errors = 0;
    number_of_tests = 0;
    number_of_passed = 0;
  }
  ~AlexTest();
  void insert_tests(std::vector<std::pair<T, T>> pair_outputs);
  void run_tests();
  void compare_outputs(T current_output, T expected_output);
};
template <typename T>
void AlexTest<T>::insert_tests(std::vector < std::pair<T, T> pair_outputs) {
  this->pair_outputs = pair_outputs;
}
template <typename T> void AlexTest<T>::run_tests() {
  for (auto entry = pair_outputs.begin(); entry != pair_outputs.end();
       entry++) {
    compare_outputs(
        *entry->first,
        *entry->second); // entry->first: current, entry->second: expected
  }
}
template <typename T>
void AlexTest<T>::compare_outputs(T current_output, T expected_output) {
  if (current_output == NULL)
    throw std::invalid_argument(
        "[ERROR]: At compare_outputs function an error was found. Please, "
        "insert correct arguments. Argument value: " +
        std::to_string(current_output));
  if (current_output == expected_output) {
    progress_bar.GetSucessBar(++number_of_tests);
    number_of_passed++;
  } else {
    progress_bar.GetFailedBar(number_of_tests++);
    number_of_errors++;
  }
}
} // namespace AlexTest

#endif // ALEXTEST_H