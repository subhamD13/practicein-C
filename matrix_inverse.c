#include<stdio.h>
#include<stdlib.h>

#define N 4

int det(int [][N],int );
void getcofactor(int [][N],int [][N],int , int ,int );
void adjoint(int [][N],int [][N]);
void inverse(int [N][N],float [N][N]);

int adj[N][N];
float inv[N][N];

int main()
{
	int d,i,j;
	int mat[N][N] = {
			 {5, -2, 2, 7}, 
                    	 {1, 0, 0, 3}, 
                    	 {-3, 1, 5, 0}, 
                    	 {3, -1, -9, 4}
			};
	
	//int adj[N][N];
	//float inv[N][N];

	/*d=det(mat,N);
	if(d==0)
	{
		printf("inverse not possible\n");
		exit(0);
	}
	else
		printf("determinant : %d\n",d);
	*/
	adjoint(mat,adj); 
	inverse(mat,inv);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%f\t",inv[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}

void adjoint(int mat[][N],int adj[][N])
{
	int i,j;
	if(N==1)
	{
		adj[0][0]=1;
		return;
	}
	int sign=1,temp[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			getcofactor(mat,temp,i,j,N);
			sign=((i+j)%2==0)? 1: -1;
			adj[j][i]=(sign)*(det(temp,N-1));
		}
	}
}

void inverse(int mat[N][N],float inv[N][N])
{
	int d=det(mat,N);
	if(d==0)
	{
		printf("inverse not possible\n");
		exit(0);
	}
	else
		printf("determinant : %d\n",d);
	
	int adj[N][N];
	adjoint(mat,adj);

	for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++) 
            inv[i][j] = adj[i][j]/(float)(d); 

}

int det(int mat[][N],int n)
{
	int D=0,f;
	if(n==1)
		return mat[0][0];
	int temp[N][N];
	int sign=1;
	for(f=0;f<n;f++)
	{
		getcofactor(mat,temp,0,f,n);
		D+=sign*mat[0][f]*det(temp,n-1);
		sign=-sign;
	}
	return D;
}

void getcofactor(int mat[N][N],int temp[N][N], int p, int q, int n)
{
	int i=0,j=0,row,col;
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{	
			if(row!=p && col!=q)
			{
				temp[i][j++]=mat[row][col];
				if(j==n-1)
				{
					i++;
					j=0;
				}
			}
		}
	}
}
