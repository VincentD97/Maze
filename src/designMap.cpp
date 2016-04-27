//
//  designMap.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "designMap.h"

const int N = 90;
int L[N], R[N];

void designMap( Map& map )
{
    int m = map.row(), n = map.col();
    int start_x = map.start_x(), start_y = map.start_y();
    int exit_x = map.exit_x(), exit_y = map.exit_y();
    int player_x = map.player_x(), player_y = map.player_y();
    
    srand( static_cast<unsigned int>(time(NULL)) );
    for ( int i = 0; i <= 2 * n; i++ )
        L[i] = R[i] = i;
    L[n] = n - 1;
    
    for ( int i = 0; i < m - 1; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            int k = L[j + 1];
            if ( j != k && rand() % 3 )
            {
                R[k] = R[j];
                L[R[k]] = k;
                R[j] = j + 1;
                L[R[j]] = j;
                map.updateE(i,j,true);
            } else
            {
                map.updateE(i,j,false);
            }
            if ( j != L[j] && rand() % 3 )
            {
                L[R[j]] = L[j];
                R[L[j]] = R[j];
                L[j] = R[j] = j;
                map.updateS(i,j,false);
            } else
            {
                map.updateS(i,j,true);
            }
        }
    }
    
    for ( int i = 0; i < n; i++ )
    {
        int k = L[i + 1];
        if ( i != k && (i == L[i] || rand() % 3) )
        {
            R[k] = R[i];
            L[R[k]] = k;
            R[i] = i + 1;
            L[R[i]] = i;
            map.updateE(m-1,i,true);
        } else
        {
            map.updateE(m-1,i,false);
        }
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        L[i] = R[i] = i;
    }
    
    for ( int j = 0; j < n; j++ )
        map.updateN(0,j,false);
    for ( int j = 0; j < n; j++ )
        map.updateS(m-1,j,false);
    for ( int i = 0; i < m; i++ )
        map.updateW(i,0,false);
    for ( int i = 0; i < m; i++ )
        map.updateE(i,n-1,false);
    for ( int i = 1; i < m; i++ )
        for ( int j = 0; j < n; j++ )
            map.updateN(i,j,map.s(i-1,j));
    for ( int i = 0; i < m; i++ )
        for ( int j = 1; j < n; j++ )
            map.updateW(i,j,map.e(i,j-1));
    
    // Decide Start and Exit.
    int num;
    do
    {
        num = rand() % ( 2 *( m + n ) );
    } while ( num == 0 || num == n - 1 || num == n || num == n + m - 1 || num == n + m || num == 2 * n + m - 1 || num == 2 * n + m || num == 2 * ( n + m ) - 1 );
    
    if ( num < n )
    {
        start_x = 0;
        start_y = num;
        exit_x = m - 1;
        exit_y = n - 1 - num;
        map.updateS(m-1,exit_y,true);
    }
    else if ( num < n + m )
    {
        start_x = num - n;
        start_y = n - 1;
        exit_x = m - 1 - num + n;
        exit_y = 0;
        map.updateW(exit_x,0,true);
    }
    else if ( num < 2 * n + m )
    {
        start_x = m - 1;
        start_y = 2 * n + m - 1 - num;
        exit_x = 0;
        exit_y = num - m - n;
        map.updateN(0,exit_y,true);
    }
    else
    {
        start_x = 2 * ( m + n ) - 1 - num;
        start_y = 0;
        exit_x = num - m - 2 * n;
        exit_y = n - 1;
        map.updateW(exit_x,m-1,true);
    }
    player_x = start_x;
    player_y = start_y;
    
    map.updateRow(m); map.updateCol(n);
    map.updateStart_x(start_x); map.updateStart_y(start_y);
    map.updateExit_x(exit_x); map.updateExit_y(exit_y);
    map.updatePlayer_x(player_x); map.updatePlayer_y(player_y);
}
