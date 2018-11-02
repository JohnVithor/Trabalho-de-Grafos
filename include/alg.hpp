// Copyright 2018 J&JV

/**
 * @file        alg.hpp
 * @brief       ...
 *
 * @author      João Vítor (jv.venceslau.c@gmail.com)
 * @author      ...
 * @since       02/11/2018
 * @date        02/11/2018
 * @version     0.1
 */

#ifndef INCLUDE_ALG_HPP_
#define INCLUDE_ALG_HPP_

/**
 * @brief ...
 * 
 */
class Graph {
   public:
    Graph();
    Graph(Graph &&) = default;
    Graph(const Graph &) = default;
    Graph &operator=(Graph &&) = default;
    Graph &operator=(const Graph &) = default;
    ~Graph();

   private:
};



#endif  // INCLUDE_ALG_HPP_
