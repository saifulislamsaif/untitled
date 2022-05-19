#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current_cc;

bool dfs(int vertex, int par) {

    vis[vertex] = true;
    bool isLoopExitss = false;
    for (int child: g[vertex]) {
        if (vis[child] && child == par) continue;
        if(vis[child]) return true;
       isLoopExitss |= dfs(child,vertex);

    }
    return isLoopExitss;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isLoopExits = false;
    for (int i = 1; i <= n ; ++i) {
        if(vis[i]) continue;
      if(dfs(i,0)){
          isLoopExits = true;
          break;
      }
    }

    cout<<isLoopExits<<endl;
}

//8 6
//1 5
//2 3
//2 4
//3 5
//6 7
//1 5