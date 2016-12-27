/**
*题目：写一个程序求一棵二叉树中相距最远的两个节点的距离
**/
#include<iostream>
using namespace std;

struct Node{
	Node * pLeft;
	Node * pRight;
	int nMaxLeft;
	int nMaxRight;
	char value;
};
int maxLen = 0;

void reBuildTree2(char* pPreOrder, char* pInOrder, int nTreeLen, Node** pRoot){
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
        reBuildTree2(pPreOrder + 1, pInOrder, leftTreeLen, &((*pRoot) -> pLeft));
    }
    if(rightTreeLen > 0){
        reBuildTree2(pPreOrder + leftTreeLen +1, pInOrder + leftTreeLen +1, rightTreeLen, &((*pRoot) -> pRight));
    }
}


void FindMaxDistance(Node* root){
	//遍历到叶子节点返回
	if(root == NULL){
		return;
	}
	//如果左子树为空，那么该节点的左边最长距离为0
	if(root -> pLeft == NULL){
		root -> nMaxLeft = 0;
	}else{
		FindMaxDistance(root -> pLeft);
	}
	//如果右子树为空，那么该节点的右边最长距离为0
	if(root -> pRight == NULL){
		root -> nMaxRight = 0;
	}else{
		FindMaxDistance(root -> pRight);
	}

	if(root -> pLeft != NULL){
		int temp;
		if(root ->pLeft ->nMaxLeft > root ->pLeft ->nMaxRight){
			temp = root ->pLeft ->nMaxLeft;
		}else{
			temp = root ->pLeft ->nMaxRight;
		}
		root ->nMaxLeft = temp + 1;
	}
	if(root ->pRight != NULL){
		int temp;
		if(root->pRight ->nMaxLeft > root ->pRight ->nMaxRight){
			temp = root ->pRight ->nMaxLeft;
		}else{
			temp = root ->pRight ->nMaxRight;
		}
		root ->nMaxRight = temp +1;
	}

	if(root ->nMaxLeft + root ->nMaxRight > maxLen){
		maxLen = root ->nMaxLeft + root ->nMaxRight;
	}
	
}


int main(int argc, char* argv){
		char pre[6] = {'a','b','d','c','e','f'};
		char in[6] = {'d','b','a','e','c','f'};
		char pre2[7] ={'a','d','b','c','e','g','h'};
		char inOrder2[7] ={'b','d','c','a','g','e','h'};
		Node* root = NULL;
		reBuildTree2(pre2,inOrder2,7,&root); //构建树
		/*for(int i = 0; i < 3; i++){
			printNodeAtLevel(root, i);   //打印树
			std::cout << std::endl;
		}*/
		//printTreeByLevel(root);
		//printNodeByLevel(root);
		FindMaxDistance(root);
		cout<< maxLen<<endl;
	}