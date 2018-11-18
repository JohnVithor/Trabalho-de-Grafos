// Copyright 2018 J&JV

/**
 * @file        main.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        02/11/2018
 * @version     0.1
 */

#include "Graph.hpp"

/**
 * @brief Função Principal da aplicação.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char const *argv[]) {
    Graph g;
    std::string horario = "35M34";
    std::string t1 = "c1";
    std::string t2 = "c2";
    std::string t3 = "c3";

    Class c1 = Class(t1, horario);
    Class c2 = Class(t2, horario);
    Class c3 = Class(t3, horario);

    g.insert_edge(c1, c2);
    g.print();

    g.insert_edge(c1, c2);
    g.print();

    g.insert_node(c3);
    g.print();

    g.insert_edge(c3, c3);
    g.print();

    auto coloration = g.get_coloration();
    for (auto color : coloration.get_partitions()) {
        int count = 0;
        for (auto node : color) {
            std::cout << "Cor " << count << ": "
                      << node.get_class().get_subject() << std::endl;
            ++count;
        }
    }
    return 0;
}
