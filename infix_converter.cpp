/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "infix_converter.h"
#include "token.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace csis3700;

namespace csis3700{
     std::queue<token> infix_converter::convert_to_postfix(std::queue<token> infix){
     
            std::stack<token> opstack;
            std::queue<token> poststack;
            opstack.push(token("("));
            
            
            if(infix.empty()) return poststack;
            infix.push(token(")"));
            
            
           
         while(!infix.empty()){
             token current_token =infix.front();
             infix.pop();
             if (current_token.is_numeric())poststack.push(current_token);
             
             else if(current_token.as_string()=="(") 
               opstack.push(token(current_token));
             else if (current_token.as_string()==")"){
             
             while (opstack.top().as_string()!="("){
                     poststack.push(opstack.top());
                     opstack.pop();
                }
             opstack.pop();
            }
             
             else if(current_token.is_operator()){
                 
                while(opstack.top().as_string()!="(" && opstack.top().precedence()>=current_token.precedence()){
                    poststack.push(opstack.top());
                    opstack.pop();
                    
                }
            opstack.push(current_token);
             }
             
         }
             
          //   while(opstack.top().as_string()!="("){
          //       poststack.push(opstack.top());
          //       opstack.pop();
                 
          //   }
             
          //   opstack.pop();
             
             
            
             
             
             
             
         
            
        return poststack;
     }
}
