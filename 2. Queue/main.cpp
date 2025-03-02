#include <iostream>
#include <fstream>
#include "queuecircular.h"

using namespace std;

struct Order{
    int time, duration;
};

int main()
{
    ifstream fin("ordersin.txt"); //reading from the file named "ordersin.txt"
    int N, T,i; //N-total number of orders, T- closing time, t-time arrival, d-time for making the dish
    QueueCirc <Order> orders; // we declare the queue as type Order (declared as a struct) where we will store the orders
    QueueCirc <Order> backupOrder; //we will use this to compute the maximum time for a single order, its the copy of the queue "orders"
    //cout<<"Number of orders: ";
    fin>>N;
    //cout<<"Restaurant closing time: ";
    fin>>T;
    cout<<"--------------"<<endl;
    cout<<"The total number of orders is "<<N<<" and the closing time is "<<T<<"!"<<endl;
    cout<<"--------------"<<endl;

    int OrderNo = 1;
    for(i=0;i<N;i++){
        Order order;    //we declare the order variable of type Order (Order it's a struct declared previously)
        cout<<"~ New order #"<<OrderNo<<" ~" <<endl;
        OrderNo++;
        cout<<"#Time: ";
        fin>>order.time; // we need to read from the file the value for "arrival time" declared in struct
        cout<<order.time<<endl;
        cout<<"#The time to prepare the dish: ";
        fin>>order.duration; // we need to read the value for "time to prepare the dish" declared in struct
        cout<<order.duration<<endl;
        cout<<"--------------"<<endl;
        orders.enqueue(order);  //we store the order in the queue orders
        backupOrder.enqueue(order);  // we store the order in the backupOrder in order to compute the maximum time for a single order
    }

    //point b: print all the times when our chef can take a breather
    int totaltime=0,hour=0; //totaltime will memorise the time when the orders will be ready from break to break
    while(orders.isEmpty()==0 && orders.peek().time<T) {

        hour=orders.peek().time; // we take the hour when the order was placed
        if (totaltime < hour && totaltime<T)
        // "if" verify if the totaltime when the orders are ready is smaller than the hour, if it is we display the time when the chef will have a break
        {
            cout << "Chef can take a breather from " << totaltime << " to " << hour << endl;
            totaltime=orders.peek().duration+hour; //when we display the break time, we put into the totaltime the current hour + the duration of the order e.g. arrival time = 10, time to prepare the dish = 3, so the totaltime is 13
        }
        else{
            totaltime = totaltime + orders.peek().duration;
            // if the "if" is not valid, then we add to the totaltime the time to prepare the dish e.g. if the total time has order 1 and 2, t
        }
        orders.dequeue();
    }

    orders=backupOrder; //we copy the data from 'backupOrder' to 'orders' for using it in the d point

    // point c: print the maximum duration our chef has to work on a single order
    int maxtime=0;  //we declare max - this will tell us the maximum time needed for a single order to be ready
    int preptime=0; //preptime will store the time to prepare the dish from the queue
    cout<<"--------------"<<endl;

    while(backupOrder.isEmpty()==0)  //we will do the "while" for calculate the maximum time our chef has to work for one order while the queue is not empty
    {
        preptime=backupOrder.peek().duration; //we save in the preptime the duration
        if(preptime>maxtime)  //we compare if the preptime is greater than maxtime
            maxtime=preptime; //if it is we put it in the maxtime
        backupOrder.dequeue(); //and we delete the time from the backupOrder queue
    }
    cout<<"The maximum duration our chef has to work on a single order is: "<<maxtime<<endl; //then we display the maxtime
    cout<<"--------------"<<endl;


    //point d: print the expected time (by the client) and the actual completion time for each order
    i=1; //we take i as a counter for the orders output
    totaltime=0;
    int incomplete=0; // in the 'incomplete' variable we will count how many orders will remain incomplete after the closing time
    while(orders.isEmpty()==0 && orders.peek().time<T){
        int expectedTime=orders.peek().time+orders.peek().duration; //the expected time is the sum of the time arrival of the client and the time of preparing the dish
        hour=orders.peek().time; // we use the same algorithm as we used at b point
        if (totaltime < hour) { //we compute the 'totaltime' in 2 ways because we need to take the 'break time' in consideration
            totaltime=orders.peek().duration+hour;
        }
        else{
            totaltime = totaltime + orders.peek().duration;
        }
        if(totaltime<T)   //we display the expected time and the actual completion time only if it is in the working time
            cout<<"Order "<<i<<": expected completion time: "<<expectedTime<<", actual completion time: "<<totaltime<<endl;
        else
            incomplete++; //if the totaltime
        i++;

        orders.dequeue();
    }
    cout<<"--------------"<<endl;

    //point d: determine if there are orders that remain incomplete
    // we calculated the incomplete variable in the point c, so we have to display if there are incomplete orders or not
    if(incomplete>0){
        if(incomplete==1)
            cout<<"There is 1 order that remains incomplete!"<<endl;
        else
            cout<<"There are "<<incomplete<<" orders that remains incompletete!"<<endl;
    }
    else{
        cout<<"No incomplete orders!";
    }
    cout<<"--------------"<<endl;



}
