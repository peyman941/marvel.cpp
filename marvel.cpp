/*in this program we simulate th marvel structure that propose in his article"encouraging moderation"you
can find his article "encouraging moderation:clus from a simple model of ideological conflict"
from researchgate*/




#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  ofstream output("./marvel.txt");
  unsigned seed=time(NULL);
  srand(seed);

  double state[100];
  //inial condition
  int t=0;
  double a0_num=0;
double b0_num=90;
  double ab0_num=0;
double ac0_num=10;/*number of zealot nod*/
  int i=0;
  int r;
  for (size_t j = 0; j<100; j++) {
  state[j]=2;
  }
  while (i<ac0_num) {
    r=rand()%100;
    if (state[r]==2) {
      state[r]=4;
    }
  i++;
}
double percentage0=(a0_num+b0_num+ab0_num+ac0_num)/100;
output<<t<<"\t"<<a0_num/100.0<<"\t"<<b0_num/100.0<<"\t"<<ab0_num/100.0<<"\t"<<ac0_num/100.0<<"\t"<<percentage0<<endl;
  //********************************************
//test output for initial condition
  /*for (size_t i = 0; i <100;i++) {
    std::cout << state[i] << '\t';
  }*/
  //**********************************************
  double ab_num=ab0_num;
  double  a_num=a0_num;
double b_num=b0_num;
double  ac_num=ac0_num;
  int t_new=1;
  int t_max=4600;
  while (t_new<t_max&&a_num>=0&&b_num>=0&&ab_num>=0&&ac_num>=0) {

  /*listener*/ int r1=rand()%100;
  /*speaker*/  int  r2=rand()%100;
  if (state[r1]==4) {
    continue;
  }
  else if(state[r1]==1&&state[r2]==2){
  state[r1]=3;
  a_num--;
  ab_num++;
  }
  else if(state[r1]==3&&state[r2]==2){
    state[r1]=2;
  ab_num--;
    b_num++;
  }
  else if(state[r1]==2&&state[r2]==4){
    state[r1]=3;
    b_num--;
    ab_num++;
  }
  else if(state[r1]==2&&state[r2]==1){
    state[r1]=3;
    b_num--;
    ab_num++;
  }
  else if(state[r1]==3&&state[r2]==4){
    state[r1]=1;
    ab_num--;
    a_num++;
  }
  else if(state[r1]==3&&state[r2]==1){
    state[r1]=1;
   ab_num--;
    a_num++;
  }
  else if(state[r1]==1&&state[r2]==3){
    state[r1]=1;
  }
  else if(state[r1]==2&&state[r2]==3){
    state[r1]=2;
  }
  double percentage=(a_num+b_num+ab_num+ac_num)/100;
  output<<t_new<<"\t"<<a_num/100.0<<"\t"<<b_num/100.0<<"\t"<<ab_num/100.0<<"\t"<<ac_num/100.0<<"\t"<<percentage<<endl;
  t_new++;

}

  return 0;
}
