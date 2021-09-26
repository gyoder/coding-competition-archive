#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int testCases;

    istream& in(cin);

    string case_line;
    getline(in, case_line);

    stringstream case_line_stream(case_line);
    case_line_stream  >> testCases;


    for(int testcase = 0; testcase < testCases; testcase++) {
        string text;
        getline(in, text);
        int gen=stoi(text); //number of iterations

        vector<vector<int>> current(12,vector<int>(12,0)); //0 and 12 index is for outside (dead cells) with 0 value
        vector<vector<int>> next(12,vector<int>(12,0)); //next cell grid state

        for(int i=0; i<10; i++) {
            getline(in, text);
            for (int j=0; j<10; j++) {
                if (text[j]=='1') //if 1 that cell is alive
                    current[i+1][j+1]=1;
                else
                    current[i+1][j+1]=0; //otherwise is dead
            }
        }

        for(int k=0; k<gen; k++) {
            for(int i=1; i<11; i++) { //loop over each cell
                for(int j=1; j<11; j++) {
                    int sum=0;
                    for(int ii=-1; ii<2; ii++) { //in this 2 loops we calculate sum of neighbor cells alives
                        for(int jj=-1; jj<2; jj++) {
                            if ((ii==0) && (jj==0)) continue;//skip cell self
                            sum+=current[i+ii][j+jj];
                        }
                    }
                    //logic for next generetion of cells
                    if (current[i][j]==1) { //if current cell is alive
                        switch(sum) {
                        case 0:
                        case 1:
                            next[i][j]=0;
                            break;
                        case 2:
                        case 3:
                            next[i][j]=1;
                            break;
                        default:
                            next[i][j]=0;
                            break;
                        }
                    }

                    if (current[i][j]==0) { //current cell is dead
                        if (sum==3)
                            next[i][j]=1;
                        else
                            next[i][j]=0;
                    }
                }
            }//copy next to current
            current=next;
        }
        //output to stdout current
        for(int i=1; i<11; i++) {
            for(int j=1; j<11; j++)
                cout<<current[i][j];

            cout<<endl;
        }
    }
}
