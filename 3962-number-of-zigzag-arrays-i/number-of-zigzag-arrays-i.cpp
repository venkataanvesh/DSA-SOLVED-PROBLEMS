#define mod 1000000007
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r-l+1;
        /*vector<int> cd(k) ,ci(k) , pi(k) ,pd(k); // current increase and decrease, previous increase and decrease
        pi[0] = 0 , pd[0] = k-1;
        for(int i = 1 ; i < k ; i++) pi[i] = i + pi[i-1];
        for(int j = 1 ; j < k ; j++) pd[j] = k-1-j + pd[j-1];

        for(int asz = 2 ; asz < n ; asz++){
            int s = pi.back();
            ci[0] = 0 , cd[0] = (s-pi[0]+mod)%mod;
            for(int i = 1 ; i < k ; i++){
                ci[i] = (pd[i-1]+ci[i-1])%mod;
                cd[i] = ((s-pi[i]+mod)%mod+cd[i-1])%mod;
            }
            swap(ci,pi);
            swap(cd,pd);
        }
        return (pi.back()+pd.back())%mod;*/
        int cdd[k],cii[k],pii[k],pdd[k];
        int *cd=cdd,*ci=cii,*pi=pii,*pd=pdd;
        pi[0] = 0 , pd[0] = k-1; ci[0] = 0;
        for(int i = 1 ; i < k ; i++) pi[i] = i + pi[i-1];
        for(int j = 1 ; j < k ; j++) pd[j] = k-1-j + pd[j-1];

        for(int asz = 2 ; asz < n ; asz++){
            int s = pi[k-1];
            cd[0] = s;
            for(int i = 1 ; i < k ; i++){
                ci[i] = (pd[i-1]+ci[i-1])%mod;
                cd[i] = ((s-pi[i]+mod)%mod+cd[i-1])%mod;
            }
            swap(ci,pi);
            swap(cd,pd);
        }
        return (pi[k-1]+pd[k-1])%mod;
    }
};