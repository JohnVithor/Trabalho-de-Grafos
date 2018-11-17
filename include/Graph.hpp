// Copyright 2018 J&JV

/**
 * @file        Graph.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_GRAPH_HPP_
#define INCLUDE_GRAPH_HPP_

#include <forward_list>
#include <iostream>

#include "Coloration.hpp"
#include "Node.hpp"

/**
 * @brief ...
 *
 */
class Graph {
   public:
    Graph();
    Graph(Graph &&) = default;
    Graph(const Graph &) = default;
    Graph &operator=(Graph &&) = default;
    Graph &operator=(const Graph &) = default;
    ~Graph();

    bool insert_node(Class &m_class);
    bool remove_node(Class &m_class);
    Node get_node(int pos);

    bool insert_edge(Class &m_class1, Class &m_class2);
    bool remove_edge(Class &m_class1, Class &m_class2);
    bool edge_exists(Class &m_class1, Class &m_class2);

    int get_size();
    int get_order();

    Coloration get_coloration();
    bool erase_coloration();

    void print();

   private:
    std::forward_list<Node> m_data;
    int m_order = 0;
    int m_size = 0;

    Coloration m_coloration;
};

#endif  // INCLUDE_GRAPH_HPP_
