#include "std_lib_facilities.h"
	
struct Point{
	double x, y;
};
int main(){

	try{
	vector<Point> original_points;
	cout << "Please enter 7 x,y pairs" << endl;
	double x,y;
	while(original_points.size() != 7){
		cin >> x >> y;
		original_points.push_back(Point{x,y});
	}
	for(int i = 0; i < original_points.size(); i++){
		cout << "(" << original_points[i].x << ", " << original_points[i].y << ")" << endl;
	}
	
	string output_file_name = "mydata.txt";
	ofstream ofn {output_file_name};

	for(int i = 0; i < original_points.size(); i++){
		ofn << original_points[i].x  << " " << original_points[i].y  <<  endl;

	}
	ofn.close();
	
	vector<Point> produced_points;
	ifstream inp {"mydata.txt"};
	if(!inp) error("can't open input file ");
	else{
		
		double x,y;
		while(inp>>x>>y) 
		{
			produced_points.push_back(Point{x,y});
		}
	}
	inp.close();
	cout << original_points.size() << " " << produced_points.size() << endl;

	if(original_points.size() != produced_points.size()){
		cout << "Something's wrong! the number of elements differ." << endl;
	}
	for(int i = 0; i < original_points.size(); i++){
		cout << "(" << produced_points[i].x << ", " << produced_points[i].y << ")" << '\t' << "(" << original_points[i].x << ", " << original_points[i].y << ")" << endl;
		if(original_points[i].x != produced_points[i].x && original_points[i].y != produced_points[i].y){
			cout << "Something's wrong! the values of elements differ.";
			break;
		}
	}
	
	return 0;
}
catch(exception& e)
{
    cerr <<e.what()<<"\n";
    return 1;
}
catch (...) {
    cerr << "Something terrible happened!\n";
    return 2;
}
}