#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

#define ARRAY_SIZE 10000

void printArray(int *arr, int n) {
  for(int i=0;i<n;i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
  return;
}

void printArrayHead(int *arr, int n) {
  for(int i=0;i<10;i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
  return;
}

void printArrayTail(int *arr, int n) {
  for(int i=n-10;i<n;i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
  return;
}

void copyArray(int * arr, int *copy, int n) {
  for(int i=0;i<n;i++) {
    copy[i]=arr[i];
  }
  return;
}

bool is_sorted(int *arr, int n) {
  for(int i=0;i<n-1;i++) {if(arr[i]>arr[i+1]) {return false;}}
  return true;
}

void diff(int *arr1, int *arr2,int n) {
  bool a=true;
  for(int i=0;i<n;i++) {
    if(arr1[i]!=arr2[i]) {
      printf("%i %i\n", arr1[i],arr2[i]);
      a=false;
    }
  }
  if(a) {printf("\narrays in same order");}
  printf("\n");
  return;
}

void diffEnds(int *arr1, int *arr2,int n) {
  for(int i=0;i<n;i++) {
    if(arr1[i]!=arr2[i]) {
      printf("%i %i\n", arr1[i],arr2[i]);
    }
    if(i==10) {i=n-10;}
  }
  printf("\n");
  return;
}

int findMax(int *arr, int n) {
  int max=arr[0];
  for(int i=0;i<n;i++) {
    if(arr[i]>max) {max=arr[i];}
  }
  return max;
}

void merge(int * arr, int b1, int b2, int e1, int e2, int n) {
  int t[n];
  int i,j,k,q;
  i=b1;
  j=b2;
  k=0;
  q=0;
  while(i<=e1 && j<=e2) {
    if(arr[j]>arr[i]) {t[k++]=arr[i++];}
    else {t[k++]=arr[j++];}
  }
  while(i<=e1) {t[k++]=arr[i++];}
  while(j<=e2) {t[k++]=arr[j++];}
  for(i=b1;i<=e2;i++) {
    arr[i]=t[q];
    q++;
  }
  return;
}

void heapify(int *arr, int p, int q) {
  int t;
  int m=q;
  int l=2*q+1;
  int r=2*(q+1);
  if(p>l && arr[l]>arr[m]) {m=l;}
  if(p>r && arr[r]>arr[m]) {m=r;}
  if(m!=q) {
    t=arr[q];
    arr[q]=arr[m];
    arr[m]=t;
    heapify(arr,p, m);
  }
}

void shuffle(int *arr, int n) {
  int a,c;
  for(int i=0;i<n;i++) {
    a=arr[i];
    c=rand()%n;
    arr[i]=arr[c];
    arr[c]=a;
  }
  return;
}

void countingSort(int *arr, int m, int n) {
  int t[n];
  int i, c[10]={0};
  for(i=0;i<n;i++) {c[(arr[i]/m)%10]++;}
  for(i=1;i<10;i++) {c[i]+=c[i-1];}
  for(i=n-1;i>=0;i--) {
    t[c[(arr[i]/m)%10]-1]=arr[i];
    c[(arr[i]/m)%10]--;
  }
  for(i=0;i<n;i++) {arr[i]=t[i];}
}

void bogoSort(int *arr, int n) {
  while(!is_sorted(arr,n)) {shuffle(arr,n);}
  return;
}

void shellSort(int *arr, int n) {
  int r,t;
  for(int g=n/2;g>0;g/=2) {
    for(int i=g;i<n;i++) {
      t=arr[i];
      for(r=i;r>=g && arr[r-g]>t;r-=g) {arr[r]=arr[r-g];}
      arr[r]=t;
    }
  }
  return;
}

void bubbleSort(int *arr, int n) {
  int t;
  for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
      if(arr[j]>arr[j+1]) {
        t=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=t;
      }
    }
  }
  return;
}

void insertionSort(int *arr, int n) {
  int j, t;
  for(int i=1;i<n;i++) {
    j=i;
    while(j>0 && arr[j-1]>arr[j]) {
      t=arr[j];
      arr[j]=arr[j-1];
      j--;
      arr[j]=t;
    }
  }
  return;
}

void selectionSort(int *arr, int n) {
  int s, j, t, q;
  for(int i=0;i<n;i++) {
    q=i;
    for(int j=i+1;j<n;j++) {
      if(arr[j]<arr[q]) {
        q=j;
      }
    }
    if(q!=i) {
      t=arr[q];
      arr[q]=arr[i];
      arr[i]=t;
    }
  }
    return;
}

void mergeSort(int *arr, int l, int n) {
  int m;
  if(l<n) {
    m=(l+n)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, n);
    merge(arr, l, m+1, m, n,n);
  }
  return;
}

void heapSort(int *arr, int n) {
  int t;
  for(int i=n/2-1;i>=0;i--) {heapify(arr, n, i);}
  for(int i=n-1;i>=0;i--) {
    t=arr[0];
    arr[0]=arr[i];
    arr[i]=t;
    heapify(arr, i, 0);
  }
  return;
}

void quickSort(int *arr, int p, int n) {
  int x,y,r,t;
  if(p<n) {
    r=p;
    x=p;
    y=n;
    while(x<y) {
      while(arr[x]<=arr[r] && x<n) {x++;}
      while(arr[y]>arr[r]) {y--;}
      if(x<y) {
        t=arr[x];
        arr[x]=arr[y];
        arr[y]=t;
      }
    }
    t=arr[r];
    arr[r]=arr[y];
    arr[y]=t;
    quickSort(arr,p,y-1);
    quickSort(arr,y+1,n);
  }
  return;
}

void radixSort(int *arr, int n) {
  int m=findMax(arr,n);
  for(int i=1;m/i>0;i*=10) {countingSort(arr,i,n);}
}

int main() {
  int arr[ARRAY_SIZE],a[ARRAY_SIZE],b[ARRAY_SIZE],
  c[ARRAY_SIZE],d[ARRAY_SIZE],f[ARRAY_SIZE],
  g[ARRAY_SIZE],h[ARRAY_SIZE],j[ARRAY_SIZE], k[ARRAY_SIZE];
  int rd, max;
  struct timeval t1,t2;
  int *mm,*p, *q, *r, *s, *u, *v, *w, *x, *y;
  mm=arr;
  p=a;
  q=b;
  r=c;
  s=d;
  u=f;
  v=g;
  w=h;
  x=j;
  y=k;
  srand(time(NULL));
  for(int i=0;i<ARRAY_SIZE;i++) {
    rd=(rand() % ARRAY_SIZE)+1;
    arr[i]=rd;
  }
  max=findMax(arr,ARRAY_SIZE);
  copyArray(mm,p,ARRAY_SIZE);
  copyArray(mm,q,ARRAY_SIZE);
  copyArray(mm,r,ARRAY_SIZE);
  copyArray(mm,s,ARRAY_SIZE);
  copyArray(mm,u,ARRAY_SIZE);
  copyArray(mm,v,ARRAY_SIZE);
  copyArray(mm,x,ARRAY_SIZE);
  copyArray(mm,y,ARRAY_SIZE);
  gettimeofday(&t1, NULL);
  shellSort(p,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\nshell sort sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  bubbleSort(q,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\nbubble sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  insertionSort(r,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\ninsertion sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  selectionSort(s,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\nselection sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  mergeSort(u,0,ARRAY_SIZE-1);
  gettimeofday(&t2, NULL);
  printf("\nmerge sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  heapSort(v,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\nheap sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  quickSort(x,0,ARRAY_SIZE-1);
  gettimeofday(&t2, NULL);
  printf("\nquick sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);
  gettimeofday(&t1, NULL);
  radixSort(y,ARRAY_SIZE);
  gettimeofday(&t2, NULL);
  printf("\nradix sort executed in %lu microsec\n", t2.tv_usec- t1.tv_usec);

  // some sorting algorithms are so fast on this array size that their execution time is occasionally displayed as 0 microseconds

  printf("\n");
  return 0;
}
