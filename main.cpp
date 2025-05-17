#include <iostream>
#include <complex>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
#define print(x) cout << x << endl
#define fori(n) for( int i = 0; i < n;i++)
#define forj(n) for( int j = 0; j < n;j++)
#define fore(i, left, right) for(int i = int(left); i < int(right); i++)

int length =  1000;
double scale = 2;
int maxiter  =50;

double map2xy(double i){
	double point =  i*scale/(length - 1) -  scale*(1 - i/(length - 1));
	return point;
}

complex<double> map2xy(double i, double j){
	auto z = complex(map2xy(i) , map2xy(j));
	return z;
}


double map2i(double x){
	int point = (x/scale + 1)*length/2;
	return min(point,length - 1);
}

complex<double> map2i(complex<double> z){
	return complex(map2i(z.real()), map2i(z.imag()));
}

complex<double> f(complex<double> z, complex<double> c){
	return z*z + c;
}



void make_img(vector<vector<int>>& img){
	fori(length){
		forj(length){
			int intensity = 255.999 * img[i][j]/maxiter;

			cout << intensity << " " << intensity << " " << intensity << " ";
		}
		cout <<"\n";
	}
}

int main(int argc, char* argv[]){
	auto starttime = chrono::high_resolution_clock::now();
	if (argc > 1) length = atoi(argv[1]);
	if (argc > 2) maxiter = atoi(argv[2]);



	print("P3");
	print(length << " " << length);
	print(255);


	vector<vector<int>> img(length, vector<int>(length));

	fori(length){
		clog << "\r Scanlines done " << 100*i/length << "% " << flush;
		forj(length){
			auto c = map2xy(i,j);
			auto z = complex(0.0,0.0);
			int iter = 0;
			while(abs(f(z,c)) < scale){
				iter += 1;
				if(iter > maxiter){
					img[i][j] = (0);
					break;
				}
				z = f(z,c);
				if(abs(f(z,c)) > scale){
					img[j][i] = (iter);
				}
			}
		}
	}

	
	make_img(img);

	auto endtime = chrono::high_resolution_clock::now();
	chrono::duration<double,milli> duration = endtime -starttime;
	if(duration.count()  < 2000){
		clog << "\nTime taken: " <<(duration.count()) << "ms \n";
	}
	else{
		clog << "\nTime taken: " <<(duration.count()/1000) << "s \n";
	}
	








	return 0;
}