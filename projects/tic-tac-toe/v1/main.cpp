// Simple Tic-Tac-Toe game developed for learning C++ 
// 
// Version: 1 
#include <iostream>

using namespace std;

const int rows = 3; 
const int columns = 3; 

char current_marker; 
int current_player; 

char board[rows][columns] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
}; 

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl; 
    cout << "-----------\n"; 
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl; 
    cout << "-----------\n"; 
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl; 
    cout << endl;
}; 

void swap_players() {
    if(current_marker == 'X') current_marker = 'O'; 
    else current_marker = 'X'; 
    
    if(current_player == 1) current_player = 2; 
    else current_player = 1; 
}; 

// this function takes a slot chosen from the user on the 
// board and assigns the current players marker there
void placeMarker(char slot) {
    int rowPlacement, colPlacement = 0; 
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            char currentChar = board[row][col]; 
            if(currentChar == slot) {
                rowPlacement = row; 
                colPlacement = col; 
            }
        }
    }
    board[rowPlacement][colPlacement] = current_marker; 
}; 

bool checkRowWin(int row) {
    return board[row][0] == board[row][1] && board[row][1] == board[row][2]; 
}; 

bool checkColumnWin(int col) {
    return board[0][col] == board[1][col] && board[1][col] == board[2][col]; 
};

bool checkDiagonalWin() {
    return board[0][0] == board[1][1] && board[1][1] == board[2][2] || 
        board[0][2] == board[1][1] && board[1][1] == board[2][0]; 
}; 

// checks for a win after the current player marks a slot 
// on the tic-tac-toe board 
int getWinner () {
    
    for(int boardIndex = 0; boardIndex < rows; boardIndex++) {
        // check row win
        if(checkRowWin(boardIndex)) return current_player; 
        // check column win 
        if(checkColumnWin(boardIndex)) return current_player; 
    }
    // check diagonal win 
    if(checkDiagonalWin()) return current_player; 
    
    // no one has won 
    return 0; 
}; 

void game() {
    cout << "Player one choose your marker: "; 
    char p1_marker; 
    cin >> p1_marker; 
    
    current_marker = p1_marker; 
    current_player = 1; 
    drawBoard(); 
    
    int winner = 0; 
    int maxMoves = rows * columns; 
    for(int i = 0; i < maxMoves; i++) {
        cout << "It's player " << current_player << "'s turn. Enter your slot: "; 
        char slot; 
        cin >> slot; 
        
        placeMarker(slot); 
         
        winner = getWinner(); 
        if(winner == 1) {
            drawBoard(); 
            cout << "Player one won! ";
            break; 
        } else if(winner == 2) {
            drawBoard(); 
            cout << "Player two won! ";
            break; 
        }
        
        swap_players(); 
        drawBoard();
        
    }
    
    if(winner == 0) {
        drawBoard(); 
        cout << "Tie game! \n"; 
    }
    
    
}; 

int main()
{
    game(); 
    return 0; 
}


