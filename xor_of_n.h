// This function return XOR of first n natural numbers
long long XOR(long long n){
	long long x = n%4;
	if(x==0) return n;
	else if(x==1) return 1;
	else if(x==2) return n+1;
	else return 0;
}
