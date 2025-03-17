class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        do{
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];
            
            if(hours<24 && minutes<60){
                string time = "";
                if(hours<10){
                    time+="0";
                }
                time += to_string(hours);
                time += ":";
                
                if(minutes<10){
                    time += "0";
                }
                
                time += to_string(minutes);
                return time;
            }
        }while(prev_permutation(arr.begin(), arr.end()));
        
        return "";
    }
};