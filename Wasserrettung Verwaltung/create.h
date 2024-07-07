#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include"person.h"
#include "Ek.h"
#include<algorithm>
#include"team.h"
class create
{
private: 
	std::vector<std::string> names;			//Fehler names ist keine Funktion
	std::string line; 
	std::vector<int> dienstzahl; 
	std::vector<person> persons;
	std::vector<Ek> einsatzkraefte;
	std::vector<team> teams;
	
public:
	create() {};
	std::vector<std::string> get_names();				   //Lese die Namen aus der txt Datei aus 
	std::vector<int> availability();					  //erstelle verschieden lange Vektoren mit Zufallszahlen
	void Person(int index, std::vector<person>& persons);						 //Diese sollen dann den Objekten von Typ person zugewiesen werden.
	void Einsatzkraft(int index, std::vector<Ek>&einsatzkraefte);
	void assign();
	std::vector<person>& getPersons();							//Damit auf die privaten Vektoren zugegriffen werden kann.
	std::vector<Ek>& getEinsatzkraefte();
	void makeTeams(int anzahl);
	std::vector<team>& getTeams() { return teams; };
	void printvectors() const;
};

