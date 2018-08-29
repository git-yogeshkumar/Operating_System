//standard c++ library
#include<bits/stdc++.h>
//macro defination for "for loop"
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	cout<<"Enter Number of Processes : ";
	int p;
	cin>>p;
	//vector declaration with initial values 0 of size p
	vector<int> processes(p,0);
	vector<int> wt(p,0);
	vector<int> tat(p,0);
	f(i,p)processes[i]=i+1;
	f(i,p) cout<<processes[i];
	vector<int> burst(p);
	f(i,p) cin>>burst[i];
	cout<<"Enter Time Quantum : ";
	int tq;
	cin>>tq;
	vector<int> rbt(p);
	f(i,p) rbt[i] = burst[i];
	int t=0;
	while (1)
    {
        bool flg = true;
        f(i,p)
        {
            if (rbt[i] > 0)
            {
                flg = false;
                if (rbt[i] > tq)
                {
                    t += tq;
                    rbt[i] -= tq;
                }
                else
                {
                    t = t + rbt[i];
                    wt[i] = t - burst[i];
                    rbt[i] = 0;
                }
            }
        }
        if (flg == true)
          break;
    }
    int total_wt=0, total_tat=0;
    f(i,p) tat[i]=burst[i]+wt[i];
    f(i,p){
    	total_wt = total_wt+wt[i];
    	total_tat = total_tat+tat[i];
	}
	cout<<endl;
	cout<<"Burst Time	Wating Time		Turn Around Time"<<endl;
	f(i,p)cout<<burst[i]<<"				"<<wt[i]<<"				"<<tat[i]<<endl;
	cout<<"Average Waiting Time : "<<total_wt/p<<endl;
	cout<<"Average Turn Around Time : "<<((float)total_tat/(float)p);
}
