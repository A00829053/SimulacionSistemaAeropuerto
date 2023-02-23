///Clase que maneja horas de salidas, duraciones, y horas de llegadas
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED
#include <cmath>
class Tiempo{
    public:
        Tiempo();
        Tiempo(int h, int m);
        int getHora();
        int getMinutos();
        int getDuracion();
        void setHora(int h);
        void setMinutos(int m);
        void setDuracion(std::string origen, std::string destino);
        void anadirTiempo();
        void setHoraFinal();
        void setMinutoFinal();
    private:
        int hora, minuto, duracion, horaFin, minutoFin;
};

///Establece los valores iniciales de todas las variables de la clase
///No tiene retornos o parametros

Tiempo::Tiempo(){
    hora=0;
    minuto=0;
    duracion=0;
    horaFin=0;
    minutoFin=0;
}

///recibe como parametro la hora y los minutos, y lo coloca a la variable local de la clase
///No tiene retorno

Tiempo::Tiempo(int h, int m){
    hora=h;
    minuto=m;
}

///Regresa el valor de la hora de salida, que se encuentra en la variable local
///No tiene parametros

int Tiempo::getHora(){
    return hora;
}

///Regresa el valor del minuto de salida que se encuentra en la variable local
///No tiene parametros

int Tiempo::getMinutos(){
    return minuto;
}

///Regresa el valor de la duracion del vuelo, que se encuentra en la variable local
///No tiene parametros

int Tiempo::getDuracion(){
    return duracion;
}

///recibe como parametro la hora de salida, y lo coloca a la variable local de la clase
///No tiene retorno

void Tiempo::setHora(int h){
    hora=h;
}

///recibe como parametro el minuto de salida, y lo coloca a la variable local de la clase
///No tiene retorno

void Tiempo::setMinutos(int m){
    minuto=m;
}

///recibe como parametro el origen y destino y lo utiliza para obtener la duracion
///del archivo Duraciones.txt
///No tiene retorno

void Tiempo::setDuracion(std::string origen, std::string destino){
    std::string str, viaje;
    int durac;
    str=origen+"-"+destino;
    std::ifstream dura;
    dura.open("Duraciones.txt");

    while (dura >> viaje >> durac){

        if (viaje==str){

            duracion=durac;
        }
    }
}

///Anade un tiempo al archivo donde se encuentran los vuelos
///No tiene parametros o retorno

void Tiempo::anadirTiempo(){
    std::ofstream archVuelo;
    archVuelo.open("Vuelos.txt",std::ios_base::app);
    archVuelo << hora << " " << minuto << " ";
    archVuelo << horaFin << " " << minutoFin << " ";
    archVuelo.close();
}

///Utiliza la duracion para encontra la hora final
///No tiene parametros o retorno

void Tiempo::setHoraFinal(){
    horaFin+=hora+duracion/60;

    if (horaFin>=24){

        horaFin-=24;
    }
}

///Utiliza la duracion para encontra la hora final
///No tiene parametros o retorno

void Tiempo::setMinutoFinal(){
    minutoFin=minuto+duracion%60;

    while (minutoFin>=60){

        minutoFin=minutoFin%60;
        horaFin+=1;
    }
}
#endif // TIEMPO_H_INCLUDED
