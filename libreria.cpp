#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct registro{
	int dia;
	string modelo;
	int cantidad;
};

struct totalDia{
    int dia;
	string modelo;
	int cantidad;
};

struct masVendido{
    string modelo;
    int cantidad;
};

void agregarVenta(){
	Venta:
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

		int i = 0;
		int cantidad = 0;
		int dia = 0;
		float precio = 0;
		int modelo1 = 10;
		int modelo2 = 15;
		int modelo3 = 18;
		int modelo4 = 20;
		string mensaje;

        cout<<"-------------------"<<endl;
        cout<<"Menu Modelos"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1 - Modelo #1 - Q10.00"<<endl;
        cout<<"2 - Modelo #2 - Q15.00"<<endl;
        cout<<"3 - Modelo #3 - Q18.00"<<endl;
        cout<<"4 - Modelo #4 - Q20.00"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"5 - Regresar a menu principal"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"6 - Salir"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Seleccione su opcion: ";
        cin>>i;

        switch(i){
            case 1:
                precio = modelo1;
                mensaje = "Modelo01";
                break;
            case 2:
                precio = modelo2;
                mensaje = "Modelo02";
                break;
            case 3:
                precio = modelo3;
                mensaje = "Modelo03";
                break;
            case 4:
                precio = modelo4;
                mensaje = "Modelo04";
                break;
            case 5:
                break;
            case 6:
                exit(1);
            default:
                system("cls");
                cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
                system("Pause");
                goto Venta;
                break;
        }

		cout<<"Ingrese cantidad de cuadernos a comprar: "<<endl;
		cin>>cantidad;

		if(cantidad < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto Venta;
		}

		cout<<"Ingrese dia de venta: "<<endl;
		cin>>dia;

		if(dia < 1 && dia > 30){
			cout<<"Debe ingresar un dia valido (1 - 30). Intente de nuevo."<<endl;
			system("Pause");
			goto Venta;
		}

		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

        archivo<<dia<<'\t'
        <<mensaje<<'\t'
        <<cantidad<<endl;

		archivo.close();

		cout<<"Registros agregados exitosamente."<<endl;

		cout<<"-------------------"<<endl;
        cout<<"Resumen venta"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Modelo :"<<mensaje<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
        cout<<"Total: "<<precio * cantidad<<endl;
        cout<<"-------------------"<<endl;
};

void generarReporteL(){
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

     registro lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].dia
                >>lista[i].modelo
                >>lista[i].cantidad;
	 }
	 archivo.close();

	 int dias = 120;
	 totalDia listaTotalDia[dias];
	 int bandera = 0;

	 for(int i = 0; i < dias; i++){
        listaTotalDia[i].dia = 0;
        listaTotalDia[i].modelo = "";
        listaTotalDia[i].cantidad = 0;
	 }

	 for(int i = 0; i < lineas; i++){
        bandera = 0;
        for(int x = 0; x < dias; x++){
            if(listaTotalDia[x].dia == lista[i].dia && listaTotalDia[x].modelo == lista[i].modelo){
                listaTotalDia[x].cantidad += lista[i].cantidad;
                bandera = 1;
            }
        }
        if(bandera == 0){
            listaTotalDia[i].dia = lista[i].dia;
            listaTotalDia[i].modelo = lista[i].modelo;
            listaTotalDia[i].cantidad = lista[i].cantidad;
        }
	 }

	 int modeloMasVendido = 0;
	 string desMasVendido;
	 int cont = 0;

	 system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"Resumen venta por dia "<<endl;
	 for(int i = 0; i < dias; i++){
        if(listaTotalDia[i].dia > 0){
            cout<<"- Dia : "<<listaTotalDia[i].dia<<" | "<<listaTotalDia[i].modelo<<" | Cantidad: "<<listaTotalDia[i].cantidad<<endl;
            cont ++;
        }
	 }
	 cout<<"--------------------------------------------------"<<endl;
	 cout<<"Resumen venta por modelo "<<endl;

	 masVendido vendido[cont];
	 for(int i = 0; i < cont; i++){
        vendido[i].modelo = "";
        vendido[i].cantidad = 0;
	 }

     for(int i = 0; i < dias; i++){
        bandera = 0;
        for(int x = 0; x < cont; x++){
            if(vendido[x].modelo == listaTotalDia[i].modelo){
                vendido[x].cantidad += listaTotalDia[i].cantidad;
                bandera = 1;
            }
        }
        if(bandera == 0){
            vendido[i].cantidad = listaTotalDia[i].cantidad;
            vendido[i].modelo = listaTotalDia[i].modelo;
        }
	 }

	 for (int i = 0; i < cont; i++){
        if(vendido[i].cantidad > 0){
            cout<<" - "<<vendido[i].modelo<<" | Cantidad: "<<vendido[i].cantidad<<endl;
        }
        if(vendido[i].cantidad > modeloMasVendido){
            modeloMasVendido = vendido[i].cantidad;
            desMasVendido = vendido[i].modelo;
        }
	 }
     cout<<"--------------------------------------------------"<<endl;
     cout<<"Modelo mas vendido "<<endl;
	 cout<<" - "<<desMasVendido<<" | Cantidad: "<<modeloMasVendido<<endl;
};

void eliminarVenta(){
     Eliminar:
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
         int deleteRegistro = 0;
         while(getline(archivo, s))
            lineas++;

         if(lineas == 0){
            cout<<"El archivo no posee registros. Intente de nuevo."<<endl;
            system("Pause");
            goto Eliminar;
         }

         archivo.close();
         system("CLS");

         registro lista[lineas];

         archivo.open(nombreArchivo.c_str(), ios::in);
         if(archivo.fail()){
            cout<<"Se presento un error al intentar abrir el archivo.";
            exit(1);
         }

         for(int i = 0; i < lineas; i++){
             archivo>>lista[i].dia
                    >>lista[i].modelo
                    >>lista[i].cantidad;
         }
         archivo.close();

         cout<<"Registros: "<<endl;
         for(int i = 0; i < lineas; i++){
            cout<<i+1<<" - "<<"Dia: "<<lista[i].dia<<" | "<<lista[i].modelo<<" | Cantidad: "<<lista[i].cantidad<<endl;
         }

         cout<<"-------------------------------------------"<<endl;
         cout<<"Ingrese el numero de registro que desea eliminar: "<<endl;
         cin>>deleteRegistro;

         if(deleteRegistro < 1 || deleteRegistro > lineas){
            cout<<"El registro ingresado no existe. Intente de nuevo."<<endl;
            system("Pause");
            goto Eliminar;
         }

         registro listaDepurada[lineas];
         for(int i = 0; i < lineas; i++){
            listaDepurada[i].dia = 0;
         }

         int cont = 0;
         for(int i = 0; i < lineas; i++){
            if(i != deleteRegistro-1){
                listaDepurada[i].dia = lista[i].dia;
                listaDepurada[i].modelo = lista[i].modelo;
                listaDepurada[i].cantidad = lista[i].cantidad;
            }
         }

         system("cls");
         cout<<"Registro a eliminar: "<<endl;
         cout<<deleteRegistro<<" - "<<"Dia: "<<lista[deleteRegistro-1].dia<<" | "<<lista[deleteRegistro-1].modelo<<" | Cantidad: "<<lista[deleteRegistro-1].cantidad<<endl;
         cout<<"--------------------------------------"<<endl;
         cout<<"Lista depurada: "<<endl;
         cont = 0;
         for(int i = 0; i < lineas; i++){
            if(listaDepurada[i].dia > 0){
                cont++;
                cout<<cont<<" - "<<"Dia: "<<listaDepurada[i].dia<<" | "<<listaDepurada[i].modelo<<" | Cantidad: "<<listaDepurada[i].cantidad<<endl;
            }
         }
         cout<<"--------------------------------------"<<endl;
         char opcion;
         cout<<"¿Seguro que desea continuar y/n?"<<endl;
         cin>>opcion;

         opcion = toupper(opcion);

         if(opcion == 'Y'){
            ofstream archivoL;
            string nombreArchivoL;
            nombreArchivoL = nombreArchivo;
            fflush(stdin);
            system("CLS");
            archivoL.open(nombreArchivoL.c_str(),ios::trunc);
            if(archivoL.fail()){
                archivoL.close();
                cout<<"No se pudo abrir el archivo";
                exit(1);
            }

            for(int i = 0; i < lineas; i++){
                if(listaDepurada[i].dia > 0){
                    archivoL<<listaDepurada[i].dia<<'\t'
                        <<listaDepurada[i].modelo<<'\t'
                        <<listaDepurada[i].cantidad<<endl;
                }
             }

            archivoL.close();
            cout<<"Registros agregados exitosamente."<<endl;
         }
};

void modificarVenta(){
     Modificar:
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
         int modificarRegistro = 0;
         int nuevaCantidad = 0;
         while(getline(archivo, s))
            lineas++;

         if(lineas == 0){
            cout<<"El archivo no posee registros. Intente de nuevo."<<endl;
            system("Pause");
            goto Modificar;
         }

         archivo.close();
         system("CLS");

         registro lista[lineas];

         archivo.open(nombreArchivo.c_str(), ios::in);
         if(archivo.fail()){
            cout<<"Se presento un error al intentar abrir el archivo.";
            exit(1);
         }

         for(int i = 0; i < lineas; i++){
             archivo>>lista[i].dia
                    >>lista[i].modelo
                    >>lista[i].cantidad;
         }
         archivo.close();

         cout<<"Registros: "<<endl;
         for(int i = 0; i < lineas; i++){
            cout<<i+1<<" - "<<"Dia: "<<lista[i].dia<<" | "<<lista[i].modelo<<" | Cantidad: "<<lista[i].cantidad<<endl;
         }

         cout<<"-------------------------------------------"<<endl;
         cout<<"Ingrese el numero de registro que desea modificar: "<<endl;
         cin>>modificarRegistro;

         if(modificarRegistro < 1 || modificarRegistro > lineas){
            cout<<"El registro ingresado no existe. Intente de nuevo."<<endl;
            system("Pause");
            goto Modificar;
         }

         cout<<"Ingrese nueva cantidad: "<<endl;
         cin>>nuevaCantidad;

         registro listaDepurada[lineas];
         for(int i = 0; i < lineas; i++){
            listaDepurada[i].dia = 0;
         }

         int cont = 0;
         for(int i = 0; i < lineas; i++){
            if(i != modificarRegistro-1){
                listaDepurada[i].dia = lista[i].dia;
                listaDepurada[i].modelo = lista[i].modelo;
                listaDepurada[i].cantidad = lista[i].cantidad;
            }else{
                listaDepurada[i].dia = lista[i].dia;
                listaDepurada[i].modelo = lista[i].modelo;
                listaDepurada[i].cantidad = nuevaCantidad;
            }
         }

         system("cls");
         cout<<"Registro a modificar: "<<endl;
         cout<<modificarRegistro<<" - "<<"Dia: "<<lista[modificarRegistro-1].dia<<" | "<<lista[modificarRegistro-1].modelo<<" | Cantidad: "<<lista[modificarRegistro-1].cantidad<<endl;
         cout<<"--------------------------------------"<<endl;
         cout<<"Lista modificada: "<<endl;
         cont = 0;
         for(int i = 0; i < lineas; i++){
            if(listaDepurada[i].dia > 0){
                cont++;
                cout<<cont<<" - "<<"Dia: "<<listaDepurada[i].dia<<" | "<<listaDepurada[i].modelo<<" | Cantidad: "<<listaDepurada[i].cantidad<<endl;
            }
         }
         cout<<"--------------------------------------"<<endl;
         char opcion;
         cout<<"¿Seguro que desea continuar y/n?"<<endl;
         cin>>opcion;

         opcion = toupper(opcion);

         if(opcion == 'Y'){
            ofstream archivoL;
            string nombreArchivoL;
            nombreArchivoL = nombreArchivo;
            fflush(stdin);
            system("CLS");
            archivoL.open(nombreArchivoL.c_str(),ios::trunc);
            if(archivoL.fail()){
                archivoL.close();
                cout<<"No se pudo abrir el archivo";
                exit(1);
            }

            for(int i = 0; i < lineas; i++){
                if(listaDepurada[i].dia > 0){
                    archivoL<<listaDepurada[i].dia<<'\t'
                        <<listaDepurada[i].modelo<<'\t'
                        <<listaDepurada[i].cantidad<<endl;
                }
             }

            archivoL.close();
            cout<<"Registros agregados exitosamente."<<endl;
         }
};
