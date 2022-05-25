#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol18;

/*
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

tuple<vector<int>, int, vector<vector<int>>>
testFixture1()
{
  auto nums = vector<int>{1, 0, -1, 0, -2, 2};
  auto output = vector<vector<int>>{
      {-1, 0, 0, 1},
      {-2, -1, 1, 2},
      {-2, 0, 0, 2}};

  return make_tuple(nums, 0, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.fourSum(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}