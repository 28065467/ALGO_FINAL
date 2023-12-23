#include <iostream>
#include <vector>
int main()
{
    int n , w ,v;
    std::cin >> n >> w >> v;
    std::vector<int> price(n) , weight(n) , volume(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> price[i];
    for(int i = 0 ; i < n ; i++)
        std::cin >> weight[i];
    for(int i = 0 ; i < n ; i++)
        std::cin >> volume[i];
    std::vector<std::vector<std::vector<int>>> dp(n+1,std::vector<std::vector<int>> (w+1,std::vector<int> (v+1,0)));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= w ; j++){
            for(int k = 1 ; k <= v ; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                if(j >= weight[i-1] && k >= volume[i-1]){
                    dp[i][j][k] = std::max(dp[i][j][k] , dp[i-1][j-weight[i-1]][k-volume[i-1]] + price[i-1]);
                }
            }
        }
    }
    int result = dp[n][w][v];
    std::cout << result << "\n";
    std::vector<int> selected;
    for(int i = n ; i > 0 && result > 0 ; i--){
        if(result == dp[i-1][w][v])
            continue;
        selected.push_back(i);
        result -= price[i-1];
        w -= weight[i-1];
        v -= volume[i-1];
    }
    std::cout << selected.size() << "\n" << "(";
    for(int i = selected.size()-1 ; i >= 0 ; i--){
        std::cout << selected[i] << (i == 0 ? ")\n" : ",");
    }
}