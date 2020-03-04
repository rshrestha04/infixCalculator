#include "tokenizer.h"
#include <queue>
#include <string>
#include "postfix_evaluator.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;
using namespace csis3700;

TEST_CASE("construct", "postfix_evaluator") {
  postfix_evaluator e;
}

TEST_CASE("empty_evaluates_to_zero", "postfix_evaluator") {
  postfix_evaluator e;
  queue<token> queue;
  REQUIRE(e.evaluate(queue)==0);
}

TEST_CASE("number_evaluates_to_number", "postfix_evaluator") {
  postfix_evaluator e;
  queue<token> q;
  q.push(token("1"));
  REQUIRE(e.evaluate(q)==1.0);
}

TEST_CASE("can_add", "postfix_evaluator") {
  postfix_evaluator e;
  queue<token> q;
  q.push(token("9"));
  q.push(token("13"));
  q.push(token("+"));
  REQUIRE(e.evaluate(q)==22.0);
}

TEST_CASE("can_multiply", "postfix_evaluator") {
  postfix_evaluator e;
  queue<token> q;
  q.push(token("2"));
  q.push(token("13"));
  q.push(token("*"));
  REQUIRE(e.evaluate(q)==26.0);
}

TEST_CASE("can_deivide","postfix_evaluator"){
    postfix_evaluator b;
    queue <token> q;
    q.push(token("12"));
    q.push(token("4"));
    q.push(token("/"));
    REQUIRE(b.evaluate(q)==3);
    
}

TEST_CASE("can_subtract","postfix_evaluator"){
    postfix_evaluator b;
    queue <token> q;
    q.push(token("12"));
    q.push(token(".4"));
    q.push(token("-"));
    REQUIRE(b.evaluate(q)==11.6);
    
}


TEST_CASE("can_negate","postfix_evaluator"){
    postfix_evaluator b;
    queue <token> q;
    q.push(token("-4"));
    q.push(token("n"));
    REQUIRE(b.evaluate(q)==4);
    
  
    
    
}

TEST_CASE("can_give_remender","postfix_evaluator"){
    postfix_evaluator b;
    queue <token> q;
    q.push(token("13"));
    q.push(token("4"));
    q.push(token("%"));
    REQUIRE(b.evaluate(q)==1);
   
    
}

TEST_CASE("can produce power","[postfix_evaluator]"){
    postfix_evaluator c;
    queue<token> a;
    a.push(token("12"));
    a.push(token("2"));
    a.push(token("^"));
    REQUIRE(c.evaluate(a)==144);
    
    
}

TEST_CASE("can produce factorial","[postfix_evaluator]"){
    postfix_evaluator c;
    queue<token> a;
    
    a.push(token("4"));
    a.push(token("!"));
    REQUIRE(c.evaluate(a)==24);
    
}

TEST_CASE("can operate .","[postfix_evaluator]"){
    postfix_evaluator c;
    queue<token> a;
    
    a.push(token("4"));
    
    a.push(token(".1"));
    a.push(token("/"));
    REQUIRE(c.evaluate(a)==40);
    
}

TEST_CASE("can operate . and -","[postfix_evaluator]"){
    postfix_evaluator c;
    queue<token> a;
    
    a.push(token("4"));
    
    a.push(token("-.1"));
    a.push(token("/"));
    REQUIRE(c.evaluate(a)==-40);
    
}



