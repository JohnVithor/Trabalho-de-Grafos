// Copyright 2018 J&JV

/**
 * @file        Coloration.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        19/11/2018
 * @version     0.2
 */

#include "Coloration.hpp"

template <typename T>
Coloration<T>::Coloration() {}

template <typename T>
Coloration<T>::~Coloration() {}

template <typename T>
std::list<std::forward_list<Node<T> *> *> Coloration<T>::get_partitions() {
    return m_partitions;
}

template <typename T>
int Coloration<T>::get_chromatic_number() {
    return chromatic_number;
}

template <typename T>
bool Coloration<T>::is_valid() {
    return false;
}

template <typename T>
bool Coloration<T>::add_node(int color, Node<T> *node) {
    if (chromatic_number <= color) {
        std::forward_list<Node *> *new_color = new std::forward_list<Node *>();
        new_color->push_front(node);
        m_partitions.push_back(new_color);
        ++chromatic_number;
        return true;
    }
    int count = 0;
    for (auto color_at : m_partitions) {
        if (count == color) {
            color_at->push_front(node);
            return true;
        }
        ++count;
    }
    return false;
}

template <typename T>
void Coloration<T>::print() {
    int count = 0;
    for (auto color : m_partitions) {
        std::cout << "Cor " << count << ": ";
        for (auto node : *color) {
            std::cout << node->get_type() << " ";
        }
        ++count;
        std::cout << std::endl;
    }
}