#include <bits/stdc++.h>
using namespace std;

int validatepass(string temp)
{
   bool upcase=0;         //used for upper case
   bool lowcase=0;          //used for lower case
   bool digit=0;            //used for digit
   bool schar=0;            //used for special characters allowed
   bool nchar=0;            //used for special characters not allowed

   for(int i=0;i<temp.length();i++)
   {
       if(isupper(temp[i]))
        upcase=1;
       else if(islower(temp[i]))
        lowcase=1;
       else if(isdigit(temp[i]))
        digit=1;
       else if(temp[i]=='*' || temp[i]=='$' || temp[i]=='_' || temp[i]=='#' || temp[i]=='=' || temp[i]=='@')
        schar=1;
       else if(temp[i]=='%' || temp[i]=='!' || temp[i]==')' || temp[i]=='(')
        nchar=1;
   }
   if(upcase==0)                        // this 10-12 lines tell which error should be shown
    return 1;
   else if(lowcase==0)
    return 2;
   else if(digit==0)
    return 3;
   else if(nchar==1)
    return 5;
   else if(schar==0)
    return 4;
   else
    return 6;
}


int main()
{
    string str;

    cout<<"Enter the string of password with comma separated"<<endl;
    cout<<endl;
    cin>>str;

    cout<<endl;
    stringstream ss(str);

    string temp;                        //contain individual string
    int result;                         //tells whether each string is valid or not

    while(getline(ss,temp,','))        //split the string entered by the user
        {
            result=0;

            if(temp.length()<6)
            {
                cout<<temp<<" Failure Password must be at least 6 characters long."<<endl<<endl;
                continue;
            }
            if(temp.length()>12)
            {
                cout<<temp<<" Failure Password must be at max 12 characters long."<<endl<<endl;
                continue;
            }

            result=validatepass(temp);   // check whether string is valid or not

            if(result==1)
                cout<<temp<<" Failure Password must contain at least one letter from A-Z."<<endl<<endl;
            else if(result==2)
                cout<<temp<<" Failure Password must contain at least one letter from a-z."<<endl<<endl;
            else if(result==3)
                cout<<temp<<" Failure Password must contain at least one letter from 0-9."<<endl<<endl;
            else if(result==4)
                cout<<temp<<" Failure Password must contain at least one letter from *$_#=@."<<endl<<endl;
            else if(result==5)
                cout<<temp<<" Failure Password cannot contain %!)(."<<endl<<endl;
            else if(result==6)
                cout<<temp<<" Success"<<endl<<endl;
        }

    return 0;


}
