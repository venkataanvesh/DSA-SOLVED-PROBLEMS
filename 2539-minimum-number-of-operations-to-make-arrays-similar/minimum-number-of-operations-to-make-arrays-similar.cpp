class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans=0;
        vector<int> oddn;
        vector<int> evenn;
        vector<int> oddt;
        vector<int> event;
        for(auto i:nums){
            if(i%2==1)
                oddn.push_back(i);
            else
                evenn.push_back(i);
        }
        for(auto i:target){
            if(i%2==1)
                oddt.push_back(i);
            else
                event.push_back(i);
        }
        
        sort(oddn.begin(),oddn.end());
        sort(evenn.begin(),evenn.end());
        sort(oddt.begin(),oddt.end());
        sort(event.begin(),event.end());
        
        for(int i=0;i<oddn.size();i++){
            if(oddt[i] >oddn[i] )
                ans+=(oddt[i]-oddn[i]);
        }
        for(int i=0;i<evenn.size();i++){
            if(event[i]>evenn[i])
                ans+=(event[i]-evenn[i]);
        }
        return ans/2;
    }
};