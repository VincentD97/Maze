//
//  Map.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include "Map.h"


Map::Map( )
{
    m_thePlayer = "\33[1mX\33[0m";
}

bool Map::n( int row, int col ) {    return map[row][col].n;    }
bool Map::s( int row, int col ) {    return map[row][col].s;    }
bool Map::w( int row, int col ) {    return map[row][col].w;    }
bool Map::e( int row, int col ) {    return map[row][col].e;    }
bool Map::onPath( int row, int col ) {    return map[row][col].onPath;    }

void Map::updateN( int row, int col, bool boo ) {    map[row][col].n = boo;   }
void Map::updateS( int row, int col, bool boo ) {    map[row][col].s = boo;   }
void Map::updateW( int row, int col, bool boo ) {    map[row][col].w = boo;   }
void Map::updateE( int row, int col, bool boo ) {    map[row][col].e = boo;   }
void Map::updateOnPath( int row, int col, bool boo ) {    map[row][col].onPath = boo;   }

int Map::row() {    return m_row;   }
int Map::col() {    return m_col;   }
int Map::start_x() {    return m_start_x;   }
int Map::start_y() {    return m_start_y;;  }
int Map::exit_x(){  return m_exit_x;    }
int Map::exit_y(){  return m_exit_y;    }
int Map::player_x(){    return m_player_x;  }
int Map::player_y(){    return m_player_y;  }
std::string Map::thePlayer() {    return m_thePlayer;   }


void Map::updateRow( int row ) {    m_row = row;    }
void Map::updateCol( int col ) {    m_col = col;    }
void Map::updateStart_x( int start_x ) {    m_start_x = start_x;    }
void Map::updateStart_y( int start_y ) {    m_start_y = start_y;    }
void Map::updateExit_x( int exit_x ) {    m_exit_x = exit_x;    }
void Map::updateExit_y( int exit_y ) {    m_exit_y = exit_y;    }
void Map::updatePlayer_x( int player_x ) {    m_player_x = player_x;    }
void Map::updatePlayer_y( int player_y ) {    m_player_y = player_y;    }
void Map::updateThePlayer( string str )
{
    m_thePlayer = "\33[1;3" + str + "mX\33[0m";
}