#include <iostream>
using namespace std;
// Definición de la estructura de un nodo del árbol binario
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int value) {
    data=value;
    left=nullptr;
    right=nullptr;
 } 
};


//funcion buscar
Node*zapato(Node* rama,int hoja){
    //caso base donde es la raiz 0 o vacio/null
    if(rama==nullptr || rama->data==hoja ){
        return rama;
    }
    //buscar por la derecha
    if(rama->data < hoja)
        return zapato(rama->right,hoja);
    //buscar por la izquierda
    return zapato(rama->left, hoja);

}

int main(){
    Node* rama=new Node(50);
    rama->left=new Node(30);
    rama->right=new Node(70);
    rama->left->left=new Node(20);
    rama->left->right=new Node(40);
    rama->right->right=new Node(80);
    rama->right->right=new Node(80);
    rama->right->left=new Node(60);

    //funcion para probar la busqueda

    auto test=[](Node* rama, int hoja){
        Node* resultado=zapato(rama,hoja);
        if(resultado!=nullptr){
            cout<<"Valor "<<hoja<<"Fue encontrado "<<endl;
        }else{
            cout<<"El valor"<<hoja<<"no fue encontrado"<<endl;
        }
    };

    test(rama,80);
    test(rama,85);

}