#ifndef _YK_HUFFMANTREE_H__
#define _YK_HUFFMANTREE_H__
#include <malloc.h>
#include <cstring>
#include <climits>
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

struct huffmantrees_node 
{
	huffmantrees_node* right;
	huffmantrees_node* left;
	unsigned int weight;
	char* value;
	bool is_used;
};

class huffmantrees {
public:
	void show();
	huffmantrees();
    void creat(int n, int* weight_list, char** value_list);
    void find(huffmantrees_node&, int);
    void show();
private:
	huffmantrees_node* all_leave;
	huffmantrees_node* all_node;
	
	int sum_node;  // sum of node.
	int n;         // sum of leaf.
	int* weight_list;
	
	int* select_2min(huffmantrees_node*);
	//void sort_all_leave();
};

huffmantrees::huffmantrees() {}

void huffmantrees::creat(int n, int* weight_list, char** value_list) 
{
    this->all_leave = (huffmantrees_node*)malloc(n * sizeof(huffmantrees_node));
	this->all_node = (huffmantrees_node*)malloc((n-1) * sizeof(huffmantrees_node));
	
	// 创建所有叶子
	for (int i = 0; i < n; i++)
	{
		*(this->all_leave + n) = huffmantrees_node( { 0, 0, * (weight_list + n), * (value_list + n), true });
	}
	
	// huffmantrees* all_leaves = ...
	this->sum_node = 0;
	this->n = n;
	this->weight_list = weight_list;
	for (int i = 0; i < n-1; i++, this->sum_leave_node++)
	{
		huffmantrees_node* min = select_2min();
	 	huffmantrees_node min1,min2 = min[0], min[1];
	 	
	 	huffmantrees_node c = { min1,min2,min1.weight + min2.weight, false};
		//*(this->all_leave_backup + min1_index) = huffmantrees_node({0,0,0,0,false});
		//*(this->all_leave_backup + min2_index) = c;
        *(this->all_node+n) = c;
        this->sum_node++;
	}
}

huffmantrees_node* huffmantrees::select_2min()
{
    min = (huffmantrees_node*)malloc(2*sizeof(huffmantrees_node));
    huffmantrees_node* min1,min2;
    min1->weight = UINT_MAX;
    min2->weight = UINT_MAX;
    
    for (int i = 0; i < this->n; i++)
    {
        if ((this->all_leave+i)->weight < min1->weight &&
            (this->all_leave+i)->is_used == false)
           )
        {
            min1 = this->all_leave + i;
        }
        else if ((this->all_leave+i)->weight < min2->weight &&
            ((this->all_leave+i)->is_used == false)
            )
        {
            min2 = this->all_leave + i;
        }
    }
    for (int i = 0; i < this->sum_node; i++)
    {
        if ((this->all_node+i)->weight < min1->weight &&
            (this->all_node+i)->is_used == false)
           )
        {
            min1 = this->all_node + i;
        }
        else if ((this->all_node+i)->weight < min2->weight &&
            ((this->all_node+i)->is_used == false)
            )
        {
            min2 = this->all_node + i;
        }
    }
    min[0] = min1;
    min[1] = min2;
    return min;
}

void huffmantrees::find(huffmantrees_node& node,int weight)
{
    if (node.left == 0 && node.right == 0)
    {
        cout << "Node Weight: " << node.weight << " Node Value: " << node.value << endl;
        return;
    }
    if (weight < node.left->weight)
    {
        putchar('0');
        find(node.left, weight);
    }
    else
    {
        putchar('1');
        find(node.right, weight);
    }
}

void huffmantrees::show()
{
    for(int i = 0; i < n; i++)
    {
        find(this->all_node[this->sum_node-1],this->weight_list[i]);
    }
}
#endif
