class Solution {
public:
    using int2=pair<char, char>;
    int n;
    vector<vector<int>> result;
    void backtrack(int i, vector<int>& subset, vector<int2>& nWm, int target) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }

        if (i == n || target < 0) 
            return;

        auto [x, m] = nWm[i];
        int j0=min((int)m, target/x);// this can save computations
        for (int j = 0; j <= j0; j++) {
            // Add j x's to 
            int sz=subset.size();
            subset.resize(sz+j);
            fill(subset.begin()+sz, subset.end(), x);

            backtrack(i+1, subset, nWm, target-j*x);

            //backtracking
            subset.resize(sz);    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        char freq[51]={0}, xMax=0;
        for(char x: candidates){
            freq[x]++;
            xMax=max(xMax, x);
        }
    
        vector<int2> nWm;
        for (char x=1; x<=xMax; x++) {
           char f=freq[x];
           if (f>0) nWm.push_back({x, f});
        }

        n=nWm.size();
        vector<int> subset;
        backtrack(0, subset, nWm, target);
        return result;
    }
};
