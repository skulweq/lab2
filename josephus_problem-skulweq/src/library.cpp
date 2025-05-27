#include "library.hpp"

namespace josephus_library {
    int josephus_problem(const std::vector <int>& nums, int k) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        std::deque <int> circle(nums.begin(), nums.end());
        while (circle.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                circle.push_back(circle.front());
                circle.pop_front();
            }
            circle.pop_front();
        }

        return circle.front();
    };
}