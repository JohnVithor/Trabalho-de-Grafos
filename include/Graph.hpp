// Copyright 2018 J&JV

/**
 * @file        Graph.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        19/11/2018
 * @version     0.2
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
template <typename T>
class Graph {
   public:
    Graph();
    Graph(Graph<T> &&) = default;
    Graph(const Graph<T> &) = default;
    Graph<T> &operator=(Graph<T> &&) = default;
    Graph<T> &operator=(const Graph<T> &) = default;
    ~Graph();

    bool insert_node(T *m_type);
    bool remove_node(T *m_type);
    Node<T> *get_node(int pos);

    bool insert_edge(T *m_type1, T *m_type2);
    bool remove_edge(T *m_type1, T *m_type2);
    bool edge_exists(T *m_type1, T *m_type2);

    int get_size();
    int get_order();

    Coloration<T> *get_coloration();
    bool erase_coloration();

    void print();
    void print_colors();
    void print_dsat();

   private:
    std::forward_list<Node<T> *> m_data;
    int m_order = 0;
    int m_size = 0;

    Coloration<T> *dsatur();
    Node<T> *get_greatest_degree_not_colored();
    Node<T> *get_greatest_degree();
    Node<T> *get_greatest_satured_degree_not_colored();
    Coloration<T> *m_coloration = nullptr;
    int next_color(Node<T> *node, Coloration<T> *coloration);
};

#include "Graph.inl"

#endif  // INCLUDE_GRAPH_HPP_
