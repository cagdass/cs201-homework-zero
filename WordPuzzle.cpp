//
//  WordPuzzle.cpp
//  Homework Zero
//
//  Created by dunkuCoder on 16/06/14.
//  Copyright (c) 2014 Çağdaş Öztekin. All rights reserved.
//

#include "WordPuzzle.h"
#include <fstream>
#include <iostream>

using namespace std;

const string Directions[9] = {	"NONE", "LEFT_TO_RIGHT", "RIGHT_TO_LEFT", "TOP_TO_BOTTOM",
    "BOTTOM_TO_TOP", "TOP_LEFT_TO_BOTTOM_RIGHT",
    "TOP_RIGHT_TO_BOTTOM_LEFT", "BOTTOM_LEFT_TO_TOP_RIGHT",
    "BOTTOM_RIGHT_TO_TOP_LEFT"};

WordPuzzle::WordPuzzle(string puzzleFileName)
{
    //char initialisation, each element of the 2-D array will be provided using this char
    char currentChar = 'p';
    
    //Open a stream for the input file
    ifstream inputFile;
//    inputFile.open( ("/supplied/"+puzzleFileName).c_str(), ios_base::in );
    inputFile.open( ("/Users/mozart/Downloads/cs201_hw0_files/"+puzzleFileName).c_str(), ios_base::in );
    
    if(!(inputFile.good()))
    {
        cout<<"ERROR: "<< puzzleFileName <<"does not exist ..."<<endl;
    }
    else
    {
        //currentRow and currentColumn set to 0, placing elements in the array will start from puzzle[0][0]
        int currentRow = 0;
        int currentColumn = 0;
        
        //rows are initialised numOfRow times
        for(; currentRow < numOfRow; currentRow++)
        {
            //each column in one row is initialised numOfColumn times
            for(currentColumn = 0; currentColumn < numOfColumn; currentColumn++)
            {
                currentChar = inputFile.get();
                //checking to see if the current character is not an escape sequence
                if(!(currentChar == '\n'))
                {
                    puzzle[currentRow][currentColumn] = currentChar;
                }
            }
            currentChar = inputFile.get();
        }
    }
    
    //no more data left in the text file, stream is closed
    inputFile.close();
}

bool WordPuzzle::searchLeftToRight(string word, int& row, int& column)
{
    // length of the word that will be searched
    int wordLength = word.length();
    // tryWord will be of length wordLength, as long as it is in the certain boundaries defined below it will be compared to the
    // original word in the wanted direction
    string tryWord = "";
    
    // two for loops starting from puzzle[0][0] to try each possible slot in the array as the initial point of the searched word
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            //the point selected if it follows the conditions below, making sure it stays in the array's boundaries
            if( row >= 0 && row < WordPuzzle::numOfRow && column >= 0 && column + wordLength < WordPuzzle::numOfColumn)
            {
                //word is initialised by adding chars to the end of the string tryWord in the wanted direction for wordLength times
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row][column+k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    //somewhat I couldn't get compare or strcmp methods to work simply doing this
                    //it is kind of a mess, it is recurrent in all 8 of search methods but I couldn't have
                    //changed the header file
                    //though I suspect I am missing a '\0' to put the end of the char array to make it a string
                    //but we have just learned it today... so...
                    for(int k = 0; k < wordLength; k++)
                    {
                        //counting the same characters in the same index
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    //if the two strings have the same characters the same as their length then they are equals, so it is true
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                //tryWord is emptied to be tried in the next index to come
                tryWord = "";
            }
        }
    }
    
    //word not found
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchRightToLeft(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row >= 0 && row < WordPuzzle::numOfRow && column + wordLength >= 0 && column < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row][column-k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchTopToBottom(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row >= 0 && row + wordLength < WordPuzzle::numOfRow && column >= 0 && column < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row+k][column];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchBottomToTop(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row - wordLength >= 0 && row < WordPuzzle::numOfRow && column >= 0 && column < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row-k][column];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchTopLeftToBottomRight(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row >= 0 && row + wordLength < WordPuzzle::numOfRow && column >= 0 && column + wordLength < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row+k][column+k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchTopRightToBottomLeft(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row >= 0 && row + wordLength < WordPuzzle::numOfRow && column - wordLength >= 0 && column < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row+k][column-k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchBottomLeftToTopRight(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row - wordLength >= 0 && row < WordPuzzle::numOfRow && column >= 0 && column + wordLength < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row-k][column+k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}

//this search method completely have the same idea as searchLeftToRight() take a look at that one please
bool WordPuzzle::searchBottomRightToTopLeft(string word, int& row, int& column)
{
    int wordLength = word.length();
    string tryWord = "";
    
    for(int i = 0; i < WordPuzzle::numOfRow; i++)
    {
        for(int j = 0; j < WordPuzzle::numOfColumn; j++)
        {
            row = i;
            column = j;
            if( row - wordLength >= 0 && row < WordPuzzle::numOfRow && column - wordLength >= 0 && column < WordPuzzle::numOfColumn)
            {
                for( int k = 0; k < wordLength; k++)
                {
                    tryWord = tryWord + puzzle[row-k][column-k];
                }
                
                if(word.length() == tryWord.length())
                {
                    int count = 0;
                    
                    for(int k = 0; k < wordLength; k++)
                    {
                        if(word[k] == tryWord[k])
                        {
                            count++;
                        }
                    }
                    
                    if(count == wordLength)
                    {
                        return true;
                    }
                }
                
                tryWord = "";
            }
        }
    }
    
    return false;
}


//   {NONE = 0, LEFT_TO_RIGHT, RIGHT_TO_LEFT, TOP_TO_BOTTOM,
//    BOTTOM_TO_TOP, TOP_LEFT_TO_BOTTOM_RIGHT,
//    TOP_RIGHT_TO_BOTTOM_LEFT, BOTTOM_LEFT_TO_TOP_RIGHT,
//    BOTTOM_RIGHT_TO_TOP_LEFT};

//the puzzle is searched for a word in every possible direction, if found one the direction is returned else none is returned
WordPuzzle::Direction WordPuzzle::solvePuzzle(string word, int& row, int& column)
{
    if(searchLeftToRight(word, row, column))
    {
        return WordPuzzle::LEFT_TO_RIGHT;
    }
    else if(searchRightToLeft(word, row, column))
    {
        return WordPuzzle::RIGHT_TO_LEFT;
    }
    else if(searchTopToBottom(word, row, column))
    {
        return WordPuzzle::TOP_TO_BOTTOM;
    }
    else if(searchBottomToTop(word, row, column))
    {
        return WordPuzzle::BOTTOM_TO_TOP;
    }
    else if(searchTopLeftToBottomRight(word, row, column))
    {
        return WordPuzzle::TOP_LEFT_TO_BOTTOM_RIGHT;
    }
    else if(searchTopRightToBottomLeft(word, row, column))
    {
        return WordPuzzle::TOP_RIGHT_TO_BOTTOM_LEFT;
    }
    else if(searchBottomLeftToTopRight(word, row, column))
    {
        return WordPuzzle::BOTTOM_LEFT_TO_TOP_RIGHT;
    }
    else if(searchBottomRightToTopLeft(word, row, column))
    {
        return WordPuzzle::BOTTOM_RIGHT_TO_TOP_LEFT;
    }
    else
    {
        return WordPuzzle::NONE;
    }
}

//words to be tried are read from file and the results are written in an output file
void WordPuzzle::solvePuzzle(string wordListFileName, string outputFileName)
{
    ifstream wordListInput;
    ofstream outputFile;
    //streams are opened
    outputFile.open( ("/Users/mozart/Downloads/cs201_hw0_files/"+outputFileName).c_str(), ios_base::out );
    wordListInput.open( ("/Users/mozart/Downloads/cs201_hw0_files/"+wordListFileName).c_str(), ios_base::in);
    
    if(wordListInput.good())
    {
        //newLineCount basically counts the number of words to be tested
        //    int newLineCount = 0;
        //char had to be initialised 'a' seemed nice
        char currentChar = 97;
        
        //the whole purpose of this while loop is to find out number of words
        //then I would declare a const int to initialise the size of the string array to
        //put the words in but a better idea came out
        //    while(wordListInput.good())
        //    {
        //        currentChar = wordListInput.get();
        //        if( currentChar == '\n')
        //        {
        //            newLineCount++;
        //        }
        //    }
        
        const int wordListSize = 100;
        
        //    wordListInput.close();
        //    wordListInput.open(wordListFileName.c_str(), ios_base::in);
        string currentWord = "";
        //    currentChar = 97;
        //    int numberOfAddedWords = 0;
        //all 4 variables below set to in case of the result is NONE, the word is not found
        Direction foundDirection = WordPuzzle::NONE;
        Direction currentDirection = WordPuzzle::NONE;
        int foundRow = -1;
        int foundColumn = -1;
        
        //works while there is data in the input file
        while(wordListInput.good())
        {
            currentChar = wordListInput.get();
            {
                if(currentChar != '\n')
                {
                    currentWord = currentWord + currentChar;
                }
                //'\n' means the words is complete, ready to be searched and the results are to be written
                else
                {
                    //the direction is found
                    currentDirection = solvePuzzle(currentWord, foundRow, foundColumn);
                    if(currentDirection != WordPuzzle::NONE)
                    {
                        foundDirection = currentDirection;
                    }
                    
                    //foundRow and foundColumn had their references put in solvePuzzle, if no direction found they must be set to again
                    if(foundDirection == WordPuzzle::NONE)
                    {
                        foundRow = -1;
                        foundColumn = -1;
                    }
                    
                    //the result is written
                    outputFile << Directions[foundDirection] << "\t" << foundRow << "\t" << foundColumn << endl;
                    
                    //the variables are set to worst case scenario values
                    foundDirection = WordPuzzle::NONE;
                    foundRow = -1;
                    foundColumn = -1;
                    currentChar = 97;
                    //currentWord will be renewed
                    currentWord = "";
                    //                numberOfAddedWords++;
                }
            }
        }
        
        outputFile.close();
    }
    else
    {
        cout<<"ERROR: "<< wordListFileName <<"does not exist ..."<<endl;
        wordListInput.close();
        outputFile.close();
    }
    
}

//solution is displayed, very simple to follow
void WordPuzzle::displaySolution(string word, WordPuzzle::Direction dir, int row, int column)
{
    //I did not see the parameters row and column and too lazy to replace the variables since I have already written according to
    //foundRow and foundColumn... so 8 bytes down to garbage :(
    int foundRow = row;
    int foundColumn = column;
    
    switch (dir)
    {
        case WordPuzzle::NONE:
            cout<<word<<" does not exist in the puzzle."<<endl;
            break;
        case WordPuzzle::LEFT_TO_RIGHT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn+i<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::RIGHT_TO_LEFT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn-i<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::TOP_TO_BOTTOM:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow+i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::BOTTOM_TO_TOP:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow-i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::TOP_LEFT_TO_BOTTOM_RIGHT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow+i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn+i<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::TOP_RIGHT_TO_BOTTOM_LEFT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow+i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn-i<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::BOTTOM_LEFT_TO_TOP_RIGHT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow-i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn+i<<"\t";
            }
            cout<<endl;
            break;
        case WordPuzzle::BOTTOM_RIGHT_TO_TOP_LEFT:
            for(int i = 0; i < word.length(); i++)
            {
                cout<<word[i]<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundRow-i<<"\t";
            }
            cout<<endl;
            for(int i = 0; i < word.length(); i++)
            {
                cout<<foundColumn-i<<"\t";
            }
            cout<<endl;
            break;
        default:
            cout<<"UNKNOWN ERROR... sort of"<<endl;
            break;
    }
}

