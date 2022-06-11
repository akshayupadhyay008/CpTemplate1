#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    new_data_set;
int main()
{
    new_data_set data;
    data.insert(34);
    data.insert(785);
    data.insert(12);
    data.insert(87);
    cout << "The value at index 2 is " << *data.find_by_order(2) << endl;
    cout << "The index of number 87 is " << data.order_of_key(87) << endl;
    return 0;
}
// Output
//     The value at index 2 is 785 The index of number 87 is 4

// https://codeforces.com/blog/entry/11080
// https://codeforces.com/blog/entry/13279

// https://www.geeksforgeeks.org/policy-based-data-structures-g/ 