## Program Description 

This program is the third version of the iterative c++ tic tac toe board game. 
In this program, we have implemented the following changes and use cases: 

* Users can assign themselves user names. To achieve this we use dynamic memory that is 
sustained throughout the program until the game ends. 
* Renamed updatePlayerTurn() function to updateMove() to more precisely describe the function 
name for what the function is doing. 

## Upcoming Features / Use Cases 
* Use C++ object oriented programming for classifying in-game objects. 
* Validate user input for the marker. 

## Bug fixes
* The first player now gets recognized for winning. Initially the program was missing the 
condition in which the first player won. 

## Sample Output of Program

> Welcome! 
> 
> Player one choose your marker (X or O): X
> Player one, enter your name: Kevin Patel
> Player two, enter your name: Steve Jobs
>  1 | 2 | 3
> -----------
>  4 | 5 | 6
> -----------
>  7 | 8 | 9

> It's Kevin Patel's turn. Enter your slot: 1
>  X | 2 | 3
> -----------
>  4 | 5 | 6
> -----------
>  7 | 8 | 9

> It's Steve Jobs's turn. Enter your slot: 2
> X | O | 3
> -----------
>  4 | 5 | 6
> -----------
>  7 | 8 | 9

> It's Kevin Patel's turn. Enter your slot: 5
>  X | O | 3
> -----------
>  4 | X | 6
> -----------
>  7 | 8 | 9

> It's Steve Jobs's turn. Enter your slot: 3
>  X | O | O
> -----------
>  4 | X | 6
> -----------
>  7 | 8 | 9

> It's Kevin Patel's turn. Enter your slot: 9
>  X | O | O
> -----------
>  4 | X | 6
> -----------
>  7 | 8 | X


>  Kevin Patel won! 

> Destroying board...

> Board destroyed...

## Program Deployment 
If you enjoyed learning about this program feel free to give it a go 
by copying the main.cpp file and running it on the following online c++ gdb compiler
* https://www.onlinegdb.com/online_c++_compiler

   

