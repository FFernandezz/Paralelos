
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

const int n=1000;

int AA[n][n];
int BB[n][n];
int C[n][n];
void add()
{
    int number;
    srand (time(NULL));

    for(int i=0;i<n;++i)
        
        {
            for(int j=0;j<n;++j)
            {
                number=rand()% 30 +1;
                AA[i][j]=number;
                BB[i][j]=number+3;
            }
         
        }
  
}

void multiplicacion()
{
    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            C[i][j]=0;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
            {
                C[i][j]+=AA[i][k]*BB[k][j];
            }
    
    cout<<"Finalizo"<<endl;        

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

void print()
{
    int count=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            cout<<C[i][j]<<endl;
            ++count;

        }

    cout<<"# elementos: "<<count<<endl;
            

}

int main (){

    //multiplicacion(A,B);
    //add();
    //multiplicacion();
    //print();

    return 0;
}