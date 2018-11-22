// Copyright 2018 J&JV

/**
 * @file        Node.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        19/11/2018
 * @version     0.2
 */

#include "Node.hpp"

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(T *m_type) {
    this->m_type = m_type;
}

template <typename T>
Node<T>::~Node() {}

template <typename T>
bool Node<T>::set_color(int color) {
    if (this->color == -1) {
        this->color = color;
        return true;
    }
    return false;
}

template <typename T>
int Node<T>::get_color() {
    return color;
}

template <typename T>
int Node<T>::get_degree() {
    return degree;
}

template <typename T>
T *Node<T>::get_type() {
    return m_type;
}

template <typename T>
bool Node<T>::set_type(T *m_type) {
    this->m_T = m_type;
    return true;
}

template <typename T>
std::forward_list<Node<T> *> Node<T>::get_neighbors() {
    return neighbors;
}

template <typename T>
bool Node<T>::remove_neighbor(Node<T> *node) {
    bool flag = false;
    for (auto neigh : neighbors) {
        if (neigh == node) {
            flag = true;
            break;
        }
    }
    if (flag) {
        neighbors.remove(node);
        --degree;
    }
    return flag;
}

template <typename T>
bool Node<T>::insert_neighbor(Node<T> *node) {
    bool flag = false;
    for (auto neigh : neighbors) {
        if (neigh == node) {
            flag = true;
        }
    }
    if (!flag) {
        neighbors.push_front(node);
        ++degree;
    }
    return flag;
}

template <typename T>
bool Node<T>::update_dsat() {
    std::map<int, int> counter;
    for (auto neigh : neighbors) {
        if (neigh->color != -1) {
            auto n = counter.insert(std::pair<int, int>(neigh->color, 1));
            if (n.second == false) {
                counter[neigh->color] = ++counter[neigh->color];
            }
        }
    }
    dsat = counter.size();
    return true;
}

template <typename T>
int Node<T>::get_dsat() {
    return dsat;
}