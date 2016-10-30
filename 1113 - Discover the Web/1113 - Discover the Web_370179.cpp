#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
 
using namespace std;
 
#define ll long long
 
int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while( t-- ){
        stack<string>back_ward;
        stack<string>for_ward;
        string command,current("http://www.lightoj.com/");
        cin >> command;
        printf("Case %d:\n",++ca);
        while( command[0] != 'Q' )
        {
            if(command[0] == 'V')
            {
                cin >> command;
                back_ward.push(current);
                current = command;
                while( !for_ward.empty() ){
                    for_ward.pop();
                }
                cout << current << endl;
            }
            else if( command[0] == 'B' )
            {
                if( back_ward.empty() )
                {
                    cout << "Ignored" << endl;
                }
                else
                {
                    for_ward.push(current);
                    current = back_ward.top();
                    back_ward.pop();
                    cout << current << endl;
                }
            }
            else if( command[0] == 'F' )
            {
                if( for_ward.empty() )
                {
                    cout << "Ignored" << endl;
                }
                else
                {
                    back_ward.push(current);
                    current = for_ward.top();
                    for_ward.pop();
                    cout << current << endl;
                }
            }
            cin >> command;
        }
    }
    return 0;
}
 
 
