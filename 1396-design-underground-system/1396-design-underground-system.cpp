class UndergroundSystem {
public:
    //12:44
    
    unordered_map<int,pair<int,string>> user;
    unordered_map<string,pair<double,int>> time;
    UndergroundSystem() {
       
    }
    
    void checkIn(int id, string stationName, int t) {
        unordered_map<int,pair<int,string>>::iterator
            per = user.find(id);
        
        if(per != user.end()){
            per->second.first = t;
            per->second.second = stationName;
        }
        else{
            user.insert(pair<int,pair<int,string>>(id,make_pair(t,stationName)));
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        unordered_map<int,pair<int,string>>::iterator
            per = user.find(id);
        
        unordered_map<string,pair<double,int>>::iterator 
            at = time.find(makeStation(per->second.second, stationName));
        
        if(at!=time.end()){
            at->second.first += t-per->second.first;
            at->second.second += 1;
        }
        else{
            time.insert(pair<string,pair<double,int>>
                        (makeStation(per->second.second, stationName),
                        make_pair(t-per->second.first,1)));
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        unordered_map<string,pair<double,int>>::iterator 
            at = time.find(makeStation(startStation, endStation));
        
        return at->second.first/at->second.second;
    }
    
    string makeStation(string s, string e){
        return s+" "+e;
    }

    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */