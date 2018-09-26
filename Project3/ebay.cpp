#include <cassert>
#include <iostream>
using namespace std;




// function declaration
bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);




int main()
{
    
    assert(isValidEbayListingString("L99B50WB+10UWB+40W"));
    assert(isValidEbayListingString("l99b50wb+10uwb+40w"));
    assert(isValidEbayListingString("L100B99"));
    assert(isValidEbayListingString("L100B50WWWWWWW"));
    assert(isValidEbayListingString("L100B50WUWUWUWWWWW"));
    assert(isValidEbayListingString("L100B50WWUUB+10WWUU"));
    assert(isValidEbayListingString("L100W"));
    assert(isValidEbayListingString("L100WU"));
    assert(isValidEbayListingString("L100B50WU"));
    assert(isValidEbayListingString("L3139018"));
    assert(isValidEbayListingString("L3139018234817239018230912B13908129028350927360912839"));
    assert( ! isValidEbayListingString("L100 B50 W B+10 U W B+40 W"));
    assert( ! isValidEbayListingString("L100.50B50"));
    assert( ! isValidEbayListingString("L100B50UW"));
    assert( ! isValidEbayListingString("L100BW50"));
    assert( ! isValidEbayListingString("L100B50WBU+50"));
    assert( ! isValidEbayListingString("L100B50WB-50"));
    assert( ! isValidEbayListingString("L100B50UUUUUUUUU"));
    assert( ! isValidEbayListingString("L100B50WWUUUUUUUUU"));
    assert( ! isValidEbayListingString("WUL100"));
    assert( ! isValidEbayListingString("L100L50"));
    assert( ! isValidEbayListingString("L100B+50"));
    assert( ! isValidEbayListingString("L100B50B+50B20"));
    assert( ! isValidEbayListingString("L5B1WUWWB+2B+10+++"));
    assert( ! isValidEbayListingString("lambda"));
    assert( ! isValidEbayListingString("L+30B1"));
    assert( ! isValidEbayListingString("L0B5+3"));
    assert( ! isValidEbayListingString("L3B5l"));
    assert( ! isValidEbayListingString("L352C"));
    assert( ! isValidEbayListingString("L3139018+"));
    assert( ! isValidEbayListingString("L100B+50 "));
    assert( ! isValidEbayListingString("333"));
    assert( ! isValidEbayListingString("lb10"));
    assert(listingSold("l99b50wb+10uwb+40w"));
    assert(listingSold("L99B50WB+10UWB+40W"));
    assert(listingSold("L5B1WUWWB+2B+10"));
    assert(listingSold("L5B6"));
    assert(listingSold("L13980B1259018390283"));
    assert(listingSold("L10B3WWWWWWWWB+8U"));
    assert(listingSold("L20B1B+3B+2B+3B+40WU"));
    assert( ! listingSold("L20B1B+3B+2B+3B+40U"));
    assert( ! listingSold("L23B23"));
    assert( ! listingSold("L100B50WU"));
    assert( ! listingSold("L100B99"));
    assert( ! listingSold("L100B50WWWWWWW"));
    assert( ! listingSold("L100B50WUWUWUWWWWW"));
    assert( ! listingSold("L100B50WWUUB+10WWUU"));
    assert( ! listingSold("L100W"));
    assert( ! listingSold("L100WU"));
    assert( 13 == howMuch("L5B1WUWWB+2B+10"));
    assert(100 == howMuch("L99B50WB+10UWB+40W"));
    assert(  6 == howMuch("L5B6"));
    assert( 11 == howMuch("L10B3WWWWWWWWB+8U"));
    assert( -1 == howMuch("L100B50WWWWWWW"));
    assert( -1 == howMuch(""));
    assert( -1 == howMuch("L100B99"));
    assert(  2 == watchers("L99B50WB+10UWB+40W"));
    assert(  2 == watchers("l99b50wb+10uwb+40w"));
    assert(  0 == watchers("L100B99"));
    assert(  7 == watchers("L100B50WWWWWWW"));
    assert(  5 == watchers("L100B50WUWUWUWWWWW"));
    assert( -1 == watchers("apple"));
    assert( -1 == watchers("L100B50WWUUUUUUUUU"));
    
    cerr << "WE OUT HERE!!!" << endl;
    
    return 0;
    
}




bool isValidEbayListingString(string auctionstring)
{
    
    
    bool result = true;
    size_t len = auctionstring.size();
    
    
    // checks for empty string
    if (auctionstring == "")
        result = result && false;
    
    
    else
    {
        
        // checks for listing
        result = result && (auctionstring[0] == 'L' || auctionstring[0] == 'l');
        
        // checks for unrealistic price
        result = result && (auctionstring[1] > '0' && auctionstring[1] <= '9');
        
        // checks for watching before unwatching
        int watch = 0;
        int unwatch = 0;
        
        for (int i = 0; i < len; i++)
        {
            char ch = auctionstring[i];
            
            if (ch == 'W' or ch == 'w')
            {
                watch = watch + 1;
            }
            
            else if (ch == 'U' or ch == 'u')
            {
                unwatch = unwatch + 1;
            }
            
            if (watch < unwatch)
            {
                result = result && false;
                break;
            }
        }
        
        // checks for initial bid
        int j = 0;
        
        while (j < len)
        {
            char ch = auctionstring[j];
            char ch2 = auctionstring[j + 1];
            
            if (ch == 'B' || ch == 'b')
            {
                result = result && (ch2>= '0' && ch2 <= '9');
                break;
            }
            
            j++;
        }
        
        // checks for subsequent bids
        for (int i = j + 1; i < len; i++)
        {
            if (auctionstring[i] == 'B' || auctionstring [i] == 'b')
            {
                if (auctionstring[i + 1] == '+' && (auctionstring[i + 2] > '0'
                                                    || auctionstring[i + 2] < '9'))
                    result = result && true;
                else
                {
                    result = result && false;
                    break;
                }
            }
        }
        
        // checks for random discrepancies
        for (int i = 1; i < len; i++)
        {
            char ch = auctionstring[i];
            
            if (ch >= '0' && ch <= '9')
                result = result && true;
            
            else if (ch >= 'A' && ch <= 'z')
            {
                if (ch == 'u' || ch == 'U')
                    result = result && true;
                else if (ch == 'w' || ch == 'W')
                    result = result && true;
                else if (ch == 'b' || ch == 'B')
                    result = result && true;
                else
                {
                    result = result && false;
                    break;
                }
            }
            
            else if (ch == '+')
            {
                if (auctionstring[i-1] == 'B' || auctionstring[i-1] == 'b')
                    result = result && true;
                else
                {
                    result = result && false;
                    break;
                }
            }
            
            else
            {
                result = result && false;
                break;
            }
            
        }
        
    }
    
    return result;
    
}




bool listingSold(string auctionstring)
{
    
    
    bool result = true;
    int init_bid = 0;
    int sub_bid = 0;
    int fin_bid = 0;
    int listing = 0;
    size_t len = auctionstring.size();
    
    
    if (isValidEbayListingString(auctionstring))
    {
        
        int num = 1;
        string num_str = "";
        
        // listing value
        while (auctionstring[num] <= '9' && auctionstring[num] >= '0')
        {
            char num_ch = auctionstring[num];
            
            num_str = num_str + num_ch;
            num++;
        }
        
        listing = atoi(num_str.c_str());
        
        // stores initial bid
        int i = 0;
        
        while (i < len)
        {
            char ch = auctionstring[i];
            
            if (ch == 'B' || ch == 'b')
            {
                int j = i + 1;
                string init_bid_str = "";
                
                while (auctionstring[j] >= '0' && auctionstring[j] <= '9')
                {
                    char num_ch = auctionstring[j];
                    
                    init_bid_str = init_bid_str + num_ch;
                    j++;
                }
                
                init_bid = atoi(init_bid_str.c_str());
                break;
            }
            
            i++;
        }
        
        // finds rest of bids
        for (int j = i + 1; j < len; j++)
        {
            
            if (auctionstring[j] == 'B' || auctionstring [j] == 'b')
            {
                string sub_bid_str = "";
                int k = j + 2;
                
                while (auctionstring[k] >= '0' && auctionstring[k] <= '9')
                {
                    char num_ch = auctionstring[k];
                    
                    sub_bid_str = sub_bid_str + num_ch;
                    k++;
                }
                
                sub_bid = sub_bid + atoi(sub_bid_str.c_str());
            }
            
        }
        
        // adds bids together
        fin_bid = init_bid + sub_bid;
        
    }
    
    
    else
        result = result && false;
    
    
    // compares bid price and listing price
    return result && (fin_bid > listing);
    
    
}



int howMuch(string auctionstring)
{
    
    
    if (listingSold(auctionstring))
    {
        
        int fin_bid = 0;
        int init_bid = 0;
        int sub_bid = 0;
        size_t len = auctionstring.size();
        
        // finds initial bid
        int i = 0;
        
        while (i < len)
        {
            char ch = auctionstring[i];
            
            if (ch == 'B' || ch == 'b')
            {
                int j = i + 1;
                string init_bid_str = "";
                
                while (auctionstring[j] >= '0' && auctionstring[j] <= '9')
                {
                    char num_ch = auctionstring[j];
                    
                    init_bid_str = init_bid_str + num_ch;
                    j++;
                }
                
                init_bid = atoi(init_bid_str.c_str());
                break;
            }
            
            i++;
        }
        
        // finds subsequent bids
        for (int j = i + 1; j < len; j++)
        {
            
            if (auctionstring[j] == 'B' || auctionstring [j] == 'b')
            {
                string sub_bid_str = "";
                int k = j + 2;
                
                while (auctionstring[k] >= '0' && auctionstring[k] <= '9')
                {
                    char num_ch = auctionstring[k];
                    
                    sub_bid_str = sub_bid_str + num_ch;
                    k++;
                }
                
                sub_bid = sub_bid + atoi(sub_bid_str.c_str());
            }
            
        }
        
        // adds bids together
        fin_bid = init_bid + sub_bid;
        
        return fin_bid;
        
    }
    
    
    else
        return -1;
    
    
}



int watchers(string auctionstring)
{
    
    
    if (isValidEbayListingString(auctionstring))
    {
        int watch = 0;
        int unwatch = 0;
        size_t len = auctionstring.size();
        
        // counts all watchers and unwatchers
        for (int i = 0; i < len; i++)
        {
            char ch = auctionstring[i];
            
            if (ch == 'W' or ch == 'w')
            {
                watch = watch + 1;
                continue;
            }
            
            if (ch == 'U' or ch == 'u')
            {
                unwatch = unwatch + 1;
                continue;
            }
        }
        
        return watch - unwatch;
    }
    
    
    else
        return -1;

    
}
