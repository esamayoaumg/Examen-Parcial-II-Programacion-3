#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string info = "Elder Geovani Samayoa Esquivel | 9941-24-10076";

struct Nodo {
    int valor;
    Nodo* siguiente;
};

struct NodoDoble {
    int valor;
    string destino;
    int correlativo;
    NodoDoble *sig, *ant;
};

struct NodoArbol {
    int valor;
    NodoArbol *izq, *der;
};

struct Control {
    int pares = 0, impares = 0, negativos = 0, ceros = 0;
    int mayor = -99999, menor = 99999;
    int contadorGlobal = 0;
};

void insertarPila(Nodo* &top, int v) {
    Nodo* nuevo = new Nodo{v, top};
    top = nuevo;
}

void insertarCola(Nodo* &frente, Nodo* &fin, int v) {
    Nodo* nuevo = new Nodo{v, nullptr};
    if (!frente) frente = nuevo;
    else fin->siguiente = nuevo;
    fin = nuevo;
}

void insertarListaSimple(Nodo* &cabeza, int v) {
    Nodo* nuevo = new Nodo{v, nullptr};
    if (!cabeza) cabeza = nuevo;
    else {
        Nodo* aux = cabeza;
        while (aux->siguiente) aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
}

void registrarHistorial(NodoDoble* &inicio, NodoDoble* &fin, int v, string tipo, Control &c) {
    c.contadorGlobal++;
    NodoDoble* nuevo = new NodoDoble{v, tipo, c.contadorGlobal, nullptr, fin};
    if (fin) fin->sig = nuevo;
    else inicio = nuevo;
    fin = nuevo;
}

NodoArbol* insertarBST(NodoArbol* raiz, int v) {
    if (!raiz) return new NodoArbol{v, nullptr, nullptr};
    if (v < raiz->valor) raiz->izq = insertarBST(raiz->izq, v);
    else if (v > raiz->valor) raiz->der = insertarBST(raiz->der, v);
    return raiz;
}

void inOrden(NodoArbol* raiz) {
    if (!raiz) return;
    inOrden(raiz->izq);
    cout << raiz->valor << " ";
    inOrden(raiz->der);
}

void preOrden(NodoArbol* raiz) {
    if (!raiz) return;
    cout << raiz->valor << " ";
    preOrden(raiz->izq);
    preOrden(raiz->der);
}

void postOrden(NodoArbol* raiz) {
    if (!raiz) return;
    postOrden(raiz->izq);
    postOrden(raiz->der);
    cout << raiz->valor << " ";
}

bool buscarBST(NodoArbol* raiz, int v) {
    if (!raiz) return false;
    if (raiz->valor == v) return true;
    return (v < raiz->valor) ? buscarBST(raiz->izq, v) : buscarBST(raiz->der, v);
}

void limpiarMemoria(Nodo* &n) {
    while(n) {
        Nodo* aux = n;
        n = n->siguiente;
        delete aux;
    }
}

void limpiarMemoriaArbol(NodoArbol* &r) {
    if (!r) return;
    limpiarMemoriaArbol(r->izq);
    limpiarMemoriaArbol(r->der);
    delete r;
    r = nullptr;
}

int main() {
    Nodo *pila = nullptr, *colaF = nullptr, *colaFin = nullptr, *listaNeg = nullptr;
    NodoDoble *histInicio = nullptr, *histFin = nullptr;
    NodoArbol *raiz = nullptr;
    Control ctrl;

    int opcion, n, valor;

    do {
        cout << "\nSISTEMA PARCIAL II | " << info;
        cout << "\n1. Ingresar N numeros";
        cout << "\n2. Mostrar pila";
        cout << "\n3. Mostrar cola";
        cout << "\n4. Mostrar lista de negativos";
        cout << "\n5. Mostrar historial (lista doble)";
        cout << "\n6. Construir y mostrar BST";
        cout << "\n7. Eliminar negativos segun condicion";
        cout << "\n8. Buscar un valor en el BST";
        cout << "\n9. Mostrar estadisticas";
        cout << "\n10. Reorganizar estructuras";
        cout << "\n11. Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese cantidad N (mayor a 0): "; cin >> n;
                if (n <= 0) { cout << "Validacion: N debe ser mayor a 0.\n"; break; }
                for(int i = 0; i < n; i++) {
                    cout << "Valor " << i+1 << ": "; cin >> valor;
                    if (valor == 0) { ctrl.ceros++; continue; }
                    if (valor > ctrl.mayor) ctrl.mayor = valor;
                    if (valor < ctrl.menor) ctrl.menor = valor;
                    if (valor > 0) {
                        if (valor % 2 == 0) {
                            ctrl.pares++; insertarCola(colaF, colaFin, valor);
                            registrarHistorial(histInicio, histFin, valor, "COLA", ctrl);
                        } else {
                            ctrl.impares++; insertarPila(pila, valor);
                            registrarHistorial(histInicio, histFin, valor, "PILA", ctrl);
                        }
                    } else {
                        ctrl.negativos++; insertarListaSimple(listaNeg, valor);
                        registrarHistorial(histInicio, histFin, valor, "LISTA SIMPLE", ctrl);
                    }
                }
                break;
            case 2:
                cout << "\nPila (Impares Positivos) | " << info << ":\n";
                if(!pila) cout << "Estructura vacia.\n";
                for(Nodo* it = pila; it; it = it->siguiente) cout << it->valor << " ";
                cout << endl;
                break;
            case 3:
                cout << "\nCola (Pares Positivos) | " << info << ":\n";
                if(!colaF) cout << "Estructura vacia.\n";
                for(Nodo* it = colaF; it; it = it->siguiente) cout << it->valor << " ";
                cout << endl;
                break;
            case 4:
                cout << "\nLista Negativos | " << info << ":\n";
                if(!listaNeg) cout << "Estructura vacia.\n";
                for(Nodo* it = listaNeg; it; it = it->siguiente) cout << it->valor << " ";
                cout << endl;
                break;
            case 5:
                cout << "\nHistorial Completo | " << info << ":\n";
                if(!histInicio) cout << "Estructura vacia.\n";
                for(NodoDoble* it = histInicio; it; it = it->sig)
                    cout << "Orden: " << it->correlativo << " | Valor: " << it->valor << " | Destino: " << it->destino << endl;
                break;
            case 6:
                if(!histInicio) { cout << "No hay datos para construir el arbol.\n"; break; }
                limpiarMemoriaArbol(raiz);
                for(NodoDoble* it = histInicio; it; it = it->sig)
                    if(it->valor > 0) raiz = insertarBST(raiz, it->valor);
                cout << "\nBST construido por: " << info;
                cout << "\nInOrden: "; inOrden(raiz);
                cout << "\nPreOrden: "; preOrden(raiz);
                cout << "\nPostOrden: "; postOrden(raiz); cout << endl;
                break;
            case 7:
                if(!listaNeg) { cout << "Lista vacia.\n"; break; }
                {
                    cout << "Lista Original: ";
                    for(Nodo* it = listaNeg; it; it = it->siguiente) cout << it->valor << " ";
                    Nodo *curr = listaNeg, *prev = nullptr;
                    int eliminados = 0;
                    while(curr) {
                        if(abs(curr->valor) < 10) {
                            eliminados++;
                            Nodo* borrar = curr;
                            if(!prev) listaNeg = curr->siguiente;
                            else prev->siguiente = curr->siguiente;
                            curr = curr->siguiente;
                            delete borrar;
                        } else {
                            prev = curr;
                            curr = curr->siguiente;
                        }
                    }
                    cout << "\nLista Resultante: ";
                    for(Nodo* it = listaNeg; it; it = it->siguiente) cout << it->valor << " ";
                    cout << "\nNodos eliminados por magnitud < 10: " << eliminados << endl;
                }
                break;
            case 8:
                if(!raiz) cout << "Arbol no construido.\n";
                else {
                    cout << "Valor a buscar: "; cin >> valor;
                    if(buscarBST(raiz, valor)) cout << "Resultado: Valor encontrado en BST.\n";
                    else cout << "Resultado: Valor no encontrado.\n";
                }
                break;
            case 9:
                cout << "\nESTADISTICAS | " << info;
                cout << "\n- Pares positivos: " << ctrl.pares;
                cout << "\n- Impares positivos: " << ctrl.impares;
                cout << "\n- Negativos: " << ctrl.negativos;
                cout << "\n- Ceros rechazados: " << ctrl.ceros;
                cout << "\n- Total validos: " << ctrl.contadorGlobal;
                if(ctrl.contadorGlobal > 0) {
                    cout << "\n- Mayor valor: " << ctrl.mayor;
                    cout << "\n- Menor valor: " << ctrl.menor;
                }
                cout << endl;
                break;
            case 10:
                {
                    cout << "\nReorganizando... (Vaciando Pila y Cola a Listas Auxiliares)\n";
                    Nodo *auxPila = nullptr, *auxCola = nullptr;
                    while(pila) {
                        int v = pila->valor;
                        insertarListaSimple(auxPila, v);
                        Nodo* temp = pila;
                        pila = pila->siguiente;
                        delete temp;
                    }
                    while(colaF) {
                        int v = colaF->valor;
                        insertarListaSimple(auxCola, v);
                        Nodo* temp = colaF;
                        colaF = colaF->siguiente;
                        delete temp;
                    }
                    cout << "Lista Auxiliar Pila: ";
                    for(Nodo* it = auxPila; it; it = it->siguiente) cout << it->valor << " ";
                    cout << "\nLista Auxiliar Cola: ";
                    for(Nodo* it = auxCola; it; it = it->siguiente) cout << it->valor << " ";
                    limpiarMemoriaArbol(raiz);
                    for(Nodo* it = auxPila; it; it = it->siguiente) raiz = insertarBST(raiz, it->valor);
                    for(Nodo* it = auxCola; it; it = it->siguiente) raiz = insertarBST(raiz, it->valor);
                    limpiarMemoria(auxPila); limpiarMemoria(auxCola);
                    cout << "\nBST reconstruido con exito por: " << info << endl;
                }
                break;
        }
    } while(opcion != 11);

    limpiarMemoria(pila);
    limpiarMemoria(colaF);
    limpiarMemoria(listaNeg);
    limpiarMemoriaArbol(raiz);

    return 0;
}