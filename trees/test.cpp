# include "trees.h"

using namespace std;

int main(){
    BST<int> b;
    int mango = 0;
    for(int i = 0; i < 30; i++){
        mango = i;
        b.insertNode(mango);
    }
    int bhadwa = 3;
    bool status = b.deleteNode(bhadwa);
    b.executeTreeWalk(INORDER_WALK);
    return 0;
}