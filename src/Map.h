//
//  Map.h
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include "global.h"

struct Cell
{
    bool n, s, w, e, onPath;    // can go to n/s/w/e
};

class Map
{
public:
    Map( );
    bool n( int row, int col );     // can go to n/s/w/e
    bool s( int row, int col );
    bool w( int row, int col );
    bool e( int row, int col );
    bool onPath( int row, int col );
    void updateOnPath( int row, int col, bool boo );
    void updateN( int row, int col, bool boo );
    void updateS( int row, int col, bool boo );
    void updateW( int row, int col, bool boo );
    void updateE( int row, int col, bool boo );
    int row();
    int col();
    int start_x();
    int start_y();
    int exit_x();
    int exit_y();
    int player_x();
    int player_y();
    void updateRow( int row );
    void updateCol( int col );
    void updateStart_x( int start_x );
    void updateStart_y( int start_y );
    void updateExit_x( int exit_x );
    void updateExit_y( int exit_y );
    void updatePlayer_x( int player_x );
    void updatePlayer_y( int player_y );
    std::string thePlayer();
    void updateThePlayer( string str );
    
private:
    Cell map[ROWMAX][COLMAX];
    int m_row, m_col;
    int m_start_x, m_start_y;
    int m_exit_x, m_exit_y;
    int m_player_x, m_player_y;
    std::string m_thePlayer;
};

#endif /* Map_h */
