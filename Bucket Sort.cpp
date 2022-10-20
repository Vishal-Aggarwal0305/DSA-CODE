

#include <bits/stdc++.h>
using namespace std;

struct node{
    float info;
    struct node* list;
};


void printall(struct node *listedlist)
{
	struct node *cur = listedlist;
	while(cur) {
		cout << cur->info << ",";
		cur = cur->list;
	}
}

/* Insertion Sort */
struct node *insertion(struct node *list)
{	
	struct node *k,*nodeList;
	/* need at least two items to sort */
	if(list == 0 || list->list == 0) { 
		return list; 
	}
	
	nodeList = list; 
	k = list->list; 
	nodeList->list = 0; /* 1st node is new list */

	while(k != 0) {	
		struct node *ptr;
		/* check if insert before first */
		if(nodeList->info > k->info)  { 
			struct node *tmp;
			tmp = k;  
			k = k->list; 
			tmp->list = nodeList;
			nodeList = tmp; 
			continue;
		}

		for(ptr = nodeList; ptr->list != 0; ptr = ptr->list) {
			if(ptr->list->info > k->info) break;
		}

		if(ptr->list!=0){  
			struct node *tmp;
			tmp = k;  
			k = k->list; 
			tmp->list = ptr->list;
			ptr->list = tmp; 
			continue;
		}
		else{
			ptr->list = k;  
			k = k->list;  
			ptr->list->list = 0; 
			continue;
		}
	}
	return nodeList;
}

void Printarray(float A[], int n)
{

    for(int i=0;i<n;i++)
    {
       cout << A[i] << " -> "; 
    }
}


void Bucketsort(float A[] , int n)
{
    int i,j;
	struct node **B;  

	B = (struct node **)malloc(sizeof(struct node*) * 10);

    /* initialize array of pointers */
	for(i = 0; i < n;++i) 
    {  
		B [i] = NULL;  
	}

    for(i = 0; i < n; ++i) 
    {	
		struct node *temp;
		int pos = floor(A[i]*n);
		temp = (struct node *) malloc(sizeof(struct node));
		temp->info = A[i]; 
		temp->list = B[pos];  
		B[pos] = temp;



	}
        for(i = 0; i < n; i++) 
    {
	cout << "Bucket(" << i << ") : ";
	printall(B[i]);
	cout << endl;
	}

    for(i = 0; i < n; ++i) 
    {                        
		B[i] = insertion(B[i]); 
	}


	for(i = 0; i < n; i++) {
		cout << "Bucket(" << i << ") : ";
	        printall(B[i]);
		cout << endl;
	}

    j=0;
    for(int i=0; i<n;i++)  
    {
        struct node * list;
        list = B[i];
        

        while(list)
        {
            A[j++]= list-> info;
            list = list->list;
        //    cout << "here";
        }
    }
}


int main()
{

     int n,i;
     
     cout << "\tEnter the value on n : ";
     cin >> n;

     float A[n];
     cout << "\n";
    
    for(i=0;i<n;i++)
    {
        cout << "Enter "<< i+1 << "th element : ";
        cin >> A[i];
    }


    Bucketsort(A,n);

    Printarray(A,n);
    return 0;
}

