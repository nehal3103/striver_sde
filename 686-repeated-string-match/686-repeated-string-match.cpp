class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = a;
        int repeat = b.length()/a.length();
        int count = 1;
        for(int i = 0; i < repeat + 2; i++){
            if(a.find(b) != string::npos){
                return count;
            }
            else{
                a = a + str;
                count++;
            }
        }
        return -1;
    }
};