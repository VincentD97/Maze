//
//  printMap.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "printMap.h"

void printMap( bool byHint, Map& map )
{
    int m = map.row(), n = map.col();
    int start_x = map.start_x(), start_y = map.start_y();
    int exit_x = map.exit_x(), exit_y = map.exit_y();
    int player_x = map.player_x(), player_y = map.player_y();
    
    int i, j;
    for ( i = 0; i < 100; i++ ) cout << endl;
    string spaces = createSpaces(84 - n);
    cout << spaces;
    for ( i = 0; i <= 2 * n; i++ )
    {
        if ( (exit_x == 0 && i == 2 * exit_y + 1) || (start_x == 0 && i == 2 * start_y + 1) ) cout << ' ';
        else cout << '_';
    }
    for ( i = 0; i < m - 1; i++ )
    {
        if ( (exit_y == 0 && i == exit_x) || (start_y == 0 && i == start_x) ) cout << endl << spaces << " ";
        else cout << endl << spaces << "|";
        for ( j = 0; j < n; j++ )
        {
            if ( i == player_x && j == player_y )
            {
                if ( map.s(i,j) == true) cout << map.thePlayer();
                else cout << "\33[4m" << map.thePlayer() << "\33[0m";
            }
            else if ( byHint && map.onPath(i,j) )
            {
                if ( map.s(i,j) == true) cout << "\33[31m+\33[0m";
                else cout << "\33[4;31m+\33[0m";
            }
            else if ( map.s(i,j) == true )
                cout << ' ';
            else cout << '_';
            if ( j == n - 1 && ((exit_y == n - 1 && i == exit_x) || (start_y == n - 1 && i == start_x)) ) cout << ' ';
            else if ( map.e(i,j) == true )
                cout << '.';
            else cout << '|';
        }
    }
    if ( (exit_y == -1 && exit_x == m - 1) || (start_y == -1 && start_x == m - 1) ) cout << "\n ";
    else cout << endl << spaces << "|";
    for ( j = 0; j < n; j++ )
    {
        if ( player_x == m - 1 && player_y == j )
        {
            if ( map.s(i,j) == true) cout << map.thePlayer();
            else cout << "\33[4m" << map.thePlayer() << "\33[0m";
        }
        else if ( byHint && map.onPath(m - 1, j) )
        {
            if ( map.s(m - 1, j) == false ) cout << "\33[1;31m+\33[0m";
            else cout << "\33[31m+\33[0m";
        }
        else if ( (exit_x == m - 1 && j == exit_y) || (start_x == m - 1 && j == start_y) )
            if ( !byHint ) cout << ' '; else cout << '+';
            else cout << '_';
        if ( map.e(m - 1,j) == true )
            cout << '_';
        else cout << '|';
    }
    for ( int i = 0; i < 34 - m; i++ ) cout << endl;
    cout << endl;
}



