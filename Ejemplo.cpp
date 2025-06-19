#include <iostream>
#include <string>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};

int main(){
    EMP EMPLEADOS[100];
    int n;
    cout<<"Cantidad de empleados: ";
    cin>>n;

    for(int i=0;i<n;i++){
    	cout<<"\n\n***REGISTRO DE EMPLEADO****";
        cout<<"\nNumero del empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Nombre: ";
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        for(int j=0;j<12;j++){
            cout<<"Ventas: ";
            cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Salario: ";
        cin>>EMPLEADOS[i].sal;
    }

    float suma;
    float mayor=0;
    int posmayor=0;

    for(int i=0;i<n;i++){
    	suma=0;
        for(int j=0;j<12;j++){
            suma=suma+(EMPLEADOS[i].ven[j]);
        }
        
        if(suma>100){
        	EMPLEADOS[i].sal+= 0.1*EMPLEADOS[i].sal;
            cout << "\nSalario incrementado en 10% para " << EMPLEADOS[i].nom 
            << ": " << EMPLEADOS[i].sal << endl;
		}
        
        if(mayor<suma){
            mayor=suma;
            posmayor=i;
        }


    }
    cout << "\nEl empleado con mayores ventas anuales es:\n";
    cout << "Numero: " << EMPLEADOS[posmayor].num << endl;
    cout << "Nombre: " << EMPLEADOS[posmayor].nom << endl;
    cout << "Total de ventas: " <<mayor<< endl;


    return 0;
}
