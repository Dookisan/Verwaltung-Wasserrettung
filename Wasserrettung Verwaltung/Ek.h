#pragma once
#include "person.h"
class Ek : public person 

{
private: 
	work_state ek; 
public: 
	Ek(); 
	Ek(std::string name, int dienstzahl, work_state ws): person(name, dienstzahl), ek(ws) {}

	virtual std::string get_name()  { return vorname; }
	virtual int get_dienst() { return dienst; }
	virtual work_state get_status() { return work_state::ek; }
	void print() const {
		std::cout << "Person: " << vorname << ", Dienstzahl: " << dienst << ", WorkState: " << ws <<  std::endl;
	}
	
};

