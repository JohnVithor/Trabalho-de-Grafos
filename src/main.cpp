// Copyright 2018 J&JV

/**
 * @file        main.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        20/11/2018
 * @version     0.3
 */

#include "GraphReader.hpp"
#include "Graph.hpp"

/**
 * @brief Função Principal da aplicação.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char const *argv[]) {
    // TODO(Someone): Montar a interface do programa para carregar os casos de
    // teste a partir de arquivos e guardar num arquivo o resultado.

    GraphReader gr("Casos de testes para coloração/optimal_coloring.txt");
    auto g = gr.get_graph("Casos de testes para coloração/myciel3.col");
    auto c = g->get_coloration();

    g->print();
    g->print_colors();
    std::cout << gr.get_optimal_coloring_number("myciel3.col") << std::endl;
    return 0;
}
