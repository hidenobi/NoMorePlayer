#include "ScoreManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager()
{
	m_Num = 5;
	readFile();
	m_currentScore = 0;
	/*for (int i = 0; i < m_Num; i++) {
		m_HighScore[i] = 0;
	}*/
	printScores();
}

void ScoreManager::setCurrentScore(int s)
{
	m_currentScore = s;
}

int ScoreManager::getCurrentScore()
{
	return m_currentScore;
}

void ScoreManager::UpdateHighScore()
{
	int s = m_currentScore;
	for (int i = 0; i < m_Num; i++) {
		if (s > m_HighScore[i]) {
			std::swap(s, m_HighScore[i]);
		}
	}
	std::sort(m_HighScore, m_HighScore + m_Num, [](int a, int b) { return a > b; });
}

int ScoreManager::getBestScore()
{
	return m_HighScore[0];
}

void ScoreManager::readFile()
{
	std::fstream input;
	input.open("Score.data", std::ios::binary | std::ios::in);
	input.read((char*)m_HighScore, sizeof(m_HighScore));
	input.close();
}

void ScoreManager::writeFile()
{
	std::fstream output;
	output.open("Score.data", std::ios::binary | std::ios::out);
	output.write((char*)m_HighScore, sizeof(m_HighScore));
	output.close();
}

int* ScoreManager::getHighScore()
{
	return m_HighScore;
}

int ScoreManager::getNum()
{
	return m_Num;
}

void ScoreManager::printScores()
{
	for (int i = 0; i < m_Num; i++) {
		printf("%d ", m_HighScore[i]);
	}
	printf("\n");
}
