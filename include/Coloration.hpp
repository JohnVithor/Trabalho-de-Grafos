// Copyright 2018 J&JV

/**
 * @file        Coloration.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       04/11/2018
 * @date        04/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_COLORATION_HPP_
#define INCLUDE_COLORATION_HPP_

/**
 * @brief ...
 *
 */
class Coloration {
   public:
    Coloration();
    Coloration(Coloration &&) = default;
    Coloration(const Coloration &) = default;
    Coloration &operator=(Coloration &&) = default;
    Coloration &operator=(const Coloration &) = default;
    ~Coloration();

    std::forward_list<std::forward_list<Node>> *get_partitions();
    int get_chromatic_number();
    bool is_valid();

   private:
    Graph *m_graph = nullptr;
    std::forward_list<std::forward_list<Node>> *m_partitions = nullptr;

    int chromatic_number = 0;
};

#endif  // INCLUDE_COLORATION_HPP_
