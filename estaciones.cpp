#include <iostream>
using namespace std;

struct Estacion{
    char zona;
    char temporada[6];
    int fechaInicio;
    int fechaFin;
};

Estacion vector[] = {
    {'A', "alta", 1221, 320},    // verano
    {'A', "baja", 321, 620},     // otoño
    {'A', "baja", 621, 920},     // invierno
    {'A', "media", 921, 1220},   // primavera
    {'B', "baja", 1221, 320},    // verano
    {'B', "media", 321, 620},    // otoño
    {'B', "alta", 621, 920},     // invierno
    {'B', "media", 921, 1220},   // primavera
};

Estacion EstacionDelAnio(int, char);

int main(){

    Estacion e1,e2,e3,e4;

    e1 = EstacionDelAnio(922, 'A');   // media
    e2 = EstacionDelAnio(323, 'A');   // baja
    e3 = EstacionDelAnio(622, 'B');   // alta
    e4 = EstacionDelAnio(923, 'B');   // media

    cout << "Zona: " << e1.zona << " - " << "Temporada: " << e1.temporada << endl;
    cout << "Zona: " << e2.zona << " - " << "Temporada: " << e2.temporada << endl;
    cout << "Zona: " << e3.zona << " - " << "Temporada: " << e3.temporada << endl;
    cout << "Zona: " << e4.zona << " - " << "Temporada: " << e4.temporada << endl;

    int fecha;
    char zona;

    do{
        cout << "Ingresa una fecha valida(desde 101 hasta 1231) o 0 para terminar: ";
        cin >> fecha;
        if(fecha != 0){
            cout << "Ingresa una zona (A o B):";
            cin >> zona;
            EstacionDelAnio(fecha, zona);
        }
    } while(fecha != 0);

    return 0;
}

Estacion EstacionDelAnio(int fecha, char zona){
    Estacion v;
    for(int i=0; i<8; i++){
        // Evalua los casos del verano (del 21/12 al 20/3)
        if((fecha >= 1221 || fecha <= 320) && (vector[i].fechaInicio >= 1221 || vector[i].fechaFin <= 320) && (zona == vector[i].zona)) {
            v = vector[i];
        } else if(zona == vector[i].zona && (fecha >= vector[i].fechaInicio && fecha <= vector[i].fechaFin) ){ // Resto del año (del 21/3 al 20/12)
            v = vector[i];
        }
    }

    //cout << "Zona: " << zona << " - " << "Fecha: " << fecha << " - " << "Temporada: " << v.temporada << endl;

    return v;
}