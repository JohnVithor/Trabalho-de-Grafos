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

#include "Graph.hpp"
#include "GraphReader.hpp"

/**
 * @brief Função Principal da aplicação.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cout << "Modo de uso:" << std::endl
                  << "./DSAT caminho/nome.col" << std::endl
                  << "Para Salvar em arquivo por favor use redirecionamento '>'"
                  << std::endl
                  << "Exemplo: ./DSAT caminho/nome.col > saida.txt"
                  << std::endl;
        return -1;
    }
    std::string archive(argv[1]);
    GraphReader gr("Casos de testes para coloração/optimal_coloring.txt");

    auto g = gr.get_graph(archive);
    if (g != nullptr) {
        std::cout << "Arquivo: " << archive << " carregado." << std::endl;
        // g->print();

        auto c = g->get_coloration();
        // c->print();

        if (g->valid_coloration()) {
            std::cout << "Coloração válida encontrada!" << std::endl;
        } else {
            std::cout << "Coloração inválida encontrada...!" << std::endl;
        }

        std::cout << "Número Cromático Encontrado: "
                  << c->get_chromatic_number()
                  << std::endl
                  // << "Número Cromático Esperado: "
                  // << Usar a biblioteca em python seria interessante
                  << "Número Cromático Ótimo: "
                  << gr.get_optimal_coloring_number("myciel3.col") << std::endl;
        return 0;
    }
    std::cout << "Arquivo não encontrado. Abortando programa." << std::endl;
    return -1;
}
