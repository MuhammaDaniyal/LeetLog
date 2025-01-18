class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (visited[i] == false)
            {
                dfs(visited, isConnected, i);
                provinces += 1;
            }
        }
        return provinces;
    }

    void dfs(vector<bool>& visited, vector<vector<int>>& isConnected, int ii)
    {
        visited[ii] = true;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (visited[i] == false && isConnected[ii][i] == true)
            {
                dfs(visited, isConnected, i);
            }
        }
    }
};