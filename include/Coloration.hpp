// Copyright 2018 J&JV

/**
 * @file        Coloration.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        22/11/2018
 * @version     0.3
 */

#ifndef INCLUDE_COLORATION_HPP_
#define INCLUDE_COLORATION_HPP_

#include <forward_list>
#include <iostream>
#include <list>

#include "Node.hpp"

/**
 * @brief ...
 *
 */
template <typename T>
class Coloration {
   public:
    Coloration();
    Coloration(Coloration<T> &&) = default;
    Coloration(const Coloration<T> &) = default;
    Coloration<T> &operator=(Coloration<T> &&) = default;
    Coloration<T> &operator=(const Coloration<T> &) = default;
    ~Coloration();

    std::list<std::forward_list<Node<T> *> *> get_partitions();
    int get_chromatic_number();
    void print();
    bool add_node(int color, Node<T> *node);

    bool operator==(const Coloration<T> &other) const {
        return m_partitions == other.m_partitions;
    }

   private:
    // Graph *m_graph = nullptr;
    std::list<std::forward_list<Node<T> *> *> m_partitions;
    int chromatic_number = 0;
};

#include "Coloration.inl"

#endif  // INCLUDE_COLORATION_HPP_
