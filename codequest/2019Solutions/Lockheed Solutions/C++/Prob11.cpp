#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void get_bits(string cur, int n){
    if (n==0) {
        cout<<cur<<endl;
        return;
    }
    get_bits(cur+"0",n-1); //run recusively
    get_bits(cur+"1",n-1);
}

int main()
{
	int testCases;

	istream& in(cin);

	string case_line;
	getline(in, case_line);

    stringstream case_line_stream(case_line);
	case_line_stream  >> testCases;

	for(int testcase = 0; testcase < testCases; testcase++){
		string text;
		getline(in, text);
		long bits = stol(text);
		get_bits("",bits);
	}
}
