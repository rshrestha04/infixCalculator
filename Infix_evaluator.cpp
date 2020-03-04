/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "postfix_evaluator.h"
#include "infix_converter.h"
#include "token.h"
#include "Infix_evaluator.h"
#include <queue>



namespace csis3700{
    double infix_evaluator::evaluate(std::queue<token> infix){
        infix_converter infconverter;
        postfix_evaluator post_eval;
        std::queue<token> postfix;
        postfix =infconverter.convert_to_postfix(infix);
        return post_eval.evaluate(postfix);
        
    }
}

