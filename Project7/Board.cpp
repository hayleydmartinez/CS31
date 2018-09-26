//
//  Board.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//
#include <iostream>
#include "Board.h"

namespace cs31
{
    
    Board::Board( )
    {
        // the default Cell constructor will be called on
        // every element of this Board's cell array
    }

    // stringify this Board, turning 0's into    .
    //   and using |s and -s between groups of three rows and columns
    std::string Board::stringify( ) const
    {
        std::string s = "";
        
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {

                s = s + mCells[ i ][ j ].stringify();
                if (j == 3 || j == 6)
                {
                    s = s + "|";
                }
            }
            if (i == 3 || i == 6)
            {
                s = s + "\n-----------";
            }
            s = s + "\n";
        }

        return( s );
    }
    
    // if the value is OKtoSet for the bounding box, row and column
    // of the Cell position specified, then change the corresponding
    // Cell's value to the parameter value and update the Cell's
    // immutability, if desired
    bool Board::acceptValue( int value, int row, int column, bool immutable )
    {
        bool result = false;
        
        NumberSet box = buildBox( row, column );
        NumberSet r = buildRow( row, column );
        NumberSet c = buildColumn( row, column );
        if (mCells[ row ][ column ].isOKToSetValue(value,box,r,c))
        {
            mCells[ row ][ column ].setValue( value );
            result = true;
        }
        if (immutable)
        {
            mCells[ row ][ column ].setImmutable( immutable );
        }
        return( result );
    }
    
    // return true if this Board is completed correctly
    // each cell must have a non-zero value
    // each cell must have a legal value when considering its
    //      row and column and bounding box
    bool Board::completed() const
    {
        // initialize result
        bool result = true;
        
        // per row
        for (int i = 1; i < 10; i++)
        {
            // per column
            for (int j = 1; j < 10; j++)
            {
                // initialize cell, box, row, column and valid value
                int cell = mCells[ i ][ j ].getValue();
                NumberSet box = buildBox( i, j );
                NumberSet row = buildRow( i, j );
                NumberSet column = buildColumn( i, j );
                bool okay = mCells[ i ][ j ].isValueOK( cell, box, row, column );
                
                // check for number in range
                if ( cell < 1 || cell > 9 )
                {
                    result = false;
                    break;
                }
                
                // makes sure everything is true
                result = result && okay;
                
            }
        }
        
        return result;
    }
    
    // for testing purposes, allow for any Board configuration
    //     legal or otherwise
    void Board::cheat()
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                mCells[ i ][ j ].setValue( 3 );
            }
        }
    }
    
    // create the NumberSet associated with the bounding box
    // for the row and column specified
    NumberSet Board::buildBox( int row, int column ) const
    {
        NumberSet set;
        int startingRow = 0, startingColumn = 0;
        int array[8];
        int counter = 0;
        int r = 0, c = 0;
        if (row <= 3)
        {
            startingRow = 1;
        }
        else if (row <= 6)
        {
            startingRow = 4;
        }
        else
        {
            startingRow = 7;
        }
        if (column <= 3)
        {
            startingColumn = 1;
        }
        else if (column <= 6)
        {
            startingColumn = 4;
        }
        else
        {
            startingColumn = 7;
        }
        
        for( int i = 0; i <= 2; i++ )
        {
            r = startingRow + i;
            for (int j = 0; j <= 2; j++)
            {
                c = startingColumn + j;
                if (r == row && c == column)
                {
                    
                }
                else
                {
                    array[ counter ] = mCells[ r ][ c ].getValue();
                    counter = counter + 1;
                }
            }
        }
        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );
        return( set );
    }

    // create the NumberSet associated with the column
    // for the row and column specified
    NumberSet Board::buildColumn( int row, int column ) const
    {
        NumberSet set;
        int array[8];
        int counter = 0;
        
        for( int c = 1; c <= 9; c++ )
        {
            if (c == row)
            {
                
            }
            else
            {
                array[ counter ] = mCells[ c ][ column ].getValue();
                counter = counter + 1;
            }
        }

        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );

        return( set );
    }
    
    // create the NumberSet associated with the row
    // for the row and column specified
    NumberSet Board::buildRow( int row, int column ) const
    {
        NumberSet set;
        int array[8];
        int counter = 0;
        
        for( int i = 1; i <= 9; i++ )
        {
            if (i == column)
            {
                
            }
            else
            {
                array[ counter ] = mCells[ row ][ i ].getValue();
                counter = counter + 1;
            }
        }

        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );

        return( set );
    }

    // the Board evaluation function
    int Board::evaluate() const
    {
        // initialize the score
        int score = 0;
        
        // perfect score for a completed board
        if ( (*this).completed() )
        {
            score = 100;
        }
        
        // if not complete
        else
        {
            // per row
            for (int i = 1; i < 10; i++)
            {
                // per column
                for (int j = 1; j < 10; j++)
                {
                    // initialize cell, box, row, column, valid value
                    int cell = mCells[ i ][ j ].getValue();
                    NumberSet box = buildBox( i, j );
                    NumberSet row = buildRow( i, j );
                    NumberSet column = buildColumn( i, j );
                    bool okay = mCells[ i ][ j ].isValueOK( cell, box, row, column );
                    
                    // if valid value and the cell is not zero, add to the score
                    if (okay && cell != 0)
                    {
                        score += 1;
                    }
                }
            }
        }
        
        return score;
        
    }
    
}
