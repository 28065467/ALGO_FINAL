#include <iostream>
#include <vector>
#include <algorithm>
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> start(n) , end(n), index;
    for(int i = 0 ; i < n  ; i++){
        std::cin >> start[i];
        index.push_back(i+1);
    }
    for(int i = 0 ; i < n  ; i++)
        std::cin >> end[i];
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(start[i] > start[j]){
                swap(end[i] , end[j]);
                swap(start[i] , start[j]);
                swap(index[i],index[j]);
            }
        }
    }
    std::vector<int> ans;
    ans.push_back(index[n-1]);
    int current_end = n - 1;
    for(int i = n - 2 ; i >= 0 ; i--){
        if(end[i] <= start[current_end]){
            ans.push_back(index[i]);
            current_end = i;
        }
    }
    std::cout << ans.size() << "\n(";
    for(int i = ans.size() - 1 ; i >= 0 ; i--)
        std::cout << ans[i] << (i == 0 ? ")\n" : ",");
}