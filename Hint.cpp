//
//  Hint.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Hint.h"

struct point {
    int x;
    int y;
    int step;
};

void hint( bool whole, Map& map )
{
    int m = map.row(), n = map.col();
    int exit_x = map.exit_x(), exit_y = map.exit_y();
    int x = map.player_x(), y = map.player_y();
    
    point tmp, next;
    queue<point> q;
    int maze[ROWMAX][COLMAX];
    memset(maze,0,sizeof(maze));
    while(q.size() != 0) q.pop();
    maze[x][y] = 1;
    tmp.x = x; tmp.y = y;
    tmp.step = 1;
    q.push(tmp);
    
    while( !q.empty() )
    {
        tmp = q.front();
        if ( tmp.x == exit_x && tmp.y == exit_y ) break;
        if ( tmp.x - 1 >= 0 && map.n(tmp.x,tmp.y) && !maze[tmp.x - 1][tmp.y])
        {
            next.x = tmp.x - 1;
            next.y = tmp.y;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x - 1][tmp.y] = next.step;
        }
        if ( tmp.y - 1 >= 0 && map.w(tmp.x,tmp.y) && !maze[tmp.x][tmp.y - 1])
        {
            next.x = tmp.x;
            next.y = tmp.y - 1;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x][tmp.y - 1] = next.step;
        }
        if ( tmp.x + 1 < m && map.s(tmp.x,tmp.y) && !maze[tmp.x + 1][tmp.y])
        {
            next.x = tmp.x + 1;
            next.y = tmp.y;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x + 1][tmp.y] = next.step;
        }
        if ( tmp.y + 1 < n && map.e(tmp.x,tmp.y) && !maze[tmp.x][tmp.y + 1])
        {
            next.x = tmp.x;
            next.y = tmp.y + 1;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x][tmp.y + 1] = next.step;
        }
        q.pop();
    }
    
    if ( !whole )
    {
        if (tmp.x == exit_x && tmp.y == exit_y )
            cout << q.front().step << endl;
        else
            cout << "Error! Please report this bug." << endl;
    }
    else {
        
        for ( int i = 0; i < m; i++ )
            for ( int j = 0; j < n; j++ )
            {
                map.updateOnPath(i, j, false);
            }
        tmp.x = exit_x; tmp.y = exit_y;
        
        while ( tmp.x != x || tmp.y != y )
        {
            if ( map.n(tmp.x,tmp.y) && maze[tmp.x - 1][tmp.y] == maze[tmp.x][tmp.y] - 1 )
            {
                tmp.x--;
                map.updateOnPath(tmp.x, tmp.y, true);
            }
            else if ( map.s(tmp.x,tmp.y) && maze[tmp.x + 1][tmp.y] == maze[tmp.x][tmp.y] - 1 )
            {
                tmp.x++;
                map.updateOnPath(tmp.x, tmp.y, true);
            }
            else if ( map.w(tmp.x,tmp.y) && maze[tmp.x][tmp.y - 1] == maze[tmp.x][tmp.y] - 1 )
            {
                tmp.y--;
                map.updateOnPath(tmp.x, tmp.y, true);
            }
            else if ( map.e(tmp.x,tmp.y) && maze[tmp.x][tmp.y + 1] == maze[tmp.x][tmp.y] - 1 )
            {
                tmp.y++;
                map.updateOnPath(tmp.x, tmp.y, true);
            }
        }
        map.updateOnPath(exit_x, exit_y, true);
        
        printMap( true, map );
        
    }
    
    cout << "\n\nType \"Back\" to continue the game.\n\n";
    
    string str = "";
    while ( convertToLowercase(str) != "back" )
    {
        cin >> str;
    }
}

