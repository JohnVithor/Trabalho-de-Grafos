// Copyright 2018 J&JV

/**
 * @file        Node.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      Josivan ()
 * @since       04/11/2018
 * @date        24/11/2018
 * @version     0.4
 */

#include "Node.hpp"

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(T *m_type) {
    this->m_type = m_type;
}

template <typename T>
Node<T>::~Node() {
    delete m_type;
    m_type = nullptr;
    /*
    for (auto node : neighbors) {
        if (node != nullptr) {
            delete node;
        }
    }
    */
}

template <typename T>
int Node<T>::set_color() {
    if (this->color == -1) {
        int color = 0;
        while (true) {
            auto it = dsat.find(color);
            if (it == dsat.end()) {
                this->color = color;
                // dsat[color] = color;
                return color;
            }
            ++color;
        }
    }
    return -1;
}

template <typename T>
bool Node<T>::erase_color() {
    this->color = -1;
    dsat.clear();
    return true;
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
int Node<T>::get_dsat() {
    return dsat.size();
}

template <typename T>
bool Node<T>::update_dsat(int color) {
    dsat[color] = color;
    return true;
}
