#include <string>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {} 
};



class Codec {
public:
    public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (root == NULL){
            return ans;
        }
        vector<TreeNode*> layer;
        layer.push_back(root);
        int num = 1;
        TreeNode* node;
        while (!layer.empty()){
            num = layer.size();
            for (int i = 0; i < num; i++){
                node = layer[i];
                if (node == NULL){
                    ans += "(n)";
                }
                else{
                    ans += "(" + to_string(node->val) + ")";
                    layer.push_back(node->left);
                    layer.push_back(node->right);
                }
            }
            layer.erase(layer.begin(), layer.begin()+num);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length(), num, i;
        if (len == 0)
            return NULL;
        vector<TreeNode*> last, cur;
        int iter = 0, val = 0;
        while (data[iter] != ')'){
            if (data[iter] == '('){
                iter++;
                continue;   
            }
            val = val * 10 + data[iter] - '0';
            iter++;
        }
        TreeNode* root = new TreeNode(val);
        last.push_back(root);
        data.erase(data.begin(), data.begin() + iter + 1);
        while (!last.empty()){
            i = iter = 0;
            num = last.size();
            while (iter < num * 2){
                if (data[i] == 'n'){
                    i += 2;
                    iter++;
                    continue;
                }
                else if (data[i] == '('){
                    i++;
                    val = 0;
                    continue;
                }
                else if (data[i] == ')'){
                    TreeNode* node;
                    if (iter % 2)
                        last[iter/2]->right = node = new TreeNode(val);
                    else
                        last[iter/2]->left = node = new TreeNode(val);
                    last.push_back(node);
                    i++;
                    iter++;
                    continue;
                }     
                else {
                    val = val * 10 + data[i] - '0';
                }
                i++;
            }
            last.erase(last.begin(), last.begin()+num);
            data.erase(data.begin(), data.begin()+i+1);
        }
        return root;
    }

};

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    TreeNode* left1 = new TreeNode(4);
    TreeNode* right1 = new TreeNode(5);
    root->left = left;
    root->right = right;
    right->left = left1;
    right->right = right1;
    string a = Codec().serialize(root);
    TreeNode* newroot = Codec().deserialize(a);
    printf("%d\n", newroot->val);
}