class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //if sort it then its directly going to be nlog(n) and done in a single pass
        // but if feed it into the map then what how do i it ?
        //lets say i am parsing the array and i am first element then i decided to add 2 in the map
        // then should i simultaneously add 3 as well ??

        // OR in the second pass do i just search the elements like 
        // first there was 2 i search for 3 count++
        // then use 3 count ++
        // then use 4 count++
        


        map<int, int> mp;
        for(auto &it: nums){
            mp[it]++;
        }
        int prev=INT_MIN;
        bool first=true;
        int count=0, maxcount=0;
        for(auto it : mp){
            if(first){
                first=false;
                count++;
            }else{
                if(it.first==prev+1){
                    count++;
                    // prev=it.first;
                }else{
                    count=1;
                    // prev=it.first;
                }
            }
            prev=it.first;
            maxcount=max(count, maxcount);
        }
        return maxcount;
        
    }
};
