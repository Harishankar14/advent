#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    long long total_sum = 0;
    while (cin >> s) {
        int n = s.length();
        int current_line_max = -1;

        // Try every digit as the "tens" place
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                
                int tens = s[i] - '0';
                int ones = s[j] - '0';
                int value = (tens * 10) + ones;

                if (value > current_line_max) {
                    current_line_max = value;
                }
            }
        }
        total_sum += current_line_max;
    }

    cout << "Total Sum: " << total_sum << endl;

    return 0;
}

// part 2 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    long long total_sum = 0;
    const int target = 12;

    while (cin >> s) {
        // Calculate how many characters we are allowed to delete
        int to_remove = s.length() - target;
        
        // If string is too short, skip or handle error (assuming valid input per problem)
        if (to_remove < 0) continue; 

        string result = "";

        for (char c : s) {
            while (!result.empty() && result.back() < c && to_remove > 0) {
                result.pop_back(); // Remove the smaller character
                to_remove--;    
            }
            result.push_back(c);
        }
        while (to_remove > 0) {
            result.pop_back();
            to_remove--;
        }
        total_sum += stoll(result);
    }

    cout << "Total Sum: " << total_sum << endl;

    return 0;
}
