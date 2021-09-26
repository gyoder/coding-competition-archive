// Minesweeper.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	string line;
	getline(cin, line);
	int numberofpuzzles = stoi(line);
	for (int puzzlecount = 0; puzzlecount < numberofpuzzles; puzzlecount++)
	{
		getline(cin, line);
		vector<int> sizes;
		size_t pos = line.find(' ');
		sizes.push_back(stoi(line.substr(0,pos)));
		line = line.substr(pos + 1);
		pos = line.find(' ');
		sizes.push_back(stoi(line.substr(0,pos)));
		sizes.push_back(stoi(line.substr(pos + 1)));

		vector<vector<char>> puzzle (sizes[0], vector<char> ('0', sizes[1]));

		for (int mineindex = 0; mineindex < sizes[2]; mineindex++)
		{
			getline(cin, line);
			pos = line.find(' ');
			puzzle[stoi(line.substr(0,pos))][stoi(line.substr(pos))] = '*';
		}

		for (int rowindex = 0; rowindex < sizes[0]; rowindex++)
		{
			for (int colindex = 0; colindex < sizes[1]; colindex++)
			{
				if (puzzle[rowindex][colindex] != '*')
				{
					int mineneighbors = 0;
					for (int subrow = max(0,rowindex - 1); subrow < min(rowindex + 2, sizes[0]); subrow++)
					{
						for (int subcol = max(0,colindex - 1); subcol < min(colindex + 2, sizes[1]); subcol++)
						{
							if (puzzle[subrow][subcol] == '*')
							{
								mineneighbors++;
							}
						}
					}
					puzzle[rowindex][colindex] = mineneighbors + '0';
				}
				cout<<puzzle[rowindex][colindex];
			}
			cout<<endl;
		}
	}
	return 0;
}

