
#include "Portfolio.h"


int main(){

    Stock s1("BOA",16.76),s2("APPL",105.04),s3("MSFT",65);
    Stock s4("BABA",55.3),s5("AMZN",123.57),s6("JPM",52.9);
    
    Portfolio p1(100000);
    p1.buy(&s1, 400).buy(&s3, 100).buy(&s5, 200);
    p1.sell(&s1, 100).buy(&s2, 200).sell(&s5, 100);
    
    p1.report(std::cout);
    std::cout << std::endl;
    
    Portfolio p2(58000);
    p2.buy(&s4, 200).buy(&s5, 100).buy(&s6, 500);
    
    p2.report(std::cout);
    std::cout << std::endl;
    
    bool comp = p1==p2;
    std::cout << "portfolio p1 and p2 are equal: "<< \
    comp << std::endl;
    
    Portfolio p3(0);
    p3 = p1 + p2;
    p3.report(std::cout);
    
    return 0;
}