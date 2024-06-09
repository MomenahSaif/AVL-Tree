#include<iostream>
#include<fstream>
using namespace std;

class Node {
public:
    Node* right, * left;
    int data, bal_factor;

    Node()
    { 
        right = NULL;
        left = NULL;
        data = 0;
       bal_factor=0;

    }

};
class Tree
{
public:
    Node* root;

    Tree()
    {
        root = NULL;
    }


    Node* insert(int x, Node* t)
    {
        if (t == NULL)       //Make a new node
        {
            t = new Node;
            t->data = x;
            t->bal_factor = 0;
            t->left = t->right = NULL;
        }
        else if (x < t->data)       // the node will be placed as a left leaf
        {
            t->left = insert(x, t->left);
            if (balance_factor(t->left) - balance_factor(t->right) > 1)   // check balance
            {
                if (x < t->left->data)
                    t = RR(t);
                else
                    t =LR(t);
            }
        }
        else if (x > t->data)         // the node will be placed as a right leaf
        {
            t->right = insert(x, t->right);
            if (balance_factor(t->right) - balance_factor(t->left) > 1)     // check balance
            {
                
                if (x > t->right->data)
                    t = LL(t);
                else
                    t =RL(t);
            }
        }

        t->bal_factor = max(balance_factor(t->left), balance_factor(t->right)) + 1;
        return t;
    }

    Node* RR(Node*& q)          //right right rotation
    {
        cout << endl << "The tree is unbalanced"<<endl;
        cout << " Z= " << q->data << endl;
        cout << " Y = " << q->right->data << endl;
        cout << " X = " << q->right->right->data << endl;
        cout<< endl << " After Rotation" << endl;
        Node* u = q->left;
        q->left = u->right;
        u->right = q;
        q->bal_factor = max(balance_factor(q->left), balance_factor(q->right)) + 1;
        u->bal_factor = max(balance_factor(u->left), q->bal_factor) + 1;
        return u;
    }

    Node* LL(Node*& m)            //left left rotation
    {
        cout << endl << "The tree is unbalanced"<<endl;
        cout << " Z= " << m->data << endl;
        cout << " Y = " << m->left->data << endl;
        cout << " X = " << m->left->left->data << endl;
        cout << endl << " After Rotation" << endl;

        Node* l = m->right;
        m->right = l->left;
        l->left = m;
        m->bal_factor = max(balance_factor(m->left), balance_factor(m->right)) + 1;
        l->bal_factor = max(balance_factor(m->right), m->bal_factor) + 1;

        return l;
    }

    Node* RL(Node*& n)    
    {
        n->right = RR(n->right);
        return LL(n);
    }

    Node* LR(Node*& n1)          
    {
        n1->left = LL(n1->left);
        return RR(n1);
    }

    Node* find_Min(Node* n)
    {
        if (n == NULL)
            return NULL;
       else if (n->left == NULL)
          return n;
        else
            return find_Min(n->left);
    }

    Node* deleteNode(Node* t,int num)
    {
        Node* temp;

        if (t == NULL)       // Node not found
            return NULL;
        else if (num < t->data)               // Searching for Node
            t->left = deleteNode(t->left, num);
        else if (num > t->data)
            t->right = deleteNode(t->right, num);
            // Node found
        else if (t->left && t->right)          // Node with 2 children
        {
            temp = find_Min(t->right);
            t->data = temp->data;
            t->right = deleteNode( t->right,t->data);
        }
        
        else            // Node with one or zero child
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }
        if (t == NULL)
            return t;

        t->bal_factor = max(balance_factor(t->left), balance_factor(t->right)) + 1;

        // If node is unbalanced
       
        if (balance_factor(t->left) - balance_factor(t->right) == 2)          // If left node is deleted, right case
        {
            // rr case
            if ((balance_factor(t->left->left) - balance_factor(t->left->right)) > 1)
                return LL(t);
            // rl case
            else
                return RL(t);
        }
        // If right node is deleted, left case
        else if (balance_factor(t->right) - balance_factor(t->left) == 2)
        {
            // ll case
            if ((balance_factor(t->right->right) - balance_factor(t->right->left)) > 1)
                return RR(t);
            // lr case
            else
                return LR(t);
        }
        return t;
    }

    int balance_factor(Node* n)
    {
        if (n == NULL)
            return NULL;

        if ((n->left == NULL) && (n->right == NULL))  // Leaf Node
        {
            n->bal_factor = 0;
            
            
        }
        else if ((n->left) && (n->right == NULL))  // has only left child
        {
            balance_factor(n->left);
            n->bal_factor = n->left->bal_factor + 1;
            
        }

        else if ((n->left == NULL) && (n->right))   // only right child present
        {
            balance_factor(n->right);
            n->bal_factor = -1 - n->right->bal_factor;
            
        }
        else    // has two child
        {
            balance_factor(n->right) && balance_factor(n->left);    
            n->bal_factor = n->left->bal_factor - n->right->bal_factor;
           

        }
       
        return n->bal_factor;
    }

    bool display_balanceFactor(Node* n)
    {
        if (n == NULL)  // The tree has ended
            return true;

        else       // displayes the nodes balance factor and the goes to next nodes
        {
            cout << n->data << ":  balance_factor=" << n->bal_factor << endl;
            return (display_balanceFactor(n->left) && display_balanceFactor(n->right));
        }

    }

    int max(int val1, int val2)
    {
        if (val1 > val2)
            return val1;
        else
            return val2;
      
    }

    bool display_tree(Node* n,int num)
    {
        if (num == 4)  // The given tree has 3 height
            return true;


        if (n == NULL)   // The node is not present
        {
            for (int i = 0; i < num; i++)
                cout << "_ " ;
            cout << endl;

        }
        else              // Node is present
        {
            for (int i = 0; i < num; i++)
                cout << "_ ";
            cout << n->data << endl;
            num++;

            display_tree(n->left, num) && display_tree(n->right, num);   // next nodes
            
        }
        
        
    }
    void Insert_Node(int x)
    {
        root = insert(x, root);
    }

    void Delete(int x)
    {
        root = deleteNode(root,x);
    }
};

int main()
{
   int data[7] = { 0,0,0,0,0,0,0 };
    ifstream myfile;
    myfile.open("File.txt");
    Tree t;

    cout << "\tInsert" << endl;
    for (int i = 0; i < 7; i++)
    {

        myfile >> data[i];
        cout << endl << "Inserting: "<<data[i] << endl;
        t.Insert_Node(data[i]);
        t.display_tree(t.root,0);
        cout << "Balance Factors of tree:" << endl;
        t.display_balanceFactor(t.root);
       

    }
    cout<<endl<<endl << "\tDelete:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << endl << "Deleting: " << data[i] << endl;
        t.Delete(data[i]);
        t.display_tree(t.root, 0);
        cout << "Balance Factors of tree:" << endl;
        t.display_balanceFactor(t.root);


    }
    
    
}