#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void mp();

void menuLibreria();
void menuCenso();
void agregarVenta();
void generarReporteL();
void eliminarVenta();
void modificarVenta();
void agregarPersona();
void generarReporteC();

int main(){
	mp();
}

void mp(){
	MenuPrincipal:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Menu Libreria"<<endl;
			cout<<"2 - Menu Censo Nacional"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{menuLibreria();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 2:
					{menuCenso();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 3:
					break;
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPrincipal;
					break;
			}
}

void menuLibreria(){
	MenuLibreria:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Libreria"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Agregar venta"<<endl;
			cout<<"2 - Modificar venta"<<endl;
			cout<<"3 - Eliminar venta"<<endl;
			cout<<"4 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"5 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"6 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{agregarVenta();}
					system("Pause");
					system("cls");
					goto MenuLibreria;
					break;
				case 2:
					{modificarVenta();}
					system("Pause");
					system("cls");
					goto MenuLibreria;
					break;
				case 3:
					{eliminarVenta();}
					system("Pause");
					system("cls");
					goto MenuLibreria;
					break;
                case 4:
					{generarReporteL();}
					system("Pause");
					system("cls");
					goto MenuLibreria;
					break;
                case 5:
                    break;
				case 6:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
					system("Pause");
					goto MenuLibreria;
					break;
			}
}

void menuCenso(){
	MenuCenso:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Censo Nacional"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Agregar registro"<<endl;
			cout<<"2 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{agregarPersona();}
					system("Pause");
					system("cls");
					goto MenuCenso;
					break;
				case 2:
					{generarReporteC();}
					system("Pause");
					system("cls");
					goto MenuCenso;
					break;
				case 3:
					break;
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuCenso;
					break;
			}
}
