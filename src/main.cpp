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
    std::string t1 = "c1";
    std::string test1 = "35M34";

    std::string t2 = "c2";
    std::string test2 = "35M34";

    Class c1 = Class(t1, test1);
    Class c2 = Class(t2, test2);
    g.insert_edge(c1,c2);
    g.print();

    return 0;
}
