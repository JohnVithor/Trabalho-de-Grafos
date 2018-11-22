// Copyright 2018 J&JV

/**
 * @file        GraphReader.cpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       22/11/2018
 * @date        22/11/2018
 * @version     0.1
 */

#include "GraphReader.hpp"

GraphReader::GraphReader(std::string data_base) {
    std::ifstream file;
    file.open(data_base);
    if (file.is_open()) {
        std::string line;
        // linha que indica aos humanos como interpretar os dados
        std::getline(file, line);
        // linha em branco que indica o inicio dos dados
        std::getline(file, line);
        while (!file.eof()) {
            // Exemplo de linha: DSJC1000.1.col.b (1000,99258), ?, DSJ
            std::getline(file, line);

            std::size_t ini_pos = line.find(" ");
            std::string name = line.substr(0, ini_pos);

            ini_pos = line.find(", ");
            std::string aux = line.substr(ini_pos + 2);
            std::size_t end_pos = aux.find(", ");
            std::string result = aux.substr(0, end_pos);
            try {
                std::stringstream ss(result);
                int ocn;
                ss >> ocn;
                m_optimal_coloring_numbers[name] = ocn;
            } catch (const std::exception &) {
            }
        }
    }
    file.close();
}

GraphReader::~GraphReader() {}

Graph<int> *GraphReader::get_graph(std::string file_name) {
    /* Exemplo de linhas:
c FILE: huck.col
c Translated from Stanford GraphBase File: huck.gb
c Stanford GraphBase ID: book(?huck?,74,0,1,43,0,0,0)
p edge 74 602
e 1 44
e 1 4
    */
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        Graph<int> *graph = new Graph();
        std::string line;

        do {
            std::getline(file, line);
        } while (line[0] == 'c');
        if (line[0] == 'p') {
            std::getline(file, line);
        }
        while (!file.eof()) {
            std::size_t pos = line.find(" ");
            pos = line.substr(pos + 1).find(" ");
            std::string aux = line.substr(pos);
            pos = line.find(" ");
            std::string source = aux.substr(0, pos);
            std::string target = aux.substr(pos);

            try {
                std::stringstream sss(source);
                std::stringstream sst(target);
                int s;
                int t;
                sss >> s;
                sst >> t;
            } catch (const std::exception &) {
            }
        }
        file.close();
        return graph;
    } else {
        // file.close();
        return nullptr;
    }
}

int GraphReader::get_optimal_coloring_number(std::string file_name) {
    return m_optimal_coloring_numbers[file_name];
}