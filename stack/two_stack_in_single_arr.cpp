#include <iostream>

using namespace std;

template<class T>
class Stack {
    private:
        T* S;
        int t1, t2, len, size;
    public:
        // Stack(int);
        // ~Stack();
        // void push1(T val);
        // void push2(T val);
        // void pop1(T &val);
        // void pop2(T &val);
        // void display1();
        // void display2();
        // T topmost1();
        // T topmost2();

    
    Stack(int sz){
        size=sz;
        S= new T[size];
        t1=-1;
        t2=size;
        len=0;

    }
    ~Stack(){
        delete [] S;
    }

    void push1(T val){
        if(t1< t2-1){
            S[++t1]=val;
            len++;
        }else{
            cout<<"Stack overflow"<<endl;
            return;
        }
    }
    
    void push2(T val){
        if(t1< t2-1){
            S[--t2]=val;
            len++;
        }else{
            cout<<"Stack overflow"<<endl;
            return;
        }
    }
    
    void pop1(T &val){
        if(t1==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }else{
            val=S[t1--];
            len--;
        }

    }

    void pop2(T &val){
        if(t2==size){
            cout<<"Stack is empty"<<endl;
            return;
        }else{
            val=S[t2++];
            len--;
        }
        
    }
    
    void display1(){
        cout<<"Stack 1..."<<endl;
        for(int i=0; i<= t1; i++)
        cout<<S[i]<<"\t";
        cout<<endl;
    }
    
    void display2(){
        cout<<"Stack 2..."<<endl;
        for(int i=size-1; i>= t2; i--)
        cout<<S[i]<<"\t";
        cout<<endl;
    }

    T topmost1(){
        return S[t1];
    }
    
    T topmost2(){
        return S[t2];
    }
};

int main(){
  Stack<int> st(7); 
  st.push1(10);
  st.push1(20);
  st.push1(30);

  st.push2(25);
  st.push2(35);
  st.push2(26);
  st.push2(12);

  st.push2(6);
  st.push1(2);
  st.display1();
  st.display2();

  return 0;
}