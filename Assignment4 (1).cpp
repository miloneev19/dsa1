/*Construct an Expression Tree from postfix and prefix expression.
 Perform recursive and non-recursive In-order, pre-order and post-order traversals.*/

#include<iostream>
#include<cstring>
using namespace std;

struct node{
        char data;
        node*l;
        node*r;
    };

struct stacknode{
    node*val;
    stacknode*next;
};

    class stack{
        private:
        stacknode*top;

        public:
        stack(){
            top=NULL;
        }
        int isEmpty();
        void push(node*x);
        node* pop();
        node* topp();
    };

    int stack::isEmpty(){
        if(top==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }

    void stack::push(node*x){
        stacknode *p;
		p=new stacknode();
		p->val=x;
		p->next=top;
		top=p;
    }

    node* stack::pop(){
        stacknode *p;
		node* x;
		x=top->val;
		p=top;
		top=top->next;

		return x;
    }

    node* stack::topp()
	{
		return (top->val);
	}

node* createTree_postfix(char postfix[10]){
    node *p;
    stack s;
	for(int i=0;postfix[i]!='\0';i++)
	{
		char token=postfix[i];
		if(isalnum(token))
		{
			p=new node();
			p->data=token;
			p->l=NULL;
			p->r=NULL;
			s.push(p);		
		}	
		else
		{
			p=new node();
			p->data=token;
			p->r=s.pop();
			p->l=s.pop();
			s.push(p);		
		}
	}
    cout<<"\n"<<"Tree created successfully"<<"\n";

    return s.pop();
}

node*createTree_prefix(char prefix[10]){
    stack s;
    node*p;
    char token;
    for(int i=strlen(prefix)-1;i>=0;i--){
        token=prefix[i];
        if(isalnum(token)){
            p=new node;
            p->data=token;
            p->l=NULL;
            p->r=NULL;
            s.push(p);
        }
        else{
            p=new node;
            p->data=token;
            p->l=s.pop();
            p->r=s.pop();
            s.push(p);
        }
    }
    cout<<"\n"<<"Tree created successfully"<<"\n";
    return s.pop();
}

void inorder_rec(node*root){
    if(root==NULL){
        return;
    }
    inorder_rec(root->l);
    cout<<root->data<<"\t";
    inorder_rec(root->r);
}

void preorder_rec(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preorder_rec(root->l);
    preorder_rec(root->r);
}

void postorder_rec(node*root){
    if(root==NULL){
        return;
    }
    postorder_rec(root->l);
    postorder_rec(root->r);
    cout<<root->data<<"\t";
}

void inorder_nonrec(node*root){
    stack s;
    node*current=root;
    while(current!=NULL || !s.isEmpty()){
        while(current!=NULL){
            s.push(current);
            current=current->l;
        }
        current=s.topp();
        node*temp=s.pop();
        cout<<temp->data<<"\t";

        current=current->r;
    }
}

void preorder_nonrec(node*root){
    stack s;
    node*current=root;
    s.push(current);
    while(!s.isEmpty()){
        node*temp=s.pop();
        cout<<temp->data<<"\t";

        if(current->r!=NULL){
            s.push(current->r);
        }

        if(current->l!=NULL){
            s.push(current->l);
        }
    }
}

int main(){
    node*root=NULL;
    char postfix[10],prefix[10];
    int choice,op;
    do{
    cout<<"\n"<<"1.Create tree"<<"\n";
    cout<<"\n"<<"2.Inorder recursive traversal"<<"\n";
    cout<<"\n"<<"3.Preorder recursive traversal"<<"\n";
    cout<<"\n"<<"4.Postorder recursive traversal"<<"\n";
    cout<<"\n"<<"5.Inorder non-recursive traversal"<<"\n";
    cout<<"\n"<<"6.Preorder non-recursive traversal"<<"\n";
    cout<<"\n"<<"7.Postorder non-recursive traversal"<<"\n";
    cout<<"\n"<<"8.Exit"<<"\n";
    cin>>choice;

    switch(choice){
        case 1:{
            cout<<"\n"<<"1.Using postfix expression"<<"\n";
            cout<<"\n"<<"2.Using prefix expression"<<"\n";

            cin>>op;
            if(op==1){
                cout<<"\n"<<"Enter the postfix expression"<<"\n";
                cin>>postfix;
                root=createTree_postfix(postfix);
                cout<<root->data;
                cout<<root->l->data;
                cout<<root->r->data;
            }
            else{
                cout<<"\n"<<"Enter the prefix expression"<<"\n";
                cin>>prefix;
                root=createTree_prefix(prefix);
                cout<<root->data;
                cout<<root->l->data;
                cout<<root->r->data;
            }
            break;
        }

        case 2:{
            inorder_rec(root);
            break;
        }

        case 3:{
            preorder_rec(root);
            break;
        }

        case 4:{
            postorder_rec(root);
            break;
        }

        case 5:{
            inorder_nonrec(root);
            break;
        }

        case 6:{
            preorder_nonrec(root);
            break;
        }
    }
    }while(choice!=8);
    return 0;
}