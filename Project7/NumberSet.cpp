//
//  NumberSet.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "NumberSet.h"

namespace cs31
{
    NumberSet::NumberSet( )
    {
        /* As with the Sudoku board, zero represents an unset value */
        mOne = 0;
        mTwo = 0;
        mThree = 0;
        mFour = 0;
        mFive = 0;
        mSix = 0;
        mSeven = 0;
        mEight = 0;
    }
    
    NumberSet::NumberSet( int one, int two, int three,
                          int four, int five, int six,
                          int seven, int eight )
    {
        mOne = one;
        mTwo = two;
        mThree = three;
        mFour = four;
        mFive = five;
        mSix = six;
        mSeven = seven;
        mEight = eight;
    }

    /* turn this set into string */
    std::string NumberSet::stringify( ) const
    {
        std::string s;
        s = "SET-";
        s += std::to_string( mOne );
        s += std::to_string( mTwo );
        s += std::to_string( mThree );
        s += std::to_string( mFour );
        s += std::to_string( mFive );
        s += std::to_string( mSix );
        s += std::to_string( mSeven );
        s += std::to_string( mEight );
        return( s );
    }
    
    /* return true if the value argument is not                */
    /* one of the eight values found in this NumberSet already */
    /* return false otherwise                                  */
    bool NumberSet::notFound( int value ) const
    {
        // change the number set into a string
        std::string num_set = (*this).stringify();
        
        // no need to check 0-3 because it begins with SET-
        for (int i = 4; i < num_set.size(); i++)
        {
            // isolate the value and the number in the set
            char val = value + '0';
            char num = num_set[i];
            
            // compare values
            if ( num == val )
            {
                return ( false );
            }
        }
        
        return ( true );
    }


}
