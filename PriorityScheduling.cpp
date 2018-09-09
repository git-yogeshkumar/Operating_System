//Priority Scheduling
#include<bits/stdc++.h>
//macro defination for "for loop"
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	cout<<"Enter the number of Processes : ";
	int p;
	cin>>p;
	vector<int> tat(p,0); //vector to store turn around time
	vector<int> wt(p,0); //vector to store waiting time  
	vector<int> ct(p,0); //vector to store Completion Time
	vector<pair<int,int> > pribt; //vector of pair having priority and burst time
	f(i,p){
		int priority;
		int bt;
		cout<<"Enter Burst Time and Priority of Process "<<i+1<<" :"<<endl;
		cin>>bt>>priority;
		pribt.push_back(make_pair(priority,bt));
	}
	//sort function of standard template library
	sort(pribt.begin(),pribt.end());
	//reverse function of standard template library
	reverse(pribt.begin(),pribt.end());
	// Calculating the waiting time for all processes
	f(i,p){
		if(i==0)
		continue;
		else
		wt[i] = pribt[i-1].second + wt[i-1] ;
	}
	// calculating turnaround time by adding
    // bt[i] + wt[i]
	f(i,p){
		tat[i]=pribt[i].second+wt[i];
	}
	//Calulation of Average wt and Turn Around time
	int wt_total=0;
	int tat_total=0;
	f(i,p){
		wt_total+=wt[i];
		tat_total+=tat[i];
	}
	//format the dispaly results accordingly
	cout<<endl;
	cout<<"Priority 	Burst Time		 Wating Time		Turn Around Time"<<endl;
	f(i,p)cout<<pribt[i].first<<"		"<<pribt[i].second<<"		"<<wt[i]<<"		"<<tat[i]<<endl;
	cout<<"Average Waiting Time : "<<(float)wt_total/(float)p<<endl;
	cout<<"Average Turn Around Time : "<<((float)tat_total/(float)p);
}
