#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string , string> mp;
map<string,bool> mp1;
int main(){
    string s,s1,s2;
    while(cin>>s){
        if(s=="INSERT"){
            cin>>s1>>s2;
            if(mp1[s1])
                cout<<"Changed. Old value = "<<mp[s1]<<endl;
            else
                cout<<"OK"<<endl;
            mp1[s1]=true;
            mp[s1]=s2;
        }
        else{
            cin>>s1;
            if(mp1[s1])
                cout<<mp[s1]<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
