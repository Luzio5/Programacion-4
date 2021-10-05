#include <data/DataCosto.hpp>

DataCosto::DataCosto(float vitalicia, float unMes, float tresMeses, float doseMeses)
    : costoVitalicia(vitalicia)
    , costoTemporal1mes(unMes)
    , costoTemporal3mes(tresMeses)
    , costoTemporal12mes(doseMeses) {}

float DataCosto::getCostoVitalicia() const {
    return this->costoVitalicia;
}

float DataCosto::getCostoTemporal1mes() const {
    return this->costoTemporal1mes;
}

float DataCosto::getCostoTemporal3mes() const {
    return this->costoTemporal3mes;
}

float DataCosto::getCostoTemporal12mes() const {
    return this->costoTemporal12mes;
}
