// Copyright 2018 J&JV

/**
 * @file        GraphReader.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       22/11/2018
 * @date        22/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_GRAPHREADER_HPP_
#define INCLUDE_GRAPHREADER_HPP_

#include <fstream>
#include <map>
#include <sstream>
#include <string>

#include "Integer.hpp"
#include "Graph.hpp"

class GraphReader {
   public:
    GraphReader(std::string data_base);
    GraphReader(GraphReader &&) = default;
    GraphReader(const GraphReader &) = default;
    GraphReader &operator=(GraphReader &&) = default;
    GraphReader &operator=(const GraphReader &) = default;
    ~GraphReader();

    Graph<Integer> *get_graph(std::string file_name);
    int get_optimal_coloring_number(std::string file_name);

   private:
    std::map<std::string, int> m_optimal_coloring_numbers;
};

#endif  // INCLUDE_GRAPHREADER_HPP_
