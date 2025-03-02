#include <iostream>
#include <cmath>
#include "list.h"

using namespace std;


struct term{
    float coefficient;
    int exponent;
};

template <typename T>
class polynomials {

public:
    polynomials() {};
    LinkedList<term> terms; //we defined the list of type term (struct) named terms where we compute the terms of polynomials


    //point b - adding the polynomials term in the list
    void addTerm(term t) {
        if (t.coefficient != 0)     //we verify to not have terms with coefficient 0
            terms.addLast(t);      //because the terms was declared as LinkedList we use the declarations from header file
    }


    //point c in main

    //point d - calculate the value of a given polynomial
    float calculate(float x) {
        float result = 0.0;
        Node<term> *i = terms.pfirst; //we take the pointer i for go from a node to another until it is null
        while (i != nullptr) {
            result = result + (i->info).coefficient * (pow)(x, (i->info).exponent);
            i = i->next;
        }
        return result;
    }

    //point e - sum

    polynomials<term> sum(polynomials<term> p1, polynomials<term> p2) { //polynomials<term> is the class polynomial of type term
        polynomials<term> result;

        Node<T>* n1 = p1.terms.pfirst; //we take n1 the pointer for the first term of the sum (e.g. a+b , here n1 is a) and n1 memorize the adress of the 1st element
        Node<T>* n2 = p2.terms.pfirst; //we tale n2 the pointer for the second term of the sum (b) and n2 memorize the adress of the 2nd element


        while (n1 != nullptr || n2 != nullptr) { //while n1 OR n2 is/are not nullptr - null pointer? i guess :) - recommended by C-Lion
            if (n1 == nullptr) {
                while (n2 != nullptr) {
                    result.addTerm(n2->info);
                    n2 = n2->next;
                }
                break;
            }

            if (n2 == nullptr) {
                while (n1 != nullptr) {
                    result.addTerm(n1->info);
                    n1 = n1->next;
                }
                break;
            }

            if (n1->info.exponent > n2->info.exponent) { //if the exponent for n1 is bigger than exp. for n2
                result.addTerm(n1->info); //we add the results from n1 to the result list
                n1 = n1->next;
            } else if (n1->info.exponent < n2->info.exponent) {
                result.addTerm(n2->info);
                n2 = n2->next;
            } else {
                T value = {n1->info.coefficient + n2->info.coefficient, n1->info.exponent}; // if the exponents are equal, we compute the sum of the coefficients
                result.addTerm(value);
                n1 = n1->next;
                n2 = n2->next;
            }
        }

        return result;
    }

    //point f - multiplication
    polynomials <term> product(polynomials<term> v1, polynomials<term> v2) {
        polynomials<term> products;

        Node<term> *n1 = v1.terms.pfirst; //we memorise the adress to v1
        while (n1 != nullptr)
        {
            Node<term> *n2 = v2.terms.pfirst; //we memorise the adress to v2

            while(n2!=nullptr)
            {
                T value = {(n1->info).coefficient * (n2->info).coefficient, (n1->info).exponent + (n2->info).exponent};
                products.addTerm(value);
                n2 = n2->next;
            }
            n1 = n1->next;
        }

        return products;
    }
};
///////////////////////////////////////////////////////////////////////////
int main() {

    LinkedList<polynomials<term>> allPolynomials;
    float c; //c - coefficient
    int e;  // e - exponent
    int degree; //degree of the polynomial
    int nOfPol; // number of polynomials
    term Term;
    cout << "How many polynomials you will add? ";
    cin >> nOfPol; //number of polynomials
    for (int j = 1; j <= nOfPol; j++) {
        polynomials<term> polynomial;
        cout << "###########################";
        cout << "Degree of the polynomial: ";
        cin >> degree;
        for (int i = degree; i >= 0; i--) {
            cout << "Enter the coefficient: ";
            cin >> c;
            cout << "Enter the exponent: ";
            cin >> e;
            cout << "----------------" << endl;
            Term = {c, e};
            polynomial.addTerm(Term);
        }
        allPolynomials.addLast(polynomial);
    }
    Node<polynomials<term>> *index = allPolynomials.pfirst;
    int i = 0, count = 0;
    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "All the Polynomials" << endl;
    while (index) {
        i++;
        cout << "Polynomial no " << i << ": ";
        Node<term> *termIndex = (index->info).terms.pfirst;
        Node<term> *verify;

        while (termIndex) {
            verify=termIndex->next;
            if(verify!=NULL)
            { cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent << " + ";}
            else
                cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent;
            termIndex = termIndex->next;
        }
        cout<< endl;
        index = index->next;
    }
    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Additions" << endl;
    polynomials<term> sumPol;
    index = allPolynomials.pfirst;
    while (index) {
        sumPol = sumPol.sum(sumPol, index->info);
        index = index->next;
    }
    Node<term> *termIndex = sumPol.terms.pfirst;
    Node<term> *verify;
    cout << "The sum of all polynomials: ";
    while (termIndex) {
        verify=termIndex->next;
        if(verify!=NULL)
        { cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent << " + ";}
        else
            cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent;
        termIndex = termIndex->next;
    }
    cout<< endl;

    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Multiplication" << endl;
    polynomials<term> prodPol;
    prodPol.addTerm({1,0});
    index = allPolynomials.pfirst;
    while (index) {
        prodPol = prodPol.product(prodPol, index->info);
        index = index->next;
    }
    termIndex = prodPol.terms.pfirst;

    cout << "The product of all polynomials: ";
    while (termIndex) {
        verify=termIndex->next;
        if(verify!=NULL)
        {
            cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent << " + ";
        }
        else
            cout << (termIndex->info).coefficient << "x^" << (termIndex->info).exponent;
        termIndex = termIndex->next;
    }
    cout<< endl;
    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;
    cout<<"We calculate the product and the sum of the polynomials ";
    int x;
    cout<<"Write a value for x .. ";
    cin>>x;
    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

    cout<<"Product: ";
    cout<<prodPol.calculate(x)<<endl;
    cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

    cout<<"Sum: ";
    cout<<sumPol.calculate(x)<<endl;
    return 0;

};