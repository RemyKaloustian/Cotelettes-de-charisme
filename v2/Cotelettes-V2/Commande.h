#pragma once

class Invocateur;
#include <string>
#include <map>
#include <stack>

class Commande
{
public:
    Commande();
    Commande(std::string);
    virtual ~Commande();
    virtual void executer() = 0;
    virtual void annuler() = 0;
    virtual Commande* constructeurVirtuel(Invocateur&)=0;

    static std::stack<Commande*> pileActions;
    static std::map<std::string, Commande*>& commandesInscrites();
    static Commande* nouvelleCommande(std::string, Invocateur&);
};

