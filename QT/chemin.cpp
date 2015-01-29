#include "chemin.h"

Chemin::Chemin() :
    listePoints()
{
}

void Chemin::ajouterPoint(QPoint *point, float poids)
{
    if (listePoints.size() > 0) {
        listePoints.insert(listePoints.begin(),(point->x()-origine));

    }
    else {
        listePoints.insert(listePoints.begin(),(point->x()));
        origine = point->x();
    }
    this->poids = this->poids + poids;
}

float Chemin::getPoids()
{
    return poids;
}
vector<int> Chemin::getListePoints() const
{
    return listePoints;
}

QPoint * Chemin::getPoint(int pos) {
    QPoint * res = new QPoint();
    res->setY(listePoints.size()-1-pos);
    if (pos != 0) {
        res->setX(origine + listePoints.at(listePoints.size()-1-pos));
    } else {
        res->setX(listePoints.at(listePoints.size()-1));
    }
}

void Chemin::decalerOrigine(int decalage)
{
    origine = origine + decalage;
    listePoints[listePoints.size()-1] = origine;
}
