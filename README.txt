*Exercice 1*

The program first prompts the user to enter the number of persons attending the dinner.
It then reads in a square matrix of size numberOfPersons x numberOfPersons, which represents the interactions between each person.
The program creates a stack named persons and pushes the IDs of each person onto the stack.
The program then uses a while loop to iterate through the stack, popping the top two elements and checking their interaction status. If they talked to each other, the first popped element is eliminated; if they didn't, the second popped element is eliminated. The loop continues until only one person remains in the stack, which must be Homer.
The program checks if there is only one element left in the stack and if so, assigns that ID to Homer.
Finally, the program outputs whether Homer was at the dinner and if so, his ID.

Instructions:
1. You have to put the number of persons invited to dinner.
2. In the file kidnap.txt you have the examples which work 100%


*Exercice 2*

The program is designed to simulate a restaurant order system. The orders are read from a text file and stored in the QueueCirc structure, which is a circular queue implemented by the user. The program consists of four main points. Firstly, it calculates the time intervals when the chef can take a break. Then, it calculates the maximum time required by the chef for a single order. After that, it prints the expected time by the customer and the actual completion time for each order. Finally, it counts the number of orders that will remain incomplete after the restaurant closing time.

The program reads the data from a file named "ordersin.txt". The first line of the file contains the total number of orders, and the second line contains the closing time of the restaurant. Each subsequent line contains two integers separated by a space, representing the arrival time and the time required to prepare the dish, respectively. The program reads the file and stores the order details in the queue. The program then dequeues the orders one by one and calculates the required time for each task.

The program uses the circular queue structure to store and manage the orders. The circular queue data structure is similar to the linear queue data structure, but in this case, the last element is connected to the first element. Therefore, the program can use the circular queue to store orders and efficiently manage them.


*Exercice 3*

This program defines a template class "polynomials" that can store and perform operations on polynomials of type "term". The program takes user input to define multiple polynomials by asking for their degree, coefficients, and exponents. The program then stores these polynomials in a linked list of "polynomials" objects. The program also includes methods to add, calculate, sum, and multiply polynomials. The "sum" method takes two polynomial objects as input, combines their terms, and returns a new polynomial object. The "product" method multiplies two polynomial objects and returns a new polynomial object. The program then prints out all the polynomials entered by the user, and the result of adding and multiplying the first two polynomials in the list.

You can add n polynomials and to the operations for all at the same time.
All you have to do is to keep the degree from the highest to the lowest.

!!IDEA FOR G) 

code: 
LinkedList<term<complex<double>>> sumComplexPolynomials(LinkedList<term<complex<double>>> &p1, LinkedList<term<complex<double>>> &p2) {
    return sumPolynomials(p1, p2);
}

I wanted to use the existing function, just a bit modified for being a complex source for polynomials.
All the operation remains the same, the only change was to turn all into complex and says that if you have i*i its -1 and all the rules for basic operation with complex numbers.

i was thinking t
