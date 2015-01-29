#ifndef CHEMIN_H
#define CHEMIN_H
#include <vector>
#include <QPoint>
#include <iostream>

using namespace std;

class Chemin
{
public:
    Chemin();
    void ajouterPoint(QPoint *point, float poids);

    float getPoids();
    vector<int> getListePoints() const;
    QPoint * getPoint(int pos);
    void decalerOrigine(int decalage);

private:
    vector<int> listePoints;
    float poids;
    int origine;
};

#endif // CHEMIN_H
