#ifndef VALIDATOR_H_
#define VALIDATOR_H_

#include "exceptions.h"
#include "domain.h"

using std::string;

class Validator {
private:
	void valideazaDenumire(const string& denumire);

	void valideazaOre(int ore);

	void valideazaTip(const string& tip);

	void valideazaProfesor(const string& profesor);

public:
	void valideazaDisciplina(const Disciplina& disciplina);
};

#endif /* VALIDATOR_H_ */
