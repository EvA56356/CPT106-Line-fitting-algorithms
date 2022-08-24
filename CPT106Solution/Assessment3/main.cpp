#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>
using namespace std;


class FileOp {
public:
	int num; // the number of point in the data.txt file
	void input();// allow users to input points from the keyboard
	void show(); // read the data from the data.txt file and show the information
	void del();// delete the point P(a,b) from the data.txt file
	void check(); // check whether some certain points are in the data.txt file
	void checkAndDel();//check whether a certain point is in the file 
					  // and delete it from the file if the point exists in the text file.
};
void FileOp::input() {

	ofstream outfile("data.txt", ios::trunc);
	cout << "The number of points that you want to put into the file: "; // ask user to input the number of point that will be input
	cin >> num;

	double x, y;
	// input the point with coordinate
	for (int i = 1; i <= num; i++) {
		cout << "Please input X of the NO." << i << " number." << endl;
		cin >> x;
		cout << "Please input Y of the NO." << i << " number." << endl;
		cin >> y;
		outfile << x << " " << y << endl;
	}

}

void FileOp::show() {
	int count = 1; // number of the point
	double x, y;
	int length = -1;
	ifstream in("data.txt", ios::in);
	char line1[10];
	while (in.eof() == false) {
		in.getline(line1, 10);
		length++;
	}

	in.close();
	fstream outfile;
	outfile.open("data.txt", ios::in);
	for (int i = 0; i < length; i++) {
		outfile >> x >> y;
		cout << "NO." << count << " point: " << x << ", " << y << endl;
		count++;
	}
	outfile.close();
}

void FileOp::del() {
	string temp1, temp2;
	string x, y;
	cout << "Please input x of the point you want to delete: ";
	cin >> x;
	cout << "Please input y of the point you want to delete: ";
	cin >> y;
	temp1 = x + " " + y;
	char line1[10];
	ifstream in("data.txt", ios::in); // orignal file
	ofstream out("temp.txt", ios::out);// temp file
	while (in.eof() == false) {
		in.getline(line1, 10);
		temp2 = line1;

		if (temp1 == temp2) {
			continue;
		}
		out << line1 << endl;

	}

	in.close();
	out.close();
	ofstream outfile("data.txt", ios::out);
	ifstream infile("temp.txt", ios::in);
	char line2[10];
	while (infile.eof() == false) {
		infile.getline(line2, 10);
		outfile << line2 << endl;
	}
	outfile.close();
	infile.close();
	system("DEL  temp.txt");// delete temp.txt file
	num--;// the number in data.txt file reduce one
	cout << "This point has been deleted." << endl;
}

void FileOp::check() {
	string temp1, temp2;
	string x, y;
	int count = 0; // count the number of loop
	cout << "Please input x of the point you want to check: ";
	cin >> x;
	cout << "Please input y of the point you want to check: ";
	cin >> y;
	temp1 = x + " " + y;


	char line1[10];
	ifstream in("data.txt", ios::in); // orignal file
	for (int i = 1; i <= num; i++) {
		in.getline(line1, 10);
		temp2 = line1; // to store each point from the file

		if (temp1 == temp2) {
			cout << "The input point is in the file." << endl;
			if (i == 1) {
				cout << "It is the first point in the file." << endl;
			}
			if (i == 2) {
				cout << "It is the second point in the file." << endl;
			}
			if (i > 2) {
				cout << "It is the " << i << "th point in the file." << endl;
			}
			break;
			goto FLAG1;
		}
		count++;

	}
	if (count == num) {
		cout << "The input point is not in the file." << endl;;
	}
FLAG1:
	int AA; // since there should be something after the FLAG, i casually add something
}

void FileOp::checkAndDel() {
	string temp1, temp2;
	string x, y;
	int count = 0; // count the number of loop
	cout << "Please input x of the point you want to check and delete: ";
	cin >> x;
	cout << "Please input y of the point you want to check and delete: ";
	cin >> y;
	temp1 = x + " " + y;
	char line1[10];
	ifstream in("data.txt", ios::in); // orignal file
	for (int i = 1; i <= num; i++) {
		in.getline(line1, 10);
		temp2 = line1; // to store each point from the file

		if (temp1 == temp2) {
			cout << "The input point is in the file." << endl;
			if (i == 1) {
				cout << "It is the first point in the file." << endl;
			}
			if (i == 2) {
				cout << "It is the second point in the file." << endl;
			}
			if (i > 2) {
				cout << "It is the " << i << "th point in the file." << endl;
			}
			break;
			goto FLAG1;
		}
		count++;

	}
	if (count == num) {
		cout << "The input point is not in the file." << endl;;
	}

FLAG1:
	in.close();
	cout << "Now it has been deleted." << endl;
	string temp3, temp4;
	temp3 = temp1;
	char line2[10];
	ifstream inn("data.txt", ios::in); // orignal file
	ofstream outt("temp.txt", ios::out);// temp file
	while (inn.eof() == false) {
		inn.getline(line2, 10);
		temp4 = line2;

		if (temp3 == temp4) {
			continue;
		}
		outt << line2 << endl;

	}

	inn.close();
	outt.close();
	ofstream outfile("data.txt", ios::out);
	ifstream infile("temp.txt", ios::in);
	char line3[10];
	while (infile.eof() == false) {
		infile.getline(line3, 10);
		outfile << line3 << endl;
	}
	outfile.close();
	infile.close();
	system("DEL  temp.txt");// delete temp.txt file
	num--;// the number in data.txt file reduce one
}




class LineFitting {
public:
	double a, b, a1, a2, b1, b2, d1, d2;// the parameters of the equation
	int length = -1;// get the number of point in the file 
	double mean = 0;// the mean of the distance
	void getPri();// caluculate the  parameters
	void showEqu();// print out the equation of the best line
	void calDis(); // calculate the distances of each point and find the distance of certain point
	void bestPoint();// show the best point in the file
	void worstPoint();// show the worst point in the file
	void getSE();// show the standard error of distance for all the points
};

void LineFitting::getPri() {
	// get the number that how many points are in the file
	ifstream in("data.txt", ios::in);
	char line1[10];
	while (in.eof() == false) {
		in.getline(line1, 10);
		length++;
	}
	in.close();

	double* x = new double[length]; // create an array to store each x of all the point
	double* y = new double[length]; // create an array to store each y of all the point

	fstream outfile;
	outfile.open("data.txt", ios::in);
	//get x and y and put them into two array
	for (int i = 0; i < length; i++) {
		outfile >> x[i] >> y[i];
	}
	//calculate a1
	double a1 = 0;
	for (int i = 0; i < length; i++) {
		a1 = a1 + x[i] * x[i];
	}
	//calculate a2
	double a2 = 0;
	for (int i = 0; i < length; i++) {
		a2 = a2 + x[i];
	}
	//calculate b1
	double b1 = 0;
	for (int i = 0; i < length; i++) {
		b1 = b1 + x[i];
	}
	//calculate b2
	double b2 = length;
	//calculate d1
	double d1 = 0;
	for (int i = 0; i < length; i++) {
		d1 = d1 + x[i] * y[i];
	}
	d1 = -d1;
	//calculate d2
	double d2 = 0;
	for (int i = 0; i < length; i++) {
		d2 = d2 + y[i];
	}
	d2 = -d2;
	a = (b1 * d2 - d1 * b2) / (a1 * b2 - b1 * a2);
	b = -(a1 * d2 - a2 * d1) / (a1 * b2 - a2 * b1);

}

void LineFitting::showEqu() {
	if (b > 0) {
		cout << "The equation of the best line is: " << a << "x - y +" << b << " = 0" << endl;
	}
	if (b < 0) {
		cout << "The equation of the best line is: " << a << "x - y " << b << " = 0" << endl;
	}
	if (b == 0) {
		cout << "The equation of the best line is: " << a << "x - y  = 0" << endl;
	}

}

void LineFitting::calDis() {
	double x, y;// the value of x,y of each point
	int tempPosi = 0;// to store the position of the point
	double* d = new double[length];// create an array to store every distance

	fstream outfile;
	outfile.open("data.txt", ios::in);
	for (int i = 0; i < length; i++) {
		outfile >> x >> y;
		d[i] = (double)abs(a * x - y + b) / sqrt(a * a + 1);
	}
	cout << "Which point do you want to show the distance from the line£¿" << endl;
	cout << "Please input the point number: ";
	cin >> tempPosi;
	if (tempPosi - 1 == 0) {
		cout << "The distance between the first point and the best fit line is: " << d[tempPosi - 1] << endl;
	}
	if (tempPosi - 1 == 1) {
		cout << "The distance between the second point and the best fit line is: " << d[tempPosi - 1] << endl;
	}
	if (tempPosi - 1 > 1) {
		cout << "The distance between the " << tempPosi << "th point and the best fit line is: " << d[tempPosi - 1] << endl;
	}
}

void LineFitting::bestPoint() {
	//get all the distance into array d
	double x, y;// the value of x,y of each point
	int tempPosi = 0;// to store the position of the point
	double* d = new double[length];// create an array to store every distance

	fstream outfile;
	outfile.open("data.txt", ios::in);
	for (int i = 0; i < length; i++) {
		outfile >> x >> y;
		d[i] = (double)abs(a * x - y + b) / sqrt(a * a + 1);
	}
	double temp = d[0];// the minimal distance
	int number = 1;// the number of best point
	 //get the minimal distance
	for (int i = 0; i < length; i++) {
		if (temp >= d[i]) {
			temp = d[i];
		}
	}
	//get the number of best point
	for (int i = 0; i < length; i++) {
		if (temp == d[i]) {
			goto FLAG1;
		}
		number++;
	}

FLAG1:
	if (number == 1) {
		cout << "The first number is the best point whose distance is: " << temp << endl;
	}
	if (number == 2) {
		cout << "The second number is the best point whose distance is: " << temp << endl;
	}
	if (number > 2) {
		cout << "The " << number << "th number is the best point whose distance is: " << temp << endl;
	}



}

void LineFitting::worstPoint() {
	//get all the distance into array d
	double x, y;// the value of x,y of each point
	int tempPosi = 0;// to store the position of the point
	double* d = new double[length];// create an array to store every distance

	fstream outfile;
	outfile.open("data.txt", ios::in);
	for (int i = 0; i < length; i++) {
		outfile >> x >> y;
		d[i] = (double)abs(a * x - y + b) / sqrt(a * a + 1);
	}

	double temp = d[0];// the maximal distance
	int number = 1;// the number of worst point
	// get the maximal distance
	for (int i = 0; i < length; i++) {
		if (temp <= d[i]) {
			temp = d[i];
		}
	}
	//get the number of worst point
	for (int i = 0; i < length; i++) {
		if (temp == d[i]) {
			goto FLAG2;
		}
		number++;
	}

FLAG2:
	if (number == 1) {
		cout << "The first number is the worst point whose distance is: " << temp << endl;
	}
	if (number == 2) {
		cout << "The second number is the worst point whose distance is: " << temp << endl;
	}
	if (number > 2) {
		cout << "The " << number << "th number is the worst point whose distance is: " << temp << endl;
	}

}

void LineFitting::getSE() {
	// get all the distance into array d
	double x, y;// the value of x,y of each point
	int tempPosi = 0;// to store the position of the point
	double* d = new double[length];// create an array to store every distance

	fstream outfile;
	outfile.open("data.txt", ios::in);
	for (int i = 0; i < length; i++) {
		outfile >> x >> y;
		d[i] = (double)abs(a * x - y + b) / sqrt(a * a + 1);
	}
	double sum = 0; // the sum of distances of all the points in the file
	double mean = 0; // the mean value of the distance

	 //get the sum
	for (int i = 0; i < length; i++) {
		sum = sum + d[i];
	}
	mean = (double)sum / length;
	double top = 0;
	for (int i = 0; i < length; i++) {
		top = top + (d[i] - mean) * (d[i] - mean);
	}

	double SE = sqrt((double)top / (length - 1));
	cout << "The standard error of distance for all the points: " << SE << endl;
}




int main() {
	// create a file and show	
	FileOp file;
	file.input();
	file.show();

	// Delete a point
	FileOp file;
	file.input();
	file.del();


	// check if a point is in the text file
	FileOp file;
	file.input();
	file.check();


	// Print out the equation of the best fit line
	FileOp file;
	file.input();
	LineFitting file2;
	file2.getPri();
	file2.showEqu();


	// Calculate the distance
	FileOp file;
	file.input();
	LineFitting file2;
	file2.getPri();
	file2.showEqu();
	file2.calDis();


	// Get the best point
	FileOp file;
	file.input();
	LineFitting file2;
	file2.getPri();
	file2.showEqu();
	file2.calDis();
	file2.bestPoint();



	// Get the worst point
	FileOp file;
	file.input();
	LineFitting file2;
	file2.getPri();
	file2.showEqu();
	file2.calDis();
	file2.worstPoint();



	// calculate the standard error
	FileOp file;
	file.input();
	LineFitting file2;
	file2.getPri();
	file2.showEqu();
	file2.getSE();



	// Input a point and delete it from the file 
	// if the point exists in the text file
	FileOp file;
	file.input();
	file.checkAndDel();







}