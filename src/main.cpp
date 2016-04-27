//
//  main.cpp
//  Maze
//
//  Created by DongVincent on 4/23/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

// hint限制次数
// 用户可以改X的颜色

#include "global.h"
#include "Map.h"
#include "designMap.h"
#include "move.h"
#include "printMap.h"
#include "Hint.h"
#include "print.h"
#include "changeColor.h"

using namespace std;



////////////////////////////////////////////////////////
                    //Declarations//
////////////////////////////////////////////////////////



// Member functions


//////////////////////////////////////////////////////////
                        //MAIN//
//////////////////////////////////////////////////////////


int main()
{
    int m,n;
    string spaces;
    Map map;
    
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
        map.updateRow(m);
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
        map.updateCol(n);
        // Design the Map
        designMap( map );
        string spaces1 = createSpaces(35);
        string spaces2 = createSpaces(54);
        string spaces3 = createSpaces(65);
        
        // Let's Play!
        for (;;)
        {
            printMap( false, map );
            cout << endl << spaces1 <<"Type               \e[1mSteps :\e[0m show minimal remaining steps              \e[1mHint :\e[0m see the solution.";
            cout << endl << spaces2 <<"\e[1mHelp  :\e[0m view the instructions." << createSpaces(20) << "\e[1mQuit :\e[0m exit.\n";
            cout << endl << spaces3 <<"Input Direction :  ";
            cin >> dir;
            // Remaining Steps
            if ( convertToLowercase(dir) == "steps" ) hint( false, map );
            // Hint.
            if ( convertToLowercase(dir) == "hint" ) hint( true, map );
            // Help.
            if ( convertToLowercase(dir) == "help" ) printHelp();
            // Change Color.
            if ( convertToLowercase(dir) == "color" ) changeColor( map );
            // Quit.
            if ( convertToLowercase(dir) == "quit" ) break;
            else
                if ( move( dir, map ) )
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
