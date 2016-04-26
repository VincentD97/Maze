//
//  main.cpp
//  Maze
//
//  Created by DongVincent on 4/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

// hint有个别时候没用？？？？
// hint限制次数


#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;










//////////////////////////////////////////////////////////
                        //Global//
//////////////////////////////////////////////////////////










const int ROWMAX = 50;
const int ROWMIN = 5;
const int COLMIN = 5;
const int COLMAX = 80;

struct Cell
{
    bool n, s, w, e, onPath;    // can go to n/s/w/e
};
int m,n;                         // m rows, n cols
Cell map [ROWMAX][COLMAX];

int start_x, start_y;
int exit_x, exit_y;
int player_x, player_y;        // Position of the Player.
string spaces;










////////////////////////////////////////////////////////
                    //Declarations//
////////////////////////////////////////////////////////










// Utility functions
string convertToLowercase(string str);
bool convertStringToNumber(string str, int& x); // return false when str is not a number
string createSpaces( int n );
// Member functions
void designMap();
bool move( string& dir );
void printMap( bool byHint );
void printHelp();
void printYouWin();
void printOpening();
void hint( int x, int y, bool whole );











//////////////////////////////////////////////////////////
                        //MAIN//
//////////////////////////////////////////////////////////










int main()
{

    string sizestring, dir, yesorno;
    bool win;
    
    printOpening();
    cout << "\n\n\nInput anything to continue ...\n";
  
    for (;;)
    {
        win = false;
        cin.ignore(INT_MAX, '\n');
        cout << "\n------------------------------------------------------------------------- Design Your Own Maze -------------------------------------------------------------------------\n\n ";
        // Input m
        for (;;)
        {
            cout << endl << createSpaces(65) << "Input Number of ROWs of the Maze :  ";
            getline(cin, sizestring);
            if ( convertToLowercase(sizestring) == "quit" )
                return 0;
            if ( !convertStringToNumber(sizestring, m) )
                cout << "\n\t\t\t\t\t\t\t\t     number Number NUMBER !!! :<\n\n";
            else
                if ( m > ROWMAX || m < ROWMIN )
                    cout << "\n\t\t\t\t\t\t\t\t The Number of ROWs Should be >= " << ROWMIN << " and <= " << ROWMAX << " orz\n\n";
                else break;
        }
        // Input n
        for (;;)
        {
            cout << endl << createSpaces(63) << "Input Number of COLUMNs of the Maze :  ";
            getline(cin, sizestring);
            if ( convertToLowercase(sizestring) == "quit" )
                return 0;
            if ( !convertStringToNumber(sizestring, n) )
                cout << endl << createSpaces(72) << "number Number NUMBER !!! :<\n\n";
            else
                if ( n > COLMAX || n < COLMIN )
                    cout << endl << createSpaces(59) << "The Number of COLUMNs Should be >= " << COLMIN << " and <= " << COLMAX << " orz\n\n";
                else break;
        }
        // Design the Map
        designMap();
        spaces = createSpaces(84 - n);
        string spaces1 = createSpaces(35);
        string spaces2 = createSpaces(54);
        string spaces3 = createSpaces(65);



        // Let's Play!
        for (;;)
        {
            printMap(false);
            cout << endl << spaces1 <<"Type               \e[1mSteps :\e[0m show minimal remaining steps              \e[1mHint :\e[0m see the solution.";
            cout << endl << spaces2 <<"\e[1mHelp  :\e[0m view the instructions." << createSpaces(20) << "\e[1mQuit :\e[0m exit.\n";
            cout << endl << spaces3 <<"Input Direction :  ";
            cin >> dir;
            // Remaining Steps
            if ( convertToLowercase(dir) == "steps" ) hint( player_x, player_y, false );
            // Hint.
            if ( convertToLowercase(dir) == "hint" ) hint( player_x, player_y, true );
            // Help.
            if ( convertToLowercase(dir) == "help" ) printHelp();
            // Quit.
            if ( convertToLowercase(dir) == "quit" ) break;
            else
                if ( move(dir) )
                {
                    printYouWin();
                    break;
                }
        }
        cout << endl << createSpaces(74) << "New Game ? (y/n)\t";
        yesorno = "";
        while ( yesorno != "y" && yesorno != "n" && yesorno != "yes" && yesorno != "no" )
        {
            cin >> yesorno;
            yesorno = convertToLowercase(yesorno);
        }
        if ( yesorno == "n" || yesorno == "no" )  { cout << "\n\n\nGoodbye.\n\n\n\n"; break; }
    }
}










//////////////////////////////////////////////////////////////
                        //Design Map//
//////////////////////////////////////////////////////////////










const int N = 92;
int L[N], R[N];

void designMap()
{
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
                map[i][j].e = true;
            } else
            {
                map[i][j].e = false;
            }
            if ( j != L[j] && rand() % 3 )
            {
                L[R[j]] = L[j];
                R[L[j]] = R[j];
                L[j] = R[j] = j;
                map[i][j].s = false;
            } else
            {
                map[i][j].s = true;
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
            map[m-1][i].e = true;
        } else
        {
            map[m-1][i].e = false;
        }
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        L[i] = R[i] = i;
    }
    
    for ( int j = 0; j < n; j++ )
        map[0][j].n = false;
    for ( int j = 0; j < n; j++ )
        map[m-1][j].s = false;
    for ( int i = 0; i < m; i++ )
        map[i][0].w = false;
    for ( int i = 0; i < m; i++ )
        map[i][n-1].e = false;
    for ( int i = 1; i < m; i++ )
        for ( int j = 0; j < n; j++ )
            map[i][j].n = map[i-1][j].s;
    for ( int i = 0; i < m; i++ )
        for ( int j = 1; j < n; j++ )
            map[i][j].w = map[i][j-1].e;
    
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
        map[m-1][exit_y].s = true;
    }
    else if ( num < n + m )
    {
        start_x = num - n;
        start_y = n - 1;
        exit_x = m - 1 - num + n;
        exit_y = 0;
        map[exit_x][0].w = true;
    }
    else if ( num < 2 * n + m )
    {
        start_x = m - 1;
        start_y = 2 * n + m - 1 - num;
        exit_x = 0;
        exit_y = num - m - n;
        map[0][exit_y].n = true;
    }
    else
    {
        start_x = 2 * ( m + n ) - 1 - num;
        start_y = 0;
        exit_x = num - m - 2 * n;
        exit_y = n - 1;
        map[exit_x][m-1].e = true;
    }
    player_x = start_x;
    player_y = start_y;
}










////////////////////////////////////////////////////////////
                          //Move//
////////////////////////////////////////////////////////////










bool move( string& dir )   // dir for direction.  return true if win   false if haven't win
{
    dir = convertToLowercase(dir);
    for ( int i = 0; i < dir.size(); i++ )
    {
        switch (dir[i])
        {
            case 'w':
                if ( map[player_x][player_y].n )
                {
                    if ( player_x == 0 ) return true;
                    else player_x--;
                }
                break;
            case 's':
                if ( map[player_x][player_y].s )
                {
                    if ( player_x == m - 1 ) return true;
                    else player_x++;
                }
                break;
            case 'a':
                if ( map[player_x][player_y].w )
                {
                    if ( player_y == 0 ) return true;
                    else player_y--;
                }
                break;
            case 'd':
                if ( map[player_x][player_y].e )
                {
                    if ( player_y == n - 1 ) return true;
                    else player_y++;
                }
                break;
        }
    }
    return false;
}










/////////////////////////////////////////////////////////////
                        //Print Map//
/////////////////////////////////////////////////////////////




void printMap( bool byHint )
{
    int i, j;
    for ( i = 0; i < 100; i++ ) cout << endl;
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
                if ( map[i][j].s == true) cout << 'X';
                else cout << "\33[4m" << 'X' << "\33[0m";
            }
            else if ( byHint && map[i][j].onPath )
            {
                if ( map[i][j].s == true) cout << '+';
                else cout << "\33[4m" << '+' << "\33[0m";
            }
            else if ( map[i][j].s == true )
                    cout << ' ';
                else cout << '_';
            if ( j == n - 1 && ((exit_y == n - 1 && i == exit_x) || (start_y == n - 1 && i == start_x)) ) cout << ' ';
            else if ( map[i][j].e == true )
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
            if ( map[i][j].s == true) cout << 'X';
            else cout << "\33[4m" << 'X' << "\33[0m";
        }
        else if ( byHint && map[i][j].onPath )
        {
            if ( map[i][j].s == true) cout << '+';
            else cout << "\33[4m" << '+' << "\33[0m";
        }
        else if ( (exit_x == m - 1 && j == exit_y) || (start_x == m - 1 && j == start_y) )
            if ( !byHint ) cout << ' '; else cout << '+';
        else cout << '_';
        if ( map[m - 1][j].e == true )
            cout << '_';
        else cout << '|';
    }
    for ( int i = 0; i < 34 - m; i++ ) cout << endl;
    cout << endl;
}










//////////////////////////////////////////////////////////////
                        //Print Help//
//////////////////////////////////////////////////////////////










void printHelp()
{
    int i;
    for (i = 0; i < 100; i++) cout << "\n";
    string str = createSpaces(28);
    cout << str << "+------------------------------------------ I N S T R U C T I O N S ------------------------------------------+\n";
    cout << str << "|                                                                                                             |\n";
    cout << str << "|   *   Determine the size of your maze :                                                                     |\n";
    cout << str << "|       The number of rows should not be over 50 and the number of columns should not be over 80 ( otherwise  |\n";
    cout << str << "|       too large to display the maze on the screen ), and should not be less than 5.                         |\n";
    cout << str << "|                                                                                                             |\n";
    cout << str << "|   *   You can not win by going back to the start point.                                                     |\n";
    cout << str << "|                                                                                                             |\n";
    cout << str << "|   *   How to Play :                                                                                         |\n";
    cout << str << "|       - Use WASD to move. Type in a command (e.g. \"w\") or command string (e.g. \"sddwda\") followed by Enter. |\n";
    cout << str << "|         If the command string is in valid, only WASD will be recognized.                                    |\n";
    cout << str << "|       - Typing in uppercase or lowercase doesn't matter.                                                    |\n";
    cout << str << "|       - At any time in game, you can quit the current puzzle by typing \"Quit\".                              |\n";
    cout << str << "|       - If you have any question, type \"Help\" to access this instruction sheet.                             |\n";
    cout << str << "|       - Type \"Steps\" or \"Hint\" to cheat. lol                                                                |\n";
    cout << str << "|                                                                                                             |\n";
    cout << str << "|   *   Contact me :  vincent_dong97@outlook.com                                                              |\n";
    cout << str << "|                                                                                                             |\n";
    cout << str << "+-------------------------------------------------------------------------------------------------------------+\n";
    
    for ( int i = 0; i < 20; i++ ) cout << endl;
    cout << str << "     Type \"Back\" to continue the game.\n\n";
    
    string back = "";
    while ( convertToLowercase(back) != "back" )
    {
        cin >> back;
    }
    
}










/////////////////////////////////////////////////////////////
                    //Print You Win !//
/////////////////////////////////////////////////////////////










void printYouWin()
{
    for ( int i = 0; i < 100; i++ ) cout << endl;
    string str1 = createSpaces(60);
    string str2 = createSpaces(40);
    cout << str1 << "__            __    _______     ___       ___\n";
    cout << str1 << "\\ \\          / /   / _____ \\    | |       | |\n";
    cout << str1 << " \\ \\        / /   / /     \\ \\   | |       | |\n";
    cout << str1 << "  \\ \\      / /   | |       | |  | |       | |\n";
    cout << str1 << "   \\ \\    / /    | |       | |  | |       | |\n";
    cout << str1 << "    \\ \\  / /     | |       | |  | |       | |\n";
    cout << str1 << "     \\ \\/ /      | |       | |  | |       | |\n";
    cout << str1 << "      |  |       | |       | |  | |       | |\n";
    cout << str1 << "      |  |       | |       | |  | |       | |\n";
    cout << str1 << "      |  |       | |       | |  | |       | |\n";
    cout << str1 << "      |  |        \\ \\_____/ /   \\ \\_______/ /\n";
    cout << str1 << "      |__|         \\_______/     \\_________/";
    
    for ( int i = 0; i < 10; i++ ) cout << endl;
    cout << str2 << "__                                      __    ____________       ___           __\n";
    cout << str2 << "\\ \\                                    / /   |____    ____|     |   \\         |  |                     |\n";
    cout << str2 << " \\ \\                                  / /         |  |          |    \\        |  |                     |\n";
    cout << str2 << "  \\ \\               /\\               / /          |  |          |  |\\ \\       |  |                     |\n";
    cout << str2 << "   \\ \\             /  \\             / /           |  |          |  | \\ \\      |  |                     |\n";
    cout << str2 << "    \\ \\           / /\\ \\           / /            |  |          |  |  \\ \\     |  |                     |\n";
    cout << str2 << "     \\ \\         / /  \\ \\         / /             |  |          |  |   \\ \\    |  |                     |\n";
    cout << str2 << "      \\ \\       / /    \\ \\       / /              |  |          |  |    \\ \\   |  |                     | \n";
    cout << str2 << "       \\ \\     / /      \\ \\     / /               |  |          |  |     \\ \\  |  |                     |\n";
    cout << str2 << "        \\ \\   / /        \\ \\   / /                |  |          |  |      \\ \\ |  |                     |\n";
    cout << str2 << "         \\ \\_/ /          \\ \\_/ /                 |  |          |  |       \\ \\|  |                     _\n";
    cout << str2 << "          \\   /            \\   /              ____|  |____      |  |        \\    |                    /.\\\n";
    cout << str2 << "           \\_/              \\_/              |____________|     |__|         \\___|                    \\_/\n";
    
    for ( int i = 0; i < 10; i++ ) cout << endl;
    cout << createSpaces(70) << "YOU ARE AWE(wu)SOME(liao) !!!!\n\n\n\n\n\n";
}










/////////////////////////////////////////////////////////////
                    //Utility Functions//
/////////////////////////////////////////////////////////////










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










////////////////////////////////////////////////////////
                        //Hint//
////////////////////////////////////////////////////////










struct point {
    int x;
    int y;
    int step;
};

void hint( int x, int y, bool whole )
{
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
        if ( tmp.x - 1 >= 0 && map[tmp.x][tmp.y].n && !maze[tmp.x - 1][tmp.y])
        {
            next.x = tmp.x - 1;
            next.y = tmp.y;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x - 1][tmp.y] = next.step;
        }
        if ( tmp.y - 1 >= 0 && map[tmp.x][tmp.y].w && !maze[tmp.x][tmp.y - 1])
        {
            next.x = tmp.x;
            next.y = tmp.y - 1;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x][tmp.y - 1] = next.step;
        }
        if ( tmp.x + 1 < m && map[tmp.x][tmp.y].s && !maze[tmp.x + 1][tmp.y])
        {
            next.x = tmp.x + 1;
            next.y = tmp.y;
            next.step = tmp.step + 1;
            q.push(next);
            maze[tmp.x + 1][tmp.y] = next.step;
        }
        if ( tmp.y + 1 < n && map[tmp.x][tmp.y].e && !maze[tmp.x][tmp.y + 1])
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
            map[i][j] = map[i][j];
            map[i][j].onPath = false;
        }
    tmp.x = exit_x; tmp.y = exit_y;
    
    while ( tmp.x != player_x || tmp.y != player_y )
    {
        if ( map[tmp.x][tmp.y].n && maze[tmp.x - 1][tmp.y] == maze[tmp.x][tmp.y] - 1 )
        {
            tmp.x--;
            map[tmp.x][tmp.y].onPath = true;
        }
        else if ( map[tmp.x][tmp.y].s && maze[tmp.x + 1][tmp.y] == maze[tmp.x][tmp.y] - 1 )
        {
            tmp.x++;
            map[tmp.x][tmp.y].onPath = true;
        }
        else if ( map[tmp.x][tmp.y].w && maze[tmp.x][tmp.y - 1] == maze[tmp.x][tmp.y] - 1 )
        {
            tmp.y--;
            map[tmp.x][tmp.y].onPath = true;
        }
        else if ( map[tmp.x][tmp.y].e && maze[tmp.x][tmp.y + 1] == maze[tmp.x][tmp.y] - 1 )
        {
            tmp.y++;
            map[tmp.x][tmp.y].onPath = true;
        }
    }
    map[exit_x][exit_y].onPath = true;
    printMap(true);
        
    }
    
    cout << "\n\nType \"Back\" to continue the game.\n\n";
    
    string str = "";
    while (!(str.size() == 4 && (str[0] == 'B' || str[0] == 'b') && (str[1] == 'A' || str[1] == 'a') && (str[2] == 'C' || str[2] == 'c') && (str[3] == 'K' || str[3] == 'k')))
    {
        cin >> str;
    }
}










/////////////////////////////////////////////////////////
                    //Print Opening//
/////////////////////////////////////////////////////////










void printOpening()
{
    cout << endl << endl;
    string str = createSpaces( 45 );
    cout << str << "=========   ========           \\\\            /        /\\\\        =======  =======\n";
    cout << str << "|                 /            |\\\\          /|       /  \\\\            /   |\n";
    cout << str << "|                /             | \\\\        / |      /    \\\\          /    |\n";
    cout << str << "|======         /              |  \\\\      /  |     /======\\\\        /     |=====\n";
    cout << str << "|              /               |   \\\\    /   |    /        \\\\      /      |\n";
    cout << str << "|             /                |    \\\\  /    |   /          \\\\    /       |\n";
    cout << str << "=========   ========           |     \\\\/     |  /            \\\\  =======  =======\n";
}










/////////////////////////////////////////////////////////
            //Create a Sting of n Spaces//
/////////////////////////////////////////////////////////










string createSpaces( int n )
{
    string result = "";
    for ( int i = 0; i < n; i++ ) result += " ";
    return result;
}