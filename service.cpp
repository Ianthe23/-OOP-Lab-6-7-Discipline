#include "service.h"

void Service::adaugaSrv(const string& denumire, int ore, const string& tip, const string& profesor) {
	Disciplina disciplina{ denumire, ore, tip, profesor };

	validator.valideazaDisciplina(disciplina);
	repo.adaugaRepo(disciplina);
}


void Service::modificaSrv(const string& denumire, int ore, const string& tip, const string& profesor) {
	Disciplina disciplina{ denumire, ore, tip, profesor };

	validator.valideazaDisciplina(disciplina);
	repo.modificaRepo(disciplina);
}


void Service::stergeSrv(const string& denumire, const string& profesor) {
	repo.stergeRepo(denumire, profesor);
}


const Disciplina& Service::cautaSrv(const string& denumire, const string& profesor) {
	return repo.get_disciplina(denumire, profesor);
}


const vector<Disciplina>& Service::getAll() noexcept {
	return this->repo.getAll();
}


vector<Disciplina> Service::sort(bool(*cmpKey)(const Disciplina&, const Disciplina&)) {
	vector<Disciplina> discipline{ repo.getAll() };
	for (size_t i = 0; i < discipline.size() - 1; ++i) {
		for (size_t j = i + 1; j < discipline.size(); ++j) {
			if (!cmpKey(discipline[i], discipline[j])) {
				///interschimbam
				Disciplina aux = discipline[i];
				discipline[i] = discipline[j];
				discipline[j] = aux;
			}
		}
	}
	return discipline;
}


vector<Disciplina> Service::filter(const function<bool(const Disciplina&)>& fct) {
	vector<Disciplina> rezultat;
	for (const auto& disciplina : repo.getAll()) {
		if (fct(disciplina)) {
			rezultat.push_back(disciplina);
		}
	}
	return rezultat;
}

vector<Disciplina> Service::filterOre(int ore) {
	return filter([ore](const Disciplina& disciplina) {
		return disciplina.get_ore() == ore;
	});
}

vector<Disciplina> Service::filterProfesor(const string& profesor) {
	return filter([profesor](const Disciplina& disciplina) {
		return disciplina.get_profesor() == profesor;
	});
}

vector<Disciplina> Service::sortDenumire() {
	return sort(cmpDenumire);
}

vector<Disciplina> Service::sortOre() {
	return sort(cmpOre);
}

vector<Disciplina> Service::sortProfTip() {
	return sort(cmpProfTip);
}


