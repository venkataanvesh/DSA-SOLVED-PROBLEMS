    #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
class Solution {
public:

  
    #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;
        ordered_set a1,b1;
        int n = nums.size();
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        a1.insert(nums[0]), b1.insert(nums[1]);
        
        for(int i=2;i<n;i++){
            int ind1=a1.order_of_key(nums[i]+1);
            int ind2=b1.order_of_key(nums[i]+1);
            int  x = a.size()-ind1;
            int y = b.size()-ind2;
            
            if(x>y){a1.insert(nums[i]),a.push_back(nums[i]);}
            else if(y>x){b1.insert(nums[i]), b.push_back(nums[i]);}
            else if(x==y && a.size()<b.size()){a1.insert(nums[i]),a.push_back(nums[i]);}
            else if(x==y && a.size()>b.size()){b1.insert(nums[i]),b.push_back(nums[i]);}
            else {a1.insert(nums[i]),a.push_back(nums[i]);}
        }
        vector<int> ans;
        for(auto x: a)ans.push_back(x);
        for(auto x: b)ans.push_back(x);
        
        return ans;
    }
};