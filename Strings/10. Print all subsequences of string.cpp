https://www.youtube.com/watch?v=Yg5a2FxU4Fo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=13&t=595s&ab_channel=AdityaVerma

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string ip, string op) {

    if (ip.length() == 0) {
        cout << op << " ";
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    solve(ip, op1);
    solve(ip, op2);

}

int main() {
    string ip;
    cin >> ip;
    string op = "";
    solve(ip, op);
}
