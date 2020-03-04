/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infix_evaluator.h
 * Author: Ronish Shrestha
 *
 * Created on March 27, 2018, 2:29 PM
 */

#ifndef INFIX_EVALUATOR_H
#define INFIX_EVALUATOR_H

#include "token.h"
#include <queue>
#include <stack>

namespace csis3700{
    class infix_evaluator{
        public:
            double evaluate(std::queue<token> infix);
        private:
    };
}



#endif /* INFIX_EVALUATOR_H */

