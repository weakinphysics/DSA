#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        vector <pair<long long int, long long int>> p(2);
        cin>>p[0].first>>p[1].first;
        cin>>p[0].second>>p[1].second;
        sort(p.begin(), p.end());
        // for(auto it: p) cout<<it.first<<" "<<it.second<<endl;
        if(p[1].second < p[0].second) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}




// long long int sliding(long long int l, long long int r, vector <long long int> &nums){
//     int n = nums.size();
//     long long int sum = 0;
//     long long int count = 0;
//     int j = 0;
//     for(int i = 0; i < n; i++){
//         sum += nums[i];
//         if(sum >= l && sum <= r){
//             count++;
//             j = i + 1;
//             sum = 0;
//         }
//         else if(sum > r){
//             while(j <= i && sum > r){
//                 sum -= nums[j];
//                 j++;
//             }
//             if(sum >= l){
//                 count++;
//                 j = i + 1;
//                 sum = 0;
//             }
//         }
//     }
//     return count;
// }


// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         long long int x,y,k;
//         cin>>x>>y>>k;
//         if(x == 0 || y == 1 || k == 0){
//             cout<<x<<endl;
//             continue;
//         }
//         x++;
//         k--;
//         while(true){
//             if(x == 1){
//                 x += (k%(y-1));
//                 break;
//             }
//             if(x%y == 0){
//                 x /= y;
//                 continue;
//             }
//             if(x <= y){
//                 if(k < y - (x%y)){
//                     x += k;
//                     break;
//                 }
//                 else{
//                     k -= (y  - (x%y));
//                     x = 1;
//                 }
//             }
//             else{
//                 if(k < y - (x%y)){
//                     x += k;
//                     break;
//                 }
//                 else{
//                     k -= (y - (x%y));
//                     x = x/y;
//                     x++;
//                 }
//             }
//         }
//         cout<<x<<endl;
//         // long long int n, l, r;
//         // cin>>n>>l>>r;
//         // vector <long long int> nums(n);
//         // for(int i = 0; i < n; i++) cin>>nums[i];
//         // long long int ans = sliding(l,r, nums);
//         // cout<<ans<<endl; 
//     }
//     return 0;
// }