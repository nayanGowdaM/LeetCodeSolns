class Solution {
public:
    int countSegments(string s) {
        vector<string>v;
        int n=s.size();
        for(int i=0;i<s.size();){
            // string str="";
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            int j=i;
            while(j<n && s[j]!=' ') j++;
            if(j<=n){
                string str(s.begin()+i,s.begin()+j);
                v.push_back(str);
            }
            i=j+1;
        }
        return v.size();
    }
};