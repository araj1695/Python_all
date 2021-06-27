#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

void calc(int i,vi &v1,int siz,int s,int &tot)

{

  if(i==siz)

   {

    if(s==0)

    tot++;

    return;

   }

  calc(i+1,v1,siz,s+v1[i],tot);

  calc(i+1,v1,siz,s,tot);

}


int main()

{

   int n;

   cin>>n;

   vi v(n);

   for(int i = 0; i < n; i++)
	cin >> v[i];

   int m=0;


for(int i=0;i<n;i++)

{

if(v[i]>m)

m=v[i];

}

int count=0;

while(m)

{

count++;

m=m>>1;

}

vi v1(n,0);

for(int i=0;i<n;i++)

{

while(v[i])

{

if(v[i]&1)

v1[i]++;

v[i]=v[i]>>1;

}

}

int j=0;

for(int i=0;i<n;i++)

{

v1[j]=count-2*v1[i];

if(v1[j]==0)

continue;

else

j++;

}

int tot=0;

calc(0,v1,j,0,tot);

tot-=1;

tot=tot*(1+n-j)+(1<<(n-j))-1;

    vi bin(count,0); 

    int i=0;

    while (tot > 0) { 

  

        bin[i] = tot &1; 

        tot = tot>>1; 

    i++;

    } 

    for (int j = count - 1; j >= 0; j--) 

        cout << bin[j]; 

return 0;

}
