#ifndef APPLESTORE_H
#define APPLESTORE_H

#include <iostream>
#include <string>
#include "AppleProduct.h"

// declare namespace
namespace cs31
{
    // create class AppleStore
    class AppleStore
    {
    public:
        // constructor
        AppleStore();
        
        // member functions
        // watch functions
        AppleProduct buyWatch1( std::string color );
        AppleProduct buyWatch3( std::string color );
        
        // iPad functions
        AppleProduct buyiPad( std::string color, int gigabytes );
        AppleProduct buyiPadPro( std::string color, int gigabytes );
        
        // iPhone functions
        AppleProduct buyiPhoneX( std::string color, int gigabytes );
        AppleProduct buyiPhone8( std::string color, int gigabytes );
        AppleProduct buyiPhone8Plus( std::string color, int gigabytes );
        
    };
}

#endif 
