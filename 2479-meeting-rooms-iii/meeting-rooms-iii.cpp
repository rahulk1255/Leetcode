class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        priority_queue<int,vector<int>,greater<int>>free_room;
        for(int i=0;i<n;i++){
            free_room.push(i);
        }
        int m=meetings.size();
        vector<int>ans(n,0);
        for(int i=0;i<m;i++){
            long long  start=meetings[i][0];
            long long end=meetings[i][1];
            long long  duration=end-start;
            
            while(!pq.empty() && pq.top().first<=start){
                free_room.push(pq.top().second);
                pq.pop();
            }

            if(!free_room.empty()){
                int room=free_room.top();
                free_room.pop();
                pq.push({end,room});
                ans[room]++;
            }else{
                auto [finish,room] = pq.top();
                pq.pop();
                pq.push({finish+duration,room});
                ans[room]++;
            }
        }

        int max_meeting=INT_MIN;
        int room_number;
        for(int i=0;i<n;i++){
            if(max_meeting<ans[i]){
                max_meeting=ans[i];
                room_number=i;
            }else if(max_meeting==ans[i]){
                room_number=min(room_number,i);
            }
        }

        return room_number;
    }
};
