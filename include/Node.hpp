// Copyright 2018 J&JV

/**
 * @file        Node.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_

#include <forward_list>

#include "Class.hpp"

/**
 * @brief ...
 *
 */
class Node {
   public:
    Node();
    Node(Class &m_class);
    Node(Node&&) = default;
    Node(const Node&) = default;
    Node& operator=(Node&&) = default;
    Node& operator=(const Node&) = default;
    ~Node();

    bool set_color(int color);
    int get_color();

    int get_degree();

    Class get_class();
    bool set_class(Class &m_class);

    std::forward_list<Node> get_neighbors();

    bool remove_neighbor(Node node);
    bool insert_neighbor(Node node);

    bool operator==(Node other) { return true; }

   private:
    Class m_class;
    int color = -1;
    int degree = -1;
    std::forward_list<Node> neighbors;
};

#endif  // INCLUDE_NODE_HPP_
