#include <bits/stdc++.h>


using namespace std;

string padStart(string s, int n, char c){
    int k = s.size();
    string straw;
    straw.resize(n+k);
    for(int i = 0; i < n; i++){
        straw[i] = c;
    }
    for(int i = 0; i < k; i++){
        straw[i + n] = s[i];
    }
    return straw;
}
string add(string num1, string num2){
    string ans;
    
    int n = num1.size();
    int m = num2.size();

    int x = max(n, m);

    num1 = padStart(num1, max(n, m)- n , '0');
    num2 = padStart(num2, max(n, m) -m , '0');
    n = max(n, m);

    int carry = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = (num1[n - i -1] - '0' + num2[n - i - 1] - '0' + carry)%10;
        carry = (num1[n - i -1] - '0' + num2[n - i - 1] - '0' + carry)/10;
        ans.push_back(sum + '0');
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string padEnd(string s, int n, char c){
    for(int i = 0; i < n; i++) s.push_back(c);
    return s;
}

string stripLeadingZeroes(string p){
    int mew = p.size();
    string truth;
    for(int i = 0; i < mew; i++){
        if(p[i] != '0'){
            mew = i;
            break;
        }
    }
    if(mew == p.size()){
        string claw = "0";
        return claw;
    }
    for(int i = mew; i < p.size(); i++){
        truth.push_back(p[i]);
    }
    return truth;
}

string subtract(string num1, string num2){

    // cout<<num1<<" "<<num2<<endl;
    // in this case we are guaranteed that the first number will be larger than or equal to the second

    int n = num1.size();
    int m = num2.size();

    int x = max(n, m);

    num1 = padStart(num1, max(n, m)- n , '0');
    num2 = padStart(num2, max(n, m) -m , '0');
    n = max(n, m);


    string ans = "";
    int borrow = 0;
    int diff = 0;
    int a, b;
    for(int i = 0; i < n; i++){
        a = num1[n - i - 1] - '0';
        b = num2[n - i - 1] - '0';
        if(a >= b + borrow){
            ans.push_back(a - b - borrow + '0');
            borrow = 0;
        }
        else{
            ans.push_back(a + 10 - b - borrow + '0');
            borrow = 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string product(string num1, string num2){
    int n = num1.size();
    int m = num2.size();
    if(n == 1  && m == 1){
        string t = "";
        int prod = (num1[0]-'0')*(num2[0]-'0');
        t.push_back(prod%10 + '0');
        if(prod >= 10){
            t.push_back(prod%10 + '0');
            t[0] = prod/10 + '0'; 
        }
        return t;
    }


    int x = max(n, m);
    if(x & 1) x++;         // when we partition a string, we can only have a difference of one(assuming the string was odd-lengthed);
    num1 = padStart(num1, x - n, '0');
    num2 = padStart(num2, x - m, '0');
    int l1 = x/2;
    string num3 = num1.substr(0, l1);
    string num4 = num1.substr(l1, l1);
    string num5 = num2.substr(0, l1);
    string num6 = num2.substr(l1, l1);
    string k1 = product(num3, num5);
    string k2 = product(num4, num6);
    string k3 = product(add(num3, num4), add(num5, num6));

    int r = k3.size();
    string a = padEnd(k1, x, '0');
    string b = subtract(k3, add(k1, k2));
    b = padEnd(b, l1, '0');
    string ans = add(a, add(b, k2));
    ans = stripLeadingZeroes(ans);
    return ans;
}

string multiply_karatsuba(string num1, string num2) {
    // this is suboptimal code, mind you.
    string p = product(num1, num2);
    return p;
}