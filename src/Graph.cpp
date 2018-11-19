// Copyright 2018 J&JV

/**
 * @file        Graph.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        19/11/2018
 * @version     0.2
 */

#include "Graph.hpp"

Graph::Graph() {}

Graph::~Graph() {}

bool Graph::insert_node(Class *m_class) {
    Node *new_node = new Node(m_class);
    bool flag = true;
    for (auto node : m_data) {
        if (*node == *new_node) {
            flag = false;
        }
    }
    if (flag) {
        m_data.push_front(new_node);
        ++m_order;
    }

    return flag;
}

bool Graph::remove_node(Class *m_class) {
    Node *r_node = new Node(m_class);
    bool flag = false;
    for (auto node : m_data) {
        if (*node == *r_node) {
            flag = true;
        }
    }
    if (flag) {
        m_data.remove(r_node);
        --m_order;
    }
    return flag;
}

Node *Graph::get_node(int pos) {
    int i = 0;
    for (auto node : m_data) {
        if (i == pos) {
            return node;
        }
        ++i;
    }
    return nullptr;
}

bool Graph::insert_edge(Class *m_class1, Class *m_class2) {
    if (m_class1->get_subject() == m_class2->get_subject()) {
        return false;
    }

    bool f1 = false, f2 = false;
    Node *node1 = new Node(m_class1);
    Node *node2 = new Node(m_class2);
    for (auto node : m_data) {
        if (node->get_class() == node1->get_class()) {
            f1 = true;
            node1 = node;
        }
        if (node->get_class() == node2->get_class()) {
            f2 = true;
            node2 = node;
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
        if (node->get_class() == node1->get_class()) {
            f1 = false;
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node2->get_class()) {
                    f1 = true;
                }
            }
            if (!f1) {
                node->insert_neighbor(node2);
                ++m_size;
            }
        }
        if (node->get_class() == node2->get_class()) {
            f2 = false;
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node1->get_class()) {
                    f2 = true;
                }
            }
            if (!f2) {
                node->insert_neighbor(node1);
                ++m_size;
            }
        }
    }
    if (f1 && f2) {
        return false;
    }
    return true;
}

bool Graph::remove_edge(Class *m_class1, Class *m_class2) {
    bool f1 = false, f2 = false, f3 = false;
    if (m_class1 == m_class2) {
        f3 = true;
    }
    Node *node1 = new Node(m_class1);
    Node *node2 = new Node(m_class2);
    for (auto node : m_data) {
        if (node->get_class() == node1->get_class()) {
            f1 = true;
        }
        if (node->get_class() == node2->get_class()) {
            f2 = true;
        }
    }
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (node->get_class() == node1->get_class()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node2->get_class()) {
                    f1 = node->remove_neighbor(node2);
                    break;
                }
            }
        }
        if (node->get_class() == node2->get_class()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node1->get_class()) {
                    f2 = node->remove_neighbor(node1);
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

bool Graph::edge_exists(Class *m_class1, Class *m_class2) {
    bool f1 = false, f2 = false;
    Node *node1 = new Node(m_class1);
    Node *node2 = new Node(m_class2);
    for (auto node : m_data) {
        if (node->get_class() == node1->get_class()) {
            f1 = true;
        }
        if (node->get_class() == node2->get_class()) {
            f2 = true;
        }
    }
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (node->get_class() == node1->get_class()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node2->get_class()) {
                    return true;
                }
            }
        }
        if (node->get_class() == node2->get_class()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (neigh->get_class() == node1->get_class()) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Graph::get_size() { return m_size; }

int Graph::get_order() { return m_order; }

Coloration *Graph::get_coloration() {
    if (m_coloration == nullptr) {
        m_coloration = dsatur();
    }
    return m_coloration;
}

bool Graph::erase_coloration() {
    m_coloration = nullptr;
    for (auto node : m_data) {
        node->set_color(-1);
    }
    return true;
}

void Graph::print() {
    std::cout << "Nodes: Edges" << std::endl;
    for (auto node : m_data) {
        std::cout << node->get_class()->get_subject() << ": ";
        for (auto neigh : node->get_neighbors()) {
            std::cout << neigh->get_class()->get_subject() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Order: " << m_order << std::endl
              << "Size: " << m_size << std::endl;
}

Coloration *Graph::dsatur() {
    Coloration *coloration = new Coloration();
    int count = m_order;
    Node *great = get_greatest_degree();
    coloration->add_node(0, great);
    great->set_color(0);
    --count;
    while (count > 0) {
        for (auto neigh : great->get_neighbors()) {
            if (neigh->get_color() == -1) {
                neigh->update_dsat();
            }
        }
        great = get_greatest_satured_degree_not_colored();
        int color = next_color(great, coloration);
        coloration->add_node(color, great);
        great->set_color(color);
        --count;
    }

    return coloration;
}

Node *Graph::get_greatest_degree_not_colored() {
    bool flag = false;
    Node *great = m_data.front();
    if (great->get_color() == -1) {
        flag = true;
    }
    for (auto node : m_data) {
        if (flag && node->get_color() == -1) {
            great = node;
            flag = false;
        }
        if (node->get_color() == -1 &&
            node->get_degree() > great->get_degree()) {
            great = node;
        }
    }
    return great;
}

Node *Graph::get_greatest_degree() {
    Node *great = m_data.front();
    for (auto node : m_data) {
        if (node->get_degree() > great->get_degree()) {
            great = node;
        }
    }
    return great;
}

Node *Graph::get_greatest_satured_degree_not_colored() {
    Node *great = nullptr;
    std::forward_list<Node *> draw;

    for (auto node : m_data) {
        if (node->get_color() == -1) {
            great = node;
            draw.push_front(great);
            break;
        }
    }
    for (auto node : m_data) {
        if (node->get_color() == -1) {
            if (node->get_dsat() > great->get_dsat()) {
                great = node;
                draw.clear();
                draw.push_front(great);
            } else if (node->get_dsat() == great->get_dsat()) {
                draw.push_front(node);
            }
        }
    }
    for (auto n : draw) {
        if (n->get_degree() >= great->get_degree()) {
            great = n;
        }
    }
    return great;
}

int Graph::next_color(Node *node, Coloration *coloration) {
    bool flag = true;
    int count = 0;
    for (auto color : coloration->get_partitions()) {
        flag = true;
        for (auto neigh : node->get_neighbors()) {
            for (auto n : *color) {
                if (n == neigh) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            return count;
        }
        ++count;
    }
    return count;
}