#include "create.h"
#include<fstream>

std::vector<std::string> create::get_names()
{
	std::ifstream import ("E:Uni/Informatik/Projekte/members.txt"); 
	if (!import.fail()) {
		while (std::getline(import, line)) {				//lese eine Line nach der anderen ein und speicher sie in einen vector
			names.push_back(line); 
		}
		import.close(); 
	}
	else
	{
		std::cerr << "Die Datei konnte nicht geöffnet werden" << std::endl; 
		exit(-1);											//Wird auch immer als standart Rückgabe gegeben mir war grad danach :)
	}
	return names;
}														//kein Übereinstimmendes Token ist meistens ne Fehlende Klammer 


std::vector<int> create::availability()
{
	int number = 0; 

	std::srand(std::time(NULL));						//ctime gibt einen Zeiger zurück 

	for ( int j = 0; j < 20; j++)
	{
		number = std::rand() % (6);					// if rand == 0 work_state::available 
		dienstzahl.push_back(number);
	}
	return dienstzahl; 
		
}

void create::Person(int index, std::vector<person>& persons)
{																			//Vector auf zeiger welche verschiedene Objecte speichern
	names = get_names();
	dienstzahl = availability();
	persons.push_back(person(names[index], dienstzahl[index]));			//persons.push_back(new Ek(names[i], dienstzahl[i], work_state::ek));
		
}

void create::Einsatzkraft(int index, std::vector<Ek>& einsatzkraefte)
{
	names = get_names();
	dienstzahl = availability(); 
	einsatzkraefte.push_back(Ek(names[index], dienstzahl[index], work_state::ek));
}

void create::assign()
{
	for (int i = 0; i < 20; i++) {
		if (((i + 1) % 4 == 0)) {
			create::Einsatzkraft(i, einsatzkraefte);							//EK
		}
		else {
			create::Person(i, persons); 									//Person 
		}
	}
}
std::vector<person>& create::getPersons()
{
	std::sort(persons.begin(), persons.end(), [](person& a, person& b) {
		return a.get_dienst() < b.get_dienst();
		});
	return persons;
}
std::vector<Ek>& create::getEinsatzkraefte()
{
	std::sort(einsatzkraefte.begin(), einsatzkraefte.end(), [](Ek& a, Ek& b) {
		return a.get_dienst() < b.get_dienst();
		});
	return einsatzkraefte;
}
void create::makeTeams(int anzahl)
{
	int ekindex = 0;
	int personindex = 0;
	int personAdded = 0;

	assign();

	std::vector<person>& persons = getPersons();                          //Neue idee es wird ein weiterer vector genutzt, dieser weißt jeden wert ein bool true und false zu, dieser sagt ob eine person schon verwendet wurde 
	std::vector<Ek>& einsatzkraefte = getEinsatzkraefte();
	//std::vector<team> teams; 

	for (int y = 0; y < anzahl; y++) {
		team myTeam;
		personAdded = 0;
		if (!einsatzkraefte.empty()) {
			myTeam.setTeamLeader(&einsatzkraefte[y]);
			//Vector mit mehreren Teams erstellen, dann sollte beides Funktionieren
		}
		while (personindex < persons.size() && personAdded < 3) {
			if (persons[personindex].get_status() != work_state::used) {
				myTeam.addMember(&persons[personindex]);
				persons[personindex].change_state();

				personAdded++;

			}
			personindex++;
		}
		teams.push_back(myTeam); 
		 
	}
	for (int i = 0; i < teams.size(); i++) {
		std::cout << "\nTeam: " << i + 1 << "\n" << std::endl;
		teams[i].display();
	}

}
void create::printvectors() const {
	// Ausgabe der Vektoren zur Überprüfung

	std::cout << "Persons:" << std::endl;
	for (const auto& person : persons) {
		person.print();
	}

	std::cout << "Einsatzkraefte:" << std::endl;
	for (const auto& ek : einsatzkraefte) {
		ek.print();
	}
}
