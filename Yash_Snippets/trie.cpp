// #include<bits/stdc++.h>
// using namespace std;

// /*For interviews
// struct node{
//     vector<node*> v;
//     bool isWord;
//     node(){
//         v.assign(26, nullptr);
//         isWord = false;
//     }
// };
// node* root;
// */

// // comparison of two strings
// struct node{
//     map<char, node*> mp;
//     bool isWord;
//     node(){
//         isWord = false;
//     }
// };
// node* root;

// void insert(string &s){
//     node* curr = root;

//     for(auto ch : s){
//         if(curr->mp[ch] == nullptr){
//             curr->mp[ch] = new node();
//         }

//         curr = curr->mp[ch];
//     }
//     curr->isWord = true;
// }

// bool check(string &s){
//     node* curr = root;

//     for(char ch : s){
//         if(curr->mp[ch] == nullptr){
//             return false;
//         }
//     }

//     return curr->isWord;
// }

// int main(){
//     root = new node();

//     // map : nlogn
//     // trie : n

// }

#include <bits/stdc++.h> 
using namespace std;

struct node{
    bool isWord = true;
    map<char, node*> mp;
    node(){
        isWord = false;
    }
};
node* root;

void insert(string s){
    node* curr = root;
    for(auto ch: s) {
        if(curr->mp[ch] == nullptr){
            curr -> mp[ch] = new node();
        }
        curr = curr -> mp[ch];
    }
    curr -> isWord = true;
}

bool checkPrefix(string s) {
    node* curr = root;
    bool flag = true;
    for(auto ch: s) {
        if(curr->mp[ch]){
            curr = curr -> mp[ch];
            flag = flag & (curr -> isWord);
        }
        else{ 
            return false;
        }
    }
    return flag;    
}

string completeString(int n, vector<string> &a){
    root = new node();
    for(int i = 0; i < n; i++){
        insert(a[i]);
    }
    
    string ans = "";
    for(int i = 0; i < n; i++) {
        bool temp = checkPrefix(a[i]);
        if(temp){
            if(a[i].size() > ans.size()){
                ans = a[i];
            }
            else if(a[i].size() == ans.size() && a[i] < ans) {
                ans = a[i];
            }
        }
    }
   return ans == "" ? "None" : ans;
}