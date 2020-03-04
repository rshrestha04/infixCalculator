/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calculator_main.cpp
 * Author: Ronish Shrestha
 *
 * Created on March 27, 2018, 6:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include "Infix_evaluator.h"
#include "tokenizer.h"
#include "token.h"


using namespace std;
using namespace csis3700;
/*
 * 
 */
int main() {
    
    
    
    cout <<" Enter the operation you want to perform:";
    tokenizer TK;
    queue<token> input; 
    input =TK.tokenize(cin);
    
    infix_evaluator Eval;
    double answer =Eval.evaluate(input);
    cout <<"The Result is :"<< answer <<endl; 
    
    
    

    return 0;
}

