#pragma once
#include<iostream>
#include<string>
#include"utils.h"


class person
{
protected:
	std::string vorname;
	int dienst;
	work_state ws;

public:
	person() {};
	person(std::string name, int dienstzahl) : vorname(name), dienst(dienstzahl) {};

	virtual std::string get_name() { return vorname; }					//um zu überprüfen wann ein Object was ist 
	virtual int get_dienst() { return dienst; }
	work_state get_status() { return ws; }
	work_state change_state() ;
	virtual void print() const {
		std::cout << "Person: " << vorname << ", Dienstzahl: " << dienst << std::endl;
	}
};
