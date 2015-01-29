#ifndef LISTECHEMINS_H
#define LISTECHEMINS_H
#include <vector>
#include "chemin.h"

using namespace std;

class ListeChemins
{
public:
    ListeChemins();
    void ajouterChemin(Chemin *c);
    vector<Chemin *> getListeChemins() const;

private:
    vector<Chemin*> listeChemins;
};

#endif // LISTECHEMINS_H
