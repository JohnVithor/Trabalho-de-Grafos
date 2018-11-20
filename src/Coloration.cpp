// Copyright 2018 J&JV

/**
 * @file        Coloration.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        19/11/2018
 * @version     0.2
 */

#include "Coloration.hpp"

Coloration::Coloration() {}

Coloration::~Coloration() {}

std::forward_list<std::forward_list<Node *> *> Coloration::get_partitions() {
    return m_partitions;
}

int Coloration::get_chromatic_number() { return chromatic_number; }

bool Coloration::is_valid() { return false; }

bool Coloration::add_node(int color, Node *node) {
    if (chromatic_number <= color) {
        std::forward_list<Node *> *new_color = new std::forward_list<Node *>();
        new_color->push_front(node);
        m_partitions.push_front(new_color);
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

void Coloration::print() {
    for (auto color : m_partitions) {
        int count = 0;
        for (auto node : *color) {
            std::cout << "Cor " << count << ": "
                      << node->get_class()->get_subject() << " ";
            ++count;
        }
        std::cout << std::endl;
    }
}