class Solution {

    int minXOR( int idx) {
// if idx == m_nums2.size() - 1, then it is the 
// last not used element in nums2 left
        if (idx + 1 == m_nums2.size()) {
            for (int i = 0; i < m_nums2.size(); i++) {
                if (!m_bs[i]) {
                    return (m_nums.back() ^ m_nums2[i]);
                }
            }
            return 0;
        }
        auto f = m_dp.find(m_bs.to_ulong());
        if (f != m_dp.end()) {
            return f->second;
        }
        int res = INT_MAX;
        for (int i = 0; i < m_nums2.size(); i++) {
            if (!m_bs[i]) {
                m_bs[i] = 1;
                // add xor of m_nums[idx] and  m_nums2[i] and continue
                int r = (m_nums[idx] ^ m_nums2[i]) + minXOR(idx + 1);
                m_bs[i] = 0;
                if (r < res) {
                    res = r;
                }
            }
        }
// store intermediate result in the map
        m_dp[m_bs.to_ulong()] = res;
        return res;
    }
    vector<int> m_nums;
    vector<int> m_nums2;
// use bitset to store the actual mapping of nums from nums2
    bitset<14> m_bs;
    unordered_map<unsigned long, int> m_dp;
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
     // store arrays into local members to make signature of minXOR shorter
        m_nums = nums1;
        m_nums2 = nums2;
        m_bs.reset();
        m_dp.clear();
        int msum = minXOR(0);
        return msum;
    }
};