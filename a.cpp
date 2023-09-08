	#include <iostream>
	#include<bits/stdc++.h>
	using namespace std;

	typedef long long ll;
	typedef vector<int> vi;
	typedef pair<int, int> pi;

	#define PB push_back
	#define MP make_pair
	#define loop(i, a, b) for(int i=a; i<=b; i++)

	class SGTree{
		vector<int> seg;
	public:
		SGTree(int n){
			seg.resize(4*n+1,0);
		}
		//This is all for sum query

		void build(vector<int> &nums,int idx,int low,int high){
        // Base case
	        if(low == high){
	            seg[idx] = nums[low];
	            return;
	        }

	        int mid = low + (high - low) / 2;
	        build(nums,2*idx+1,low,mid);
	        build(nums,2*idx+2,mid+1,high);
	        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
	    }

	    int updateseg(int idx,int low,int high,int targetIdx,int val){
	        // inside the of range
	        if(low == targetIdx && high == targetIdx){
	            return seg[idx] = val;
	        }

	        // Case 2 : if inside the range completly
	        if(low > targetIdx || high < targetIdx) return seg[idx];

	        // Case 3 : if not inside the range completly
	        int mid = low + (high - low) / 2;

	        int left = updateseg(2*idx+1,low,mid,targetIdx,val);
	        int right = updateseg(2*idx+2,mid+1,high,targetIdx,val);
	        seg[idx] = left + right;
	        return seg[idx];
	    }

	    int query(int idx,int low,int high,int l,int r){
	        // Case 1 : if inside the range completely
	        if(low >= l && high <= r){
	            return seg[idx];
	        }

	        // Out of range
	        if(low > r || high < l) return 0;

	        // Case 3 : if not inside the range completly
	        int mid = low + (high - low) / 2;

	        int left = query(2*idx+1,low,mid,l,r);
	        int right = query(2*idx+2,mid+1,high,l,r);

	        return left + right;
	    }
	};

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		// cout<<123391;
		ll t = 1;
		cin>>t;
		while(t--){
			SGTree sg(5);
			//code();
		}
		return 0;

	}