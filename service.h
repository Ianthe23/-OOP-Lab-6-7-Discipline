#ifndef SERVICE_H_
#define SERVICE_H_

#include "repo.h"
#include "validator.h"

#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::function;

class Service {
	Repo& repo;
	Validator& validator;

	/*
	* Functie ce sorteaza lista de obiecte.
	*	 - compara 2 obiecte
	*	 - primeste o cheie dupa care sorteaza
	* returneaza: o copie a listei cu obiectele sortate
	*/
	vector<Disciplina> sort(bool(*cmpKey)(const Disciplina&, const Disciplina&));

	/*
	* Functie ce filtreaza lista de obiecte.
	*	 - primeste ca param o functie/ lambda 
	* returneaza: obiectele filtrate
	*/
	vector<Disciplina> filter(const function<bool(const Disciplina&)>& fct);

public:
	Service(Repo& repo, Validator& validator) : repo{ repo }, validator{ validator } {

	}
	
	//nu putem lasa sa se faca copie
	Service(const Service& copie) = delete;

	/*
	* Adauga o disciplina
	* Arunca exceptie daca: deja exista SAU nu este valida
	*/
	void adaugaSrv(const string& denumire, int ore, const string& tip, const string& profesor);

	/*
	* Sterge o disciplina
	* Arunca exceptie daca: disciplina nu exista
	*/
	void stergeSrv(const string& denumire, const string& profesor);

	/*
	* Modifica o disciplina
	* Arunca exceptie daca: disciplina nu exista SAU nu este valida
	*/
	void modificaSrv(const string& denumire, int ore, const string& tip, const string& profesor);

	/*
	* Cauta o disciplina dupa denumire si profesor
	* Arunca exceptie daca: disciplina nu exista
	*/
	const Disciplina& cautaSrv(const string& denumire, const string& profesor);

	const vector<Disciplina>& getAll() noexcept;

	
	/// FILTRARI

	//filtreaza dupa numarul de ore
	vector<Disciplina> filterOre(int ore);

	//filtreaza dupa numele disciplinei
	vector<Disciplina> filterProfesor(const string& profesor);


	/// SORTARI

	//sorteaza dupa denumire
	vector<Disciplina> sortDenumire();

	//sorteaza dupa ore
	vector<Disciplina> sortOre();

	//sorteaza dupa profesor si dupa tip
	vector<Disciplina> sortProfTip();

};

#endif /* SERVICE_H_ */
