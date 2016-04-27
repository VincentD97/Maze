//
//  print.cpp
//  Maze
//
//  Created by DongVincent on 4/26/16.
//  Copyright © 2016 UCLA. All rights reserved.
//

#include <iostream>
#include "global.h"
#include "print.h"
using namespace std;

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










