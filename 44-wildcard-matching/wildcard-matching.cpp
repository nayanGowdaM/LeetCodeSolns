// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sBacktrackIdx = -1, nextToWildcardIdx = -1;
//         while (sIdx < s.size()) {
//             if (pIdx < p.size() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) { 
//                 // chars match
//                 ++sIdx;
//                 ++pIdx;
//             } else if (pIdx < p.size() && p[pIdx] == '*') { 
//                 // wildcard, so chars match - store index.
//                 lastWildcardIdx = pIdx;
//                 nextToWildcardIdx = ++pIdx;
//                 sBacktrackIdx = sIdx;
                 
//                 //storing the pidx+1 as from there I want to match the remaining pattern 
//             } else if (lastWildcardIdx == -1) { 
//                 // no match, and no wildcard has been found.
//                 return false;
//             } else { 
//                 // backtrack - no match, but a previous wildcard was found.
//                 pIdx = nextToWildcardIdx;
//                 sIdx = ++sBacktrackIdx;
//                 //backtrack string from previousbacktrackidx + 1 index to see if then new pidx and sidx have same chars, if that is the case that means wildcard can absorb the chars in b/w and still further we can run the algo, if at later stage it fails we can backtrack
//             }
//         }
//         for(int i = pIdx; i < p.size(); i++){
//             if(p[i] != '*') return false;
//         }
//         return true;
//     }
// };




class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx=0,pIdx=0,sBackTrack=-1,lastWildCard=-1,nextTOwildCard=-1;
        int m=s.size(), n=p.size();
        while(sIdx<m){
            if(pIdx<n && ( p[pIdx]=='?'  || s[sIdx]==p[pIdx]  )){
                sIdx++;
                pIdx++;
            }
            else if(pIdx<n && p[pIdx]=='*') {
                lastWildCard=pIdx;
                nextTOwildCard= ++pIdx;
                sBackTrack=sIdx;
            }
            else if(lastWildCard==-1) return false;
            else {
                pIdx=nextTOwildCard;
                sIdx= ++sBackTrack;
            }
        }
        for(int i=pIdx;i<n;i++) if(p[i]!='*'  ) return false;
        return true;
    }
};