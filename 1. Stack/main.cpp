#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack <int> persons;
    int numberOfPersons, A[50][50]; //a is the matrix of interactions, I put it on 50 because that is the NMAX for stack
    int i,j, ID1, ID2; //we will use ID 1 and ID2 to get the top and the second attendee at the dinner
    int Homer=0; //here we will put the ID where Homer Simpson is identify
    cout<<"Number of person for dinner: "; //we read the number of person at the dinner
    cin>>numberOfPersons;

    i=0;
    while(i<numberOfPersons)  //while we have persons, we push them into stack
    {
        persons.push(i);
        i++;
    }

    cout<<"Matrix: "<<endl;  //we read the matrix , in the file kidnap.txt you have both matrix from examples
    for(i=0;i<numberOfPersons;i++)
        for(j=0;j<numberOfPersons;j++)
            cin>>A[i][j];

    while (persons.getTopLevel() > 0) {
        ID1 = persons.pop(); //we take the last person that arrive at the dinner
        ID2 = persons.pop(); // and the 2nd one from the top
        if (A[ID1][ID2] == 1) { //we verify the interaction between people
            persons.push(ID2); //if they they talk, that means that id1 was talking so we can eliminate it
        } else {
            persons.push(ID1); //if they don't talk that means that id2 was talking so we can eliminate it
        }
    }


    if(persons.getTopLevel()==0)
    {
        Homer=persons.peek(); //if we have only one element in the stack, we are 100% that it's Homer here so we memorise the ID
    }

    if(Homer==0){
        cout<<"Homer Simpson wasn't at the dinner.";
    }
    else{
        cout<<"Homer Simpson was at the dinner and his ID is "<<Homer<<".";
    }

    return 0;
}
