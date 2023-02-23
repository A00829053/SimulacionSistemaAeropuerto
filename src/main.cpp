///Programa general, simulador de aeropuerto para pasageros y tripulantes
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Vuelo.h"
#include "Tiempo.h"
#include "Tripulacion.h"
#include "Aviones.h"
#include "Pasageros.h"
using namespace std;

///corre el programa, pregunta si es pasagero o tripulante, pregunta que se desea
///hacer, y da opciones. Maneja todas las clases.

int main()
{
    string nombrePas, nombreTrip, numVuelo, origen, destino, vuelElim, aerolinea, numempleado;
    string apellido1Trip, apellido2Trip, posicion, numTrip, apellido1Pas, apellido2Pas;
    string avion;
    char opcion1, opcion2, SiNo, opcionAvion, cancelar;
    int hsal, minsal, duracion, cantTrip, boletos, bolDisp, bolUsados;
    int horaLlegada, minLlegada;
    cantTrip=24;
    void mostrarEmpleados(string aerolinea);
    void muestraVuelos(string aerolinea1, string aerolinea2, string aerolinea3);
    void asigEmpleado(string numVuelo, string numempleado);
    cout << "Es tripulacion o pasagero?" << endl;

    do {

        cout << "a) tripulacion b) pasagero c) terminar" << endl;
        cin >> opcion1;

        switch (opcion1) {

            case 'a': {

                cout << "cual es su nombre?" << endl;
                cin >> nombreTrip;
                cout << "Bienvenido: " << nombreTrip << endl;
                cout << "Que desea hacer?" << endl;

                do {

                    cout << "a) anadir vuelo b) eliminar vuelo";
                    cout <<" c) asignar tripulacion d) anadir tripulacion";
                    cout << " e) eliminar tripulacion \nf) informacion Vuelo";
                    cout << " g) terminar" << endl;
                    cin >> opcion2;

                    switch (opcion2) {

                        case 'a': {

                            Vuelo vuelo1;
                            Aviones avion;
                            Tiempo tiem1;
                            cout << "Numero de vuelo?" << endl;
                            cin >> numVuelo;
                            vuelo1.setNumeroVuelo(numVuelo);
                            cout << "Cual es la hora de salida? (hora, minutos)" << endl;
                            cin >> hsal >> minsal;
                            cout << "Cual es el origen del vuelo? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                            cin >> origen;
                            cout << "Y el destino? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                            cin >> destino;
                            cout << "Para cual Aerolinea? (AA, AM, UA)" << endl;
                            cin >> aerolinea;
                            vuelo1.setAerolinea(aerolinea);
                            avion.setAerolinea(aerolinea);
                            avion.muestraAviones();
                            cout << "Cual avion quiere utilizar? " << endl;
                            cin >> opcionAvion;
                            vuelo1.setOpcionAvion(opcionAvion);
                            vuelo1.setOrigenDestino(origen,destino);
                            tiem1.setHora(hsal);
                            tiem1.setMinutos(minsal);
                            tiem1.setDuracion(origen,destino);
                            tiem1.setMinutoFinal();
                            tiem1.setHoraFinal();
                            vuelo1.setCapacidadAvion();
                            vuelo1.setNombreAvion();
                            vuelo1.anadirVuelo1();
                            tiem1.anadirTiempo();
                            vuelo1.anadirVuelo2();
                            vuelo1.muestraVuelo();
                            break;
                        }

                        case 'b':{

                            Vuelo vueloe;
                            cout << "Que vuelo desea eliminar? (ingrese numero de vuelo)" << endl;
                            muestraVuelos("AA","AM","UA");
                            cin >> vuelElim;
                            vueloe.setNumeroVuelo(vuelElim);
                            vueloe.elimVuelo();
                            muestraVuelos("AA","AM","UA");
                            break;
                        }

                        case 'c':{

                            Tripulacion tripu;
                            cout << "Cual es su aerolinea? (AA, UA, AM)" << endl;
                            cin >> aerolinea;
                            mostrarEmpleados(aerolinea);
                            cout << "Que empleado desea asignar? (numEmpleado)" << endl;
                            cin >> numempleado;
                            mostrarEmpleados(numempleado);
                            muestraVuelos(aerolinea, aerolinea, aerolinea);
                            cout << "A que vuelo?" << endl;
                            cin >> numVuelo;
                            tripu.setNumeEmple(numempleado);
                            tripu.asigEmpleado(numVuelo);
                            break;
                        }

                        case 'd':{

                            Tripulacion tripmas;
                            cout << "Cual es su aerolinea? (AA, UA, AM)" << endl;
                            cin >> aerolinea;
                            cout << "Cual es su nombre completo (1 nombre + 2 apellidos)" << endl;
                            cin >> nombreTrip >> apellido1Trip >> apellido2Trip;
                            cout << "Cual es su posicion? (Piloto, Azafata)" << endl;
                            cin >> posicion;
                            cantTrip++;
                            tripmas.setAerolinea(aerolinea);
                            tripmas.setNombre(nombreTrip);
                            tripmas.setApellido1(apellido1Trip);
                            tripmas.setApellido2(apellido2Trip);
                            tripmas.setPosicion(posicion);
                            tripmas.setNumeroEmpleado(cantTrip);
                            tripmas.anadirEmpleado();
                            break;
                        }

                        case 'e':{

                            Tripulacion tripel;
                            cout << "Cual es su aerolinea? (AA, UA, AM)" << endl;
                            cin >> aerolinea;
                            mostrarEmpleados(aerolinea);
                            cout << "Que empleado desea eliminar? (numero Empleado)" << endl;
                            cin >> numTrip;
                            tripel.setNumeroTripulacion(numTrip);
                            tripel.elimTripulacion();
                            break;
                        }

                        case 'f':{

                            muestraVuelos("AA","AM","UA");
                            cout << "De que vuelo desea mas informacion?" << endl;
                            cin >> numVuelo;
                            Vuelo vuelos;
                            Vuelo vueloInicio;
                            vuelos.setNumeroVuelo(numVuelo);
                            vuelos.setValoresConNumeroVuelo();
                            aerolinea=vuelos.getAerolinea();
                            bolDisp=vuelos.getCapacidadAvion();
                            vueloInicio.setNumeroVuelo(numVuelo);
                            vueloInicio.setValoresConNumeroVuelo();
                            vueloInicio.setCapacidadAvion3();
                            boletos=vueloInicio.getCapacidadAvion();
                            bolUsados=boletos-bolDisp;
                            avion=vuelos.getAvion();
                            cout << "El vuelo utiliza el avion " << avion << endl;
                            cout << "Su capacidad es de " << boletos << " pasageros" << endl;
                            cout << "Han comprado " << bolUsados << " boletos" << endl;
                            cout << "Los tripulantes asignados son: " << endl;
                            mostrarEmpleados(numVuelo);
                            cout << "Desea ver la lista de pasageros? (s/n)" << endl;
                            cin >> SiNo;

                            if (SiNo=='s'){

                                Pasageros pasa;
                                pasa.setNumeroVuelo(numVuelo);
                                pasa.mostrarPasageros();
                            }

                        }
                    }

                }while (opcion2!='g');

                break;
            }

            case 'b':{

                cout << "ya tiene vuelo? (s/n)" << endl;
                cin >> SiNo;
                cout << "cual es su nombre completo?" << endl;
                cin >> nombrePas >> apellido1Pas >> apellido2Pas;

                if (SiNo=='s'){

                    Pasageros pasagero;
                    Vuelo vuelopas;
                    pasagero.setNombre(nombrePas,apellido1Pas,apellido2Pas);
                    numVuelo=pasagero.getNumeroVuelo();
                    vuelopas.setNumeroVuelo(numVuelo);
                    vuelopas.setValoresConNumeroVuelo();
                    cout << "Su informacion de vuelo es:" << endl;
                    vuelopas.muestraVuelo();
                    boletos=pasagero.getNumeroBoletos();
                    cout << "Y compro " << boletos << " boletos" << endl;
                    cout << "Quiere Cancelar? (s/n)" << endl;
                    cin >> cancelar;

                    if (cancelar=='s'){

                        Pasageros elimPas;
                        Vuelo elimVuelo;
                        Tiempo tiem1;
                        elimPas.setNombre(nombrePas, apellido1Pas, apellido2Pas);
                        elimPas.eliminarPasagero();
                        elimVuelo.setNumeroVuelo(numVuelo);
                        hsal=vuelopas.getHoraSal();
                        minsal=vuelopas.getMinSal();
                        origen=vuelopas.getOrigen();
                        destino=vuelopas.getDestino();
                        vuelopas.boletosRegresados(boletos);
                        vuelopas.muestraVuelo();
                        tiem1.setHora(hsal);
                        tiem1.setMinutos(minsal);
                        tiem1.setDuracion(origen,destino);
                        tiem1.setMinutoFinal();
                        tiem1.setHoraFinal();
                        elimVuelo.elimVuelo();
                        vuelopas.anadirVuelo1();
                        tiem1.anadirTiempo();
                        vuelopas.anadirVuelo2();
                    }
                }

                else {

                    cout << "Bienvenido: " << nombrePas << endl;
                    cout << "Que desea hacer?" << endl;

                    do {

                        cout << "a) Checar Vuelos b) Comprar Boletos c) Terminar" << endl;
                        cin >> opcion2;

                        switch(opcion2){

                            case 'a':{

                                Vuelo vuePas;
                                cout << "Desea buscar por ciudad destino y origen (d) o mostrar todos (t)? \n";
                                cin >> SiNo;

                                if (SiNo=='d'){

                                    cout << "Cual es la ciudad origen? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                                    cin >> origen;
                                    cout << "Cual es la ciudad destino? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                                    cin >> destino;
                                    vuePas.setOrigenDestino(origen, destino);
                                    vuePas.muestraVuelosPas();
                                }

                                else if (SiNo=='t'){

                                    muestraVuelos("AA", "AM", "UA");
                                }
                                break;
                            }

                            case 'b':{

                                Vuelo vuePas;
                                Vuelo vueloComprado;
                                Pasageros pasagero;
                                Tiempo tiem1;
                                cout << "Cual es la ciudad origen? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                                cin >> origen;
                                cout << "Cual es la ciudad destino? \nMTY, HOU, MEX, DAL, AUS?" << endl;
                                cin >> destino;
                                vuePas.setOrigenDestino(origen, destino);
                                vuePas.muestraVuelosPas();
                                cout << "Cual Vuelo quiere?" << endl;
                                cin >> numVuelo;
                                cout << "Cuantos boletos?" << endl;
                                cin >> boletos;
                                vuePas.setNumeroVuelo(numVuelo);
                                vueloComprado.setNumeroVuelo(numVuelo);
                                vueloComprado.setValoresConNumeroVuelo();
                                hsal=vueloComprado.getHoraSal();
                                minsal=vueloComprado.getMinSal();
                                origen=vueloComprado.getOrigen();
                                destino=vueloComprado.getDestino();
                                vueloComprado.boletosComprados(boletos);
                                vueloComprado.muestraVuelo();
                                vuePas.elimVuelo();
                                tiem1.setHora(hsal);
                                tiem1.setMinutos(minsal);
                                tiem1.setDuracion(origen,destino);
                                tiem1.setMinutoFinal();
                                tiem1.setHoraFinal();
                                vueloComprado.anadirVuelo1();
                                tiem1.anadirTiempo();
                                vueloComprado.anadirVuelo2();
                                pasagero.setNumeroVuelo(numVuelo);
                                pasagero.setNombre(nombrePas, apellido1Pas, apellido2Pas);
                                pasagero.setBoletos(boletos);
                                pasagero.anadirPasagero();
                                break;
                            }
                            break;
                        }

                    }while(opcion2!='c');

                }
                break;
            }
        }

    }while(opcion1!='c');

}

///Muestra los vuelos disponibles de las aerolineas
///Recibe como parametro 3 aerolineas, ya que son las maximas posibles
///Si solo se quiere mostrar vuelos de una Aerolinea utilizo la misma aerolinea 3 veces
///No tiene retorno

void muestraVuelos(string aerolinea1, string aerolinea2, string aerolinea3){
    string numVuelo, origen, destino,aerolinea, avion;
    int hsal, minsal, cap, horaLlegada, minLlegada;
    ifstream archVuelo;
    cout << "N Vuelo dest sal  lleg aero  avion       cap." << endl;
    archVuelo.open("Vuelos.txt");

    while (archVuelo>>numVuelo>>origen>>destino>>hsal>>minsal>>horaLlegada>>minLlegada>>aerolinea >> avion >> cap){

        if ((aerolinea==aerolinea1) || (aerolinea==aerolinea2) || (aerolinea==aerolinea3)){

            Vuelo vuelos;
            vuelos.setNumeroVuelo(numVuelo);
            vuelos.setOrigenDestino(origen,destino);
            vuelos.muestraVuelosPas();
        }
    }
    archVuelo.close();
}

///Muestra a los empleados de una aerolinea
///Recibe como parametro una aerolinea de la cual va a mostrar empleados
///no tiene retorno

void mostrarEmpleados(string aerolinea){
    string empleado;
    ifstream listEmpleados;
    listEmpleados.open("Tripulacion.txt");

    while (getline(listEmpleados,empleado)){

        if (string::npos!=empleado.find(aerolinea)){

            cout << empleado << endl;
        }
    }
    listEmpleados.close();
}
