#ifndef STACKTEMPLETEHEADER_H_INCLUDED
#define STACKTEMPLETEHEADER_H_INCLUDED

using namespace std;


template<typename Type1>

class Stack{
    private:
        Type1 * stackPtr;
        signed int tos;     // point to highest element in stack
        int stackCapacity;


    public:
        // const
        Stack(int stackElements=5);

        // copy const
        Stack(Stack& s);

        // full
        bool isStackFull (void);

        // empty
        bool isStackEmpty(void);
        // dispaly
        void stackDisplay(void);   // display all elements or display the pushed elements
        // push
        bool push(Type1 element);
        // pop
        bool pop(Type1* popedElement);
        // operators
        bool operator == (Stack& s);

        Stack* operator = (Stack& s);

        // top
        void stackTop (void);

        // destructor
        ~Stack();
};



template<typename Type1>
Stack<Type1>::Stack(int stackElements)
{
    this->stackCapacity=stackElements;
    if(stackElements>0)
    {
        this->stackPtr= new Type1[stackElements];
        this->tos=-1;
        cout<<"I'm Created"<<endl;
    }
    else
    {
        this->stackPtr=nullptr;
        cout<<"Error in Creation"<<endl;
    }
}

// copy const

template<typename Type1>
Stack<Type1>::Stack(Stack& s)
{
    this->tos=s.tos;
    this->stackCapacity=s.stackCapacity;
    this->stackPtr= new Type1 [this->stackCapacity];
    for(int i=0; i<= this->tos ;i++)
    {
        this->stackPtr[i]=s.stackPtr[i];
    }

    cout<<"In copy Constructor"<<endl;
}

// full

template<typename Type1>
bool Stack<Type1>::isStackFull (void)
{
    if(this->tos == (this->stackCapacity)-1)
    {
        cout<<"Stack is Full"<<endl;
        return true;
    }
    else
    {
        cout<<"Stack is not Full"<<endl;
        return false;
    }

}

// empty

template<typename Type1>
bool Stack<Type1>::isStackEmpty(void)
{
    if(this->tos == -1)
    {
        cout<<"Stack is Empty"<<endl;
        return true;
    }
    else
    {
        cout<<"Stack is not Empty"<<endl;
        return false;
    }

}
// dispaly

template<typename Type1>
void Stack<Type1>::stackDisplay(void)   // display all elements or display the pushed elements
{
    if(this->tos !=-1)
    {
        for(int i=0; i<= this->tos ;i++)
        {
            cout<<this->stackPtr[i]<< " | ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"No Elements to Display"<<endl;
    }

}
// push

template<typename Type1>
bool Stack<Type1>::push(Type1 element)
{
    if(this->tos >= -1 &&  this->tos < (this->stackCapacity)-1)
    {
        tos++;
        this->stackPtr[(this->tos)]=element;
        cout<<element<<"is pushed"<<endl;
        return true;
    }
    else
    {
        cout<<element<<"isn't pushed"<<endl;
        return false;
    }
}
// pop

template<typename Type1>
bool Stack<Type1>::pop(Type1* popedElement)
{
    if(this->tos > -1 &&  this->tos <= (this->stackCapacity)-1)
    {
        *popedElement = this->stackPtr[(this->tos)];
        this->stackPtr[(this->tos)]=0;
        tos--;
        cout<<(*popedElement)<<"is poped"<<endl;
        return true;
    }
    else
    {
        cout<<"Nothing Poped"<<endl;
        return false;
    }
}
// operators

template<typename Type1>
bool Stack<Type1>::operator == (Stack& s)
{
    int flag=1;
    if(this->tos!=s.tos)
        flag=0;
    if(this->stackCapacity!=s.stackCapacity)
        flag=0;
    for(int i=0; i<= this->tos ;i++)
    {
        if(this->stackPtr[i]!=s.stackPtr[i])
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<"These 2 Stacks are Equal"<<endl;
        return true;
    }
    else
    {
        cout<<"These 2 Stacks are not same"<<endl;
        return false;
    }
}


template<typename Type1>
Stack<Type1>* Stack<Type1>::operator = (Stack& s)
{
    if(this->stackPtr == s.stackPtr)
        return this;

    delete [] this->stackPtr;

    this->tos=s.tos;
    this->stackCapacity=s.stackCapacity;
    this->stackPtr= new Type1 [this->stackCapacity];
    for(int i=0; i<= s.tos ;i++)
    {
        this->stackPtr[i]=s.stackPtr[i];
    }
    return this;
}

// top

template<typename Type1>
void Stack<Type1>::stackTop (void)
{
    cout<<"Max Index is "<<this->tos<<endl;
}

// destructor

template<typename Type1>
Stack<Type1>::~Stack()
{
    if(this->stackPtr!=nullptr)
    {
        delete [] stackPtr;
        cout<<"I'm Dead"<<endl;
    }
}



#endif // STACKTEMPLETEHEADER_H_INCLUDED
