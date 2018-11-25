// Copyright 2018 J&JV

/**
 * @file        Graph.inl
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      Josivan Gois ()
 * @since       02/11/2018
 * @date        24/11/2018
 * @version     0.5
 */

#include "Graph.hpp"

template <typename T>
Graph<T>::Graph() {}

template <typename T>
Graph<T>::~Graph() {
    for (auto node : m_data) {
        if (node != nullptr) {
            delete node;
            node = nullptr;
        }
    }
    if (m_coloration != nullptr) {
        delete m_coloration;
        m_coloration = nullptr;
    }
}

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
bool Graph<T>::valid_coloration() {
    for (auto node : m_data) {
        for (auto neigh : node->get_neighbors()) {
            if (node->get_color() == neigh->get_color()) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Graph<T>::erase_coloration() {
    delete m_coloration;
    m_coloration = nullptr;
    for (auto node : m_data) {
        node->erase_color();
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

// O(n) + O(x) + O(x) +
// O(n-1) * ( O(n) + O(x) + O(x) + O(v) * O(1) )
// O(n-1) * O(n)
// No pior caso... Grafo completo... O(n^2)
// Complexidade quadratica... Finalmente...
template <typename T>
Coloration<T> *Graph<T>::dsatur() {
    Coloration<T> *coloration = new Coloration<T>();
    int count = m_order;
    // O(n) Passa uma vez por cada node
    Node<T> *great = get_greatest_degree();
    // O(x) Onde x é o numero de cores atualmente sendo usadas
    // No caso, para cores novas é constante
    coloration->add_node(0, great);
    // O(x) dependendo das cores já existentes nos vizinhos
    great->set_color();
    for (auto neigh : great->get_neighbors()) {
        // O(1) get e O(1)
        neigh->update_dsat(great->get_color());
    }
    --count;
    // O(n-1) Passa uma vez por cada node restante
    while (count > 0) {
        // O(n) Onde n é o numero de nodes
        great = get_greatest_satured_degree_not_colored();

        // O(x) dependendo das cores já existentes nos vizinhos
        int color = great->set_color();
        // O(x) Onde x é o numero de cores atualmente sendo usadas
        coloration->add_node(color, great);
        /*
                std::cout << std::endl;
                coloration->print();
                std::cout << std::endl;
        */

        --count;

        // O(v) onde v é o numero de vizinhos do node great
        for (auto neigh : great->get_neighbors()) {
            // O(1) get e O(1)
            neigh->update_dsat(great->get_color());
        }
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
void Graph<T>::print_colors(std::ostream *output) {
    for (auto node : m_data) {
        *output << *node->get_type() << " : " << node->get_color() << std::endl;
    }
}

template <typename T>
void Graph<T>::print_dsat() {
    for (auto node : m_data) {
        std::cout << *node->get_type() << " : " << node->get_dsat()
                  << std::endl;
    }
}
template <typename T>
int Graph<T>::get_degree_no_colored(Node<T> *node) {
    int degree = 0;
    for (auto n : node->get_neighbors()) {
        if (n->get_color() == -1) {
            ++degree;
        }
    }
    return degree;
}