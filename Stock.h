
#include <string>

class Stock{

friend class Portfolio;

public:
    Stock(std::string, double);
private:
    std::string sid;
    double price;
};

