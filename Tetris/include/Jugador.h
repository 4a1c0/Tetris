#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include<string>

const int MAX_LONG_NOM = 17;

using namespace std;

class Jugador
{
    public:
        Jugador();
        Jugador(char nom[], int punts);
        ~Jugador();
        int getPuntuacio();
        void printar();

    private:
        char m_nom[MAX_LONG_NOM];
        int m_puntuacio;
};

#endif // JUGADOR_H
