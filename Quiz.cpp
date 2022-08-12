#include <iostream>
#include <string>
using namespace std; 

int tren(int vagones,int asientos_x_vagon){
         
    int arr[vagones][asientos_x_vagon];

    //cout << sizeof arr/sizeof arr[0] << endl; // Cantidad de vagones
    //cout << sizeof arr[0]/sizeof arr[0][0] << endl; // Cantidad de asientos

    //Para establecer todos los asientos desocupados se usa el 0
    for(int i=0;i<vagones;++i){ 
        for(int j=0;j<asientos_x_vagon;++j){
            arr[i][j]=0;
        };
    };

    //Los asientos ocupados se pueden hacer como una entrada estandar (input) pero no se pedia.

    //Asientos Ocupados realizados a mano, se pueden cambiar, el primero es el vagon, y el segundo el asiento
    //---------------------------------------------------------------------------------------------
    arr[0][0]=1, arr[0][2]=1, arr[0][3]=1, arr[0][4]=1, arr[0][5]=1, arr[0][9]=1, arr[0][13]=1;
    arr[1][2]=1, arr[1][3]=1, arr[1][5]=1, arr[1][8]=1, arr[1][9]=1, arr[1][11]=1, arr[1][13]=1;

    arr[2][0]=1, arr[2][2]=1, arr[2][3]=1, arr[2][4]=1, arr[2][5]=1, arr[2][9]=1, arr[2][13]=1;
    /*
    arr[3][2]=1, arr[3][3]=1, arr[3][5]=1, arr[3][8]=1, arr[3][9]=1, arr[3][11]=1, arr[3][13]=1;
    arr[4][0]=1, arr[4][2]=1, arr[4][3]=1, arr[4][4]=1, arr[4][5]=1, arr[4][9]=1, arr[4][13]=1;
    arr[5][2]=1, arr[5][3]=1, arr[5][5]=1, arr[5][8]=1, arr[5][9]=1, arr[5][11]=1, arr[5][13]=1;
    arr[6][0]=1, arr[6][2]=1, arr[6][3]=1, arr[6][4]=1, arr[6][5]=1, arr[6][9]=1, arr[6][13]=1;
    arr[7][2]=1, arr[7][3]=1, arr[7][5]=1, arr[7][8]=1, arr[7][9]=1, arr[7][11]=1, arr[7][0]=1;
    */
   //---------------------------------------------------------------------------------------------

   cout << "\n-1 para los asientos ocupados y -0 para los que no\n\n";
    for(int i=0;i<vagones;++i){
        cout << "Vagon #" << i+1 <<" \n" << "\n";
        cout << "Asientos: " << endl;
        for(int j=0;j<asientos_x_vagon;++j){
            if (j+1<asientos_x_vagon){
                cout << "#" << j << ": "<< arr[i][j] << "  " << "#" << j+1 << ": "<< arr[i][j+1] << endl;
            }
            else{
                cout <<  "#" << j << ": "<< arr[i][j] << endl;
            }
            ++j;
        };
        cout << endl;
    };

    int primeros = 0;
    int ultimos = 0;
    string num_asientoP;
    string num_asientoU;

    int campos[2];
    int flag = 0;

    for(int i=0; i<vagones;++i){
        for (int j=0;j<asientos_x_vagon;++j){
            if (arr[i][j]== 0 && primeros < 10){
                primeros+=1;
                campos[0]=i,campos[1]=j;
                num_asientoP+="Vagon #"+ to_string(i+1)+", asiento: "+to_string(j)+"\n";
               
            };
        };
    };


    for(int i=vagones-1; i>-1;--i){
        for (int j=asientos_x_vagon;j>-1;--j){
            if (i==campos[0] && j== campos[1]){
                flag = 1;
            };
            if (flag==0){
                if (arr[i][j]== 0 && ultimos < 10){
                    ultimos+=1;
                    num_asientoU+="Vagon #"+ to_string(i+1)+", asiento: "+to_string(j)+"\n";
               
                };
            };
        };  
    };
    cout << "Asientos por vagon vacios: \n\n";
    cout << "Primeros 10: \n";
    cout << num_asientoP + "\n";
    cout << "Ultimos 10: \n";

    if (ultimos>0){
        cout << num_asientoU + "\n";
    }

    else{

        cout << "\nCoinciden con los primeros";
    }
}
int main (){

    int vagones = 3; //numero de vagones
    int asientos_x_vagon = 15; //Numero de asientos por vagon
    tren(vagones,asientos_x_vagon);
    return 0;
}
