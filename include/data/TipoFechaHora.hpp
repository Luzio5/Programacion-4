#ifndef TIPO_FECHA_HORA_H
#define TIPO_FECHA_HORA_H

class TipoFechaHora {
    private:
        int anio;
        int mes;
        int dia;
        int hora;
        int minuto;
    public:
        TipoFechaHora(int anio, int mes, int dia, int hora, int minuto);

        int getAnio() const;
        int getMes() const;
        int getDia() const;
        int getHora() const;
        int getMinuto() const;
};

#endif
