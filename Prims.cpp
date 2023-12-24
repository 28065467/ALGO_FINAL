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
    int n,e,start;
    std::cin >> n >> e;
    std::vector<std::vector<edge>> edges(n+1);

    for(int i = 0 ; i < e ; i++){
        int s , e, w;
        std::cin >> s >> e >> w;
        edges[s].push_back(edge(s , e , w));
        edges[e].push_back(edge(e , s ,w));
        sort(edges[s].begin(),edges[s].end(),cmp);
        sort(edges[e].begin(),edges[e].end(),cmp);
    }
    std::vector<int> parents(n+1 , 0);
    std::vector<int> selected_node;
    std::vector<bool> selected(n+1 , false);
    std::cin >> start;
    selected_node.push_back(start);
    selected[start] = true;
    int count = 0 , total_weight = 0;
    while(count != n - 1){
        int min = INT16_MAX, parent , min_node;
        for(int i = 0 ; i < selected_node.size() ; i++){
            std::vector<edge> curr_edge = edges[selected_node[i]];
            for(int j = 0 ; j < curr_edge.size() ; j++){
                if(curr_edge[j].weight < min && !selected[curr_edge[j].end]){
                    parent = curr_edge[j].start;
                    min = curr_edge[j].weight;
                    min_node = curr_edge[j].end;
                }
            }
        }
        parents[min_node] = parent;
        selected[min_node] = true;
        selected_node.push_back(min_node);
        total_weight += min;
        count++;
    }
    for(int i = 1 ; i <= n ;i++)
        std::cout << parents[i] << (i == n ? "\n" : " ");
    std::cout << total_weight << "\n";
}