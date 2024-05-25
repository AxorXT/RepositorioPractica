#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>

struct Login {
    std::string Usuario;
    std::string Contrasena;
    std::string Correo;
};

bool isValidEmail(const std::string &email){
    return email.find("@");
}

int main() {
    Login ingreso;
    std::cout << "BIENVENIDO" << std::endl;
    std::cout << "Ingresa el usuario, Ingresa la contrasena, Ingresa el correo:" << std::endl;
    std::cin >> ingreso.Usuario >> ingreso.Contrasena >> ingreso.Correo;
    std::ofstream Ing("BD.text");
    if(!Ing.is_open()){
        std::cerr << "No abrio" << std::endl;
    }
    Ing << ingreso.Usuario << "" << ingreso.Contrasena << "" << ingreso.Correo << "\r\n";
    Ing.close();

    // Lectura del archivo
    std::ifstream archivoEntrada("BD.text");
    std::string linea;

    if (archivoEntrada.is_open()) {
        std::cout << "Contenido del archivo:" << std::endl;
        while (getline(archivoEntrada, linea)) {
            std::cout << linea << std::endl;
        }
        archivoEntrada.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
    }

    return 0;
}