///Clase para anadir, eliminar pasageros
///Andres Remis Serna, A00829053
///Fecha de creacion 27 de noviembre de 2019
///Fecha de ultima modificacion 2 de diciembre de 2019

#ifndef PASAGEROS_H_INCLUDED
#define PASAGEROS_H_INCLUDED
class Pasageros{
    public:
        Pasageros();
        Pasageros(std::string numVuelo);
        std::string getNumeroVuelo();
        int getNumeroBoletos();
        void setNombre(std::string nom, std::string ape1, std::string ape2);
        void setNumeroVuelo(std::string numVuelo);
        void setBoletos(int bol);
        void anadirPasagero();
        void eliminarPasagero();
        void mostrarPasageros();
    private:
        std::string numeroVuelo, nombre, apellido1, apellido2;
        int boletos;
};

///Establece los valores iniciales de todas las variables de la clase
///No tiene retornos o parametros

Pasageros::Pasageros(){
    numeroVuelo="-";
    nombre="-";
    apellido1="-";
    apellido2="-";
    boletos=0;
}

///Regresa el valor del numero de vuelo, que se encuentra en la variable local
///No tiene parametros

std::string Pasageros::getNumeroVuelo(){
    std::string nom, ape1, ape2, numVuelo;
    int bol;
    std::ifstream listPasag;
    listPasag.open("Pasageros.txt");

    while(listPasag >> nom >> ape1 >> ape2 >> numVuelo >> bol){

        if((nombre==nom) && (apellido1==ape1) && (apellido2==ape2)){

            numeroVuelo=numVuelo;
        }
    }
    return numeroVuelo;
}

///Regresa el valor de los numeros de boletos, que se encuentra en la variable local
///No tiene parametros

int Pasageros::getNumeroBoletos(){
    std::string nom, ape1, ape2, numVuelo;
    int bol;
    std::ifstream listPasag;
    listPasag.open("Pasageros.txt");

    while(listPasag >> nom >> ape1 >> ape2 >> numVuelo >> bol){

        if((nombre==nom) && (apellido1==ape1) && (apellido2==ape2)){

            boletos=bol;
        }
    }
    return boletos;
}

///recibe como parametro el nombre completo, y lo coloca a la variable local de la clase
///No tiene retorno

void Pasageros::setNombre(std::string nom, std::string ape1, std::string ape2){
    nombre=nom;
    apellido1=ape1;
    apellido2=ape2;
}

///recibe como parametro el Numero de Vuelo, y lo coloca a la variable local de la clase
///No tiene retorno

void Pasageros::setNumeroVuelo(std::string numVuelo){
    numeroVuelo=numVuelo;
}

///recibe como parametro los boletos comprados, y lo coloca a la variable local de la clase
///No tiene retorno

void Pasageros::setBoletos(int bol){
    boletos=bol;
}

///Anade un pasagero al archivo donde se encuentra el resto
///No tiene parametros o retorno

void Pasageros::anadirPasagero(){
    std::ofstream pasagero;
    pasagero.open("Pasageros.txt",std::ios_base::app);
    pasagero << nombre << " " << apellido1 << " ";
    pasagero << apellido2 << " " << numeroVuelo << " " << boletos;
    pasagero.close();
}

///Elimina un pasagero basado en su identificador
///No tiene retornos o parametros

void Pasageros::eliminarPasagero(){
    std::string datoArch, linea, nombreCompleto;
    std::ifstream elimPas;
    std::ofstream anadPas;
    nombreCompleto=nombre+" "+apellido1+" "+apellido2;
    anadPas.open("PasagerosTemp.txt");
    elimPas.open("Pasageros.txt");

    while(getline(elimPas, datoArch)){

        if (std::string::npos == datoArch.find(nombreCompleto)){

            anadPas << datoArch << std::endl;
        }
    }
    elimPas.close();
    anadPas.close();
    std::ifstream listaTemp;
    std::ofstream nuevaLista;
    listaTemp.open("PasagerosTemp.txt");
    nuevaLista.open("Pasageros.txt");

    while (getline(listaTemp, linea)){

        nuevaLista << linea << std::endl;
    }
    listaTemp.close();
    nuevaLista.close();
}

///Muestra a los pasageros de un vuelo
///No tiene retornos o parametros

void Pasageros::mostrarPasageros(){
    std::string nom, apel1, apel2, numVuelo;
    int bol;
    std::ifstream pasag;
    pasag.open("Pasageros.txt");

    while(pasag >> nom >> apel1 >> apel2 >> numVuelo >> bol){

        if(numVuelo==numeroVuelo){

            std::cout << nom << " " << apel1 << " " << apel2;
            std::cout << " compro " << bol << " boletos" << std::endl;
        }
    }
}
#endif // PASAGEROS_H_INCLUDED
