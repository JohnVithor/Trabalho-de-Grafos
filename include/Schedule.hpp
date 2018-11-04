// Copyright 2018 J&JV

/**
 * @file        Schedule.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_SCHEDULE_HPP_
#define INCLUDE_SCHEDULE_HPP_

#include <string>

/**
 * @brief ...
 *
 */
class Schedule {
   public:
    Schedule();
    Schedule(std::string s_schedule);
    Schedule(Schedule &&) = default;
    Schedule(const Schedule &) = default;
    Schedule &operator=(Schedule &&) = default;
    Schedule &operator=(const Schedule &) = default;
    ~Schedule();

    bool intersection(Schedule *schedule);

   private:
    bool m_days[7] = {false, false, false, false, false, false, false};
    bool m_shift[3] = {false, false, false};
    bool m_class[6] = {false, false, false, false, false, false};
};

#endif  // INCLUDE_SCHEDULE_HPP_
