#include "AppleStore.h"
#include "AppleProduct.h"

// NOTE: not using namespace std, therefore must add the prefix
// declare namespace
namespace cs31
{
    // constructor
    AppleStore::AppleStore()
    {
        // blank because it does not input variables
    }
    
    // watch functions
    AppleProduct AppleStore::buyWatch1( std::string color )
    {
        // returns a Watch 1 with specified color
        return AppleProduct( AppleProduct::Kind::WATCH, "1", color, 249.00 );
    }
    
    AppleProduct AppleStore::buyWatch3( std::string color )
    {
        // returns a Watch 3 with specified color
        return AppleProduct( AppleProduct::Kind::WATCH, "3", color, 329.00 );
    }
    
    // iPad functions
    AppleProduct AppleStore::buyiPad( std::string color, int gigabytes )
    {
        // initializes cost
        double cost = 0.0;
        
        // checks valid gigabytes and assigns cost
        if (gigabytes == 32)
            cost = 329.00;
        else if (gigabytes == 128)
            cost = 429.00;
        else
        {
            std::logic_error error("Invalid.");
            throw(error);
        }
        
        // returns an iPad with specified color and cost
        return AppleProduct( AppleProduct::Kind::IPAD, "", color, cost );
    }
    
    AppleProduct AppleStore::buyiPadPro( std::string color, int gigabytes )
    {
        // initializes cost
        double cost = 0.0;
        
        // checks valid gigabytes and assigns cost
        if (gigabytes == 64)
            cost = 649.00;
        else if (gigabytes == 256)
            cost = 799.00;
        else if (gigabytes == 512)
            cost = 999.00;
        else
        {
            std::logic_error error("Invalid.");
            throw(error);
        }
        
        // returns an iPad Pro with specified color and cost
        return AppleProduct( AppleProduct::Kind::IPAD, "Pro", color, cost );
    }
    
    // iPhone functions
    AppleProduct AppleStore::buyiPhone8( std::string color, int gigabytes )
    {
        //initializes cost
        double cost = 0.0;
        
        // checks valid gigabytes and assigns cost
        if (gigabytes == 64)
            cost = 699.00;
        else if (gigabytes == 256)
            cost = 849.00;
        else
        {
            std::logic_error error("Invalid.");
            throw(error);
        }
        
        // returns an iPhone 8 with specified color and cost
        return AppleProduct( AppleProduct::Kind::IPHONE, "8", color, cost );
    }
    
    AppleProduct AppleStore::buyiPhone8Plus( std::string color, int gigabytes )
    {
        // initializes cost
        double cost = 0.0;
        
        // checks valid gigabytes and assigns cost
        if (gigabytes == 64)
            cost = 799.00;
        else if (gigabytes == 256)
            cost = 949.00;
        else
        {
            std::logic_error error("Invalid.");
            throw(error);
        }
        
        // returns an iPhone 8 Plus with specified color and cost
        return AppleProduct( AppleProduct::Kind::IPHONE, "8Plus", color, cost );
    }
    
    AppleProduct AppleStore::buyiPhoneX( std::string color, int gigabytes )
    {
        // initializes cost
        double cost = 0.0;
        
        // checks valid gigabytes and assigns cost
        if (gigabytes == 64)
            cost = 999.00;
        else if (gigabytes == 256)
            cost = 1149.00;
        else
        {
            std::logic_error error("Invalid.");
            throw(error);
        }
        
        // returns an iPhone X with specified color and cost
        return AppleProduct( AppleProduct::Kind::IPHONE, "X", color, cost );
    }
}
