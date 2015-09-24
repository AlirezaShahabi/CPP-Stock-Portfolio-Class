
#include "Portfolio.h"


// friend function definitions
Portfolio operator+(const Portfolio& lhs, const Portfolio& rhs){
    Portfolio temp(lhs);
    return temp += rhs;
}

bool operator==(const Portfolio& lhs, const Portfolio& rhs){
    return (lhs.stocks==rhs.stocks && lhs.total==rhs.total);
}

bool operator!=(const Portfolio& lhs, const Portfolio& rhs){
    return !(lhs==rhs);
}


// constructor
Portfolio::Portfolio(double money):num_share(0),invested(0),
cash(money),total(money) {/* std::map is default initialized */}


// member function definitions
Portfolio& Portfolio::buy(Stock* ps, int n){
    if (cash > n * (ps->price)){
    
        if (stocks.find(ps->sid) == stocks.end()){
            stocks[ps->sid] = std::make_pair(ps,n);
            num_share+= n;
            invested += n * (ps->price);
            cash     -= n * (ps->price);
        }else{
            stocks[ps->sid].second += n;
            num_share+= n;
            invested += n * (ps->price);
            cash     -= n * (ps->price);
        }
        
    }else{
        std::cout << "Not enough cash!" << std::endl;
    }
    return *this;
}


Portfolio& Portfolio::sell(Stock* ps, int n){
    auto it = stocks.find(ps->sid);
    
    if ( it == stocks.end()){
        std::cout << "Not in the portfolio!" << std::endl;
    }else{
        if (n > (it->second).second){
            std::cout << "Not enough stock!" << std::endl;
        }else if(n == (it->second).second){
            stocks.erase(ps->sid);
            num_share-= n;
            invested -= n * (ps->price);
            cash     += n * (ps->price);
        }else{
            stocks[ps->sid].second -= n;
            num_share-= n;
            invested -= n * (ps->price);
            cash     += n * (ps->price);
        }
    }
    return *this;
}


void Portfolio::report(std::ostream& os) const{
    os <<total << " $ is the total money of the portfolio\n";
    os <<cash  << " $ is in cash\n";
    os <<invested <<" $ in " <<num_share <<" stocks: \n";
    for (auto a : stocks){
        os <<(a.second).second <<" share of "<<a.first<<std::endl;
    }
}


Portfolio& Portfolio::operator+=(const Portfolio& rhs){
    for (auto a : rhs.stocks){
        if ( stocks.find(a.first) == stocks.end() ){
            stocks[a.first] = a.second;
        }else{
            stocks[a.first].second += (a.second).second;
        }
    }
    num_share += rhs.num_share;
    invested  += rhs.invested;
    cash      += rhs.cash;
    total     += rhs.total;
    
    return *this;
}

