#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;
 
int t[4 * N];
// this stores the sum
 
 
bool lazy[4 * N]; // tells if a certain node is storing any unpropagated update or not
 
 
 
int upd[4 * N]; // the value of the unpropagated updates
// memory of the man
 
 
 
// this is the process of telling the man to rememeber "val"
void apply(int v,int tl,int tr,int val){   // tl,tr -> node range and v is the node id
 
 
	t[v] += val * (tr - tl + 1); // set correct information at the node
 
 
 
	if(tl != tr){ // if it is not leaf, mark it lazy
		lazy[v] = 1;
		upd[v] += val;
	}
}
 
 
 
// assigning the task to his both employees 
void pushdown(int v,int tl,int tr){
	if(lazy[v]){ // if it is lazy, propagate it
		lazy[v] = 0; // not lazy anymore
 
		// he was remembering upd[v]
 
		int tm = (tl + tr) / 2;
		apply(2*v,tl,tm,upd[v]); // propagate on left child
		apply(2*v+1,tm+1,tr,upd[v]); // propagate on right child
 
 
		upd[v] = 0; // update done
		// the man doesn't remember anything anymore
	}
}
 
 
 
// l,r is the update range
// val is the update value, add this to all leaves in the range [l,r]
void update(int v,int tl,int tr,int l,int r,int val){ 
	if(tl > r || tr < l){ // no overlap
		// ignore
		return;
	}
	if(l <= tl && tr <= r){ // fully within
		// ask the man to remember it
		apply(v,tl,tr,val);
		return;
	}
	// partial overlap
	pushdown(v,tl,tr);// we remove lazy tag before going down
	// why? So that the children have correct information
 
 
 
	int tm = (tl + tr) / 2;
	update(2*v,tl,tm,l,r,val);
	update(2*v+1,tm+1,tr,l,r,val);
 
 
	t[v] = t[2*v] + t[2*v+1]; // store correct value here at this node
}
 
 
 
// pretty much unchanged except for the pushdown
int query(int v,int tl,int tr,int l,int r){
	if(tl > r || tr < l){
		return 0;
	}
	if(l <= tl && tr <= r){
		return t[v];
	}
 
 
	pushdown(v,tl,tr); // we remove lazy tag before going down
	// why? So that the children have correct information
 
 
	int tm = (tl + tr) / 2;
	int ans = 0;
	ans += query(2*v,tl,tm,l,r);
	ans += query(2*v+1,tm+1,tr,l,r);
	return ans;
}
 
// v,tl,tr -> 1, 0, Length - 1
 
int main(){
	update(1,0,N-1,2,5,3);   // add 3 to [2,5]
	cout << query(1,0,N-1,1,3); // print sum in range [1,3]
}
