// Copyright 2018 J&JV

/**
 * @file        Schedule.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        20/11/2018
 * @version     0.2
 */

#include "Schedule.hpp"

Schedule::Schedule() {}

Schedule::Schedule(std::string s_schedule) {
    m_schedule = s_schedule;
    bool flag = false;
    for (size_t i = 0; i < s_schedule.size(); ++i) {
        if (!flag) {
            switch (s_schedule[i]) {
                case '1':
                    m_days[0] = true;
                    break;
                case '2':
                    m_days[1] = true;
                    break;
                case '3':
                    m_days[2] = true;
                    break;
                case '4':
                    m_days[3] = true;
                    break;
                case '5':
                    m_days[4] = true;
                    break;
                case '6':
                    m_days[5] = true;
                    break;
                case '7':
                    m_days[6] = true;
                    break;
                default:
                    break;
            }
            if (s_schedule[i] == 'M') {
                m_shift[0] = true;
                flag = true;
                continue;
            } else if (s_schedule[i] == 'T') {
                m_shift[1] = true;
                flag = true;
                continue;
            } else if (s_schedule[i] == 'N') {
                m_shift[2] = true;
                flag = true;
                continue;
            }
        } else {
            switch (s_schedule[i]) {
                case '1':
                    m_class[0] = true;
                    break;
                case '2':
                    m_class[1] = true;
                    break;
                case '3':
                    m_class[2] = true;
                    break;
                case '4':
                    m_class[3] = true;
                    break;
                case '5':
                    m_class[4] = true;
                    break;
                case '6':
                    m_class[5] = true;
                    break;
                default:
                    break;
            }
        }
    }
}
Schedule::~Schedule() {}

bool Schedule::intersection(Schedule* schedule) {
    for (size_t i = 0; i < 3; ++i) {
        if (m_shift[i]) {
            if (!schedule->m_shift[i]) {
                return false;
            }
        }
    }

    for (size_t i = 0; i < 7; ++i) {
        if (m_days[i]) {
            if (schedule->m_days[i]) {
                for (size_t i = 0; i < 6; ++i) {
                    if (m_class[i]) {
                        if (schedule->m_class[i]) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Schedule::print() { std::cout << m_schedule << std::endl; }