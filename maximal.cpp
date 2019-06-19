#include <iostream>
#include<fstream>
#include<new>
using namespace std;



int flag=0;
struct Points{
 	int x;
	int y;
	int z;

};
 int out[100000];
 int size=0;


int mergesort(Points point[], int low, int high);
int merge (Points point[], int low , int mid , int high);


struct node{
  int i;
	int x;
	int y;
	int z;
	struct node* next;
};
struct node* head=NULL;


struct node* addnode(struct node* N,int i,int x, int y, int z){
      struct node* newnode=new node;
      struct node* tmp=N;
      struct node* p=N;
      newnode->i=i;
      newnode->x=x;
      newnode->y=y;
      newnode->z=z;
      newnode->next=NULL;
      if (N==NULL)
      {
        out[size++]=i;
        return newnode;
      }
      else
      {
        while(tmp!=NULL)
        {
        if(((newnode->x)<(tmp->x))&&((newnode->y)<(tmp->y))&&((newnode->z)<(tmp->z)))
        {
          flag=1;
          break;
        }
        p=tmp;
        tmp=tmp->next;
        }
        if(flag==0)
        {
          p->next=newnode;
          out[size++]=i;

        }
          flag=0;
          return N;
      }
    }


int main(int argc,char** argv){

	 int t,x,y,z,i;
   
    

	ifstream input;
	ofstream output;
	output.open(argv[2]);
	input.open(argv[1]);
	input >> t;
	Points point[t];
	for(i=0;i<t;i++){
		input>>x>>y>>z;
		point[i].x=x;
		point[i].y=y;
		point[i].z=z;
		}

	mergesort(point,0,t-1);



		for(i=t-1;i>=0;i--)
    {
    head=addnode(head,i,point[i].x,point[i].y,point[i].z);
    }
    output<<size<<endl;
    for(i=size-1;i>=0;i--)
    output<<out[i]<<endl;
		input.close();
		output.close();
		return 0;

}

int  mergesort(Points point[], int low , int high)
	{
		  int mid;
		if(low<high){
			mid=(low+high)/2;
 			mergesort(point,low,mid);
			mergesort(point,mid+1,high);
			merge(point,low,mid,high);
		}
		return 0;
	}



int merge(Points point[], int low, int mid, int high)
	{
		  int i,j,k,n1,n2;
		n1=mid-low+1;
		n2=high-mid;
		Points L[n1],R[n2];
		for(i=0;i<n1;i++)
		{
			L[i].x=point[low+i].x;
			L[i].y=point[low+i].y;
			L[i].z=point[low+i].z;

		}
		for(j=0;j<n2;j++)
		{
			R[j].x=point[mid+1+j].x;
			R[j].y=point[mid+1+j].y;
			R[j].z=point[mid+1+j].z;

		}
		i=0,j=0,k=low;
		while(i<n1 && j<n2)
			{
				if(L[i].x<=R[j].x)
				{
					point[k].x=L[i].x;
					point[k].y=L[i].y;
					point[k].z=L[i].z;

					i++;
				}
				else
				{
					point[k].x=R[j].x;
					point[k].y=R[j].y;
					point[k].z=R[j].z;

					j++;
				}
				k++;
			}
  		while(i<n1)
		{
					point[k].x=L[i].x;
					point[k].y=L[i].y;
					point[k].z=L[i].z;

					i++;k++;
		}
		while(j<n2)
		{
					point[k].x=R[j].x;
					point[k].y=R[j].y;
					point[k].z=R[j].z;

					j++;k++;
		}
		return 0;
	}
