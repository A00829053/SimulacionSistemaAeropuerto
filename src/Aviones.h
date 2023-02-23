///Clase para nombrar y generar capacidad de los aviones
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED
class Aviones{
    public:
        Aviones();
        Aviones(std::string aerolin);
        int getCapacidad();
        void setAerolinea(std::string aerolin);
        void setCapcidad();
        void setCapcidad2(std::string avion);
        void setOpcion(char opc);
        void muestraAviones();
    private:
        std::string aerolinea, avion;
        int capacidad;
        char opcion;
};

///Establece los valores iniciales de todas las variables de la clase
///No tiene retornos o parametros

Aviones::Aviones(){
    aerolinea="-";
    capacidad=0;
    opcion='a';
}

///regresa la capacidad del avion
///No tiene parametros

int Aviones::getCapacidad(){
    return capacidad;
}

///recibe como parametro la aerolinea, y lo coloca a la variable local de la clase
///No tiene retorno

void Aviones::setAerolinea(std::string aerolin){
    aerolinea=aerolin;
}

///lee la capacidad de un avion en el archivo
///No tiene retornos o parametros

void Aviones::setCapcidad(){
    std::string espac;
    int espa;
    char esp;
    std::ifstream capAvion;
    capAvion.open("Aviones.txt");

    while (capAvion >> esp >> espac >> espac >> espac >> espac >> espa){

        if (opcion==esp){

            capacidad=espa;
        }
    }
}

///recibe como parametro el nombre del avion, y lo utiliza para obtener la capacidad
///No tiene retorno

void Aviones::setCapcidad2(std::string avion){
    std::string str1,str2,str3,str4,str;
    int espa;
    char esp;
    std::ifstream capAvion;
    capAvion.open("Aviones.txt");

    while (capAvion >> esp >> str1 >> str2 >> str3 >> str4 >> espa){

        str=str1+"-"+str2+"-"+str3;

        if (avion==str){

            capacidad=espa;
        }
    }
}

///recibe como parametro la opcion del avion, y lo coloca a la variable local de la clase
///No tiene retorno

void Aviones::setOpcion(char opc){
    opcion=opc;
}

///Muestra a los aviones de una aerolinea
///No tiene retornos o parametros

void Aviones::muestraAviones(){
    std::string avion;
    std::ifstream listAviones;
    listAviones.open("Aviones.txt");

    while (getline(listAviones,avion)){

        if (std::string::npos!=avion.find(aerolinea)){

            std::cout << avion << std::endl;
        }
    }
    listAviones.close();
}
#endif // AVIONES_H_INCLUDED
