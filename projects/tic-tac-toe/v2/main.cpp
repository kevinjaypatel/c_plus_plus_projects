 #include <iostream>

using namespace std;

const int rows = 3; 
const int columns = 3; 

char current_marker; 
int current_player; 

// defines a variable to be used for pointing to the rows of the board
typedef char* charArrayPtr; 
// declares a variable that will be used to instantiate the board 
charArrayPtr* board;  

void destructBoard() {
    cout << "\nDestroying board...\n"; 
    for(int row = 0; row < rows; row++) {
        delete[] board[row]; 
    }
    delete[] board; 
    cout << "\nBoard destroyed...\n"; 
}

void printBoard() {
    cout << "\nPrinting contents of board\n"; 
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            cout << board[row][col] << endl; 
        }
    }
}

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl; 
    cout << "-----------\n"; 
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl; 
    cout << "-----------\n"; 
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl; 
    cout << endl;
};

void initBoard() {
    cout << "Initializing board ...\n"; 
    board = new charArrayPtr[rows]; 
    // initializes a board of size: rows * columns
    for(int row = 0; row < rows; row++) {
        board[row] = new char[columns]; 
    }
    
    char slot = '1'; 
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            board[row][col] = slot; 
            slot++; 
        }
    }
    cout << "\nBoard created ...\n"; 
}

void swap_players() {
    if(current_marker == 'X') {
        current_marker = 'O';
    } 
    else {
      current_marker = 'X';  
    }  
    
    if(current_player == 1) {
        current_player = 2; 
    }
    else {
        current_player = 1; 
    }    
}; 

// this function returns a pointer to an array which stores the first element 
// as the given slot's row, and the second element as the slot's column 
int* getSlotRowAndColumn(char slot) {
    int row, column = 0; 
    // convert slot to int
    int intSlot = slot - '0';
    // check if slot is factor of 3
    if(intSlot % 3 == 0) {
        column = 2; 
        row = (intSlot / 3) - 1;  
    } else {
        column = (intSlot % 3) - 1;
        row = intSlot / 3; 
    }
    
    int cell[2] = {row, column}; 
    int* p = cell; 
    return p; 
}; 

// this function takes a slot chosen from the user on the 
// board and assigns the current players marker there
void placeMarker(char slot) {
    int* cell = getSlotRowAndColumn(slot); 
    int row = cell[0]; 
    int column = cell[1]; 

    // initialize board at the cell with current marker 
    board[row][column] = current_marker;
}

void updatePlayerTurn(int& i) {
    i++; 
}

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
int checkWinner () {
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

bool slotIsValid(char slot) {
    bool slotInRange = slot >= '1' && slot <= '9'; 
    if(!slotInRange) {
        return false; 
    }
    
    int* checkCell = getSlotRowAndColumn(slot); 
    int row = checkCell[0]; 
    int column = checkCell[1]; 
    // ensure that 'X' / 'O' doesn't already exist at that location on the board
    bool isEmpty = board[row][column] != 'X' && board[row][column] != 'O'; 
    
    return isEmpty; 
}

void game() {
    initBoard(); 
    
    cout << "Player one choose your marker (X or O): "; 
    char p1_marker; 
    cin >> p1_marker; 
    
    current_marker = p1_marker; 
    current_player = 1; 
    drawBoard(); 
    
    int winner = 0; 
    int maxMoves = rows * columns; 
    for(int i = 0; i < maxMoves; ) {
        
        cout << "It's player " << current_player << "'s turn. Enter your slot: "; 
        char slot; 
        cin >> slot; 
        
        if(slotIsValid(slot)) {
            placeMarker(slot); 
            winner = checkWinner(); 
            if(winner == 1) {
                drawBoard(); 
                cout << "\nPlayer one won! \n";
                break; 
            } else if(winner == 2) {
                drawBoard(); 
                cout << "\nPlayer two won! \n";
                break; 
            }
            
            swap_players(); 
            drawBoard();    
            updatePlayerTurn(i);  
            
        } else {
            cout << "\nInvalid slot entry. Re-enter the slot \n"; 
        }
    }
    
    if(winner == 0) {
        drawBoard(); 
        cout << "\nTie game! \n"; 
    } 
}; 

int main()
{
    game(); 
    destructBoard(); 
    return 0; 
}


