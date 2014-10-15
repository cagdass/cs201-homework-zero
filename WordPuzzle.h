// This is the header file of a WordPuzzle solver system. In this header
// file, you will find the definition of WordPuzzle class.
//
// Note that you ARE NOT ALLOWED TO MODIFY this class definition.
// Otherwise you will lose a considerable amount of grade even though
// your implementation is totally correct.


#include <string>		// For string declarations and operations
using namespace std;

class WordPuzzle
{
public:
	const static int numOfRow = 15;
	const static int numOfColumn = 15;
	
	// There are 8 directions for which the search operation is done
	enum Direction{	NONE = 0, LEFT_TO_RIGHT, RIGHT_TO_LEFT, TOP_TO_BOTTOM,
        BOTTOM_TO_TOP, TOP_LEFT_TO_BOTTOM_RIGHT,
        TOP_RIGHT_TO_BOTTOM_LEFT, BOTTOM_LEFT_TO_TOP_RIGHT,
        BOTTOM_RIGHT_TO_TOP_LEFT};
	
	
	// The constructor takes the puzzle file name as a parameter, reads the
	// contents of the file, and initializes the puzzle from that content
	WordPuzzle(string puzzleFileName);
	
	
	// This function takes a word as a parameter and searches it from
	// left to right in the puzzle. If it finds the word in the puzzle,
	// it returns true and the numbers of the row and column at which
	// the word starts. Otherwise, it returns false.
	bool searchLeftToRight(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// right to left in the puzzle. If it finds the word in the puzzle,
	// it returns true and the numbers of the row and column at which
	// the word starts. Otherwise, it returns false.
	bool searchRightToLeft(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// top to bottom in the puzzle. If it finds the word in the puzzle,
	// it returns true and the numbers of the row and column at which
	// the word starts. Otherwise, it returns false.
	bool searchTopToBottom(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// bottom to top in the puzzle. If it finds the word in the puzzle,
	// it returns true and the numbers of the row and column at which
	// the word starts. Otherwise, it returns false.
	bool searchBottomToTop(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// top-left to bottom-right (diagonally) in the puzzle. If it finds
	// the word in the puzzle, it returns true and the numbers of the row
	// and column at which the word starts. Otherwise, it returns false.
	bool searchTopLeftToBottomRight(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// top-right to bottom-left (diagonally) in the puzzle. If it finds
	// the word in the puzzle, it returns true and the numbers of the row
	// and column at which the word starts. Otherwise, it returns false.
	bool searchTopRightToBottomLeft(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// bottom-left to top-right (diagonally) in the puzzle. If it finds
	// the word in the puzzle, it returns true and the numbers of the row
	// and column at which the word starts. Otherwise, it returns false.
	bool searchBottomLeftToTopRight(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter and searches it from
	// bottom-right to top-left (diagonally) in the puzzle. If it finds
	// the word in the puzzle, it returns true and the numbers of the row
	// and column at which the word starts. Otherwise, it returns false.
	bool searchBottomRightToTopLeft(string word, int& row, int& column);
	
	
	// This function takes a word as a parameter, calls 8 different
	// functions, defined above, each of which searches in a particular
	// direction. If it finds the word, it returns the direction in which it
	// finds the word and the numbers of the row and column at which the
	// word starts. If it does not find the word, it returns NONE.
	Direction solvePuzzle(string word, int& row, int& column);
	
	
	// This function takes two parameters (the names of two files). It
	// reads a list of words from the first file, searches these words
	// in the puzzle and writes the search results in a new output file,
	// whose name is provided as the second parameter. Please see the
	// homework description for the format of the results.
	void solvePuzzle(string wordListFileName, string outputFileName);
	
	
	// This function takes a word and its search results (direction,
	// starting row number, and starting column number) and writes the
	// solution on the screen. The solution contains 3 lines: the first
	// line contains the characters of the word, the second line contains
	// the row number of each character, and the third line contains
	// the column number of each character. For the words that do not
	// exist in the puzzle, the system will just give a message on
	// the screen. Please see the homework description for the detailed
	// format of the solution.
	void displaySolution(string word, Direction dir, int row, int column);
	
	
//private:
	char puzzle[numOfRow][numOfColumn];
	
};
