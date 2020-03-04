/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   infix_converter.h
 * Author: Ronish Shrestha
 *
 * Created on March 23, 2018, 10:29 PM
 */

#ifndef INFIX_CONVERTER_H
#define INFIX_CONVERTER_H

#include "token.h"

#include <stack>
#include <string>
#include <queue>

namespace csis3700{
    class infix_converter{
        public:
            std::queue<token> convert_to_postfix(std::queue<token> infix);
        private:
        
    };
}



#endif /* INFIX_CONVERTER_H */

