//
// Created by ctis-szx on 2016/12/25.
//
#include <iostream>
//#include <afxres.h>


struct Node {
    char value;
    Node* pLeft;
    Node* pRight;
};
/**
 * ��Ŀ1������ǰ���������������Ľ���������������
 * ���裺ÿ���ڵ���ַ�Ψһ
 */
void reBuildTree(char* pPreOrder, char* pInOrder, int nTreeLen, Node** pRoot){
    if(pPreOrder == NULL || pInOrder == NULL){
        return;
    }
    Node* temp = new Node;
    temp ->value = * pPreOrder;
    temp ->pLeft = NULL;
    temp -> pRight = NULL;
    if(*pRoot == NULL){
        *pRoot = temp;
    }
    if(nTreeLen == 1){
        return;
    }
    char * pInOrderTemp = pInOrder;
    char * pLeftEnd = pInOrder;
    int tmpLen = 0;
    while(* pPreOrder != *pLeftEnd){
        pLeftEnd ++;
        tmpLen++;
        if(tmpLen > nTreeLen){
            break;
        }
    }
    int leftTreeLen = (int)(pLeftEnd - pInOrderTemp);
    int rightTreeLen = nTreeLen - leftTreeLen -1;
    if(leftTreeLen > 0){
        reBuildTree(pPreOrder + 1, pInOrder, leftTreeLen, &((*pRoot) -> pLeft));
    }
    if(rightTreeLen > 0){
        reBuildTree(pPreOrder + leftTreeLen +1, pInOrder + leftTreeLen +1, rightTreeLen, &((*pRoot) -> pRight));
    }
}
/*
* ��Ŀ����ӡ��������ĳһ��Ľڵ�
*/
int printNodeAtLevel(Node * root, int level){
    if(!root || level < 0){
        return 0;
    }
    if(level == 0){
		std::cout << root -> value <<" ";
    }
    printNodeAtLevel(root -> pLeft, level - 1);
    printNodeAtLevel(root -> pRight, level - 1);
    return 1;
}

	int main(int argc, char* argv){
		char pre[6] = {'a','b','d','c','e','f'};
		char in[6] = {'d','b','a','e','c','f'};
		char pre2[7] ={'a','d','b','c','e','g','h'};
		char inOrder2[7] ={'b','d','c','a','g','e','h'};
		Node* root = NULL;
		reBuildTree(pre2,inOrder2,7,&root); //������
		for(int i = 0; i < 3; i++){
			printNodeAtLevel(root, i);   //��ӡ��
			std::cout << std::endl;
		}
		
	}

