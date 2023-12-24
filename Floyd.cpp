#include <iostream>
#include <vector>
int main()
{
    int n , m;
    std::cin >> n >> m;
    std::vector<std::vector<float>> dist(n+1, std::vector<float> (n+1,INT16_MAX));
    for(int i = 1 ; i <= n ; i++)
        dist[i][i] = 0;
    for(int i = 0 ; i < m ; i++){
        int s, e;
        std::cin >> s >> e;
        std::cin >> dist[s][e];
    }
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(dist[i][k] != INT16_MAX && dist[k][j] != INT16_MAX && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(dist[i][j] == INT16_MAX)
                std::cout << "N" << (j == n ? "\n" : " ");
            else
                std::cout << dist[i][j] << (j == n ? "\n" : " ");
        }
    }
}