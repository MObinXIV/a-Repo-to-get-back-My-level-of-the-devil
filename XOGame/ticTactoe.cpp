// XO
#include<bits/stdc++.h> 
 using namespace std; 
class TicTacToe 
 {
    private:
    char board[3][3];
    char currentPlayer; // use it to switch between players
    public:
    // Constructor to initialize the board
    TicTacToe(){
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j]=' ';
            }
        }
        currentPlayer='X'; // Start game always with player X
    }
    // function to handle game logic
    void startGame(){
        int filled=0;
       do
       {
              DrawBoard();
              int x,y;
              cout<<"Enter the value of x and y";
              
              cin>>x>>y;
              // Validate input
              while(x < 0 || x >= 3 || y < 0 || y >= 3 ||board[x][y]!=' ')
              {
                cout<<"Already filled location! Please choose again! " << endl;
                cin >> x >> y;  
                }
// Place the current player's mark on the board
            board[x][y] = currentPlayer;
                 filled++;
                  // Check for a winner
            if(isWinner()) {
                DrawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                return;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
       } while (filled<9 );
       DrawBoard();
       cout<<"Game is a draw"<<endl;
    }
    
    void DrawBoard()
{
    for(int i=0;i<7;i++)
    {
        if(!(i%2))
        {
            for(int i=0;i<12;i++)
            {
                cout<<"-";
            }
        }
        else
        {
            for(int j=0;j<4;j++)//to iterate through 4 columns. This is because each cell is followed by a vertical bar (|), and there are 3 cells per row.
            {
                if(board[i/2][j]&&j<3)// if the cell is not empty and the column is less than 3
                {
                   cout<<"| "<<board[i/2][j]<<" ";
                }
                else
                {
                    cout<<"|   ";
                }
            }
        }
        cout<<endl;
    }
	
}
    char checkWinner()
    {
        
         // Diagonal check 
            if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ' || board [2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[2][0]!=' ')
            {
                return board[1][1];
            }
            //rows equalizers
                for(int i=0;i<3;i++)
                {
                    
                    if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' ') //equals and the first cell not empty
                    {
                       return board[0][i];
                    }
                    
                }
                
                //columns equalizers
                for(int i=0;i<3;i++){
                    if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
                    {
                        return board[i][0];
                    }
                }
            
            return' ';
        }

         bool isWinner() {
        char winner = checkWinner();
        return (winner == 'X' || winner == 'O');
    }
 };
 int main() 

 {     
        TicTacToe* t = new TicTacToe();
       t->startGame();
       cout<<endl;
       delete t;
 }
 