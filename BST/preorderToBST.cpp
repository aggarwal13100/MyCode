/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/


                                                  ************* TLE *************
                                                  
                                                    
int getMinIndex(vector<int>& preorder,int s,int e,int target){
    for(int i=s;s<=e;s++){
        if(preorder[s]>target){
            return s;
        }
    }
    return s;
}
BinaryTreeNode<int>* BST(vector<int>& preorder,int s,int e){
    if(s>e){
        return NULL;
    }
    if(s==e){
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[s]);
        return root;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[s]);
    int minIndex = getMinIndex(preorder,s+1,e,preorder[s]);
    root->left = BST(preorder,s+1,minIndex-1);
    root->right = BST(preorder,minIndex,e);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int e = preorder.size()-1;
    BinaryTreeNode<int>* ans = BST(preorder,0,e);
    return ans;
}






                                          ***************** O(N) *****************
                                          
                                            
                                            
                                            
                                            
                                            
                                            
                                            
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
// int getMinIndex(vector<int>& preorder,int s,int e,int target){
//     for(int i=s;s<=e;s++){
//         if(preorder[s]>target){
//             return s;
//         }
//     }
//     return s;
// }
// BinaryTreeNode<int>* BST(vector<int>& preorder,int s,int e){
//     if(s>e){
//         return NULL;
//     }
//     if(s==e){
//         BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[s]);
//         return root;
//     }
//     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[s]);
//     int minIndex = getMinIndex(preorder,s+1,e,preorder[s]);
//     root->left = BST(preorder,s+1,minIndex-1);
//     root->right = BST(preorder,minIndex,e);
//     return root;
// }
BinaryTreeNode<int>* ToBST(vector<int> &preorder,int& i,int min,int max){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]>max || preorder[i]<min){
        return NULL;
    }
    int node = preorder[i];
    i++;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(node);
    root->left = ToBST(preorder,i,min,node);
    root->right = ToBST(preorder,i,node,max);
    return root;
        
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
//     int e = preorder.size()-1;
//     BinaryTreeNode<int>* ans = BST(preorder,0,e);
//     return ans;
    int i= 0;
    BinaryTreeNode<int>* ans = ToBST(preorder,i,INT_MIN,INT_MAX);
    return ans;
}
