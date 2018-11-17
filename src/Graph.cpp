// Copyright 2018 J&JV

/**
 * @file        Graph.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#include "Graph.hpp"

Graph::Graph() {}

Graph::~Graph() {}

bool Graph::insert_node(Class &m_class) {
    Node node(m_class);
    m_data.push_front(node);
    ++m_order;
}

bool Graph::remove_node(Class &m_class) {}

Node Graph::get_node(int pos) {}

bool Graph::insert_edge(Class &m_class1, Class &m_class2) {
    bool f1 = false, f2 = false;
    Node node1(m_class1);
    Node node2(m_class2);
    for (auto node : m_data) {
        if (node.get_class() == node1.get_class()) {
            f1 = true;
        }
        if (node.get_class() == node2.get_class()) {
            f2 = true;
        }
    }
    if(!f1){
        m_data.push_front(node1);
    }
    if(!f2){
        m_data.push_front(node2);
    }
    
    for(auto&& node : m_data){
        if (node.get_class() == node1.get_class()) {
            f1 = false;
            for(auto&& neigh : node.get_neighbors()) {
                if (node.get_class() == node2.get_class()) {
                    f1 = true;
                }
            }
            if(!f1){
                node.insert_neighbor(node2);
            }
        }
        if (node.get_class() == node2.get_class()) {
            f2 = false;
            for(auto&& neigh : node.get_neighbors()) {
                if (node.get_class() == node1.get_class()) {
                    f2 = true;
                }
            }
            if(!f2){
                node.insert_neighbor(node1);
            }
        }
    }
    if(f1 && f2) {
        return false;
    }
    return true;    
}

bool Graph::remove_edge(Class &m_class1, Class &m_class2) {}

bool Graph::edge_exists(Class &m_class1, Class &m_class2) {}

int Graph::get_size() {}

int Graph::get_order() {}

Coloration Graph::get_coloration() {}

bool Graph::erase_coloration() {}

void Graph::print() {
    for (auto node : m_data) {
        std::cout << node.get_class().get_subject() << std::endl;
    }
}
