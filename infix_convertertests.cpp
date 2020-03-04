/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "infix_converter.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "token.h"
#include <stack>
#include <cmath>
#include "postfix_evaluator.h"

using namespace csis3700;


TEST_CASE("testing a simple equation","[sequence]"){
    std::queue<token> a;
    std::queue<token> result;
    a.push(token("3"));
    a.push(token("+"));
    a.push(token("4"));
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==7);
    
    
}

TEST_CASE("testing a simple equation with brakets","[sequence]"){
    std::queue<token> a;
    std::queue<token> result;
    a.push(token("("));
    a.push(token("1"));
    a.push(token("+"));
    a.push(token("2"));
    a.push(token(")"));
    a.push(token("+"));
    a.push(token("("));
    a.push(token("4"));
    a.push(token("+"));
    a.push(token("6"));
    a.push(token(")"));
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==13);
    
    
}


TEST_CASE("testing a precedence","[sequence]"){
    std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("5"));
    a.push(token("*"));
    a.push(token("8"));
    a.push(token("+"));
    a.push(token("6"));
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==46);
    
    
}

TEST_CASE("testing a precedence with complex operators","[sequence]"){
    std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("4"));
    a.push(token("+"));
    a.push(token("9"));
    a.push(token("-"));
    a.push(token("6"));
    a.push(token("*"));
    a.push(token("4"));
    a.push(token("!"));
    a.push(token("/"));
    a.push(token("8"));
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==-5);
    
    
}

TEST_CASE("testing values with . "){
     std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("4"));
    a.push(token("+"));
    a.push(token(".9"));
   
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==4.9);
    
    
}

TEST_CASE("testing values with . and signs "){
     std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("4"));
    a.push(token("+"));
    a.push(token("-.9"));
   
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==3.1);
    
    
}


TEST_CASE("testing values with ^ "){
     std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("4"));
    a.push(token("+"));
    a.push(token("-9"));
    a.push(token("^"));
    a.push(token("2"));
   
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==85);
    
    
}

TEST_CASE("testing values with ^ and precedence "){
     std::queue<token> a;
    std::queue<token> result;
    
    a.push(token("-9"));
    a.push(token("^"));
    a.push(token("2"));
    a.push(token("+"));
    a.push(token("4"));
   
   
    infix_converter con;
    
    postfix_evaluator evval;
    result=con.convert_to_postfix(a);
    REQUIRE(evval.evaluate(result)==85);
    
    
}

