#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
queue <unsigned short  int> q;
vector <string> v;
vector <pair <string, int>> lables;
pair <char, int> registers[26];
int it = 0;
void plus_q()
{
    unsigned short int a = q.front();
    q.pop();
    unsigned short int b = q.front();
    q.pop();
    q.push((a + b) % 65536);
}
void minus_q()
{
    unsigned short int a = q.front();
    q.pop();
    unsigned short int b = q.front();
    q.pop();
    q.push(abs((65536 + a - b)% 65536));
}
void multi ()
{
    unsigned short int a = q.front();
    q.pop();
    unsigned short int b = q.front();
    q.pop();
    q.push(abs((a * b)) % 65536);
}
void div()
{
    unsigned short int a = q.front();
    q.pop();
    unsigned short int b = q.front();
    q.pop();
    if (b == 0)
        q.push(0);
    else
        q.push((a / b) % 65536);
}
void mod()
{
    unsigned short int a = q.front();
    q.pop();
    unsigned short int b = q.front();
    q.pop();
    if (b == 0)
        q.push(0);
    else
        q.push((a % b) % 65536);
}
void get_reg(char c)
{
    unsigned short int a = q.front();
    q.pop();
    registers[c-'a'].second = a;
}
void push_reg(char c)
{
    unsigned short int a = registers[c-'a'].second;
    q.push(a % 65536);
}
void print_q()
{
    unsigned short int a = q.front();
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
    unsigned short int a = q.front();
    q.pop();
    cout << char(a % 256);
}
void print_reg_code(char c1) {
    int a = registers[c1 - 'a'].second;
    cout << char(a % 256);
}
void new_label(string s)
{
    pair<string, int> buf;
    buf.first = s;
    buf.second = it;
    lables.push_back(buf);
}
void join_label(string s)
{
    int i = 0;
    while (lables[i].first != s)
        i++;
    it = lables[i].second - 1;
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
    if (registers[c1 - 'a'].second > registers[c2-'a'].second)
        join_label(s);
}
unsigned short int str_to_int(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res*=10;
        res+=int(s[i])-'0';
    }
    return res;
}
int main() {
    for (int i = 0; i < 26; i++) {
        registers[i].first = 'a' + i;
        registers[i].second = 0;
    }
    string s;
    int i = 0;
    while(cin >> s)
    {
        v.push_back(s);
        it = i;
        if (v[i][0] == ':')
            new_label(v[i].substr(1));
        i++;
    }
    it = 0;
    while (it < v.size())
    {
        switch ( v[it][0] )
        {
            case 'Q':
                return 0;
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
                break;
            }
            case('J'):
            {
                join_label(v[it].substr(1));
                break;
            }
            case('Z'):
            {
                if_zero(v[it][1], v[it].substr(2));
                break;
            }
            case('E'):
            {
                if_simple(v[it][1], v[it][2], v[it].substr(3));
                break;
            }
            case('G'):
            {
                if_bigger(v[it][1],v[it][2], v[it].substr(3));
                break;
            }
            default:
            {
                q.push(abs(str_to_int(v[it]) % 65536));
            }
        }
        it++;
    }
    return 0;
}