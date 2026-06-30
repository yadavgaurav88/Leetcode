class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int,int>> q;

        for (int i = 0; i < tickets.size(); i++)
            q.push({i, tickets[i]});

        int time = 0;

        while (!q.empty()) {

            auto [idx, t] = q.front();
            q.pop();

            t--;
            time++;

            if (t == 0) {
                if (idx == k)
                    return time;
            } else {
                q.push({idx, t});
            }
        }

        return time;
    }
};