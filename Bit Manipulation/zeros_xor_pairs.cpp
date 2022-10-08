long long int calculate(int a[], int n)
{
	// Sorting the list using
	// built in function
	sort(a, a + n);

	long long int count = 1;
	long long int answer = 0;

	// Traversing through the
	// elements
	for (int i = 1; i < n; i++) {
	
		if (a[i] == a[i - 1]){

			// Counting frequency of each 
			// elements
			count += 1;
			
		} 
		else
		{
			// Adding the contribution of
			// the frequency to the answer
			answer = answer + (count * (count - 1)) / 2;
			count = 1;
		}
	}

	answer = answer + (count * (count - 1)) / 2;

	return answer;
}