#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Creep {
public:
	Creep();
	~Creep();
	virtual void Init(float x, float y);
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(sf::Vector2f point) { m_startPoint = point; }

	void Reset();
	bool isStop() { return m_stop; }
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation1* m_currentAni;
	Animation1* m_runAni;

	bool m_stop;
	bool m_soundDeadisPlay;
};