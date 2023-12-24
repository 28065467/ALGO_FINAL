#include <iostream>
#include <vector>
#include <algorithm>
struct edge{
    int start,end;
    float weight;
    edge(int a , int b , float c){
        start = a;
        end = b;
        weight = c;
    }
};
bool cmp(edge a , edge b){
    return a.weight < b.weight;
};
int main()
{
    int n , m , start;
    std::cin >> n >> m;
    std::vector<edge> edges;
    for(int i = 0 ; i < m ;  i++){
        int s , e;
        float w;
        std::cin >> s >> e >> w;
        edges.push_back(edge(s,e,w));
    }
    std::vector<float> ans_weight(n+1 , INT16_MAX);
    std::vector<int> ans_parent(n+1, 0);
    std::cin >> start;
    ans_weight[start] = 0;
    for(int i = 0 ; i < n ; i++){
        for(auto e : edges){
            if(ans_weight[e.start] != INT16_MAX && ans_weight[e.start] + e.weight < ans_weight[e.end]){
                ans_weight[e.end] = ans_weight[e.start] + e.weight;
                ans_parent[e.end] = e.start;
            }
        }
    }
    for(auto e : edges){
        if(ans_weight[e.start] != INT16_MAX && ans_weight[e.start] + e.weight < ans_weight[e.end]){
            std::cout << "There is a negative weight cycle in the graph\n";
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; i++)
        std::cout << ans_weight[i] << (i == n ? "\n" : " ");
    for(int i = 1 ; i <= n ; i++)
        std::cout << ans_parent[i] << (i == n ? "\n" : " ");
}