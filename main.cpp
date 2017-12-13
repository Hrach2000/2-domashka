#include <iostream>
#include <string>
using namespace std;
int a=0,b=0;
string s;
int main()
{
	cin>>s;
	for(int i = 0;i<s.size();i++)
        {
            if ( (s[i]== '(' & s[i+1]== '}') || (s[i]== '{' & s[i+1]== ')'))
            {
                cout<<"false";
                    return 0;
            }
        }
	for(int i=0;i<s.size();i++)
	{
		if ( s[i] == '(' )
           a++;
        else
           if ( s[i] == ')' )
               if( --a < 0 )
                   break;
		if ( s[i] == '{' )
           b++;
        else
           if ( s[i] == '}' )
               if( --b < 0 )
                   break;

		}

		if(a==0 && b==0)
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
		return 0;
}
