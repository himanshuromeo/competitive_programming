#include <bits/stdc++.h>

using namespace std;

ofstream fout("sitout.txt");  //for output
ifstream fin("sitin.txt");  //for input

int main(){
  long long a,b,c;
  fin>>a>>b>>c;   //'fin' and not 'cin'
  (c>=a*b)?fout<<a*b<<" "<<c-a*b:fout<<c<<" "<<0<<endl;
}
