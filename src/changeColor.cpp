//
//  changeColor.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "changeColor.h"

void changeColor( Map& map )
{
    for ( int i = 0; i < 100; i++ ) cout << endl;
    string spaces = createSpaces(45);
    cout << spaces << "\33[1m 0 :\33[0m   Black           \e[1m 1 :\e[0m   Red             \e[1m 2 :\e[0m   Green           \e[1m 3 :\e[0m   Yellow\n";
    cout << spaces << "\33[1m 4 :\33[0m   Blue            \e[1m 5 :\e[0m   Magenta         \e[1m 6 :\e[0m   Cyan            \e[1m 7 :\e[0m   White\n\n\n";
    cout << spaces << "                           Input one of the Color Codes :";

    string code;
    cin >> code;
    while ( !(code.size() == 1 && code[0] >= '0' && code[0] <= '9') )
    {
        cout << spaces << "                                         INVALID !\n";
        cout << spaces << "                           Input one of the Color Codes :";
        cin >> code;
    }

         map.updateThePlayer( code );
}
