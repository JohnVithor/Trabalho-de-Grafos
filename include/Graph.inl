// Copyright 2018 J&JV

/**
 * @file        Graph.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        22/11/2018
 * @version     0.4
 */

#include "Graph.hpp"

template <typename T>
Graph<T>::Graph() {}

template <typename T>
Graph<T>::~Graph() {}

template <typename T>
bool Graph<T>::insert_node(T *m_type) {
    Node<T> *new_node = new Node<T>(m_type);
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

template <typename T>
bool Graph<T>::remove_node(T *m_type) {
    Node<T> *r_node = new Node<T>(m_type);
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

template <typename T>
Node<T> *Graph<T>::get_node(int pos) {
    int i = 0;
    for (auto node : m_data) {
        if (i == pos) {
            return node;
        }
        ++i;
    }
    return nullptr;
}

template <typename T>
bool Graph<T>::insert_edge(T *m_type1, T *m_type2) {
    if (*m_type1 == *m_type2) {
        return false;
    }

    bool f1 = false, f2 = false;
    Node<T> *node1 = new Node<T>(m_type1);
    Node<T> *node2 = new Node<T>(m_type2);
    for (auto node : m_data) {
        if (*node->get_type() == *node1->get_type()) {
            f1 = true;
            node1 = node;
        }
        if (*node->get_type() == *node2->get_type()) {
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
        if (*node->get_type() == *node1->get_type()) {
            f1 = false;
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node2->get_type()) {
                    f1 = true;
                }
            }
            if (!f1) {
                node->insert_neighbor(node2);
                ++m_size;
            }
        }
        if (*node->get_type() == *node2->get_type()) {
            f2 = false;
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node1->get_type()) {
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

template <typename T>
bool Graph<T>::remove_edge(T *m_type1, T *m_type2) {
    bool f1 = false, f2 = false, f3 = false;
    if (*m_type1 == *m_type2) {
        f3 = true;
    }
    Node<T> *node1 = new Node<T>(m_type1);
    Node<T> *node2 = new Node<T>(m_type2);
    for (auto node : m_data) {
        if (*node->get_type() == *node1->get_type()) {
            f1 = true;
        }
        if (*node->get_type() == *node2->get_type()) {
            f2 = true;
        }
    }
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (node->get_type() == node1->get_type()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node2->get_type()) {
                    f1 = node->remove_neighbor(node2);
                    break;
                }
            }
        }
        if (*node->get_type() == *node2->get_type()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node1->get_type()) {
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

template <typename T>
bool Graph<T>::edge_exists(T *m_type1, T *m_type2) {
    bool f1 = false, f2 = false;
    Node<T> *node1 = new Node<T>(m_type1);
    Node<T> *node2 = new Node<T>(m_type2);
    for (auto node : m_data) {
        if (*node->get_type() == *node1->get_type()) {
            f1 = true;
        }
        if (*node->get_type() == *node2->get_type()) {
            f2 = true;
        }
    }
    if (!f1 || !f2) {
        return false;
    }

    for (auto &&node : m_data) {
        if (*node->get_type() == *node1->get_type()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node2->get_type()) {
                    return true;
                }
            }
        }
        if (*node->get_type() == *node2->get_type()) {
            for (auto &&neigh : node->get_neighbors()) {
                if (*neigh->get_type() == *node1->get_type()) {
                    return true;
                }
            }
        }
    }
    return false;
}

template <typename T>
int Graph<T>::get_size() {
    return m_size;
}

template <typename T>
int Graph<T>::get_order() {
    return m_order;
}

template <typename T>
Coloration<T> *Graph<T>::get_coloration() {
    if (m_coloration == nullptr) {
        m_coloration = dsatur();
    }
    return m_coloration;
}

template <typename T>
bool Graph<T>::erase_coloration() {
    m_coloration = nullptr;
    for (auto node : m_data) {
        node->set_color(-1);
    }
    return true;
}

template <typename T>
void Graph<T>::print() {
    std::cout << "Nodes: Edges" << std::endl;
    for (auto node : m_data) {
        std::cout << *node->get_type() << ": ";
        for (auto neigh : node->get_neighbors()) {
            std::cout << *neigh->get_type() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Order: " << m_order << std::endl
              << "Size: " << m_size << std::endl;
}

template <typename T>
Coloration<T> *Graph<T>::dsatur() {
    Coloration<T> *coloration = new Coloration<T>();
    int count = m_order;
    Node<T> *great = get_greatest_degree();
    coloration->add_node(0, great);
    great->set_color(0);
    --count;
    // std::cout << great->get_type()->get_subject() << " 0" << std::endl;
    while (count > 0) {
        for (auto neigh : great->get_neighbors()) {
            if (neigh->get_color() == -1) {
                neigh->update_dsat();
            }
        }
        // print_dsat();

        great = get_greatest_satured_degree_not_colored();

        int color = next_color(great, coloration);

        // std::cout << great->get_type()->get_subject() << " " << color
        //           << std::endl;

        coloration->add_node(color, great);
        great->set_color(color);
        --count;
    }

    return coloration;
}

template <typename T>
Node<T> *Graph<T>::get_greatest_degree_not_colored() {
    bool flag = false;
    Node<T> *great = m_data.front();
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

template <typename T>
Node<T> *Graph<T>::get_greatest_degree() {
    Node<T> *great = m_data.front();
    for (auto node : m_data) {
        if (node->get_degree() >= great->get_degree()) {
            great = node;
        }
    }
    return great;
}

template <typename T>
Node<T> *Graph<T>::get_greatest_satured_degree_not_colored() {
    Node<T> *great = nullptr;
    std::forward_list<Node<T> *> draw;

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
        if (get_degree_no_colored(n) >= get_degree_no_colored(great)) {
            great = n;
        }
    }
    return great;
}

template <typename T>
int Graph<T>::next_color(Node<T> *node, Coloration<T> *coloration) {
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

template <typename T>
void Graph<T>::print_colors() {
    for (auto node : m_data) {
        std::cout << node->get_type() << " : "
                  << node->get_color() << std::endl;
    }
}

template <typename T>
void Graph<T>::print_dsat() {
    for (auto node : m_data) {
        std::cout << node->get_type()->get_subject() << " : "
                  << node->get_dsat() << std::endl;
    }
}
template <typename T>
int Graph<T>::get_degree_no_colored(Node<T>* node){
    int degree = 0;
    for(auto n : node->get_neighbors()) {
        if(n->get_color() == -1) {
            ++degree;
        }
    }
    return degree;
}