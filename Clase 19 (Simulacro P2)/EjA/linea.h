#ifndef LINEA_H
#define LINEA_H


class Linea
{
public:
    Linea( int x_inicial = 0, int y_inicial = 0, int x_final = 0, int y_final = 0 );

    int getX_inicial() const;
    void setX_inicial(const int value);

    int getY_inicial() const;
    void setY_inicial(const int value);

    int getX_final() const;
    void setX_final(const int value);

    int getY_final() const;
    void setY_final(const int value);

private:
    int x_inicial, y_inicial, x_final, y_final;

};

#endif // LINEA_H
