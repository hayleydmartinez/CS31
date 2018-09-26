#include "AppleProduct.h"

// NOTE: not using namespace std, therefore must add the prefix
// declare namespace 
namespace cs31
{
    // default constructor
    AppleProduct::AppleProduct()
    {
        mVersion = "";
        mColor = "";
        mKind = AppleProduct::Kind::NOTSPECIFIED;
        mCost = 0.0;
    }
    
    // main constructor
    AppleProduct::AppleProduct( AppleProduct::Kind kind, std::string version, std::string color, double cost )
    {
        mVersion = version;
        mColor = color;
        mKind = kind;
        mCost = cost;
    }
    
    // member functions
    std::string AppleProduct::getVersion() const
    {
        return mVersion;
    }

    std::string AppleProduct::getColor() const
    {
        return mColor;
    }

    AppleProduct::Kind AppleProduct::getKind() const
    {
        return mKind;
    }

    double AppleProduct::getCost() const
    {
        return mCost;
    }

}





