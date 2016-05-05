#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador
{
    public:
        Jugador();
        Jugador(char nom[], int punts);
        ~Jugaador();
        int getPuntuacio();
        void printar();
    private:
        char m_nom[17];
        int m_puntuacio;
};


#endif // JUGADOR_H_INCLUDED
