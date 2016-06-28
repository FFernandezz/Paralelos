#include <iostream>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

const int n=10;
const int blockSize=5;

int AA[n][n];
int BB[n][n];
int C[n][n];

void add()
{
    int number;
    int number2;
    srand (time(NULL));

    for(int i=0;i<n;++i)
        
        {
            for(int j=0;j<n;++j)
            {
                number=rand()% 20 +1;
                number2=rand()% 20 +1;
                AA[i][j]=number;
                BB[i][j]=number2;
            }
         
        } 
}

void InicializarMatrix()
{
	for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            C[i][j]=0;
}

void BlockMultiplication()
{
	InicializarMatrix();
    for(int i=0; i<n; i+=blockSize)
    	for(int j=0; j<n; j+=blockSize)
    		for(int k=0; k<n; k+=blockSize)
    			for(int x=i; x<i+blockSize; ++x)
    				for(int y=j; y<j+blockSize; ++y)
    					for(int z=k; z<k+blockSize; ++z)
    					{
    						C[x][y]+=AA[x][z]*BB[z][y];
    					}

}

void multiplicacion()
{
    InicializarMatrix();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
            {
                C[i][j]+=AA[i][k]*BB[k][j];
            }        

}


void print()
{
    int count=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            cout<<i<<" "<<j<<": "<<C[i][j]<<endl;
            ++count;

        }

    cout<<"# elementos: "<<count<<endl;
            

}


int main(){

	add();
	multiplicacion();
	print();




	return 0;
}