class Solution {
    public:
        int tilingRectangle(int n, int m) {
            if (n == m) 
                return 1;
            int ans=INT_MAX;
            unordered_map<unsigned long long,int> Map;

            if (n > m) {
                int temp = n;
                n = m;
                m = temp;
            }
            vector<int> foo(n+1);
            dfs(n, m, foo, 0, ans, Map);
            return ans;
        }
    private:
        void dfs(int n, int m, vector<int> h, int cnt,int &ans, unordered_map<unsigned long long,int> &Map) {
            if (cnt >= ans) 
                return;
            bool isFull = true;
            int pos = -1, minH = INT_MAX;
            for (int i = 1; i <= n; i++) {
                if (h[i] < m) 
                    isFull = false;
                if (h[i] < minH) {
                    pos = i;
                    minH = h[i];
                }
            }
            if (isFull) {
                ans = min(cnt, ans);
                return;
            }
        
            unsigned long long key = 0, base = m + 1;
            for (int i = 1; i <= n; i++) {
                key += h[i] * base;
                base *= m + 1;
            }
            auto it=Map.find(key);
            if(it!=Map.end()&&Map[key]<=cnt)
                return;
            Map[key]=cnt;
            int end = pos;
            while (end + 1 <= n && h[end + 1] == h[pos] && (end + 1 - pos + 1 + minH) <= m) 
                end++;
            for (int j = end; j >= pos; j--) {
                int curH = j - pos + 1;
                vector<int> next=h;
            for (int k = pos; k <= j; k++) {
                next[k] += curH;
            }
            dfs(n, m, next, cnt + 1, ans, Map);
        }
    }
};
