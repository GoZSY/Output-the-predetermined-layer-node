/*********************************************************************
方法一、利用队列，记录每一层的结点，并记录层数，到达指定层后，顺序输出
该层的结点，然后创建链表。
**********************************************************************/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        ListNode* lis = NULL;
        if(dep == 0) return lis;
        int level = 1;
        queue<TreeNode*> curQueue;
        curQueue.push(root);
         
        while(level < dep){
            TreeNode* tempNode;
            queue<TreeNode*> nextQueue;
            while(!curQueue.empty()){
                tempNode = curQueue.front();
                curQueue.pop();
                if(tempNode->left != NULL) nextQueue.push(tempNode->left);
                if(tempNode->right != NULL) nextQueue.push(tempNode->right);
            }
            curQueue = nextQueue;
            level++;
        }
         
        lis = new ListNode(curQueue.front()->val);
        curQueue.pop();
        ListNode* curNode = lis;
        while(!curQueue.empty()){
            curNode->next = new ListNode(curQueue.front()->val);
            curQueue.pop();
            curNode = curNode->next;
        }
        return lis;
    }
};
/*********************************************************************
方法二、递归实现
**********************************************************************/
class TreeLevel {
public:
    ListNode* pHeadPre = new ListNode(-1);
    ListNode* pTraverse = pHeadPre;
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
    if (root == NULL || dep <= 0)
        return NULL;
     
    if (dep == 1)
    {
        ListNode* p = new ListNode(root->val);
        pTraverse->next = p;
        pTraverse = pTraverse->next;
    }
 
    getTreeLevel(root->left, dep - 1);
    getTreeLevel(root->right, dep - 1);
    return pHeadPre->next;
    }
};
