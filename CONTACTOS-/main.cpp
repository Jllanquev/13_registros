#include<iostream>
#include "LeerFunciones.h"
#include "struct.h"
using namespace std;





int main(){
    int n, op,mod;
    string nom, user,dom, domain;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;

    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contacto"<<endl;
        cout<<"4. Mostrar listado de contactos por dominio"<<endl;
        cout<<"5. Eliminar contactos"<<endl;
        cout<<"0. Salir"<<endl<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 3:
			    for(int i = 0; i < n; i++){
			        cout<<"Contacto #"<<i+1<<" - "<<lista[i].nom<<endl;
			    }
			    cout<<"Que contacto desea modificar: ";
			    cin >> mod;
				mod--;
			    if(mod >= 0 && mod < n){
			        int campo;
			        do {
			            system("cls");
			            cout<<"Contacto actual:"<<endl;
			            imprimeContacto(lista[mod]);
			            cout<<"\n�Que desea modificar?"<<endl;
			            cout<<"1. Nombre"<<endl;
			            cout<<"2. Sexo"<<endl;
			            cout<<"3. Edad"<<endl;
			            cout<<"4. Usuario del correo"<<endl;
			            cout<<"5. Dominio del correo"<<endl;
			            cout<<"0. Volver al menu principal"<<endl;
			            cout<<"Seleccione una opcion: ";
			            cin >> campo;
			
			            cin.ignore(); 
			
			            switch(campo){
			                case 1:
			                    cout<<"Nuevo nombre: ";
			                    getline(cin, lista[mod].nom);
			                    break;
			                case 2:
			                    cout<<"Nuevo sexo (M/F): ";
			                    cin >> lista[mod].sex;
			                    break;
			                case 3:
			                    cout<<"Nueva edad: ";
			                    cin >> lista[mod].edad;
			                    break;
			                case 4:
			                    cout<<"Nuevo usuario del correo: ";
			                    cin >> lista[mod].email.user;
			                    break;
			                case 5:
			                    cout<<"Nuevo dominio del correo: ";
			                    cin >> lista[mod].email.domain;
			                    break;
			                case 0:
			                    cout<<"Volviendo al menu principal..."<<endl;
			                    break;
			                default:
			                    cout<<"Opcion no valida."<<endl;
			            }
			            system("pause");
			        } while(campo != 0);
			    } else {
			        cout<<"Indice no valido."<<endl;
			        system("pause");
			    }
			    break;
			case 4: {
					cout<<"Filtrar contactos por dominio "<<endl;
					cout<<"Ingrese el dominio a filtrar: "; cin>>dom;
					bool imprime=false;
					cout<<"\n";
					for(int i=0;i<n;i++){
						if(lista[i].email.domain==dom){
							imprimeContacto(lista[i]);
							cout<<"\n";
							imprime=true;
						}
					}
					if(!imprime){
						cout<<"No se encontro contactos con el dominio "<<dom;
					}
					system("pause");
					break;
				}
			case 5: 
				    for(int i = 0; i < n; i++){
				        cout << "Contacto #" << i + 1 << " - " << lista[i].nom << endl;
				    }
				    cout << "Ingrese el numero del contacto a eliminar: ";
				    cin >> mod;
				    mod--;
				    if(mod >= 0 && mod < n){
				        for(int i = mod; i < n - 1; i++){
				            lista[i] = lista[i + 1];  
				        }
				        n--; 
				        cout << "Contacto eliminado correctamente.\n";
				    } else {
				        cout << "Indice invalido.\n";
				    }
				    system("pause");
				    break;				
            case 0:
            	char Finish;
                cout<<"Esta seguro de salir? (S/N): ";
                cin>>Finish;
                if(Finish=='S'||Finish=='s'){
                	cout<<"Cerrando programa...";
				}
				else{
					op=-1;
				}
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}



