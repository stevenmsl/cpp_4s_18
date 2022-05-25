#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol18;
using namespace std;

/*takeaways
  - use hash table so we can improve the time compexity from
    O(n^4 + nlogn) to O(n^3 + nlogn)

*/

vector<vector<int>> Solution::fourSum(vector<int> &nums, int target)
{
  int n = nums.size();
  /* make sure the quadruplets are unique */
  auto result = set<vector<int>>();
  sort(nums.begin(), nums.end());

  auto valIndexs = unordered_map<int, int>();
  /* if there are duplicates for a number, only
     the index of the very last occurrence will
     be recorded
  */
  for (auto i = 0; i < n; i++)
    valIndexs[nums[i]] = i;

  /* We don't implement the logic here to eliminate
     duplicate quadruplets. We reply by using a set
     to do the work.
  */
  for (auto i = 0; i < n; i++)
    for (auto j = i + 1; j < n; j++)
      for (auto k = j + 1; k < n; k++)
      {
        auto val = target - nums[i] - nums[j] - nums[k];

        if (nums[k] > val)
          break;
        /* this is O(1) as we are accessing the map */
        auto it = valIndexs.find(val);
        /* don't forget for a number that has duplicates we
           only record the index of the very last occurrence
           - so this is sufficient
        */
        if (it == valIndexs.end() || it->second <= k)
          continue;

        result.insert({nums[i], nums[j], nums[k], val});
      }

  return vector<vector<int>>(begin(result), end(result));
}
