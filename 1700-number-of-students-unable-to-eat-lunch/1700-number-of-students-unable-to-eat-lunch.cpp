class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        for (int x : students)
            q.push(x);

        int i = 0;
        int cnt = 0;

        while (!q.empty() && cnt < q.size()) {

            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                cnt = 0;
            } else {
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }

        return q.size();
    }
};