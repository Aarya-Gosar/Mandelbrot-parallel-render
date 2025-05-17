#include <iostream>
#include <complex>
#include <vector>

using namespace std;
#define print(x) cout << x << endl
#define fori(n) for( int i = 0; i < n;i++)
#define forj(n) for( int j = 0; j < n;j++)
#define fore(i, left, right) for(int i = int(left); i < int(right); i++)

#define length  4000
#define scale  2
#define maxiter 100

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

int main(){


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







	return 0;
}