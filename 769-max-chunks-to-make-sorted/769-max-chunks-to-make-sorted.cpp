class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
        int maxelement = 0, chunks = 0;

		for(int i=0;i<arr.size();i++){
			maxelement = max(maxelement, arr[i]); 
			if(i == maxelement) chunks++;
		}

		return chunks;
	}
};