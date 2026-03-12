class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;// end the loop even (n-1)!
            numbers.push_back(i);
        }
        numbers.push_back(n);

        k--;

        string result = "";

        while (true) {

            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            if (numbers.empty())
                break;

            k = k % fact;
            fact /= numbers.size();
        }
        return result;
    }
};