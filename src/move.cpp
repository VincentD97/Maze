//
//  move.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "move.h"

bool move( string& dir, Map& map )   // dir for direction.  return true if win   false if haven't win
{
    int m = map.row(), n = map.col();
    int player_x = map.player_x(), player_y = map.player_y();
    
    dir = convertToLowercase(dir);
    for ( int i = 0; i < dir.size(); i++ )
    {
        switch (dir[i])
        {
            case 'w':
                if ( map.n(player_x, player_y) )
                {
                    if ( player_x == 0 ) return true;
                    else player_x--;
                }
                break;
            case 's':
                if ( map.s(player_x, player_y) )
                {
                    if ( player_x == m - 1 ) return true;
                    else player_x++;
                }
                break;
            case 'a':
                if ( map.w(player_x, player_y) )
                {
                    if ( player_y == 0 ) return true;
                    else player_y--;
                }
                break;
            case 'd':
                if ( map.e(player_x, player_y) )
                {
                    if ( player_y == n - 1 ) return true;
                    else player_y++;
                }
                break;
        }
    }
    
    map.updatePlayer_x(player_x); map.updatePlayer_y(player_y);
    return false;
}
