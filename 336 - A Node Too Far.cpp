// Problem ID: 336 - A Node Too Far
// sol by bfs
#include <iostream>
#include <cstring>//memset
#include <utility>//pair
#include <queue>

using namespace std;

int graph[31][31] = {0};
int node_name[31] = {-1}; //노드의 이름.(양수)
int ttl[31] = {999};
int case_num = 1;
int nodes;
queue<pair<int,int>> bfs_queue;

int node_addr(int node){
    int k=0;
    for(;k<=30;k++){
        if(node == node_name[k]){//이미 있는 노드일때
            return k;
        }
        else if(node_name[k] == -1){//새로운 노드일때
            node_name[k] = node;
            nodes++;
            return k;
        }
    }
    return k;
}

int bfs(int node){
    for(int k=0;k<nodes;k++){
        //cout << node_name[k] << ' ';
        ttl[k] = 999;
    }
    //cout << endl;
    int dep = 0;
    bfs_queue.push({node_addr(node),dep});
    while(!bfs_queue.empty()){
    //for(int k=0;k<=30;k++){
    //    cout << ttl[k] << ' ';
    //}
    //cout << endl;
        pair<int,int> n;
        n = bfs_queue.front();
        //n = node_addr(n);
        dep = n.second;
        //cout << n.first << ' ' << n.second << endl;
        bfs_queue.pop();
        if(ttl[n.first] < dep)continue;
        ttl[n.first] = dep;
        for(int k=0;k<nodes;k++){
            if(graph[n.first][k] == 1 && n.first != k){
                bfs_queue.push({k,dep+1}); //next node
            }
        }
    }
    return dep;
}

int init_vals(){
    memset(graph,0,sizeof(graph));
    for(int k=0;k<=30;k++){
        node_name[k] = -1;
    }
    nodes=0;
    return 0;
}

int main(void){
    while(1){
        init_vals();
        int nc;
        cin >> nc;
        if(nc == 0)break;
        for(int i=0;i<nc;i++){
            int p1,p2;
            cin >> p1 >> p2;
            //cout << p1 << p2 << endl;
            p1 = node_addr(p1);
            p2 = node_addr(p2);
            //cout << p1 << p2 << endl;
            graph[p1][p2] = 1;
            graph[p2][p1] = 1;
        }
        while(1){
            int p1,p2;
            cin >> p1 >> p2;
            if(p1 == 0)break;
            bfs(p1);
            int not_reachable = 0;
            for(int k=0;k<nodes;k++){
                if(ttl[k] > p2){
                    not_reachable++;
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",case_num,not_reachable,p1,p2);
            case_num++;
        }

    }
}
