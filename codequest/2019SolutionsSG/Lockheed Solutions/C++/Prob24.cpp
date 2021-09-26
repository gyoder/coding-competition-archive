// Sudoku.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	int choices[9] = {1,2,3,4,5,6,7,8,9};
	
	string line;
	getline(cin, line);
	int testcasecount = stoi(line);
	for (int i = 0; i < testcasecount; i++)
	{
		int puzzle[9][9];
		int puzzleColByRow[9][9];
		int boxes[9][9];
		vector<vector<vector<int>>> savedpuzzles;
		vector<pair<int,vector<int>>> guesschoices;
		vector<pair<vector<int*>,vector<int>>> possibilities;
		int possibilitycount = 0;
		for (int j = 0; j < 9; j++)
		{
			getline(cin, line);
			for (int k = 0; k < 9; k++)
			{
				if (line.at(k) == '_')
				{
					
					puzzle[j][k] = 0;
					puzzleColByRow[k][j] = 0;
					boxes[(j/3)*3 + k/3][k%3 + (j%3)*3] = 0;
					vector<int*> unsolvedlocs; 
					unsolvedlocs.push_back(&puzzle[j][k]);
					unsolvedlocs.push_back(puzzle[j]);
					unsolvedlocs.push_back(&puzzleColByRow[k][j]);
					unsolvedlocs.push_back(puzzleColByRow[k]);
					unsolvedlocs.push_back(&boxes[(j/3)*3 + k/3][k%3 + (j%3)*3]);
					unsolvedlocs.push_back(boxes[(j/3)*3 + k/3]);
					vector<int> choicevec (choices, choices + 9);
					pair<vector<int*>,vector<int>> possibilitypair = make_pair(unsolvedlocs,choicevec);
					possibilities.push_back(possibilitypair);
					possibilitycount++;
					
				}
				else
				{
					puzzle[j][k] = line.at(k) - '0';
					puzzleColByRow[k][j] = line.at(k) - '0';
					boxes[(j/3)*3 + k/3][k%3 + (j%3)*3] = line.at(k) - '0';
				}
				
			}
		}
		
		while (possibilities.size() > 0)
		{
			guessagain:
			
			for (int i = 0; i < possibilities.size(); i ++)
			{
				vector<int> choicevec (choices, choices + 9);
				possibilities[i].second = choicevec;
			}
			vector<int> solvedindices;
			for (int unsolvedindex = 0; unsolvedindex < possibilities.size(); unsolvedindex++)
			{
				vector<int> nonoptions;
				for (int checknum = 1; checknum < 10; checknum++)
				{						
					if(	find(possibilities[unsolvedindex].first[1],possibilities[unsolvedindex].first[1] +9, checknum) != possibilities[unsolvedindex].first[1] + 9
						|| find(possibilities[unsolvedindex].first[3],possibilities[unsolvedindex].first[3] +9, checknum) != possibilities[unsolvedindex].first[3] + 9
						|| find(possibilities[unsolvedindex].first[5],possibilities[unsolvedindex].first[5] +9, checknum) != possibilities[unsolvedindex].first[5] +9)
					{
						nonoptions.push_back(checknum);
					}
				}
				vector<int> remains;
				set_difference(
					possibilities[unsolvedindex].second.begin(), 
					possibilities[unsolvedindex].second.end(),
					nonoptions.begin(),
					nonoptions.end(),
					inserter(remains, remains.begin()));
				possibilities[unsolvedindex].second = remains;
				if (remains.size() == 0)
				{
					if (savedpuzzles.size() == 0)
					{
					}
					else
					{
						possibilities.clear();
						while(guesschoices.back().first + 1 >= guesschoices.back().second.size())
						{
							savedpuzzles.pop_back();
							guesschoices.pop_back();
						}
						vector<vector<int>> oldpuzzle (savedpuzzles.back());
						for (int j = 0; j < 9; j++)
						{
							for (int k = 0; k < 9; k++)
							{
								puzzle[j][k] = oldpuzzle[j][k];
								puzzleColByRow[k][j] = oldpuzzle[j][k];
								boxes[(j/3)*3 + k/3][k%3 + (j%3)*3] = oldpuzzle[j][k];
								if (oldpuzzle[j][k] == 0)
								{
									vector<int*> unsolvedlocs; 
									unsolvedlocs.push_back(&puzzle[j][k]);
									unsolvedlocs.push_back(puzzle[j]);
									unsolvedlocs.push_back(&puzzleColByRow[k][j]);
									unsolvedlocs.push_back(puzzleColByRow[k]);
									unsolvedlocs.push_back(&boxes[(j/3)*3 + k/3][k%3 + (j%3)*3]);
									unsolvedlocs.push_back(boxes[(j/3)*3 + k/3]);
									vector<int> choicevec (choices, choices + 9);
									pair<vector<int*>,vector<int>> possibilitypair = make_pair(unsolvedlocs,choicevec);
									possibilities.push_back(possibilitypair);
								}
							}
						}
						// next guess
						guesschoices.back().first++;
						int solution = guesschoices.back().second[guesschoices.back().first];
						*possibilities[0].first[0] = solution;
						*possibilities[0].first[2] = solution;
						*possibilities[0].first[4] = solution;
						possibilities.erase(possibilities.begin());
						goto guessagain;
					}
					
				}

				if (possibilities[unsolvedindex].second.size() == 1)
				{
					int solution = possibilities[unsolvedindex].second.at(0);
					*possibilities[unsolvedindex].first[0] = solution;
					*possibilities[unsolvedindex].first[2] = solution;
					*possibilities[unsolvedindex].first[4] = solution;
					solvedindices.push_back(unsolvedindex);
					continue;
				}

				// only works for pairs
				if (possibilities[unsolvedindex].second.size() == 2)
				{
					for(int others = 0; others < unsolvedindex; others++)
					{
						for (int groupindex = 1; groupindex < 6; groupindex += 2)
						{
							if (possibilities[others].second.size() == 2 &&
								possibilities[others].second == possibilities[unsolvedindex].second && 
								possibilities[others].first[groupindex] == possibilities[unsolvedindex].first[groupindex])
							{
								for (int extras = 0; extras < possibilities.size(); extras++)
								{
									if (extras != unsolvedindex && extras != others && 
										find(solvedindices.begin(), solvedindices.end(), extras) == solvedindices.end() &&
										possibilities[extras].first[groupindex] == possibilities[others].first[groupindex])
									{
										vector<int> diff;
										set_difference(
											possibilities[extras].second.begin(), 
											possibilities[extras].second.end(),
											possibilities[others].second.begin(),
											possibilities[others].second.end(),
											inserter(diff, diff.begin()));
										possibilities[extras].second = diff;
										if (diff.size() == 1)
										{
											int solution = diff.at(0);
											if (extras == 9 && solution == 6)
												int zzzz = 1;
											*possibilities[extras].first[0] = solution;
											*possibilities[extras].first[2] = solution;
											*possibilities[extras].first[4] = solution;
											solvedindices.push_back(extras);
										}
									}

								}
							}


						}
					}
				}
				
			}
			
			if (solvedindices.size() > 0)
			{
				sort(solvedindices.begin(), solvedindices.end());
				for (int solvedindex = solvedindices.size() - 1; solvedindex >= 0; solvedindex--)
				{

					possibilities.erase(possibilities.begin() + solvedindices[solvedindex]);
					
				}
			}
			else
			{
				vector<int> eliminated;
				for (int i = 0; i < 9; i++)
				{
					vector<int> otherindices;
					map<int,int> occurrencecount;
					for (int posindex = 0; posindex < possibilities.size(); posindex++)
					{
						if (possibilities[posindex].first[1] == puzzle[i])
						{
							otherindices.push_back(posindex);
							for (int j = 0; j < possibilities[posindex].second.size(); j++)
							{
								if (occurrencecount.find(possibilities[posindex].second[j]) != occurrencecount.end())
								{
									occurrencecount.find(possibilities[posindex].second[j]) ->second++;
								}
								else
								{
									occurrencecount.insert(pair<int,int>(possibilities[posindex].second[j],1));
								}
							}
						}
					}
					
					for (map<int,int>::iterator it = occurrencecount.begin(); it != occurrencecount.end(); ++it)
					{
						if (it -> second == 1)
						{
							for (int j = 0; j < otherindices.size(); j++)
							{
								if (find(possibilities[otherindices[j]].second.begin(), possibilities[otherindices[j]].second.end(), it -> first) != possibilities[otherindices[j]].second.end())
								{
									int solution = it -> first;
									*possibilities[otherindices[j]].first[0] = solution;
									*possibilities[otherindices[j]].first[2] = solution;
									*possibilities[otherindices[j]].first[4] = solution;
									eliminated.push_back(otherindices[j]);
								}
							}
						}
					}
				}
				if (eliminated.size() > 0)
				{
					sort(eliminated.begin(), eliminated.end());
					for (int solvedindex = eliminated.size() - 1; solvedindex >= 0; solvedindex--)
					{
						possibilities.erase(possibilities.begin() + eliminated[solvedindex]);
					}
					continue;
				}
				else
				{
					for (int i = 0; i < 9; i++)
					{
						vector<int> otherindices;
						map<int,int> occurrencecount;
						for (int posindex = 0; posindex < possibilities.size(); posindex++)
						{
							if (possibilities[posindex].first[3] == puzzleColByRow[i])
							{
								otherindices.push_back(posindex);
								for (int j = 0; j < possibilities[posindex].second.size(); j++)
								{
									if (occurrencecount.find(possibilities[posindex].second[j]) != occurrencecount.end())
									{
										occurrencecount.find(possibilities[posindex].second[j]) ->second++;
									}
									else
									{
										occurrencecount.insert(pair<int,int>(possibilities[posindex].second[j],1));
									}
								}
							}
						}
						for (map<int,int>::iterator it = occurrencecount.begin(); it != occurrencecount.end(); ++it)
						{
							if (it -> second == 1)
							{
								for (int j = 0; j < otherindices.size(); j++)
								{
									if (find(possibilities[otherindices[j]].second.begin(), possibilities[otherindices[j]].second.end(), it -> first) != possibilities[otherindices[j]].second.end())
									{
										int solution = it -> first;
										*possibilities[otherindices[j]].first[0] = solution;
										*possibilities[otherindices[j]].first[2] = solution;
										*possibilities[otherindices[j]].first[4] = solution;
										eliminated.push_back(otherindices[j]);
									}
								}
							}
						}
					}
				}
				if (eliminated.size() > 0)
				{
					sort(eliminated.begin(), eliminated.end());
					for (int solvedindex = eliminated.size() - 1; solvedindex >= 0; solvedindex--)
					{
						possibilities.erase(possibilities.begin() + eliminated[solvedindex]);
					}
					continue;
				}
				else
				{
					for (int i = 0; i < 9; i++)
					{
						vector<int> otherindices;
						map<int,int> occurrencecount;
						for (int posindex = 0; posindex < possibilities.size(); posindex++)
						{
							if (possibilities[posindex].first[5] == boxes[i])
							{
								otherindices.push_back(posindex);
								for (int j = 0; j < possibilities[posindex].second.size(); j++)
								{
									if (occurrencecount.find(possibilities[posindex].second[j]) != occurrencecount.end())
									{
										occurrencecount.find(possibilities[posindex].second[j]) ->second++;
									}
									else
									{
										occurrencecount.insert(pair<int,int>(possibilities[posindex].second[j],1));
									}
								}
							}
						}
						for (map<int,int>::iterator it = occurrencecount.begin(); it != occurrencecount.end(); ++it)
						{
							if (it -> second == 1)
							{
								for (int j = 0; j < otherindices.size(); j++)
								{
									if (find(possibilities[otherindices[j]].second.begin(), possibilities[otherindices[j]].second.end(), it -> first) != possibilities[otherindices[j]].second.end())
									{
										int solution = it -> first;
										*possibilities[otherindices[j]].first[0] = solution;
										*possibilities[otherindices[j]].first[2] = solution;
										*possibilities[otherindices[j]].first[4] = solution;
										eliminated.push_back(otherindices[j]);
									}
								}
							}
						}
					}
				}
				if (eliminated.size() > 0)
				{
					sort(eliminated.begin(), eliminated.end());
					for (int solvedindex = eliminated.size() - 1; solvedindex >= 0; solvedindex--)
					{
						possibilities.erase(possibilities.begin() + eliminated[solvedindex]);
					}
					continue;
				}
				else
				{
					// only add a guess here (always guess first possibility of index 0).  Purge guesses at big trouble
					vector<vector<int>> savedpuzzle;
					
					for (int row = 0; row < 9; row++)
					{
						vector<int> savedrow;
						for (int column = 0; column < 9; column++)
						{
							savedrow.push_back(puzzle[row][column]);
						}
						savedpuzzle.push_back(savedrow);
					}
					savedpuzzles.push_back(savedpuzzle);
					guesschoices.push_back(make_pair(0,possibilities[0].second));
					int solution = possibilities[0].second[0];
					*possibilities[0].first[0] = solution;
					*possibilities[0].first[2] = solution;
					*possibilities[0].first[4] = solution;
					possibilities.erase(possibilities.begin());
				}
			}
		}
		
		for (int row = 0; row < 9; row ++)
		{
			for (int col = 0; col < 9; col++)
			{
				cout << puzzle[row][col];
			}
			cout << endl;
		}

	}
	return 0;
}

