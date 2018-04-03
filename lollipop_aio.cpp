//ac
//Link - https://orac.amt.edu.au/cgi-bin/train/problem.pl?set=aio17sen&problemid=985
#include <bits/stdc++.h>

using namespace std;

ofstream fout("lscout.txt");
ifstream fin("lscin.txt");

int main(){
  int N,i,j,lefti,righti;
  long long L,k,left,right;
  vector<long long> Pos;
  vector<long long> leftv;
  vector<long long> rightv;
  vector<int> Permut;
  bool flag=0;
  fin>>N>>L;
  for(i=0;i<N;i++){
    fin>>k;
    Pos.push_back(k);
  }
  for(i=0;i<N;i++){
    fin>>j;
    Permut.push_back(j-1);
  }
  //deciding left and right borders
  left=1;
  right=L;
  for(i=1;i<N;i++){
    if(Pos[Permut[i]]<Pos[Permut[0]]){
      leftv.push_back(Pos[Permut[i]]);
    }
  }
  for(i=1;i<N;i++){
    if(Pos[Permut[i]]>Pos[Permut[0]]){
      rightv.push_back(Pos[Permut[i]]);
    }
  }
  /*for(i=0;i<rightv.size();i++){
    fout<<rightv[i]<<" ";
  }
  fout<<endl;
  for(i=0;i<leftv.size();i++){
    fout<<leftv[i]<<" ";
  }
  fout<<endl;*/
  for(i=0;i<rightv.size()-1 && !rightv.empty();i++){
    if(rightv[i]>rightv[i+1]){
      flag=1;
      //fout<<"right";
      break;
    }
  }
  for(i=0;i<leftv.size()-1 && !leftv.empty();i++){
    if(leftv[i]<leftv[i+1]){
      flag=1;
      //fout<<"left";
      break;
    }
  }
  if(!(leftv.empty() || rightv.empty()) && flag!=1){
    left=(Pos[Permut[0]]+leftv[0])/2;
    right=(Pos[Permut[0]]+rightv[0])/2;
    //fout<<left<<" "<<right<<endl;
    lefti=0;
    righti=0;
    for(i=1;i<N;i++){
      if(lefti>=leftv.size()){
        break;
      }
      else if(righti>=rightv.size()){
        break;
      }
      if(Pos[Permut[i]]<Pos[Permut[0]]){
        if((Pos[Permut[i]]+rightv[righti])/2 < right){
          right = (Pos[Permut[i]]+rightv[righti])/2;
        }
        lefti++;
      }
      if(Pos[Permut[i]]>Pos[Permut[0]]){
        if((Pos[Permut[i]]+leftv[lefti])/2 > left){
            left = (Pos[Permut[i]]+leftv[lefti])/2;
        }
        righti++;
      }
      //fout<<i<<" "<<Pos[Permut[i]]<<" "<<left<<" "<<right<<endl;
    }
  }
  else if(leftv.empty() && flag!=1){
    left=1;
    right=1;
  }
  else if(rightv.empty() && flag!=1){
    left=L;
    right=L;
  }
  if(left>right || flag==1)
    fout<<-1<<endl;
  else
    fout<<left<<endl;
  return 0;
}
