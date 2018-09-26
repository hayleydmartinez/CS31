s#ifndef APPLEPRODUCT_H
#define APPLEPRODUCT_H

#include <iostream>
#include <string>

// NOTE: not using namespace std, therefore must add the prefix
// declare namespace
namespace cs31
{
    // create class AppleProduct
    class AppleProduct
    {
    public:
        // create Kind
        enum Kind { NOTSPECIFIED, IPHONE, IPAD, WATCH };
        
        // constructors
        AppleProduct();
        AppleProduct( Kind kind, std::string version, std::string color, double cost );
        
        // member functions
        std::string getVersion() const;
        std::string getColor() const;
        Kind getKind() const;
        double getCost() const;
        
    private:
        // member variables
        std::string mVersion, mColor;
        Kind mKind;
        double mCost;
    };
}

#endif
