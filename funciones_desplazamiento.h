#ifndef FUNCIONES_DESPLAZAMIENTO_H_INCLUDED
#define FUNCIONES_DESPLAZAMIENTO_H_INCLUDED
#include <iostream>
using namespace std;

 struct estaciones{
    char identificacion[2];
    char detenerse;
    };
    struct terreno {
    char trayectoria;
    estaciones estacion;
    };
    const int F = 10;
    const int C = 10;


    void crear_trayectoria(terreno plataforma[][10]){
        int ubicacion[8] = {5,8,0,3,3,0,8,5};

    for (int i = 0 ; i <10;i++){
        for(int j = 0 ; j <10;j++){
            plataforma[i][j].estacion.detenerse ='b';
        }
    }
    for(int i = 0; i < 7;i+=2){
        plataforma[ubicacion[i]][ubicacion[i+1]].estacion.detenerse = 'n';
    }
    plataforma[ubicacion[0]][ubicacion[1]].estacion.identificacion[0]= 'b';
    plataforma[ubicacion[0]][ubicacion[1]].estacion.identificacion[1]= 'b';

    plataforma[ubicacion[2]][ubicacion[3]].estacion.identificacion[0]= 'b';
    plataforma[ubicacion[2]][ubicacion[3]].estacion.identificacion[1]= 'n';

    plataforma[ubicacion[4]][ubicacion[5]].estacion.identificacion[0]= 'n';
    plataforma[ubicacion[4]][ubicacion[5]].estacion.identificacion[1]= 'b';

    plataforma[ubicacion[6]][ubicacion[7]].estacion.identificacion[0]= 'n';
    plataforma[ubicacion[6]][ubicacion[7]].estacion.identificacion[1]= 'n';

    for (int i = 0; i< F;i++){
        for (int j = 0; j < C;j++){
            plataforma[i][j].trayectoria = 'b';
        }
    }

    for (int i = 0 ; i<6;i++){
        plataforma[0][i].trayectoria = 'n';
    }
    for(int i = 0;i<4;i++){
        plataforma[i][5].trayectoria = 'n';
    }
    for(int i = 5;i<9;i++){
        plataforma[3][i].trayectoria = 'n';
    }
    for(int i = 3;i<9;i++){
        plataforma[i][8].trayectoria = 'n';
    }
    for(int i = 8;i>2;i--){
        plataforma[8][i].trayectoria = 'n';
    }
    for(int i = 8;i>5;i--){
        plataforma[i][8].trayectoria = 'n';
    }
    for(int i = 3;i>=0;i--){
        plataforma[6][i].trayectoria = 'n';
    }
    for(int i = 8;i>=6;i--){
        plataforma[i][3].trayectoria = 'n';
    }
    for(int i = 6;i>=0;i--){
        plataforma[i][0].trayectoria = 'n';
    }
    cout << "trayectoria"<<endl;
    for(int i = 0; i<F;i++){
        for (int j = 0; j < C; j++){
            cout<< plataforma[i][j].trayectoria<<" ";
        }
        cout <<endl;
    }

    cout << "estacion"<<endl;
    for(int i = 0; i<F;i++){
        for (int j = 0; j < C; j++){
            cout<< plataforma[i][j].estacion.detenerse<<" ";
        }
        cout <<endl;
    }

    }

    char s1_lectura(terreno plataforma[][10],int a,int b,bool derecha,bool izquierda,bool abajo,bool arriba){
        char sensor = 'b' ;
            if(derecha == true){
                if(plataforma[a][b+1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(izquierda == true&&b>0){
                if(plataforma[a][b-1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(arriba == true&& a > 0){
                if(plataforma[a-1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(abajo == true){
                if(plataforma[a+1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }

        return sensor;
    }
    char s2_lectura(terreno plataforma[][10],int a, int b,bool derecha,bool izquierda,bool abajo,bool arriba){
        char sensor = 'b' ;
            if(derecha == true){
                if(plataforma[a+1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(izquierda == true&& a > 0){
                if(plataforma[a-1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(arriba == true&& b > 0){
                if(plataforma[a][b+1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(abajo == true){
                if(plataforma[a][b-1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }

        return sensor;

    }
    char s3_lectura(terreno plataforma[][10],int a, int b,bool derecha,bool izquierda,bool abajo,bool arriba){

        char sensor = 'b' ;
            if(derecha == true&& a > 0){
                if(plataforma[a-1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(izquierda == true){
                if(plataforma[a+1][b].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(arriba == true){
                if(plataforma[a][b-1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }
            if(abajo == true&&b > 0){
                if(plataforma[a][b+1].trayectoria== 'n'){
                    sensor = 'n';
                }else{
                    sensor = 'b';
                }
            }

        return sensor;
    }

    void Desplazamiento_Detener(terreno plataforma[][10],int a,int b,bool derecha,bool izquierda,bool abajo,bool arriba){
        if(derecha == true){
                if(plataforma[a][b+1].estacion.detenerse == 'n'){
                    cout << "deternerse"<<endl;
                }else{
                    cout << "avanzar"<<endl;
                }
            }
            if(izquierda == true&&b>0){
                if(plataforma[a][b-1].estacion.detenerse== 'n'){
                   cout << "deternerse"<<endl;
                }else{
                    cout << "avanzar"<<endl;
                }
            }
            if(arriba == true&& a > 0){
                if(plataforma[a-1][b].estacion.detenerse== 'n'){
                    cout << "deternerse"<<endl;
                }else{
                   cout << "avanzar"<<endl;
                }
            }
            if(abajo == true){
                if(plataforma[a+1][b].estacion.detenerse== 'n'){
                    cout << "deternerse"<<endl;
                }else{
                    cout << "avanzar"<<endl;
                }
            }
    }

        int  Desplazamiento_Rotar_AgujasReloj(int posiciones[],int a,int b, bool derecha,bool izquierda,bool abajo,bool arriba,int dirreccion){
            if(derecha == true){
                posiciones[0] = a+1;
                posiciones[1] = b+1;
                cout << "giro a la derecha"<<endl;
                dirreccion = 3;
            }
            if(izquierda == true){
                posiciones[0] = a-1;
                posiciones[1] = b-1;
                cout << "giro a la derecha"<<endl;
                dirreccion = 4;
            }
            if(arriba == true){
                posiciones[0] = a-1;
                posiciones[1] = b+1;
                cout << "giro a la derecha"<<endl;
                dirreccion = 1;
            }
            if(abajo == true){
                posiciones[0] = a+1;
                posiciones[1] = b-1;
                cout << "giro a la derecha"<<endl;
                dirreccion = 2;
            }
            return dirreccion;
        }
    int Desplazamiento_Rotar_Opuesto_AgujasReloj(int posiciones[],int a,int b,bool derecha,bool izquierda,bool abajo,bool arriba,int dirreccion){
        if(derecha == true){
                posiciones[0] = a-1;
                posiciones[1] = b-1;
                cout << "giro a la izquierda"<<endl;
                dirreccion = 4;
            }
            if(izquierda == true){
                posiciones[0] = a+1;
                posiciones[1] = b+1;
                cout << "giro a la izquierda"<<endl;
                dirreccion = 3;
            }
            if(arriba == true){
                posiciones[0] = a+1;
                posiciones[1] = b-1;
                cout << "giro a la izquierda"<<endl;
                dirreccion = 2;
            }
            if(abajo == true){
                posiciones[0] = a-1;
                posiciones[1] = b+1;
                cout << "giro a la izquierda"<<endl;
                dirreccion = 1;
            }
            return dirreccion;
        }



#endif // FUNCIONES_DESPLAZAMIENTO_H_INCLUDED
