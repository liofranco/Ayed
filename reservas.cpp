#include <iostream>
using namespace std;

struct Fecha{
    int mes;
    int dia;
};

struct Reserva{
    char zona;
    Fecha fecha;
    int reservas;
};

int main(){

    Reserva r, a, b;
    FILE* f = fopen("reservas", "rb");
    
    // LEER TODOS LOS REGISTROS
    cout << "Listado de todos los registros" << endl;
    int i = 0;
    fread(&r, sizeof(Reserva), 1, f);
    while(!feof(f)){
        cout << i+1 << ": " << r.zona << "  " << r.fecha.mes << "  " << r.fecha.dia << "  " << r.reservas << endl;
        i++;
        fread(&r, sizeof(Reserva), 1, f);
    }
    cout << "-------------------------------" << endl;

    fseek(f, 0, SEEK_SET); //  VOLVER PUNTERO AL INICIO 
   

    // TEMPORADA ALTA ZONA ATLANTICA (DESDE EL REGISTRO 350 HASTA 359 Y DESDE EL REGISTRO 0 HASTA EL 79)
    cout<< "Temporada alta zona atlantica (21/12 hasta 20/3)" << endl;
    fseek(f, 350*sizeof(Reserva), SEEK_SET); //  PONER PUNTERO AL INICIO DEL VERANO DE LOS REGISTROS DE LA ZONA A 

    //LEER DESDE REGISTRO 350 HASTA 359
    for(int i = 0; i < 10; i++){
        fread(&a, sizeof(Reserva), 1, f);
        cout << a.zona << "  " << a.fecha.mes << "  " << a.fecha.dia << "  " << a.reservas << endl;
    }

    fseek(f, 0, SEEK_SET); //  VOLVER PUNTERO AL INICIO

    //LEER DESDE REGISTRO 0 HASTA 79
    for(int i = 0; i < 80; i++){
        fread(&a, sizeof(Reserva), 1, f);
        cout << a.zona << "  " << a.fecha.mes << "  " << a.fecha.dia << "  " << a.reservas << endl;
    }
    cout << "-------------------------------" << endl;



    // TEMPORADA BAJA ZONA MONTAÑA (DESDE EL REGISTRO 710 HASTA 719 Y DESDE EL REGISTRO 360 HASTA EL 439)
    cout<< "Temporada baja zona montaña (21/12 hasta 20/3)" << endl;
    fseek(f, 710*sizeof(Reserva), SEEK_SET); //  PONER PUNTERO AL INICIO DEL VERANO DE LOS REGISTROS DE LA ZONA B

    //LEER DESDE REGISTRO 710 HASTA 719
    for(int i = 0; i < 10; i++){
        fread(&b, sizeof(Reserva), 1, f);
        cout << b.zona << "  " << b.fecha.mes << "  " << b.fecha.dia << "  " << b.reservas << endl;
    }

    fseek(f, 360*sizeof(Reserva), SEEK_SET); //  PONER PUNTERO AL INICIO DE LOS REGISTROS DE LA ZONA B

    //LEER DESDE REGISTRO 360 HASTA 439
    for(int i = 0; i < 80; i++){
        fread(&b, sizeof(Reserva), 1, f);
        cout << b.zona << "  " << b.fecha.mes << "  " << b.fecha.dia << "  " << b.reservas << endl;
    }
    
    fclose(f);

    return 0;
}