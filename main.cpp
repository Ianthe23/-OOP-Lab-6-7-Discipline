#include "ui.h"
#include "tests.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

#include <iostream>

/*
5. Contract de studii
Creați o aplicație care permite:
· gestiunea unei liste de discipline. Disciplina: denumire, ore pe săptămâna, tip, cadru
didactic
· adăugare, ștergere, modificare și afișare discipline
· căutare disciplina
· filtrare discipline după: nr ore, cadru didactic
· sortare discipline după: denumire, nr ore, cadru didactic + tip
*/

using namespace std;

int main() {
	Tests tests;
	tests.testAll();
	
	cout << GREEN << "Teste finalizate cu succes!\n" << RESET;
	//run();
}