#ifndef DATA_COSTO_H
#define DATA_COSTO_H

class DataCosto {
    private:
        float costoVitalicia;
        float costoTemporal1mes;
        float costoTemporal3mes;
        float costoTemporal12mes;
    public:
        DataCosto(float vitalicia, float unMes, float tresMeses, float doseMeses);

        float getCostoVitalicia() const;
        float getCostoTemporal1mes() const;
        float getCostoTemporal3mes() const;
        float getCostoTemporal12mes() const;
};

#endif
