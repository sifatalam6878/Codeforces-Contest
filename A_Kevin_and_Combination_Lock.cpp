#include <iostream>
#include <string>
using namespace std;
bool canUnlock(int x){
    while (x >= 33){
        string s = to_string(x);
        size_t pos = s.find("33");
        if (pos != string::npos) {
            s.erase(pos, 2);
            if (s.empty()) {
                x = 0;
            } else {
                x = stoi(s);
            }
        } else {
            x -= 33;
        }
    }
    return x == 0;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (canUnlock(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
