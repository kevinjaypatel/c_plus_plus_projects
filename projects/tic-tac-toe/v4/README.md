## Program Description 

This is the fourth version of our iterative c++ tic tac toe board game. We are following 
a [Udemy course on C++](https://www.udemy.com/course/cpp-deep-dive/) from instructor [Abdul Bari](https://www.udemy.com/user/mohammed-abdul-bari-2/) 
and directly applying the concepts to building this board game and other future projects. 
 
In this program, we have implemented the following changes and use cases: 

* Object Oriented Programming: We now have two classified objects that are used in our game: Board, Player
* Static variables: Our program uses static variables as a way to sustain memory allocation 
throughout the program during function execution 
* Default Arguments: Default arguments help us reduce the number of overloaded functions in our 
program. In our `Player` class, we use default arguments to determine which player is setting 
their `marker` preference to be used in the board game. The first player has the option of setting 
their `marker` preference, whereas the second player instance is assigned a default `marker` 
(opposite of that of the first player). 
* Usage of `string` library: We now import the string library and make use of it to assign player names. In our previous version, v3, we developed our own implementation of 
this feature. The perks of using the string library here is that we are able to use the pre-defined functionality of a class object instead of having to implement it ourselves. In our previous implmentation for storing player names, we allocated a fixed size in memory to store the characters, however, we did not define an approach to resize the memory
in the case the player enters more characters for their name. The benefit of using the string library is that it handles that for us! 

## Upcoming Features / Use Cases 
* Give users the option to declare a tie or forfeit the match (either or) :-) 
* Validate user input for the marker. 

## Bug Fixes
* We weren't correctly validating wins. The way we were comparing a potential row win 
was like so, `board[row][0] == board[row][1] == board[row][2]` however that would evaluate to false. 
To return the correct result, we made the following adjustment to our code and returned a potential 
row win like so, `board[row][0] == board[row][1] && board[row][1] == board[row][2]`  
* Initially member functions in our `Board` class were having trouble recognizing the `Player` 
class. Once we declared our `Player` class implementation above the `Board` class implementation, 
it seemed to have resolved the issue and the compiler was able to produce an executable.   

## Program Deployment 
If you enjoyed learning about this program feel free to give it a go 
by copying the `main.cpp` file and running it on the [online c++ gdb compiler](https://www.onlinegdb.com/online_c++_compiler)
