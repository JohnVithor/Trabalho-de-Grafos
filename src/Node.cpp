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

Node::Node(Class *m_class) { this->m_class = m_class; }

Node::~Node() {}

bool Node::set_color(int color)
{
    if (this->color == -1)
    {
        this->color = color;
        return true;
    }
    return false;
}

int Node::get_color() { return color; }

int Node::get_degree() { return degree; }

Class *Node::get_class() { return m_class; }

bool Node::set_class(Class *m_class)
{
    this->m_class = m_class;
    return true;
}

std::forward_list<Node *> Node::get_neighbors() { return neighbors; }

bool Node::remove_neighbor(Node *node)
{
    bool flag = false;
    for (auto neigh : neighbors)
    {
        if (neigh == node)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        neighbors.remove(node);
        --degree;
    }
    return flag;
}

bool Node::insert_neighbor(Node *node)
{
    bool flag = false;
    for (auto neigh : neighbors)
    {
        if (neigh == node)
        {
            flag = true;
        }
    }
    if (!flag)
    {
        neighbors.push_front(node);
        ++degree;
    }
    return flag;
}

bool Node::update_dsat()
{
    std::map<int, int> counter;
    for (auto neigh : neighbors)
    {
        if (neigh->color != -1)
        {
            auto n = counter.insert(std::pair<int, int>(neigh->color, 1));
            if (n.second == false)
            {
                counter[neigh->color] = ++counter[neigh->color];
            }
        }
    }
    dsat = counter.size();
    return true;
}

int Node::get_dsat() { return dsat; }