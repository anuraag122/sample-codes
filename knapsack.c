    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;
    typedef vector <int> vi;
    typedef vector <long long> vill;
    typedef pair<int,int> ii;
    #define sc(a) scanf("%d",&a)
    #define scll(a) scanf("%I64d",&a)
    #define pf(a) printf("%d\n",a)
    #define pfll(a) printf("%I64d\n",a)
    #define all(a) a.begin(),a.end()
    #define rall(a) a.rbegin(),a.rend()
    #define pb(a) push_back(a)
    #define fore(i,a,b) for(i=a;i<=b;i++)
    #define MOD 1000000007
    int main()
    {
    int j,i,n,weight;
    cout<<"Enter no";
    cin>>n;
    cout<<"Enter max weight";
    cin>>weight;
    n++;weight++;                    //increment w and n
    vector<int> v(n),w(n);
    int a[n][weight];

    n--;weight--;
    fore(i,1,n){
        cout<<"value "<<i<<": ";
        cin>>v[i];
        cout<<"weight "<<i<<": ";
        cin>>w[i];
    }
    fore(i,0,weight){
        a[0][i]=0;
    }
    fore(i,1,n){
        fore(j,0,weight){
            if(j-w[i]<0){
                a[i][j]=a[i-1][j];
            }
            else{
                a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
            }
        }
    }
    fore(i,0,n){
        fore(j,0,weight){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    i=n;
    j=weight;
    while(i!=0){
        if(a[i][j]!=a[i-1][j]){
            cout<<i<<"-->" ;
            j=j-w[i];
        }
        i--;
    }
    return 0;
}
