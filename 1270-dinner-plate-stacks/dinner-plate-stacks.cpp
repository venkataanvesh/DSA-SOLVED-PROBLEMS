class DinnerPlates {
    set<int> full,nf,empty;
    map<int,vector<int>> curr;
    int c;
public:
    DinnerPlates(int cap) {
        c=cap;
        nf.insert(0);
    }
    
    void push(int val) {
        int l=-2;
        if(nf.size())
            l=*nf.begin();
        if(empty.size()){
            auto it=empty.begin();
            if(l==-2)
                l=*it;
            else
                l=min(l,*it);
        }
        if(l==-2 && full.size()){
            auto it=full.begin();
            if(*it){
                l=*it-1;
                nf.insert(l);
            }
            else{
                auto it=full.end();
                --it;
                l=*it+1;
                nf.insert(l);
            }
        }
        
        curr[l].push_back(val);
        if(curr[l].size()==c){
            full.insert(l);
            if(empty.find(l)!=empty.end())
                empty.erase(l);
            if(nf.find(l)!=nf.end())
                nf.erase(l);
        }
        else{
            if(empty.find(l)!=empty.end()){
                nf.insert(l);
                empty.erase(l);
            }
        }
    }
    
    int pop() {
        int r=-10;
        if(full.size()){
            auto it1=full.end();
            --it1;
            r=*it1;
        }
        if(nf.size()){
            auto it1=nf.end();
            --it1;
            r=max(r,*it1);
        }
        
        if(r==-10 or curr.find(r)==curr.end() or curr[r].size()==0)
            return -1;
        
        int v=curr[r].back();
        curr[r].pop_back();
        
        if(full.find(r)!=full.end()){
            full.erase(r);
            if(curr[r].size())
                nf.insert(r);
            else
                empty.insert(r);
        }
        else{
            if(curr[r].size()==0){
                empty.insert(r);
                nf.erase(r);
            }
        }
        
        return v;
    }
    
    int popAtStack(int ind) {
        if(curr[ind].size()==0)
            return -1;
        
        int v=curr[ind].back();
        if(curr[ind].size()==c){
            full.erase(ind);
            if(curr[ind].size()<2)
                empty.insert(ind);
            else
                nf.insert(ind);
        }
        else{
            if(curr[ind].size()==1){
                nf.erase(ind);
                empty.insert(ind);
            }
        }
        curr[ind].pop_back();        
        return v;   
    }
};
  