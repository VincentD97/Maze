//
//  global.h
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#ifndef global_h
#define global_h

#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

const int ROWMAX = 50;
const int ROWMIN = 5;
const int COLMIN = 5;
const int COLMAX = 80;

string convertToLowercase(string str);
bool convertStringToNumber(string str, int& x);
string createSpaces( int n );



#endif /* global_h */
