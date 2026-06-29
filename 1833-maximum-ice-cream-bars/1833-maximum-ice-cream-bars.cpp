class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> count(maxCost + 1, 0);

        // Count frequency of each cost
        for (int cost : costs)
            count[cost]++;

        int ans = 0;

        // Buy from cheapest to most expensive
        for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
            if (count[cost] == 0)
                continue;

            int canBuy = min(count[cost], coins / cost);
            ans += canBuy;
            coins -= canBuy * cost;
        }

        return ans;
    }
};