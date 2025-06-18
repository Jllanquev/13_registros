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
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingrese el numero del empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        for(int j=0;j<12;j++){
            cout<<"ingrese el numero de ventas: ";
            cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Ingrese el salario del empleado "<<i+1<<": ";
        cin>>EMPLEADOS[i].sal;
    }

    float suma=0;
    float mayor;
    int posmayor=0;

    for(int i=0;i<n;i++){
       

        for(int j=0;j<12;j++){
            suma=suma+(EMPLEADOS[i].ven[j]);
        }

        mayor=0;
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