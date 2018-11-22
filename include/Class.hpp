// Copyright 2018 J&JV

/**
 * @file        Class.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        19/11/2018
 * @version     0.2
 */

#ifndef INCLUDE_CLASS_HPP_
#define INCLUDE_CLASS_HPP_

#include <string>

#include "Schedule.hpp"

/**
 * @brief ...
 *
 */
class Class {
   public:
    Class();
    Class(std::string subject, std::string schedule);
    Class(Class&&) = default;
    Class(const Class&) = default;
    Class& operator=(Class&&) = default;
    Class& operator=(const Class&) = default;
    ~Class();

    std::string get_subject();
    Schedule& get_schedule();

    bool operator==(const Class& other) const;
    bool operator!=(const Class& other) const;

    friend std::ostream& operator<<(std::ostream &o, Class &s_class) {
        o << s_class.get_subject();
        return o;
    }

   private:
    std::string subject;
    Schedule schedule;
};

#endif  // INCLUDE_CLASS_HPP_
