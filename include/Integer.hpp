// Copyright 2018 J&JV

/**
 * @file        Integer.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       22/11/2018
 * @date        22/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_INTEGER_HPP_
#define INCLUDE_INTEGER_HPP_

class Integer {
   public:
    Integer(int integer){
        m_data = integer;
    }
    Integer(Integer &&) = default;
    Integer(const Integer &) = default;
    Integer &operator=(Integer &&) = default;
    Integer &operator=(const Integer &) = default;
    ~Integer() = default;

    int get(){ return m_data; }

    bool operator==(const Integer &other) const { return m_data == other.m_data; }
    bool operator==(const int &other) const { return m_data == other; }

    bool operator!=(const Integer &other) const { return m_data != other.m_data; }
    bool operator!=(const int &other) const { return m_data != other; }

    friend std::ostream& operator<<(std::ostream &o, Integer const &integer) {
        o << integer.m_data;
        return o;
    }

   private:
    int m_data;
};

#endif