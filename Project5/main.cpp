#include <iostream>
#include <string>
#include <cassert>

#include "AppleStore.h"
#include "AppleProduct.h"

int main()
{
    using namespace std;
    using namespace cs31;
    
    cout.setf( ios::fixed );
    cout.setf( ios::showpoint );
    cout.precision( 2 );
    
    AppleProduct p;
    assert( p.getCost() == 0.0);
    assert( p.getKind() == AppleProduct::Kind::NOTSPECIFIED );
    assert( p.getColor() == "" );
    assert( p.getVersion() == "" );
    
    AppleProduct p1( AppleProduct::Kind::IPHONE, "8", "Grey", 849.00 );
    assert( p1.getCost() == 849.00 );
    assert( p1.getKind() == AppleProduct::Kind::IPHONE );
    assert( p1.getColor() == "Grey" );
    assert( p1.getVersion() == "8" );
    
    AppleProduct p2( AppleProduct::Kind::IPAD, "Pro", "Rose", 799.00);
    assert( p2.getCost() == 799.00 );
    assert( p2.getKind() == AppleProduct::Kind::IPAD );
    assert( p2.getColor() == "Rose" );
    assert( p2.getVersion() == "Pro" );
    
    AppleStore s;
    AppleProduct w1 = s.buyWatch1("Blue");
    assert( w1.getColor() == "Blue" );
    
    AppleStore s1;
    AppleProduct w2 = s1.buyWatch3("Pink");
    assert( w2.getColor() == "Pink" );
    
    AppleStore s3;
    AppleProduct ipad = s1.buyiPad("Gold", 32 );
    assert( ipad.getColor() == "Gold" );
    assert( ipad.getCost() == 329.00 );
    
    AppleStore s4;
    AppleProduct ipad2 = s4.buyiPad("Green", 128 );
    assert( ipad2.getColor() == "Green" );
    assert( ipad2.getCost() == 429.00 );
    
    AppleStore s5;
    AppleProduct ipadp = s5.buyiPadPro("Orange", 64 );
    assert( ipadp.getColor() == "Orange" );
    assert( ipadp.getCost() == 649.00 );
    
    try
    {
        cs31::AppleStore e1;
        cs31::AppleProduct iphone8 = e1.buyiPhone8( "Space", 9999 );
        assert( false );
        
    } catch( std::logic_error ) {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore e2;
        cs31::AppleProduct iphonex = e2.buyiPhoneX( "White", 390 );
        assert( false );
        
    } catch( std::logic_error ) {
        assert( true );
    }
    
    try
    {
        cs31::AppleStore e3;
        cs31::AppleProduct iphone8p = e3.buyiPhone8Plus("Purple", 1290 );
        assert( false );
    } catch( std:: logic_error ) {
        assert( true );
    }
    
    cerr << "WE OUT HERE!!!" << endl;
    
    return 0;
}
