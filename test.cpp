#include <iostream>

using namespace std;
int main(){
    string seed ="ASDGHSGJAHVX";
    for (int i = 0; i < seed.size(); ++i) {
        string name = "ѡ��";
        name += seed[i];
        cout<<name<<endl;
    }
    return 0;
}