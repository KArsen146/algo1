#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <string>
using namespace std;
queue <int> q;
vector <string> v;
vector <pair <string,int>> lables;
pair <char, int> registers[26];
int it = 0;
void plus_q()
{
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    q.push((a + b) % 65536);
}
void minus_q()
{
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    q.push((a - b) % 65536);
}
void multi ()
{
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    q.push((a * b) % 65536);
}
void div()
{
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    if (b == 0)
        q.push(0);
    else
        q.push((a / b) % 65536);
}
void mod()
{
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    if (b == 0)
        q.push(0);
    else
        q.push((a % b) % 65536);
}
void get_reg(char c)
{
    int a = q.front();
    q.pop();
    registers[c-'a'].second = a;
}
void push_reg(char c)
{
    int a = registers[c-'a'].second;
    q.push(a);
}
void print_q()
{
    int a = q.front();
    q.pop();
    cout << a << '\n';
}
void print_reg(char c)
{
    int a = registers[c - 'a'].second;
    cout << a << '\n';
}
void print_code()
{
    int a = q.front();
    q.pop();
    char c = (a % 256);
    cout << c << '\n';
}
void print_reg_code(char c1)
{
    int a = registers[c1 - 'a'].second;
    char c = (a % 256);
    cout << c << '\n';
}
void new_label(string s)
{
    bool t = true;
    for (int i = 0; i < lables.size(); i++)
        if (lables[i].first == s)
            t = false;
    if (t)
    {
        pair<string, int> buf;
        buf.first = s;
        buf.second = it;
        lables.push_back(buf);
    }
}
void join_label(string s)
{
    int i = 0;
    while (lables[i].first != s)
        i++;
    it = lables[i].second;
}
void if_zero(char c, string s)
{
    if (registers[c- 'a'].second == 0)
        join_label(s);
}
void if_simple(char c1, char c2, string s)
{
    if (registers[c1 - 'a'].second == registers[c2-'a'].second)
        join_label(s);
}
void if_bigger(char c1, char c2, string s)
{
    if (registers[c1 - 'a'].second == registers[c2-'a'].second)
        join_label(s);
}
int str_to_int(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res*=10;
        res+=int(s[i])-'0';
    }
    return res;
}
int main() {
   // freopen("quack.in", "r", stdin);
 //   freopen("quack.out", "w", stdout);
    for (int i = 0; i < 26; i++) {
        registers[i].first = 'a' + i;
        registers[i].second = 0;
    }
    string s;
    int i = 0;
    while(cin >> s) {
        v.push_back(s);
        it = i;
        if (v[i][0] == ':')
            new_label(v[i].substr(1));
        i++;
    }
    it = 0;
    while ((v[it] != "Q") && (it < v.size()))
    {
        switch ( v[it][0] )
        {
            case '+':
            {
                plus_q();
                break;
            }
            case '-':
            {
                minus_q();
                break;
            }
            case '*':
            {
                multi();
                break;
            }
            case '/':
            {
                div();
                break;
            }
            case '%':
            {
                mod();
                break;
            }
            case('>'):
            {
                get_reg(v[it][1]);
                break;
            }
            case('<'):
            {
                push_reg(v[it][1]);
                break;
            }
            case ('P'):
            {
                if (v[it].size() == 1)
                    print_q();
                else
                    print_reg(v[it][1]);
                break;
            }
            case('C'):
            {
                if(v[it].size() == 1)
                    print_code();
                else
                    print_reg_code(v[it][1]);
                break;
            }
            case(':'):
            {
                // new_label(v[it].substr(1));
                break;
            }
            case('J'):
            {
                join_label(v[it].substr(1));
                break;
            }
            case('Z'):
            {
                if_zero(s[1], v[it].substr(2));
                break;
            }
            case('E'):
            {
                if_simple(s[1], s[2], v[it].substr(3));
                break;
            }
            case('G'):
            {
                if_bigger(s[1],s[2], v[it].substr(3));
                break;
            }
            default:
            {
                q.push(str_to_int(v[it]));
            }
        }
        it++;
    }
    return 0;
}