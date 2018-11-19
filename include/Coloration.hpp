// Copyright 2018 J&JV

/**
 * @file        Coloration.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_COLORATION_HPP_
#define INCLUDE_COLORATION_HPP_

#include <forward_list>

#include "Node.hpp"

/**
 * @brief ...
 *
 */
class Coloration
{
  public:
    Coloration();
    Coloration(Coloration &&) = default;
    Coloration(const Coloration &) = default;
    Coloration &operator=(Coloration &&) = default;
    Coloration &operator=(const Coloration &) = default;
    ~Coloration();

    std::forward_list<std::forward_list<Node *>*> get_partitions();
    int get_chromatic_number();
    bool is_valid();

    bool add_node(int color, Node *node);

    bool operator==(const Coloration &other) const
    {
        return m_partitions == other.m_partitions;
    }

  private:
    // Graph *m_graph = nullptr;
    std::forward_list<std::forward_list<Node *>*> m_partitions;
    int chromatic_number = 0;
};

#endif // INCLUDE_COLORATION_HPP_
