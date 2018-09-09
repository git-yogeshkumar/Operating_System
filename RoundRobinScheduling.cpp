//Round Robin Scheduling.
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
	vector<int> wt(p,0); //vector to store waiting time
	vector<int> tat(p,0); //vector to store turn around time
	f(i,p)processes[i]=i+1;
	vector<int> burst(p); //vector to store burst time
	f(i,p) cin>>burst[i];
	//take the time quantum input
	cout<<"Enter Time Quantum : ";
	int tq;
	cin>>tq;
	vector<int> rbt(p); //vector to store remaining burst time
	f(i,p) rbt[i] = burst[i];
	int t=0;
	while (1)
    {
        bool flg = true;
        f(i,p)
        {
            if (rbt[i] > 0) //If there is some burst time remaining for the process we need to further consider it.
            {
                flg = false;
                if (rbt[i] > tq)
                {
                    t += tq;
                    rbt[i] -= tq; // Remaining burst time = Remaining burst time - Time quantum for which it ran 
                }
                else
                {
                    t = t + rbt[i];
                    wt[i] = t - burst[i]; //Waiting time calculation
                    rbt[i] = 0;
                }
            }
        }
        if (flg == true)
          break;
    }
    int total_wt=0, total_tat=0;
    f(i,p) tat[i]=burst[i]+wt[i]; // turn around time calculation
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
