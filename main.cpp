#include <iostream>
#include "funciones_desplazamiento.h"
using namespace std;


int main()
    {
    terreno plataforma[F][C];

    char sensor_1;
    char sensor_2;
    char sensor_3;
    int a =0;
    int b =0;
    int posiciones[2];
    bool derecha = true;
    bool izquierda = false;
    bool abajo = false;
    bool arriba = false;
    bool terminar = false;
    int dirreccion =1 ;

    crear_trayectoria(plataforma);

    cout <<"RECORRIDO"<<endl;
    cout <<endl;

    do{
            sensor_1 = s1_lectura(plataforma,a,b,derecha,izquierda,abajo,arriba);
            sensor_2 = s2_lectura(plataforma,a,b,derecha,izquierda,abajo,arriba);
            sensor_3 = s3_lectura(plataforma,a,b,derecha,izquierda,abajo,arriba);

            if (sensor_1 == 'n'){
                Desplazamiento_Detener(plataforma,a,b,derecha,izquierda,abajo,arriba);
            }

            if (sensor_1 ==  'b'){
                if (sensor_2 == 'n'){
                     dirreccion = Desplazamiento_Rotar_AgujasReloj(posiciones,a,b,derecha,izquierda,abajo,arriba,dirreccion);
                }
                if (sensor_3 == 'n'){
                    dirreccion = Desplazamiento_Rotar_Opuesto_AgujasReloj(posiciones,a,b,derecha,izquierda,abajo,arriba,dirreccion);
                }
            }
                if (dirreccion == 1){
                    derecha = true;
                    izquierda = false;
                    abajo = false;
                    arriba = false;
                    b++;
                    }


                 if (dirreccion == 2){
                    derecha = false;
                    izquierda = true;
                    abajo = false;
                    arriba = false;
                    b--;

                }
                if (dirreccion == 3){
                    derecha = false;
                    izquierda = false;
                    abajo = true;
                    arriba = false;
                    a++;
                }
                if (dirreccion == 4){
                    derecha = false;
                    izquierda = false;
                    abajo = false;
                    arriba = true;
                    a--;
            }

            cout << " Fila "<< a<<" ";
            cout << " Columna "<<b<<endl ;
            cout << endl;
            if(a == 0 && b == 0 ){
                terminar = true;
            }
        }while(terminar == false);
    cout<<endl;
    cout<< "FIN RECORRIDO";
    return 0;
}
