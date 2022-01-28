// Simple Tic-Tac-Toe game developed for learning C++ 
// 
// Version: 4 

// TODO: Validate character input from user at the beginning of the game
#include <iostream>
#include <string> 

using namespace std;

class Player {
    private: 
        int id; 
        string name;
        char marker; 
        
    public: 
    
        Player(int i) {
            this->id = i; 
        }
        
        void setMarker(char m, bool isFirstPlayer=false) {
            if(isFirstPlayer) {
                cout << "Setting first player marker: " << m << endl; 
                this->marker = m; 
            } else {
                
                cout << "Setting second player marker: "; 
                this->marker = (m == 'X') ? 'O' : 'X'; 
                cout << this->marker << endl; 
            }
        } 
        char getMarker() {
            return this->marker; 
        }
        void setName(string n) {
            this->name = n; 
        }
        string getName() {
            return this->name; 
        } 
        void setId(int n) {
            this->id = n; 
        } 
        int getId() {
            return this->id; 
        }
        bool validateMarker(char m); 
}; 

class Board {
    private:
        const int rows = 3; 
        const int columns = 3;
        // 2d matrix 
        char **matrix; 
        
    public:
    
        int getRows() {
            return this->rows; 
        } 
        
        int getColumns() {
            return this->columns; 
        }
        
        void initBoard() {
            cout << "Initializing board ...\n"; 
            this->matrix = new char*[rows]; 
            // initializes a board of size: rows * columns
            for(int row = 0; row < rows; row++) {
                this->matrix[row] = new char[columns]; 
            }
            
            char slot = '1'; 
            for(int row = 0; row < rows; row++) {
                for(int col = 0; col < columns; col++) {
                    this->matrix[row][col] = slot; 
                    slot++; 
                }
            }
            cout << "Board created ...\n"; 
        }
        
        void desctructBoard() {
            cout << "\nDestroying board ...\n";
            for(int row = 0; row < rows; row++) {
                delete[] this->matrix[row]; 
            }
            delete[] this->matrix; 
            cout << "\nBoard destroyed...\n";
        } 
        
        void draw() {
            cout << " " << this->matrix[0][0] << " | " << this->matrix[0][1] << " | " << this->matrix[0][2] << endl; 
            cout << "-----------\n"; 
            cout << " " << this->matrix[1][0] << " | " << this->matrix[1][1] << " | " << this->matrix[1][2] << endl; 
            cout << "-----------\n"; 
            cout << " " << this->matrix[2][0] << " | " << this->matrix[2][1] << " | " << this->matrix[2][2] << endl; 
            cout << endl;
        } 
        
        int *getSlotRowAndColumn(char slot) {
            int row, column = 0; 
            static int cell[2] = {row, column}; 
            static int *p = nullptr; 
            
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
            
            cell[0] = row; 
            cell[1] = column; 
            p = cell; 
            return p;
        }
        
        // this function takes a slot chosen from the user on the 
        // board and assigns the current players marker there
        void placeMarker(char slot, Player *current) {
            int* cell = getSlotRowAndColumn(slot); 
            int row = cell[0], column = cell[1];  
            
            // initialize board at the cell with current marker 
            this->matrix[row][column] = current->getMarker();
        }; 
        
        bool slotIsValid(char slot) {
            bool slotInRange = slot >= '1' && slot <= '9'; 
            if(!slotInRange) return false; 
            
            int *checkCell = this->getSlotRowAndColumn(slot); 
            int row = checkCell[0], column = checkCell[1]; 
            // ensure that 'X' / 'O' doesn't already exist at that location on the board
            bool isEmpty = this->matrix[row][column] != 'X' && this->matrix[row][column] != 'O'; 
    
            return isEmpty; 
        }
        
        bool checkRowWin(int row) {
            return this->matrix[row][0] == this->matrix[row][1] && this->matrix[row][1] == this->matrix[row][2]; 
        }
        
        bool checkColumnWin(int col) {
            return this->matrix[0][col] == this->matrix[1][col] && this->matrix[1][col] == this->matrix[2][col]; 
        }
        
        bool checkDiagonalWin() {
            return this->matrix[0][0] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[2][2] || 
                this->matrix[0][2] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[2][0]; 
        }
        
        // this function checks to see if the current player that set the 
        // mark made a winning play 
        bool isWinner() {
            for(int boardIndex = 0; boardIndex < rows; boardIndex++) {
                // check row win
                if(checkRowWin(boardIndex)) return true; 
                // check column win 
                if(checkColumnWin(boardIndex)) return true;  
            }
            // check diagonal win 
            if(checkDiagonalWin()) return true;  
            
            // no one has won 
            return false; 
        }
}; 

void assignMarkers(Player &one, Player &two) {
    cout << "Welcome! \n";
    cout << "Player one choose your marker (X or O): ";
    char marker; 
    cin >> marker; 
    cin.ignore(); 
    one.setMarker(marker, true); 
    two.setMarker(marker);
}

void initPlayerNames(Player &one, Player &two) {
    string first, second; 
    cout << "Player one, enter your name: "; 
    getline(cin, first); 
    
    cout << "Player two, enter your name: "; 
    getline(cin, second); 
    
    one.setName(first); 
    two.setName(second); 
}

// updates the current move in the game 
// used to help the game approach closer to an end 
void updateMove(int &move) {
    move++;     
}

void game() {
    // initalize the board 
    Board board; 
    board.initBoard(); 
    // initalize the players 
    Player p1(0), p2(1);
    assignMarkers(p1, p2);
    initPlayerNames(p1, p2);
    
    Player *currentPlayer = &p1;
    board.draw(); 
    
    int i = 0; 
    int winner = 0; 
    int maxMoves = board.getRows() * board.getColumns();
    for(; i < maxMoves; ) {
        cout << "It's " << currentPlayer->getName() << "'s turn. Enter a slot: ";
        char slot; 
        cin >> slot; 
        cin.ignore(); 
        
        if(board.slotIsValid(slot)) {
            board.placeMarker(slot, currentPlayer); 
            winner = board.isWinner();
            cout << "Winner = " << winner << endl; 
            if(winner > 0) {
                board.draw(); 
                cout << "\n " << currentPlayer->getName() << " won! \n";
                break; 
            }
            
            // swap players 
            if(currentPlayer->getId() == 0) {
                currentPlayer = &p2; 
            } else {
                currentPlayer = &p1; 
            }
            board.draw(); 
            updateMove(i); 
        } else {
            cout << "\nInvalid slot entry. Re-enter the slot \n"; 
        }
    }
    
    if(winner <= 0) {
        board.draw(); 
        cout << "\nTie game! \n"; 
    }     
    
    board.desctructBoard(); 
    
}; 

int main()
{
    game(); 
    return 0; 
}



