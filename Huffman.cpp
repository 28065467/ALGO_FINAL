#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <map>
std::map<int,std::string> ans;
struct node
{
    int value;
    node* left;
    node* right;
    node() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    node(int v, struct node* l, struct node* r) {
        value = v;
        left = l;
        right = r;
    }
};
bool cmp(node* a, node* b) {
    return a->value < b->value;
}
void generatecode(node* curr , std::string toprint){
    if(curr->left == nullptr || curr->right == nullptr){
        ans[curr->value] = toprint;
        return;
    }
    if(curr->left != nullptr)
        generatecode(curr->left , toprint+"0");
    if(curr->right != nullptr)
        generatecode(curr->right , toprint+"1");
}
int main()
{
    int n;
    std::cin >> n;
    std::deque<node*> frqence;
    std::vector<int> order;
    for(int i = 0 ; i < n ; i++){
        int temp;
        std::cin >> temp;
        frqence.push_back(new node(temp));
        order.push_back(temp);
    }
    std::sort(frqence.begin(),frqence.end() , cmp);
    while(frqence.size() != 1){
        node* l = frqence.front();
        frqence.pop_front();
        node* r = frqence.front();
        frqence.pop_front();
        frqence.push_back(new node(l->value + r->value , l , r));
        std::sort(frqence.begin(),frqence.end() , cmp);
    }
    generatecode(frqence.front() , "");
    for(int i = 0 ; i < n ; i++){
        std::cout << ans[order[i]] << (i == n-1 ? "\n" : " ");
    }
}