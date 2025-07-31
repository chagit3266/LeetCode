class Solution {
public:
    static bool comper(const vector<int>& a,const vector<int> &b){
    return a[1]<b[1];
}
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(courses.begin(),courses.end(),comper);
    
    int curr_time=0;
    int count=0;
    std::priority_queue<int> maxHeap;
    
    for(vector <int> course :courses){
        int duration=course[0];
        int last_day=course[1];
        
        curr_time+=duration;
        
        maxHeap.push(duration);
        
        if(curr_time>last_day){
            //אם הקורס שהוספנו הוא עם הזמן המקסימלי אז הוא יצא פה
            curr_time-=maxHeap.top();
            maxHeap.pop();
        }
    }
    
    return maxHeap.size();
    }
};