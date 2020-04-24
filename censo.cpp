#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct persona{
	float peso;
	float altura;
	int edad;
	char genero;
};

void agregarPersona(){
	Persona:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

		float peso = 0;
		float altura = 0;
		int edad = 0;
		char genero;
		int personas = 0;

        cout<<"Ingrese cantidad de registros a guardar: "<<endl;
        cin>>personas;

		if(personas < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto Persona;
		}

		persona lista[personas];
		int bandera = 0;

		for(int i = 0; i < personas; i ++){
            bandera = 0;
            system("cls");
            cout<<"Ingrese peso de la persona_"<<i+1<<" (lb): "<<endl;
            cin>>peso;

            cout<<"Ingrese altura de la persona_"<<i+1<<" (m): "<<endl;
            cin>>altura;

            cout<<"Ingrese edad de la persona_"<<i+1<<" (anios): "<<endl;
            cin>>edad;

            if(edad < 1 || edad > 100){
                cout<<"Rango de edad invalido. Intente de nuevo."<<endl;
                system("Pause");
                i = i - 1;
                bandera = 1;
            }

            if (bandera == 0){
                cout<<"Ingrese genero de la persona_"<<i+1<<" (m = masculino / f = femenino): "<<endl;
                cin>>genero;
                genero = toupper(genero);

                if (genero != 'M' && genero != 'F'){
                    cout<<"Genero ingresado invalido. Intente de nuevo."<<endl;
                    system("Pause");
                    i = i - 1;
                    bandera = 1;
                }
            }

            if (bandera == 0){
                lista[i].peso = peso;
                lista[i].altura = altura;
                lista[i].edad = edad;
                lista[i].genero = genero;
            }
		}

		//Algoritmo bubblesort
        int tempEdad = 0;
        char tempGenero;
        float tempAltura = 0;;
        float tempPeso = 0;
        for(int i = 0; i < personas; i ++){
            for(int j = 0; j < personas; j ++){
                if(lista[j].edad < lista[i].edad){
                    tempEdad = lista[i].edad;
                    tempAltura = lista[i].altura;
                    tempGenero = lista[i].genero;
                    tempPeso = lista[i].peso;

                    lista[i].edad = lista[j].edad;
                    lista[i].altura = lista[j].altura;
                    lista[i].peso = lista[j].peso;
                    lista[i].genero = lista[j].genero;

                    lista[j].edad = tempEdad;
                    lista[j].altura = tempAltura;
                    lista[j].genero = tempGenero;
                    lista[j].peso = tempPeso;
                }
            }
        }
		//

		archivo.open(nombreArchivo.c_str(),ios::trunc);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		for(int i = 0; i < personas; i ++){
            archivo<<lista[i].edad<<'\t'
            <<lista[i].peso<<'\t'
            <<lista[i].altura<<'\t'
            <<lista[i].genero<<endl;
		}

		archivo.close();

		cout<<"Registros agregados exitosamente."<<endl;
};

void generarReporteC(){
	 ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     persona lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].edad
                >>lista[i].peso
                >>lista[i].altura
                >>lista[i].genero;
	 }
	 archivo.close();

	 float pesoMedio = 0;
	 float alturaMedia = 0;
	 float edadMedia = 0;

	 for(int i = 0; i < lineas; i++){
        pesoMedio += lista[i].peso;
        alturaMedia += lista[i].altura;
        edadMedia += lista[i].edad;
	 }

	 system("CLS");
	 cout<<"        Reporte         "<<endl;
     cout<<"------------------------"<<endl;
     cout<<"- Peso promedio: "<<pesoMedio/lineas<<endl;
	 cout<<"- Altura promedio: "<<alturaMedia/lineas<<endl;
	 cout<<"- Edad promedio: "<<edadMedia/lineas<<endl;
};
