#pragma once
#include "../GameManager/Singleton.h"

class ScoreManager :public CSingleton<ScoreManager> {
public:
	ScoreManager();
	void setCurrentScore(int s);
	int getCurrentScore();

	void UpdateHighScore();

	int getBestScore();

	void readFile();
	void writeFile();

	int* getHighScore();
	int getNum();

	void printScores();
private:
	int m_currentScore;
	int m_HighScore[5];
	int m_Num;
};