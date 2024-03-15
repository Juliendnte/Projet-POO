#pragma once
#include <iostream>
#include <string>


class head
{
private:

	int m_dur;
	std::string m_name;

public:

	//Constructeur / Destructeur
	head();
	head(int dur, std::string name);
	head(head const& Head);
	~head();

	//Methodes
	virtual void recevoirDegat(int degat);
	virtual inline bool isAlive() { return m_dur > 0; }

	//Getteur Setteur
	inline int getDur() { return m_dur; }
	inline std::string getName() { return m_name; }

	inline void setDur(int dur) { m_dur = dur; }
	inline void setName(std::string name) { m_name = name; }


};

//Operator std::cout
std::ostream& operator<<(std::ostream& os, head& d);

