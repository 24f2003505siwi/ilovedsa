class Solution {
private:
    int checkValid(int i, string s, vector<int>& leftmost, vector<int>& rightmost){
        int right = rightmost[s[i] - 'a'];
        for (int j = i; j <= right; j++){
            if (leftmost[s[j] - 'a'] < i) return -1;
            right = max(right, rightmost[s[j] - 'a']);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        for (int i = 0; i < n; i++){
            leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
            rightmost[s[i] - 'a'] = max(rightmost[s[i] - 'a'], i);
        }
        vector<string> ans;
        int lastright = -1;
        for (int i = 0; i < n; i++){
            if (leftmost[s[i] - 'a'] != i) continue;
            int newright = checkValid(i, s, leftmost, rightmost);
            if (newright == -1) continue;
            if (i > lastright){
                ans.push_back(s.substr(i, newright - i + 1));
                lastright = newright;
            } else {
                ans.back() = s.substr(i, newright - i + 1);
                lastright = newright;
            }
        }
        return ans;
    }
};