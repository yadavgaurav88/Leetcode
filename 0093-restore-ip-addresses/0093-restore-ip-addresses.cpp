class Solution {
public:
    vector<string> ans;
    vector<string> path;

    bool valid(string part) {

        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void solve(int idx, string &s) {

        if (path.size() == 4) {
            if (idx == s.size()) {
                string ip = path[0];

                for (int i = 1; i < 4; i++)
                    ip += "." + path[i];

                ans.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {

            if (idx + len > s.size())
                break;

            string part = s.substr(idx, len);

            if (!valid(part))
                continue;

            path.push_back(part);

            solve(idx + len, s);

            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(0, s);

        return ans;
    }
};