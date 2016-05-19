#ifndef NODEJUGADOR_H
#define NODEJUGADOR_H


class NodeJugador
{
    public:
        NodeJugador();
        ~NodeJugador();
        NodeJugador* getNext(void) const;
        void setNext(NodeJugador*);
        int getValor(void) const;
        void setValor(int);



    private:

    NodeJugador* m_next;
	int m_valor;
};

#endif // NODEJUGADOR_H
