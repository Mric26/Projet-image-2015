#include "listechemins.h"

ListeChemins::ListeChemins() :
    listeChemins()
{
}

void ListeChemins::ajouterChemin(Chemin *c)
{
    int i = 0;
    if (listeChemins.size() > 0) {
        while (i < listeChemins.size() && listeChemins[i]->getPoids() <= c->getPoids()) {
            ++i;
        }
    }


    vector<Chemin*>::iterator it = listeChemins.begin() + i;

    listeChemins.insert(it,c);
}
vector<Chemin *> ListeChemins::getListeChemins() const
{
    return listeChemins;
}


