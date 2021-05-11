// a[i]/(t+1)  neighbour element
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        int n=a.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,a[i]);
        }
        int sz=maxi/(t+1);
        vector<int> bucket(sz+1);
        for(int i=0;i<=sz;i++)
        {
            bucket[i]=-1;
        }
        int i=0;
        int j=i+k-1;
        while(j<n)
        {
            for(int t=i;t<=j;t++)
            {
                int x=a[i]/(t+1);
                if(bucket[x]!=-1)
                {
                    return true;
                }
                else
                {
                    bucket[x]=a[i];
                }
                if(x>0)
                {
                    if(bucket[x-1]!=-1 and bucket[x-1]-bucket[x]<=t)
                    {
                        return true;
                    }
                }
                if(x<sz)
                {
                    if(bucket[x+1]!=-1 and bucket[x+1]-bucket[x]<=t)
                    {
                        return true;
                    }
                }
            }
            bucket[a[i]/(t+1)]=-1;
            i++;
            j++;
        }
        return false;
    }
};
