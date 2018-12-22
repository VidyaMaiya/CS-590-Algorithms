#include<iostream>
#include <stack>
#include<climits>
using namespace std;

class Queue{
private:
    stack<int> stack1, stack2;
public:
    void EnQueue(int data){
          if(stack2.empty())                                   // checking Stack2 is empty or not
        {
        stack1.push(data);
        }

        else
        {
        while(!stack2.empty())                               // while stack2 is not empty
        {
        stack1.push(stack2.top());                            // pushing elements from stack2 to stack1
        stack2.pop();
        }
        stack1.push(data);                                  // pushing new elements in the stack
        }
}

    int DeQueue(){

            if(!stack1.empty())                         // if stack1 is not empty
                {
                while(!stack1.empty()){
                stack2.push(stack1.top());              // pushing the elements from stack1 to stack2
                stack1.pop();
                cout <<  stack2.top() << '\n';
                }
                }
                 int temp=stack2.top();
                stack2.pop();
        return temp;                                   
}
};

int main(){
    Queue q;
    for(int i=0; i<10; i++)
        q.EnQueue(i);
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    for(int i=10; i<20; i++){
        q.EnQueue(i);
    }
    cout<<q.DeQueue()<<" ";
    cout<<q.DeQueue()<<'\n';

    return 0;
}