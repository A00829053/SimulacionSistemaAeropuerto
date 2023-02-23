///Clase para crear, eliminar, y mostrar los vuelos
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include <fstream>
#include "Aviones.h"
#include "Tiempo.h"
class Vuelo{
    public:
        Vuelo();
        Vuelo(int numVuelo);
        int getCapacidadAvion();
        std::string getAerolinea();
        std::string getAvion();
        int getHoraSal();
        int getMinSal();
        std::string getOrigen();
        std::string getDestino();
        void setNumeroVuelo(std::string numVuelo);
        void setOrigenDestino(std::string ori, std::string dest);
        void setAerolinea(std::string aerolin);
        void setOpcionAvion(char opc);
        void setCapacidadAvion();
        void setCapacidadAvion2(int cap);
        void setCapacidadAvion3();
        void setNombreAvion();
        void setValoresConNumeroVuelo();
        void boletosComprados(int boletos);
        void boletosRegresados(int boletos);
        void muestraVuelo();
        void muestraVuelosPas();
        void anadirVuelo1();
        void anadirVuelo2();
        void elimVuelo();
    private:
        std::string origen, destino, numeroVuelo, aerolinea, viaje, avion;
        int hsal, minsal, capacidadVuelo, duracion, hllegada, minllegada;
        char opcionAvion;
};

///Crea los valores iniciales, no tiene parametros o retornos

Vuelo::Vuelo(){
    numeroVuelo="-";
    origen="-";
    destino="-";
    aerolinea="-";
    avion="-";
    hsal=0;
    minsal=0;
}

///regresa la capacidad del avion, no tiene parametros

int Vuelo::getCapacidadAvion(){
    return capacidadVuelo;
}

///Regresa la aerolinea del vuelo, no tiene parametros

std::string Vuelo::getAerolinea(){
    return aerolinea;
}

///Regresa el avion utilizado, no tiene parametros

std::string Vuelo::getAvion(){
    return avion;
}

///Regresa la hora de salida, no tiene parametros

int Vuelo::getHoraSal(){
    return hsal;
}

///Regresa los minutos de la hora de salida, no tiene parametros

int Vuelo::getMinSal(){
    return minsal;
}

///Regresa el origen del vuelo, no tiene parametros

std::string Vuelo::getOrigen(){
    return origen;
}

///Regresa el destino del vuelo, no tiene parametros

std::string Vuelo::getDestino(){
    return destino;
}

///recibe como parametro el Numero de Vuelo, y lo coloca a la variable local de la clase
///No tiene retorno

void Vuelo::setNumeroVuelo(std::string numVuelo){
    numeroVuelo=numVuelo;
}

///recibe como parametro el origen y el destion, y los coloca a las variables locales de la clase
///No tiene retorno

void Vuelo::setOrigenDestino(std::string ori, std::string dest){
    origen=ori;
    destino=dest;
}

///recibe como parametro la opcion del avion seleccionado, y lo coloca a la variable local de la clase
///No tiene retorno

void Vuelo::setOpcionAvion(char opc){
    opcionAvion=opc;
}

///lee el al archivo de aviones.txt y utiliza la opcion para encontrar el nombre del avion
///No tiene retorno, ni parametros

void Vuelo::setNombreAvion(){
    std::string nom1, nom2, nom3, espac;
    int espa;
    char esp;
    std::ifstream capAvion;
    capAvion.open("Aviones.txt");

    while (capAvion >> esp >> nom1 >> nom2 >> nom3 >> espac >> espa){

        if (esp==opcionAvion){

            avion=nom1+"-"+nom2+"-"+nom3;
        }
    }
}

///Utiliza la clase aviones para obtener la capacidad del avion
///No tiene retorno ni parametros

void Vuelo::setCapacidadAvion(){
    Aviones avion;
    avion.setAerolinea(aerolinea);
    avion.setOpcion(opcionAvion);
    avion.setCapcidad();
    capacidadVuelo=avion.getCapacidad();
}

///recibe como parametro la capacidad de un vuelo, y lo coloca a la variable local de la clase
///No tiene retorno

void Vuelo::setCapacidadAvion2(int cap){
    capacidadVuelo=cap;
}

///Establece la capacidad del avion mandando el nombre del avion como parametro a la clase aviones
///No tiene retorno o parametros

void Vuelo::setCapacidadAvion3(){
    Aviones avionCap;
    avionCap.setAerolinea(aerolinea);
    avionCap.setCapcidad2(avion);
    capacidadVuelo=avionCap.getCapacidad();
}

///Establece todos los valores de un vuelo ya existente con solo el numero de vuelo
///No tiene retornos ni parametros

void Vuelo::setValoresConNumeroVuelo(){
    std::string numVuelo, ori, dest, aeli, avi;
    int hora, minu, cap, hora2, minu2;
    std::ifstream vueloComprado;
    vueloComprado.open("Vuelos.txt");

    while (vueloComprado >> numVuelo >> ori >> dest >> hora >> minu >> hora2 >> minu2  >> aeli >> avi >> cap){

        if (numVuelo==numeroVuelo){

            hsal=hora;
            minsal=minu;
            origen=ori;
            destino=dest;
            aerolinea=aeli;
            avion=avi;
            capacidadVuelo=cap;
        }
    }
}

///Recibe los boletos comprados para un vuelo, y se los resta a los boletos disponibles
///No tiene retornos o parametros

void Vuelo::boletosComprados(int boletos){
    capacidadVuelo-=boletos;
}

///Recibe los boletos regresados para un vuelo, y se los suma a los boletos disponibles
///No tiene retornos o parametros

void Vuelo::boletosRegresados(int boletos){
    capacidadVuelo+=boletos;
}

///Muestra la informacion basica del vuelo
///No tiene retornos o parametros

void Vuelo::muestraVuelo(){
    std::cout << numeroVuelo;
    std::cout << "  " << origen << "-" << destino << "  " << aerolinea;
    std::cout << " " << avion << " " << capacidadVuelo << std::endl;
}

///Anade un vuelo a la lista de vuelos
///No tiene retornos o parametros

void Vuelo::anadirVuelo1(){
    Tiempo tiem;
    std::ofstream archVuelo;
    archVuelo.open("Vuelos.txt",std::ios_base::app);
    archVuelo << numeroVuelo << " " << origen << " " << destino << " ";
    archVuelo.close();
}

///anade el resto de valores al vuelo
///No tiene retornos o parametros

void Vuelo::anadirVuelo2(){
    std::ofstream archVuelo;
    archVuelo.open("Vuelos.txt",std::ios_base::app);
    archVuelo << aerolinea << " ";
    archVuelo << avion << " " << capacidadVuelo << "\n";
    archVuelo.close();
}

///recibe como parametro la aerolinea, y lo coloca a la variable local de la clase
///No tiene retorno

void Vuelo::setAerolinea(std::string aerolin){
    aerolinea=aerolin;
}

///Elimina un vuelo basado en el numero de vuelo del objeto
///No tiene retornos o parametros

void Vuelo::elimVuelo(){
    std::string datoArch, linea;
    std::ifstream elimVuelo;
    std::ofstream anadVuelo;
    anadVuelo.open("VuelosTemp.txt");
    elimVuelo.open("Vuelos.txt");

    while(getline(elimVuelo, datoArch)){

        if (std::string::npos == datoArch.find(numeroVuelo)){

            anadVuelo << datoArch << std::endl;
        }
    }
    elimVuelo.close();
    anadVuelo.close();
    std::ifstream listaTemp;
    std::ofstream nuevaLista;
    listaTemp.open("VuelosTemp.txt");
    nuevaLista.open("Vuelos.txt");

    while (getline(listaTemp, linea)){

        nuevaLista << linea << std::endl;
    }
    listaTemp.close();
    nuevaLista.close();

}

///Muestra toda la informacion de los vuelos
///No tiene retornos o parametros

void Vuelo::muestraVuelosPas(){
    std::string datoArch, linea;
    std::ifstream muesVuelo;
    viaje=origen+" "+destino;
    muesVuelo.open("Vuelos.txt");

    while(getline(muesVuelo, datoArch)){

        if ((std::string::npos != datoArch.find(viaje)) && (std::string::npos != datoArch.find(numeroVuelo))){

           std::cout << datoArch << std::endl;
        }
    }
    muesVuelo.close();
}
#endif // VUELO_H_INCLUDED
