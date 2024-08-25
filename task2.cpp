#include<iostream>
using namespace std;

int main() {
     
    cout<<"Enter 1 for addition between two numbers"<<endl;
    cout<<"Enter 2 for subtraction between two numbers"<<endl;
    cout<<"Enter 3 for multiplication between two numbers"<<endl;
    cout<<"Enter 4 for division between two numbers"<<endl;
    int n;
    cin>>n;

    if(n==1) {
        cout<<"You have selected addition"<<endl;
        cout<<"Enter the first number"<<endl;
        int a;
        cin>>a;

        cout<<"Enter the second number"<<endl;
        int b;
        cin>>b;
        int sum = a+b;
        cout<<"The sum is :- "<<sum<<endl;
    } 
    else if(n==2) {
        cout<<"You have selected subtraction"<<endl;
        cout<<"Enter the first number"<<endl;
        int a;
        cin>>a;

        cout<<"Enter the second number"<<endl;
        int b;
        cin>>b;
        int diff=a-b;
        cout<<"The diff is:- "<<diff<<endl;
    } else if(n==3) {
        cout<<"You have selected multiplication"<<endl;
        cout<<"Enter the first number"<<endl;
        int a;
        cin>>a;

        cout<<"Enter the second number"<<endl;
        int b;
        cin>>b;
        int mul=a*b;
        cout<<"The product is :- "<<mul<<endl;
    } else if(n==4) {
        cout<<"You have selected division"<<endl;
        cout<<"Enter the first number"<<endl;
        int a;
        cin>>a;

        cout<<"Enter the second number"<<endl;
        int b;
        cin>>b;
        int div= b/a;
        cout<<"The division is:- "<<div<<endl;
    } else {
        cout<<"Invalid input"<<endl;
    }
    cout<<"Thank you"<<endl;
}
