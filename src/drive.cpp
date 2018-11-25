// Copyright 2018 J&JV

/**
 * @file        main.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      Josivan ()
 * @since       02/11/2018
 * @date        20/11/2018
 * @version     0.3
 */

#include "Graph.hpp"

/**
 * @brief Função Principal da aplicação.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char const *argv[]) {
    Graph<Class> g;
    std::string horario = "35M34";
    std::string horario2 = "46M34";

    /*
    Schedule t1(horario);
    Schedule t2(horario2);
    std::cout << t1.intersection(&t2) << std::endl;
    return 1;
    */
    std::string x[] = {"x1", "x2", "x3", "x4", "x5",
                       "x6", "x7", "x8", "x9", "x10"};

    Class c[10];

    for (size_t i = 0; i < 10; ++i) {
        c[i] = Class(x[i], horario);
    }

    g.insert_edge(&c[0], &c[1]);
    g.insert_edge(&c[0], &c[2]);
    g.insert_edge(&c[0], &c[3]);
    g.insert_edge(&c[0], &c[4]);
    g.insert_edge(&c[0], &c[8]);

    g.insert_edge(&c[1], &c[2]);
    g.insert_edge(&c[1], &c[3]);
    g.insert_edge(&c[1], &c[8]);
    g.insert_edge(&c[1], &c[9]);

    g.insert_edge(&c[2], &c[4]);

    g.insert_edge(&c[3], &c[4]);
    g.insert_edge(&c[3], &c[6]);

    g.insert_edge(&c[4], &c[5]);
    g.insert_edge(&c[4], &c[6]);
    g.insert_edge(&c[4], &c[7]);

    g.insert_edge(&c[5], &c[7]);
    g.insert_edge(&c[5], &c[8]);

    g.insert_edge(&c[6], &c[8]);
    g.insert_edge(&c[6], &c[9]);

    g.insert_edge(&c[7], &c[8]);

    g.insert_edge(&c[8], &c[9]);

    g.print();
    Coloration<Class> *coloration = g.get_coloration();
    g.print_colors();
    coloration->print();

    return 0;
}
