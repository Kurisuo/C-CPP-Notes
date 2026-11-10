#include <queue>
#include <stdio>
#include <vector>


void bfs(int startNode, std::vector<std::vector<int>> adjList){ 
    int len_n = adjList.size();
    std::queue<int> q;
    std::vector<bool> explored(len_n, false);

    q.push(startNode);
    explored[startNode] = true;

    while(!q.empty()){

        int front_node = q.front();
        q.pop();

            for(int curr : adjList[front_node]){ 
                if(!explored[curr]){ 
                    explored[curr] = true;
                    q.push(curr);
                }
            }

    }




}