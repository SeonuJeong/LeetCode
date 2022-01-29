class Solution {
public:
    
    vector<vector<int>> firstList;
    vector<vector<int>> secondList;
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int apos=0, bpos=0;
        
        this->firstList = firstList;
        this->secondList = secondList;
        
        vector<vector<int>> result;
        
        while(apos<firstList.size() && bpos<secondList.size()){
            
           pair<int,int> pr = intersection(apos,bpos);
            
            if(pr.first!=-1){
                result.push_back(vector<int>(2));
                result.back()[0] = pr.first;
                result.back()[1] = pr.second;
            }
            
            if(firstList[apos][1]>secondList[bpos][1]){
                bpos++;   
            }
            else apos++;
        }
        
        return result;
    }
    
    pair<int,int> intersection(int apos,int bpos){
        pair<int,int> bf;
        pair<int,int> af;
        
        if(firstList[apos][0] <= secondList[bpos][0]){
            bf = make_pair(firstList[apos][0],firstList[apos][1]);
            af = make_pair(secondList[bpos][0],secondList[bpos][1]);
        }
        else{
            bf = make_pair(secondList[bpos][0],secondList[bpos][1]);
            af = make_pair(firstList[apos][0],firstList[apos][1]);
        }
        
        
        if(bf.second < af.first){
            return make_pair(-1,-1);
        }
        else if(bf.second >= af.first && bf.second <= af.second){
            return make_pair(af.first, bf.second);
        }
        else if(bf.second > af.second){
            return make_pair(af.first, af.second);
        }
        
        return make_pair(-1,-1);
    }
};