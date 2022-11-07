#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip> 

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){ //revisar isso aqui
  int i,j,k; //contadores

  nx = _nx;
  ny = _ny;
  nz = _nz;
  r = 0;
  g = 0;
  b = 0;
  a = 0; // inicializando os valores dos metodos

 //Alocar matriz 3D
  
  //alocando dimensao x:
  v = new Voxel ** [nx];
  
  //alocando dimensao y:
  for(i = 0; i < nx; i ++){
     v[i] = new Voxel * [ny];
  }
  
  //alocando dimensao z:
  for(i = 0; i < nx; i ++){
    for(j = 0; j < ny; j++){
      v[i][j] = new Voxel [nz];
    } 
  }

  
  //passar propriedades da matriz (10,10,10)

  for(i = 0; i < nx; i ++){
    
     for(j = 0; j < ny; j ++){
       
       for(k = 0; k < nz; k ++){
         
     this -> v[i][j][k].r = this -> r;
     this -> v[i][j][k].g = this -> g;
     this -> v[i][j][k].b = this -> b;
     this -> v[i][j][k].a = this -> a;
     this -> v[i][j][k].show = false; //desativado
           
           }
         }
      }
  }
  
  //DESTRUTOR DA CLASSE:
  Sculptor::~Sculptor() {
  
    int i,j;
    
    for(i = 0; i < nx; i ++){
    
     for(j = 0; j < ny; j ++){

       delete [] v[i][j]; //liberando ultima sequencia
       }
    }

    for(i = 0; i < nx; i ++){
     
      delete [] v[i] ; //liberando penultima sequencia  
       }
       
      delete [] v; //liberando primeira sequencia
   }

  //CORES DO VOXEL
 void Sculptor::setColor(float r, float g, float b, float alpha)
  {
 this -> r = r;
 this -> g = g;
 this -> b = b;
 this -> a = alpha;
  }
  //ATIVACAO DO VOXEL
  void Sculptor::putVoxel(int x, int y, int z){
    
      this -> v[x][y][z].show = true;

      this -> v[x][y][z].r = this -> r;
      this -> v[x][y][z].g = this -> g;
      this -> v[x][y][z].b = this -> b;
      this -> v[x][y][z].a = this -> a;
  }

//DESATIVACAO DO VOXEL
  void Sculptor :: cutVoxel(int x, int y, int z){

      this -> v[x][y][z].show = false;
    }

//BLOCO DE VOXEL - PUT
    void Sculptor :: putBox( int x0, int x1, int y0, int y1, int z0, int z1){
      int i,j,k;
      int x, y, z;
        
        for(i = x0; i < x1; i ++){
    
         for(j = y0; j < y1; j ++){
       
           for(k = z0; k < z1; k ++){
        
             this -> v[i][j][k].show = true;

               this -> v[i][j][k].r = this -> r;
               this -> v[i][j][k].g = this -> g;
               this -> v[i][j][k].b = this -> b;
               this -> v[i][j][k].a = this -> a;
           }
          }
         }
        }

//BLOCO DE VOXELS - CUT
  void Sculptor :: cutBox( int x0, int x1, int y0, int y1, int z0, int z1){
      int i,j,k;
      int x,y,z;
        for(i = x0; i < x1; i ++){
    
         for(j = y0; j < y1; j ++){
       
           for(k = z0; k < z1; k ++){
        
             this -> v[i][j][k].show = false;
             }
          }
        }
      }

//ATIVACAO ESFERA
void Sculptor :: putSphere (int xcenter, int ycenter, int zcenter, int radius){
  int i,j,k;
  int x,y,z;
   for(i = 0; i < nx; i ++){
    
     for(j = 0; j < ny; j ++){
       
       for(k = 0; k < nz; k ++){
         
         if ((pow(i-xcenter,2)) + (pow(j-ycenter,2)) + (pow(k-zcenter,2)) <= (pow(radius,2))){
           
           this -> v[i][j][k].show = true;

               this -> v[i][j][k].r = this -> r;
               this -> v[i][j][k].g = this -> g;
               this -> v[i][j][k].b = this -> b;
               this -> v[i][j][k].a = this -> a;
           
           }
         }
       }
     }
  }

//REMOVER ESFERA
  void Sculptor :: cutSphere (int xcenter, int ycenter, int zcenter, int radius){
    int i,j,k;
    int x,y,z;
   for(i = 0; i < nx; i ++){
    
     for(j = 0; j < ny; j ++){
       
       for(k = 0; k < nz; k ++){
         
         if ((pow(i-xcenter,2)) + (pow(j-ycenter,2)) + (pow(k-zcenter,2)) <= (pow(radius,2))){
           this -> v[i][j][k].show = false;
           }
         }
       }
     }
  }

//ATIVACAO DO ELIPSOIDE
    void Sculptor:: putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
      int i,j,k;
      int x,y,z;
       
       for(i = 0; i < nx; i ++){
    
         for(j = 0; j < ny; j ++){
       
           for(k = 0; k < nz; k ++){
              
          if((pow(i - xcenter,2) / pow(rx,2)) + (pow(j-ycenter,2) / pow(ry,2)) + (pow(k-zcenter,2) / pow(rz,2)) <= 1)
          {
            this -> v[i][j][k].show = true;

               this -> v[i][j][k].r = this -> r;
               this -> v[i][j][k].g = this -> g;
               this -> v[i][j][k].b = this -> b;
               this -> v[i][j][k].a = this -> a;
            
             }
           }
         }
       }
      }

// REMOVENDO ELIPSOIDE:
      void Sculptor:: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
        int i,j,k;
        int nx,ny,nz;
        int x,y,z;
        
        for(i = 0; i < nx; i ++){
    
           for(j = 0; j < ny; j ++){
       
             for(k = 0; k < nz; k ++){
         
               if((pow(i-xcenter,2)/pow(rx,2))+(pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1)  {
                 
                 this -> v[i][j][k].show = false;   
           }
          }
         }
       }
      }

//GRAVANDO O ARQUIVO
     void Sculptor:: writeOFF(const char* filename){
       int i,j,k;
       int x,y,z;
       int nx,ny,nz;
       int n_voxel;
       int n_vertice;

       n_voxel = 0;
       
       ofstream fout;
       fout.open (filename); //abertura do arquivo
       if(!fout.is_open()){
        cout << "O arquivo nao pode ser aberto"<< endl;
         exit (1);
       }
       for(i = 0; i < nx; i ++){
    
        for(j = 0; j < ny; j ++){
       
         for(k = 0; k < nz; k ++){
        
           if (v[i][j][k].show == true){
           n_voxel = n_voxel + 1; //n de voxels ativos
               }
             }
           }
         }
       
    fout << "OFF" << endl; //escreve arquivo tipo OFF
    fout << n_voxel*8 << " " << n_voxel*6 << " " << n_voxel*0 << endl; 
       float lado = 0.5;
       for(i = 0; i < nx; i ++){
    
         for(j = 0; j < ny; j ++){
       
           for(k = 0; k < nz; k ++){
        
             if (v[i][j][k].show == true){
                    fout << i - lado << " " << j + lado << " " << k - lado << "\n";
                    fout << i - lado << " " << j - lado << " " << k - lado << "\n";
                    fout << i + lado << " " << j - lado << " " << k - lado << "\n";
                    fout << i + lado << " " << j + lado << " " << k - lado << "\n";
                    fout << i - lado << " " << j + lado << " " << k + lado << "\n";
                    fout << i - lado << " " << j - lado << " " << k + lado << "\n";
                    fout << i + lado << " " << j - lado << " " << k + lado << "\n";
                    fout << i + lado << " " << j + lado << " " << k + lado << "\n";
               }
            }
          }
       } // coordenadas dos vertices do voxel
    n_voxel = 0; // volta pra o valor nulo 
     for(i = 0; i < nx; i ++){
    
       for(j = 0; j < ny; j ++){
       
       for(k = 0; k < nz; k ++){
        
         if (v[i][j][k].show == true){
           
           n_vertice = n_voxel * 8;
           
           fout  << " 4 " << " " << n_vertice + 0 << " "<< n_vertice + 1 << " " <<  n_vertice + 2 << " " << n_vertice + 3 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
           
           fout  << " 4 " << " " << n_vertice + 0 << " "<< n_vertice + 3 << " " <<  n_vertice + 5 << " " << n_vertice + 4 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
           
           fout  << " 4 " << " " << n_vertice + 4 << " "<< n_vertice + 5 << " " <<  n_vertice + 7 << " " << n_vertice + 6 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
           
           fout  << " 4 " << " " << n_vertice + 1 << " "<< n_vertice + 6 << " " <<  n_vertice + 7 << " " << n_vertice + 2 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
           
           fout  << " 4 " << " " << n_vertice + 0 << " "<< n_vertice + 4 << " " <<  n_vertice + 6 << " " << n_vertice + 1 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

           fout  << " 4 " << " " << n_vertice + 2 << " "<< n_vertice + 7 << " " <<  n_vertice + 5 << " " << n_vertice + 3 << " "<< v[i][j][k].r <<" "<< v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

           n_voxel = n_voxel + 1;
         
               }
            }
          }
       } 

           fout.close(); //fechando arquivo
    }
