// Copyright 2018 J&JV

/**
 * @file        main.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      Josivan ()
 * @since       02/11/2018
 * @date        25/11/2018
 * @version     0.4
 */

#include <unistd.h>
#include <iostream>
#include "Graph.hpp"
#include "GraphReader.hpp"

/**
 * @brief Função Principal da aplicação.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Modo de uso:" << std::endl
                  << "./DSAT -i caminho/nome.col" << std::endl
                  << "Para salvar resultado em arquivo existem duas opções: "
                  << std::endl
                  << "1 - ./DSAT -i caminho/nome.col -o destino" << std::endl
                  << "2 - ./DSAT -i caminho/nome.col >> destino" << std::endl
                  << "Para salvar resultados como CSV inclua a flag -m"
                  << std::endl;
        //<< "flags"

        return -1;
    }

    bool m_flag = false;
    std::string i_file = "";
    std::string o_file = "";
    int c;
    std::ostream *saida = &std::cout;
    opterr = 0;

    while ((c = getopt(argc, argv, "mi:o:")) != -1) switch (c) {
            case 'm':
                m_flag = true;
                break;
            case 'i':
                i_file = optarg;
                break;
            case 'o':
                o_file = optarg;
                break;
            case '?':
                if (optopt == 'i' || optopt == 'o')
                    std::cerr << "Option -" << optopt
                              << " requires an argument." << std::endl;
                else if (isprint(optopt))
                    std::cerr << "Unknown option `-" << optopt << "'."
                              << std::endl;
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n",
                            optopt);
                return -1;
            default:
                abort();
        }
    if (o_file != "") {
        std::ofstream output_file;
        output_file.open(o_file);
        if (output_file.fail()) {
            std::cout << "Arquivo: " << o_file << "não foi aberto."
                      << std::endl;
        } else {
            saida = &output_file;
        }
    }
    GraphReader gr("Test_cases/optimal_coloring.txt");

    auto g = gr.get_graph(i_file);
    if (g != nullptr) {
        if (!m_flag) {
            *saida << "Arquivo: " << i_file << " carregado." << std::endl;
        }

        // g->print();

        auto c = g->get_coloration();
        // c->print();
        if (!g->valid_coloration()) {
            std::cerr << "Coloração inválida encontrada!" << std::endl
                      << "Arquivo: " << i_file << std::endl;
        }
        if (m_flag) {
            *saida << c->get_chromatic_number() << ";"
                   << gr.get_optimal_coloring_number("myciel3.col");
        } else {
            *saida << "Número Cromático Encontrado: "
                   << c->get_chromatic_number() << std::endl
                   << "Número Cromático Ótimo: "
                   << gr.get_optimal_coloring_number("myciel3.col")
                   << std::endl;
        }
        return 0;
    }
    std::cerr << "Arquivo não encontrado. Abortando programa." << std::endl;
    return -1;
}
