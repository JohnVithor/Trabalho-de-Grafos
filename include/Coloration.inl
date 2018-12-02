// Copyright 2018 J&JV

/**
 * @file        Coloration.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      Josivan ()
 * @since       04/11/2018
 * @date        22/11/2018
 * @version     0.3
 */

#include "Coloration.hpp"

template <typename T>
Coloration<T>::Coloration() {}

template <typename T>
Coloration<T>::~Coloration() {
    for (auto color : m_partitions) {
        color->clear();
        if (color != nullptr) {
            delete color;
            color = nullptr;
        }
    }
}

template <typename T>
std::list<std::list<Node<T> *> *> Coloration<T>::get_partitions() {
    return m_partitions;
}

template <typename T>
int Coloration<T>::get_chromatic_number() {
    return chromatic_number;
}

template <typename T>
bool Coloration<T>::add_node(int color, Node<T> *node) {
    if (chromatic_number <= color) {
        std::list<Node<T> *> *new_color =
            new std::list<Node<T> *>();
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
            std::cout << *node->get_type() << " ";
        }
        ++count;
        std::cout << std::endl;
    }
}