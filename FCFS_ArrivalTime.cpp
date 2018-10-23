//First Come First Serve Scheduling
#include<bits/stdc++.h>
//macro defination for "for loop"
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	cout<<"Enter the Number of Processes : ";
	int p;
	cin>>p;
	vector<int> tat(p,0); //vector to store turn around time
	vector<int> wt(p,0); //vector to store waiting time  
	vector<int> ct(p,0); //vector to store Completion Time
	vector<int> at(p,0); //vector to store Arrival Time
	vector<pair<int,int> > atbt; //vector of arrival time & burst time pairs
	f(i,p){
		int at,bt;
		cout<<"Enter the Arrival time and Burst time of Process "<<i+1<<" :"<<endl;
		cin>>at>>bt;
		atbt.push_back(make_pair(at,bt));
	}
	f(i,p){
		if(i==0){
			ct[i]+=atbt[i].second;
			tat[i]=ct[i]-atbt[i].first;
			wt[i]=tat[i]-atbt[i].second;
		}
		else{
			ct[i]=ct[i-1]+atbt[i].second; 	//Loop for calculating Completion time
			tat[i]=ct[i]-atbt[i].first;	//loop for calculating Turn Around Time
			wt[i]=tat[i]-atbt[i].second;	//loop for calculating Waiting Time
			
			while(wt[i]<0){			//to handle negative waiting time, happens when CPU is ideal
				wt[i]+=1;
				ct[i]+=1;
				tat[i]+=1;
			}
		}
		
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
	cout<<"Arrival Time\tBurst Time\tCompletion time\tWating Time\tTurn Around Time"<<endl;
	f(i,p)cout<<atbt[i].first<<"\t\t"<<atbt[i].second<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	cout<<"Average Waiting Time : "<<(float)wt_total/(float)p<<endl;
	cout<<"Average Turn Around Time : "<<((float)tat_total/(float)p);
}
