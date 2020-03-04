#include "token.h"
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

namespace csis3700 {

  token::token(const string& contents) {
    value = contents;
  }

  bool token::is_numeric() const {
      bool digit=false;
      if(isdigit(value[0]))digit=true;
      if(value[0] == '.' && value.length()>1 && isdigit(value[1])) digit=true;
      if (value[0]=='-' && value.length()>1 && isdigit(value[1])) digit=true;
      if (value[0]=='-' && value.length()>1 && value[1]=='.' && isdigit(value[2])) digit=true;
      
      return digit;

    //return isdigit(value[0]) || (value[0] == '.' && isdigit(value[1]));
  }

  double token::as_number() const {
    return atof(value.c_str());
  }

  string token::as_string() const {
    return value;
  }

  int token::arity() const {
    if (strchr("+-*/%^", value[0]) != NULL) return 2;
    if (strchr("!n", value[0]) != NULL) return 1;
    return -1;
  }
  
  int token::precedence() const{
      if (strchr("+-", value[0])!=NULL) return 1;
      if (strchr("*%/", value[0])!=NULL) return 2;
      if (strchr("^", value[0])!=NULL) return 3;
      if (strchr("n", value[0])!=NULL) return 4;
      if (strchr("!", value[0])!=NULL) return 5;
      return -1;
  }
   bool token::is_operator() const{
       if (strchr("+-*%/n!^",value[0])!=NULL) return true;
       return false;
   }
}
