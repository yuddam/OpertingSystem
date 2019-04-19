#include<iostream>
using namespace std;
int main()
{
  int max_need[10][10], required[10][10], res_allo[10][10], avail[10], processed[10], safeorder[10];
  int p,r,i,j,process,count=0;

  cout<<"Enter the number of processes: ";
  cin>>p;
  for(i=0; i<p; i++)
    {
       processed[i]=0;
    }
  
  cout<<Enter the number of resources:  ";
  cin>>r;
  
  cout<<" Enter the max_need requireduirement for each process :  ";
  for(i=0;i<p;i++)
   {
      cout<<("for process %d : ",i+1);
      for(j=0;j<r;j++)
      {
          cin>>max_need[i][j]);
      }
   }
  
  cout<<Enter the allocation for each process : ";
  for(i=0;i<p;i++)
   {
      cout<<("For process %d : ",i+1);
      for(j=0;j<r;j++)
      {
          cin>>("%d",&res_allo[i][j]);
      }
   }
 
  cout<<"Enter the avaibility of the resources : ";
  for(i=0;i<r;i++)
   {
      cin>>avail[i];
   }
    
  for(i=0;i<p;i++)
  {
     for(j=0;j<r;j++)
     {
        required[i][j]= max_need[i][j]- res_allo[i][j];
     }
  }
 
  count=0;
  do
  {
     process=-1;
     
     for(i=0;i<p;i++)
     {
       if( processed[i]==0)
       {
          process=i;
          for(j=0;j<r;j++)
          {
             if(avail[j]<required[i][j])
             {
               process=-1;
               break;
             }
          }
       }
       if(process !=-1)
        break;
     }
     if(process!=-1)
     {
       safeorder[count]=process+1;
       count++;
       for(j=0;j<r;j++)
       {
            avail[j] += res_allo[process][j];
            res_allo[process][j]=0;
            max_need[process][j]=0;
            processed[process]=1;
       }  
     }
  }
  while(count != p && process!= -1);
  
  if(count==p)
  {
       cout<<"The system is in safe sequence!!!";
       cout<<s"afe sequence is : <";
       for(i=0;i<p;i++)
       {
          cout<<safeorder[i];
          cout<<">";
       }
  }
  else
          cout<<("System is in the safe state::::::::::");
 
}
