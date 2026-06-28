class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;
        for (string &w : words) {
            wordMap[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            unordered_map<string, int> currMap;
            int count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(word)) {
                    currMap[word]++;
                    count++;

                    while (currMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};