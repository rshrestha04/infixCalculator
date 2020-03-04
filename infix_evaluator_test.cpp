/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tokenizer.h"
#include <queue>
#include <string>
#include "postfix_evaluator.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Infix_evaluator.h"
using namespace std;
using namespace csis3700;

TEST_CASE("trying out infix eval","[infix_evaluator]"){
    queue<token> a; 
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
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==13);
    
    
}

TEST_CASE("trying out complex infix eval","[infix_evaluator]"){
    queue<token> a; 
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
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==-5);
    
    
}

TEST_CASE("trying out digits with .","[infix_evaluator]"){
    queue<token> a; 
   
    a.push(token("9"));
    a.push(token("-"));
    a.push(token(".6"));
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==8.4);
    
    
}

TEST_CASE("trying out digits with -.","[infix_evaluator]"){
    queue<token> a; 
   
    a.push(token("-9"));
    a.push(token("+"));
    a.push(token("-.6"));
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==-9.6);
    
    
}

TEST_CASE("trying out digits with ^","[infix_evaluator]"){
    queue<token> a; 
   
    a.push(token("4"));
    a.push(token("^"));
    a.push(token("3"));
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==64);
    
    
}


TEST_CASE("trying out digits with ^ with -","[infix_evaluator]"){
    queue<token> a; 
   
    a.push(token("-4"));
    a.push(token("^"));
    a.push(token("3"));
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==-64);
    
    
}

TEST_CASE("trying out digits with even ^  and with -" ,"[infix_evaluator]"){
    queue<token> a; 
   
    a.push(token("-4"));
    a.push(token("^"));
    a.push(token("2"));
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==16);
    
    
}

TEST_CASE("testin an equation with all operators "){
    queue<token> a; 
   
    a.push(token("-4"));
    a.push(token("^"));
    a.push(token("2"));
    a.push(token("+"));
    a.push(token("3"));
    a.push(token("!"));
    a.push(token("/"));
    a.push(token("("));
    a.push(token("2"));
    a.push(token("*"));
    a.push(token("5"));
    a.push(token(")"));
    a.push(token("+"));
     a.push(token("n"));
    a.push(token("-6"));
    a.push(token("%"));
    a.push(token("2"));
    a.push(token("+"));
    a.push(token("1"));
    
    
    infix_evaluator ee;
    REQUIRE(ee.evaluate(a)==17.6);
    
}



