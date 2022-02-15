class Solution {
public:
    //07:58
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        
        unordered_map<string, int> um;
        vector<string> result;
        
        for(int i=0; i<cpdomains.size(); i++){
            int ri=cpdomains[i].size()-1;
            int le=0;
            int count;
            //find count;
            while(le<=ri){
                if(cpdomains[i][le]==' ') break;
                le++;
            }
            
            count = stoi(cpdomains[i].substr(0,le));
            
            while(ri>=le){
                if(ri==le || cpdomains[i][ri]=='.'){
                    //make sub string
                    string sub = cpdomains[i].substr(ri+1, cpdomains[i].size()-1-ri);
        
                    unordered_map<string, int>::iterator it = um.find(sub);
                    if(it != um.end()){
                        it->second += count;
                    }
                    else{
                        um.insert(make_pair(sub,count));
                    }
                }
                
                ri--;
                
            }// while(ri>=0)
        }
        
        
        for(unordered_map<string, int>::iterator it = um.begin(); it!=um.end(); it++){
            string sub = to_string(it->second);
            sub += " ";
            sub += it->first;
            result.push_back(sub);
        }
        
        return result;
    }
};