class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& a) {
        int n=a.size();

        queue<int> q;
        q.push(1);
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vis[n-1][0]=1;

        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();q.pop();

                if(curr==n*n)return steps;

                for(int die=1; die<=6; die++){
                    int next=curr+die;
                    if(next>n*n)break;
                    int x=(n-1)-(next-1)/n;
                    int y=(next-1)%n;
                    if(x%2==n%2)y=n-1-y;
                    if(x>=0 && y>=0 & x<n && y<n && !vis[x][y]){
                        vis[x][y]=1;
                        if(a[x][y]!=-1)q.push(a[x][y]);
                        else q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};