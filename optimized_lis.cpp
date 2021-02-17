//TC:NLOGN
//SC:N
int n;
cin>>n;
ll a[n];
loop(i,0,n)
{
    cin>>a[i];
}
vector<int> lcs;
lcs.push_back(a[0]);
loop(i,1,n)
{
    if(a[i]>lcs.back())
    {
        lcs.push_back(a[i]);
    }
    else
    {
        int ind=lower_bound(lcs.begin(),lcs.end(),a[i])-lcs.begin();
        lcs[ind]=a[i];
    }

}
cout<<lcs.size()<<endl;