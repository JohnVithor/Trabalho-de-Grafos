// Copyright 2018 J&JV

/**
 * @file        Node.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#include "Node.hpp"

Node::Node() {}

Node::Node(Class &m_class) { this->m_class = m_class; }

Node::~Node() {}

bool Node::set_color(int color) {
    this->color = color;
    return true;
}

int Node::get_color() { return color; }

int Node::get_degree() { return degree; }

Class Node::get_class() { return m_class; }

bool Node::set_class(Class &m_class) {
    this->m_class = m_class;
    return true;
}

std::forward_list<Node> Node::get_neighbors() { return neighbors; }

bool Node::remove_neighbor(Node node) {
    neighbors.remove(node);
    return true;
}

bool Node::insert_neighbor(Node node) {
    neighbors.push_front(node);
    return true;
}