#include<bits/stdc++.h>
using namespace std;
int N ;

void Div_Con(int n) {

    int str_sz = pow(3, n - 1) ;

	if (n == 0)
    {
		cout << "-";
		return;
	}

	Div_Con(n - 1) ;
	for (int i = 0 ; i < str_sz ; i++)
		cout << " " ;
	Div_Con(n - 1) ;

}

int main()
{
    while(cin >> N)
    {
        Div_Con(N) ;
        cout << "\n" ;
    }
}