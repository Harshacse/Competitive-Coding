#include<stdio.h>
#include<limits.h>

void insert_min(int heap[],int element,int size)
{
  size++;
  heap[size] = element; 
  int now = size;
  while(heap[now/2] > element && now>1) 
  {
          heap[now] = heap[now/2];
          now /= 2;
  }
        heap[now] = element;
}

void insert_max(int heap[],int element,int size)
{
  size++;
  heap[size] = element; 
  int now = size;
  while(heap[now/2] < element && now>1) 
  {
          heap[now] = heap[now/2];
          now /= 2;
  }
  heap[now] = element;
}

int delete_max(int heap[],int size)
{
  int return_value = heap[1],greater,smaller,temp1,temp;
  heap[1] = heap[size];
  size--;
  temp = 1;
  while(1)
  {
    if(2*temp+1>size)
    {
      if(2*temp>size)
        break;
      if(heap[temp]<heap[2*temp])
      {
        temp1 = heap[temp];
        heap[temp] = heap[2*temp];
        heap[2*temp] = temp1;
        break;
      }
      else
        break;
    }
    greater = temp;
    if(heap[temp]<heap[2*temp])
      greater = 2*temp;
    if(heap[greater]<heap[2*temp+1])
      greater = 2*temp+1;
    if(greater!=temp)
    {
      temp1 = heap[temp];
      heap[temp] = heap[greater];
      heap[greater] = temp1;
      temp = greater;
    }
    else
      break;
  }
  return return_value;
}

void printheap(int heap[],int size)
{ 
  int i;
  for(i=1;i<=size;i++)
    printf("%d ",heap[i]);
  printf("\n");
}
int delete_min(int heap[],int size)
{
  int return_value = heap[1],greater,temp1,temp;
  heap[1] = heap[size];
  size--;
  temp = 1;
  while(1)
  {
    if(2*temp+1>size)
    {
      if(2*temp>size)
        break;
      if(heap[temp]>heap[2*temp])
      {
        temp1 = heap[temp];
        heap[temp] = heap[2*temp];
        heap[2*temp] = temp1;
        break;
      }
      else
        break;
    }
    greater = temp;
    if(heap[temp]>heap[2*temp])
      greater = 2*temp;
    if(heap[greater]>heap[2*temp+1])
      greater = 2*temp+1;
    if(greater!=temp)
    {
      temp1 = heap[temp];
      heap[temp] = heap[greater];
      heap[greater] = temp1;
      temp = greater;
    }
    else
      break;
  }
  return return_value;
}

int main()
{
  int n,i,temp,temp1;
  float median;
  scanf("%d",&n);
  int max[n],min[n],max_size=1,min_size=1;
  scanf("%d",&temp);
  median = (float)temp;
  printf("%.2f ",median);
  scanf("%d",&temp1);
  median = (float)(temp+temp1)/2.0;
  printf("%.2f ",median);
  if(temp>temp1)
  {
    max[1] = temp1;
    min[1] = temp;
  }
  else
  {
    max[1] = temp;
    min[1] = temp1;
  }
  for(i=3;i<=n;i++)
  {
    scanf("%d",&temp);
    if(max[1]>temp)
    {
      insert_max(max,temp,max_size);
      max_size++;
    }
    else
    {
      insert_min(min,temp,min_size);
      min_size++;
    }
    // printf("check\n");
    //printheap(max,max_size);
    //printheap(min,min_size);
    if(max_size - min_size>=2)
    {
      temp1 = delete_max(max,max_size);
      max_size--;
      insert_min(min,temp1,min_size);
      min_size++;
    }
    else if(min_size - max_size>=2)
    {
      //printf("check1\n");
      temp1 = delete_min(min,min_size);
      //printf("check2\n");
      min_size--;
      insert_max(max,temp1,max_size);
      max_size++;
    }
    if(i%2==1)
    {
      if(max_size>min_size)
        median = (float)max[1];
      else
        median = (float)min[1];
    }
    else
    {
      median = (float)(max[1]+min[1])/2.0;
    }
    printf("%.2f ",median);
  }
}




