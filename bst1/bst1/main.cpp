//
//  main.cpp
//  bst1
//
//  Created by Аружан Туткенова on 3/5/20.
//  Copyright © 2020 Аружан Туткенова. All rights reserved.
//

#include <iostream>
using namespace std;
int root = 0;
struct Node{
public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        left=right=NULL;
        val = data;
    }
    };
Node *data;
Node *insert(Node *v, int data,int roots)
{
    root = max(root, roots);
    if (!v)
    {
        return new Node(data);
    }
    
    if(v->val == data)
        return v;
    if(v -> val < data)
        v -> right = insert (v -> right, data, roots + 1);
    else
        v -> left = insert (v -> left, data, roots + 1);
    return v;
}


int main()
{

    int a;
    cin >> a;
    data = new Node (a);
    while (a) {
        cin >> a;
        if (a)
            data = insert(data, a, 1);
    }
    cout << root;
    return 0;
}
