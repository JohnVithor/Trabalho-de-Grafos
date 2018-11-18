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
    Node new_node(m_class);
    bool flag = true;
    for (auto node : m_data) {
        if (node == new_node) {
            flag = false;
        }
    }
    if (flag) {
        m_data.push_front(new_node);
        ++m_order;
    }

    return flag;
}

bool Graph::remove_node(Class &m_class) {
    Node r_node(m_class);
    bool flag = false;
    for (auto node : m_data) {
        if (node == r_node) {
            flag = true;
        }
    }
    if (flag) {
        m_data.remove(r_node);
        --m_order;
    }
    return flag;
}

Node Graph::get_node(int pos) {
    int i = 0;
    for (auto node : m_data) {
        if (i == pos) {
            return node;
        }
        ++i;
    }
    return Node();
}

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
    if (!f1) {
        m_data.push_front(node1);
        ++m_order;
    }
    if (!f2) {
        m_data.push_front(node2);
        ++m_order;
    }

    for (auto &&node : m_data) {
        if (node.get_class() == node1.get_class()) {
            f1 = false;
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node2.get_class()) {
                    f1 = true;
                }
            }
            if (!f1) {
                node.insert_neighbor(node2);
                ++m_size;
            }
        }
        if (node.get_class() == node2.get_class()) {
            f2 = false;
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node1.get_class()) {
                    f2 = true;
                }
            }
            if (!f2) {
                node.insert_neighbor(node1);
                ++m_size;
            }
        }
    }
    if (f1 && f2) {
        return false;
    }
    return true;
}

bool Graph::remove_edge(Class &m_class1, Class &m_class2) {
    bool f1 = false, f2 = false, f3 = false;
    if (m_class1 == m_class2) {
        f3 = true;
    }
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
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (node.get_class() == node1.get_class()) {
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node2.get_class()) {
                    f1 = node.remove_neighbor(node2);
                    break;
                }
            }
        }
        if (node.get_class() == node2.get_class()) {
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node1.get_class()) {
                    f2 = node.remove_neighbor(node1);
                    break;
                }
            }
        }
    }
    if ((f1 && f2) || (f1 && f3) || (f2 && f3)) {
        --m_size;
    }
    return (f1 && f2) || (f1 && f3) || (f2 && f3);
}

bool Graph::edge_exists(Class &m_class1, Class &m_class2) {
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
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (node.get_class() == node1.get_class()) {
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node2.get_class()) {
                    return true;
                }
            }
        }
        if (node.get_class() == node2.get_class()) {
            for (auto &&neigh : node.get_neighbors()) {
                if (neigh.get_class() == node1.get_class()) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Graph::get_size() { return m_size; }

int Graph::get_order() { return m_order; }

Coloration Graph::get_coloration() {
    if (m_coloration == Coloration()) {
        m_coloration = dsatur();
    }
    return m_coloration;
}

bool Graph::erase_coloration() {
    m_coloration = Coloration();
    return true;
}

void Graph::print() {
    std::cout << "Nodes: Edges" << std::endl;
    for (auto node : m_data) {
        std::cout << node.get_class().get_subject() << ": ";
        for (auto neigh : node.get_neighbors()) {
            std::cout << neigh.get_class().get_subject() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Order: " << m_order << std::endl
              << "Size: " << m_size << std::endl;
}

Coloration Graph::dsatur() {
    Coloration coloration;
    return coloration;
}