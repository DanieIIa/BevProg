#include "std_lib_facilities.h"


int main(){
	
	try{
		cout << "1. " << endl;
		cout << "Success!\n";

		cout << "2. " << endl;
		cout << "Success!\n";
		cout << "3. " << endl;

		cout << "Success" << "!\n";
		cout << "4. " << endl;
		cout << "success" << '\n';

		cout << "5. " << endl;
		int res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";

		cout << "6. " << endl;
		v[5] = 7;
		if(v[5] == 7) 
			cout << "Success!\n";

		cout << "7. " << endl;
		if(cout)
			cout << "Success!\n";
		else
			cout << "Fail!\n";

		cout << "8. " << endl;
		bool c = false;
		if(!c)
			cout  << "Success!\n";
		else
			cout << "Fail!\n";


		cout << "9. " << endl;
		string s = "ape";
		bool c1 = false;
		if(!c1)
			cout << "Success!\n";

		cout << "10. " << endl;
		string s1 = "fool";
		if(s1 == "fool")
			cout << "Success!\n";

		cout << "11. " << endl;
		string s2 = "ape";
		if(s2 != "fool")
			cout << "Success!\n";

		cout << "12. " << endl;
		string s3  = "ape";
		if((s3+="fool") == "apefool")
			cout << "Success!\n";

		cout << "13." << endl;
		vector<char> v2(5);
		for(int i = 0; i < v2.size(); ++i)
			cout << "Success!\n";


		cout << "14." << endl;
		vector<char> v3(5);
		for (int i = 0; i < v3.size(); ++i)
			cout << "Success!\n";			

		cout << "15." << endl;
		string s4 = "Success!\n";
		for(int i = 0; i < 6; i++){
			cout << s4;
		}

		cout << "16. " << endl;
		if(true)
			cout  << "Success!\n";
		else
			cout << "Fail!\n";

		cout << "17. " << endl;
		int x = 2000;
		int c2 = x;
		if(c2 == 2000)
			cout  << "Success!\n";

		cout << "18. " << endl;
		string s5 = "Success!\n";
		for(int i = 0; i < 10; i++){
			cout << s5[i];
		}

		cout << "19. " << endl;
		vector<int>v4(5);
		for (int i = 0; i < v4.size(); ++i){
			cout  << "Success!\n";
		}

		cout << "20. " << endl;
		int i1 = 0; 
		int j1 = 9;
		while(i1 < 10) ++i1;{
			if(j1 < i1){
				cout  << "Success!\n";
			}
			
		}	
		

		cout << "21. " << endl;
		double x1 = 2;
		double d = 5/x1+2;
		if(d == 2*x1+0.5){
			cout  << "Success!\n";
		}

		cout << "22." << endl;
		string s6 = "Success!\n";
		for (int i = 0; i < 10; ++i)
			cout << s6[i];

		cout << "23. " << endl;
		int i2 = 0;
		int j2 = 9;
		while(j2 < 10) ++j2;
		if(j2 > i2)
			cout  << "Success!\n";

		cout << "24. " << endl;
		double x2 = 4;
		double d2 = 5/(x2-2)+2;
		if(d2 == x2+0.5)
			cout << "Success! \n";
		cout << "25. " << endl;
		cout << "Success! \n";
		keep_window_open();
		return 0;


	}
	catch(exception& e){
		cerr << "error: " << e.what() << endl;
		keep_window_open();
		return 1;

	}catch(...){
		cerr << "Oops: unknow exception!s "<< endl;
		keep_window_open();
		return 2;
	}

	return 0;
}