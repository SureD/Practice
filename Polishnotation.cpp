/* Polish notation
 * tranfermation bewteen notions
 *
 * stack
 *
 * the function can ignore space in the notation
 * 
 *
 */
#include<iostream>
#include<stack>
#include<string.h>
#include<stdlib.h>
typedef char* notation;
typedef char opt;
using namespace std;

notation mid2pol(notation p)
{
    if(p==NULL) return p;
    stack<opt> s_opt;
    stack<opt> reverse;
    notation q;
    int n_size=0;
    char aux;
    char *ans;

    // ignore space
    for(;*p==' ';p++);
    q = p;   
    // reverse mid notation 
    // also ingore the space in the notation
    while(*p)
    {
        char a;
        a = *p;
        switch(*p){
        case ' ':
            break;
        default:
            reverse.push(*p);
        }
        p++;
    }
    p = q;
    ans = q;
    n_size = reverse.size();

    // transfer the nonation
    // make sure dump all "reverse"'s stuff
    while(reverse.size())
    {
        char t,t2;
        t = reverse.top();
        switch(t){
            case'+':
                s_opt.push(t);
                break;
            case'-':
                s_opt.push(t);
                break;
            case'*':
                s_opt.push(t);
                break;
            case'/':
                s_opt.push(t);
                break;
            case')':
                s_opt.push(t);
                break;
            case'(':
                t2 = s_opt.top();
                while(t2!=')')
                {
                    s_opt.pop();
                    *p++ = t2;
                    t2 = s_opt.top();
                  //  n_size--;
                }
                s_opt.pop();
                break;
            default:
                *p++ = t;
            
        }
        reverse.pop();
    }

    // if s_opt still have operaters then dump them all
    n_size = s_opt.size();
    while(n_size--){
        char t;
        t = s_opt.top();
        *p++ = t;
        s_opt.pop();
    }
    *p = '\0';
    p--;
    //reverese the notation
    while(q<p){
        aux = *q;
        *q = *p;
        *p = aux;
        q++;
        p--;
    }
    return ans;
}
int main()
{
    string a;
   // a = "4* 3/(5-2)+6";
    cout<<"Please type an notation use charactor '#' for end of the nonation\n";
  //  getline(cin,a,'#');
   a = "a+(b*3)/(4+c)";
    char *p;
    int len;
    len = a.size();
    p = (char*)malloc(2*len*sizeof(char));
    a.copy(p,len,0);
   // char p[] ="  4* 3/(5-2)+6";
    notation q;
    q = mid2pol(p);
    cout<<"The polish notation is"<<endl;
    while(*q)
        cout<<*q++;
    cout<<endl;
}
