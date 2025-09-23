/*
 * enlace al problema: https://omegaup.com/arena/problem/Minimo-comun-multiplo-de-varios-/
 *
 * Author: Aragón Galván
 *
 * Date: 23/09/25
 *
 */

#include <iostream>

using namespace std;

int mcd(int,int);
int mcm(int,int);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t,k,r;
  cin >> t;
  t--;
  cin >> k;

  while (t--) {
    cin>>r;
    k=mcm(k,r);
  }

  printf("%i",k);

  return 0;
}

int mcd(int a, int b){
  if (b==0)
    return a;
  return mcd(b,a%b);
}

int mcm(int a, int b){
  return (a*b)/mcd(a,b);
}
