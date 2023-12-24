#include <iostream>
#include <vector>
#include <algorithm>
struct edge{
    int start,end,weight;
    edge(int a , int b , int c){
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
    std::vector<std::vector<edge>> edges(n+1);
    for(int i = 0 ; i < m ; i++){
        int s , e, w;
        std::cin >> s >> e >> w;
        edges[s].push_back(edge(s , e ,w));
        std::sort(edges[s].begin() , edges[s].end() , cmp);
    }
    std::cin >> start;
    std::vector<int> ans_weight(n+1 , INT16_MAX);
    std::vector<int> ans_parent(n+1 , 0);
    std::vector<int> selected_node;
    std::vector<bool> selected(n+1 , false);
    ans_weight[start] = 0;
    selected[start] = true;
    selected_node.push_back(start);
    int count = 0;
    while(count != n-1){
        std::vector<edge> curr_edges = edges[selected_node[selected_node.size()-1]];
        if(curr_edges.size() != 0){
            for(int i = 0 ; i < curr_edges.size() ; i++){
                int start_node = curr_edges[i].start , end_node = curr_edges[i].end;
                if(ans_weight[start_node] + curr_edges[i].weight < ans_weight[end_node]){
                    ans_weight[end_node] = ans_weight[start_node] + curr_edges[i].weight;
                    ans_parent[end_node] = start_node;
                }
            }
        }
        int min = INT16_MAX, min_node;
        for(int i = 1 ; i <= n ; i++){
            if(ans_weight[i] <= min && !selected[i]){
                min = ans_weight[i];
                min_node = i;
            }
        }
        selected[min_node] = true;
        selected_node.push_back(min_node);
        count++;
    }
    for(int i = 1 ; i <= n ; i++)
        std::cout << ans_weight[i] << (i == n ? "\n" : " ");
    for(int i = 1 ; i <= n ; i++)
        std::cout << ans_parent[i] << (i == n ? "\n" : " ");
}