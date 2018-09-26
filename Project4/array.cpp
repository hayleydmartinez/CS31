#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



// function declaration
int findMinimum( const string array[ ],int n );
int countAllPunctuation( const string array[ ], int n );
int countFloatingPointValues( const string array[ ],int n );
int removeDuplicatedValues( string array[ ], int n );
int replaceAll( string array1[ ], int n, char letterToReplace, char letterToFill );
int shiftRight( string array[ ], int n, int amount, string placeholder );



int main()
{
    
    //test cases here
    string n[0] = {};
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
    string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
    string c[9] = { "frodo?", "sam...", "merry!", "pippin!?", "gimli.", "legolas-",
        "boromir,", "aragorn'", "gandalf!" };
    string d[4] = { "peter!", "susan!", "edmund!", "lucy!" };
    string e[5] = { "c3p0", "3.33", "bb8", "14.2.4", "r2d2" };
    string f[9] = { "blue", "lily!", "lily!", "blue", "gansey", "adam", "ronan", "noah",
        "henry" };
    string g[6] = { "harry", "hermione", "ron", "luna", "ginny", "neville" };
    string h[10] = { "&12940", "1214.354", "...1241", "1/2", "333.", "1423", ".", "1259000",
        "b", "1.2" };
    string i[5] = { "ac", "aa", "ab", "aaa", ""};
    string j[6] = { "1", ".3", "..", "1.1.", "1.", "3.1" };
    
    assert(findMinimum(n,  0) == -1);
    assert(findMinimum(a,  6) ==  0);
    assert(findMinimum(a, -1) == -1);
    assert(findMinimum(b,  6) ==  3);
    assert(findMinimum(c,  9) ==  7);
    assert(findMinimum(d,  4) ==  2);
    assert(findMinimum(e,  5) ==  3);
    assert(findMinimum(f,  9) ==  5);
    assert(findMinimum(g,  4) == 0);
    assert(findMinimum(h, 10) ==  0);
    assert(findMinimum(i,  5) ==  4);
    assert(findMinimum(i,  4) ==  1);
    assert(countAllPunctuation(n,  0) == -1);
    assert(countAllPunctuation(a,  6) ==  0);
    assert(countAllPunctuation(a, -4) == -1);
    assert(countAllPunctuation(b,  6) ==  0);
    assert(countAllPunctuation(c,  9) == 12);
    assert(countAllPunctuation(d,  4) ==  4);
    assert(countAllPunctuation(e,  5) ==  3);
    assert(countAllPunctuation(f,  9) ==  2);
    assert(countAllPunctuation(h, 10) ==  8);
    assert(countFloatingPointValues(n,  0) == -1);
    assert(countFloatingPointValues(a,  6) ==  0);
    assert(countFloatingPointValues(a, -1) == -1);
    assert(countFloatingPointValues(e,  5) ==  1);
    assert(countFloatingPointValues(h, 10) ==  5);
    assert(countFloatingPointValues(j,  6) ==  4);
    assert(removeDuplicatedValues(n,  0) == -1);
    assert(removeDuplicatedValues(a,  6) ==  2 && a[5] == "");
    assert(removeDuplicatedValues(a, -1) == -1);
    assert(removeDuplicatedValues(b,  6) ==  2 && b[4] == "");
    assert(removeDuplicatedValues(c,  9) ==  0 && c[1] == "sam...");
    assert(replaceAll(n, 0, 'e', '?') == -1);
    assert(replaceAll(d, -1, 'e', '?') == -1 && d[0] == "peter!");
    assert(replaceAll(e,  5, '.', '-') ==  3 && e[1] == "3-33");
    assert(replaceAll(f,  9, 'a', 'q') ==  5 && f[5] == "qdqm");
    assert(shiftRight(n,  0, 4, "") == -1);
    assert(shiftRight(g,  6, 4, "draco") ==  4 && g[3] == "draco");
    assert(shiftRight(h, 10, 1, "3") ==  1 && h[1] == "&12940");
    assert(shiftRight(i, -9, 1, "b") == -1  && i[1] == "aa");
    
    cerr << "WE OUT HERE!!!" << endl;
    
    return 0;
    
}



// actual functions
int findMinimum( const string array[ ], int n )
{
    int min = 0;
    
    if (n > 0)
    {
        string smallest = array[0];
        
        for ( int i = 1; i < n; i++ )
        {
            if (array[i] < smallest)
            {
                smallest = array[i];
                min = i;
            }
        }
    }
    
    else
        min = -1;
    
    return min;
}


int countAllPunctuation( const string array[ ], int n )
{
    int punctuation = 0;
    
    if (n > 0)
    {
        for ( int i = 0; i < n; i++ )
        {
            string value = array[i];
            size_t len = value.size();
            
            for ( int j = 0; j < len; j++ )
            {
                char ch = value[j];
                
                switch(ch)
                {
                    case '.':
                    case ',':
                    case '!':
                    case ';':
                    case '\'':
                    case '-':
                    case '/':
                    case ':':
                    case '?':
                    case '"':
                        punctuation = punctuation + 1;
                        break;
                }
            }
        }
    }
    
    else
        punctuation = -1;
    
    return punctuation;
}


int countFloatingPointValues( const string array[ ],int n )
{
    int fpn = 0;
    
    if (n > 0)
    {
    
        for ( int i = 0; i < n; i++ )
        {
            string num = array[i];
            size_t len = num.size();
            int points = 0;
            bool valid = true;
            
            for ( int j = 0; j < len; j++ )
            {
                char ch = num[j];
                
                if (ch == '.' && num.size() > 1)
                    points++;
                
                else if (ch < '0' || ch > '9')
                {
                    valid = false;
                    break;
                }
            }
            
            if ( valid && points < 2 )
                fpn++;
        }
    }
    
    else
        fpn = -1;
    
    return fpn;
}


int removeDuplicatedValues( string array[ ], int  n )
{
    int dups = 0;
    
    if ( n > 0 )
    {
        for ( int i = 0; i < n - 1; i++ )
        {
            for ( int j = i + 1; j < n; j ++)
            {
                if (array[i] == array[j])
                {
                    array[i] = "";
                    dups++;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (array[j] != "" && dups > 0)
                {
                    array[i] = array[j];
                    array[j] = "";
                }
        }
    }
    
    else
        dups = -1;
    
    return dups;
}


int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill )
{
    int replaced = 0;
    
    if ( n > 0 )
    {
        
        for (int i = 0; i < n; i++)
        {
            size_t len = array[i].size();
            
            for (int j = 0; j < len; j++)
            {
                if (array[i][j] == letterToReplace)
                {
                    array[i][j] = letterToFill;
                    replaced++;
                }
            }
        }
    }
    
    else
        replaced = -1;
    
    return replaced;
}


int shiftRight( string array[ ], int n, int amount, string placeholder )
{
    int val = 0;
    
    if (n > 0 && amount > 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (i - amount >= 0)
                array[i] = array[i - amount];
            else
            {
                array[i] = placeholder;
                val++;
            }
        }
    }
    
    else
        val = -1;
    
    return val;
}
