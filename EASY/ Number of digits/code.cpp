int countDigits(int n){
	// Write your code here.
	int cnt = 0;
	while(n>0){
		int l = n % 10;
		cnt += 1;
		n = n/10;
	}	
	return cnt;
}
