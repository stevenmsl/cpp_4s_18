
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol18
{

  class Solution
  {
  private:
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target);
  };
}
#endif