///Clase para anadir, asignar y eliminar tripulacion
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#ifndef TRIPULACION_H_INCLUDED
#define TRIPULACION_H_INCLUDED
#include <fstream>
class Tripulacion{
    public:
        Tripulacion();
        Tripulacion(std::string numEmple);
        void setNumeEmple(std::string numEmple);
        void setNumeroEmpleado(int numEmple);
        void setNumeroTripulacion(std::string numEmple);
        void setNombre(std::string nom);
        void setApellido1(std::string ape1);
        void setApellido2(std::string ape2);
        void setAerolinea(std::string aerolin);
        void setPosicion(std::string pos);
        void asigEmpleado(std::string numVuelo);
        void muestraEmpleado();
        void anadirEmpleado();
        void elimTripulacion();
    private:
        std::string posicion, nombre, apellido1, apellido2, aerolinea, numeroTripulacion, numeEmple;
        int numeroEmpleado;
};

///Establece los valores iniciales de todas las variables de la clase
///No tiene retornos o parametros

Tripulacion::Tripulacion(){
    numeroEmpleado=0;
    numeroTripulacion="-";
    nombre="-";
    apellido1="-";
    apellido2="-";
    aerolinea="-";
    posicion="-";
    numeEmple="-";
}

///recibe como parametro el Numero de empleado en formato string, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setNumeEmple(std::string numEmple){
    numeEmple=numEmple;
}

///recibe como parametro el Numero de empleado, en formato int, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setNumeroEmpleado(int numEmple){
    numeroEmpleado=numEmple;
}

///recibe como parametro el Numero de Empleado en formato String, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setNumeroTripulacion(std::string numEmple){
    numeroTripulacion=numEmple;
}

///recibe como parametro el nombre, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setNombre(std::string nom){
    nombre=nom;
}

///recibe como parametro el primer apellido, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setApellido1(std::string ape1){
    apellido1=ape1;
}

///recibe como parametro el segundo apellido, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setApellido2(std::string ape2){
    apellido2=ape2;
}

///recibe como parametro la aerolinea, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setAerolinea(std::string aerolin){
    aerolinea=aerolin;
}

///recibe como parametro el puesto del tripulante, y lo coloca a la variable local de la clase
///No tiene retorno

void Tripulacion::setPosicion(std::string pos){
    posicion=pos;
}

///Muestra a los empleados del archivo
///No tiene retornos o parametros

void Tripulacion::muestraEmpleado(){
    std::cout << numeroEmpleado << " " << nombre << " " << apellido1;
    std::cout << " " << apellido2 << " " << posicion << " " << aerolinea << std::endl;
}

///Anade un empleado al archivo donde se encuentra el resto
///No tiene parametros o retorno

void Tripulacion::anadirEmpleado(){
    std::ofstream archEmple;
    archEmple.open("Tripulacion.txt",std::ios_base::app);
    archEmple << numeroEmpleado << " " << nombre << " " << apellido1;
    archEmple << " " << apellido2 << " " << posicion << " " << aerolinea << "\n";
    archEmple.close();
}

///Elimina una tripulacion basado en su identificador
///No tiene retornos o parametros

void Tripulacion::elimTripulacion(){
    std::string datoArch, linea;
    std::ifstream elimTrip;
    std::ofstream anadTrip;
    anadTrip.open("TripulacionTemp.txt");
    elimTrip.open("Tripulacion.txt");

    while(getline(elimTrip, datoArch)){

        if (std::string::npos == datoArch.find(numeroTripulacion)){

            anadTrip << datoArch << std::endl;
        }
    }
    elimTrip.close();
    anadTrip.close();
    std::ifstream listaTemp;
    std::ofstream nuevaLista;
    listaTemp.open("TripulacionTemp.txt");
    nuevaLista.open("Tripulacion.txt");

    while (getline(listaTemp, linea)){

        nuevaLista << linea << std::endl;
    }
    listaTemp.close();
    nuevaLista.close();
}

///asigna a un empleado a un vuelo
///No tiene retornos o parametros

void Tripulacion::asigEmpleado(std::string numVuelo){
    std::string aerolin, nombre, apellido1, apellido2, puesto, empleado;
    std::ifstream listaEmple;
    std::ofstream empleTemp;
    listaEmple.open("Tripulacion.txt");
    empleTemp.open("TripulacionTemp.txt");

    if (numeroEmpleado==0){

        while(getline(listaEmple,empleado)){

        if (std::string::npos!=empleado.find(numeEmple)) {

            empleTemp << empleado << " " << numVuelo << std::endl;
        }

        else{

            empleTemp << empleado << std::endl;
        }
    }
    }

    else{

        while(getline(listaEmple,empleado)){

            if (std::string::npos!=empleado.find(numeroEmpleado)) {

                empleTemp << empleado << " " << numVuelo << std::endl;
            }

            else{

                empleTemp << empleado << std::endl;
            }
        }
    }
    listaEmple.close();
    empleTemp.close();
    listaEmple.open("TripulacionTemp.txt");
    empleTemp.open("tripulacion.txt");

    while (getline(listaEmple,empleado)){

        empleTemp << empleado << std::endl;
    }
}
#endif // TRIPULACION_H_INCLUDED
