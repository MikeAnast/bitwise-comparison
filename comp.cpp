#include <iostream>
#include <cmath>
#include <vector>

#include <algorithm>
#include <iterator>

long long int z(int i,int j, std::vector<long> x,std::vector<long> y){
	
	if (j==1){return (x[i]^y[i]^1);}
	else {
		int l=ceil(j/2);
		return z(i+l,j-l,x,y)&z(i,l,x,y);
	}
		
}

long long int t(int i,int j,std::vector<long> x,std::vector<long> y){
 	if (j==1){
 	
 	return ((x[i]&y[i])^x[i]);
 	}
 	else {
 		int l1=ceil(j/2);
 		return (t(i+l1,j-l1,x,y)^(z(i+l1,j-l1,x,y)&t(i,l1,x,y)));
 	}
 }




void decToBinary(int n, long binaryNum[])
{

    int i = 0;
    while (n > 0) {


        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    
}


std::vector<long> minimum(std::vector<long> x,std::vector<long>  y,long int t){

	std::vector<long> flag(x.size(),0);
	
	for (int i=0;i<y.size();i++){
		
		flag[i]=((x[i]&1)^t)^(t&y[i]);
	
	}
	return flag;
}

std::vector<long> listmin(std::vector<std::vector<long> > list){
	
	std::vector<long> min;
	min=list[0]; 
	for (int i=1;i<list.size();i++){
		long int tau=0;
		tau=t(0,min.size()-1,min,list[i]);
		min=minimum(min,list[i], tau);		
	}
	return min;	
}


int main(){
	
	int m,n,q;
	std::cout << "give me three numbers"<< std::endl;
	std::cout<< "first:";
	std::cin >> n;
	std::cout<< "second:";
	std::cin >> m;
	std::cout<< "third:";
	std::cin >> q;


	int binarysizen=floor(log2(n)) + 1;
	long x[binarysizen];
	decToBinary(n,x);

	int binarysizem=floor(log2(m)) + 1;
	long y[binarysizem];
	decToBinary(m,y);


	int binarysizeq=floor(log2(q)) + 1;
	long z[binarysizeq];
	decToBinary(q,z);

	
	
	size_t x_size = sizeof(x)/sizeof(x[0]);
    std::reverse(x, x + x_size);
    size_t y_size = sizeof(y)/sizeof(y[0]);
    std::reverse(y, y + y_size);
    size_t z_size = sizeof(z)/sizeof(z[0]);
    std::reverse(z, z + z_size);
	


	std::vector<long> v(x, x + sizeof x / sizeof x[0]);
	std::vector<long> c(y, y + sizeof y / sizeof y[0]);
	std::vector<long> k(z, z + sizeof z / sizeof z[0]);




	
	std::vector<std::vector<long> > list;

	list.push_back(v);
	list.push_back(c);
	list.push_back(k);
	
	

	

	std::cout << std::endl;
	
	

	//std::cout << "the minimum of the first two is:"<< number;
	
	
	if ((binarysizen>binarysizem) && (binarysizeq>binarysizem)){
		std::cout<< "the minimum is:" << m;
		return 0;
	}
	else if ((binarysizen<binarysizem) && (binarysizen<binarysizeq)){
		std::cout << "the minimum is:" << n;
		return 0;
	}
	else if ((binarysizen>binarysizeq) && (binarysizeq<binarysizem)){
		std::cout<< "the minimum is:" << q;
		return 0;
	}
	else {

	std::vector<long> f=listmin(list);

	std::cout << std::endl;
	
	int number=0,g=0;
	for (int i=0;i< binarysizen;i++){
	 	g=pow(2,i)*f[(binarysizen-1) - i];			
		number=number+g;
	}
	std::cout << "the minimum:"<< number << std::endl;
		return 0; 
	}	
}