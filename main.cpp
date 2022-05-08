#include "./utils/utils.h"
#include "./problem/442.cpp"
#include <algorithm>
using namespace std;

int main(){
    Solution s1;
    vector<int> nums1 = {1};
    vector<int> ans1 = s.findDuplicates(nums1);
    sort(ans1.begin(), ans1.end());
    cout << ans1 << endl;
    return 0;
}
