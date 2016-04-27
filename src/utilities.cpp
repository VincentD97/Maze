//
//  utilities.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "global.h"

string convertToLowercase(string str)
{
    string result("");
    for ( int i = 0; i < str.size(); i++ )
        result += tolower(str[i]);
    return result;
}

bool convertStringToNumber(string str, int& x)
{
    x = 0;
    for ( int i = 0; i < str.size(); i++ )
    {
        if ( !isdigit(str[i]) ) return false;
        x = 10 * x + static_cast<int>(str[i]) - 48;
    }
    return true;
}

string createSpaces( int n )
{
    string result = "";
    for ( int i = 0; i < n; i++ ) result += " ";
    return result;
}

