
#include <map>
#include <iostream>
#include "Stock.h"

class Portfolio{

friend Portfolio operator+(const Portfolio&, const Portfolio&);
friend bool     operator==(const Portfolio&, const Portfolio&);
friend bool     operator!=(const Portfolio&, const Portfolio&);

public:
    Portfolio(double);
    // other copy-control operators are default created
    
    Portfolio& buy(Stock*, int);
    Portfolio& sell(Stock*, int);
    void report(std::ostream&) const;
    
    Portfolio& operator+=(const Portfolio&);
    
private:
    std::map<std::string, std::pair<Stock*,int>> stocks;
    int num_share;
    double invested, cash, total;
};
