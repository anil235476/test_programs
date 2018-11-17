/*
 * print number in triangle format
 * like this way
 * if given 4
 * then 
 * output should be:-
 *
 * 1
 * 2*3
 * 4*5*6
 * 7*8*9*10
 * 7*8*9*10
 * 4*5*6
 * 2*3
 * 1
 *
 * */

#include <iostream>

using namespace std;

void print_second(int val, int iter){
  if(iter ==0) return;

  auto const next_v = val - iter;
  auto start_v = next_v +1;
  for( int i =0; i<iter-1;i++){
  	cout<<start_v<<'*';
	start_v++;
  }

  cout<<start_v<<'\n';
  
  print_second(next_v , iter -1);
   
  
}


int print_first(int iter){
	if(iter == 1){
		cout<<1<<'\n';
		return 2;
	}
	else{
		auto r = print_first(iter -1);
		for(int i =0;i < iter -1;i++){
			cout<<r<<'*';
			r++;
		}

		cout<<r<<'\n';
		return r+1;

	}
}


void show_triangle(int n){
	const auto r = print_first(n);
	print_second(r-1, n);	
		

}


void show_triangle_iter(int n){
	int start_val =1;
	for( int i = 1; i <=n; i++){
		for( int j = 0; j < i-1;j++){
			cout<<start_val<<'*';
			start_val++;
		}
		cout<<start_val<<'\n';
		start_val++;

	}

	// 
	for( int i = n; i>0; i--){
	      start_val -= i;
	      auto new_start = start_val;
	      for( int j = 0; j<i -1; j++){
	      	cout<<new_start<<'*';
		new_start++;
	      }
	      cout<<new_start<<'\n';
	      new_start++;
	}

}


int main(){
	while(true){
		cout<<"enter valid number to show trianlge(valid range greater than 0\n";
		int n;
		cin>>n;
		if( n < 1) 
		{
			cout<<"exiting!!!\n";
			return 0;
		}
		//	show_triangle(n);
		show_triangle_iter(n);
	}
}
