#ifndef REPO_H_
#define REPO_H_

#include "domain.h"
#include "exceptions.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Repo {
private:
	//vectorul nostru
	vector<Disciplina> discipline;

public:

	Repo() = default;

	//nu putem lasa sa se faca copie
	Repo(const Repo& copy) = delete;

	/*
	* adaugam discipline la lista de obiecte
	* 
	* param: disciplina
	* arunca exceptii daca exista deja un obiect egal cu disciplina
	*/
	void adaugaRepo(const Disciplina& disciplina);

	void modificaRepo(const Disciplina& disciplina_noua);

	void stergeRepo(const string& denumire, const string& profesor);

	int cautaRepo(const string& denumire, const string& profesor);

	const Disciplina& get_disciplina(const string& denumire, const string& profesor);

	[[nodiscard]] const vector<Disciplina>& getAll() const noexcept;

};

#endif /* REPO_H_ */
