#include <iostream>
#include <vector>
void knapsack(std::vector<int> price){
    int n = price.size();
    std::vector<int> cuts(n+1 , 0);
    int dp[101] = {0};
    for(int i = 1 ; i <= n ; i++){
        int max = INT16_MIN , cut = 0;
        for(int j = 0 ; j < i ; j++){
            if(dp[i - j - 1] + price[j] > max){
                max = dp[i - j - 1] + price[j];
                cut = j;
            }
        }
        dp[i] = max;
        cuts[i] = cut + 1; // Since j = 0 means not cutting
    }
    std::cout << dp[n] << '\n';
    std::vector<int> cut_seqence;
    int length = n;
    while(cuts[length] != 0){
        cut_seqence.push_back(cuts[length]);
        length -= cuts[length];
    }
    std::cout << cut_seqence.size() << '\n' << n << "=";
    for(int i = 0 ; i < cut_seqence.size() ; i++){
        std::cout << cut_seqence[i] << ((i == cut_seqence.size()-1) ?  "\n" : "+") ;
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> price(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> price[i];
    knapsack(price);
}