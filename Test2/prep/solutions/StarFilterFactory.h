#pragma once
#include "StarFilter.h"

class StarFilterFactory
{
public:
    /* това може да бъде изнесено и в класа StarFilter и се получава т.нар 
    * static factory метод вътре в самия клас. Въпрос на стил е дали ще се изнесе в отделен клас като този,
    но ако можете, напишете Factory клас за този Design Pattern*/
    static std::unique_ptr<StarFilter> create(const std::string& type);

};

