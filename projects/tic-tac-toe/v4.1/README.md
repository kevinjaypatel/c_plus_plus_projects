## Program Description 

This is the fourth version of our iterative c++ tic tac toe board game. We are following 
a [Udemy course on C++](https://www.udemy.com/course/cpp-deep-dive/) from instructor [Abdul Bari](https://www.udemy.com/user/mohammed-abdul-bari-2/) 
and directly applying the concepts to building this board game and other future projects. 
 
In this program, we have implemented the following changes and use cases: 

* Scope Resolution Operator - We define the member functions of our class instances outside the class scope. When we define 
member functions outside the scope of the object class, the code section of our application allocates space for them outside as opposed to inline
as they would be if they were defined inside the class. Some members functions, in particular, our accessor functions are defined in the class 
themselves, however they perform negligble logic, they simply return the value of data members in most cases.    

## Program Deployment 
If you enjoyed learning about this program feel free to give it a go 
by copying the `main.cpp` file and running it on the [online c++ gdb compiler](https://www.onlinegdb.com/online_c++_compiler)